// =============================================================================
// test_token_embedding.cpp -- Harness for token_embedding.
//
// stdin:  SEQ_LEN int16 -- token ids (only bottom 6 bits are used by the DUT)
// stdout: SEQ_LEN * EMBED_DIM int16 -- embedded_output
// =============================================================================
#include "Vtoken_embedding.h"
#include "Vtoken_embedding___024root.h"
#include "common.h"

static constexpr int SEQ_LEN   = 8;
static constexpr int EMBED_DIM = 16;

int main(int argc, char** argv) {
    setvbuf(stderr, nullptr, _IONBF, 0);
    Verilated::commandArgs(argc, argv);
    auto* dut = new Vtoken_embedding;

    int16_t tokens[SEQ_LEN];
    if (!sim::read_int16s(tokens, SEQ_LEN)) return 2;
    for (int s = 0; s < SEQ_LEN; ++s)
        dut->input_tokens[s] = (uint8_t)(tokens[s] & 0x3F);  // 6 bits

    if (sim::run_to_done(dut) < 0) return 1;

    int16_t out[SEQ_LEN * EMBED_DIM];
    for (int s = 0; s < SEQ_LEN; ++s)
        for (int d = 0; d < EMBED_DIM; ++d)
            out[s * EMBED_DIM + d] = (int16_t)dut->embedded_output[s][d];
    sim::write_int16s(out, SEQ_LEN * EMBED_DIM);

    delete dut;
    return 0;
}
