// =============================================================================
// test_positional_encoding.cpp -- Harness for positional_encoding.
//
// stdin:  SEQ_LEN * EMBED_DIM int16 -- embedded_input
// stdout: SEQ_LEN * EMBED_DIM int16 -- position_encoded_output
// =============================================================================
#include "Vpositional_encoding.h"
#include "Vpositional_encoding___024root.h"
#include "common.h"

static constexpr int SEQ_LEN   = 8;
static constexpr int EMBED_DIM = 16;
static constexpr int N         = SEQ_LEN * EMBED_DIM;

int main(int argc, char** argv) {
    setvbuf(stderr, nullptr, _IONBF, 0);
    Verilated::commandArgs(argc, argv);
    auto* dut = new Vpositional_encoding;

    int16_t in_buf[N];
    if (!sim::read_int16s(in_buf, N)) return 2;
    for (int s = 0; s < SEQ_LEN; ++s)
        for (int d = 0; d < EMBED_DIM; ++d)
            dut->embedded_input[s][d] = in_buf[s * EMBED_DIM + d];

    if (sim::run_to_done(dut) < 0) return 1;

    int16_t out_buf[N];
    for (int s = 0; s < SEQ_LEN; ++s)
        for (int d = 0; d < EMBED_DIM; ++d)
            out_buf[s * EMBED_DIM + d] = (int16_t)dut->position_encoded_output[s][d];
    sim::write_int16s(out_buf, N);

    delete dut;
    return 0;
}
