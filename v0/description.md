# v0 Module Descriptions

## memory_module

Generic single-port synchronous read memory. Parameterized by address width, data width, depth, and an optional `.mem` file path. On reset/initialization, if a `MEM_FILE` is provided, it loads hex values from that file via `$readmemh`; otherwise it zero-initializes. On each clock edge, if `enable` is high and the address is in range, it outputs the value at `addr` with one cycle of read latency (registered output). This is the pattern Vivado recognizes for BRAM inference, so weight storage goes into block RAM rather than LUTs.

Used by every other module to store weights, biases, embeddings, positional encodings, and layernorm parameters.

## token_embedding

Lookup table that converts a sequence of 5-bit token IDs into 16-bit fixed-point embedding vectors. It instantiates one `memory_module` loaded with `embedding.mem`, which holds a flattened `[VOCAB_SIZE x EMBED_DIM]` embedding table.

Processing is sequential: it iterates over each sequence position, and within each position iterates over each embedding dimension. For each `(seq_idx, dim_idx)` pair, it computes the address `token_id * EMBED_DIM + dim_idx`, waits 2 pipeline stages for the BRAM read latency, then stores the result into `embedded_output[seq_idx][dim_idx]`. Total cycles: roughly `SEQ_LEN * EMBED_DIM * 3`.

## positional_encoding

Adds pre-computed positional encoding values to the embedded token vectors. Instantiates one `memory_module` loaded with `positional_encoding.mem`, which holds a flattened `[SEQ_LEN x EMBED_DIM]` table of fixed-point sinusoidal (or learned) position values.

Iterates over `(seq_idx, dim_idx)`, reads the positional value from memory (2-cycle pipeline wait), then adds it to the corresponding element of `embedded_input`. The sum is saturated to the signed 16-bit range `[-32768, 32767]` to prevent overflow. Output is `position_encoded_output`.

Note: there is a latency bug here -- `temp_sum` is computed and clamped in the same cycle, but since `temp_sum` is a register, the clamping actually uses the *previous* iteration's `temp_sum` value, not the current one. The result is shifted by one element. This same off-by-one pattern appears in the FFN and layer norm modules as well.

## attention_head

A single scaled dot-product attention head. Instantiates three `memory_module`s for the Q, K, and V weight matrices (each `[EMBED_DIM x HEAD_DIM]`, loaded from per-head `.mem` files), and one `enhanced_softmax` instance.

Proceeds through 7 states:

1. **COMPUTE_Q**: For each sequence position, computes `Q[seq][head_d] = sum_over_embed(input[seq][e] * Wq[e][head_d]) >> 8`. This is a matrix multiply of `[SEQ_LEN x EMBED_DIM] @ [EMBED_DIM x HEAD_DIM]` done one output element at a time, with a 32-bit accumulator and a right-shift by 8 to rescale from Q8.8 fixed-point multiplication.
2. **COMPUTE_K**: Same operation with Wk weights to produce the K matrix.
3. **COMPUTE_V**: Same operation with Wv weights to produce the V matrix.
4. **ATTENTION_SCORES**: Computes `scores[i][j] = dot(Q[i], K[j])` for all position pairs. The dot product is accumulated across `HEAD_DIM` elements in a single cycle each (no pipeline wait since Q and K are registers, not BRAM). The raw score is then scaled by approximately `1/sqrt(HEAD_DIM)` via `(acc >>> 2) + (acc >>> 4)` (which is ~0.3125x, approximating `1/sqrt(8) = 0.354`). Causal masking is applied: if `j > i`, the score is set to `-16384` (a large negative value that softmax will drive near zero).
5. **SOFTMAX**: Triggers the `enhanced_softmax` module on the full `[SEQ_LEN x SEQ_LEN]` score matrix and waits for completion.
6. **APPLY_ATTENTION**: Computes the weighted sum `output[seq][d] = sum_over_j(weights[seq][j] * V[j][d]) >> 12`. This multiplies the softmax attention weights by V, producing a `[SEQ_LEN x HEAD_DIM]` output. The right-shift by 12 accounts for the Q12.4 fixed-point format of the softmax weights.
7. **COMPLETE**: Signals done.

## enhanced_softmax

Applies softmax row-by-row to a `[SEQ_LEN x SEQ_LEN]` matrix of attention scores. Uses a piecewise linear approximation to the exponential function rather than actual `exp()`, since that would require extensive hardware.

