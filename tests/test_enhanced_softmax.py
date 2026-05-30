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


def torch_softmax_simple(scores_q88: np.ndarray,) -> np.ndarray:
    x = torch.tensor(scores_q88.astype(np.float32) / SCALE)
    return torch.softmax(x, dim=1).numpy()



def main():
    rng = np.random.default_rng(0)
    scores = rng.integers(-512, 512, size=(SEQ_LEN, SEQ_LEN), dtype=np.int16)


    test = ModuleTest("enhanced_softmax", SOFTMAX_BINARY)
    hw_out = test.run(scores, expected_out_size=SEQ_LEN * SEQ_LEN, verbose=True).reshape(SEQ_LEN, SEQ_LEN)
    torch_out = torch_softmax_simple(scores)

    compare("enhanced_softmax", hw_out, torch_out, scale=4096, tol_mean=0.05, tol_max=0.3)

if __name__ == "__main__":
    main()
