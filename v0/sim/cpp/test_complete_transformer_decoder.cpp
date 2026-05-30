// =============================================================================
// test_complete_transformer_decoder.cpp -- End-to-end harness with full
// intermediate dumps.
//
// stdin:  SEQ_LEN int16 token ids (only bottom 6 bits used)
// stdout: int16s in this order:
//           embedded_tokens   [SEQ_LEN][EMBED_DIM]
//           position_encoded  [SEQ_LEN][EMBED_DIM]
//           attention_out     [SEQ_LEN][EMBED_DIM]
//           norm1_out         [SEQ_LEN][EMBED_DIM]
//           ffn_out           [SEQ_LEN][EMBED_DIM]
//           norm2_out         [SEQ_LEN][EMBED_DIM]
//           final_logits      [VOCAB_SIZE]
//           predicted_token   [1]
// =============================================================================
#include "Vcomplete_transformer_decoder.h"
#include "Vcomplete_transformer_decoder___024root.h"
#include "common.h"

static constexpr int SEQ_LEN    = 8;
static constexpr int EMBED_DIM  = 16;
static constexpr int VOCAB_SIZE = 40;

int main(int argc, char** argv) {
    setvbuf(stderr, nullptr, _IONBF, 0);
    Verilated::commandArgs(argc, argv);
    auto* dut = new Vcomplete_transformer_decoder;

    int16_t tokens[SEQ_LEN];
    if (!sim::read_int16s(tokens, SEQ_LEN)) return 2;

    // Pack into input_sequence_flat: slot i at bits [i*6+5 : i*6].
    uint64_t flat = 0;
    for (int i = 0; i < SEQ_LEN; ++i) {
        flat |= ((uint64_t)(tokens[i] & 0x3F)) << (i * 6);
    }
    dut->input_sequence_flat = flat;

    // Run the entire pipeline -- ~125k cycles for the small model.
    if (sim::run_to_done(dut, 10000000) < 0) return 1;

    auto* r = dut->rootp;

    // Helpers to dump 2D and 1D regs.
    auto dump_2d = [&](auto&& arr, int rows, int cols) {
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                printf("%d\n", (int16_t)arr[i][j]);
    };
    auto dump_1d = [&](auto&& arr, int n) {
        for (int i = 0; i < n; ++i) printf("%d\n", (int16_t)arr[i]);
    };

    dump_2d(r->complete_transformer_decoder__DOT__embedded_tokens,   SEQ_LEN, EMBED_DIM);
    dump_2d(r->complete_transformer_decoder__DOT__position_encoded,  SEQ_LEN, EMBED_DIM);
    dump_2d(r->complete_transformer_decoder__DOT__attention_out,     SEQ_LEN, EMBED_DIM);
    dump_2d(r->complete_transformer_decoder__DOT__norm1_out,         SEQ_LEN, EMBED_DIM);
    dump_2d(r->complete_transformer_decoder__DOT__ffn_out,           SEQ_LEN, EMBED_DIM);
    dump_2d(r->complete_transformer_decoder__DOT__norm2_out,         SEQ_LEN, EMBED_DIM);
    dump_1d(r->complete_transformer_decoder__DOT__final_logits,      VOCAB_SIZE);

    printf("%d\n", (int)dut->predicted_token);

    delete dut;
    return 0;
}