The `enhanced_exp` function first right-shifts the input by 4 (dividing by 16 to bring values into a manageable range), then applies:
- If shifted value < -16: output 1 (near-zero)
- If shifted value > 16: output 512 (capped maximum)
- If shifted value < 0: output `64 + shifted * 3` (shallow negative slope)
- If shifted value >= 0: output `64 + shifted * 8` (steeper positive slope)
- Minimum clamped to 1 to avoid division by zero

For each row, it:
1. **FIND_MAX**: Scans the entire matrix (not just the row) to find the global maximum score. This is unusual -- standard softmax finds the per-row max for numerical stability. Using the global max still works but is less numerically precise for rows whose values are far from the global max.
2. **COMPUTE_EXP**: For each element in the row, computes `enhanced_exp(score - max_val)` and accumulates the sum.
3. **NORMALIZE**: Divides each `temp_exp` value by `exp_sum`, scaling into Q4.12 format: `(temp_exp << 12) / exp_sum`. The output is clamped to 16 bits.

Then loops back to COMPUTE_EXP for the next row until all rows are processed.

## multi_head_attention

Orchestrates all `NUM_HEADS` (8) attention heads in parallel and combines their outputs. Instantiates 8 `attention_head` modules with per-head weight files, plus one `memory_module` for the output projection matrix `Wo` (`[EMBED_DIM x EMBED_DIM]`, loaded from `attention_wo.mem`).

Proceeds through 4 states:

1. **PROCESS_HEADS**: Asserts all 8 `head_start_signals` simultaneously, then waits until all heads report `done && valid`. This is the only parallel computation in the entire design -- all 8 heads run concurrently.
2. **CONCAT_OUTPUT**: Concatenates the 8 head outputs (each `[SEQ_LEN x HEAD_DIM]`) side-by-side into a single `[SEQ_LEN x EMBED_DIM]` matrix. For each `dim_idx`, it computes `head_id = dim_idx / HEAD_DIM` and `local_dim = dim_idx % HEAD_DIM` to index into the correct head's output. If `dim_idx >= HEAD_DIM * NUM_HEADS` (shouldn't happen when `EMBED_DIM == NUM_HEADS * HEAD_DIM`), it zero-fills.
3. **OUTPUT_PROJ**: Multiplies the concatenated matrix by `Wo` to produce the final attention output. This is a `[SEQ_LEN x EMBED_DIM] @ [EMBED_DIM x EMBED_DIM]` matrix multiply, done one element at a time: accumulate `concatenated[seq][in_dim] * Wo[in_dim][out_dim]`, right-shift by 8, store to `output_data[seq][out_dim]`.
4. **COMPLETE**: Signals done.

## layer_normalization

Applies layer normalization with a residual connection. Takes two inputs: `input_data` (the module output to normalize) and `residual_data` (the skip connection to add first). Instantiates two `memory_module`s for the learned `gamma` (scale) and `beta` (shift) parameters, each of size `[EMBED_DIM]`.

Proceeds through 5 states:

1. **ADD_RESIDUAL**: Computes `sum_data[seq][dim] = input_data[seq][dim] + residual_data[seq][dim]` with saturation clamping. (Has the same off-by-one register bug as positional_encoding.)
2. **COMPUTE_MEAN**: For a single sequence position, accumulates `sum_data[seq][dim]` across all dims, then divides by `EMBED_DIM` via `>>> 6` (assumes `EMBED_DIM = 64`). Stores per-position `mean_val[seq]`.
3. **COMPUTE_VAR**: Computes variance for that position: accumulates `(sum_data[seq][dim] - mean) ^ 2 >> 8` across all dims, then divides by `EMBED_DIM` via `>>> 6`. Computes standard deviation as `sqrt(variance + 256)` using Newton's method (3 iterations). The `+ 256` is an epsilon term for numerical stability (equivalent to `+ 1.0` in the Q8.8 fixed-point format). Note: this has multi-cycle pipeline issues -- `diff`, `diff_sq`, and `var_acc` are all registers updated in the same cycle, so each depends on the *previous* iteration's values, introducing a 2-element pipeline lag.
4. **NORMALIZE**: For each element, computes `normalized = ((value - mean) << 8) / std`, then `output = (normalized * gamma) >> 8 + beta`, with saturation clamping. Reads gamma and beta from BRAM (2-cycle pipeline wait). After finishing one position, loops back to COMPUTE_MEAN for the next position. Same pipeline lag issue here -- `normalized`, `with_gamma`, and `final_result` each use the previous cycle's value.
5. **COMPLETE**: Signals done.

