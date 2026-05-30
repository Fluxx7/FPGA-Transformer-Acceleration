"""
Reusable framework for module-level co-simulation tests.

Each per-module test:
  1. Constructs a `ModuleTest` pointing at a verilator binary.
  2. Calls `.run(*input_arrays, expected_out_size=N)` to drive the sim and
     parse stdout as int16s.
  3. Calls `compare(...)` to print a pass/fail line against a torch reference.

Helpers:
  read_mem_q8_8(path)   -- Load a .mem file as float (sign-corrected Q8.8).
  quantize_q8_8(arr)    -- Quantize a float array to Q8.8 int16 with saturation.
"""
from __future__ import annotations

import os
import subprocess
import sys
import numpy as np

# Make `from model import ...` work when tests are run from anywhere
REPO_ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
if REPO_ROOT not in sys.path:
    sys.path.insert(0, REPO_ROOT)


class ModuleTest:
    def __init__(self, name: str, binary: str,
                 cwd: str = REPO_ROOT, timeout_s: float = 120.0):
        if not os.path.isabs(binary):
            binary = os.path.join(cwd, binary)
        # Tolerate .exe suffix on Windows builds
        if not os.path.exists(binary) and os.path.exists(binary + ".exe"):
            binary = binary + ".exe"
        if not os.path.exists(binary):
            raise FileNotFoundError(
                f"{name} sim binary not found at {binary}.\n"
                f"Build it first:  cd v0 && make test-{name}"
            )
        self.name = name
        self.binary = binary
        self.cwd = cwd
        self.timeout_s = timeout_s

    def run(self, *input_arrays: np.ndarray,
            expected_out_size: int, verbose: bool = False) -> np.ndarray:
        """Pipe int16 arrays to stdin, parse int16 outputs from stdout."""
        flat = np.concatenate([a.flatten() for a in input_arrays]).astype(np.int64)
        stdin_text = "\n".join(str(int(v)) for v in flat)

        try:
            proc = subprocess.run(
                [self.binary],
                input=stdin_text,
                stdout=subprocess.PIPE, stderr=subprocess.PIPE,
                cwd=self.cwd, timeout=self.timeout_s,
                text=True, check=False,
            )
        except subprocess.TimeoutExpired as e:
            raise RuntimeError(
                f"{self.name} sim timed out after {self.timeout_s}s"
            ) from e

        if proc.returncode != 0:
            raise RuntimeError(
                f"{self.name} exited {proc.returncode}.\n"
                f"--- stderr tail ---\n"
                + "\n".join(proc.stderr.splitlines()[-20:])
                + "\n--- stdout tail ---\n"
                + "\n".join(proc.stdout.splitlines()[-20:])
            )

        nums = []
        non_int_lines = []
        for line in proc.stdout.splitlines():
            line = line.strip()
            if not line:
                continue
            try:
                nums.append(int(line))
            except ValueError:
                non_int_lines.append(line)

        if verbose:
            for line in non_int_lines:
                print(f"[{self.name} stdout]: {line}", file=sys.stderr)
            for line in proc.stderr.splitlines():
                print(f"[{self.name} stderr]: {line}", file=sys.stderr)

        if len(nums) != expected_out_size:
            raise RuntimeError(
                f"{self.name}: expected {expected_out_size} outputs, "
                f"got {len(nums)}.\n"
                f"--- stderr ---\n{proc.stderr}\n"
                f"--- stdout (non-int lines) ---\n"
                + "\n".join(non_int_lines)
            )

        return np.array(nums, dtype=np.int16)


def compare(name: str,
            hw_int: np.ndarray,
            torch_float: np.ndarray,
            *,
            scale: float = 256.0,
            tol_mean: float = 0.05,
            tol_max: float = 0.30) -> bool:
    """
    Dequantize hw_int by `scale` and compare to torch_float.
    Returns True on pass; prints one summary line either way.
    """
    hw_float = hw_int.astype(np.float32) / scale
    diff = np.abs(hw_float.flatten() - torch_float.flatten())
    mean_err = float(diff.mean())
    max_err = float(diff.max())

    if hw_float.std() == 0 or np.std(torch_float) == 0:
        corr = float("nan")
    else:
        corr = float(np.corrcoef(hw_float.flatten(),
                                 torch_float.flatten())[0, 1])

    passed = (mean_err < tol_mean) and (max_err < tol_max)
    status = "PASS" if passed else "FAIL"
    print(f"[{status}] {name:38s} "
          f"mean_err={mean_err:.4f}  max_err={max_err:.4f}  corr={corr:.4f}")
    return passed


def read_mem_q8_8(path: str) -> np.ndarray:
    """Load a hex-text .mem file and interpret each value as signed Q8.8."""
    vals = []
    with open(path) as f:
        for line in f:
            line = line.strip()
            if not line:
                continue
            v = int(line, 16)
            if v >= 32768:
                v -= 65536
            vals.append(v / 256.0)
    return np.array(vals, dtype=np.float32)


def quantize_q8_8(x: np.ndarray) -> np.ndarray:
    """Quantize a float array to Q8.8 int16 with saturation."""
    return np.clip(np.round(x * 256.0), -32768, 32767).astype(np.int16)
