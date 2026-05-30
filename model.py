"""
Shared model definitions, dataset, and utilities.
Imported by train.py and compare.py.
"""

import torch
import torch.nn as nn
import numpy as np
import math
from typing import List
import re
import itertools

# -- Model Configuration
class Config:
    VOCAB_SIZE = 40
    EMBED_DIM = 16
    SEQ_LEN = 8
    NUM_HEADS = 4
    HEAD_DIM = EMBED_DIM // NUM_HEADS
    FFN_DIM = 128
    DATA_WIDTH = 16
    MAX_VAL = 2**(DATA_WIDTH - 1) - 1
    MIN_VAL = -2**(DATA_WIDTH - 1)
    EPOCHS = 20
    LEARNING_RATE = 0.001
    BATCH_SIZE = 4

# -- Model Vocab
VOCABULARY = {
    # Special
    'PAD': 0, 'START': 1, 'END': 2,
    # Articles
    'the': 3, 'a': 4,
    # Animals (original)
    'cat': 5, 'dog': 6, 'bird': 7,
    # Verbs (original)
    'runs': 8, 'jumps': 9, 'flies': 10, 'sleeps': 11, 'eats': 12,
    # Prepositions (original)
    'on': 13, 'in': 14, 'under': 15, 'near': 16, 'with': 17,
    # Adjectives (original)
    'big': 18, 'small': 19, 'red': 20, 'blue': 21, 'happy': 22,
    # Adverbs (original)
    'quickly': 23, 'slowly': 24,
    # --- New tokens ---
    # Animals
    'fish': 25, 'fox': 26, 'bear': 27,
    # Verbs
    'walks': 28, 'swims': 29, 'sits': 30, 'plays': 31,
    # Adverbs
    'gently': 32, 'loudly': 33,
    # Adjectives
    'tall': 34, 'dark': 35, 'young': 36,
    # Prepositions
    'above': 37, 'behind': 38,
    # Conjunction
    'and': 39,
}

VOCAB_REVERSE = {v: k for k, v in VOCABULARY.items()}

_ARTICLES     = ['the', 'a']
_ANIMALS      = ['cat', 'dog', 'bird', 'fish', 'fox', 'bear']
_VERBS        = ['runs', 'jumps', 'flies', 'sleeps', 'eats', 'walks', 'swims', 'sits', 'plays']
_ADVERBS      = ['quickly', 'slowly', 'gently', 'loudly']
_ADJECTIVES   = ['big', 'small', 'red', 'blue', 'happy', 'tall', 'dark', 'young']
_PREPOSITIONS = ['on', 'in', 'under', 'near', 'with', 'above', 'behind']

CATEGORIES = {
    "article": _ARTICLES,
    "animal": _ANIMALS,
    "verb": _VERBS,
    "adverb": _ADVERBS,
    "adjective": _ADJECTIVES,
    "preposition": _PREPOSITIONS
}

TEMPLATES_LONG = [
    "START {article} {animal} {verb} {adverb} {preposition} {article} {adjective} {animal} END",
    "START {article} {animal} {verb} and {article} {adjective} {animal} {verb} END",
    "START {article} {adjective} {animal} {verb} {adverb} {preposition} {article} {animal} END"
]

TEMPLATES_SHORT = [
    "START {article} {animal} {verb} {adverb} END PAD PAD",
    "START {article} {adjective} {animal} {verb} {adverb} END PAD",
    "START {article} {animal} {verb} and {verb} {adverb} END",
]
def _placeholders(template: str) -> list[str]:
    """Unique placeholder names in order of first appearance."""
    seen, order = set(), []
    for name in re.findall(r"{(\w+)}", template):
        if name not in seen:
            seen.add(name)
            order.append(name)
    return order

def _category_for(placeholder: str) -> list[str]:
    """Strip a trailing digit so animal2 -> animal."""
    base = re.sub(r"\d+$", "", placeholder)
    if base not in CATEGORIES:
        raise KeyError(f"Unknown category '{base}' in placeholder '{placeholder}'")
    return CATEGORIES[base]

def windows_of(tokens: list[str], window_size: int) -> list[list[str]]:
    """Every contiguous window_size-token slice. Shorter sequences pass through."""
    if len(tokens) <= window_size:
        return [tokens]
    return [tokens[i:i + window_size]
            for i in range(len(tokens) - window_size + 1)]

