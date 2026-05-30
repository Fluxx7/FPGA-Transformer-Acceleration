"""
Test for output_projection: hidden @ W.T = logits.

NOTE: the hardware addresses output_proj.mem as
    addr = dim * VOCAB_SIZE + vocab
which means it treats the file as [EMBED_DIM][VOCAB_SIZE] row-major. PyTorch's
nn.Linear.weight is [VOCAB_SIZE][EMBED_DIM] -- so for the hardware reference
to be exact, the file would need to be the *transpose* of what train.py writes.
This test computes the reference both ways so you can see if there's a
transpose mismatch.
"""
import os
import numpy as np

from module_tester import ModuleTest, compare, read_mem_q8_8, REPO_ROOT

EMBED_DIM, VOCAB_SIZE, SCALE = 16, 40, 256.0

BIN = os.path.join("v0", "obj_dir", "test_output_projection",
                   "Voutput_projection")
PROJ_MEM = os.path.join(REPO_ROOT, "memory", "output_proj.mem")


def main():
    test = ModuleTest("output_projection", BIN)

    proj_flat = read_mem_q8_8(PROJ_MEM)
    assert proj_flat.size == EMBED_DIM * VOCAB_SIZE

    rng = np.random.default_rng(0)
    hidden_q88 = rng.integers(-512, 512, size=EMBED_DIM, dtype=np.int16)
    hidden = hidden_q88.astype(np.float32) / SCALE

    hw = test.run(hidden_q88, expected_out_size=VOCAB_SIZE)

    # Reference 1: assume file is [VOCAB_SIZE][EMBED_DIM] (PyTorch layout)
    W_pytorch = proj_flat.reshape(VOCAB_SIZE, EMBED_DIM)
    torch_out_pytorch = hidden @ W_pytorch.T

    # Reference 2: assume file is [EMBED_DIM][VOCAB_SIZE] (what hw addresses)
    W_hw = proj_flat.reshape(EMBED_DIM, VOCAB_SIZE)
    torch_out_hw = hidden @ W_hw

    print("comparing against BOTH possible weight layouts:")
    compare("output_projection (assume PyTorch layout)",
            hw, torch_out_pytorch, tol_mean=0.1, tol_max=0.5)
    compare("output_projection (assume hw-addressing layout)",
            hw, torch_out_hw, tol_mean=0.1, tol_max=0.5)


if __name__ == "__main__":
    main()
