#!/usr/bin/env python3
"""
Complete Decoder Transformer Training & Verification Pipeline for IEEE Paper
Generates all memory files, training plots, and hardware verification plots.
"""

import torch
import torch.nn as nn
import torch.optim as optim
import numpy as np
import math
import os
from typing import List, cast
import matplotlib.pyplot as plt

# --- Configuration Matching Verilog Implementation ---
class Config:
    VOCAB_SIZE = 25
    EMBED_DIM = 16
    SEQ_LEN = 8
    NUM_HEADS = 4
    HEAD_DIM = EMBED_DIM // NUM_HEADS
    FFN_DIM = 32
    DATA_WIDTH = 16
    MAX_VAL = 2**(DATA_WIDTH - 1) - 1
    MIN_VAL = -2**(DATA_WIDTH - 1)
    EPOCHS = 100
    LEARNING_RATE = 0.001
    BATCH_SIZE = 4

# --- Dataset and Vocabulary (as provided) ---
TRAINING_SENTENCES = [
    # (Using a smaller subset for faster example run, use your full list for the paper)
    "START the big red cat runs quickly on END", "START the small blue dog jumps slowly in END",
    "START the happy red bird flies quickly under END", "START a big blue cat sleeps slowly near END",
    "START a small red dog eats quickly with END", "START the happy small bird flies slowly on END",
    "START the big happy red cat runs quickly near END", "START a small happy blue dog jumps slowly under END",
    "START the big red happy bird flies quickly with END", "START a small blue happy cat sleeps slowly on END",
    "START the red big happy dog eats quickly in END", "START a blue small happy bird flies slowly near END",
    "START the big red cat runs quickly and jumps near END", "START the small blue dog jumps slowly and runs with END",
    "START the happy red bird flies quickly and sleeps on END", "START a big blue cat sleeps slowly and eats under END",
    "START a small red dog eats quickly and runs in END", "START the happy blue bird flies slowly and jumps near END",
    "START the cat runs quickly under the big red END", "START the dog jumps slowly near the small blue END",
    "START the bird flies quickly on the happy red END", "START a cat sleeps slowly in the big blue END",
    "START a dog eats quickly with the small red END", "START a bird flies slowly under the happy blue END"
]
VOCABULARY = {
    'PAD': 0, 'START': 1, 'END': 2, 'the': 3, 'a': 4, 'cat': 5, 'dog': 6, 'bird': 7,
    'runs': 8, 'jumps': 9, 'flies': 10, 'sleeps': 11, 'eats': 12, 'on': 13, 'in': 14,
    'under': 15, 'near': 16, 'with': 17, 'big': 18, 'small': 19, 'red': 20, 'blue': 21,
    'happy': 22, 'quickly': 23, 'slowly': 24
}
VOCAB_REVERSE = {v: k for k, v in VOCABULARY.items()}

# --- Helper Functions ---
def tokenize_sentence(sentence: str) -> List[int]:
    tokens = sentence.split()
    return [VOCABULARY[token] for token in tokens if token in VOCABULARY]

def pad_sequence(tokens: List[int], max_len: int) -> List[int]:
    return (tokens + [0] * max_len)[:max_len]

# --- PyTorch Model (as provided) ---
class MultiHeadAttention(nn.Module):
    def __init__(self, embed_dim: int, num_heads: int):
        super().__init__()
        self.embed_dim = embed_dim
        self.num_heads = num_heads
        self.head_dim = embed_dim // num_heads
        self.q_heads = nn.ModuleList([nn.Linear(embed_dim, self.head_dim, bias=False) for _ in range(num_heads)])
        self.k_heads = nn.ModuleList([nn.Linear(embed_dim, self.head_dim, bias=False) for _ in range(num_heads)])
        self.v_heads = nn.ModuleList([nn.Linear(embed_dim, self.head_dim, bias=False) for _ in range(num_heads)])
        self.output_projection = nn.Linear(embed_dim, embed_dim, bias=False)

    def forward(self, x):
        batch_size, seq_len, _ = x.shape
        head_outputs = []
        for h in range(self.num_heads):
            Q, K, V = self.q_heads[h](x), self.k_heads[h](x), self.v_heads[h](x)
            scores = torch.matmul(Q, K.transpose(-2, -1)) / math.sqrt(self.head_dim)
            mask = torch.tril(torch.ones(seq_len, seq_len)).to(x.device)
            scores = scores.masked_fill(mask == 0, float('-inf'))
            attention_weights = torch.softmax(scores, dim=-1)
            attention_weights = torch.nan_to_num(attention_weights, 0.0)
            head_output = torch.matmul(attention_weights, V)
            head_outputs.append(head_output)
        concatenated = torch.cat(head_outputs, dim=-1)
        return self.output_projection(concatenated)

