"""
interface.py

Single-prompt generation harness that works with either the PyTorch model
or the PYNQ hardware overlay behind a common `Backend` API.

Usage:
    python interface.py --backend torch --prompt "the cat"
    python interface.py --backend hw    --prompt "the cat"   # only on PYNQ board

Both backends implement:
    predict_next(context: list[int]) -> int
        Given the current token sequence (1..SEQ_LEN tokens), return the
        single most likely next token id. Padding / last-position logic is
        the backend's problem.
"""

from __future__ import annotations

import argparse
import os
import re
import subprocess
import sys
from typing import Protocol

import torch

from model import (
    VOCABULARY, VOCAB_REVERSE,
    Config, DecoderTransformer,
    tokenize_sentence,
)


MODELS_DIR = "models"
DEFAULT_MODEL_PATH = os.path.join(MODELS_DIR, "decoder_model.pth")
DEFAULT_SIM_BINARY = os.path.join("v0", "obj_dir", "Vcomplete_transformer_decoder")
REPO_ROOT          = os.path.dirname(os.path.abspath(__file__))
START_TOKEN = VOCABULARY["START"]
END_TOKEN   = VOCABULARY["END"]
PAD_TOKEN   = VOCABULARY["PAD"]


# ---------------------------------------------------------------------------
# Backend protocol -- a backend is anything with predict_next(context) -> int.
# ---------------------------------------------------------------------------

class Backend(Protocol):
    name: str
    def predict_next(self, context: list[int]) -> int: ...


# ---------------------------------------------------------------------------
# PyTorch backend
# ---------------------------------------------------------------------------

class TorchBackend:
    """Runs inference through the float PyTorch reference model."""

    name = "torch"

    def __init__(self, model: DecoderTransformer):
        self.model = model
        self.model.eval()
        self.seq_len   = model.config.SEQ_LEN
        self.vocab_size = model.config.VOCAB_SIZE

    def predict_next(self, context: list[int]) -> int:
        if not 1 <= len(context) <= self.seq_len:
            raise ValueError(
                f"context length {len(context)} not in [1, {self.seq_len}]"
            )
        # Pad with PAD tokens to match the hardware, which always sees a
        # SEQ_LEN-wide input and argmaxes at the last non-pad position.
        padded = context + [PAD_TOKEN] * (self.seq_len - len(context))
        last_pos = len(context) - 1

        x = torch.tensor([padded], dtype=torch.long)
        with torch.no_grad():
            logits = self.model(x)        # [1, SEQ_LEN, VOCAB_SIZE]
        return int(logits[0, last_pos].argmax().item())


# ---------------------------------------------------------------------------
# Hardware backend (only importable on the PYNQ board)
# ---------------------------------------------------------------------------

class VerilatorBackend:
    """
    Drives the Verilator simulation of `complete_transformer_decoder`.
    Each predict_next() call is a fresh subprocess invocation -- the sim has
    no persistent state across calls, just like the real hardware on a
    soft-reset boundary.

    The sim's $readmemh paths are relative to the FPGA-Transformer-Acceleration
    root (they expect to find memory/*.mem there), so we always invoke the
    binary with cwd=REPO_ROOT.

    Build prerequisite (from FPGA-Transformer-Acceleration/v0):
        make verilate
    """

    name = "verilator"

    # The sim prints exactly one line of the form:
    #   RESULT predicted_token=<int> cycles=<int>
    _RESULT_RE = re.compile(
        r"^RESULT\s+predicted_token=(-?\d+)\s+cycles=(\d+)\s*$",
        re.MULTILINE,
    )

    def __init__(self, binary: str = DEFAULT_SIM_BINARY,
                 cwd: str = REPO_ROOT, timeout_s: float = 120.0):
        # Resolve binary relative to cwd if it's not absolute.
        if not os.path.isabs(binary):
            binary = os.path.join(cwd, binary)
        # Verilator emits "<name>.exe" on Windows and bare "<name>" elsewhere.
        # Accept whichever exists so the same default path works on both.
        if not os.path.exists(binary) and os.path.exists(binary + ".exe"):
            binary = binary + ".exe"
        if not os.path.exists(binary):
            raise FileNotFoundError(
                f"Verilator sim binary not found at {binary}.\n"
                f"Build it first:\n"
                f"  Mac/Linux: cd {os.path.join(cwd, 'v0')} && make verilate\n"
                f"  Windows:   cd {os.path.join(cwd, 'v0')}; .\\build_sim.ps1"
            )
        self._binary    = binary
        self._cwd       = cwd
        self._timeout_s = timeout_s

    def predict_next(self, context: list[int]) -> int:
        cmd = [self._binary] + [str(t) for t in context]
        try:
            proc = subprocess.run(
                cmd,
                cwd=self._cwd,
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE,
                timeout=self._timeout_s,
                text=True,
                check=False,
            )
        except subprocess.TimeoutExpired as e:
            raise RuntimeError(
                f"Verilator sim timed out after {self._timeout_s}s for "
                f"context {context}"
            ) from e

        if proc.returncode != 0:
            # Negative returncode on POSIX means killed by signal -N.
            sig_note = ""
            if proc.returncode < 0:
                sig_note = f" (killed by signal {-proc.returncode})"
            raise RuntimeError(
                f"Verilator sim exited with code {proc.returncode}{sig_note} "
                f"for context {context}.\n"
                f"--- stdout tail ---\n"
                + "\n".join(proc.stdout.splitlines()[-20:])
                + "\n--- stderr tail ---\n"
                + "\n".join(proc.stderr.splitlines()[-20:])
            )

        m = self._RESULT_RE.search(proc.stdout)
        if not m:
            raise RuntimeError(
                f"Could not find RESULT line in sim stdout. Got:\n{proc.stdout}"
            )
        token = int(m.group(1))
        if token < 0:
            raise RuntimeError(
                f"Sim reported error result (token={token}). stderr tail:\n"
                + "\n".join(proc.stderr.splitlines()[-20:])
            )
        return token


