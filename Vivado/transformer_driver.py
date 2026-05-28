"""
transformer_driver.py

PYNQ driver for the transformer_axi_wrap_0 IP. Run on the PYNQ-Z1 with the
matching transformer.bit / transformer.hwh in the same directory.

Register map (matches Vivado/transformer_axi_wrapper.v):

    Offset  Dir  Field
    0x00    W    bit 0 = start (self-clearing 1-cycle pulse)
                 bit 1 = soft_rst
    0x00    R    bit 0 = done, bit 1 = valid
    0x04    R    bit 0   = done
                 bit 1   = valid
                 bits[6:2]  = predicted_token  (width = $clog2(VOCAB_SIZE) = 5 for VOCAB_SIZE=25)
                 bits[10:7] = current_state_debug (4 bits)
    0x08    R    cycle_count[31:0]
    0x0C..  W/R  input_sequence[i], bits[4:0]   (i = 0..SEQ_LEN-1)
    0x28
"""

from pynq import Overlay
import time
import os

# These must match the parameters used at synthesis time.
SEQ_LEN    = 8
VOCAB_SIZE = 25
TOK_BITS   = (VOCAB_SIZE - 1).bit_length()   # = 5 for VOCAB_SIZE=25

# Register offsets
REG_CONTROL_STATUS_BASIC = 0x00
REG_STATUS_FULL          = 0x04
REG_CYCLE_COUNT          = 0x08
REG_INPUT_SEQ_BASE       = 0x0C

# Control bits
CTRL_START    = 1 << 0
CTRL_SOFTRST  = 1 << 1


class Transformer:
    def __init__(self, bitfile="transformer.bit", ip_name="transformer_axi_wrap_0"):
        bit_path = os.path.abspath(bitfile)
        self.overlay = Overlay(bit_path)
        # The IP name comes from the BD instance name. Adjust if you renamed it.
        self.ip = getattr(self.overlay, ip_name)

    # ---- low-level register helpers ----
    def _w(self, off, val):
        self.ip.write(off, val & 0xFFFFFFFF)

    def _r(self, off):
        return self.ip.read(off) & 0xFFFFFFFF

    # ---- control / status ----
    def soft_reset(self):
        """Pulse the soft reset; clears done/valid and FSM state."""
        self._w(REG_CONTROL_STATUS_BASIC, CTRL_SOFTRST)
        # The wrapper self-clears soft_rst every cycle, so a single write is enough.

    def is_done(self):
        return bool(self._r(REG_CONTROL_STATUS_BASIC) & 0x1)

    def is_valid(self):
        return bool(self._r(REG_CONTROL_STATUS_BASIC) & 0x2)

    def read_status(self):
        """Return (done, valid, predicted_token, state_debug) from 0x04."""
        s = self._r(REG_STATUS_FULL)
        done           = s & 0x1
        valid          = (s >> 1) & 0x1
        predicted_tok  = (s >> 2) & ((1 << TOK_BITS) - 1)
        state_debug    = (s >> (2 + TOK_BITS)) & 0xF
        return done, valid, predicted_tok, state_debug

    def cycle_count(self):
        return self._r(REG_CYCLE_COUNT)

    # ---- inference ----
    def load_sequence(self, tokens):
        """Write up to SEQ_LEN tokens; pad remaining slots with 0."""
        if len(tokens) > SEQ_LEN:
            raise ValueError(f"sequence length {len(tokens)} > SEQ_LEN ({SEQ_LEN})")
        for i in range(SEQ_LEN):
            tok = tokens[i] if i < len(tokens) else 0
            if not (0 <= tok < (1 << 5)):  # input slots are 5 bits wide
                raise ValueError(f"token {tok} at pos {i} out of range [0, 31]")
            self._w(REG_INPUT_SEQ_BASE + i * 4, tok)

    def start(self):
        """Pulse the start bit (self-clears in hardware)."""
        self._w(REG_CONTROL_STATUS_BASIC, CTRL_START)

    def wait_done(self, timeout_s=5.0, poll_interval=0.001):
        """Poll until done=1, then return the full status tuple."""
        t0 = time.time()
        while not self.is_done():
            if time.time() - t0 > timeout_s:
                done, valid, tok, st = self.read_status()
                raise TimeoutError(
                    f"timeout after {timeout_s}s: done={done} valid={valid} "
                    f"state_debug={st} cycles={self.cycle_count()}"
                )
            time.sleep(poll_interval)
        return self.read_status()

    def infer(self, tokens, timeout_s=5.0):
        """End-to-end: reset, load, start, wait, return predicted token + cycles."""
        self.soft_reset()
        # Give the FSM a cycle to settle. At 3 MHz one cycle is ~333 ns,
        # so a 1 ms sleep is plenty.
        time.sleep(0.001)
        self.load_sequence(tokens)
        self.start()
        done, valid, predicted, state = self.wait_done(timeout_s=timeout_s)
        return {
            "predicted_token": predicted,
            "valid": bool(valid),
            "state_debug": state,
            "cycles": self.cycle_count(),
        }


if __name__ == "__main__":
    # Smoke test: send a short sequence and print the result.
    t = Transformer()
    # Replace with whatever input tokens make sense for your model.
    example = [1, 4, 7, 2]
    result = t.infer(example)
    print(f"input  : {example}")
    print(f"output : token={result['predicted_token']}  "
          f"valid={result['valid']}  cycles={result['cycles']}  "
          f"state_debug={result['state_debug']}")
