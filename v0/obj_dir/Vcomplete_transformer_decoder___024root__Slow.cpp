// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcomplete_transformer_decoder.h for the primary calling header

#include "Vcomplete_transformer_decoder__pch.h"

void Vcomplete_transformer_decoder___024root___ctor_var_reset(Vcomplete_transformer_decoder___024root* vlSelf);

Vcomplete_transformer_decoder___024root::Vcomplete_transformer_decoder___024root(Vcomplete_transformer_decoder__Syms* symsp, const char* namep)
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    Vcomplete_transformer_decoder___024root___ctor_var_reset(this);
}

void Vcomplete_transformer_decoder___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vcomplete_transformer_decoder___024root::~Vcomplete_transformer_decoder___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