class HardwareBackend:
    """Drives the transformer_axi_wrap_0 IP via PYNQ."""

    name = "hw"

    def __init__(self, bitfile: str = "transformer.bit",
                 ip_name: str = "transformer_axi_wrap_0"):
        # Lazy import so this module is usable on a dev box without pynq.
        try:
            from transformer_driver import Transformer  # type: ignore
        except ImportError as e:
            raise RuntimeError(
                "HardwareBackend requires transformer_driver.py (and pynq) "
                "to be importable. Run this on the PYNQ-Z1, with "
                "transformer_driver.py alongside the bit/hwh files."
            ) from e
        self._driver = Transformer(bitfile=bitfile, ip_name=ip_name)

    def predict_next(self, context: list[int]) -> int:
        return int(self._driver.infer(context)["predicted_token"])


# ---------------------------------------------------------------------------
# Generation loop (backend-agnostic)
# ---------------------------------------------------------------------------

def generate(backend: Backend, prompt_tokens: list[int],
             max_tokens: int) -> list[int]:
    """Autoregressively extend prompt_tokens until END or max tokens."""
    context = list(prompt_tokens)

    while len(context) < max_tokens:
        next_tok = backend.predict_next(context[-min(len(context), 8):])
        context.append(next_tok)
        if next_tok == END_TOKEN:
            break
    return context


def tokens_to_words(tokens: list[int]) -> str:
    return " ".join(VOCAB_REVERSE[t] for t in tokens)


# ---------------------------------------------------------------------------
# CLI
# ---------------------------------------------------------------------------

def build_torch_backend(model_path: str) -> TorchBackend:
    if not os.path.exists(model_path):
        sys.exit(f"No model found at {model_path}. Run train.py first.")
    model = DecoderTransformer(Config)
    model.load_state_dict(torch.load(model_path, weights_only=True))
    print(f"--- Loaded PyTorch model from {model_path} ---")
    return TorchBackend(model)


def build_hw_backend(bitfile: str) -> HardwareBackend:
    print(f"--- Loading hardware overlay {bitfile} ---")
    return HardwareBackend(bitfile=bitfile)


def build_verilator_backend(binary: str) -> VerilatorBackend:
    print(f"--- Using Verilator sim {binary} ---")
    return VerilatorBackend(binary=binary)


def parse_prompt(prompt: str) -> list[int]:
    """Tokenize a prompt string. Defaults to [START] if empty."""
    if not prompt.strip():
        return [START_TOKEN]
    toks = tokenize_sentence(prompt)
    # tokenize_sentence may or may not prepend START -- depends on model.py.
    # Make sure we start with START so the model sees a valid prefix.
    if toks[0] != START_TOKEN:
        toks = [START_TOKEN] + toks
    return toks


def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--backend", choices=["torch", "verilator", "hw"],
                    default="torch", help="Which inference backend to use.")
    ap.add_argument("--prompt", default="",
                    help='Prompt words (e.g. "the cat"). Defaults to just <START>.')
    ap.add_argument("--max-tokens", type=int, default=100,
                    help=f"Stop after this many tokens (default: {100}).")
    ap.add_argument("--model-path", default=DEFAULT_MODEL_PATH,
                    help="Torch backend: path to decoder_model.pth.")
    ap.add_argument("--bitfile", default="transformer.bit",
                    help="Hardware backend: path to the .bit (needs matching .hwh).")
    ap.add_argument("--sim-binary", default=DEFAULT_SIM_BINARY,
                    help="Verilator backend: path to the compiled sim binary "
                         "(default: v0/obj_dir/Vcomplete_transformer_decoder).")
    args = ap.parse_args()

    if args.backend == "torch":
        backend: Backend = build_torch_backend(args.model_path)
    elif args.backend == "verilator":
        backend = build_verilator_backend(args.sim_binary)
    else:
        backend = build_hw_backend(args.bitfile)

    prompt_tokens = parse_prompt(args.prompt)
    print(f"prompt tokens: {prompt_tokens}  ({tokens_to_words(prompt_tokens)!r})")

    out_tokens = generate(backend, prompt_tokens, args.max_tokens)
    print(f"output tokens: {out_tokens}")
    print(f"output text  : {tokens_to_words(out_tokens)!r}")


if __name__ == "__main__":
    main()
