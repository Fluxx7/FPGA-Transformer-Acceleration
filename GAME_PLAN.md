# Transformer Accelerator Game Plan

Target: PYNQ-Z1 (Zynq XC7Z020)

## Step 1: Sequentialize Attention Heads

Replace the 8 parallel `attention_head` instances with a single instance that runs 8 times. The `multi_head_attention` module currently instantiates all heads at once (lines 742-788) and starts them simultaneously. Instead, keep one head instance, add a head counter, and mux which weight files are loaded for each pass. Store each head's output in a small buffer, then concatenate and project as before. This is the single biggest resource win for minimal code change.

## Step 2: Single-Position Processing

Convert from processing all `SEQ_LEN` positions in parallel to processing one token at a time. All the `[SEQ_LEN][EMBED_DIM]` intermediate arrays become `[EMBED_DIM]` vectors. Embedding, positional encoding, FFN, and layer norm are straightforward — just drop the `seq_idx` loop and process the one position you're given. Attention is the main change: introduce a KV cache stored in BRAM that accumulates K and V vectors as each new position is processed. Q is computed for the current position only, attention scores are computed against all cached K entries, and the result is a weighted sum over cached V entries. An outer controller feeds tokens one at a time and manages the KV cache pointer.

## Step 3: Consolidate into a Generic Matmul Unit

Notice that embedding lookup, Q/K/V projection, output projection, FFN linear1, FFN linear2, and final output projection are all the same operation: accumulate `input[i] * weight[addr]`, shift, optionally add bias, optionally apply activation. Replace all of these with a single parameterizable matmul module that takes dimensions (M, N, K), a weight base address, an input base address, and an output base address. It reads inputs and weights from BRAM, writes results to BRAM. Softmax, layernorm, ReLU, and argmax stay as small dedicated modules since their compute patterns are different.

## Step 4: Move Intermediate Storage to BRAM

Replace all `reg` intermediate arrays with a shared BRAM scratchpad. Modules no longer pass data as array ports — instead they read/write to BRAM addresses. Each stage is told "your input starts at address X, write your output starting at address Y." This is what finally frees up the LUTs. The BRAM has a single-port or dual-port interface; the controller ensures only one module accesses it at a time (which is naturally true since stages run sequentially). Weight storage stays in separate BRAMs.

## Step 5: AXI-Lite Control Interface

Add a set of memory-mapped control registers accessible from the PS (ARM) side. The model architecture and weight addresses remain hard-coded in the PL. Registers cover: input token address, go signal, and a done/status register. The PS writes the input, pulses go, polls done, then reads the output token. This is the minimum needed to drive the accelerator as a PYNQ overlay without requiring a full software-defined model structure.

Weights stay baked in via `.mem` files at synthesis time. The design is tied to a specific model configuration and cannot be swapped without resynthesizing — this is an accepted constraint given the time budget.

## Notes

- Each step produces a functional design — no step depends on a later one
- Steps 1-2 solve the immediate resource problem and get the design running on the Z1
- Steps 3-4 are cleanup/consolidation that further reduce resources and set up the accelerator architecture
- Step 5 turns it into a usable PYNQ overlay; model architecture is hard-coded, not software-defined
- The fixed-point arithmetic (Q8.8 scaling, saturation clamping, softmax approximation) carries through unchanged across all steps
