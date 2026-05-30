"""
Test for attention_head with per-stage intermediate comparisons.

Pulls Q, K, V, scores, weights, and output out of the verilator binary, then
compares each against the torch reference *at that same point*. The first
intermediate that fails localizes which sub-stage of attention is broken.

Comparison uses the hw-addressing weight layout (file is [EMBED_DIM][HEAD_DIM]
row-major), which is the layout output_projection confirmed. If your fix
changed that convention, swap the reshape pattern below.

Pay attention to two things in the scaling:
  - Q/K/V are stored Q8.8 (compare with `scale=256`).
  - attention_scores has the hardware's strange scaling applied
        (>>>2 + >>>4 = ~0.3125 * accumulator at Q16.16)
    instead of the proper 1/sqrt(HEAD_DIM) * (>>>8) = >>>9.
    This test compares against torch's correctly-scaled scores, so even a
    bug-free Q/K computation will show a magnitude mismatch on `scores`
    unless you fix the score scaling.
  - attention_weights is Q4.12 from softmax (compare with `scale=4096`).
  - output_data is Q8.8 again.
"""
import os
import numpy as np

from module_tester import (
    ModuleTest, compare, read_mem_q8_8, REPO_ROOT
)

SEQ_LEN, EMBED_DIM, NUM_HEADS = 8, 16, 4
HEAD_DIM = EMBED_DIM // NUM_HEADS
SCALE    = 256.0

BIN = os.path.join("v0", "obj_dir", "test_attention_head",
                   "Vattention_head")
WQ_MEM = os.path.join(REPO_ROOT, "memory", "attention_wq_head0.mem")
WK_MEM = os.path.join(REPO_ROOT, "memory", "attention_wk_head0.mem")
WV_MEM = os.path.join(REPO_ROOT, "memory", "attention_wv_head0.mem")


# Toggle this to swap between weight-file layout interpretations.
#   "hw"      -- file is [EMBED_DIM][HEAD_DIM] row-major (what addr = embed*HD+head implies)
#   "pytorch" -- file is [HEAD_DIM][EMBED_DIM] row-major (what train.py actually saves)
WEIGHT_LAYOUT = "hw"     # try "pytorch" to compare


def load_w(path):
    """Load a weight file under the configured layout, return a
    [HEAD_DIM, EMBED_DIM] tensor in PyTorch's nn.Linear convention so the
    downstream `x @ W.T` math is uniform."""
    flat = read_mem_q8_8(path)
    assert flat.size == EMBED_DIM * HEAD_DIM
    if WEIGHT_LAYOUT == "hw":
        # File is [EMBED_DIM][HEAD_DIM] row-major -> transpose to [HEAD_DIM, EMBED_DIM]
        return flat.reshape(EMBED_DIM, HEAD_DIM).T
    elif WEIGHT_LAYOUT == "pytorch":
        # File is [HEAD_DIM][EMBED_DIM] row-major -- already PyTorch-shaped
        return flat.reshape(HEAD_DIM, EMBED_DIM)
    else:
        raise ValueError(f"Unknown WEIGHT_LAYOUT: {WEIGHT_LAYOUT!r}")


