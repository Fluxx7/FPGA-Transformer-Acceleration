"""
Module-level test for layer_normalization.

Two scenarios run in sequence:

  1. Controlled input -- ±1.0 alternating, zero residual. Validates the
     normalization math against torch using the *trained* gamma/beta read
     from the same .mem files the hardware loads.

  2. Model input -- one forward pass through the PyTorch model up to the
     point layer_norm1 is called, comparing hardware against torch at the
     same boundary. Skipped if no trained model is on disk.

Build:
  cd v0 && make test-layer_normalization

Run:
  python tests/test_layer_normalization.py
"""
import os
import numpy as np
import torch

from module_tester import (
    ModuleTest, compare, read_mem_q8_8, quantize_q8_8, REPO_ROOT
)

SEQ_LEN, EMBED_DIM, SCALE = 8, 16, 256.0

LNORM_BINARY = os.path.join("v0", "obj_dir",
                            "test_layer_normalization",
                            "Vlayer_normalization")
GAMMA_PATH = os.path.join(REPO_ROOT, "memory", "layernorm1_gamma.mem")
BETA_PATH  = os.path.join(REPO_ROOT, "memory", "layernorm1_beta.mem")


def torch_layer_norm(input_q88: np.ndarray,
                     residual_q88: np.ndarray,
                     gamma: np.ndarray,
                     beta: np.ndarray) -> np.ndarray:
    """
    Float reference that mirrors the hardware sequence:
        sum = saturate_q8_8(input + residual)
        out = LayerNorm(sum; gamma, beta)
    """
    a = input_q88.astype(np.float32) / SCALE
    b = residual_q88.astype(np.float32) / SCALE
    s = np.clip(a + b, -128.0, 127.99609375)        # Q8.8 saturation bounds
    s_t = torch.tensor(s, dtype=torch.float32)
    return torch.nn.functional.layer_norm(
        s_t, (EMBED_DIM,),
        torch.tensor(gamma), torch.tensor(beta),
    ).numpy()


def scenario_controlled(test: ModuleTest,
                        gamma: np.ndarray, beta: np.ndarray) -> bool:
    print("\n--- Scenario 1: controlled input (+1/-1 alternating) ---")
    pattern = np.array([256] * 8 + [-256] * 8, dtype=np.int16)
    hw_in   = np.tile(pattern, (SEQ_LEN, 1))
    hw_res  = np.zeros_like(hw_in)

    hw_out = test.run(hw_in, hw_res,
                      expected_out_size=SEQ_LEN * EMBED_DIM) \
                  .reshape(SEQ_LEN, EMBED_DIM)
    torch_out = torch_layer_norm(hw_in, hw_res, gamma, beta)

    return compare("layer_normalization (controlled)", hw_out, torch_out)


def scenario_model(test: ModuleTest,
                   gamma: np.ndarray, beta: np.ndarray) -> bool:
    print("\n--- Scenario 2: real model input ---")
    model_path = os.path.join(REPO_ROOT, "models", "decoder_model.pth")
    if not os.path.exists(model_path):
        print(f"  SKIPPED: no model at {model_path} -- run train.py first")
        return True   # treat as pass

    # Lazy-import so the script still works if model.py changes a lot
    from model import DecoderTransformer, Config
    model = DecoderTransformer(Config)
    model.load_state_dict(torch.load(model_path, weights_only=True))
    model.eval()

    input_ids = torch.tensor([[1, 3, 5, 0, 0, 0, 0, 0]], dtype=torch.long)
    with torch.no_grad():
        positions = torch.arange(SEQ_LEN).unsqueeze(0)
        embeddings = (model.token_embedding(input_ids)
                      + model.positional_embedding(positions))
        attention_out = model.attention(embeddings)

    hw_in  = quantize_q8_8(attention_out[0].numpy())
    hw_res = quantize_q8_8(embeddings[0].numpy())

    hw_out = test.run(hw_in, hw_res,
                      expected_out_size=SEQ_LEN * EMBED_DIM) \
                  .reshape(SEQ_LEN, EMBED_DIM)
    torch_out = torch_layer_norm(hw_in, hw_res, gamma, beta)

    return compare("layer_normalization (model)", hw_out, torch_out)


def main():
    test = ModuleTest("layer_normalization", LNORM_BINARY)

    gamma = read_mem_q8_8(GAMMA_PATH)
    beta  = read_mem_q8_8(BETA_PATH)
    assert gamma.size == EMBED_DIM, (
        f"gamma has {gamma.size} entries, expected {EMBED_DIM}. "
        f"Did you retrain with the current EMBED_DIM?")

    ok1 = scenario_controlled(test, gamma, beta)
    ok2 = scenario_model(test, gamma, beta)

    if not (ok1 and ok2):
        raise SystemExit(1)


if __name__ == "__main__":
    main()
