# FPGA Transformer Acceleration — Project Context

## What This Project Is

This is Nicholas Armstrong's Major Qualifying Project (MQP) at WPI, counting as a CS MQP (he is a double major). The goal is to design and demonstrate hardware acceleration for a transformer decoder on an FPGA — specifically, a proof of concept showing that embedded systems can run transformer/LLM inference locally without a GPU or internet connection. The motivating use case is privacy-sensitive embedded devices (e.g. medical devices) that need transformer capabilities but cannot outsource computation.

**Andy Armstrong (Nicholas's dad) is assisting with writing, planning, and Claude sessions.** When working in this repo, assume the audience for suggestions and plans is both Andy and Nicholas.

## Hardware Platform

- **Board**: PynQ-Z1 (Zynq — ARM Cortex-A9 + Xilinx FPGA on one chip)
- **Interface**: AXI-Lite memory-mapped registers; Python on the ARM side controls the FPGA via `Vivado/transformer_driver.py`
- **Synthesis tool**: Vivado
- **Simulation**: Verilator (C++ test benches in `v0/sim/cpp/`, driven by Python harness in `tests/`)
- **Number format**: 16-bit fixed-point 8.8 throughout the hardware

## RTL Architecture (`v0/rtl/`)

All modules run **sequentially** (state machine at the top level), except attention heads inside `multi_head_attention` which run in parallel. Execution order:

1. `token_embedding.sv` — looks up learned embedding vector for each input token
2. `positional_encoding.sv` — adds positional encoding (cosine-based) to embeddings
3. `multi_head_attention.sv` — contains N parallel `attention_head.sv` instances; each computes Q/K/V projections, attention scores (with score shift), softmax, and attention application
4. `layer_normalization.sv` — after attention; uses reciprocal square root lookup table
5. `feed_forward_network.sv` — two-layer MLP with bias; uses GELU-like activation
6. `layer_normalization.sv` — second normalization
7. `output_projection.sv` — matrix multiply against learned token weights to produce logits
8. `argmax.sv` — picks highest-logit token

`memory_module.sv` is a generic BRAM wrapper used throughout. `complete_transformer_decoder.sv` is the top-level RTL. `Vivado/transformer_axi_wrapper.v` wraps the top level for AXI-Lite communication with the ARM.

**Key hardware parameters (cut-down version that fits the board):**
- `NUM_HEADS`: 4
- `EMBEDDING_DIM`: 16
- `FFN_DIM`: 64
- `SEQ_LEN`: 8
- `VOCAB_SIZE`: 40

Original repo parameters (too large): 8 heads, 64 embedding dim, 256 FFN dim.

## Software / Python Side

- `model.py` — PyTorch transformer decoder model (provided by original repo, ~200 lines)
- `train.py` — training script; now uses template-based sentence generation (~5000 sentences, ~20 epochs); vocabulary of 40 tokens (articles, animals, verbs, adverbs, adjectives, conjunctions, special tokens)
- `interface.py` — unified inference interface that can use PyTorch backend, Verilator backend, or (eventually) hardware backend
- `compare.py` — runs inference comparison between backends
- `gen_luts.py` — generates lookup table memory files from trained model weights
- `plot.py` — graphs logit comparisons
- `tests/module_tester.py` — Python harness that drives Verilator C++ test benches and computes error/correlation metrics

Training sentence templates (examples):
- `start [article] [animal] [verb] [adverb] end pad pad`
- `start [article] [adjective] [animal] [verb] [adverb] end pad`
- `start [article] [animal] [verb] and [verb] [adverb] end`

## Testing Framework

Each RTL module has a paired C++ Verilator test bench (`v0/sim/cpp/test_<module>.cpp`) and Python driver (`tests/test_<module>.py`). The Python side computes PyTorch reference outputs and compares against hardware simulation outputs, reporting mean error, max error, and Pearson correlation.

**Module test results (as of bug-fix freeze):**

| Module | Correlation | Notes |
|--------|-------------|-------|
| token_embedding | 1.0 | |
| positional_encoding | 1.0 | Fixed pipeline stage timing |
| layer_normalization | 1.0 | Replaced bad sqrt with reciprocal sqrt LUT |
| enhanced_softmax | ~0.9991 | Exponential LUT approximation (64 entries); not 1.0 by nature |
| feed_forward_network | 1.0 | Fixed non-blocking assignment errors in both layers |
| output_projection | 1.0 | Fixed PyTorch vs hardware memory layout (row/col major swap) |
| argmax | 1.0 | Trivial; verified 20 cases first try |
| attention_head | ~0.98+ | Compound error from multiple softmax passes + quantization |
| multi_head_attention | ~0.98+ | Depends on attention_head |
| complete_transformer_decoder | ~0.9996+ final logit correlation (on 5000-sentence trained model) |

**End-to-end demo outputs (from hardware/Verilator):**
- Input `the` → `the cat sleeps gently`
- Input `the cat` → `the cat sleeps gently`
- Input `the dog` → `the dog jumps gently` (after 5000-sentence training; 500-sentence training caused a dog-token edge case)
- Input nothing → `the tall fish jumps gently`

## Key Technical Story Points (important for the paper)

1. **Original repo problems**: All Verilog in a single file, ~5 commits (each dumping a whole file), trained on 12-24 sentences, 220%+ LUT utilization, no constraint file, no AXI interface, various timing bugs.

2. **Getting it on the board**: Added AXI-Lite wrapper, created constraint file, cut parameters (embedding dim, FFN dim, then number of heads as last resort), fixed code to synthesize.

3. **Non-blocking assignment errors**: The original code repeatedly tried to write to a register and read the updated value in the same clock cycle (Verilog non-blocking semantics prevent this). This was the most common bug class and affected layer_normalization, positional_encoding, feed_forward_network (both layers), attention_head, and output_projection.

4. **Lookup table replacements**:
   - Reciprocal square root (for layer norm): replaced a chained-division combinational approximation → now 1.0 correlation (the LUT process naturally compensates for quantization)
   - Exponential function (for softmax): replaced piecewise linear approximation → ~0.9991 correlation; 64-entry LUT can't perfectly approximate a continuous curve, but adding linear interpolation was deemed unnecessary overhead

5. **Score shift insight**: The attention score scaling (divide by sqrt(head_dim)) uses bit shifts instead of true sqrt. The resulting uniform scale error gets cancelled by the subsequent softmax, because softmax normalizes relative values — so this imprecision is harmless. Correlation at this stage is ~1.0.

6. **Memory layout bug**: PyTorch stores weight matrices in row-major order; the hardware was reading them as column-major. Fixed by transposing weight matrices when saving `.mem` files (but NOT transposing bias vectors).

7. **Parameter propagation bug**: `attention_head` was never receiving `HEAD_DIM` from the parent module; it defaulted to 8 instead of the correct 4. Fixed by adding explicit parameterization and computing `HEAD_DIM = EMBEDDING_DIM / NUM_HEADS` at the top level.

8. **Softmax clamp edge case**: Lower clamp bound for the exponential LUT should be -2016 (63×32), not -2048 (64×32). Values in that narrow 32-unit range caused the softmax to fail silently in isolated module tests but became visible in full end-to-end testing with real trained weights. This is a good paper anecdote.

9. **Training data scale matters**: 500 sentences → dog-token embedding went out of quantization range, causing garbage output for `the dog`. 5000 sentences → resolved completely, final logit correlation 0.9996+.

10. **Claude usage**: Claude was used extensively — AXI wrapper, Makefile, test harness framework, sentence generation, debugging analysis. Nicholas's contribution was all architectural decisions, understanding the code, identifying bug classes, and implementing fixes. The paper should acknowledge Claude as a development tool.

## Current Status (as of May 30)

- Feature freeze: done
- Bug fix freeze: ~6am May 30 (last night)
- Hardware and software produce consistent, valid sentences
- SD card acquired; board testing pending
- Still to do before paper submission:
  - Run on actual board and capture results
  - Measure achievable clock speed (timing slack improved after lookup table replacements)
  - Check per-module LUT utilization breakdown in Vivado
  - Generate logit comparison graphs (`plot.py`)
  - Write the report

## Paper Structure Plan

Store report sections as individual `.md` files in `report/`. Work on sections independently (separate Claude sessions per section). Target: send first draft to professor this weekend; final draft Tuesday.

### Section Files

```
report/
  01_introduction.md          # Motivation: embedded systems, privacy, medical devices, no GPU
  02_background.md            # Transformer architecture, fixed-point math, FPGAs, AXI; includes glossary
  03_repository_selection.md  # Hypothetical final product → POC → why this repo; what was missing
  04_model_work.md            # Python model, training data improvements, interface design
  05a_getting_to_board.md     # AXI wrapper, constraint file, parameter reduction experiments
  05b_hardware_validation.md  # Testing framework + per-module debug story (LONGEST, MOST IMPORTANT)
  06_results.md               # Module correlation table, board outputs, utilization, tokens/sec
  07_future_work.md           # Steps 1-4 from GAME_PLAN.md (Step 5 AXI is already done)
  08_conclusion.md
```

### Drafting Priority Order

1. **05b** — Hardware validation (most important, most reviewer attention)
2. **05a** — Getting to the board
3. **04** — Model work (important for CS component of dual-major MQP)
4. **06** — Results (flag TODOs where actual data is needed)
5. **07** — Future work (GAME_PLAN.md Steps 1-4 are raw material; convert to prose)
6. **03** — Repository selection (short, narrative)
7. **02** — Background + glossary (Claude can draft from general knowledge)
8. **08** — Conclusion (write last)
9. **01** — Introduction/motivation (lowest priority for first draft; professor wants expansion but that's for final draft)

### Who Writes What

- **Nicholas must write or heavily review**: `03_repository_selection.md` (the hypothetical final product framing needs his design thinking); all sections need his technical review
- **Andy + Claude can draft**: everything else using transcripts + code as source material
- **Diagrams**: `schematic.svg` is in repo root; use it in 02 or 05a. Per-module diagrams can be generated from Verilog files.

### TODO Items Needing Nicholas

Use `<!-- TODO: -->` comments in section files wherever real data is missing:

- Vivado LUT utilization numbers for each parameter-reduction experiment (on Nicholas's Vivado PC)
- Tokens per second measurement (clock frequency × cycles per inference pass)
- Timing slack before/after rsqrt lookup table fix (needs a new Vivado implementation run)
- Logit comparison graphs (`plot.py` / `compare.py` need to be run with current model)
- Multi-head attention final error numbers (0.1–0.4 range — confirm final value)
- Whether a board run succeeded after SD card acquisition

## Repo Layout Reference

```
v0/rtl/          — SystemVerilog RTL modules
v0/sim/cpp/      — Verilator C++ test benches
v0/sim/sv/       — SystemVerilog testbench
Vivado/          — AXI wrapper, block design, TCL scripts
tests/           — Python test drivers (use module_tester.py framework)
memory/          — Learned weight .mem files (exported from trained model)
models/          — Saved PyTorch model checkpoints
docs/            — Existing brief docs on model/train/compare
context/         — Andy's transcripts and reference material
report/          — (to be created) Paper sections as .md files
model.py         — PyTorch model definition
train.py         — Training script
interface.py     — Unified inference interface
compare.py       — Backend comparison
gen_luts.py      — LUT generation from model weights
GAME_PLAN.md     — Earlier planning document (Claude-generated, partially obsolete)
```

## Diagrams and Report Notes

Per-module Mermaid architecture diagrams live in `report/05b_hardware_validation.md`, inserted before each `### Module Name` subsection with an italic `*Figure: ...*` caption. Diagrams cover: `attention_head`, `feed_forward_network`, `enhanced_softmax`, `layer_normalization`, `output_projection`, `positional_encoding`, `token_embedding`. No diagrams for `argmax`, `multi_head_attention`, or `complete_transformer_decoder`.

**Mermaid syntax rules for VS Code preview compatibility** (learned the hard way — breaking any of these causes "No diagram type detected" for the whole block):
- Do **not** use subgraphs with quoted titles (`subgraph id["Title"]`) — not supported by VS Code's bundled Mermaid renderer; omit subgraphs entirely or use bare `subgraph Title`.
- Do **not** use `direction LR` or `direction TB` inside subgraph blocks.
- Do **not** use `A & B --> C` or `A --> B & C` multi-connection shorthand — expand to separate arrow lines.
- Do **not** put `>>`, `=>`, Unicode arrows (`→`), or em-dashes (`—`) in node labels — use plain ASCII words instead.
- Set graph direction only at the top-level (`graph TD` / `graph LR`).
- Safe subset: `graph TD`/`LR`, `ID["Label"]` nodes, `A --> B` edges, plain `subgraph Title ... end`.

## Code Authorship Convention

When writing new comments or code blocks, suffix them with `// [Claude]` (or `# [Claude]` for Python) so AI-generated additions are identifiable.
