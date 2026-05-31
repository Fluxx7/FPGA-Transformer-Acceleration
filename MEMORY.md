# FPGA Transformer Acceleration — Session Memory

Context for resuming work in a fresh Claude session. Living document.

## Project overview

WPI MQP (CS + CompE). A small decoder-only transformer is trained in PyTorch,
quantized to int16 fixed-point, and inferred on a PYNQ-Z1 (Xilinx Zynq-7020)
via a Verilog accelerator. Reference Python model + hardware accelerator share
the same weight files; module-level co-simulation verifies hardware matches
torch within Q8.8 quantization noise.

- Main Vivado project: `C:/MQP/mqp_real/mqp_real.xpr` (Windows)
- Verilator builds: typically run on macOS at `~/MQP/Hardware_PC/`
- Target board: PYNQ-Z1, currently running FCLK_CLK0 at **3 MHz** (dropped from
  50 MHz to close timing — layer_norm's variance-sqrt chain was 954 logic
  levels deep at -278ns WNS; the rsqrt LUT fix below makes higher clock
  feasible but not yet re-attempted)

## Current model config (`model.py:Config`)

```
VOCAB_SIZE = 40
EMBED_DIM  = 16
SEQ_LEN    = 8
NUM_HEADS  = 4
HEAD_DIM   = EMBED_DIM / NUM_HEADS = 4
FFN_DIM    = 128
DATA_WIDTH = 16   # Q8.8 throughout the pipeline
```

The hardware was originally written for EMBED_DIM=64, NUM_HEADS=8, FFN_DIM=256.
Most parameters now propagate via `-G` flags in the Verilator Makefile and via
explicit BD parameter overrides in Vivado. **HEAD_DIM** was a long-standing
silent footgun: it's an independent parameter on `attention_head.sv` (default
8) and was being left at the default. Now derived as a `localparam` in
`multi_head_attention.sv` from EMBED_DIM/NUM_HEADS, and explicitly set to 4
in the standalone test Makefile.

## Conventions (read carefully — these have caused multiple bugs)

- **Q8.8 fixed-point** is the universal interpretation. Integer value =
  real value × 256. `quantize_weight` in `model.py` uses a **fixed scale of
  256** (not the original per-tensor scale). Don't revert.

- **Weight files are saved transposed** for all matmul layers. Hardware
  reads `attention_w*`, `ffn_w*`, and `output_proj.mem` as
  `[in_dim][out_dim]` row-major. PyTorch `nn.Linear.weight` is
  `[out_dim][in_dim]` row-major. So train.py exports must use
  `.T.contiguous()` before flatten. Pattern:
  ```python
  save_memory_file(quantize_weight(W.T.contiguous(), 16), "memory/...", 16)
  ```
  This applies to:
  - `output_proj.mem` (output_projection.weight)
  - `attention_wq_head{h}.mem`, `attention_wk_head{h}.mem`, `attention_wv_head{h}.mem`
  - `attention_wo.mem`
  - `ffn_w1.mem`, `ffn_w2.mem`
  Biases (`ffn_b1`, `ffn_b2`, `layernorm*_beta`, `layernorm*_gamma`) are
  1D — no transpose.

- **Softmax outputs Q4.12** (probabilities × 4096), not Q8.8. The `<< 12`
  shift in `enhanced_softmax`'s NORMALIZE state bakes this in.

- **Per-module test framework** in `tests/` (Python) + `v0/sim/cpp/test_*.cpp`
  (C++). All tests follow the same pattern: stdin = int16 inputs, stdout =
  int16 outputs, stderr = progress + intermediate dumps. `ModuleTest` and
  `compare()` from `tests/module_tester.py`.

## Verification status (last known)

