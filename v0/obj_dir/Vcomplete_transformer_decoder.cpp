// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vcomplete_transformer_decoder__pch.h"

//============================================================
// Constructors

Vcomplete_transformer_decoder::Vcomplete_transformer_decoder(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vcomplete_transformer_decoder__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , start{vlSymsp->TOP.start}
    , predicted_token{vlSymsp->TOP.predicted_token}
    , done{vlSymsp->TOP.done}
    , valid{vlSymsp->TOP.valid}
    , current_state_debug{vlSymsp->TOP.current_state_debug}
    , cycle_count{vlSymsp->TOP.cycle_count}
    , input_sequence_flat{vlSymsp->TOP.input_sequence_flat}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vcomplete_transformer_decoder::Vcomplete_transformer_decoder(const char* _vcname__)
    : Vcomplete_transformer_decoder(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vcomplete_transformer_decoder::~Vcomplete_transformer_decoder() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vcomplete_transformer_decoder___024root___eval_debug_assertions(Vcomplete_transformer_decoder___024root* vlSelf);
#endif  // VL_DEBUG
void Vcomplete_transformer_decoder___024root___eval_static(Vcomplete_transformer_decoder___024root* vlSelf);
void Vcomplete_transformer_decoder___024root___eval_initial(Vcomplete_transformer_decoder___024root* vlSelf);
void Vcomplete_transformer_decoder___024root___eval_settle(Vcomplete_transformer_decoder___024root* vlSelf);
void Vcomplete_transformer_decoder___024root___eval(Vcomplete_transformer_decoder___024root* vlSelf);

void Vcomplete_transformer_decoder::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vcomplete_transformer_decoder::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vcomplete_transformer_decoder___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vcomplete_transformer_decoder___024root___eval_static(&(vlSymsp->TOP));
        Vcomplete_transformer_decoder___024root___eval_initial(&(vlSymsp->TOP));
        Vcomplete_transformer_decoder___024root___eval_settle(&(vlSymsp->TOP));
        vlSymsp->__Vm_didInit = true;
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vcomplete_transformer_decoder___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vcomplete_transformer_decoder::eventsPending() { return false; }

uint64_t Vcomplete_transformer_decoder::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vcomplete_transformer_decoder::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vcomplete_transformer_decoder___024root___eval_final(Vcomplete_transformer_decoder___024root* vlSelf);

VL_ATTR_COLD void Vcomplete_transformer_decoder::final() {
    Vcomplete_transformer_decoder___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vcomplete_transformer_decoder::hierName() const { return vlSymsp->name(); }
const char* Vcomplete_transformer_decoder::modelName() const { return "Vcomplete_transformer_decoder"; }
unsigned Vcomplete_transformer_decoder::threads() const { return 1; }
void Vcomplete_transformer_decoder::prepareClone() const { contextp()->prepareClone(); }
void Vcomplete_transformer_decoder::atClone() const {
    contextp()->threadPoolpOnClone();
}
