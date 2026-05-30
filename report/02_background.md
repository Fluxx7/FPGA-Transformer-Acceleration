# Background

## Transformer Architecture

<!-- TODO: Claude can draft this section independently. Cover:
  - The attention mechanism: Q, K, V projections, scaled dot-product attention, softmax
  - Multi-head attention: why multiple heads, how outputs are concatenated
  - Positional encoding: why needed (attention is permutation-invariant), cosine/sine approach
  - Feed-forward network: two linear layers + activation
  - Layer normalization: what it does, why placed after attention and FFN
  - The decoder-only architecture (vs. encoder-decoder): autoregressive token generation
  Keep it concise — this is background, not the main contribution.
-->

## Fixed-Point Arithmetic

In standard software implementations, transformer models use 32-bit or 16-bit floating-point numbers. This hardware uses **Q8.8 fixed-point** throughout: each value is a 16-bit integer where the upper 8 bits represent the integer part and the lower 8 bits represent the fractional part. This format trades dynamic range and precision for hardware simplicity — fixed-point arithmetic requires far fewer LUTs than floating-point units.

The tradeoff is quantization error: real-valued weights and activations must be rounded to the nearest representable Q8.8 value. This introduces a noise floor that accumulates through the computation. The validation work (see Section 5b) measures this error at each module boundary and confirms it remains within acceptable bounds for the proof of concept.

<!-- TODO: Add a brief table or formula showing Q8.8 range and precision:
  - Range: approximately -128 to +127.996
  - Precision: 1/256 ≈ 0.0039
-->

## FPGAs and the PYNQ-Z1

A field-programmable gate array (FPGA) is an integrated circuit that can be reconfigured after manufacture to implement arbitrary digital logic. Rather than a fixed instruction set, an FPGA contains an array of configurable logic blocks — primarily **lookup tables (LUTs)**, flip-flops (registers), and **block RAM (BRAM)** — connected by a programmable routing fabric. A hardware design is described in a hardware description language (HDL) such as SystemVerilog, then compiled by a synthesis tool (here, Xilinx Vivado) into a **bitstream** that programs the FPGA fabric.

Key resource metrics relevant to this project:
- **LUT utilization**: the fraction of the FPGA's lookup tables consumed by the design. 100% is the hard ceiling — designs over this limit cannot be placed and routed.
- **BRAM**: dedicated on-chip memory blocks, far more area-efficient than register arrays for storing large tables (e.g., weight matrices).
- **Timing slack**: the margin between a signal's arrival time and the clock edge. Negative slack means the design cannot run at the target clock frequency.

The **PYNQ-Z1** board uses a Xilinx Zynq XC7Z020 SoC, which pairs an ARM Cortex-A9 processing system (PS) with an FPGA programmable logic (PL) fabric. The PS runs embedded Linux and a Python environment; the PL hosts the hardware accelerator. Communication between them uses the **AXI-Lite** protocol: memory-mapped registers in the PL are accessible from Python on the PS, allowing the ARM to send input tokens, trigger inference, and read output tokens. This architecture closely resembles a real embedded deployment where a host processor offloads inference to dedicated acceleration hardware.

## Verilator and the Simulation Flow

**Verilator** is an open-source tool that compiles SystemVerilog designs into cycle-accurate C++ models. Rather than running logic simulations on the FPGA or in a slow event-driven simulator, Verilator produces a fast executable that mimics the hardware's behavior cycle by cycle. This project uses Verilator extensively for per-module validation: each hardware module has a C++ test bench that drives inputs and captures outputs, paired with a Python script that generates reference values from PyTorch and compares them against the simulated hardware.

## Glossary

| Term | Definition |
|------|------------|
| AXI / AXI-Lite | ARM's AMBA bus protocol for memory-mapped communication between PS and PL on Zynq |
| Bitstream | Binary file that programs the FPGA fabric; produced by Vivado from a synthesized design |
| BRAM | Block RAM — dedicated on-chip memory in the FPGA, initialized from `.mem` files |
| FFN | Feed-forward network — a two-layer MLP inside each transformer block |
| FPGA | Field-programmable gate array — reconfigurable digital logic fabric |
| LUT | Lookup table — the basic configurable logic unit of an FPGA |
| MQP | Major Qualifying Project — WPI's capstone senior thesis project |
| PS / PL | Processing System / Programmable Logic — the two halves of the Zynq SoC |
| Q8.8 | Fixed-point format: 16-bit value with 8 integer bits and 8 fractional bits |
| SystemVerilog | Hardware description language used to write the RTL modules |
| Verilator | Open-source SystemVerilog-to-C++ compiler for cycle-accurate simulation |
| Vivado | Xilinx's synthesis and implementation tool for FPGA designs |
