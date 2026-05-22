# `model.py` — Shared Model Library

Defines the transformer architecture, vocabulary, dataset, and all utilities shared between `train.py` and `compare.py`. Nothing in this file trains or runs a model — it is a library of building blocks.

---

## Configuration

### `class Config`

Holds all hyperparameters as class-level constants. Both `train.py` and `compare.py` instantiate or subclass this to configure the model.

| Attribute | Value | Meaning |
|---|---|---|
| `VOCAB_SIZE` | 40 | Number of distinct tokens |
| `EMBED_DIM` | 64 | Token/position embedding width |
| `SEQ_LEN` | 8 | Fixed input sequence length (tokens) |
| `NUM_HEADS` | 8 | Number of attention heads |
| `HEAD_DIM` | `EMBED_DIM // NUM_HEADS` = 8 | Per-head key/query/value dimension |
| `FFN_DIM` | 256 | Hidden width of the feed-forward network |
| `DATA_WIDTH` | 16 | Bit-width for INT16 quantization |
| `MAX_VAL` / `MIN_VAL` | ±32767/−32768 | INT16 clamp bounds |
| `EPOCHS` | 100 | Training epochs for `train.py` |
| `LEARNING_RATE` | 0.001 | Adam optimizer step size |
| `BATCH_SIZE` | 4 | Mini-batch size during training |

---

## Vocabulary

### `VOCABULARY`

A `dict[str, int]` mapping every word token to its integer index (0–39). Organized into:

- **Special** (0–2): `PAD`, `START`, `END`
- **Articles** (3–4): `the`, `a`
- **Animals** (5–7, 25–27): `cat`, `dog`, `bird`, `fish`, `fox`, `bear`
- **Verbs** (8–12, 28–31): `runs`, `jumps`, `flies`, `sleeps`, `eats`, `walks`, `swims`, `sits`, `plays`
- **Prepositions** (13–17, 37–38): `on`, `in`, `under`, `near`, `with`, `above`, `behind`
- **Adjectives** (18–22, 34–36): `big`, `small`, `red`, `blue`, `happy`, `tall`, `dark`, `young`
- **Adverbs** (23–24, 32–33): `quickly`, `slowly`, `gently`, `loudly`
- **Conjunction** (39): `and`

### `VOCAB_REVERSE`

The inverse mapping `dict[int, str]` — used for labeling plots and decoding predictions.

### Word-category lists

`_ARTICLES`, `_ANIMALS`, `_VERBS`, `_ADVERBS`, `_ADJECTIVES`, `_PREPOSITIONS` — Python lists of token strings grouped by grammatical role. Used exclusively by `generate_sentences()` to enumerate all combinations.

---

## Dataset Generation

### `generate_sentences(seed=0) → List[str]`

Programmatically builds all grammatically valid sentences from the vocabulary word lists, then shuffles them with a seeded RNG so the ordering is reproducible but unpredictable.

Two sentence patterns are used, both fitting within `SEQ_LEN=8` after padding:

| Pattern | Template | Token count | Combinations |
|---|---|---|---|
| Without adjective | `START art animal verb adv prep END` | 7 | 2×6×9×4×7 = **3,024** |
| With adjective | `START art adj animal verb adv prep END` | 8 | 2×8×6×9×4×7 = **24,192** |

Total: **27,216 sentences**, shuffled with `numpy.random.default_rng(seed)`.

### `TRAINING_SENTENCES`

A module-level list holding the first 1,000 sentences from `generate_sentences()`. Imported directly by `train.py` and `compare.py` so both scripts always see the same dataset.

---

## Data Helpers

### `tokenize_sentence(sentence) → List[int]`

Splits a sentence string on whitespace and maps each word to its integer index via `VOCABULARY`. Words not in the vocabulary are silently dropped.

### `pad_sequence(tokens, max_len) → List[int]`

Right-pads `tokens` with zeros (`PAD`) to exactly `max_len` entries, or truncates if longer. Used to produce fixed-length input tensors.

---

## Model Architecture

