#!/usr/bin/env python3
"""
Training and weight export pipeline.
Run this to train the model, export .mem files, and generate verification data.
"""

import torch
import torch.nn as nn
import numpy as np
import os
from typing import cast
import matplotlib.pyplot as plt

from model import (
    Config, DecoderTransformer, TRAINING_SENTENCES, VOCAB_REVERSE,
    tokenize_sentence, pad_sequence, quantize_weight, save_memory_file, probe_logits
)

MODELS_DIR = "models"
PLOTS_DIR  = "plots"
DATA_DIR   = "data"

def train_model(config: Config, sentences: list) -> tuple:
    """Train model and return (model, loss_history)."""
    print("\n--- Stage 1: Training Software Reference Model ---")
    model = DecoderTransformer(config)

    tokenized = [pad_sequence(tokenize_sentence(s), config.SEQ_LEN) for s in sentences]
    inputs  = torch.tensor([s[:-1] for s in tokenized], dtype=torch.long)
    targets = torch.tensor([s[1:]  for s in tokenized], dtype=torch.long)

    optimizer = torch.optim.Adam(model.parameters(), lr=config.LEARNING_RATE)
    criterion = nn.CrossEntropyLoss(ignore_index=0)

    losses = []
    model.train()
    for epoch in range(config.EPOCHS):
        total_loss = 0
        for i in range(0, len(inputs), config.BATCH_SIZE):
            batch_inputs  = inputs[i:i+config.BATCH_SIZE]
            batch_targets = targets[i:i+config.BATCH_SIZE]
            optimizer.zero_grad()
            logits = model(batch_inputs)
            loss = criterion(logits.view(-1, config.VOCAB_SIZE), batch_targets.view(-1))
            loss.backward()
            torch.nn.utils.clip_grad_norm_(model.parameters(), 1.0)
            optimizer.step()
            total_loss += loss.item()

        avg_loss = total_loss / (len(inputs) // config.BATCH_SIZE + 1)
        losses.append(avg_loss)
        if (epoch + 1) % 10 == 0:
            print(f"  Epoch {epoch+1}/{config.EPOCHS}, Loss: {avg_loss:.4f}")

    print("Training complete.")
    return model, losses

def export_model_weights(model: DecoderTransformer):
    print("\n--- Stage 2: Exporting Weights ---")
    config = model.config

    os.makedirs("memory", exist_ok=True)
    save_memory_file(quantize_weight(model.token_embedding.weight, 16), "memory/embedding.mem", 16)
    save_memory_file(quantize_weight(model.positional_embedding.weight, 16), "memory/positional_encoding.mem", 16)
    for h in range(config.NUM_HEADS):
        save_memory_file(quantize_weight(cast(nn.Linear, model.attention.q_heads[h]).weight, 16), f"memory/attention_wq_head{h}.mem", 16)
        save_memory_file(quantize_weight(cast(nn.Linear, model.attention.k_heads[h]).weight, 16), f"memory/attention_wk_head{h}.mem", 16)
        save_memory_file(quantize_weight(cast(nn.Linear, model.attention.v_heads[h]).weight, 16), f"memory/attention_wv_head{h}.mem", 16)
    save_memory_file(quantize_weight(model.attention.output_projection.weight, 16), "memory/attention_wo.mem", 16)
    save_memory_file(quantize_weight(model.layer_norm1.weight, 16), "memory/layernorm1_gamma.mem", 16)
    save_memory_file(quantize_weight(model.layer_norm1.bias, 16), "memory/layernorm1_beta.mem", 16)
    save_memory_file(quantize_weight(cast(torch.Tensor, model.ffn[0].weight), 16), "memory/ffn_w1.mem", 16)
    save_memory_file(quantize_weight(cast(torch.Tensor, model.ffn[0].bias), 16), "memory/ffn_b1.mem", 16)
    save_memory_file(quantize_weight(cast(torch.Tensor, model.ffn[2].weight), 16), "memory/ffn_w2.mem", 16)
    save_memory_file(quantize_weight(cast(torch.Tensor, model.ffn[2].bias), 16), "memory/ffn_b2.mem", 16)
    save_memory_file(quantize_weight(model.layer_norm2.weight, 16), "memory/layernorm2_gamma.mem", 16)
    save_memory_file(quantize_weight(model.layer_norm2.bias, 16), "memory/layernorm2_beta.mem", 16)
    save_memory_file(quantize_weight(model.output_projection.weight, 16), "memory/output_proj.mem", 16)
    print("✓ Saved all 36 memory files to memory/.")

    os.makedirs(PLOTS_DIR, exist_ok=True)
    ffn_layer1 = cast(nn.Linear, model.ffn[0])
    ffn_w1_float     = ffn_layer1.weight.detach().cpu().numpy().flatten()
    ffn_w1_quantized = quantize_weight(ffn_layer1.weight, 16).flatten()

    fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(12, 5))
    ax1.hist(ffn_w1_float,     bins=50, color='skyblue', edgecolor='black')
    ax1.set_title("Original FP32 Weights (FFN Layer 1)")
    ax1.set_xlabel("Value"); ax1.set_ylabel("Frequency")
    ax2.hist(ffn_w1_quantized, bins=50, color='salmon',  edgecolor='black')
    ax2.set_title("Quantized INT16 Weights (FFN Layer 1)")
    ax2.set_xlabel("Value")
    fig.tight_layout()
    plt.savefig(os.path.join(PLOTS_DIR, "quantization_effect.png"))
    plt.close()
    print(f"✓ Saved plot: {PLOTS_DIR}/quantization_effect.png")