class DecoderTransformer(nn.Module):
    def __init__(self, config: Config):
        super().__init__()
        self.config = config
        self.token_embedding = nn.Embedding(config.VOCAB_SIZE, config.EMBED_DIM)
        self.positional_embedding = nn.Embedding(config.SEQ_LEN, config.EMBED_DIM)
        self.attention = MultiHeadAttention(config.EMBED_DIM, config.NUM_HEADS)
        self.layer_norm1 = nn.LayerNorm(config.EMBED_DIM)
        self.layer_norm2 = nn.LayerNorm(config.EMBED_DIM)
        self.ffn = nn.Sequential(
            nn.Linear(config.EMBED_DIM, config.FFN_DIM),
            nn.ReLU(),
            nn.Linear(config.FFN_DIM, config.EMBED_DIM)
        )
        self.output_projection = nn.Linear(config.EMBED_DIM, config.VOCAB_SIZE, bias=False)

    def forward(self, x):
        batch_size, seq_len = x.shape
        positions = torch.arange(seq_len).unsqueeze(0).expand(batch_size, -1).to(x.device)
        embeddings = self.token_embedding(x) + self.positional_embedding(positions)
        attention_out = self.attention(embeddings)
        norm1_out = self.layer_norm1(embeddings + attention_out)
        ffn_out = self.ffn(norm1_out)
        norm2_out = self.layer_norm2(norm1_out + ffn_out)
        return self.output_projection(norm2_out)

# --- Training and Export Functions (with plotting integrated) ---
def train_model():
    """Train the decoder and generate the training loss plot."""
    print("\n--- Stage 1: Training Software Reference Model ---")
    config = Config()
    model = DecoderTransformer(config)

    tokenized_data = [pad_sequence(tokenize_sentence(s), config.SEQ_LEN) for s in TRAINING_SENTENCES]
    inputs = torch.tensor([seq[:-1] for seq in tokenized_data], dtype=torch.long)
    targets = torch.tensor([seq[1:] for seq in tokenized_data], dtype=torch.long)

    optimizer = optim.Adam(model.parameters(), lr=config.LEARNING_RATE)
    criterion = nn.CrossEntropyLoss(ignore_index=0)

    losses = []
    model.train()
    for epoch in range(config.EPOCHS):
        total_loss = 0
        for i in range(0, len(inputs), config.BATCH_SIZE):
            batch_inputs, batch_targets = inputs[i:i+config.BATCH_SIZE], targets[i:i+config.BATCH_SIZE]
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
            print(f"Epoch {epoch+1}/{config.EPOCHS}, Loss: {avg_loss:.4f}")

    print("Training complete.")

    # Generate and save the training loss plot
    plt.figure(figsize=(8, 5))
    plt.plot(range(1, config.EPOCHS + 1), losses, marker='.')
    plt.xlabel("Epoch")
    plt.ylabel("Cross-Entropy Loss")
    plt.title("Model Training Convergence")
    plt.grid(True)
    plt.tight_layout()
    plt.savefig("training_loss_curve.png")
    print("✓ Saved plot: training_loss_curve.png")

    return model

def quantize_weight(weight: torch.Tensor, data_width: int) -> np.ndarray:
    max_val, min_val = 2**(data_width-1) - 1, -2**(data_width-1)
    weight_np = weight.detach().cpu().numpy()
    max_abs = np.maximum(np.abs(weight_np.min()), np.abs(weight_np.max()))
    scale = (max_val * 0.8) / max_abs if max_abs > 0 else 1.0
    return np.clip(np.round(weight_np * scale), min_val, max_val).astype(np.int16)

def save_memory_file(data: np.ndarray, filename: str, data_width: int):
    with open(filename, 'w') as f:
        for val in data.flatten():
            unsigned_val = int(val) & ((1 << data_width) - 1)
            f.write(f"{unsigned_val:0{data_width//4}x}\n")