| Module                       | Status | Notes                                    |
|------------------------------|--------|------------------------------------------|
| `argmax`                     | ✓ 20/20 | trivial |
| `positional_encoding`        | ✓ | after fixing pipeline timing (memory read off-by-one) |
| `token_embedding`            | ✓ | no changes needed |
| `output_projection`          | ✓ 1.0 corr | after train.py `.T` fix |
| `layer_normalization`        | ✓ 1.0 ctrl, 0.999 model | rsqrt LUT, NBA cleanup, scale fixes |
| `enhanced_softmax`           | ✓ 0.999 standalone | exp LUT replacing piecewise-linear hack |
| `feed_forward_network`       | ✓ 1.0 | hw-layout reference test |
| `attention_head`             | ✓ 0.9991 | needed HEAD_DIM param + K/V missing-last-MAC fix + softmax clamp fix + score scaling |
| `multi_head_attention`       | ✓ high | inherits attention_head's fixes |
| `complete_transformer_decoder` (e2e) | ✓ ~1.0 corr | passes near 1.0 after retraining with a larger training set (2026-05-30); attention_out still has a smaller residual drop in the overall process but no longer catastrophic |

## Known active issues

1. **attention_out residual drop in e2e is now smaller** (2026-05-30) after
   retraining with a larger training set — likely because broader weight
   distribution avoids the clustered Q/K values that pushed softmax inputs
   into the same exp-LUT bin. The standalone module is 0.999. Characterize
   as a (now milder) quantization ceiling. Fix would still be linear
   interpolation in the exp LUT consumer if it ever needs to be tightened.

2. **"the dog" prompt logit collapse** — previously the final_logits
   correlation crashed for that prompt while others recovered cleanly. The
   retrain on a larger set may have shifted the activation magnitudes
   enough that the suspected `output_projection` accumulator overflow no
   longer trips. Re-check `tests/test_complete_transformer_decoder.py`'s
   per-prompt logit ranges on the new model before assuming it's gone; if
   any prompt's hw logits saturate to ±32767 while torch is much smaller,
   the saturation-before-cast fix in `output_projection.sv` is still the
   right move.

3. **Bitstream needs a rebuild.** Last bitstream on the board predates a
   bunch of these RTL fixes (rsqrt LUT, exp LUT, attention timing/scaling,
   weight transposes). The PYNQ inference will produce different (likely
   better) results once the bit is regenerated and `interface.py --backend hw`
   is re-run.

4. **Score scaling shift** (`SCORE_SHIFT` in attention_head) is hardcoded to
   9 — correct for HEAD_DIM=4 (sqrt(4)=2, shift = 8+1). For HEAD_DIM={1,16,64}
   it's still exact (perfect squares). For non-square HEAD_DIM (8, 32, etc.)
   the constant scale on scores cancels through softmax's max-subtraction,
   so it's effectively right anyway, just not literally `/sqrt(d)`.

## Quick reference: how to do common things

### Build a module test and run it
```bash
cd v0 && make test-<module_name>
cd .. && python tests/test_<module_name>.py
```

### Build everything
```bash
cd v0 && make tests
```

### Re-export weights without retraining
```python
# from a python prompt:
from model import DecoderTransformer, Config
import torch
from train import export_model_weights
m = DecoderTransformer(Config)
m.load_state_dict(torch.load("models/decoder_model.pth", weights_only=True))
export_model_weights(m)
```

### Run the end-to-end model
```bash
# Torch reference:
python interface.py --backend torch --prompt "the cat"

# Verilator sim:
python interface.py --backend verilator --prompt "the cat"

# Hardware (only on PYNQ board):
python interface.py --backend hw --prompt "the cat"
```

### Generate LUT files
```bash
python gen_luts.py    # writes memory/rsqrt_lut.mem, memory/exp_lut.mem
```

## Test framework files

- `tests/module_tester.py` — `ModuleTest`, `compare()`, `read_mem_q8_8()`,
  `quantize_q8_8()`, `REPO_ROOT`. Inserts repo root into `sys.path` so
  `from model import ...` works from tests/.
- `tests/test_<module>.py` — per-module driver. Pattern:
  1. Load .mem files via `read_mem_q8_8` and reshape with `.reshape(IN, OUT).T`
     for hw-layout weights.
  2. Build random or controlled input.
  3. Run hardware via `test.run(...)`.
  4. Run torch reference using the same dequantized weights.
  5. `compare()` each stage with appropriate `scale=` (256 for Q8.8, 4096 for
     Q4.12 softmax outputs).