def generate_from_template(template: str, window_size: int = 8) -> list[str]:
    """Cartesian product over placeholders, then enumerate every window of each
    filled sentence. Sentences <= window_size yield one entry (themselves);
    longer sentences yield (len - window_size + 1) entries."""
    names = _placeholders(template)
    pools = [_category_for(n) for n in names]
    out = []
    for combo in itertools.product(*pools):
        tokens = template.format(**dict(zip(names, combo))).split()
        for window in windows_of(tokens, window_size):
            out.append(" ".join(window))
    return out

def generate_sentences(seed: int = 0, max_samples: int | None = None, templates = TEMPLATES_LONG) -> list[str]:
    sentences = []
    for tmpl in templates:
        sentences.extend(generate_from_template(tmpl))
    rng = np.random.default_rng(seed)
    rng.shuffle(sentences)
    if max_samples is not None:
        sentences = sentences[:max_samples]
    return sentences

TRAINING_SENTENCES = generate_sentences(max_samples=500, templates=TEMPLATES_SHORT)

# --- Data Helpers ---
def tokenize_sentence(sentence: str) -> List[int]:
    return [VOCABULARY[t] for t in sentence.split() if t in VOCABULARY]

def pad_sequence(tokens: List[int], max_len: int) -> List[int]:
    return (tokens + [0] * max_len)[:max_len]

# --- Model ---
class MultiHeadAttention(nn.Module):
    def __init__(self, embed_dim: int, num_heads: int):
        super().__init__()
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
            attention_weights = torch.nan_to_num(torch.softmax(scores, dim=-1), 0.0)
            head_outputs.append(torch.matmul(attention_weights, V))
        return self.output_projection(torch.cat(head_outputs, dim=-1))

class DecoderTransformer(nn.Module):
    def __init__(self, config):
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

# --- Weight Export Helpers ---
def quantize_weight(weight: torch.Tensor, data_width: int) -> np.ndarray:
    max_val, min_val = 2**(data_width-1) - 1, -2**(data_width-1)
    weight_np = weight.detach().cpu().numpy()
    max_abs = np.maximum(np.abs(weight_np.min()), np.abs(weight_np.max()))
    scale = 256 #(max_val * 0.8) / max_abs if max_abs > 0 else 1.0
    return np.clip(np.round(weight_np * scale), min_val, max_val).astype(np.int16)

def save_memory_file(data: np.ndarray, filename: str, data_width: int):
    with open(filename, 'w') as f:
        for val in data.flatten():
            unsigned_val = int(val) & ((1 << data_width) - 1)
            f.write(f"{unsigned_val:0{data_width//4}x}\n")

# --- Evaluation Helpers ---
def evaluate(model: DecoderTransformer, sentences: List[str]) -> dict:
    """Returns loss, perplexity, and token accuracy on a list of sentences."""
    config = model.config
    criterion = nn.CrossEntropyLoss(ignore_index=0, reduction='sum')

    tokenized = [pad_sequence(tokenize_sentence(s), config.SEQ_LEN) for s in sentences]
    inputs  = torch.tensor([s[:-1] for s in tokenized], dtype=torch.long)
    targets = torch.tensor([s[1:]  for s in tokenized], dtype=torch.long)

    model.eval()
    with torch.no_grad():
        logits = model(inputs)
        loss = criterion(logits.view(-1, config.VOCAB_SIZE), targets.view(-1))
        mask = targets.view(-1) != 0
        n_tokens = mask.sum().item()
        avg_loss = loss.item() / n_tokens
        preds = logits.argmax(dim=-1).view(-1)
        accuracy = (preds[mask] == targets.view(-1)[mask]).float().mean().item()

    return {
        "loss": avg_loss,
        "perplexity": math.exp(avg_loss),
        "accuracy": accuracy,
    }

def probe_logits(model: DecoderTransformer, sentence: str) -> np.ndarray:
    """Returns the logits at the last token position of the given sentence."""
    config = model.config
    tokens = tokenize_sentence(sentence)
    padded = pad_sequence(tokens, config.SEQ_LEN - 1)
    input_tensor = torch.tensor([padded], dtype=torch.long)
    model.eval()
    with torch.no_grad():
        logits = model(input_tensor)
    return logits[0, len(tokens) - 1, :].cpu().numpy()
