#include "Vcomplete_transformer_decoder.h"
#include "Vcomplete_transformer_decoder___024root.h"
#include "verilated.h"
#include <cstdio>
#include <cstdint>

// Matches $readmemh paths — run the sim from Hardware_PC/ where the .mem files live
static const int CLK_HALF = 5;        // 5ns half-period → 100MHz
static const int MAX_CYCLES = 20000000; // 20M cycles — transformer is slow sequentially
static const int PRINT_INTERVAL = 500000;

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

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    Vcomplete_transformer_decoder* dut = new Vcomplete_transformer_decoder;

    // Reset
    dut->rst = 1; dut->start = 0;
    dut->input_sequence[0] = 1; // START
    dut->input_sequence[1] = 3; // the
    dut->input_sequence[2] = 5; // cat
    dut->input_sequence[3] = 0; dut->input_sequence[4] = 0;
    dut->input_sequence[5] = 0; dut->input_sequence[6] = 0;
    dut->input_sequence[7] = 0;

    for (int i = 0; i < 5; i++) tick(dut);
    dut->rst = 0;
    tick(dut); tick(dut);

    // Assert start for one cycle
    dut->start = 1; tick(dut);
    dut->start = 0;

    // Run until done & valid, or timeout
    int cycles = 0;
    int last_state = -1;
    while (!(dut->done && dut->valid)) {
        tick(dut);
        ++cycles;

        int state = dut->current_state_debug;
        if (state != last_state) {
            printf("[%8d cycles] entering state %d (%s)\n",
                   cycles, state, state < 10 ? STATE_NAMES[state] : "?");
            last_state = state;
        }

        if (cycles % PRINT_INTERVAL == 0) {
            printf("[%8d cycles] still in state %d (%s)...\n",
                   cycles, state, state < 10 ? STATE_NAMES[state] : "?");
        }

        if (cycles > MAX_CYCLES) {
            printf("TIMEOUT after %d cycles — stuck in state %d (%s)\n",
                   MAX_CYCLES, state, state < 10 ? STATE_NAMES[state] : "?");
            delete dut;
            return 1;
        }
    }

    printf("Done after %d cycles\n", cycles);
    printf("Predicted token: %d\n", (int)dut->predicted_token);

    // Dump logits for comparison with data/golden_logits.txt
    // Requires --public-flat-rw so Verilator exposes internal signals
    FILE* f = fopen("data/hardware_logits.txt", "w");
    if (f) {
        for (int i = 0; i < 40; i++) {
            int16_t logit = (int16_t)dut->rootp->complete_transformer_decoder__DOT__final_logits[i];
            fprintf(f, "%d\n", (int)logit);
        }
        fclose(f);
        printf("Wrote data/hardware_logits.txt\n");
    } else {
        printf("Warning: could not write data/hardware_logits.txt (does data/ exist?)\n");
    }

    delete dut;
    return 0;
}
