# Transformer Accelerator Game Plan

Target: PYNQ-Z1 (Zynq XC7Z020)

## Step 1: Separate Vocabulary From Hardware

Remove `token_embedding` and `argmax` from the design and directly 

## Step 2: Sequentialize Attention Heads

Replace the 8 parallel `attention_head` instances with a single instance that runs 8 times. The `multi_head_attention` module currently instantiates all heads at once (lines 742-788) and starts them simultaneously. Instead, keep one head instance, add a head counter, and mux which weight files are loaded for each pass. Store each head's output in a small buffer, then concatenate and project as before. This is the single biggest resource win for minimal code change.

## Step 3: Consolidate into a Generic Matmul Unit

Notice that embedding lookup, Q/K/V projection, output projection, FFN linear1, FFN linear2, and final output projection are all the same operation: accumulate `input[i] * weight[addr]`, shift, optionally add bias, optionally apply activation. Replace all of these with a single parameterizable matmul module that takes dimensions (M, N, K), a weight base address, an input base address, and an output base address. It reads inputs and weights from BRAM, writes results to BRAM. Softmax, layernorm, ReLU, and argmax stay as small dedicated modules since their compute patterns are different.

## Step 4: Move Intermediate Storage to BRAM

Replace all `reg` intermediate arrays with a shared BRAM scratchpad. Modules no longer pass data as array ports — instead they read/write to BRAM addresses. Each stage is told "your input starts at address X, write your output starting at address Y." This is what finally frees up the LUTs. The BRAM has a single-port or dual-port interface; the controller ensures only one module accesses it at a time (which is naturally true since stages run sequentially). Weight storage stays in separate BRAMs.

## Notes

- Each step produces a functional design — no step depends on a later one
