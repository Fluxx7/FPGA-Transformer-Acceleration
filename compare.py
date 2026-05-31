#!/usr/bin/env python3
"""
Compare full vs. reduced hyperparameter models.
Uses a fixed train/val/test split, early stopping on val loss,
and multiple seeds to produce averaged metrics with error bars.
"""

import torch
import torch.nn as nn
import numpy as np
import os
import math
import matplotlib.pyplot as plt
from copy import deepcopy

from model import (
    Config, DecoderTransformer, TRAINING_SENTENCES, VOCAB_REVERSE,
    tokenize_sentence, pad_sequence, evaluate, probe_logits
)
from train import PLOTS_DIR

# --- Edit this to match your reduced hyperparameters ---
class Config1(Config):
    EMBED_DIM = 64
    NUM_HEADS = 8
    HEAD_DIM  = EMBED_DIM // NUM_HEADS
    FFN_DIM   = 256


class Config2(Config):
    EMBED_DIM = 16
    NUM_HEADS = 4
    HEAD_DIM  = EMBED_DIM // NUM_HEADS
    FFN_DIM   = 32

# --- Comparison settings ---
SEEDS      = [42, 123, 7, 44, 23, 734, 928, 38, 584, 20]   # one run per seed — add more for tighter error bars
MAX_EPOCHS = 200
PATIENCE   = 20             # stop if val loss doesn't improve for this many epochs

# Fixed data split (shuffled once with seed 0, then never changed)
PROBE_SENTENCE = "START the cat"

def make_split(sentences, train_frac=0.70, val_frac=0.15):
    """Reproducible shuffle then split into train / val / test."""
    rng = np.random.default_rng(0)
    idx = rng.permutation(len(sentences))
    n_train = int(len(sentences) * train_frac)
    n_val   = int(len(sentences) * val_frac)
    train = [sentences[i] for i in idx[:n_train]]
    val   = [sentences[i] for i in idx[n_train:n_train + n_val]]
    test  = [sentences[i] for i in idx[n_train + n_val:]]
    return train, val, test

def _make_tensors(sentences, seq_len):
    tokenized = [pad_sequence(tokenize_sentence(s), seq_len) for s in sentences]
    inputs  = torch.tensor([s[:-1] for s in tokenized], dtype=torch.long)
    targets = torch.tensor([s[1:]  for s in tokenized], dtype=torch.long)
    return inputs, targets