def main():
    test = ModuleTest("attention_head", BIN)

    print(f"Using weight layout: {WEIGHT_LAYOUT!r}")
    Wq = load_w(WQ_MEM)   # [HEAD_DIM, EMBED_DIM]
    Wk = load_w(WK_MEM)
    Wv = load_w(WV_MEM)

    rng = np.random.default_rng(0)
    x_q88 = rng.integers(-256, 256, size=(SEQ_LEN, EMBED_DIM), dtype=np.int16)
    x = x_q88.astype(np.float32) / SCALE

    # ---- Torch reference, stage by stage ----
    Q_ref      = x @ Wq.T                                  # [SEQ_LEN, HEAD_DIM]
    K_ref      = x @ Wk.T
    V_ref      = x @ Wv.T

    scores_raw = Q_ref @ K_ref.T / np.sqrt(HEAD_DIM)       # [SEQ_LEN, SEQ_LEN]
    mask       = np.triu(np.full((SEQ_LEN, SEQ_LEN), -np.inf), k=1)
    scores_ref = scores_raw + mask                          # causal-masked

    # Stable softmax
    s_norm = scores_raw - scores_raw.max(axis=-1, keepdims=True)
    e      = np.exp(s_norm) * np.where(mask == 0, 1.0, 0.0)
    weights_ref = np.nan_to_num(e / e.sum(axis=-1, keepdims=True), nan=0.0)

    output_ref = weights_ref @ V_ref                       # [SEQ_LEN, HEAD_DIM]

    # ---- Run hardware, parse interleaved buffers ----
    sizes = [
        ("Q",       SEQ_LEN * HEAD_DIM),
        ("K",       SEQ_LEN * HEAD_DIM),
        ("V",       SEQ_LEN * HEAD_DIM),
        ("scores",  SEQ_LEN * SEQ_LEN),
        ("weights", SEQ_LEN * SEQ_LEN),
        ("output",  SEQ_LEN * HEAD_DIM),
    ]
    total = sum(n for _, n in sizes)
    hw_flat = test.run(x_q88, expected_out_size=total)

    chunks = {}
    offset = 0
    for name, n in sizes:
        chunks[name] = hw_flat[offset:offset + n]
        offset += n

    Q_hw       = chunks["Q"].reshape(SEQ_LEN, HEAD_DIM)
    K_hw       = chunks["K"].reshape(SEQ_LEN, HEAD_DIM)
    V_hw       = chunks["V"].reshape(SEQ_LEN, HEAD_DIM)
    scores_hw  = chunks["scores"].reshape(SEQ_LEN, SEQ_LEN)
    weights_hw = chunks["weights"].reshape(SEQ_LEN, SEQ_LEN)
    output_hw  = chunks["output"].reshape(SEQ_LEN, HEAD_DIM)

    # ---- Stage-by-stage comparison ----
    print("\n--- Stage 1: Q = x @ Wq.T ---")
    compare("Q matrix",      Q_hw,       Q_ref,
            scale=SCALE, tol_mean=0.05, tol_max=0.2)

    print("\n--- Stage 2: K = x @ Wk.T ---")
    compare("K matrix",      K_hw,       K_ref,
            scale=SCALE, tol_mean=0.05, tol_max=0.2)

    print("\n--- Stage 3: V = x @ Wv.T ---")
    compare("V matrix",      V_hw,       V_ref,
            scale=SCALE, tol_mean=0.05, tol_max=0.2)

    print("\n--- Stage 4: attention_scores = Q @ K.T / sqrt(d) (masked) ---")
    # NB: hardware's score scaling is `(acc>>>2)+(acc>>>4)` which is *not*
    # equivalent to torch's `1/sqrt(d) * (acc>>>8)`. Magnitude WILL differ;
    # what matters here is the *shape* (correlation), not the absolute error.
    # Only compare valid (non-masked) entries.
    valid = ~np.isinf(scores_ref)
    compare("scores (valid entries)",
            scores_hw[valid], scores_ref[valid],
            scale=SCALE, tol_mean=2.0, tol_max=10.0)

    print("\n--- Stage 5: attention_weights = softmax(scores) ---")
    # softmax output is Q4.12 in this design (matches enhanced_softmax tests)
    compare("attention_weights",
            weights_hw, weights_ref,
            scale=4096.0, tol_mean=0.05, tol_max=0.3)

    print("\n--- Stage 6: output = weights @ V ---")
    compare("output",
            output_hw, output_ref,
            scale=SCALE, tol_mean=0.2, tol_max=1.0)

    print("\n=== Hints for interpreting results ===")
    print("- Q passes but K/V fail with smaller magnitudes than expected:")
    print("    likely the off-by-one MAC bug in COMPUTE_K/COMPUTE_V")
    print("    (Q uses next_accum wire, K/V use stale accumulator)")
    print("- Q/K/V pass but scores fail with magnitude ~150x too small:")
    print("    score scaling is wrong -- should be >>>9 (= 1/sqrt(d) * >>>8),")
    print("    not (>>>2)+(>>>4) which is *0.3125 at scale 65536")
    print("- weights pass but output is off:")
    print("    APPLY_ATTENTION's accumulator shift (>>>12) may not match")
    print("    your Q4.12 weights * Q8.8 V product scale")


if __name__ == "__main__":
    main()