### `class MultiHeadAttention(nn.Module)`

Implements multi-head causal self-attention. Each head has its own independent linear projections for Q, K, and V — there is no single fused QKV matrix.

**`__init__(embed_dim, num_heads)`**

Creates `num_heads` separate `nn.Linear` layers for Q, K, and V (no bias), plus a single output projection `W_O : embed_dim → embed_dim`.

**`forward(x) → Tensor`** — input shape `[batch, seq, embed_dim]`

For each head:
1. Projects `x` to Q, K, V of shape `[batch, seq, head_dim]`.
2. Computes scaled dot-product scores: `QKᵀ / √head_dim`.
3. Applies a **causal (lower-triangular) mask** — future positions are set to `-inf` before softmax so the model cannot attend to tokens it hasn't seen yet. `nan_to_num` cleans up any NaNs produced by rows that are entirely masked.
4. Computes weighted sum of V.

All head outputs are concatenated along the last dimension (recovering `embed_dim`), then passed through `output_projection`.

---

### `class DecoderTransformer(nn.Module)`

A single-layer transformer decoder. Mirrors the RTL architecture in `v0/rtl/`.

**`__init__(config)`**

Constructs:
- `token_embedding` — learned `[VOCAB_SIZE × EMBED_DIM]` lookup table
- `positional_embedding` — learned `[SEQ_LEN × EMBED_DIM]` lookup table (added to token embeddings)
- `attention` — a `MultiHeadAttention` instance
- `layer_norm1`, `layer_norm2` — PyTorch `LayerNorm` over `EMBED_DIM`
- `ffn` — two-layer MLP: `EMBED_DIM → FFN_DIM [ReLU] → EMBED_DIM`
- `output_projection` — linear `EMBED_DIM → VOCAB_SIZE` (no bias); maps the final hidden state to vocabulary logits

**`forward(x) → Tensor`** — input shape `[batch, seq_len]` (integer token IDs)

Runs the full pipeline:
1. **Embedding** — token + positional embeddings are summed.
2. **Attention** — multi-head causal self-attention.
3. **Add & Norm 1** — residual connection from the embedding, then `LayerNorm`.
4. **FFN** — two-layer MLP with ReLU.
5. **Add & Norm 2** — residual connection from `norm1_out`, then `LayerNorm`.
6. **Output projection** — linear map to `[batch, seq_len, VOCAB_SIZE]` logits.

Output logits at position `i` predict the token at position `i+1`.

---

## Weight Export Helpers

### `quantize_weight(weight, data_width) → np.ndarray[int16]`

Converts a floating-point weight tensor to a fixed-point `int16` array for use in the Verilog simulation.

Steps:
1. Finds the absolute maximum of the weight.
2. Computes a linear scale factor so the maximum maps to 80% of `INT16_MAX` (leaves headroom to avoid clipping during accumulation).
3. Rounds and clamps to `[MIN_VAL, MAX_VAL]`.

### `save_memory_file(data, filename, data_width)`

Writes a quantized weight array to a `.mem` file in the hexadecimal format expected by Verilog's `$readmemh`. Each value is written as a 4-hex-digit unsigned integer on its own line (two's complement representation for negative values).

---

## Evaluation Helpers

### `evaluate(model, sentences) → dict`

Runs the model in inference mode on a list of sentence strings and returns:

| Key | Description |
|---|---|
| `"loss"` | Per-token cross-entropy loss (ignoring `PAD` tokens) |
| `"perplexity"` | `exp(loss)` — geometric mean probability per token |
| `"accuracy"` | Fraction of non-padding token positions predicted correctly |

Used by `compare.py` to score models on the held-out test set.

### `probe_logits(model, sentence) → np.ndarray`

Returns the raw logit vector (length `VOCAB_SIZE`) at the **last non-padding token position** of a given sentence. Used to compare what token the model predicts next — the argmax of this vector is the predicted next token.

In `train.py`, this is called on `"START the cat"` to produce the golden reference logits that are compared against the Verilog simulation output.
