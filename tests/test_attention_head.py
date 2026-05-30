"""
Test for attention_head (single head, defaults to head 0).

Replicates the per-head attention compute:
    Q = x @ Wq.T,  K = x @ Wk.T,  V = x @ Wv.T
    scores = Q @ K.T / sqrt(HEAD_DIM)
    masked causal softmax
    out = attn @ V

Compares against both weight layout interpretations like the other matmul
tests, since attention_head likely has the same transpose ambiguity.
"""
import os
import numpy as np

from module_tester import (
    ModuleTest, compare, read_mem_q8_8, REPO_ROOT
)

SEQ_LEN, EMBED_DIM, NUM_HEADS, SCALE = 8, 16, 4, 256.0
HEAD_DIM = EMBED_DIM // NUM_HEADS

BIN = os.path.join("v0", "obj_dir", "test_attention_head",
                   "Vattention_head")
WQ_MEM = os.path.join(REPO_ROOT, "memory", "attention_wq_head0.mem")
WK_MEM = os.path.join(REPO_ROOT, "memory", "attention_wk_head0.mem")
WV_MEM = os.path.join(REPO_ROOT, "memory", "attention_wv_head0.mem")


def head_attention(x_q88, Wq, Wk, Wv):
    """Compute one attention head's output. Q/K/V matrices already shaped
    [HEAD_DIM, EMBED_DIM] (PyTorch nn.Linear weight convention)."""
    x = x_q88.astype(np.float32) / SCALE
    Q = x @ Wq.T   # [SEQ, HEAD_DIM]
    K = x @ Wk.T
    V = x @ Wv.T

    scores = Q @ K.T / np.sqrt(HEAD_DIM)
    mask = np.triu(np.full((SEQ_LEN, SEQ_LEN), -np.inf), k=1)
    scores = scores + mask
    # Softmax stable
    s = scores - scores.max(axis=-1, keepdims=True)
    e = np.exp(s)
    attn = e / e.sum(axis=-1, keepdims=True)
    attn = np.nan_to_num(attn, nan=0.0)
    return attn @ V  # [SEQ, HEAD_DIM]


def main():
    test = ModuleTest("attention_head", BIN)

    wq_flat = read_mem_q8_8(WQ_MEM)
    wk_flat = read_mem_q8_8(WK_MEM)
    wv_flat = read_mem_q8_8(WV_MEM)
    assert wq_flat.size == HEAD_DIM * EMBED_DIM

    rng = np.random.default_rng(0)
    x_q88 = rng.integers(-256, 256, size=(SEQ_LEN, EMBED_DIM), dtype=np.int16)

    hw = test.run(x_q88, expected_out_size=SEQ_LEN * HEAD_DIM) \
              .reshape(SEQ_LEN, HEAD_DIM)

    # Layout interpretation 1: PyTorch convention [HEAD_DIM, EMBED_DIM]
    Wq_p = wq_flat.reshape(HEAD_DIM, EMBED_DIM)
    Wk_p = wk_flat.reshape(HEAD_DIM, EMBED_DIM)
    Wv_p = wv_flat.reshape(HEAD_DIM, EMBED_DIM)
    out_p = head_attention(x_q88, Wq_p, Wk_p, Wv_p)

    # Layout interpretation 2: hw-addressing [EMBED_DIM, HEAD_DIM]
    Wq_h = wq_flat.reshape(EMBED_DIM, HEAD_DIM).T
    Wk_h = wk_flat.reshape(EMBED_DIM, HEAD_DIM).T
    Wv_h = wv_flat.reshape(EMBED_DIM, HEAD_DIM).T
    out_h = head_attention(x_q88, Wq_h, Wk_h, Wv_h)

    print("comparing against BOTH possible weight layouts:")
    compare("attention_head (PyTorch layout)",
            hw, out_p, tol_mean=0.5, tol_max=2.0)
    compare("attention_head (hw-addressing layout)",
            hw, out_h, tol_mean=0.5, tol_max=2.0)


if __name__ == "__main__":
    main()
