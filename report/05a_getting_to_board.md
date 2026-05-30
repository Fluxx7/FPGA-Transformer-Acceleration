# Hardware Development — Part 1: Getting to the Board

## Initial Synthesis

Initial synthesis of the GenCore design with its default parameters — 8 attention heads, 64-dimensional embeddings, 256-dimensional FFN — produced approximately 220% LUT utilization on the PYNQ-Z1. A design over 100% utilization cannot be placed and routed; the FPGA simply does not have enough resources. Reducing resource consumption to fit within the board's limits was the first major challenge.

![Initial utilization report at default parameters](../context/figures/utilization_initial.png)
<!-- TODO (Nicholas): Export this figure from Vivado and save to context/figures/ -->

A significant contributor to the excessive resource consumption is the design's use of large register arrays for intermediate storage throughout the pipeline. Each module maintains its own registers for intermediate products, but since the modules execute sequentially — only one is active at any time — this storage is never shared. This observation motivates a future architectural improvement (see Section 7).

## Parameter Reduction Experiments

Several parameters were candidates for reduction. The embedding dimension and FFN dimension were the primary targets, as they have the most direct impact on hardware resource usage and require no structural code changes. Other parameters were deprioritized:

- **Sequence length**: reducing the context window was considered a less meaningful test of model quality and treated as a last resort.
- **Number of attention heads**: partially hard-coded in the original design; modifying it requires structural code changes.
- **Vocabulary size**: already only 40 tokens — far smaller than any production model; further reduction was not practical.

The following experiments were run, reducing parameters incrementally to find the minimum that fits on the board:

<!-- TODO (Nicholas): Fill in this table with actual Vivado utilization numbers from your experiments.
  The approximate final numbers are known (72% at NUM_HEADS=4, EMBED_DIM=16, FFN_DIM=32)
  but the intermediate steps need the actual figures from Vivado.
-->

| EMBED_DIM | FFN_DIM | NUM_HEADS | LUT Utilization | Placed? |
|-----------|---------|-----------|-----------------|---------|
| 64 | 256 | 8 | ~220% | No |
| <!-- TODO --> | <!-- TODO --> | 8 | <!-- TODO --> | No |
| 16 | 32 | 8 | <!-- TODO --> | No |
| 16 | 32 | 4 | ~72% | Yes |

Ultimately, achieving successful placement required more aggressive parameter cuts than initially hoped. Reducing embedding and FFN dimensions alone was insufficient — even at EMBED_DIM=16 and FFN_DIM=32, the design still failed to place with 8 heads. Halving the number of attention heads from 8 to 4 was necessary, despite concerns that synthesis tools might not eliminate the unused hardware associated with hard-coded head counts.

![Utilization report at final parameters (EMBED_DIM=16, FFN_DIM=32, NUM_HEADS=4)](../context/figures/utilization_final.png)
<!-- TODO (Nicholas): Export this figure from Vivado and save to context/figures/ -->

With these parameters, the design places and routes with approximately 72% LUT utilization.

## Adding the AXI-Lite Wrapper

The original design had no interface to the PYNQ-Z1's ARM processing system. The board's standard PS-to-PL communication mechanism is AXI-Lite: a memory-mapped register interface that the ARM can read and write from Python. A wrapper module (`Vivado/transformer_axi_wrapper.v`) was written to bridge the top-level transformer decoder to this interface.

The wrapper exposes three registers:
- **Input token address**: the address in the token embedding memory of the current input sequence
- **Go signal**: a write to this register triggers an inference pass
- **Done/status register**: polled by the ARM to detect completion; the output token is read from this register

The Python driver (`Vivado/transformer_driver.py`) writes input tokens, pulses the go signal, polls until done, and reads the output token — the complete inference loop from the ARM side.

## Constraint File

No XDC constraint file was provided with the original design. A constraint file was created to map the design's clock and I/O ports to the correct physical pins on the PYNQ-Z1 and to define timing constraints for the target clock frequency.

<!-- TODO (Nicholas): What clock frequency did you target? What was the timing slack after the initial implementation? -->

## Code Corrections

Several errors in the original RTL required correction before synthesis would succeed. These are distinct from the logical bugs addressed in Section 5b — they were straightforward issues that prevented compilation or produced obviously incorrect synthesis results.

<!-- TODO (Nicholas): List the specific pre-synthesis fixes here. Examples from the transcripts include:
  - Constraint/port mapping issues
  - Any syntax or structural errors flagged by Vivado during synthesis
-->

## The SD Card Requirement

After successfully generating a bitstream, an additional requirement became apparent: to use the AXI-Lite Python interface, the PYNQ-Z1 needs to boot from an SD card containing the PYNQ Linux image. The board cannot run the Python overlay system without it. An SD card was acquired and the PYNQ image loaded.

<!-- TODO (Nicholas): Confirm whether the board run was successfully completed after acquiring the SD card. What was the first result from the actual hardware? -->
