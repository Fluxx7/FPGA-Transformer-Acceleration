// =============================================================================
// test_attention_head.cpp -- Harness for attention_head with full intermediate
// dumps (Q, K, V, scores, weights, output).
//
// stdin:  SEQ_LEN * EMBED_DIM int16 -- input_data, row-major
// stdout: int16s in this order:
//           Q                [SEQ_LEN][HEAD_DIM]
//           K                [SEQ_LEN][HEAD_DIM]
//           V                [SEQ_LEN][HEAD_DIM]
//           attention_scores [SEQ_LEN][SEQ_LEN]
//           attention_weights[SEQ_LEN][SEQ_LEN]
//           output_data      [SEQ_LEN][HEAD_DIM]
// =============================================================================
#include "Vattention_head.h"
#include "Vattention_head___024root.h"
#include "common.h"

static constexpr int SEQ_LEN   = 8;
static constexpr int EMBED_DIM = 16;
static constexpr int NUM_HEADS = 4;
static constexpr int HEAD_DIM  = EMBED_DIM / NUM_HEADS;

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

    auto* r = dut->rootp;

    // -- Q [SEQ_LEN][HEAD_DIM]
    for (int s = 0; s < SEQ_LEN; ++s)
        for (int h = 0; h < HEAD_DIM; ++h)
            printf("%d\n", (int16_t)r->attention_head__DOT__Q[s][h]);

    // -- K [SEQ_LEN][HEAD_DIM]
    for (int s = 0; s < SEQ_LEN; ++s)
        for (int h = 0; h < HEAD_DIM; ++h)
            printf("%d\n", (int16_t)r->attention_head__DOT__K[s][h]);

    // -- V [SEQ_LEN][HEAD_DIM]
    for (int s = 0; s < SEQ_LEN; ++s)
        for (int h = 0; h < HEAD_DIM; ++h)
            printf("%d\n", (int16_t)r->attention_head__DOT__V[s][h]);

    // -- attention_scores [SEQ_LEN][SEQ_LEN]
    for (int s1 = 0; s1 < SEQ_LEN; ++s1)
        for (int s2 = 0; s2 < SEQ_LEN; ++s2)
            printf("%d\n",
                   (int16_t)r->attention_head__DOT__attention_scores[s1][s2]);

    // -- attention_weights [SEQ_LEN][SEQ_LEN]
    for (int s1 = 0; s1 < SEQ_LEN; ++s1)
        for (int s2 = 0; s2 < SEQ_LEN; ++s2)
            printf("%d\n",
                   (int16_t)r->attention_head__DOT__attention_weights[s1][s2]);

    // -- output_data [SEQ_LEN][HEAD_DIM]
    for (int s = 0; s < SEQ_LEN; ++s)
        for (int h = 0; h < HEAD_DIM; ++h)
            printf("%d\n", (int16_t)dut->output_data[s][h]);

    delete dut;
    return 0;
}
