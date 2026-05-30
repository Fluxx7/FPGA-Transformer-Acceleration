# Background

## Transformer Architecture

A transformer is a neural network architecture built around a mechanism called *attention* — a learned way of computing, for each position in a sequence, which other positions are most relevant to predicting the next token. This project implements a **decoder-only** transformer, which is the architecture underlying modern autoregressive language models: given a sequence of input tokens, predict the most likely next token, append it, and repeat.

### Tokens and Embeddings

The model operates on discrete tokens — in this case a vocabulary of 40 items covering articles, animals, verbs, adjectives, adverbs, and special tokens like `start`, `end`, and `pad`. Each token is represented by an integer index. A learned **token embedding** table maps each index to a dense vector in the model's embedding space. The idea is that training causes semantically related tokens to end up close together in that space — the classic example being that `king − man + woman ≈ queen`. All subsequent computation operates in this embedding space; the final step is a projection back to vocabulary size to produce output scores.

### Positional Encoding

Attention has no inherent notion of order — it treats the input as a set, not a sequence. To give the model information about where in the sequence each token appears, a **positional encoding** is added to each embedding before the computation begins. This project uses a cosine-based encoding: each position gets a fixed vector derived from sine and cosine functions at varying frequencies. Since this is summed with the token embedding, the model sees a combined signal encoding both what a token is and where it sits in the sequence.

### Scaled Dot-Product Attention

The core of the transformer is scaled dot-product attention. Each input vector is projected through three learned weight matrices to produce a **query** (Q), **key** (K), and **value** (V) vector. The intuition: the query represents what a position is looking for; the key represents what each position has to offer; the value is the information contributed when there is a match.

Attention scores are the dot product of each query against every key, scaled down by the square root of the head dimension to keep gradients from collapsing as dimensionality grows:

```
scores = (Q · Kᵀ) / sqrt(head_dim)
```

These scores pass through **softmax**, which normalizes them into a probability distribution summing to 1. The output for each position is the weighted sum of all value vectors using those normalized scores as weights — positions that are highly relevant contribute more. For a decoder, **causal masking** prevents any position from attending to tokens that appear later in the sequence, which is what makes autoregressive generation possible.

### Multi-Head Attention

Rather than running a single attention computation, the input is split into multiple **heads**, each operating on a lower-dimensional slice of the embedding space. Each head can learn to attend to different kinds of relationships simultaneously — one might pick up on syntactic patterns, another on semantic similarity. The outputs of all heads are concatenated and projected back to the full embedding dimension.

This project uses 4 attention heads over a 16-dimensional embedding, giving each head a 4-dimensional subspace. The original GenCore repository used 8 heads over a 64-dimensional embedding; reducing these parameters was necessary to fit within the PYNQ-Z1's resource budget (see Section 5a).

### Feed-Forward Network

After the attention sublayer, each position passes independently through a **feed-forward network** (FFN): two linear layers with a nonlinear activation in between. The FFN applies the same transformation to every position independently — there is no interaction between positions here. Its role is to give the model capacity to transform representations after attention has gathered information from across the sequence. The inner dimension is typically larger than the embedding dimension; here it is 64 versus 16.

### Layer Normalization

**Layer normalization** is applied after both the attention sublayer and the FFN. It normalizes each vector to zero mean and unit variance, then scales and shifts using learned parameters. This keeps activations from growing unbounded as they pass through the network, which stabilizes training. In the implementation used here, normalization is applied at the output of each sublayer before the residual connection.

### Autoregressive Decoding

At inference time, the model is run iteratively. The current token sequence is fed in, the model produces a logit score for every token in the vocabulary, and the token with the highest score is selected (argmax). That token is appended to the sequence and the process repeats until an `end` token is generated or the sequence length limit is reached. The model never sees tokens beyond its current position — each prediction depends only on what has come before, which is the defining property of an autoregressive decoder.

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