# def generate_verification_data(model: DecoderTransformer):
#     print("\n--- Stage 3: Generating Verification Data ---")
#     config = model.config

#     os.makedirs(DATA_DIR, exist_ok=True)
#     golden_path  = os.path.join(DATA_DIR, "golden_logits.txt")
#     hardware_path = os.path.join(DATA_DIR, "hardware_logits.txt")

#     golden_logits = probe_logits(model, "START the cat")
#     np.savetxt(golden_path, golden_logits, fmt='%f')
#     print(f"✓ Saved {golden_path}")

#     if os.path.exists(hardware_path):
#         print("Hardware logits found. Generating comparison plot...")
#         hardware_logits = np.loadtxt(hardware_path, dtype=np.int32).astype(np.int16)

#         max_abs = np.maximum(np.abs(golden_logits.min()), np.abs(golden_logits.max()))
#         scale = (config.MAX_VAL * 0.8) / max_abs if max_abs > 0 else 1.0
#         quantized_golden = np.clip(np.round(golden_logits * scale), config.MIN_VAL, config.MAX_VAL).astype(np.int16)

#         x = np.arange(config.VOCAB_SIZE)
#         width = 0.35
#         fig, ax = plt.subplots(figsize=(14, 7))
#         ax.bar(x - width/2, quantized_golden, width, label='Software (Quantized)', color='dodgerblue')
#         ax.bar(x + width/2, hardware_logits,  width, label='Hardware (Verilog)',   color='orangered')
#         ax.set_ylabel('Logit Value')
#         ax.set_title('Software vs. Hardware Final Logit Comparison')
#         ax.set_xticks(x)
#         ax.set_xticklabels([VOCAB_REVERSE[i] for i in range(config.VOCAB_SIZE)], rotation=90, fontsize=8)
#         ax.legend(); ax.grid(axis='y', linestyle='--', alpha=0.7)
#         fig.tight_layout()
#         out = os.path.join(PLOTS_DIR, "sw_hw_logit_comparison.png")
#         plt.savefig(out); plt.close()
#         print(f"✓ Saved plot: {out}")
#     else:
#         print(f"Info: {hardware_path} not found. Run the Verilog simulation first.")

def main():
    config = Config()
    os.makedirs(MODELS_DIR, exist_ok=True)
    model_path = os.path.join(MODELS_DIR, "decoder_model.pth")

    model, losses = train_model(config, TRAINING_SENTENCES)
    torch.save(model.state_dict(), model_path)
    print(f"✓ Saved {model_path}")

    os.makedirs(PLOTS_DIR, exist_ok=True)
    plt.figure(figsize=(8, 5))
    plt.plot(range(1, config.EPOCHS + 1), losses, marker='.')
    plt.xlabel("Epoch"); plt.ylabel("Cross-Entropy Loss")
    plt.title("Model Training Convergence")
    plt.grid(True); plt.tight_layout()
    out = os.path.join(PLOTS_DIR, "training_loss_curve.png")
    plt.savefig(out); plt.close()
    print(f"✓ Saved plot: {out}")

    export_model_weights(model)
    print("\nPIPELINE COMPLETE!")

if __name__ == "__main__":
    main()
