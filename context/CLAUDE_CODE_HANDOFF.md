# Claude Code Handoff: Nicholas Armstrong MQP Report Sprint
*Generated May 30, 2026 — supersedes all prior handoff documents*

---

## What This Is

Nicholas Armstrong is a WPI graduate student completing his MQP (Major Qualifying Project — equivalent to a senior thesis). The project is a hardware accelerator for transformer inference on a PYNQ-Z1 FPGA board, implemented in SystemVerilog. This weekend, Andy (his father) is cloning the repo and working with Claude Code to scaffold and draft the written report.

**The stakes:** WPI requires completing at least two of three project requirements to graduate. The MQP is one of them. First draft is due to the faculty advisor this weekend; final draft target is Tuesday.

**Repo:** https://github.com/Fluxx7/FPGA-Transformer-Acceleration

**Code authorship note from CLAUDE.md:** All Claude-generated code or comments should be suffixed with `// [Claude]` (or `# [Claude]` for Python). Apply this to any report-related scripts you write too.

---

## Repo Structure (as observed)

```
/
├── CLAUDE.md              # AI authorship convention
├── GAME_PLAN.md           # Future architecture roadmap (5 steps — very detailed)
├── compare.py             # Logit comparison between hardware and software
├── gen_luts.py            # Generates lookup tables (exp, rsqrt, etc.)
├── interface.py           # Python interface to the hardware/board
├── model.py               # PyTorch transformer decoder model
├── plot.py                # Plotting/graphing utilities
├── train.py               # Training script with template-based data generation
├── schematic.svg          # Architecture schematic
├── v0/                    # Original repository code (the starting point)
├── Vivado/                # Vivado project files, constraints, bitstream artifacts
├── memory/                # .mem weight files (exported from trained model)
├── models/                # Saved PyTorch model checkpoints
├── tests/                 # Per-module Verilator test benches (C++ + Python)
└── docs/                  # (Exists — check contents when cloned)
```

Language breakdown: Python 39%, SystemVerilog 33%, C++ 11%, Verilog 8%, Tcl 4%, Makefile 3%.

**When cloned, your first task:** inventory the actual SystemVerilog module files (likely under `Vivado/` or a `src/` directory — navigate to find them) and list all modules. Nicholas said there are 10 modules plus an untested memory module (11 total). The tests directory should have one test file per module.

---

## Technical Background

### The Project in One Sentence
A parameterized transformer decoder implemented in SystemVerilog, synthesized to a PYNQ-Z1 FPGA, validated against a PyTorch software model, as a proof of concept for local transformer inference on embedded systems.

### Why This Matters (Motivation Section Material)
Transformers are too computationally expensive to run in real-time on embedded systems (medical devices, IoT sensors, edge devices). Current options are: attach a GPU (impractical), send data to the cloud (latency, connectivity, privacy issues — especially for medical data), or build dedicated acceleration hardware. This project explores the third option using an FPGA, which is actually used in production embedded systems because FPGAs are mass-produced and cost-effective at low volume. The PYNQ-Z1 is essentially an embedded Linux device with an FPGA — nearly a perfect simulation of the target use case.

### Architecture Overview
The hardware implements a single-layer transformer decoder with these modules (sequential state machine — only one runs at a time, except attention heads which run in parallel):

1. **Token Embedding** — lookup table mapping token IDs to embedding vectors
2. **Positional Encoding** — adds cosine-based positional signal to embeddings
3. **Multi-Head Attention** — contains N parallel `attention_head` instances; each computes Q, K, V projections, attention scores, softmax, and weighted sum
4. **Layer Normalization** (×2) — normalizes intermediate representations; uses a reciprocal square root lookup table (replaced from an earlier combinational approximation)
5. **Feed Forward Network** — two linear layers with ReLU
6. **Output Projection** — projects final hidden state to vocabulary logits
7. **Arg Max** — selects highest-logit token (deterministic, simplest module)
8. **Memory module** — generic BRAM interface (untested, known to work)
9. **AXI Wrapper** — top-level interface to PYNQ's memory-mapped Python interface

