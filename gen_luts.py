#!/usr/bin/env python3
"""
gen_luts.py

Generates the two fixed-function lookup tables used by the hardware:

    memory/rsqrt_lut.mem   1/sqrt(m) for m in [1, 4), 64 entries, Q1.15 unsigned
    memory/exp_lut.mem     exp(x)    for x in [-8, 0],  64 entries, Q8.8 signed

These are content-only ROMs -- they don't depend on the trained model, so this
script can run once after cloning and the .mem files can otherwise stay put.
The pre-synth staging hook (Vivado/stage_mem_files.tcl) already grabs every
*.mem in memory/, so once written these are picked up automatically.

Run from the FPGA-Transformer-Acceleration/ repo root:

    python gen_luts.py
"""

from __future__ import annotations
import math
import os
import numpy as np

from model import save_memory_file

MEM_DIR = "memory"

# =============================================================================
# 1/sqrt(m) lookup
# =============================================================================
#
# How it's used in the layer_normalization rewrite:
#
#   Given variance V (a non-negative integer), normalize into
#       V = 4^k * m       where m in [1, 4)
#   by locating the leading set bit.
#
#       n = floor(log2(V))
#       k = n >> 1                          // integer
#       m = V >> (2*k - 6)                  // pulled into a 6-bit fixed-point
#                                           // index covering [1, 4) over [0, 64)
#       rsqrt_m  = rsqrt_lut[m_index]       // Q1.15 unsigned
#       rsqrt_V  = rsqrt_m >> k             // shift back by k
#
# So the LUT only covers a 2-bit dynamic range; the surrounding shifter handles
# the rest. 64 entries is a fine balance between accuracy (~6 bits in the
# mantissa, ~half-bit error after the shift) and size (128 bytes -- fits in a
# single LUTRAM slice or one distributed BRAM).
#
# Q-format note: rsqrt(m) for m in [1, 4) lands in (0.5, 1.0]. We store it as
# Q1.15 *unsigned* to get the maximum precision (~15 bits) for the value 1.0.
# That means rsqrt(1.0) = 1.0 -> 0x8000, which is -32768 if you sign-extend
# accidentally -- make sure the using Verilog treats this as `wire [15:0]` and
# not `wire signed [15:0]`. Then the multiply (signed_x * unsigned_rsqrt) is
# what you want.
# =============================================================================

RSQRT_LUT_SIZE   = 64           # must be a power of 2
RSQRT_OUT_FRAC   = 15           # Q1.15

def gen_rsqrt_lut() -> np.ndarray:
    """64 entries of 1/sqrt(m), m in [1, 4), Q1.15 unsigned."""
    entries = np.zeros(RSQRT_LUT_SIZE, dtype=np.uint16)
    for i in range(RSQRT_LUT_SIZE):
        # Mantissa covers [1, 4); we sample at the *midpoint* of each bin so
        # the worst-case rounding error is symmetric (~half a bin instead of
        # one full bin).
        m = 1.0 + 3.0 * (i + 0.5) / RSQRT_LUT_SIZE
        rsqrt_m = 1.0 / math.sqrt(m)
        scaled = round(rsqrt_m * (1 << RSQRT_OUT_FRAC))
        # rsqrt(1) hits 32768; clamp to fit uint16 just in case rounding pushes
        # the boundary entry over.
        entries[i] = min(scaled, 0xFFFF)
    return entries

# =============================================================================
# exp(x) lookup
# =============================================================================
#
# How it's used in enhanced_softmax:
#
#   exp() inputs are already shifted by max(scores) -- the standard softmax
#   numerical-stability trick -- so x is always <= 0. exp(-8) ~= 3e-4 in real
#   units, which in Q8.8 underflows to zero, so we don't need to go any lower
#   than -8 in the LUT.
#
#       clamped = (x_q8_8 < -2048) ? -2048 : (x_q8_8 > 0 ? 0 : x_q8_8);
#       index   = (-clamped) >>> 5;          // [0, 2048] / 32 -> [0, 64)
#       exp_val = exp_lut[index];            // Q8.8 unsigned, [0, 256]
#
# The shift amount of 5 comes from:
#       LUT covers |x| in [0, 8.0]   => 2048 in Q8.8
#       LUT_SIZE = 64                => 32 q8.8 units per index
#       log2(32) = 5
#
# Output is in Q8.8 because the rest of the softmax pipeline already works in
# that representation (exp(0) = 1.0 -> 256, which fits easily in 16 bits).
# Storage is technically *unsigned* but the values never go above 256 so signed
# vs unsigned doesn't matter at the boundary.
#
# Linear interpolation between bins would buy you a substantial accuracy bump
# at the cost of one subtract + one multiply + one shift in the consumer --
# easy to add later by widening the index to (5 + 3) bits and using the bottom
# 3 as the interpolation fraction. The LUT itself stays the same.
# =============================================================================

EXP_LUT_SIZE     = 64
EXP_INPUT_CLAMP  = 8.0          # exp(-8) underflows in Q8.8 -- don't go lower
EXP_OUT_FRAC     = 8            # Q8.8

def gen_exp_lut() -> np.ndarray:
    """64 entries of exp(x), x in [-EXP_INPUT_CLAMP, 0], Q8.8."""
    entries = np.zeros(EXP_LUT_SIZE, dtype=np.uint16)
    for i in range(EXP_LUT_SIZE):
        # Sample at bin midpoints, matching the rsqrt LUT's convention.
        # index 0 corresponds to x in (-CLAMP/N, 0], so midpoint x = -CLAMP/(2N)
        x = -EXP_INPUT_CLAMP * (i + 0.5) / EXP_LUT_SIZE
        exp_x = math.exp(x)
        scaled = round(exp_x * (1 << EXP_OUT_FRAC))
        entries[i] = max(0, min(scaled, 0xFFFF))
    return entries


# =============================================================================
# Driver
# =============================================================================

def _write_lut(name: str, data: np.ndarray) -> None:
    path = os.path.join(MEM_DIR, name)
    # save_memory_file expects int-ish; pass through as int16-shaped uint16
    # (the function masks to data_width bits anyway, so signedness doesn't
    # matter for the file contents).
    save_memory_file(data.astype(np.int16), path, data_width=16)
    print(f"  {path:35s} {len(data):4d} entries  "
          f"min=0x{int(data.min()):04x}  max=0x{int(data.max()):04x}")

def main() -> None:
    os.makedirs(MEM_DIR, exist_ok=True)
    print("--- Generating lookup tables ---")
    _write_lut("rsqrt_lut.mem", gen_rsqrt_lut())
    _write_lut("exp_lut.mem",   gen_exp_lut())
    print("done.")

if __name__ == "__main__":
    main()
