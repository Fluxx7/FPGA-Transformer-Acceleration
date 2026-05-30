#include "Vlayer_normalization.h"
#include "verilated.h"
#include <cstdio>
#include <cstdint>

static constexpr int SEQ_LEN   = 8;
static constexpr int EMBED_DIM = 16;
static constexpr int CLK_HALF  = 5;

static void tick(Vlayer_normalization* dut) {
    dut->clk = 0; dut->eval();
    dut->clk = 1; dut->eval();
}

int main(int argc, char** argv) {
    setvbuf(stderr, nullptr, _IONBF, 0);
    Verilated::commandArgs(argc, argv);
    auto* dut = new Vlayer_normalization;

    // Read 2SEQ_LENEMBED_DIM int16s from stdin: input_data then residual_data.
    // One value per line as signed decimal.
    int val;
    for (int s = 0; s < SEQ_LEN; ++s){
        for (int d = 0; d < EMBED_DIM; ++d) {
            if (scanf("%d", &val) != 1) { fprintf(stderr, "input read failed\n"); return 2; }
            dut->input_data[s][d] = (int16_t)val;
        }
    }
    for (int s = 0; s < SEQ_LEN; ++s) {
        for (int d = 0; d < EMBED_DIM; ++d) {
            if (scanf("%d", &val) != 1) { fprintf(stderr, "residual read failed\n"); return 2; }
            dut->residual_data[s][d] = (int16_t)val;
        }
    }
    // Reset
    dut->rst = 1; dut->start = 0;
    for (int i = 0; i < 5; ++i) tick(dut);
    dut->rst = 0; tick(dut); tick(dut);
    printf("reset sent\n");
    // Start pulse
    dut->start = 1; tick(dut);
    dut->start = 0;
    printf("start sent\n");
    // Run until done && valid (with a generous timeout)
    int cycles = 0;
    while (!(dut->done && dut->valid)) {
        tick(dut);
        if (++cycles > 10000) {
            fprintf(stderr, "TIMEOUT after %d cycles\n", cycles);
            return 1;
        }
    }
    fprintf(stderr, "done after %d cycles\n", cycles);

    // Dump output_data to stdout, one int16 per line
    for (int s = 0; s < SEQ_LEN; ++s)
        for (int d = 0; d < EMBED_DIM; ++d)
            printf("%d\n", (int16_t)dut->output_data[s][d]);

    delete dut;
    return 0;
}