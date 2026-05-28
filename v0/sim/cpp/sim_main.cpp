// =============================================================================
// sim_main.cpp -- Verilator harness for complete_transformer_decoder.
//
// Usage (run from FPGA-Transformer-Acceleration/ so memory/ paths resolve):
//   v0/obj_dir/Vcomplete_transformer_decoder [tok0 tok1 ... tokN]
//
// Up to SEQ_LEN tokens may be given as positional args; missing slots are
// padded with 0 (PAD). With no args, falls back to the legacy demo input.
//
// Output:
//   Verbose progress goes to stderr (state transitions, cycle counts).
//   Stdout always ends with one machine-parseable line:
//     RESULT predicted_token=<int> cycles=<int>
// =============================================================================

#include "Vcomplete_transformer_decoder.h"
#include "Vcomplete_transformer_decoder___024root.h"
#include "verilated.h"

#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>

static constexpr int SEQ_LEN        = 8;
static constexpr int TOK_BITS       = 6;          // per-slot bit width
static constexpr int VOCAB_SIZE     = 40;         // matches model.py Config
static constexpr int CLK_HALF       = 5;          // 5ns half-period -> 100MHz
static constexpr int MAX_CYCLES     = 20000000;
static constexpr int PRINT_INTERVAL = 500000;

static const char* STATE_NAMES[] = {
    "IDLE", "EMBEDDING", "POSITIONAL", "ATTENTION",
    "LAYER_NORM1", "FEED_FORWARD", "LAYER_NORM2",
    "OUTPUT_PROJ", "ARGMAX", "FINISHED"
};

static vluint64_t sim_time = 0;

static void tick(Vcomplete_transformer_decoder* dut) {
    dut->clk = 0; dut->eval(); sim_time += CLK_HALF;
    dut->clk = 1; dut->eval(); sim_time += CLK_HALF;
}

// Pack up to SEQ_LEN tokens into the 48-bit input_sequence_flat layout
// the decoder expects: slot i occupies bits [i*6+5 : i*6].
static uint64_t pack_input(const int* tokens, int count) {
    uint64_t flat = 0;
    for (int i = 0; i < SEQ_LEN; ++i) {
        uint64_t tok = (i < count) ? (uint64_t)tokens[i] : 0;
        flat |= (tok & ((1ULL << TOK_BITS) - 1)) << (i * TOK_BITS);
    }
    return flat;
}

int main(int argc, char** argv) {
    // Unbuffer stderr so progress / error messages aren't lost on crash.
    setvbuf(stderr, nullptr, _IONBF, 0);
    Verilated::commandArgs(argc, argv);

    // Parse positional tokens. argv[0] is the binary; argv[1..] are tokens.
    int  tokens[SEQ_LEN] = {0};
    int  token_count     = 0;
    if (argc > 1) {
        token_count = argc - 1;
        if (token_count > SEQ_LEN) {
            fprintf(stderr, "ERROR: got %d tokens, max is %d\n",
                    token_count, SEQ_LEN);
            return 2;
        }
        for (int i = 0; i < token_count; ++i) {
            tokens[i] = atoi(argv[i + 1]);
            if (tokens[i] < 0 || tokens[i] >= VOCAB_SIZE) {
                fprintf(stderr, "ERROR: token %d (arg %d) out of range [0, %d)\n",
                        tokens[i], i + 1, VOCAB_SIZE);
                return 2;
            }
        }
    } else {
        // Legacy demo input: "<START> the cat"
        tokens[0] = 1; tokens[1] = 3; tokens[2] = 5;
        token_count = 3;
    }

    uint64_t flat = pack_input(tokens, token_count);
    fprintf(stderr, "input tokens (count=%d): ", token_count);
    for (int i = 0; i < token_count; ++i) fprintf(stderr, "%d ", tokens[i]);
    fprintf(stderr, "\ninput_sequence_flat = 0x%012llx\n",
            (unsigned long long)flat);

    Vcomplete_transformer_decoder* dut = new Vcomplete_transformer_decoder;

    // Drive inputs through reset.
    dut->rst   = 1;
    dut->start = 0;
    dut->input_sequence_flat = flat;
    for (int i = 0; i < 5; ++i) tick(dut);
    dut->rst = 0;
    tick(dut); tick(dut);

    // One-cycle start pulse.
    dut->start = 1; tick(dut);
    dut->start = 0;

    int cycles = 0;
    int last_state = -1;
    while (!(dut->done && dut->valid)) {
        tick(dut);
        ++cycles;

        int state = dut->current_state_debug;
        if (state != last_state) {
            fprintf(stderr, "[%8d cycles] entering state %d (%s)\n",
                    cycles, state, state < 10 ? STATE_NAMES[state] : "?");
            last_state = state;
        }
        if (cycles % PRINT_INTERVAL == 0) {
            fprintf(stderr, "[%8d cycles] still in state %d (%s)...\n",
                    cycles, state, state < 10 ? STATE_NAMES[state] : "?");
        }
        if (cycles > MAX_CYCLES) {
            fprintf(stderr, "TIMEOUT after %d cycles -- stuck in state %d (%s)\n",
                    MAX_CYCLES, state, state < 10 ? STATE_NAMES[state] : "?");
            printf("RESULT predicted_token=-1 cycles=%d\n", cycles);
            delete dut;
            return 1;
        }
    }

    int predicted = (int)dut->predicted_token;
    fprintf(stderr, "Done after %d cycles. Predicted token: %d\n",
            cycles, predicted);

    // Optional logits dump (kept from the original harness; harmless if data/
    // doesn't exist).
    FILE* f = fopen("data/hardware_logits.txt", "w");
    if (f) {
        for (int i = 0; i < VOCAB_SIZE; ++i) {
            int16_t logit = (int16_t)dut->rootp
                ->complete_transformer_decoder__DOT__final_logits[i];
            fprintf(f, "%d\n", (int)logit);
        }
        fclose(f);
        fprintf(stderr, "Wrote data/hardware_logits.txt\n");
    }

    // The one line interface.py parses:
    printf("RESULT predicted_token=%d cycles=%d\n", predicted, cycles);

    delete dut;
    return 0;
}
