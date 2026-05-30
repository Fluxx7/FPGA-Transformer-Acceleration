"""Test for argmax: pick the index of the largest logit."""
import os
import numpy as np

from module_tester import ModuleTest

VOCAB_SIZE = 40
BIN = os.path.join("v0", "obj_dir", "test_argmax", "Vargmax")


def main():
    test = ModuleTest("argmax", BIN)
    rng = np.random.default_rng(0)

    # Several random rounds -- argmax is trivial, just check it lands on the
    # right index every time.
    fails = 0
    for trial in range(20):
        logits = rng.integers(-30000, 30000, size=VOCAB_SIZE, dtype=np.int16)
        hw = int(test.run(logits, expected_out_size=1)[0])
        torch_idx = int(np.argmax(logits))
        ok = hw == torch_idx
        if not ok:
            fails += 1
            print(f"  trial {trial}: hw={hw}, torch={torch_idx}, "
                  f"hw_logit={logits[hw]}, torch_logit={logits[torch_idx]}")

    status = "PASS" if fails == 0 else "FAIL"
    print(f"[{status}] argmax                                "
          f"{20 - fails}/20 trials matched")


if __name__ == "__main__":
    main()
