# Future Work

The current implementation is a working proof of concept, but several architectural improvements would substantially increase its practical value — either by reducing resource consumption enough to support larger model parameters, or by making the design more flexible and reusable. Each improvement described here is independent of the others and produces a functional design when applied in isolation.

## Sequentializing the Attention Heads

The current `multi_head_attention` module instantiates one `attention_head` hardware unit for each head in the model. All heads run simultaneously, which is fast but expensive: with four heads, the FPGA contains four complete copies of the attention head logic. Since each head's computation is independent of the others — they read different weight memories, process the same input, and write to separate output slots — the parallelism is real but not necessary. The same result can be obtained by running a single attention head unit four times in sequence, accumulating each head's output into the appropriate slot in the output buffer.

This change is the single largest resource reduction available with minimal code change. The number of attention heads would effectively become a runtime parameter (how many times to iterate the single head unit), rather than requiring N copies of hardware. This flexibility would also allow increasing the head count — and therefore model capacity — without a corresponding increase in resource consumption.

## Generic Parameterizable Matrix Multiplication Unit

Nearly every module in the pipeline — token embedding, Q/K/V projection, feed-forward layers, output projection — performs the same fundamental operation: multiply an input vector by a weight matrix and optionally add a bias. Currently, each module contains its own bespoke implementation of this operation, along with its own dedicated intermediate storage registers.

A generic matrix multiplication unit, parameterized by input/output dimensions, would replace all of these redundant implementations. Since the modules run sequentially, only one matrix multiplication ever occurs at a time — the single shared unit would be fully utilized and never idle. All modules would interface with it by providing their weight addresses and input/output addresses, receiving results when the unit completes.

This consolidation would reduce the total gate count substantially. It would also make the design easier to maintain and extend: optimizations to the matrix multiplication unit (such as pipelining or DSP block inference) would automatically benefit every module that uses it.

## Shared Intermediate Storage (BRAM Scratchpad)

Each module currently maintains its own registers for intermediate products — partial sums, pipeline stages, and buffered outputs. These registers collectively consume a significant fraction of the FPGA's flip-flop resources. Because the modules execute sequentially, their intermediate storage is never simultaneously active: when the FFN is computing, the attention head's intermediate registers are idle, and vice versa.

Replacing all per-module intermediate registers with a single shared BRAM scratchpad would allow this storage to be reused across stages. Each module would be allocated a region of the scratchpad for its working state and would read and write via the BRAM interface rather than dedicated registers. The controller would ensure only one module accesses the scratchpad at a time — which is naturally satisfied by the sequential execution model.

Unlike converting to BRAM for weight storage, this change should introduce no additional latency: modules are replacing register reads and writes with BRAM reads and writes of the same data, not adding new access steps. The benefit is purely in resource utilization.

Combined with the generic matrix multiplication unit, this change could reduce LUT and flip-flop usage dramatically — potentially enough to support the original default parameters (8 heads, 64-dimensional embeddings, 256-dimensional FFN) on the same PYNQ-Z1 board.

## Runtime Model Weight Updates

Currently, model weights are baked into the FPGA bitstream via `.mem` files at synthesis time. Updating the weights requires re-synthesizing and re-programming the board — a process that takes roughly 20 minutes. This is acceptable for a proof of concept but would be limiting in any real deployment scenario where models need to be updated or different tasks require different trained weights.

A more flexible approach would treat the weight memories as writable BRAM blocks. The ARM processing system could load a new set of weight files over the AXI interface before triggering inference, effectively flashing the model without resynthesis. The hardware parameters (embedding dimension, head count, etc.) would still be fixed at synthesis time — only the learned values would be updatable — but this would allow retraining and redeployment without a Vivado build cycle.

## Vocabulary Independence

The output projection and argmax modules are currently tied to a specific vocabulary size at synthesis time, because the output weight matrix has dimensions `[EMBED_DIM × VOCAB_SIZE]`. Removing this coupling would allow the vocabulary to be changed by retraining the software model (with the same architectural parameters) without modifying the hardware.

One path to achieving this, enabled by the generic matrix multiplication unit above, is to expose the output projection weight memory as a writable region accessible over the AXI interface. The hardware would perform the projection using whatever weights are loaded, and the `VOCAB_SIZE` could be treated as an upper bound rather than a fixed compile-time constant.