**Fixed-point arithmetic:** Q8.8 (16-bit, 8 integer bits + 8 fractional bits) throughout. Lookup tables for softmax exponential and reciprocal square root.

### Current Parameters (on-board, cut down to fit)
- Attention heads: 4 (down from 8)
- Embedding dimension: reduced from 64
- FFN dimension: reduced from 256
- Vocabulary: 40 tokens (simple English words: articles, animals, verbs, adverbs, adjectives)
- Context window: 8 tokens

### Original Parameters (too large at 219% LUT utilization)
- 8 attention heads, 64 embedding dim, 256 FFN dim

---

## What Nicholas Accomplished (Technical Chronology for the Report)

### Phase 1: Getting It to Build
- Took the `v0` repository as a starting point
- Added constraint file for the PYNQ-Z1 board
- Added AXI wrapper for Python/board interface
- Fixed several code errors present in the original repo
- Discovered initial LUT utilization: ~219% (well over 100% capacity)

### Phase 2: Parameter Reduction to Fit the Board
- Ran experiments reducing embedding dimension, FFN dimension, number of attention heads
- Eventually achieved a bitstream write (the file that programs the FPGA) by cutting parameters significantly, including halving the attention heads from 8 to 4
- Required an SD card with PYNQ image to actually boot the Python interface on the board

