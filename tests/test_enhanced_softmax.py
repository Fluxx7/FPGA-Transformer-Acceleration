import os
import numpy as np
import torch

from module_tester import (
    ModuleTest, compare
)

SEQ_LEN, SCALE = 8, 256.0

SOFTMAX_BINARY = os.path.join("v0", "obj_dir",
                            "test_enhanced_softmax",
                            "Venhanced_softmax")


def torch_softmax_causal(scores_q88: np.ndarray,) -> np.ndarray:
    x = torch.tensor(scores_q88.astype(np.float32) / SCALE)
    mask = torch.tril(torch.ones(SEQ_LEN, SEQ_LEN))
    x = x.masked_fill(mask == 0, float("-inf"))
    return torch.nan_to_num(torch.softmax(x, dim=1), 0.0).numpy()


def main():
    rng = np.random.default_rng(0)
    scores = rng.integers(-1024, 1024, size=(SEQ_LEN, SEQ_LEN), dtype=np.int16)


    test = ModuleTest("enhanced_softmax", SOFTMAX_BINARY)
    hw_out = test.run(scores, expected_out_size=SEQ_LEN * SEQ_LEN).reshape(SEQ_LEN, SEQ_LEN)
    torch_out = torch_softmax_causal(scores)

    compare("enhanced_softmax", hw_out, torch_out, tol_mean=0.05, tol_max=0.3)

if __name__ == "__main__":
    main()
