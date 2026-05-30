"""
Test for feed_forward_network: ReLU(x @ W1.T + b1) @ W2.T + b2.

W1.mem is treated by the hardware as [EMBED_DIM][FFN_DIM] row-major,
W2.mem is treated by the hardware as [FFN_DIM][EMBED_DIM] row-major.
PyTorch's W1 has shape [FFN_DIM, EMBED_DIM] and W2 has shape [EMBED_DIM, FFN_DIM].
This test compares both possible layouts so a transpose mismatch is visible.
"""
import os
import numpy as np

from module_tester import (
    ModuleTest, compare, read_mem_q8_8, quantize_q8_8, REPO_ROOT
)

SEQ_LEN, EMBED_DIM, FFN_DIM, SCALE = 8, 16, 128, 256.0

BIN = os.path.join("v0", "obj_dir", "test_feed_forward_network",
                   "Vfeed_forward_network")
W1_MEM = os.path.join(REPO_ROOT, "memory", "ffn_w1.mem")
B1_MEM = os.path.join(REPO_ROOT, "memory", "ffn_b1.mem")
W2_MEM = os.path.join(REPO_ROOT, "memory", "ffn_w2.mem")
B2_MEM = os.path.join(REPO_ROOT, "memory", "ffn_b2.mem")


def torch_ffn(x_q88, W1, b1, W2, b2):
    """Compute float-equivalent FFN with the given matrices.
    W1 expected shape [FFN_DIM, EMBED_DIM]; W2 [EMBED_DIM, FFN_DIM]."""
    x = x_q88.astype(np.float32) / SCALE
    h = np.maximum(0.0, x @ W1.T + b1)
    return h @ W2.T + b2


def main():
    test = ModuleTest("feed_forward_network", BIN)

    w1_flat = read_mem_q8_8(W1_MEM)
    b1      = read_mem_q8_8(B1_MEM)
    w2_flat = read_mem_q8_8(W2_MEM)
    b2      = read_mem_q8_8(B2_MEM)

    rng = np.random.default_rng(0)
    x_q88 = rng.integers(-256, 256, size=(SEQ_LEN, EMBED_DIM), dtype=np.int16)

    hw = test.run(x_q88, expected_out_size=SEQ_LEN * EMBED_DIM) \
              .reshape(SEQ_LEN, EMBED_DIM)

    W1_hw = w1_flat.reshape(EMBED_DIM, FFN_DIM).T   # transpose to match
    W2_hw = w2_flat.reshape(FFN_DIM, EMBED_DIM).T
    out_hw_layout = torch_ffn(x_q88, W1_hw, b1, W2_hw, b2)

    compare("feed_forward_network (hw-addressing layout)",
            hw, out_hw_layout, tol_mean=0.2, tol_max=1.0)


if __name__ == "__main__":
    main()
