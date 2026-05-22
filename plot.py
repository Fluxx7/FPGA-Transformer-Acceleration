#!/usr/bin/env python3
"""
Creates plots comparing the SystemVerilog results to the Python results
"""

import torch
import torch.nn as nn
import numpy as np
import os
from typing import cast
import matplotlib.pyplot as plt

from model import (
    Config, DecoderTransformer, VOCAB_REVERSE, probe_logits
)

MODELS_DIR = "models"
PLOTS_DIR  = "plots"
DATA_DIR   = "data"

def generate_verification_data(model: DecoderTransformer):
    print("\n--- Generating Verification Data ---")
    config = model.config

    os.makedirs(DATA_DIR, exist_ok=True)
    golden_path  = os.path.join(DATA_DIR, "golden_logits.txt")
    hardware_path = os.path.join(DATA_DIR, "hardware_logits.txt")

    golden_logits = probe_logits(model, "START the cat")
    np.savetxt(golden_path, golden_logits, fmt='%f')
    print(f"✓ Saved {golden_path}")

    if os.path.exists(hardware_path):
        print("Hardware logits found. Generating comparison plot...")
        hardware_logits = np.loadtxt(hardware_path, dtype=np.int32).astype(np.int16)

        max_abs = np.maximum(np.abs(golden_logits.min()), np.abs(golden_logits.max()))
        scale = (config.MAX_VAL * 0.8) / max_abs if max_abs > 0 else 1.0
        quantized_golden = np.clip(np.round(golden_logits * scale), config.MIN_VAL, config.MAX_VAL).astype(np.int16)

        x = np.arange(config.VOCAB_SIZE)
        width = 0.35
        fig, ax = plt.subplots(figsize=(14, 7))
        ax.bar(x - width/2, quantized_golden, width, label='Software (Quantized)', color='dodgerblue')
        ax.bar(x + width/2, hardware_logits,  width, label='Hardware (Verilog)',   color='orangered')
        ax.set_ylabel('Logit Value')
        ax.set_title('Software vs. Hardware Final Logit Comparison')
        ax.set_xticks(x)
        ax.set_xticklabels([VOCAB_REVERSE[i] for i in range(config.VOCAB_SIZE)], rotation=90, fontsize=8)
        ax.legend(); ax.grid(axis='y', linestyle='--', alpha=0.7)
        fig.tight_layout()
        out = os.path.join(PLOTS_DIR, "sw_hw_logit_comparison.png")
        plt.savefig(out); plt.close()
        print(f"✓ Saved plot: {out}")
    else:
        print(f"Info: {hardware_path} not found. Run the Verilog simulation first.")

def main():
    config = Config()
    os.makedirs(MODELS_DIR, exist_ok=True)
    model_path = os.path.join(MODELS_DIR, "decoder_model.pth")

    if not os.path.exists(model_path):
        print(f"No model found, run train.py first")
    else:
        print(f"--- Found {model_path}, loading. ---")
        model = DecoderTransformer(config)
        model.load_state_dict(torch.load(model_path, weights_only=True))
    generate_verification_data(model)
    print("\nPIPELINE COMPLETE!")

if __name__ == "__main__":
    main()
