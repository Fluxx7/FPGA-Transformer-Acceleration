// =============================================================================
// test_argmax.cpp -- Standalone harness for argmax.
//
// stdin:  VOCAB_SIZE int16 logits
// stdout: 1 int -- predicted token id
// =============================================================================
#include "Vargmax.h"
#include "Vargmax___024root.h"
#include "common.h"

static constexpr int VOCAB_SIZE = 40;

int main(int argc, char** argv) {
    setvbuf(stderr, nullptr, _IONBF, 0);
    Verilated::commandArgs(argc, argv);
    auto* dut = new Vargmax;

    int16_t logits[VOCAB_SIZE];
    if (!sim::read_int16s(logits, VOCAB_SIZE)) return 2;

    for (int v = 0; v < VOCAB_SIZE; ++v) dut->input_logits[v] = logits[v];

    if (sim::run_to_done(dut) < 0) return 1;

    int16_t out = (int16_t)dut->selected_token;
    sim::write_int16s(&out, 1);

    delete dut;
    return 0;
}
