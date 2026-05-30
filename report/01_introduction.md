# Introduction

## Motivation

Transformer-based models are becoming more prevalent in many industries, and future innovations will likely drive further growth. For industries that heavily rely on embedded devices, this presents a problem. Since a full GPU/NPU would be too costly and power-hungry for the constraints of an embedded system, they either have to forgo any potential applications of transformers, or they need to send requests to a remote model, which adds latency and either requires outsourcing the model or dedicating extra hardware to running and hosting the model in a semi-local capacity. If a device needs to operate without internet or if privacy is a concern, a remote model is not a feasible option, meaning that these devices are left without a viable option for usage of transformer-based models. Dedicated FPGA-based acceleration hardware offers a path to running these models locally on such devices.

<!-- TODO: Professor wants this section expanded with specific application examples and their requirements. Suggested additions:
  - Medical devices: specific examples (e.g. patient monitoring, diagnostic assistance), why data privacy makes cloud inference unacceptable
  - IoT / edge devices: latency requirements, offline operation
  - Industrial embedded systems: reliability, no connectivity assumptions
  - Quantify the gap: what does a transformer require vs. what a typical embedded MCU/SoC can provide?
  - Why FPGA specifically vs. a custom ASIC or a low-power CPU: mass production cost, reconfigurability, availability
  Note: treat this expansion as lower priority for the first draft — get the rest of the report in shape first.
-->

## Project Overview

This project implements a parameterized transformer decoder accelerator in SystemVerilog, synthesized to a PYNQ-Z1 FPGA board, as a proof of concept for local transformer inference on embedded systems. The PYNQ-Z1 combines an ARM Cortex-A9 processing system with a Xilinx FPGA fabric on a single Zynq SoC, making it an excellent simulation of a real embedded deployment: the ARM side runs Python control code, while the FPGA fabric executes the hardware accelerator.

The goal is not to produce a production-ready system but to demonstrate that a correctly-functioning transformer decoder can be implemented in hardware, that its outputs match a software reference model to within acceptable quantization error, and to identify the architectural improvements that would make the design practical at scale.
