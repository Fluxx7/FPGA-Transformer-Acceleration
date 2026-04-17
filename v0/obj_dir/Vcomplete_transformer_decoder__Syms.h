// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VCOMPLETE_TRANSFORMER_DECODER__SYMS_H_
#define VERILATED_VCOMPLETE_TRANSFORMER_DECODER__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vcomplete_transformer_decoder.h"

// INCLUDE MODULE CLASSES
#include "Vcomplete_transformer_decoder___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES) Vcomplete_transformer_decoder__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vcomplete_transformer_decoder* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vcomplete_transformer_decoder___024root TOP;

    // CONSTRUCTORS
    Vcomplete_transformer_decoder__Syms(VerilatedContext* contextp, const char* namep, Vcomplete_transformer_decoder* modelp);
    ~Vcomplete_transformer_decoder__Syms();

    // METHODS
    const char* name() const { return TOP.vlNamep; }
};

#endif  // guard
