import subprocess
import numpy as np
import torch
from model import DecoderTransformer, Config
import sys

# Q8.8 scale
SCALE = 256

def quantize(x: torch.Tensor) -> np.ndarray:
    """Float -> int16 Q8.8, matching what the hardware would see."""
    return np.clip(
        np.round(x.detach().cpu().numpy() * SCALE),
        -32768, 32767
    ).astype(np.int16)

def dequantize(x: np.ndarray) -> np.ndarray:
    return x.astype(np.float32) / SCALE

def run_lnorm_sim(input_data: np.ndarray, residual_data: np.ndarray) -> np.ndarray:
    """input_data, residual_data: [SEQ_LEN, EMBED_DIM] int16. Returns same-shape int16."""
    stdin_text = "\n".join(
        str(int(v)) for v in
        np.concatenate([input_data.flatten(), residual_data.flatten()])
    )
    proc = subprocess.run(
        ["v0/obj_dir/Vlayer_normalization"],
        input=stdin_text, capture_output=True, text=True,
        cwd=".",  # so memory/ paths resolve for gamma/beta/rsqrt
        timeout=60,
    )
    if proc.returncode != 0:
        raise RuntimeError(f"sim failed: {proc.stderr}")
    nums = []
    for line in proc.stdout.splitlines():
        line = line.strip()
        if not line:
            continue
        try:
            nums.append(int(line))
        except ValueError:
            # Surface anything weird to stderr but keep parsing
            print(f"[sim non-int line]: {line}", file=sys.stderr)
    flat = np.array(nums, dtype=np.int16)

    expected = input_data.size  # SEQ_LEN * EMBED_DIM
    if len(flat) != expected:
        raise RuntimeError(
            f"expected {expected} output values, got {len(flat)}.\n"
            f"sim stderr:\n{proc.stderr}"
        )
    return flat.reshape(input_data.shape)
#--- Run torch up to the layer_norm1 input ---
model = DecoderTransformer(Config)
model.load_state_dict(torch.load("models/decoder_model.pth", weights_only=True))
model.eval()

#A test input — pick something representative
input_ids = torch.tensor([[1, 3, 5, 0, 0, 0, 0, 0]], dtype=torch.long)

with torch.no_grad():
    # Replicate forward up to layer_norm1
    batch, seq_len = input_ids.shape
    positions = torch.arange(seq_len).unsqueeze(0)
    embeddings    = model.token_embedding(input_ids) + model.positional_embedding(positions)
    attention_out = model.attention(embeddings)
    expected_out  = model.layer_norm1(embeddings + attention_out)

#--- Quantize inputs, run hardware sim, dequantize ---
hw_in  = quantize(attention_out[0])    # [SEQ_LEN, EMBED_DIM]
hw_res = quantize(embeddings[0])
hw_out_int = run_lnorm_sim(hw_in, hw_res)
hw_out = dequantize(hw_out_int)

#--- Compare ---
torch_out = expected_out[0].detach().numpy()

# #Hand-craft an input where you know the LayerNorm answer
# hw_in  = np.array([[256] * 8 + [-256] * 8] * 8, dtype=np.int16)  # alternating ±1 in Q8.8
# hw_res = np.zeros_like(hw_in)
# hw_out_int = run_lnorm_sim(hw_in, hw_res)
# hw_out = dequantize(hw_out_int)
# #Torch reference
# x = torch.tensor(hw_in.astype(np.float32) / 256.0)
# def read_mem_q8_8(path):
#     """Read a .mem file as int16 then dequantize from Q8.8 to float."""
#     vals = []
#     with open(path) as f:
#         for line in f:
#             line = line.strip()
#             if not line: continue
#             v = int(line, 16)
#             if v >= 32768: v -= 65536    # sign-correct from raw hex
#             vals.append(v / 256.0)
#     return torch.tensor(vals, dtype=torch.float32)

# gamma_real = read_mem_q8_8("memory/layernorm1_gamma.mem")
# beta_real  = read_mem_q8_8("memory/layernorm1_beta.mem")

# #Use real gamma/beta in torch
# torch_out = torch.nn.functional.layer_norm(x, (16,), gamma_real, beta_real).numpy()

print(f"\n{'pos':>4} {'torch':>10} {'hardware':>10} {'ratio':>8}")
for s in range(8):
    for d in range(16):
        t, h = torch_out[s,d], hw_out[s,d]
        ratio = h/t if abs(t) > 0.1 else 0
        print(f"({s},{d:2d}) {t:10.4f} {h:10.4f} {ratio:8.3f}")
print(f"torch range:   [{torch_out.min():.3f}, {torch_out.max():.3f}]")
print(f"hardware range:[{hw_out.min():.3f}, {hw_out.max():.3f}]")
print(f"mean abs error: {np.abs(torch_out - hw_out).mean():.4f}")
print(f"max  abs error: {np.abs(torch_out - hw_out).max():.4f}")
print(f"correlation: {np.corrcoef(torch_out.flatten(), hw_out.flatten())[0,1]:.4f}")