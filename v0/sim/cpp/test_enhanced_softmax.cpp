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

    if (sim::run_to_done_with(dut, [&]() { return dut->done; },
                            2000000) < 0) return 1;

    // Internal-signal dump from the final sample (helpful when debugging).
    auto* r = dut->rootp;
    fprintf(stderr, "--- internal signals at completion ---\n");
    fprintf(stderr, "exp_lookup   = %d\n", (int)r->enhanced_softmax__DOT__exp_lookup);
    fprintf(stderr, "exp_index    = %d\n", (int)r->enhanced_softmax__DOT__exp_index);
    //fprintf(stderr, "temp_exp[i]  = %d\n", (int)r->enhanced_softmax__DOT__temp_exp);
    fprintf(stderr, "exp_sum      = %d\n", (int)r->enhanced_softmax__DOT__exp_sum);
    // fprintf(stderr, "normalized   = %d\n", (int)r->enhanced_softmax__DOT__exp_lookup);

    int16_t out[SEQ_LEN * SEQ_LEN];
    for (int i = 0; i < SEQ_LEN; ++i)
        for (int j = 0; j < SEQ_LEN; ++j)
            out[i * SEQ_LEN + j] = (int16_t)dut->output_weights[i][j];
    sim::write_int16s(out, SEQ_LEN * SEQ_LEN);

    delete dut;
    return 0;
}