// =============================================================================
// test_layer_normalization.cpp -- Standalone harness for layer_normalization.
//
// stdin (decimal int16s, one per line, in this exact order):
//   SEQ_LEN * EMBED_DIM ints  -- input_data,    row-major
//   SEQ_LEN * EMBED_DIM ints  -- residual_data, row-major
//
// stdout:
//   SEQ_LEN * EMBED_DIM ints  -- output_data,   row-major
//
// stderr:
//   Progress messages and a dump of internal regs from the last sample.
//
// NOTE: SEQ_LEN and EMBED_DIM below must match the verilator -G overrides in
// the Makefile. Default is 16/8 to match the model's current config.
// =============================================================================

#include "Vlayer_normalization.h"
#include "Vlayer_normalization___024root.h"
#include "common.h"

static constexpr int SEQ_LEN   = 8;
static constexpr int EMBED_DIM = 16;
static constexpr int N         = SEQ_LEN * EMBED_DIM;

int main(int argc, char** argv) {
    setvbuf(stderr, nullptr, _IONBF, 0);
    Verilated::commandArgs(argc, argv);
    auto* dut = new Vlayer_normalization;

    int16_t in_buf[N], res_buf[N];
    if (!sim::read_int16s(in_buf,  N)) return 2;
    if (!sim::read_int16s(res_buf, N)) return 2;

    for (int s = 0; s < SEQ_LEN; ++s) {
        for (int d = 0; d < EMBED_DIM; ++d) {
            dut->input_data[s][d]    = in_buf [s * EMBED_DIM + d];
            dut->residual_data[s][d] = res_buf[s * EMBED_DIM + d];
        }
    }

    if (sim::run_to_done(dut) < 0) return 1;

    // Internal-signal dump from the final sample (helpful when debugging).
    auto* r = dut->rootp;
    fprintf(stderr, "--- internal signals at completion ---\n");
    fprintf(stderr, "var_lookup   = %d\n", (int)r->layer_normalization__DOT__var_lookup);
    fprintf(stderr, "k            = %d\n", (int)r->layer_normalization__DOT__k);
    fprintf(stderr, "rsqrt_index  = %d\n", (int)r->layer_normalization__DOT__rsqrt_index);
    fprintf(stderr, "rsqrt_var    = %d\n", (int)r->layer_normalization__DOT__rsqrt_var);
    fprintf(stderr, "normalized   = %d\n", (int)r->layer_normalization__DOT__normalized);

    int16_t out_buf[N];
    for (int s = 0; s < SEQ_LEN; ++s)
        for (int d = 0; d < EMBED_DIM; ++d)
            out_buf[s * EMBED_DIM + d] = (int16_t)dut->output_data[s][d];
    sim::write_int16s(out_buf, N);

    delete dut;
    return 0;
}
