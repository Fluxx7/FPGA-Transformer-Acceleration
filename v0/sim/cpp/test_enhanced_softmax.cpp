#include "Venhanced_softmax.h"
#include "Venhanced_softmax___024root.h"
#include "common.h"

static constexpr int SEQ_LEN = 8;

int main(int argc, char** argv) {
    setvbuf(stderr, nullptr, _IONBF, 0);
    Verilated::commandArgs(argc, argv);
    auto* dut = new Venhanced_softmax;

    int16_t scores[SEQ_LEN * SEQ_LEN];
    if (!sim::read_int16s(scores, SEQ_LEN * SEQ_LEN)) return 2;
    for (int i = 0; i < SEQ_LEN; ++i)
        for (int j = 0; j < SEQ_LEN; ++j)
            dut->input_scores[i][j] = scores[i * SEQ_LEN + j];

    if (sim::run_to_done(dut) < 0) return 1;

    int16_t out[SEQ_LEN * SEQ_LEN];
    for (int i = 0; i < SEQ_LEN; ++i)
        for (int j = 0; j < SEQ_LEN; ++j)
            out[i * SEQ_LEN + j] = (int16_t)dut->output_weights[i][j];
    sim::write_int16s(out, SEQ_LEN * SEQ_LEN);

    delete dut;
    return 0;
}