### Phase 3: Model Improvements (Python/CS Side)
- Original training data: 24 hardcoded sentences — severe overfitting
- Built a template-based training data generator: `start [article] [animal] [verb] [adverb] end`, `start [article] [adjective] [animal] [verb] [adverb] end`, etc.
- Added support for sentences longer than the context window (trained separately; model struggles but it's documented)
- Added `and` conjunction token that was in vocabulary but never used in training data
- Trained on 5,000 sentences; software model now generates valid grammatical outputs: "the cat sleeps gently", "the bird swims gently"
- Built a unified Python interface (`interface.py`) supporting PyTorch backend, and designed to support hardware backend with the same API

### Phase 4: Per-Module Validation (the overnight session, ~6am bug freeze)
Nicholas built a per-module test harness: each module is verilated, driven with test inputs, and its output compared to an equivalent PyTorch operation. Metrics: mean error, max error, and Pearson correlation coefficient.

**Results by module:**

| Module | Status | Notes |
|--------|--------|-------|
| Feed Forward Network | ✅ 1.0 correlation | Fixed non-blocking assignment errors |
| Layer Normalization | ✅ ~1.0 correlation | Replaced combinational sqrt with rsqrt lookup table |
| Attention Head (Q, K, V) | ✅ 1.0 correlation | Fixed non-blocking assignments + parameter propagation bug (head_dim was always 8; now computed as embed_dim/num_heads and explicitly passed) |
| Attention Scores | ✅ ~1.0 correlation | Fixed scaling for non-power-of-2 head dims; fixed softmax clamp bug |
| Softmax | ✅ ~0.99+ correlation | Clamp bug: lower bound should be -2016 not -2048 (hard-coded fix applied) |
| Multi-Head Attention | ⚠️ Strong correlation, error ~0.1–0.4 | One remaining non-blocking assignment issue suspected; not 1.0 |
| Arg Max | ✅ 20/20 test cases | Deterministic; trivially correct |
| Full System | Run and verify | End-to-end test via Verilator + compare.py |

**The softmax clamp story** (worth a full paragraph in the report): Softmax had passed standalone testing with near-perfect correlation. But when testing attention head end-to-end, correlation collapsed. Investigation revealed the softmax exponential lookup table was clamping its input range to [-2048, 0], but the correct lower bound given the Q8.8 quantization and lookup table indexing was -2016 (63×32, not 64×32). The 32-entry gap only affects extreme values, which standalone random test data rarely hit — but attention score distributions hit those values regularly. The fix (hard-coding -2016) was straightforward once diagnosed. This is a good case study in how integration testing catches bugs that unit testing misses.

---

## The Report Structure (Agreed Between Nicholas and Andy)

Create one `.md` file per section in a `/report/` directory in the repo. Work on them independently. VS Code's Markdown Preview (with image support) is the review environment. Final assembly step converts to the submission document.

### Section Files to Create

**`report/01_introduction.md`** — Motivation  
- Problem statement: transformers impractical on embedded systems
- Applications: medical devices (data privacy), IoT, edge inference
- Options considered; why dedicated FPGA acceleration
- The PYNQ-Z1 as an embedded Linux + FPGA system, nearly ideal for this proof of concept
- *Note: professor wants this expanded with specific applications and their requirements. Treat as lower priority — get it started but don't block on it.*

**`report/02_background.md`** — Background  
- Transformer architecture: attention mechanism, positional encoding, feed-forward, layer normalization
- Fixed-point arithmetic: Q8.8 format, why used here, tradeoffs vs. float32
- FPGAs in embedded systems: LUTs, BRAM, synthesis vs. simulation
- PYNQ-Z1 board: Zynq architecture, AXI interface, Python overlay model
- Glossary of terms (Verilog, SystemVerilog, Verilator, LUT, BRAM, AXI, Vivado, bitstream)
- *Claude Code can draft most of this independently from general knowledge*

**`report/03_repository_selection.md`** — Selecting the Starting Repository  
- What Nicholas was looking for: a working transformer decoder in SystemVerilog
- What `v0` provided and what it was missing
- Notable characteristics of the original code: all-registers approach, sequential FSM, parallel attention heads
- What immediately needed to change (constraints, AXI wrapper, code fixes)

**`report/04_model_work.md`** — Software Model Development (CS focus)  
- Starting state of the Python model: 24-sentence training set, overfitting, limited capability
- Template-based training data generation system (describe the slot format, templates used)
- Token vocabulary: 40 tokens, why `and` was added
- Training runs: sentence counts, training time observations
- Example outputs from software model
- The unified interface design (PyTorch backend / hardware backend)
- Brief discussion of logit generation and why argmax vs. weighted sampling

**`report/05a_getting_to_board.md`** — Hardware Development Part 1: Getting to the Board  
- Initial LUT utilization: 219%
- What LUT utilization means and why 100% is the hard ceiling
- The parameter reduction experiments (table: what was changed, resulting utilization)
- The AXI wrapper addition
- The constraint file
- Achieving the bitstream write
- The SD card / PYNQ image requirement
- Brief note on the board interface: Python → AXI → hardware

**`report/05b_hardware_validation.md`** — Hardware Development Part 2: Validation  
- The per-module test harness: how it works (Verilator + Python, metrics reported)
- Why per-module testing: if attention head fails, you need to know which sub-stage
- The intermediate value exposure approach (adding output ports for internal signals)
- Walk through each module fix chronologically:
  - FFN: non-blocking assignment errors
  - Layer norm: combinational sqrt → rsqrt lookup table (timing motivation)
  - Attention head Q/K/V: non-blocking + head_dim parameter bug
  - Softmax clamp story (see above — deserves its own paragraph)
  - Multi-head attention: remaining error
- Bug fix freeze: 6am May 30, 2026
- *This is the longest and most important section*

**`report/06_results.md`** — Results  
- Correlation table (all modules, final numbers)
- LUT utilization: original parameters vs. final parameters on board
- Representative hardware outputs: input token sequences → output tokens
- Logit comparison graphs (hardware vs. software) — *may need to be generated; see below*
- Tokens per second (Nicholas specifically wants this metric)
- Timing analysis: clock cycles per module pass, total inference latency
- Clock speed / timing slack (has the rsqrt fix improved it? — needs a new Vivado run to confirm)

**`report/07_future_work.md`** — Future Work  
Draw directly from `GAME_PLAN.md` in the repo — it's well-written and already structured into 5 steps. The report version should be prose not bullets, and should explain the *motivation* for each step, not just what it does. The five steps are:
1. Sequentialize attention heads (biggest single resource win)
2. Single-position processing with KV cache
3. Generic parameterizable matmul unit
4. Move intermediate storage to BRAM scratchpad
5. AXI-Lite control interface for full PYNQ overlay

Also mention: decoupling token embedding and arg max from the hardware (vocabulary independence), BRAM weight flashing (runtime model update without resynthesis).

**`report/08_conclusion.md`** — Conclusion  
- What was achieved: working, validated transformer decoder hardware accelerator
- Proof of concept status: demonstrates feasibility; current parameters are reduced but functionally correct
- What distinguishes this from the hypothetical final product (and where future work begins)
- Brief forward pointer to the future work

---

## Priority Order for Drafting

1. **05b** (Hardware Validation) — longest, most important, most reviewer attention
2. **05a** (Getting to the Board) — second most important
3. **04** (Model Work) — important for CS component of the dual-major MQP
4. **06** (Results) — needs actual data; flag what's missing
5. **07** (Future Work) — GAME_PLAN.md is the raw material; convert to prose
6. **03** (Repository Selection) — short, narrative
7. **02** (Background + Glossary) — Claude Code can draft independently
8. **08** (Conclusion) — write last
9. **01** (Motivation/Introduction) — lowest priority for first draft; professor already has it and wants expansion, but that's for final draft

---

## Data and Artifacts Still Needed

Flag these in the relevant section files with a `<!-- TODO: -->` comment so Nicholas knows what to fill in:

- **Vivado utilization numbers** for each parameter experiment (screenshots are on the PC running Vivado; Nicholas needs to pull the actual percentages)
- **Logit comparison graphs**: `compare.py` and `plot.py` exist for this; may need to be run with the current model
- **Tokens per second**: needs to be measured (clock frequency × cycles per inference)
- **Timing slack post-rsqrt fix**: needs a Vivado implementation run after the layer norm change
- **Multi-head attention final error**: the ~0.1–0.4 error — is there a fix, or is this the final number?
- **Specific LUT numbers**: exact before/after for each experiment, not just "reduced"

---

## Workflow Notes

- **One `.md` file per section.** Don't write a monolithic document — context window management matters and parallel editing is the goal.
- **Use `<!-- TODO: [data needed] -->` comments** wherever real data, screenshots, or measurements need to be inserted by Nicholas.
- **Tone:** Academic but readable. First person is fine ("I modified...", "The results show..."). Negative results and dead ends are valid engineering content — don't skip them.
- **Don't invent technical claims.** If the transcripts or code don't support a specific number or assertion, leave a TODO rather than guessing.
- **Claude AI usage disclosure:** Nicholas plans to note somewhere that Claude was used for assistance, debugging, and generating scripts. Don't hide it, but don't make it the focus.
- **The GAME_PLAN.md is gold for Section 7.** It's already written in a clear, technical style. Convert to flowing prose, add motivation sentences, and it's largely done.
- **The schematic.svg is in the repo root.** It should be embedded in Section 02 or 05a — reference it as `../schematic.svg` from the report directory.

---

## Submission Plan

1. **Tonight/tomorrow:** Create all section skeleton files, draft 05a, 05b, 04 in full
2. **Tomorrow:** Nicholas reviews, fills TODOs with actual data, generates graphs
3. **Sunday evening:** Complete first draft → copy into Google Doc (new tab labeled "First Draft") → professor already has access
4. **Monday:** Address professor feedback while continuing to flesh out Motivation section
5. **Tuesday:** Final draft submitted

---

## Quick Reference: Key People

- **Nicholas Armstrong** — the student; GitHub username Fluxx7
- **Andy Armstrong** — Nicholas's father; helping with report scaffolding and structure
- **Faculty advisor** — reviews the shared Google Doc; has been checking daily and giving positive feedback on the writing so far

---

*This handoff was generated from: two prior handoff documents, four Otter AI transcripts (FaceTime April 5, April 11, April 15, and two sessions May 30), and direct inspection of the GitHub repo including CLAUDE.md and GAME_PLAN.md.*