def train_with_early_stopping(config, train_sents, val_sents):
    """
    Train with early stopping on validation loss.
    Returns (best_model, train_losses, val_losses, best_epoch).
    """
    model = DecoderTransformer(config)
    optimizer = torch.optim.Adam(model.parameters(), lr=config.LEARNING_RATE)
    criterion = nn.CrossEntropyLoss(ignore_index=0)

    train_inputs,  train_targets = _make_tensors(train_sents, config.SEQ_LEN)
    val_inputs,    val_targets   = _make_tensors(val_sents,   config.SEQ_LEN)

    best_val_loss = math.inf
    best_weights  = deepcopy(model.state_dict())
    best_epoch    = 0
    patience_count = 0

    train_losses, val_losses = [], []

    for epoch in range(MAX_EPOCHS):
        # --- train ---
        model.train()
        total_loss = 0
        for i in range(0, len(train_inputs), config.BATCH_SIZE):
            bi = train_inputs[i:i+config.BATCH_SIZE]
            bt = train_targets[i:i+config.BATCH_SIZE]
            optimizer.zero_grad()
            loss = criterion(model(bi).view(-1, config.VOCAB_SIZE), bt.view(-1))
            loss.backward()
            torch.nn.utils.clip_grad_norm_(model.parameters(), 1.0)
            optimizer.step()
            total_loss += loss.item()
        train_losses.append(total_loss / (len(train_inputs) // config.BATCH_SIZE + 1))

        # --- validate ---
        model.eval()
        with torch.no_grad():
            val_loss = criterion(
                model(val_inputs).view(-1, config.VOCAB_SIZE),
                val_targets.view(-1)
            ).item() / (val_targets != 0).sum().item()
        val_losses.append(val_loss)

        if val_loss < best_val_loss:
            best_val_loss  = val_loss
            best_weights   = deepcopy(model.state_dict())
            best_epoch     = epoch + 1
            patience_count = 0
        else:
            patience_count += 1
            if patience_count >= PATIENCE:
                break

    model.load_state_dict(best_weights)
    return model, train_losses, val_losses, best_epoch

def run_seeds(config, train_sents, val_sents, test_sents, label):
    """Run training for each seed and collect metrics + curves."""
    all_metrics     = []
    all_train_curves = []
    all_val_curves   = []
    best_epochs      = []

    for seed in SEEDS:
        torch.manual_seed(seed)
        np.random.seed(seed)
        print(f"  [{label}] seed={seed}", end="", flush=True)

        model, t_losses, v_losses, best_ep = train_with_early_stopping(
            config, train_sents, val_sents
        )
        metrics = evaluate(model, test_sents)
        all_metrics.append(metrics)
        all_train_curves.append(t_losses)
        all_val_curves.append(v_losses)
        best_epochs.append(best_ep)
        print(f"  → stopped ep {best_ep}, test loss={metrics['loss']:.4f}, acc={metrics['accuracy']:.3f}")

    # aggregate
    agg = {}
    for key in all_metrics[0]:
        vals = [m[key] for m in all_metrics]
        agg[key] = {"mean": np.mean(vals), "std": np.std(vals)}

    return agg, all_train_curves, all_val_curves, best_epochs

def _plot_curves(ax, curves, color, label):
    """Plot individual seed curves (thin) + mean (thick)."""
    max_len = max(len(c) for c in curves)
    padded  = [c + [c[-1]] * (max_len - len(c)) for c in curves]
    arr     = np.array(padded)
    mean    = arr.mean(axis=0)
    for row in arr:
        ax.plot(row, color=color, alpha=0.25, linewidth=0.8)
    ax.plot(mean, color=color, linewidth=2, label=label)

def main():
    os.makedirs(PLOTS_DIR, exist_ok=True)

    train_sents, val_sents, test_sents = make_split(TRAINING_SENTENCES)
    print(f"Split: {len(train_sents)} train / {len(val_sents)} val / {len(test_sents)} test")

    full_label    = f"Full (E={Config1.EMBED_DIM}, H={Config1.NUM_HEADS}, F={Config1.FFN_DIM})"
    reduced_label = f"Reduced (E={Config2.EMBED_DIM}, H={Config2.NUM_HEADS}, F={Config2.FFN_DIM})"

    print("\n=== Full model ===")
    full_agg,    full_train,    full_val,    full_epochs    = run_seeds(Config1(), train_sents, val_sents, test_sents, "configuration 1")
    print("\n=== Reduced model ===")
    reduced_agg, reduced_train, reduced_val, reduced_epochs = run_seeds(Config2(), train_sents, val_sents, test_sents, "configuration 2")

    # --- Print results table ---
    print(f"\n{'Metric':<14} {'Full mean':>12} {'Full std':>10} {'Reduced mean':>14} {'Reduced std':>12}")
    print("-" * 64)
    for key in ("loss", "perplexity", "accuracy"):
        fm, fs = full_agg[key]["mean"],    full_agg[key]["std"]
        rm, rs = reduced_agg[key]["mean"], reduced_agg[key]["std"]
        print(f"{key:<14} {fm:>12.4f} {fs:>10.4f} {rm:>14.4f} {rs:>12.4f}")

    print(f"\nFull best epochs:    {full_epochs}  (mean {np.mean(full_epochs):.1f})")
    print(f"Reduced best epochs: {reduced_epochs}  (mean {np.mean(reduced_epochs):.1f})")

    # --- Plot 1: Training + val loss curves ---
    fig, axes = plt.subplots(1, 2, figsize=(14, 5))
    for ax, curves, title in [
        (axes[0], (full_train,   reduced_train), "Training Loss"),
        (axes[1], (full_val,     reduced_val),   "Validation Loss"),
    ]:
        _plot_curves(ax, curves[0], "dodgerblue", full_label)
        _plot_curves(ax, curves[1], "orangered",  reduced_label)
        ax.set_xlabel("Epoch"); ax.set_ylabel("Loss")
        ax.set_title(title); ax.legend(fontsize=7); ax.grid(True)
    fig.suptitle(f"Learning Curves ({len(SEEDS)} seeds, early stopping patience={PATIENCE})")
    fig.tight_layout()
    out = os.path.join(PLOTS_DIR, "compare_training_curves.png")
    plt.savefig(out); plt.close()
    print(f"\n✓ Saved plot: {out}")

    # --- Plot 2: Metrics with error bars ---
    metrics_keys = ["loss", "perplexity", "accuracy"]
    x = np.arange(len(metrics_keys))
    width = 0.35
    fig, ax = plt.subplots(figsize=(8, 5))
    ax.bar(x - width/2,
           [full_agg[m]["mean"]    for m in metrics_keys],
           width, yerr=[full_agg[m]["std"]    for m in metrics_keys],
           label="Full",    color="dodgerblue", capsize=5)
    ax.bar(x + width/2,
           [reduced_agg[m]["mean"] for m in metrics_keys],
           width, yerr=[reduced_agg[m]["std"] for m in metrics_keys],
           label="Reduced", color="orangered",  capsize=5)
    ax.set_xticks(x); ax.set_xticklabels(metrics_keys)
    ax.set_title(f"Test Set Metrics — mean ± std over {len(SEEDS)} seeds")
    ax.legend(); ax.grid(axis='y', linestyle='--', alpha=0.7)
    fig.tight_layout()
    out = os.path.join(PLOTS_DIR, "compare_metrics.png")
    plt.savefig(out); plt.close()
    print(f"✓ Saved plot: {out}")

    # --- Plot 3: Logit comparison (best seed = last trained) ---
    torch.manual_seed(SEEDS[-1]); np.random.seed(SEEDS[-1])
    full_final,    _, _, _ = train_with_early_stopping(Config1(), train_sents, val_sents)
    reduced_final, _, _, _ = train_with_early_stopping(Config2(), train_sents, val_sents)

    full_logits    = probe_logits(full_final,    PROBE_SENTENCE)
    reduced_logits = probe_logits(reduced_final, PROBE_SENTENCE)

    x = np.arange(Config.VOCAB_SIZE)
    fig, ax = plt.subplots(figsize=(14, 6))
    ax.bar(x - width/2, full_logits,    width, label="Full",    color="dodgerblue", alpha=0.85)
    ax.bar(x + width/2, reduced_logits, width, label="Reduced", color="orangered",  alpha=0.85)
    ax.set_xticks(x)
    ax.set_xticklabels([VOCAB_REVERSE[i] for i in range(Config.VOCAB_SIZE)], rotation=90, fontsize=8)
    ax.set_ylabel("Logit Value")
    ax.set_title(f'Logit Comparison on "{PROBE_SENTENCE}"')
    ax.legend(); ax.grid(axis='y', linestyle='--', alpha=0.7)
    fig.tight_layout()
    out = os.path.join(PLOTS_DIR, "compare_logits.png")
    plt.savefig(out); plt.close()
    print(f"✓ Saved plot: {out}")

    print("\nCOMPARISON COMPLETE!")

if __name__ == "__main__":
    main()
