"""Test for token_embedding: look up each token's row in embedding.mem."""
import os
import numpy as np

from module_tester import ModuleTest, compare, read_mem_q8_8, REPO_ROOT

SEQ_LEN, EMBED_DIM, VOCAB_SIZE, SCALE = 8, 16, 40, 256.0

BIN = os.path.join("v0", "obj_dir", "test_token_embedding",
                   "Vtoken_embedding")
EMB_MEM = os.path.join(REPO_ROOT, "memory", "embedding.mem")


def main():
    test = ModuleTest("token_embedding", BIN)

    # Load embedding table as float (Q8.8 dequantized)
    emb_flat = read_mem_q8_8(EMB_MEM)
    assert emb_flat.size == VOCAB_SIZE * EMBED_DIM, (
        f"embedding has {emb_flat.size} entries, expected "
        f"{VOCAB_SIZE * EMBED_DIM}")
    emb_table = emb_flat.reshape(VOCAB_SIZE, EMBED_DIM)

    rng = np.random.default_rng(0)
    tokens = rng.integers(0, VOCAB_SIZE, size=SEQ_LEN, dtype=np.int16)

    hw = test.run(tokens, expected_out_size=SEQ_LEN * EMBED_DIM) \
              .reshape(SEQ_LEN, EMBED_DIM)
    torch_out = emb_table[tokens]   # direct row lookup

    compare("token_embedding", hw, torch_out,
            tol_mean=0.005, tol_max=0.01)


if __name__ == "__main__":
    main()
