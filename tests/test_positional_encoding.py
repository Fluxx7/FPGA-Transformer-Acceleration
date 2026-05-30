"""Test for positional_encoding: input + positional_table, saturated to Q8.8."""
import os
import numpy as np

from module_tester import ModuleTest, compare, read_mem_q8_8, REPO_ROOT

SEQ_LEN, EMBED_DIM, SCALE = 8, 16, 256.0

BIN = os.path.join("v0", "obj_dir", "test_positional_encoding",
                   "Vpositional_encoding")
POS_MEM = os.path.join(REPO_ROOT, "memory", "positional_encoding.mem")


def torch_pos_enc(embed_q88: np.ndarray, pos_table: np.ndarray) -> np.ndarray:
    """Reference: dequantize input, add positional table (already float),
    saturate to Q8.8 range. Matches what the hardware does element-wise."""
    a = embed_q88.astype(np.float32) / SCALE
    out = a + pos_table          # pos_table is already float (post-dequant)
    return np.clip(out, -128.0, 127.99609375)


def main():
    test = ModuleTest("positional_encoding", BIN)

    pos_flat = read_mem_q8_8(POS_MEM)
    assert pos_flat.size == SEQ_LEN * EMBED_DIM, (
        f"pos_enc table has {pos_flat.size} entries, expected "
        f"{SEQ_LEN * EMBED_DIM}")
    pos_table = pos_flat.reshape(SEQ_LEN, EMBED_DIM)

    rng = np.random.default_rng(0)
    embed_q88 = rng.integers(-2048, 2048, size=(SEQ_LEN, EMBED_DIM),
                             dtype=np.int16)

    hw = test.run(embed_q88, expected_out_size=SEQ_LEN * EMBED_DIM) \
              .reshape(SEQ_LEN, EMBED_DIM)
    torch_out = torch_pos_enc(embed_q88, pos_table)

    compare("positional_encoding", hw, torch_out,
            tol_mean=0.02, tol_max=0.05)


if __name__ == "__main__":
    main()
