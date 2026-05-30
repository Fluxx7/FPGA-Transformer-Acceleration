# FPGA Transformer Acceleration — Nicholas Armstrong MQP

WPI Major Qualifying Project. Demonstrates hardware acceleration of a transformer decoder on a PYNQ-Z1 FPGA (Zynq XC7Z020). A small decoder-only transformer (vocabulary size 40, embedding dim 16, 4 attention heads) is fully implemented in SystemVerilog and validated against a PyTorch reference model.

## Repository Layout

```
v0/rtl/          SystemVerilog RTL modules
v0/sim/cpp/      Verilator C++ test benches
Vivado/          AXI-Lite wrapper and block design
tests/           Python test drivers
memory/          Trained weight .mem files (from gen_luts.py)
models/          PyTorch model checkpoints
report/          Paper sections (Markdown) and build script
context/         Reference documents and figures
model.py         PyTorch model definition
train.py         Training script
interface.py     Unified inference interface (PyTorch / Verilator / hardware)
compare.py       Backend comparison
gen_luts.py      Export trained weights to .mem files
```

## Prerequisites

### Python dependencies

Create and activate a virtual environment, then install dependencies:

```bash
python3 -m venv .venv
source .venv/bin/activate   # re-run this each time you open a new terminal
pip install torch numpy scipy
```

### Hardware simulation (Verilator)

```bash
brew install verilator   # macOS
# or: apt install verilator  (Linux)
```

Then build the simulators. `make verilate` builds the full-pipeline binary; `make tests` builds the per-module binaries required by the Python test drivers:

```bash
cd v0 && make tests
```

### Report build dependencies

```bash
brew install pandoc
brew install node          # includes npm
npm install -g @mermaid-js/mermaid-cli
```

## Building the Report

Run from the **project root**:

```bash
python3 report/build.py
```

This concatenates all `report/[0-9]*.md` sections in order, renders any
Mermaid diagrams to PNG, and produces `report/output/Nicholas_Armstrong_MQP.docx`.

```
Options:
  -o FILE            Output path (default: report/output/Nicholas_Armstrong_MQP.docx)
  --no-mermaid       Skip Mermaid rendering (if mmdc is not installed)
  --no-reference-doc Ignore context/Armstrong (MQP report).docx style template
  -h, --help         Show full help
```

The build uses `context/Armstrong (MQP report).docx` as a Word style template
if present. Place the WPI-formatted reference document there to apply WPI
heading and body styles automatically.

### Figure TODOs

Several figures in the report are placeholders that require exports from
Vivado or a board run. The build script warns about missing figure files.
Look for `<!-- TODO (Nicholas): -->` comments in the section files.

Required figures (save to `context/figures/`):
- `utilization_initial.png` — Vivado utilization at default parameters
- `utilization_final.png` — Vivado utilization at final parameters (EMBED=16, FFN=32, HEADS=4)
- Logit comparison graphs (run `plot.py` after a `compare.py` run)

## Running Tests

Each RTL module has a paired Python test driver:

```bash
python tests/test_layer_normalization.py
python tests/test_attention_head.py
# etc.
```

## Training the Model

```bash
python train.py
python gen_luts.py    # exports weights to memory/
```

## Running Inference

```bash
python interface.py --backend verilator --prompt "the"
python interface.py --backend pytorch   --prompt "the"
```