- `tests/test_complete_transformer_decoder.py` — e2e test with per-stage
  intermediate comparisons against torch.

## Vivado side

- `Vivado/project_setup.tcl` — sources the `stage_mem_files.tcl` hook on
  `synth_1` AND the OOC wrapper run, clears stale incremental-synth refs,
  suppresses benign `rst_ps7_0_50M` warnings. Run once per project clone.
- `Vivado/stage_mem_files.tcl` — pre-synth hook that copies `memory/*.mem`
  into the run's working dir so `$readmemh` resolves.
- `Vivado/transformer_axi_wrapper.v` — AXI4-Lite wrapper. Recent changes:
  done/valid are now **latched** (sticky), so software can poll without
  catching the 1-cycle FINISHED pulse. Predicted_token width derives from
  `$clog2(VOCAB_SIZE)`.
- `Vivado/transformer_driver.py` — PYNQ driver. Copy to board along with
  `.bit` and `.hwh` files (must share basename for PYNQ to find both).

## Architecture: hardware vs PyTorch model alignment

The hardware's `complete_transformer_decoder.sv` exactly mirrors `model.py`'s
`DecoderTransformer.forward()`:

```
                  PyTorch                          Hardware
                  -------                          --------
input_ids     →   token_embedding(x)           →   token_embedding (lookup, $readmemh embedding.mem)
              +   positional_embedding(pos)    +   positional_encoding (saturated add)
position_encoded                                   position_encoded
              →   attention(position_encoded)  →   multi_head_attention → attention_head ×4 (no transformer block split; single layer)
              +   (residual: position_encoded) +   (residual handled in layer_normalization)
              →   layer_norm1(...)             →   layer_normalization #1
              →   ffn(...)                     →   feed_forward_network
              +   (residual: norm1_out)        +
              →   layer_norm2(...)             →   layer_normalization #2
              →   output_projection            →   output_projection (uses norm2_out[last_pos])
              →   argmax                       →   argmax
predicted_token                                    predicted_token
```

Single transformer block (no stacking). All weights in `memory/*.mem`.

## Workflow advice for a fresh session

1. Read `MEMORY.md` (this file) first.
2. Check `tests/test_complete_transformer_decoder.py` output to see current
   per-stage error levels — first stage that fails locates the active bug.
3. For new bugs in any module: run the standalone test for that module first
   (`python tests/test_<module>.py`). If it passes, the bug is in the seam
   between modules or in weight layout (probably train.py).
4. When asked to add a feature or fix a bug:
   - Check `MEMORY.md` conventions section first
   - Use the existing test framework rather than ad-hoc print debugging
   - Update `MEMORY.md` after substantial changes (status table, known
     issues, conventions)

## Files NOT to revert without explicit ask

The user has made intentional changes to these — they may diverge from what
the conversation appears to leave them as:

- `tests/test_*.py` — user has been tuning tolerances and test inputs
- `v0/Makefile` — user added test targets, parameter handling
- `gen_luts.py` — has both old (commented) and new rsqrt LUT formats
- All RTL files under `v0/rtl/` — user has made many bug fixes; current
  state reflects the cumulative result of the debug history above
- `train.py` — `.T.contiguous()` added to weight exports
- `.gitignore` — ignores most generated artifacts, including memory/ and
  models/

## Open questions / future work mentioned

- **Embeddings-as-input refactor**: Plan to remove `token_embedding`,
  `output_projection`, and `argmax` from hardware, so the accelerator
  becomes vocab-size-agnostic and the host does sampling. Output: final
  hidden state. Discussed in detail; not started.
- **Larger model training**: User wants to push model capability by
  expanding training templates and using random-window sampling of chained
  sentences (so the model learns mid-context patterns for sliding-window
  inference). Template-driven generator already in place via `TEMPLATES`
  list in `model.py`.
- **Bit-rebuild and PYNQ verification** after the many RTL fixes — likely
  the most impactful next single action for a demonstrable result.
