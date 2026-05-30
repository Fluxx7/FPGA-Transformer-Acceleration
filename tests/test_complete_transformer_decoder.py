"""
End-to-end test for complete_transformer_decoder.

For each test prompt:
  - Run the PyTorch model forward, capturing every intermediate activation
    (embeddings, post-positional, attention out, norm1, FFN, norm2, logits)
  - Run the verilator binary on the same input tokens
  - Compare each intermediate stage with `compare()`

The first stage that fails localizes the seam where hardware diverges from
torch. Tolerances grow per stage to absorb compounding quantization noise.
"""
import os
import numpy as np
import torch

from module_tester import ModuleTest, compare, REPO_ROOT

SEQ_LEN, EMBED_DIM, VOCAB_SIZE = 8, 16, 40
SCALE = 256.0

BIN = os.path.join("v0", "obj_dir", "test_complete_transformer_decoder",
                   "Vcomplete_transformer_decoder")


def torch_forward_with_intermediates(model, input_ids: torch.Tensor) -> dict:
    """Replicate complete_transformer_decoder's forward, capturing every
    intermediate the hardware exposes."""
    model.eval()
    with torch.no_grad():
        batch, seq_len = input_ids.shape
        positions = torch.arange(seq_len).unsqueeze(0)

        embedded          = model.token_embedding(input_ids)
        pos_embedding     = model.positional_embedding(positions)
        position_encoded  = embedded + pos_embedding

        attention_out     = model.attention(position_encoded)
        norm1_out         = model.layer_norm1(position_encoded + attention_out)

        ffn_out           = model.ffn(norm1_out)
        norm2_out         = model.layer_norm2(norm1_out + ffn_out)

        # Hardware uses last non-zero token position for the output projection.
        nonzero = (input_ids[0] != 0).nonzero(as_tuple=False)
        last_pos = int(nonzero[-1].item()) if nonzero.numel() else 0

        final_logits      = model.output_projection(norm2_out[0, last_pos])
        predicted_token   = int(final_logits.argmax().item())

    return {
        "embedded":         embedded[0].numpy(),
        "position_encoded": position_encoded[0].numpy(),
        "attention_out":    attention_out[0].numpy(),
        "norm1_out":        norm1_out[0].numpy(),
        "ffn_out":          ffn_out[0].numpy(),
        "norm2_out":        norm2_out[0].numpy(),
        "final_logits":     final_logits.numpy(),
        "predicted_token":  predicted_token,
    }


def run_hardware(test: ModuleTest, tokens: list[int]) -> dict:
    """Pad to SEQ_LEN, run the binary, parse intermediate dumps."""
    padded = (tokens + [0] * SEQ_LEN)[:SEQ_LEN]
    in_array = np.array(padded, dtype=np.int16)

    sizes = [
        ("embedded",         SEQ_LEN * EMBED_DIM),
        ("position_encoded", SEQ_LEN * EMBED_DIM),
        ("attention_out",    SEQ_LEN * EMBED_DIM),
        ("norm1_out",        SEQ_LEN * EMBED_DIM),
        ("ffn_out",          SEQ_LEN * EMBED_DIM),
        ("norm2_out",        SEQ_LEN * EMBED_DIM),
        ("final_logits",     VOCAB_SIZE),
        ("predicted_token",  1),
    ]
    total = sum(n for _, n in sizes)
    hw_flat = test.run(in_array, expected_out_size=total, timeout_s=300.0) \
                  if hasattr(test, "_orig_run") else test.run(
                      in_array, expected_out_size=total)

    chunks = {}
    offset = 0
    for name, n in sizes:
        chunks[name] = hw_flat[offset:offset + n]
        offset += n

    return {
        "embedded":         chunks["embedded"].reshape(SEQ_LEN, EMBED_DIM),
        "position_encoded": chunks["position_encoded"].reshape(SEQ_LEN, EMBED_DIM),
        "attention_out":    chunks["attention_out"].reshape(SEQ_LEN, EMBED_DIM),
        "norm1_out":        chunks["norm1_out"].reshape(SEQ_LEN, EMBED_DIM),
        "ffn_out":          chunks["ffn_out"].reshape(SEQ_LEN, EMBED_DIM),
        "norm2_out":        chunks["norm2_out"].reshape(SEQ_LEN, EMBED_DIM),
        "final_logits":     chunks["final_logits"],
        "predicted_token":  int(chunks["predicted_token"][0]),
    }


# Per-stage tolerances. These grow as quantization noise accumulates through
# the pipeline. Tune as needed.
STAGES = [
    ("embedded",         0.01,  0.05),
    ("position_encoded", 0.02,  0.08),
    ("attention_out",    0.10,  0.50),
    ("norm1_out",        0.10,  0.50),
    ("ffn_out",          0.15,  0.80),
    ("norm2_out",        0.15,  0.80),
    ("final_logits",     0.30,  1.50),
]


def compare_one_prompt(tokens: list[int], tag: str, model, test):
    print(f"\n=== {tag}: tokens {tokens} ===")

    padded = (tokens + [0] * SEQ_LEN)[:SEQ_LEN]
    input_ids = torch.tensor([padded], dtype=torch.long)

    torch_out = torch_forward_with_intermediates(model, input_ids)
    hw_out    = run_hardware(test, tokens)

    all_pass = True
    for name, tol_mean, tol_max in STAGES:
        ok = compare(name, hw_out[name], torch_out[name],
                     scale=SCALE, tol_mean=tol_mean, tol_max=tol_max)
        all_pass = all_pass and ok

    hw_tok    = hw_out["predicted_token"]
    torch_tok = torch_out["predicted_token"]
    status    = "PASS" if hw_tok == torch_tok else "FAIL"
    print(f"[{status}] predicted_token{'':<22} "
          f"hw={hw_tok}  torch={torch_tok}")
    all_pass = all_pass and (hw_tok == torch_tok)

    # Top-5 of torch logits for context when tokens disagree
    if hw_tok != torch_tok:
        top5_torch = np.argsort(torch_out["final_logits"])[-5:][::-1]
        top5_hw    = np.argsort(hw_out["final_logits"])[-5:][::-1]
        print(f"       torch top-5: {top5_torch.tolist()}")
        print(f"       hw    top-5: {top5_hw.tolist()}")

    return all_pass


def main():
    from model import DecoderTransformer, Config

    test = ModuleTest("complete_transformer_decoder", BIN, timeout_s=300.0)

    model_path = os.path.join(REPO_ROOT, "models", "decoder_model.pth")
    if not os.path.exists(model_path):
        print(f"No model at {model_path}. Run train.py first.")
        return

    model = DecoderTransformer(Config)
    model.load_state_dict(torch.load(model_path, weights_only=True))
    model.eval()

    # A small variety of prompts: increasing prefix lengths, mix of vocab.
    prompts = [
        ([1, 3, 5],          "START the cat"),
        ([1, 3, 6],          "START the dog"),
        ([1, 4, 5, 8],       "START a cat runs"),
        ([1, 3, 5, 8, 13, 3, 6],  "START the cat runs on the dog"),
    ]

    all_pass = True
    for tokens, tag in prompts:
        ok = compare_one_prompt(tokens, tag, model, test)
        all_pass = all_pass and ok

    print(f"\n{'='*60}")
    print(f"Overall: {'PASS' if all_pass else 'FAIL'}")


if __name__ == "__main__":
    main()
