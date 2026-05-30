// =============================================================================
// test_attention_head.cpp -- Harness for attention_head (single head).
//
// stdin:  SEQ_LEN * EMBED_DIM int16 -- input_data, row-major
// stdout: SEQ_LEN * HEAD_DIM  int16 -- output_data, row-major
//
// NOTE: The attention_head defaults its WQ_FILE / WK_FILE / WV_FILE params to
// head 0. So this test exercises head 0 with whatever inputs you provide.
// =============================================================================
#include "Vattention_head.h"
#include "Vattention_head___024root.h"
#include "common.h"

static constexpr int SEQ_LEN   = 8;
static constexpr int EMBED_DIM = 16;
static constexpr int NUM_HEADS = 4;
static constexpr int HEAD_DIM  = EMBED_DIM / NUM_HEADS;   // 4

int main(int argc, char** argv) {
    setvbuf(stderr, nullptr, _IONBF, 0);
    Verilated::commandArgs(argc, argv);
    auto* dut = new Vattention_head;

    int16_t in_buf[SEQ_LEN * EMBED_DIM];
    if (!sim::read_int16s(in_buf, SEQ_LEN * EMBED_DIM)) return 2;
    for (int s = 0; s < SEQ_LEN; ++s)
        for (int d = 0; d < EMBED_DIM; ++d)
            dut->input_data[s][d] = in_buf[s * EMBED_DIM + d];

    if (sim::run_to_done(dut) < 0) return 1;

    int16_t out_buf[SEQ_LEN * HEAD_DIM];
    for (int s = 0; s < SEQ_LEN; ++s)
        for (int h = 0; h < HEAD_DIM; ++h)
            out_buf[s * HEAD_DIM + h] = (int16_t)dut->output_data[s][h];
    sim::write_int16s(out_buf, SEQ_LEN * HEAD_DIM);

    delete dut;
    return 0;
}