def export_model_weights(model: DecoderTransformer):
    """Export all weights and generate the quantization plot."""
    print("\n--- Stage 2: Exporting Weights and Generating Plots ---")
    config = Config()

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

    # Generate and save the quantization plot
    ffn_layer1 = cast(nn.Linear, model.ffn[0])
    ffn_w1_float = ffn_layer1.weight.detach().cpu().numpy().flatten()
    ffn_w1_quantized = quantize_weight(ffn_layer1.weight, 16).flatten()

    fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(12, 5))
    ax1.hist(ffn_w1_float, bins=50, color='skyblue', edgecolor='black')
    ax1.set_title("Original FP32 Weights (FFN Layer 1)")
    ax1.set_xlabel("Value")
    ax1.set_ylabel("Frequency")
    ax2.hist(ffn_w1_quantized, bins=50, color='salmon', edgecolor='black')
    ax2.set_title("Quantized INT16 Weights (FFN Layer 1)")
    ax2.set_xlabel("Value")
    fig.tight_layout()
    plt.savefig("quantization_effect.png")
    print("✓ Saved plot: quantization_effect.png")

def generate_verification_data(model: DecoderTransformer):
    """Generate golden logits and the final comparison plot."""
    print("\n--- Stage 3: Generating Verification Data ---")
    config = Config()
    model.eval()

    test_sentence = "START the cat"
    tokens = tokenize_sentence(test_sentence)
    last_token_index = len(tokens) - 1
    padded = pad_sequence(tokens, config.SEQ_LEN - 1)
    input_tensor = torch.tensor([padded], dtype=torch.long)

    with torch.no_grad():
        logits = model(input_tensor)
        golden_logits = logits[0, last_token_index, :].detach().cpu().numpy()

    np.savetxt("golden_logits.txt", golden_logits, fmt='%f')
    print("✓ Saved golden_logits.txt for hardware verification.")

    # Check if hardware results exist and create the final plot
    if os.path.exists("hardware_logits.txt"):
        print("Hardware logits file found. Generating comparison plot...")
        # Load hardware logits (they are already quantized integers)
        hardware_logits_unsigned = np.loadtxt("hardware_logits.txt", dtype=np.int32)
        # Convert from two's complement unsigned back to signed for plotting
        hardware_logits = hardware_logits_unsigned.astype(np.int16)

        # For comparison, quantize the golden logits as well
        # We need a custom quantization for logits
        max_abs = np.maximum(np.abs(golden_logits.min()), np.abs(golden_logits.max()))
        scale = (config.MAX_VAL * 0.8) / max_abs if max_abs > 0 else 1.0
        quantized_golden_logits = np.clip(np.round(golden_logits * scale), config.MIN_VAL, config.MAX_VAL).astype(np.int16)

        # Plotting
        x = np.arange(config.VOCAB_SIZE)
        width = 0.35

        fig, ax = plt.subplots(figsize=(14, 7))
        rects1 = ax.bar(x - width/2, quantized_golden_logits, width, label='Software Model (Quantized)', color='dodgerblue')
        rects2 = ax.bar(x + width/2, hardware_logits, width, label='Hardware (Verilog)', color='orangered')

        ax.set_ylabel('Logit Value')
        ax.set_title('Software vs. Hardware Final Logit Comparison')
        ax.set_xticks(x)
        ax.set_xticklabels([VOCAB_REVERSE[i] for i in range(config.VOCAB_SIZE)], rotation=90, fontsize=8)
        ax.legend()
        ax.grid(axis='y', linestyle='--', alpha=0.7)
        fig.tight_layout()
        plt.savefig("sw_hw_logit_comparison.png")
        print("✓ Saved final plot: sw_hw_logit_comparison.png")
    else:
        print("Info: hardware_logits.txt not found. Run Verilog simulation, then re-run this script to generate the final plot.")

def main():
    if not os.path.exists("decoder_model.pth"):
        model = train_model()
        torch.save(model.state_dict(), "decoder_model.pth")
        print("✓ Saved trained model to decoder_model.pth")
    else:
        print("--- Found existing model file (decoder_model.pth). Loading it. ---")
        config = Config()
        model = DecoderTransformer(config)
        model.load_state_dict(torch.load("decoder_model.pth"))

    export_model_weights(model)
    generate_verification_data(model)
    print("\nPIPELINE COMPLETE!")

if __name__ == "__main__":
    main()