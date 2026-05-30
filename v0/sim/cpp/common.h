// =============================================================================
// common.h -- Shared utilities for module-level Verilator test harnesses.
//
// Convention used by every test_*.cpp harness:
//   stdin   = newline-separated decimal int16s, in row-major order for arrays
//   stdout  = newline-separated decimal int16s of output values
//   stderr  = progress messages, internal-signal dumps, anything not a number
//
// The Python framework filters stderr away from output parsing automatically.
// =============================================================================
#pragma once

#include "verilated.h"
#include <cstdio>
#include <cstdint>

namespace sim {

static constexpr int CLK_HALF = 5;   // 5 ns half-period -> 100 MHz

// Read N int16 values from stdin (one per line, decimal). Returns true on
// success; logs and returns false on parse failure.
inline bool read_int16s(int16_t* out, int n) {
    for (int i = 0; i < n; ++i) {
        int v;
        if (scanf("%d", &v) != 1) {
            fprintf(stderr, "ERROR: input read failed at %d / %d\n", i, n);
            return false;
        }
        out[i] = (int16_t)v;
    }
    return true;
}

// Write N int16 values to stdout, one per line.
inline void write_int16s(const int16_t* data, int n) {
    for (int i = 0; i < n; ++i) printf("%d\n", data[i]);
}

// Generic reset + start pulse + wait-until-done. The `is_done` callable lets
// each module check whatever combination of done/valid it actually exposes.
// Returns cycles spent in the wait loop, or -1 on timeout.
template <typename Dut, typename DoneFn>
int run_to_done_with(Dut* dut, DoneFn is_done, int max_cycles = 2000000) {
    auto tick = [&]() {
        dut->clk = 0; dut->eval();
        dut->clk = 1; dut->eval();
    };

    dut->rst = 1; dut->start = 0;
    for (int i = 0; i < 5; ++i) tick();
    dut->rst = 0;
    tick(); tick();

    dut->start = 1; tick();
    dut->start = 0;

    int cycles = 0;
    while (!is_done()) {
        tick();
        if (++cycles > max_cycles) {
            fprintf(stderr, "ERROR: TIMEOUT after %d cycles\n", cycles);
            return -1;
        }
    }
    fprintf(stderr, "done after %d cycles\n", cycles);
    return cycles;
}

// Convenience: standard `done && valid` check used by most modules.
template <typename Dut>
int run_to_done(Dut* dut, int max_cycles = 2000000) {
    return run_to_done_with(dut, [&]() { return dut->done && dut->valid; },
                            max_cycles);
}

}  // namespace sim
