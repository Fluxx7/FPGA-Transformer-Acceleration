"""
Test for multi_head_attention: concat of all heads followed by Wo projection.

Uses the same per-head computation as test_attention_head, looped over all
NUM_HEADS heads, concatenated, then projected by attention_wo. Like the other
matmul tests, runs both possible weight layouts so a transpose mismatch shows.
"""
import os
import numpy as np

from module_tester import (
    ModuleTest, compare, read_mem_q8_8, REPO_ROOT
)

SEQ_LEN, EMBED_DIM, NUM_HEADS, SCALE = 8, 16, 4, 256.0
HEAD_DIM = EMBED_DIM // NUM_HEADS

BIN = os.path.join("v0", "obj_dir", "test_multi_head_attention",
                   "Vmulti_head_attention")
WO_MEM = os.path.join(REPO_ROOT, "memory", "attention_wo.mem")

def head_attention(x, Wq, Wk, Wv):
    Q, K, V = x @ Wq.T, x @ Wk.T, x @ Wv.T
    scores = Q @ K.T / np.sqrt(HEAD_DIM)
    mask = np.triu(np.full((SEQ_LEN, SEQ_LEN), -np.inf), k=1)
    scores = scores + mask
    s = scores - scores.max(axis=-1, keepdims=True)
    e = np.exp(s)
    attn = np.nan_to_num(e / e.sum(axis=-1, keepdims=True), nan=0.0)
    return attn @ V


def full_attention(x_q88, Wq_list, Wk_list, Wv_list, Wo):
    x = x_q88.astype(np.float32) / SCALE
    heads = [head_attention(x, Wq_list[h], Wk_list[h], Wv_list[h])
             for h in range(NUM_HEADS)]
    concat = np.concatenate(heads, axis=-1)   # [SEQ, EMBED_DIM]
    return concat @ Wo.T


def main():
    test = ModuleTest("multi_head_attention", BIN)

    # Per-head Q/K/V weights
    Wq_p, Wk_p, Wv_p = [], [], []   # PyTorch layout interpretation
    Wq_h, Wk_h, Wv_h = [], [], []   # hw-addressing layout
    for head in range(NUM_HEADS):
        wq = read_mem_q8_8(os.path.join(REPO_ROOT, "memory",
                                         f"attention_wq_head{head}.mem"))
        wk = read_mem_q8_8(os.path.join(REPO_ROOT, "memory",
                                         f"attention_wk_head{head}.mem"))
        wv = read_mem_q8_8(os.path.join(REPO_ROOT, "memory",
                                         f"attention_wv_head{head}.mem"))
        Wq_p.append(wq.reshape(HEAD_DIM, EMBED_DIM))
        Wk_p.append(wk.reshape(HEAD_DIM, EMBED_DIM))
        Wv_p.append(wv.reshape(HEAD_DIM, EMBED_DIM))
        Wq_h.append(wq.reshape(EMBED_DIM, HEAD_DIM).T)
        Wk_h.append(wk.reshape(EMBED_DIM, HEAD_DIM).T)
        Wv_h.append(wv.reshape(EMBED_DIM, HEAD_DIM).T)

    wo_flat = read_mem_q8_8(WO_MEM)
    Wo_p = wo_flat.reshape(EMBED_DIM, EMBED_DIM)   # PyTorch nn.Linear convention
    Wo_h = wo_flat.reshape(EMBED_DIM, EMBED_DIM).T   # opposite interpretation

    rng = np.random.default_rng(0)
    x_q88 = rng.integers(-256, 256, size=(SEQ_LEN, EMBED_DIM), dtype=np.int16)

    hw = test.run(x_q88, expected_out_size=SEQ_LEN * EMBED_DIM) \
              .reshape(SEQ_LEN, EMBED_DIM)

    out_p = full_attention(x_q88, Wq_p, Wk_p, Wv_p, Wo_p)
    out_h = full_attention(x_q88, Wq_h, Wk_h, Wv_h, Wo_h)

    print("comparing against BOTH possible weight layouts:")
    compare("multi_head_attention (PyTorch layout)",
            hw, out_p, tol_mean=0.5, tol_max=3.0)
    compare("multi_head_attention (hw-addressing layout)",
            hw, out_h, tol_mean=0.5, tol_max=3.0)


if __name__ == "__main__":
    main()
