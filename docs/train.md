# `train.py` — Training & Weight Export Pipeline

The main runnable script for this project. Trains a `DecoderTransformer` on the generated sentence dataset, exports all learned weights as `.mem` files for use in the Verilog simulation, and produces verification data to compare software and hardware outputs.

**Run from `Hardware_PC/`:**
```bash
python train.py
```

---

## Output Files

| Path | Contents |
|---|---|
| `models/decoder_model.pth` | Saved PyTorch model weights |
| `memory/*.mem` | 36 weight files in hex format for `$readmemh` |
| `plots/training_loss_curve.png` | Cross-entropy loss vs. epoch |
| `plots/quantization_effect.png` | Float vs. INT16 weight distribution for FFN layer 1 |
| `data/golden_logits.txt` | Software reference logits for `"START the cat"` |
| `plots/sw_hw_logit_comparison.png` | Bar chart comparing software vs. hardware logits (only generated if `data/hardware_logits.txt` exists) |

---

## Directory Constants

```python
MODELS_DIR = "models"
PLOTS_DIR  = "plots"
DATA_DIR   = "data"
```

All output directories are created automatically if they don't exist.

---

## Functions

### `train_model(config, sentences) → (model, losses)`

Trains a fresh `DecoderTransformer` from random initialization using mini-batch gradient descent.

**What it does:**
1. Tokenizes and pads all sentences to `SEQ_LEN` tokens.
2. Constructs input/target tensor pairs: input is tokens `[0..n-2]`, target is tokens `[1..n-1]` (the model is trained to predict the next token at every position simultaneously).
3. Trains for `config.EPOCHS` epochs using the Adam optimizer and cross-entropy loss, ignoring `PAD` (index 0) in the loss calculation.
4. Clips gradients to norm 1.0 each step to prevent exploding gradients.
5. Prints the average loss every 10 epochs.

**Returns:** the trained `DecoderTransformer` and a list of per-epoch average losses.

---

### `export_model_weights(model)`

Quantizes every learnable weight matrix to INT16 and writes it to a `.mem` file that the Verilog `$readmemh` system task can load.

**Files written (36 total):**

| File | Weight | Shape |
|---|---|---|
| `embedding.mem` | Token embedding table | `VOCAB_SIZE × EMBED_DIM` |
| `positional_encoding.mem` | Positional embedding table | `SEQ_LEN × EMBED_DIM` |
| `attention_wq_head{0..7}.mem` | Per-head Q projection | `HEAD_DIM × EMBED_DIM` |
| `attention_wk_head{0..7}.mem` | Per-head K projection | `HEAD_DIM × EMBED_DIM` |
| `attention_wv_head{0..7}.mem` | Per-head V projection | `HEAD_DIM × EMBED_DIM` |
| `attention_wo.mem` | Output projection W_O | `EMBED_DIM × EMBED_DIM` |
| `layernorm1_gamma.mem` | Layer norm 1 scale | `EMBED_DIM` |
| `layernorm1_beta.mem` | Layer norm 1 bias | `EMBED_DIM` |
| `ffn_w1.mem` | FFN layer 1 weight | `FFN_DIM × EMBED_DIM` |
| `ffn_b1.mem` | FFN layer 1 bias | `FFN_DIM` |
| `ffn_w2.mem` | FFN layer 2 weight | `EMBED_DIM × FFN_DIM` |
| `ffn_b2.mem` | FFN layer 2 bias | `EMBED_DIM` |
| `layernorm2_gamma.mem` | Layer norm 2 scale | `EMBED_DIM` |
| `layernorm2_beta.mem` | Layer norm 2 bias | `EMBED_DIM` |
| `output_proj.mem` | Vocabulary output projection | `VOCAB_SIZE × EMBED_DIM` |

Also saves `plots/quantization_effect.png` — side-by-side histograms of the raw float32 vs. quantized INT16 weight values for FFN layer 1. Useful for visually inspecting how much precision is lost in quantization.

---

### `generate_verification_data(model)`

Generates the golden reference logits that allow the Verilog simulation output to be compared against the software model.

**What it does:**
1. Runs `probe_logits(model, "START the cat")` — the test sentence used for hardware verification.
2. Saves the raw float logit vector to `data/golden_logits.txt` (one value per line).
3. If `data/hardware_logits.txt` already exists (written by the Verilog simulation via `sim_main.cpp`), generates `plots/sw_hw_logit_comparison.png`:
   - Re-quantizes the software logits to INT16 using the same scale factor as `quantize_weight`.
   - Plots a grouped bar chart with one bar per vocabulary token, software in blue and hardware in red.
   - X-axis labels are the actual token strings from `VOCAB_REVERSE`.

If the hardware logits file is not present, it prints a reminder to run the simulation first.

---

### `main()`

Top-level entry point. Orchestrates the three stages in order:

1. **Load or train** — if `models/decoder_model.pth` exists, loads the saved weights instead of retraining. Otherwise trains from scratch, saves the model, and plots the training loss curve.
2. **Export weights** — calls `export_model_weights` to write all `.mem` files.
3. **Generate verification data** — calls `generate_verification_data` to produce golden logits and (if hardware results exist) the comparison plot.
