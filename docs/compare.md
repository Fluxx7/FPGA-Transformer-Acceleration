# `compare.py` — Model Comparison Script

Evaluates whether reducing the hardware parameters (smaller `EMBED_DIM`, fewer heads, smaller FFN) significantly hurts model quality. Trains both the full-size and reduced-size models across multiple random seeds with early stopping, then reports averaged test metrics and generates comparison plots.

**Run from `Hardware_PC/`:**
```bash
python compare.py
```

This script is slow — it trains `2 × len(SEEDS)` models and then trains two more for the logit plot (see below).

---

## Output Files

| Path | Contents |
|---|---|
| `plots/compare_training_curves.png` | Train + val loss per epoch for every seed, with a thick mean line |
| `plots/compare_metrics.png` | Grouped bar chart of test loss, perplexity, and accuracy with error bars |
| `plots/compare_logits.png` | Per-token logit comparison on the probe sentence |

---

## Configuration

### `class ReducedConfig(Config)`

Subclasses `Config` and overrides only the size-related parameters to match the reduced hardware implementation:

| Attribute | Full (`Config`) | Reduced (`ReducedConfig`) |
|---|---|---|
| `EMBED_DIM` | 64 | 16 |
| `NUM_HEADS` | 8 | 4 |
| `HEAD_DIM` | 8 | 4 |
| `FFN_DIM` | 256 | 32 |

All other hyperparameters (`VOCAB_SIZE`, `SEQ_LEN`, `EPOCHS`, `LEARNING_RATE`, `BATCH_SIZE`) are inherited unchanged.

### Module-level constants

| Constant | Value | Purpose |
|---|---|---|
| `SEEDS` | `[42, 123, 7, 44, 23, 734, 928, 38, 584, 20]` | Random seeds for reproducible multi-run averaging |
| `MAX_EPOCHS` | 200 | Upper bound on training epochs before forced stop |
| `PATIENCE` | 20 | Early stopping: halt if val loss doesn't improve for this many epochs |
| `PROBE_SENTENCE` | `"START the cat"` | Input used to generate the logit comparison plot |

---

## Functions

### `make_split(sentences, train_frac=0.70, val_frac=0.15) → (train, val, test)`

Creates a reproducible train/validation/test split from the sentence list.

Uses `numpy.random.default_rng(0)` (seed fixed at 0) to shuffle the indices once — this ensures the split is always identical regardless of which script calls it or in what order. The remaining 15% after train and val becomes the test set.

With 1,000 sentences: **700 train / 150 val / 150 test**.

---

### `_make_tensors(sentences, seq_len) → (inputs, targets)`

Internal helper that tokenizes and pads a list of sentences and returns two PyTorch tensors:
- `inputs` — token IDs at positions `[0..seq_len-2]`
- `targets` — token IDs at positions `[1..seq_len-1]`

This shift-by-one pairing is the standard next-token prediction setup: the model sees token `i` and is trained to predict token `i+1`.

---

### `train_with_early_stopping(config, train_sents, val_sents) → (model, train_losses, val_losses, best_epoch)`

Trains a `DecoderTransformer` and stops early when validation loss stops improving, returning the weights from the best epoch rather than the final epoch.

**What it does:**
1. Converts train and val sentences to input/target tensor pairs.
2. Trains mini-batches with Adam + gradient clipping (same as `train.py`).
3. After each epoch, evaluates the model on the full validation set (no gradient).
4. If the validation loss is a new minimum, saves a deep copy of the model weights and resets the patience counter.
5. If validation loss fails to improve for `PATIENCE` consecutive epochs, stops training.
6. Restores the best-seen weights before returning.

**Returns:**
- `model` — `DecoderTransformer` with best-epoch weights loaded
- `train_losses` — list of average training loss per epoch (up to early-stop point)
- `val_losses` — list of validation loss per epoch
- `best_epoch` — epoch number (1-indexed) where validation loss was minimized

---

### `run_seeds(config, train_sents, val_sents, test_sents, label) → (agg_metrics, train_curves, val_curves, best_epochs)`

Runs `train_with_early_stopping` once per entry in `SEEDS`, collecting per-seed results, then aggregates them into mean ± std statistics.

**What it does for each seed:**
1. Sets `torch.manual_seed` and `numpy.random.seed` so weight initialization and any stochastic operations are reproducible.
2. Trains with early stopping.
3. Calls `evaluate()` on the held-out test set.
4. Records the loss/perplexity/accuracy metrics, the train/val curves, and the best epoch.

**Aggregation:** for each metric key, computes `{"mean": ..., "std": ...}` across all seeds using `numpy`.

**Returns:**
- `agg_metrics` — `{metric_name: {"mean": float, "std": float}}`
- `train_curves` / `val_curves` — list of per-seed loss lists (different lengths due to early stopping)
- `best_epochs` — list of best epoch per seed

---

### `_plot_curves(ax, curves, color, label)`

Plots a set of per-seed training curves onto a matplotlib `Axes` object.

- Each individual seed curve is drawn as a thin, semi-transparent line (alpha=0.25) to show variability without cluttering the plot.
- Since different seeds stop at different epochs, shorter curves are extended by repeating their final value before stacking into a 2D array.
- The mean across seeds is drawn as a thick solid line.

---

### `main()`

Top-level entry point. Runs the full comparison pipeline:

1. **Split data** — calls `make_split` on `TRAINING_SENTENCES`.
2. **Train full model** — calls `run_seeds(Config(), ...)`.
3. **Train reduced model** — calls `run_seeds(ReducedConfig(), ...)`.
4. **Print results table** — prints mean ± std for loss, perplexity, and accuracy side-by-side for both models, plus per-seed best epoch lists.
5. **Plot 1 — Learning curves** (`compare_training_curves.png`) — two subplots (train loss, val loss) each showing all seeds as thin lines and the mean as a thick line, for both models overlaid.
6. **Plot 2 — Metrics bar chart** (`compare_metrics.png`) — grouped bars for loss, perplexity, and accuracy with error bar caps showing ±std.
7. **Plot 3 — Logit comparison** (`compare_logits.png`) — trains one final model per config (using `SEEDS[-1]`) and calls `probe_logits` on `PROBE_SENTENCE`. Plots the raw logit value for every vocabulary token side-by-side for the full and reduced models. Shows whether the reduced model's output distribution is meaningfully different from the full model's.
