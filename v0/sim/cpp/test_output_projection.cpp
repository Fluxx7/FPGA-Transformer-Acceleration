// =============================================================================
// test_output_projection.cpp -- Harness for output_projection.
//
// stdin:  EMBED_DIM int16 -- final_hidden_state (one row)
// stdout: VOCAB_SIZE int16 -- vocabulary_logits
// =============================================================================
#include "Voutput_projection.h"
#include "Voutput_projection___024root.h"
#include "common.h"

static constexpr int EMBED_DIM  = 16;
static constexpr int VOCAB_SIZE = 40;

int main(int argc, char** argv) {
    setvbuf(stderr, nullptr, _IONBF, 0);
    Verilated::commandArgs(argc, argv);
    auto* dut = new Voutput_projection;

    int16_t hidden[EMBED_DIM];
    if (!sim::read_int16s(hidden, EMBED_DIM)) return 2;
    for (int d = 0; d < EMBED_DIM; ++d) dut->final_hidden_state[d] = hidden[d];

    if (sim::run_to_done(dut) < 0) return 1;

    int16_t out[VOCAB_SIZE];
    for (int v = 0; v < VOCAB_SIZE; ++v)
        out[v] = (int16_t)dut->vocabulary_logits[v];
    sim::write_int16s(out, VOCAB_SIZE);

    delete dut;
    return 0;
}
