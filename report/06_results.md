# Results

## Module Validation Summary

The following table summarizes the final validation results for each hardware module, measured by comparing Verilator simulation outputs against PyTorch reference computations.

| Module | Correlation | Mean Error | Max Error | Notes |
|--------|-------------|------------|-----------|-------|
| token_embedding | 1.0 | ~0 | ~0 | Passed first run; no changes needed |
| positional_encoding | 1.0 | ~0 | ~0 | Fixed pipeline stage timing |
| layer_normalization | 1.0 | ~0 | ~0 | Replaced combinational sqrt with rsqrt LUT |
| enhanced_softmax | ~0.9991 | ~0.004 | ~0.03 | Exponential LUT approximation; not 1.0 by design |
| feed_forward_network | 1.0 | ~0 | ~0 | Fixed non-blocking assignment errors in both layers |
| output_projection | 1.0 | ~0 | ~0 | Fixed PyTorch/hardware memory layout mismatch |
| argmax | 1.0 | 0 | 0 | 20/20 test cases; deterministic |
| attention_head | ~0.98+ | ~0.35 | ~1.9 | Compound quantization + softmax approximation error |
| multi_head_attention | ~0.98+ | <!-- TODO --> | <!-- TODO --> | Depends on attention_head |
| complete_transformer_decoder | ~0.9996+ | ~0.27 | ~0.8 | Final logit correlation; 5000-sentence training |

<!-- TODO (Nicholas): Fill in the exact final numbers from your test runs. The values above are from the transcripts and may not match the last run exactly. -->

## End-to-End Hardware Outputs

After training on 5,000 sentences, the hardware (via Verilator simulation) produces the following outputs for representative inputs:

| Input Tokens | Hardware Output | Software Output | Match? |
|-------------|-----------------|-----------------|--------|
| *(empty)* | *the tall fish jumps gently* | *the tall fish jumps gently* | ✅ |
| `the` | *the cat sleeps gently* | *the cat sleeps gently* | ✅ |
| `the cat` | *the cat sleeps gently* | *the cat sleeps gently* | ✅ |
| `the dog` | *the dog jumps gently* | *the dog jumps gently* | ✅ |
| `a cat runs` | token 32 | token 39 | ❌ (same top-5) |

<!-- TODO (Nicholas): 
  - Confirm these outputs against the actual test run output
  - Run additional test cases and add them to the table
  - For the `a cat runs` case, add the actual top-5 logit rankings showing they match
-->

## FPGA Resource Utilization

<!-- TODO (Nicholas): Fill in the utilization table below from Vivado implementation reports.
  These are the key numbers: LUTs, FFs (flip-flops), BRAM, DSPs, for both the initial default
  parameters and the final placed parameters. Screenshots of the utilization report should be
  saved to context/figures/ and referenced here.
-->

| Configuration | LUT Usage | FF Usage | BRAM | DSP | Placed? |
|---------------|-----------|----------|------|-----|---------|
| Default (8h, 64e, 256f) | ~220% | <!-- TODO --> | <!-- TODO --> | <!-- TODO --> | No |
| Final (4h, 16e, 32f) | ~72% | <!-- TODO --> | <!-- TODO --> | <!-- TODO --> | Yes |

## Timing and Performance

<!-- TODO (Nicholas): The following need to be measured:

**Clock frequency**: What is the target clock frequency in the constraint file? What is the 
achieved frequency after implementation (i.e., what is the worst negative slack, or is 
timing clean)?

**Impact of rsqrt lookup table fix**: The original layer normalization used a combinational 
sqrt approximation that was likely the dominant timing bottleneck. After replacing it with 
a lookup table, the worst-case combinational path should have improved. Has a new Vivado 
implementation been run post-fix? What does the timing report show?

**Tokens per second**: Clock frequency (Hz) × (1 / cycles per inference pass).
The number of cycles per inference pass can be read from the Verilator simulation — add a 
cycle counter to the complete decoder test bench.
-->

| Metric | Value |
|--------|-------|
| Target clock frequency | <!-- TODO --> MHz |
| Achieved clock frequency | <!-- TODO --> MHz |
| Cycles per inference pass | <!-- TODO --> |
| Tokens per second | <!-- TODO --> |

## On-Board Results

<!-- TODO (Nicholas): Once the board run is complete (SD card + PYNQ image loaded), add results here:
  - Does the board produce the same outputs as Verilator?
  - Any unexpected differences? 
  - Photo or terminal capture of the Python interface showing a successful inference
-->