## feed_forward_network

A two-layer MLP with ReLU activation (the position-wise feed-forward network). Instantiates four `memory_module`s: `ffn_w1` (`[EMBED_DIM x FFN_DIM]`), `ffn_b1` (`[FFN_DIM]`), `ffn_w2` (`[FFN_DIM x EMBED_DIM]`), and `ffn_b2` (`[EMBED_DIM]`).

Proceeds through 2 compute states:

1. **LINEAR1**: For each `(seq, hidden_dim)` output element, accumulates `input[seq][in_dim] * W1[in_dim][hidden_dim]` across all `in_dim`, right-shifts by 8, adds bias `b1[hidden_dim]`. Then applies ReLU: if the result is negative, clamps to 0; if above 32767, clamps to 32767. Stores into `hidden_data[seq][hidden_dim]`. This computes `ReLU(input @ W1 + b1)`.
2. **LINEAR2**: For each `(seq, out_dim)` output element, accumulates `hidden[seq][hidden_dim] * W2[hidden_dim][out_dim]` across all `hidden_dim`, right-shifts by 8, adds bias `b2[out_dim]`, saturates to 16-bit signed range. Stores into `output_data[seq][out_dim]`. This computes `hidden @ W2 + b2`.

The hidden_data array `[SEQ_LEN x FFN_DIM]` is one of the largest register arrays in the design.

## output_projection

Projects the final hidden state of a single sequence position down to vocabulary-sized logits. Instantiates one `memory_module` for the projection weight matrix (`[EMBED_DIM x VOCAB_SIZE]`, loaded from `output_proj.mem`).

Takes `final_hidden_state[EMBED_DIM]` (a single vector, not the full sequence -- the top-level module feeds it `norm2_out[last_pos]`). For each `vocab_idx`, accumulates `hidden[dim] * W[dim][vocab_idx]` across all dims, right-shifts by 8, stores to `vocabulary_logits[vocab_idx]`. This is a single matrix-vector multiply producing `VOCAB_SIZE` logits.

## argmax

Finds the index of the maximum value in the `vocabulary_logits` array. Purely combinational comparison logic with a sequential scan: iterates through all `VOCAB_SIZE` entries, tracking the running maximum value and its index. Outputs `selected_token` (the predicted token ID) when done. No memory modules, no fixed-point arithmetic -- just a comparator loop.

## complete_transformer_decoder

Top-level module that wires everything together and orchestrates the full inference pipeline via a 10-state FSM. Declares all intermediate data arrays (`embedded_tokens`, `position_encoded`, `attention_out`, `norm1_out`, `ffn_out`, `norm2_out`, `final_logits`) and instantiates one of each submodule, connecting outputs to inputs in the correct order.

The FSM sequence is:
1. **IDLE**: Wait for `start` signal
2. **EMBEDDING**: Trigger `token_embedding`, wait for done
3. **POSITIONAL**: Trigger `positional_encoding`, wait for done
4. **ATTENTION**: Trigger `multi_head_attention`, wait for done
5. **LAYER_NORM1**: Trigger `layer_normalization` (with `residual_data = position_encoded`), wait for done
6. **FEED_FORWARD**: Trigger `feed_forward_network`, wait for done
7. **LAYER_NORM2**: Trigger `layer_normalization` (with `residual_data = norm1_out`), wait for done
8. **OUTPUT_PROJ**: Trigger `output_projection` (fed `norm2_out[last_pos]`, the hidden state of the last non-zero token), wait for done
9. **ARGMAX**: Trigger `argmax`, wait for done
10. **FINISHED**: Assert `done` and `valid`, output `predicted_token`

This implements a single transformer decoder layer: embedding + positional encoding, then one block of (multi-head self-attention -> add & layernorm -> FFN -> add & layernorm), followed by projection to vocabulary and argmax token selection. A `cycle_count` register increments every clock cycle for performance measurement.

The `last_pos` logic scans the input sequence combinationally to find the last non-zero token index, which determines which position's hidden state gets sent to the output projection (next-token prediction at the final filled position).

All intermediate arrays are declared as `reg` at the top level and passed as ports to submodules, which means they synthesize as flip-flop/LUT storage rather than BRAM -- this is the primary driver of the high LUT utilization discussed elsewhere.
