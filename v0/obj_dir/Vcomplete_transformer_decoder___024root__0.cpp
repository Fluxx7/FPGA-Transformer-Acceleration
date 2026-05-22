// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcomplete_transformer_decoder.h for the primary calling header

#include "Vcomplete_transformer_decoder__pch.h"

void Vcomplete_transformer_decoder___024root___eval_triggers_vec__ico(Vcomplete_transformer_decoder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcomplete_transformer_decoder___024root___eval_triggers_vec__ico\n"); );
    Vcomplete_transformer_decoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered[0U]) 
                                     | (IData)((IData)(vlSelfRef.__VicoFirstIteration)));
}

bool Vcomplete_transformer_decoder___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcomplete_transformer_decoder___024root___trigger_anySet__ico\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void Vcomplete_transformer_decoder___024root___ico_sequent__TOP__0(Vcomplete_transformer_decoder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcomplete_transformer_decoder___024root___ico_sequent__TOP__0\n"); );
    Vcomplete_transformer_decoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.complete_transformer_decoder__DOT__embedding_inst__DOT__embed_addr 
        = (0x00000fffU & (VL_SHIFTL_III(12,12,32, vlSelfRef.input_sequence
                                        [vlSelfRef.complete_transformer_decoder__DOT__embedding_inst__DOT__seq_idx], 4U) 
                          + (IData)(vlSelfRef.complete_transformer_decoder__DOT__embedding_inst__DOT__dim_idx)));
    vlSelfRef.complete_transformer_decoder__DOT__last_pos = 0U;
    if ((0U != vlSelfRef.input_sequence[0U])) {
        vlSelfRef.complete_transformer_decoder__DOT__last_pos = 0U;
    }
    if ((0U != vlSelfRef.input_sequence[1U])) {
        vlSelfRef.complete_transformer_decoder__DOT__last_pos = 1U;
    }
    if ((0U != vlSelfRef.input_sequence[2U])) {
        vlSelfRef.complete_transformer_decoder__DOT__last_pos = 2U;
    }
    if ((0U != vlSelfRef.input_sequence[3U])) {
        vlSelfRef.complete_transformer_decoder__DOT__last_pos = 3U;
    }
    if ((0U != vlSelfRef.input_sequence[4U])) {
        vlSelfRef.complete_transformer_decoder__DOT__last_pos = 4U;
    }
    if ((0U != vlSelfRef.input_sequence[5U])) {
        vlSelfRef.complete_transformer_decoder__DOT__last_pos = 5U;
    }
    if ((0U != vlSelfRef.input_sequence[6U])) {
        vlSelfRef.complete_transformer_decoder__DOT__last_pos = 6U;
    }
    if ((0U != vlSelfRef.input_sequence[7U])) {
        vlSelfRef.complete_transformer_decoder__DOT__last_pos = 7U;
    }
    vlSelfRef.complete_transformer_decoder__DOT____Vcellinp__projection_inst__final_hidden_state[0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__norm2_out
        [vlSelfRef.complete_transformer_decoder__DOT__last_pos][0U];
    vlSelfRef.complete_transformer_decoder__DOT____Vcellinp__projection_inst__final_hidden_state[1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__norm2_out
        [vlSelfRef.complete_transformer_decoder__DOT__last_pos][1U];
    vlSelfRef.complete_transformer_decoder__DOT____Vcellinp__projection_inst__final_hidden_state[2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__norm2_out
        [vlSelfRef.complete_transformer_decoder__DOT__last_pos][2U];
    vlSelfRef.complete_transformer_decoder__DOT____Vcellinp__projection_inst__final_hidden_state[3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__norm2_out
        [vlSelfRef.complete_transformer_decoder__DOT__last_pos][3U];
    vlSelfRef.complete_transformer_decoder__DOT____Vcellinp__projection_inst__final_hidden_state[4U] 
        = vlSelfRef.complete_transformer_decoder__DOT__norm2_out
        [vlSelfRef.complete_transformer_decoder__DOT__last_pos][4U];
    vlSelfRef.complete_transformer_decoder__DOT____Vcellinp__projection_inst__final_hidden_state[5U] 
        = vlSelfRef.complete_transformer_decoder__DOT__norm2_out
        [vlSelfRef.complete_transformer_decoder__DOT__last_pos][5U];
    vlSelfRef.complete_transformer_decoder__DOT____Vcellinp__projection_inst__final_hidden_state[6U] 
        = vlSelfRef.complete_transformer_decoder__DOT__norm2_out
        [vlSelfRef.complete_transformer_decoder__DOT__last_pos][6U];
    vlSelfRef.complete_transformer_decoder__DOT____Vcellinp__projection_inst__final_hidden_state[7U] 
        = vlSelfRef.complete_transformer_decoder__DOT__norm2_out
        [vlSelfRef.complete_transformer_decoder__DOT__last_pos][7U];
    vlSelfRef.complete_transformer_decoder__DOT____Vcellinp__projection_inst__final_hidden_state[8U] 
        = vlSelfRef.complete_transformer_decoder__DOT__norm2_out
        [vlSelfRef.complete_transformer_decoder__DOT__last_pos][8U];
    vlSelfRef.complete_transformer_decoder__DOT____Vcellinp__projection_inst__final_hidden_state[9U] 
        = vlSelfRef.complete_transformer_decoder__DOT__norm2_out
        [vlSelfRef.complete_transformer_decoder__DOT__last_pos][9U];
    vlSelfRef.complete_transformer_decoder__DOT____Vcellinp__projection_inst__final_hidden_state[10U] 
        = vlSelfRef.complete_transformer_decoder__DOT__norm2_out
        [vlSelfRef.complete_transformer_decoder__DOT__last_pos][10U];
    vlSelfRef.complete_transformer_decoder__DOT____Vcellinp__projection_inst__final_hidden_state[11U] 
        = vlSelfRef.complete_transformer_decoder__DOT__norm2_out
        [vlSelfRef.complete_transformer_decoder__DOT__last_pos][11U];
    vlSelfRef.complete_transformer_decoder__DOT____Vcellinp__projection_inst__final_hidden_state[12U] 
        = vlSelfRef.complete_transformer_decoder__DOT__norm2_out
        [vlSelfRef.complete_transformer_decoder__DOT__last_pos][12U];
    vlSelfRef.complete_transformer_decoder__DOT____Vcellinp__projection_inst__final_hidden_state[13U] 
        = vlSelfRef.complete_transformer_decoder__DOT__norm2_out
        [vlSelfRef.complete_transformer_decoder__DOT__last_pos][13U];
    vlSelfRef.complete_transformer_decoder__DOT____Vcellinp__projection_inst__final_hidden_state[14U] 
        = vlSelfRef.complete_transformer_decoder__DOT__norm2_out
        [vlSelfRef.complete_transformer_decoder__DOT__last_pos][14U];
    vlSelfRef.complete_transformer_decoder__DOT____Vcellinp__projection_inst__final_hidden_state[15U] 
        = vlSelfRef.complete_transformer_decoder__DOT__norm2_out
        [vlSelfRef.complete_transformer_decoder__DOT__last_pos][15U];
}

void Vcomplete_transformer_decoder___024root___eval_ico(Vcomplete_transformer_decoder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcomplete_transformer_decoder___024root___eval_ico\n"); );
    Vcomplete_transformer_decoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered[0U])) {
        Vcomplete_transformer_decoder___024root___ico_sequent__TOP__0(vlSelf);
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vcomplete_transformer_decoder___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vcomplete_transformer_decoder___024root___eval_phase__ico(Vcomplete_transformer_decoder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcomplete_transformer_decoder___024root___eval_phase__ico\n"); );
    Vcomplete_transformer_decoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VicoExecute;
    // Body
    Vcomplete_transformer_decoder___024root___eval_triggers_vec__ico(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vcomplete_transformer_decoder___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
    __VicoExecute = Vcomplete_transformer_decoder___024root___trigger_anySet__ico(vlSelfRef.__VicoTriggered);
    if (__VicoExecute) {
        Vcomplete_transformer_decoder___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vcomplete_transformer_decoder___024root___eval_triggers_vec__act(Vcomplete_transformer_decoder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcomplete_transformer_decoder___024root___eval_triggers_vec__act\n"); );
    Vcomplete_transformer_decoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    ((IData)(vlSelfRef.clk) 
                                                     & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0)))));
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
}

bool Vcomplete_transformer_decoder___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcomplete_transformer_decoder___024root___trigger_anySet__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void Vcomplete_transformer_decoder___024root___nba_sequent__TOP__0(Vcomplete_transformer_decoder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcomplete_transformer_decoder___024root___nba_sequent__TOP__0\n"); );
    Vcomplete_transformer_decoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    SData/*15:0*/ __Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__0__Vfuncout;
    __Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__0__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__0__x;
    __Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__0__x = 0;
    SData/*15:0*/ __Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__1__Vfuncout;
    __Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__1__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__1__x;
    __Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__1__x = 0;
    SData/*15:0*/ __Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__2__Vfuncout;
    __Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__2__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__2__x;
    __Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__2__x = 0;
    SData/*15:0*/ __Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__3__Vfuncout;
    __Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__3__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__3__x;
    __Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__3__x = 0;
    SData/*15:0*/ __Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__4__Vfuncout;
    __Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__4__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__4__x;
    __Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__4__x = 0;
    SData/*15:0*/ __Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__5__Vfuncout;
    __Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__5__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__5__x;
    __Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__5__x = 0;
    SData/*15:0*/ __Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__6__Vfuncout;
    __Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__6__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__6__x;
    __Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__6__x = 0;
    SData/*15:0*/ __Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__7__Vfuncout;
    __Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__7__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__7__x;
    __Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__7__x = 0;
    SData/*15:0*/ __Vfunc_complete_transformer_decoder__DOT__layer_norm1_inst__DOT__improved_sqrt__8__Vfuncout;
    __Vfunc_complete_transformer_decoder__DOT__layer_norm1_inst__DOT__improved_sqrt__8__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_complete_transformer_decoder__DOT__layer_norm1_inst__DOT__improved_sqrt__8__x;
    __Vfunc_complete_transformer_decoder__DOT__layer_norm1_inst__DOT__improved_sqrt__8__x = 0;
    SData/*15:0*/ __Vfunc_complete_transformer_decoder__DOT__layer_norm2_inst__DOT__improved_sqrt__9__Vfuncout;
    __Vfunc_complete_transformer_decoder__DOT__layer_norm2_inst__DOT__improved_sqrt__9__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_complete_transformer_decoder__DOT__layer_norm2_inst__DOT__improved_sqrt__9__x;
    __Vfunc_complete_transformer_decoder__DOT__layer_norm2_inst__DOT__improved_sqrt__9__x = 0;
    CData/*3:0*/ __Vdly__complete_transformer_decoder__DOT__current_state;
    __Vdly__complete_transformer_decoder__DOT__current_state = 0;
    CData/*0:0*/ __Vdly__complete_transformer_decoder__DOT__embed_start;
    __Vdly__complete_transformer_decoder__DOT__embed_start = 0;
    CData/*0:0*/ __Vdly__complete_transformer_decoder__DOT__pos_start;
    __Vdly__complete_transformer_decoder__DOT__pos_start = 0;
    CData/*0:0*/ __Vdly__complete_transformer_decoder__DOT__attn_start;
    __Vdly__complete_transformer_decoder__DOT__attn_start = 0;
    CData/*0:0*/ __Vdly__complete_transformer_decoder__DOT__norm1_start;
    __Vdly__complete_transformer_decoder__DOT__norm1_start = 0;
    CData/*0:0*/ __Vdly__complete_transformer_decoder__DOT__ffn_start;
    __Vdly__complete_transformer_decoder__DOT__ffn_start = 0;
    CData/*0:0*/ __Vdly__complete_transformer_decoder__DOT__norm2_start;
    __Vdly__complete_transformer_decoder__DOT__norm2_start = 0;
    CData/*0:0*/ __Vdly__complete_transformer_decoder__DOT__proj_start;
    __Vdly__complete_transformer_decoder__DOT__proj_start = 0;
    CData/*0:0*/ __Vdly__complete_transformer_decoder__DOT__argmax_start;
    __Vdly__complete_transformer_decoder__DOT__argmax_start = 0;
    CData/*1:0*/ __Vdly__complete_transformer_decoder__DOT__embedding_inst__DOT__state;
    __Vdly__complete_transformer_decoder__DOT__embedding_inst__DOT__state = 0;
    CData/*2:0*/ __Vdly__complete_transformer_decoder__DOT__embedding_inst__DOT__seq_idx;
    __Vdly__complete_transformer_decoder__DOT__embedding_inst__DOT__seq_idx = 0;
    CData/*3:0*/ __Vdly__complete_transformer_decoder__DOT__embedding_inst__DOT__dim_idx;
    __Vdly__complete_transformer_decoder__DOT__embedding_inst__DOT__dim_idx = 0;
    CData/*1:0*/ __Vdly__complete_transformer_decoder__DOT__embedding_inst__DOT__pipe_stage;
    __Vdly__complete_transformer_decoder__DOT__embedding_inst__DOT__pipe_stage = 0;
    CData/*1:0*/ __Vdly__complete_transformer_decoder__DOT__positional_inst__DOT__state;
    __Vdly__complete_transformer_decoder__DOT__positional_inst__DOT__state = 0;
    CData/*2:0*/ __Vdly__complete_transformer_decoder__DOT__positional_inst__DOT__seq_idx;
    __Vdly__complete_transformer_decoder__DOT__positional_inst__DOT__seq_idx = 0;
    CData/*3:0*/ __Vdly__complete_transformer_decoder__DOT__positional_inst__DOT__dim_idx;
    __Vdly__complete_transformer_decoder__DOT__positional_inst__DOT__dim_idx = 0;
    CData/*1:0*/ __Vdly__complete_transformer_decoder__DOT__positional_inst__DOT__pipe_stage;
    __Vdly__complete_transformer_decoder__DOT__positional_inst__DOT__pipe_stage = 0;
    IData/*16:0*/ __Vdly__complete_transformer_decoder__DOT__positional_inst__DOT__temp_sum;
    __Vdly__complete_transformer_decoder__DOT__positional_inst__DOT__temp_sum = 0;
    CData/*2:0*/ __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__state;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__state = 0;
    CData/*3:0*/ __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__head_start_signals;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__head_start_signals = 0;
    CData/*2:0*/ __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__seq_idx;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__seq_idx = 0;
    CData/*3:0*/ __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__dim_idx;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__dim_idx = 0;
    CData/*3:0*/ __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__in_dim;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__in_dim = 0;
    CData/*3:0*/ __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__out_dim;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__out_dim = 0;
    CData/*2:0*/ __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__pipe_stage;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__pipe_stage = 0;
    IData/*31:0*/ __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__proj_accumulator;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__proj_accumulator = 0;
    CData/*2:0*/ __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__state;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__state = 0;
    CData/*2:0*/ __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx = 0;
    CData/*2:0*/ __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx2;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx2 = 0;
    CData/*3:0*/ __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__embed_idx;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__embed_idx = 0;
    CData/*3:0*/ __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__head_idx;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__head_idx = 0;
    CData/*2:0*/ __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__pipe_stage;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__pipe_stage = 0;
    IData/*31:0*/ __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__accumulator;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__accumulator = 0;
    CData/*0:0*/ __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_start;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_start = 0;
    CData/*2:0*/ __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__state;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__state = 0;
    CData/*2:0*/ __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__row_idx;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__row_idx = 0;
    CData/*2:0*/ __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__col_idx;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__col_idx = 0;
    SData/*15:0*/ __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__max_val;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__max_val = 0;
    IData/*31:0*/ __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__exp_sum;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__exp_sum = 0;
    CData/*2:0*/ __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__state;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__state = 0;
    CData/*2:0*/ __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx = 0;
    CData/*2:0*/ __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx2;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx2 = 0;
    CData/*3:0*/ __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__embed_idx;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__embed_idx = 0;
    CData/*3:0*/ __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__head_idx;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__head_idx = 0;
    CData/*2:0*/ __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__pipe_stage;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__pipe_stage = 0;
    IData/*31:0*/ __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__accumulator;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__accumulator = 0;
    CData/*0:0*/ __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_start;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_start = 0;
    CData/*2:0*/ __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__state;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__state = 0;
    CData/*2:0*/ __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__row_idx;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__row_idx = 0;
    CData/*2:0*/ __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__col_idx;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__col_idx = 0;
    SData/*15:0*/ __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__max_val;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__max_val = 0;
    IData/*31:0*/ __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__exp_sum;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__exp_sum = 0;
    CData/*2:0*/ __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__state;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__state = 0;
    CData/*2:0*/ __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx = 0;
    CData/*2:0*/ __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx2;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx2 = 0;
    CData/*3:0*/ __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__embed_idx;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__embed_idx = 0;
    CData/*3:0*/ __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__head_idx;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__head_idx = 0;
    CData/*2:0*/ __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__pipe_stage;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__pipe_stage = 0;
    IData/*31:0*/ __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__accumulator;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__accumulator = 0;
    CData/*0:0*/ __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_start;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_start = 0;
    CData/*2:0*/ __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__state;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__state = 0;
    CData/*2:0*/ __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__row_idx;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__row_idx = 0;
    CData/*2:0*/ __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__col_idx;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__col_idx = 0;
    SData/*15:0*/ __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__max_val;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__max_val = 0;
    IData/*31:0*/ __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__exp_sum;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__exp_sum = 0;
    CData/*2:0*/ __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__state;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__state = 0;
    CData/*2:0*/ __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx = 0;
    CData/*2:0*/ __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx2;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx2 = 0;
    CData/*3:0*/ __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__embed_idx;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__embed_idx = 0;
    CData/*3:0*/ __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__head_idx;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__head_idx = 0;
    CData/*2:0*/ __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__pipe_stage;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__pipe_stage = 0;
    IData/*31:0*/ __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__accumulator;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__accumulator = 0;
    CData/*0:0*/ __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_start;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_start = 0;
    CData/*2:0*/ __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__state;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__state = 0;
    CData/*2:0*/ __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__row_idx;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__row_idx = 0;
    CData/*2:0*/ __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__col_idx;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__col_idx = 0;
    SData/*15:0*/ __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__max_val;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__max_val = 0;
    IData/*31:0*/ __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__exp_sum;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__exp_sum = 0;
    CData/*2:0*/ __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__state;
    __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__state = 0;
    CData/*2:0*/ __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__seq_idx;
    __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__seq_idx = 0;
    CData/*3:0*/ __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__dim_idx;
    __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__dim_idx = 0;
    IData/*31:0*/ __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__mean_acc;
    __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__mean_acc = 0;
    IData/*31:0*/ __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__var_acc;
    __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__var_acc = 0;
    CData/*2:0*/ __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__pipe_stage;
    __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__pipe_stage = 0;
    IData/*16:0*/ __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__temp_sum;
    __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__temp_sum = 0;
    IData/*31:0*/ __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__diff;
    __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__diff = 0;
    IData/*31:0*/ __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__diff_sq;
    __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__diff_sq = 0;
    IData/*31:0*/ __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__normalized;
    __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__normalized = 0;
    IData/*31:0*/ __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__with_gamma;
    __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__with_gamma = 0;
    IData/*31:0*/ __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__final_result;
    __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__final_result = 0;
    IData/*31:0*/ __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__variance;
    __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__variance = 0;
    CData/*2:0*/ __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__state;
    __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__state = 0;
    CData/*2:0*/ __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__seq_idx;
    __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__seq_idx = 0;
    CData/*3:0*/ __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__in_dim;
    __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__in_dim = 0;
    CData/*3:0*/ __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__out_dim;
    __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__out_dim = 0;
    CData/*4:0*/ __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__hidden_dim;
    __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__hidden_dim = 0;
    IData/*31:0*/ __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__accumulator;
    __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__accumulator = 0;
    CData/*2:0*/ __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__pipe_stage;
    __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__pipe_stage = 0;
    IData/*31:0*/ __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__with_bias;
    __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__with_bias = 0;
    CData/*2:0*/ __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__state;
    __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__state = 0;
    CData/*2:0*/ __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__seq_idx;
    __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__seq_idx = 0;
    CData/*3:0*/ __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__dim_idx;
    __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__dim_idx = 0;
    IData/*31:0*/ __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__mean_acc;
    __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__mean_acc = 0;
    IData/*31:0*/ __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__var_acc;
    __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__var_acc = 0;
    CData/*2:0*/ __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__pipe_stage;
    __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__pipe_stage = 0;
    IData/*16:0*/ __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__temp_sum;
    __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__temp_sum = 0;
    IData/*31:0*/ __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__diff;
    __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__diff = 0;
    IData/*31:0*/ __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__diff_sq;
    __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__diff_sq = 0;
    IData/*31:0*/ __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__normalized;
    __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__normalized = 0;
    IData/*31:0*/ __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__with_gamma;
    __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__with_gamma = 0;
    IData/*31:0*/ __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__final_result;
    __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__final_result = 0;
    IData/*31:0*/ __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__variance;
    __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__variance = 0;
    CData/*1:0*/ __Vdly__complete_transformer_decoder__DOT__projection_inst__DOT__state;
    __Vdly__complete_transformer_decoder__DOT__projection_inst__DOT__state = 0;
    CData/*5:0*/ __Vdly__complete_transformer_decoder__DOT__projection_inst__DOT__vocab_idx;
    __Vdly__complete_transformer_decoder__DOT__projection_inst__DOT__vocab_idx = 0;
    CData/*3:0*/ __Vdly__complete_transformer_decoder__DOT__projection_inst__DOT__dim_idx;
    __Vdly__complete_transformer_decoder__DOT__projection_inst__DOT__dim_idx = 0;
    IData/*31:0*/ __Vdly__complete_transformer_decoder__DOT__projection_inst__DOT__logit_accumulator;
    __Vdly__complete_transformer_decoder__DOT__projection_inst__DOT__logit_accumulator = 0;
    CData/*2:0*/ __Vdly__complete_transformer_decoder__DOT__projection_inst__DOT__pipe_stage;
    __Vdly__complete_transformer_decoder__DOT__projection_inst__DOT__pipe_stage = 0;
    CData/*1:0*/ __Vdly__complete_transformer_decoder__DOT__argmax_inst__DOT__state;
    __Vdly__complete_transformer_decoder__DOT__argmax_inst__DOT__state = 0;
    CData/*5:0*/ __Vdly__complete_transformer_decoder__DOT__argmax_inst__DOT__current_idx;
    __Vdly__complete_transformer_decoder__DOT__argmax_inst__DOT__current_idx = 0;
    SData/*15:0*/ __Vdly__complete_transformer_decoder__DOT__argmax_inst__DOT__max_value;
    __Vdly__complete_transformer_decoder__DOT__argmax_inst__DOT__max_value = 0;
    CData/*5:0*/ __Vdly__complete_transformer_decoder__DOT__argmax_inst__DOT__max_index;
    __Vdly__complete_transformer_decoder__DOT__argmax_inst__DOT__max_index = 0;
    SData/*15:0*/ __VdlyVal__complete_transformer_decoder__DOT__embedded_tokens__v0;
    __VdlyVal__complete_transformer_decoder__DOT__embedded_tokens__v0 = 0;
    CData/*3:0*/ __VdlyDim0__complete_transformer_decoder__DOT__embedded_tokens__v0;
    __VdlyDim0__complete_transformer_decoder__DOT__embedded_tokens__v0 = 0;
    CData/*2:0*/ __VdlyDim1__complete_transformer_decoder__DOT__embedded_tokens__v0;
    __VdlyDim1__complete_transformer_decoder__DOT__embedded_tokens__v0 = 0;
    CData/*0:0*/ __VdlySet__complete_transformer_decoder__DOT__embedded_tokens__v0;
    __VdlySet__complete_transformer_decoder__DOT__embedded_tokens__v0 = 0;
    SData/*15:0*/ __VdlyVal__complete_transformer_decoder__DOT__position_encoded__v0;
    __VdlyVal__complete_transformer_decoder__DOT__position_encoded__v0 = 0;
    CData/*3:0*/ __VdlyDim0__complete_transformer_decoder__DOT__position_encoded__v0;
    __VdlyDim0__complete_transformer_decoder__DOT__position_encoded__v0 = 0;
    CData/*2:0*/ __VdlyDim1__complete_transformer_decoder__DOT__position_encoded__v0;
    __VdlyDim1__complete_transformer_decoder__DOT__position_encoded__v0 = 0;
    CData/*0:0*/ __VdlySet__complete_transformer_decoder__DOT__position_encoded__v0;
    __VdlySet__complete_transformer_decoder__DOT__position_encoded__v0 = 0;
    SData/*15:0*/ __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__concatenated__v0;
    __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__concatenated__v0 = 0;
    CData/*3:0*/ __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__concatenated__v0;
    __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__concatenated__v0 = 0;
    CData/*2:0*/ __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__concatenated__v0;
    __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__concatenated__v0 = 0;
    CData/*0:0*/ __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__concatenated__v0;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__concatenated__v0 = 0;
    SData/*15:0*/ __VdlyVal__complete_transformer_decoder__DOT__attention_out__v0;
    __VdlyVal__complete_transformer_decoder__DOT__attention_out__v0 = 0;
    CData/*3:0*/ __VdlyDim0__complete_transformer_decoder__DOT__attention_out__v0;
    __VdlyDim0__complete_transformer_decoder__DOT__attention_out__v0 = 0;
    CData/*2:0*/ __VdlyDim1__complete_transformer_decoder__DOT__attention_out__v0;
    __VdlyDim1__complete_transformer_decoder__DOT__attention_out__v0 = 0;
    CData/*0:0*/ __VdlySet__complete_transformer_decoder__DOT__attention_out__v0;
    __VdlySet__complete_transformer_decoder__DOT__attention_out__v0 = 0;
    SData/*15:0*/ __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__Q__v0;
    __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__Q__v0 = 0;
    CData/*1:0*/ __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__Q__v0;
    __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__Q__v0 = 0;
    CData/*2:0*/ __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__Q__v0;
    __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__Q__v0 = 0;
    CData/*0:0*/ __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__Q__v0;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__Q__v0 = 0;
    SData/*15:0*/ __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__K__v0;
    __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__K__v0 = 0;
    CData/*1:0*/ __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__K__v0;
    __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__K__v0 = 0;
    CData/*2:0*/ __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__K__v0;
    __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__K__v0 = 0;
    CData/*0:0*/ __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__K__v0;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__K__v0 = 0;
    SData/*15:0*/ __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__V__v0;
    __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__V__v0 = 0;
    CData/*1:0*/ __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__V__v0;
    __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__V__v0 = 0;
    CData/*2:0*/ __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__V__v0;
    __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__V__v0 = 0;
    CData/*0:0*/ __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__V__v0;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__V__v0 = 0;
    SData/*15:0*/ __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_scores__v0;
    __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_scores__v0 = 0;
    CData/*2:0*/ __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_scores__v0;
    __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_scores__v0 = 0;
    CData/*2:0*/ __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_scores__v0;
    __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_scores__v0 = 0;
    CData/*0:0*/ __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_scores__v0;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_scores__v0 = 0;
    CData/*2:0*/ __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_scores__v1;
    __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_scores__v1 = 0;
    CData/*2:0*/ __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_scores__v1;
    __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_scores__v1 = 0;
    CData/*0:0*/ __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_scores__v1;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_scores__v1 = 0;
    SData/*15:0*/ __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__0__KET____DOT__head__output_data__v0;
    __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__0__KET____DOT__head__output_data__v0 = 0;
    CData/*1:0*/ __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__0__KET____DOT__head__output_data__v0;
    __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__0__KET____DOT__head__output_data__v0 = 0;
    CData/*2:0*/ __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__0__KET____DOT__head__output_data__v0;
    __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__0__KET____DOT__head__output_data__v0 = 0;
    CData/*0:0*/ __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__0__KET____DOT__head__output_data__v0;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__0__KET____DOT__head__output_data__v0 = 0;
    SData/*15:0*/ __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__temp_exp__v0;
    __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__temp_exp__v0 = 0;
    CData/*2:0*/ __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__temp_exp__v0;
    __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__temp_exp__v0 = 0;
    CData/*0:0*/ __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__temp_exp__v0;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__temp_exp__v0 = 0;
    SData/*15:0*/ __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_weights__v0;
    __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_weights__v0 = 0;
    CData/*2:0*/ __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_weights__v0;
    __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_weights__v0 = 0;
    CData/*2:0*/ __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_weights__v0;
    __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_weights__v0 = 0;
    CData/*0:0*/ __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_weights__v0;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_weights__v0 = 0;
    CData/*2:0*/ __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_weights__v1;
    __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_weights__v1 = 0;
    CData/*2:0*/ __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_weights__v1;
    __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_weights__v1 = 0;
    CData/*0:0*/ __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_weights__v1;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_weights__v1 = 0;
    SData/*15:0*/ __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__Q__v0;
    __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__Q__v0 = 0;
    CData/*1:0*/ __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__Q__v0;
    __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__Q__v0 = 0;
    CData/*2:0*/ __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__Q__v0;
    __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__Q__v0 = 0;
    CData/*0:0*/ __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__Q__v0;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__Q__v0 = 0;
    SData/*15:0*/ __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__K__v0;
    __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__K__v0 = 0;
    CData/*1:0*/ __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__K__v0;
    __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__K__v0 = 0;
    CData/*2:0*/ __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__K__v0;
    __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__K__v0 = 0;
    CData/*0:0*/ __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__K__v0;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__K__v0 = 0;
    SData/*15:0*/ __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__V__v0;
    __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__V__v0 = 0;
    CData/*1:0*/ __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__V__v0;
    __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__V__v0 = 0;
    CData/*2:0*/ __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__V__v0;
    __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__V__v0 = 0;
    CData/*0:0*/ __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__V__v0;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__V__v0 = 0;
    SData/*15:0*/ __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_scores__v0;
    __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_scores__v0 = 0;
    CData/*2:0*/ __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_scores__v0;
    __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_scores__v0 = 0;
    CData/*2:0*/ __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_scores__v0;
    __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_scores__v0 = 0;
    CData/*0:0*/ __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_scores__v0;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_scores__v0 = 0;
    CData/*2:0*/ __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_scores__v1;
    __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_scores__v1 = 0;
    CData/*2:0*/ __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_scores__v1;
    __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_scores__v1 = 0;
    CData/*0:0*/ __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_scores__v1;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_scores__v1 = 0;
    SData/*15:0*/ __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__1__KET____DOT__head__output_data__v0;
    __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__1__KET____DOT__head__output_data__v0 = 0;
    CData/*1:0*/ __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__1__KET____DOT__head__output_data__v0;
    __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__1__KET____DOT__head__output_data__v0 = 0;
    CData/*2:0*/ __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__1__KET____DOT__head__output_data__v0;
    __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__1__KET____DOT__head__output_data__v0 = 0;
    CData/*0:0*/ __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__1__KET____DOT__head__output_data__v0;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__1__KET____DOT__head__output_data__v0 = 0;
    SData/*15:0*/ __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__temp_exp__v0;
    __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__temp_exp__v0 = 0;
    CData/*2:0*/ __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__temp_exp__v0;
    __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__temp_exp__v0 = 0;
    CData/*0:0*/ __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__temp_exp__v0;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__temp_exp__v0 = 0;
    SData/*15:0*/ __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_weights__v0;
    __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_weights__v0 = 0;
    CData/*2:0*/ __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_weights__v0;
    __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_weights__v0 = 0;
    CData/*2:0*/ __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_weights__v0;
    __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_weights__v0 = 0;
    CData/*0:0*/ __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_weights__v0;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_weights__v0 = 0;
    CData/*2:0*/ __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_weights__v1;
    __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_weights__v1 = 0;
    CData/*2:0*/ __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_weights__v1;
    __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_weights__v1 = 0;
    CData/*0:0*/ __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_weights__v1;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_weights__v1 = 0;
    SData/*15:0*/ __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__Q__v0;
    __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__Q__v0 = 0;
    CData/*1:0*/ __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__Q__v0;
    __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__Q__v0 = 0;
    CData/*2:0*/ __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__Q__v0;
    __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__Q__v0 = 0;
    CData/*0:0*/ __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__Q__v0;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__Q__v0 = 0;
    SData/*15:0*/ __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__K__v0;
    __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__K__v0 = 0;
    CData/*1:0*/ __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__K__v0;
    __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__K__v0 = 0;
    CData/*2:0*/ __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__K__v0;
    __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__K__v0 = 0;
    CData/*0:0*/ __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__K__v0;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__K__v0 = 0;
    SData/*15:0*/ __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__V__v0;
    __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__V__v0 = 0;
    CData/*1:0*/ __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__V__v0;
    __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__V__v0 = 0;
    CData/*2:0*/ __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__V__v0;
    __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__V__v0 = 0;
    CData/*0:0*/ __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__V__v0;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__V__v0 = 0;
    SData/*15:0*/ __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_scores__v0;
    __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_scores__v0 = 0;
    CData/*2:0*/ __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_scores__v0;
    __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_scores__v0 = 0;
    CData/*2:0*/ __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_scores__v0;
    __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_scores__v0 = 0;
    CData/*0:0*/ __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_scores__v0;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_scores__v0 = 0;
    CData/*2:0*/ __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_scores__v1;
    __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_scores__v1 = 0;
    CData/*2:0*/ __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_scores__v1;
    __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_scores__v1 = 0;
    CData/*0:0*/ __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_scores__v1;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_scores__v1 = 0;
    SData/*15:0*/ __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__2__KET____DOT__head__output_data__v0;
    __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__2__KET____DOT__head__output_data__v0 = 0;
    CData/*1:0*/ __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__2__KET____DOT__head__output_data__v0;
    __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__2__KET____DOT__head__output_data__v0 = 0;
    CData/*2:0*/ __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__2__KET____DOT__head__output_data__v0;
    __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__2__KET____DOT__head__output_data__v0 = 0;
    CData/*0:0*/ __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__2__KET____DOT__head__output_data__v0;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__2__KET____DOT__head__output_data__v0 = 0;
    SData/*15:0*/ __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__temp_exp__v0;
    __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__temp_exp__v0 = 0;
    CData/*2:0*/ __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__temp_exp__v0;
    __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__temp_exp__v0 = 0;
    CData/*0:0*/ __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__temp_exp__v0;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__temp_exp__v0 = 0;
    SData/*15:0*/ __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_weights__v0;
    __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_weights__v0 = 0;
    CData/*2:0*/ __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_weights__v0;
    __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_weights__v0 = 0;
    CData/*2:0*/ __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_weights__v0;
    __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_weights__v0 = 0;
    CData/*0:0*/ __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_weights__v0;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_weights__v0 = 0;
    CData/*2:0*/ __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_weights__v1;
    __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_weights__v1 = 0;
    CData/*2:0*/ __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_weights__v1;
    __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_weights__v1 = 0;
    CData/*0:0*/ __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_weights__v1;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_weights__v1 = 0;
    SData/*15:0*/ __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__Q__v0;
    __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__Q__v0 = 0;
    CData/*1:0*/ __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__Q__v0;
    __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__Q__v0 = 0;
    CData/*2:0*/ __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__Q__v0;
    __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__Q__v0 = 0;
    CData/*0:0*/ __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__Q__v0;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__Q__v0 = 0;
    SData/*15:0*/ __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__K__v0;
    __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__K__v0 = 0;
    CData/*1:0*/ __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__K__v0;
    __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__K__v0 = 0;
    CData/*2:0*/ __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__K__v0;
    __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__K__v0 = 0;
    CData/*0:0*/ __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__K__v0;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__K__v0 = 0;
    SData/*15:0*/ __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__V__v0;
    __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__V__v0 = 0;
    CData/*1:0*/ __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__V__v0;
    __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__V__v0 = 0;
    CData/*2:0*/ __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__V__v0;
    __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__V__v0 = 0;
    CData/*0:0*/ __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__V__v0;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__V__v0 = 0;
    SData/*15:0*/ __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_scores__v0;
    __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_scores__v0 = 0;
    CData/*2:0*/ __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_scores__v0;
    __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_scores__v0 = 0;
    CData/*2:0*/ __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_scores__v0;
    __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_scores__v0 = 0;
    CData/*0:0*/ __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_scores__v0;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_scores__v0 = 0;
    CData/*2:0*/ __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_scores__v1;
    __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_scores__v1 = 0;
    CData/*2:0*/ __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_scores__v1;
    __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_scores__v1 = 0;
    CData/*0:0*/ __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_scores__v1;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_scores__v1 = 0;
    SData/*15:0*/ __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__3__KET____DOT__head__output_data__v0;
    __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__3__KET____DOT__head__output_data__v0 = 0;
    CData/*1:0*/ __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__3__KET____DOT__head__output_data__v0;
    __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__3__KET____DOT__head__output_data__v0 = 0;
    CData/*2:0*/ __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__3__KET____DOT__head__output_data__v0;
    __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__3__KET____DOT__head__output_data__v0 = 0;
    CData/*0:0*/ __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__3__KET____DOT__head__output_data__v0;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__3__KET____DOT__head__output_data__v0 = 0;
    SData/*15:0*/ __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__temp_exp__v0;
    __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__temp_exp__v0 = 0;
    CData/*2:0*/ __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__temp_exp__v0;
    __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__temp_exp__v0 = 0;
    CData/*0:0*/ __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__temp_exp__v0;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__temp_exp__v0 = 0;
    SData/*15:0*/ __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_weights__v0;
    __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_weights__v0 = 0;
    CData/*2:0*/ __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_weights__v0;
    __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_weights__v0 = 0;
    CData/*2:0*/ __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_weights__v0;
    __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_weights__v0 = 0;
    CData/*0:0*/ __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_weights__v0;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_weights__v0 = 0;
    CData/*2:0*/ __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_weights__v1;
    __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_weights__v1 = 0;
    CData/*2:0*/ __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_weights__v1;
    __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_weights__v1 = 0;
    CData/*0:0*/ __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_weights__v1;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_weights__v1 = 0;
    SData/*15:0*/ __VdlyVal__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__sum_data__v0;
    __VdlyVal__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__sum_data__v0 = 0;
    CData/*3:0*/ __VdlyDim0__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__sum_data__v0;
    __VdlyDim0__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__sum_data__v0 = 0;
    CData/*2:0*/ __VdlyDim1__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__sum_data__v0;
    __VdlyDim1__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__sum_data__v0 = 0;
    CData/*0:0*/ __VdlySet__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__sum_data__v0;
    __VdlySet__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__sum_data__v0 = 0;
    SData/*15:0*/ __VdlyVal__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__mean_val__v0;
    __VdlyVal__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__mean_val__v0 = 0;
    CData/*2:0*/ __VdlyDim0__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__mean_val__v0;
    __VdlyDim0__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__mean_val__v0 = 0;
    CData/*0:0*/ __VdlySet__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__mean_val__v0;
    __VdlySet__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__mean_val__v0 = 0;
    SData/*15:0*/ __VdlyVal__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__std_val__v0;
    __VdlyVal__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__std_val__v0 = 0;
    CData/*2:0*/ __VdlyDim0__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__std_val__v0;
    __VdlyDim0__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__std_val__v0 = 0;
    CData/*0:0*/ __VdlySet__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__std_val__v0;
    __VdlySet__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__std_val__v0 = 0;
    SData/*15:0*/ __VdlyVal__complete_transformer_decoder__DOT__norm1_out__v0;
    __VdlyVal__complete_transformer_decoder__DOT__norm1_out__v0 = 0;
    CData/*3:0*/ __VdlyDim0__complete_transformer_decoder__DOT__norm1_out__v0;
    __VdlyDim0__complete_transformer_decoder__DOT__norm1_out__v0 = 0;
    CData/*2:0*/ __VdlyDim1__complete_transformer_decoder__DOT__norm1_out__v0;
    __VdlyDim1__complete_transformer_decoder__DOT__norm1_out__v0 = 0;
    CData/*0:0*/ __VdlySet__complete_transformer_decoder__DOT__norm1_out__v0;
    __VdlySet__complete_transformer_decoder__DOT__norm1_out__v0 = 0;
    SData/*15:0*/ __VdlyVal__complete_transformer_decoder__DOT__ffn_inst__DOT__hidden_data__v0;
    __VdlyVal__complete_transformer_decoder__DOT__ffn_inst__DOT__hidden_data__v0 = 0;
    CData/*4:0*/ __VdlyDim0__complete_transformer_decoder__DOT__ffn_inst__DOT__hidden_data__v0;
    __VdlyDim0__complete_transformer_decoder__DOT__ffn_inst__DOT__hidden_data__v0 = 0;
    CData/*2:0*/ __VdlyDim1__complete_transformer_decoder__DOT__ffn_inst__DOT__hidden_data__v0;
    __VdlyDim1__complete_transformer_decoder__DOT__ffn_inst__DOT__hidden_data__v0 = 0;
    CData/*0:0*/ __VdlySet__complete_transformer_decoder__DOT__ffn_inst__DOT__hidden_data__v0;
    __VdlySet__complete_transformer_decoder__DOT__ffn_inst__DOT__hidden_data__v0 = 0;
    SData/*15:0*/ __VdlyVal__complete_transformer_decoder__DOT__ffn_out__v0;
    __VdlyVal__complete_transformer_decoder__DOT__ffn_out__v0 = 0;
    CData/*3:0*/ __VdlyDim0__complete_transformer_decoder__DOT__ffn_out__v0;
    __VdlyDim0__complete_transformer_decoder__DOT__ffn_out__v0 = 0;
    CData/*2:0*/ __VdlyDim1__complete_transformer_decoder__DOT__ffn_out__v0;
    __VdlyDim1__complete_transformer_decoder__DOT__ffn_out__v0 = 0;
    CData/*0:0*/ __VdlySet__complete_transformer_decoder__DOT__ffn_out__v0;
    __VdlySet__complete_transformer_decoder__DOT__ffn_out__v0 = 0;
    SData/*15:0*/ __VdlyVal__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__sum_data__v0;
    __VdlyVal__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__sum_data__v0 = 0;
    CData/*3:0*/ __VdlyDim0__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__sum_data__v0;
    __VdlyDim0__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__sum_data__v0 = 0;
    CData/*2:0*/ __VdlyDim1__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__sum_data__v0;
    __VdlyDim1__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__sum_data__v0 = 0;
    CData/*0:0*/ __VdlySet__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__sum_data__v0;
    __VdlySet__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__sum_data__v0 = 0;
    SData/*15:0*/ __VdlyVal__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__mean_val__v0;
    __VdlyVal__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__mean_val__v0 = 0;
    CData/*2:0*/ __VdlyDim0__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__mean_val__v0;
    __VdlyDim0__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__mean_val__v0 = 0;
    CData/*0:0*/ __VdlySet__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__mean_val__v0;
    __VdlySet__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__mean_val__v0 = 0;
    SData/*15:0*/ __VdlyVal__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__std_val__v0;
    __VdlyVal__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__std_val__v0 = 0;
    CData/*2:0*/ __VdlyDim0__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__std_val__v0;
    __VdlyDim0__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__std_val__v0 = 0;
    CData/*0:0*/ __VdlySet__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__std_val__v0;
    __VdlySet__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__std_val__v0 = 0;
    SData/*15:0*/ __VdlyVal__complete_transformer_decoder__DOT__norm2_out__v0;
    __VdlyVal__complete_transformer_decoder__DOT__norm2_out__v0 = 0;
    CData/*3:0*/ __VdlyDim0__complete_transformer_decoder__DOT__norm2_out__v0;
    __VdlyDim0__complete_transformer_decoder__DOT__norm2_out__v0 = 0;
    CData/*2:0*/ __VdlyDim1__complete_transformer_decoder__DOT__norm2_out__v0;
    __VdlyDim1__complete_transformer_decoder__DOT__norm2_out__v0 = 0;
    CData/*0:0*/ __VdlySet__complete_transformer_decoder__DOT__norm2_out__v0;
    __VdlySet__complete_transformer_decoder__DOT__norm2_out__v0 = 0;
    SData/*15:0*/ __VdlyVal__complete_transformer_decoder__DOT__final_logits__v0;
    __VdlyVal__complete_transformer_decoder__DOT__final_logits__v0 = 0;
    CData/*5:0*/ __VdlyDim0__complete_transformer_decoder__DOT__final_logits__v0;
    __VdlyDim0__complete_transformer_decoder__DOT__final_logits__v0 = 0;
    CData/*0:0*/ __VdlySet__complete_transformer_decoder__DOT__final_logits__v0;
    __VdlySet__complete_transformer_decoder__DOT__final_logits__v0 = 0;
    // Body
    __Vdly__complete_transformer_decoder__DOT__argmax_inst__DOT__state 
        = vlSelfRef.complete_transformer_decoder__DOT__argmax_inst__DOT__state;
    __Vdly__complete_transformer_decoder__DOT__argmax_inst__DOT__current_idx 
        = vlSelfRef.complete_transformer_decoder__DOT__argmax_inst__DOT__current_idx;
    __Vdly__complete_transformer_decoder__DOT__argmax_inst__DOT__max_value 
        = vlSelfRef.complete_transformer_decoder__DOT__argmax_inst__DOT__max_value;
    __Vdly__complete_transformer_decoder__DOT__argmax_inst__DOT__max_index 
        = vlSelfRef.complete_transformer_decoder__DOT__argmax_inst__DOT__max_index;
    __Vdly__complete_transformer_decoder__DOT__embedding_inst__DOT__state 
        = vlSelfRef.complete_transformer_decoder__DOT__embedding_inst__DOT__state;
    __Vdly__complete_transformer_decoder__DOT__embedding_inst__DOT__pipe_stage 
        = vlSelfRef.complete_transformer_decoder__DOT__embedding_inst__DOT__pipe_stage;
    __VdlySet__complete_transformer_decoder__DOT__embedded_tokens__v0 = 0U;
    __Vdly__complete_transformer_decoder__DOT__embedding_inst__DOT__seq_idx 
        = vlSelfRef.complete_transformer_decoder__DOT__embedding_inst__DOT__seq_idx;
    __Vdly__complete_transformer_decoder__DOT__embedding_inst__DOT__dim_idx 
        = vlSelfRef.complete_transformer_decoder__DOT__embedding_inst__DOT__dim_idx;
    __Vdly__complete_transformer_decoder__DOT__projection_inst__DOT__state 
        = vlSelfRef.complete_transformer_decoder__DOT__projection_inst__DOT__state;
    __Vdly__complete_transformer_decoder__DOT__projection_inst__DOT__logit_accumulator 
        = vlSelfRef.complete_transformer_decoder__DOT__projection_inst__DOT__logit_accumulator;
    __Vdly__complete_transformer_decoder__DOT__projection_inst__DOT__pipe_stage 
        = vlSelfRef.complete_transformer_decoder__DOT__projection_inst__DOT__pipe_stage;
    __VdlySet__complete_transformer_decoder__DOT__final_logits__v0 = 0U;
    __Vdly__complete_transformer_decoder__DOT__projection_inst__DOT__vocab_idx 
        = vlSelfRef.complete_transformer_decoder__DOT__projection_inst__DOT__vocab_idx;
    __Vdly__complete_transformer_decoder__DOT__projection_inst__DOT__dim_idx 
        = vlSelfRef.complete_transformer_decoder__DOT__projection_inst__DOT__dim_idx;
    __Vdly__complete_transformer_decoder__DOT__positional_inst__DOT__state 
        = vlSelfRef.complete_transformer_decoder__DOT__positional_inst__DOT__state;
    __Vdly__complete_transformer_decoder__DOT__positional_inst__DOT__seq_idx 
        = vlSelfRef.complete_transformer_decoder__DOT__positional_inst__DOT__seq_idx;
    __Vdly__complete_transformer_decoder__DOT__positional_inst__DOT__dim_idx 
        = vlSelfRef.complete_transformer_decoder__DOT__positional_inst__DOT__dim_idx;
    __Vdly__complete_transformer_decoder__DOT__positional_inst__DOT__pipe_stage 
        = vlSelfRef.complete_transformer_decoder__DOT__positional_inst__DOT__pipe_stage;
    __Vdly__complete_transformer_decoder__DOT__positional_inst__DOT__temp_sum 
        = vlSelfRef.complete_transformer_decoder__DOT__positional_inst__DOT__temp_sum;
    __VdlySet__complete_transformer_decoder__DOT__position_encoded__v0 = 0U;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__state 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__state;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__row_idx 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__row_idx;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__col_idx 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__col_idx;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__max_val 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__max_val;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__exp_sum 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__exp_sum;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__state 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__state;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__row_idx 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__row_idx;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__col_idx 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__col_idx;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__max_val 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__max_val;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__exp_sum 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__exp_sum;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__state 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__state;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__row_idx 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__row_idx;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__col_idx 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__col_idx;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__max_val 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__max_val;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__exp_sum 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__exp_sum;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__state 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__state;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__row_idx 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__row_idx;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__col_idx 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__col_idx;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__max_val 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__max_val;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__exp_sum 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__exp_sum;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__temp_exp__v0 = 0U;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__temp_exp__v0 = 0U;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__temp_exp__v0 = 0U;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__temp_exp__v0 = 0U;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_weights__v0 = 0U;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_weights__v1 = 0U;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_weights__v0 = 0U;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_weights__v1 = 0U;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_weights__v0 = 0U;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_weights__v1 = 0U;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_weights__v0 = 0U;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_weights__v1 = 0U;
    __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__state 
        = vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__state;
    __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__seq_idx 
        = vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__seq_idx;
    __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__dim_idx 
        = vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__dim_idx;
    __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__mean_acc 
        = vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__mean_acc;
    __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__var_acc 
        = vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__var_acc;
    __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__pipe_stage 
        = vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__pipe_stage;
    __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__temp_sum 
        = vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__temp_sum;
    __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__diff 
        = vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__diff;
    __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__diff_sq 
        = vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__diff_sq;
    __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__normalized 
        = vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__normalized;
    __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__with_gamma 
        = vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__with_gamma;
    __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__final_result 
        = vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__final_result;
    __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__variance 
        = vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__variance;
    __VdlySet__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__mean_val__v0 = 0U;
    __VdlySet__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__std_val__v0 = 0U;
    __VdlySet__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__sum_data__v0 = 0U;
    __VdlySet__complete_transformer_decoder__DOT__norm1_out__v0 = 0U;
    __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__state 
        = vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__state;
    __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__seq_idx 
        = vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__seq_idx;
    __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__dim_idx 
        = vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__dim_idx;
    __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__mean_acc 
        = vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__mean_acc;
    __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__var_acc 
        = vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__var_acc;
    __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__pipe_stage 
        = vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__pipe_stage;
    __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__temp_sum 
        = vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__temp_sum;
    __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__diff 
        = vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__diff;
    __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__diff_sq 
        = vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__diff_sq;
    __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__normalized 
        = vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__normalized;
    __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__with_gamma 
        = vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__with_gamma;
    __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__final_result 
        = vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__final_result;
    __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__variance 
        = vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__variance;
    __VdlySet__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__mean_val__v0 = 0U;
    __VdlySet__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__std_val__v0 = 0U;
    __VdlySet__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__sum_data__v0 = 0U;
    __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__state 
        = vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__state;
    __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__seq_idx 
        = vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__seq_idx;
    __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__in_dim 
        = vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__in_dim;
    __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__out_dim 
        = vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__out_dim;
    __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__hidden_dim 
        = vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__hidden_dim;
    __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__accumulator 
        = vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__accumulator;
    __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__pipe_stage 
        = vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__pipe_stage;
    __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__with_bias 
        = vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__with_bias;
    __VdlySet__complete_transformer_decoder__DOT__norm2_out__v0 = 0U;
    __VdlySet__complete_transformer_decoder__DOT__ffn_inst__DOT__hidden_data__v0 = 0U;
    __VdlySet__complete_transformer_decoder__DOT__ffn_out__v0 = 0U;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__state 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__state;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx2 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx2;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__pipe_stage 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__pipe_stage;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__accumulator 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__accumulator;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_start 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_start;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__state 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__state;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx2 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx2;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__pipe_stage 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__pipe_stage;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__accumulator 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__accumulator;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_start 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_start;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__state 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__state;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx2 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx2;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__pipe_stage 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__pipe_stage;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__accumulator 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__accumulator;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_start 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_start;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__state 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__state;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx2 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx2;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__pipe_stage 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__pipe_stage;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__accumulator 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__accumulator;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_start 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_start;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__Q__v0 = 0U;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__K__v0 = 0U;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__V__v0 = 0U;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__Q__v0 = 0U;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__K__v0 = 0U;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__V__v0 = 0U;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__Q__v0 = 0U;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__K__v0 = 0U;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__V__v0 = 0U;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__Q__v0 = 0U;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__K__v0 = 0U;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__V__v0 = 0U;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__embed_idx 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__embed_idx;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__head_idx 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__head_idx;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__embed_idx 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__embed_idx;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__head_idx 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__head_idx;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__embed_idx 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__embed_idx;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__head_idx 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__head_idx;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__embed_idx 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__embed_idx;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__head_idx 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__head_idx;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_scores__v0 = 0U;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_scores__v1 = 0U;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_scores__v0 = 0U;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_scores__v1 = 0U;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_scores__v0 = 0U;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_scores__v1 = 0U;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_scores__v0 = 0U;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_scores__v1 = 0U;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__0__KET____DOT__head__output_data__v0 = 0U;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__1__KET____DOT__head__output_data__v0 = 0U;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__2__KET____DOT__head__output_data__v0 = 0U;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__3__KET____DOT__head__output_data__v0 = 0U;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__state 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__state;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__head_start_signals 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_start_signals;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__seq_idx 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__seq_idx;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__dim_idx 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__dim_idx;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__in_dim 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__in_dim;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__out_dim 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__out_dim;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__pipe_stage 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__pipe_stage;
    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__proj_accumulator 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__proj_accumulator;
    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__concatenated__v0 = 0U;
    __VdlySet__complete_transformer_decoder__DOT__attention_out__v0 = 0U;
    __Vdly__complete_transformer_decoder__DOT__embed_start 
        = vlSelfRef.complete_transformer_decoder__DOT__embed_start;
    __Vdly__complete_transformer_decoder__DOT__pos_start 
        = vlSelfRef.complete_transformer_decoder__DOT__pos_start;
    __Vdly__complete_transformer_decoder__DOT__attn_start 
        = vlSelfRef.complete_transformer_decoder__DOT__attn_start;
    __Vdly__complete_transformer_decoder__DOT__norm1_start 
        = vlSelfRef.complete_transformer_decoder__DOT__norm1_start;
    __Vdly__complete_transformer_decoder__DOT__ffn_start 
        = vlSelfRef.complete_transformer_decoder__DOT__ffn_start;
    __Vdly__complete_transformer_decoder__DOT__norm2_start 
        = vlSelfRef.complete_transformer_decoder__DOT__norm2_start;
    __Vdly__complete_transformer_decoder__DOT__proj_start 
        = vlSelfRef.complete_transformer_decoder__DOT__proj_start;
    __Vdly__complete_transformer_decoder__DOT__argmax_start 
        = vlSelfRef.complete_transformer_decoder__DOT__argmax_start;
    __Vdly__complete_transformer_decoder__DOT__current_state 
        = vlSelfRef.complete_transformer_decoder__DOT__current_state;
    if (vlSelfRef.rst) {
        vlSelfRef.cycle_count = 0U;
        __Vdly__complete_transformer_decoder__DOT__current_state = 0U;
        vlSelfRef.done = 0U;
        vlSelfRef.valid = 0U;
        __Vdly__complete_transformer_decoder__DOT__embed_start = 0U;
        __Vdly__complete_transformer_decoder__DOT__pos_start = 0U;
        __Vdly__complete_transformer_decoder__DOT__attn_start = 0U;
        __Vdly__complete_transformer_decoder__DOT__norm1_start = 0U;
        __Vdly__complete_transformer_decoder__DOT__ffn_start = 0U;
        __Vdly__complete_transformer_decoder__DOT__norm2_start = 0U;
        __Vdly__complete_transformer_decoder__DOT__proj_start = 0U;
        __Vdly__complete_transformer_decoder__DOT__argmax_start = 0U;
        vlSelfRef.complete_transformer_decoder__DOT__current_state 
            = __Vdly__complete_transformer_decoder__DOT__current_state;
        vlSelfRef.current_state_debug = vlSelfRef.complete_transformer_decoder__DOT__current_state;
        __Vdly__complete_transformer_decoder__DOT__argmax_inst__DOT__state = 0U;
        __Vdly__complete_transformer_decoder__DOT__argmax_inst__DOT__current_idx = 0U;
        __Vdly__complete_transformer_decoder__DOT__argmax_inst__DOT__max_value = 0x8000U;
        __Vdly__complete_transformer_decoder__DOT__argmax_inst__DOT__max_index = 0U;
        vlSelfRef.predicted_token = 0U;
        vlSelfRef.complete_transformer_decoder__DOT__argmax_done = 0U;
        vlSelfRef.complete_transformer_decoder__DOT__argmax_valid = 0U;
        vlSelfRef.complete_transformer_decoder__DOT__argmax_start 
            = __Vdly__complete_transformer_decoder__DOT__argmax_start;
        vlSelfRef.complete_transformer_decoder__DOT__argmax_inst__DOT__state 
            = __Vdly__complete_transformer_decoder__DOT__argmax_inst__DOT__state;
        vlSelfRef.complete_transformer_decoder__DOT__argmax_inst__DOT__current_idx 
            = __Vdly__complete_transformer_decoder__DOT__argmax_inst__DOT__current_idx;
        vlSelfRef.complete_transformer_decoder__DOT__argmax_inst__DOT__max_value 
            = __Vdly__complete_transformer_decoder__DOT__argmax_inst__DOT__max_value;
        vlSelfRef.complete_transformer_decoder__DOT__argmax_inst__DOT__max_index 
            = __Vdly__complete_transformer_decoder__DOT__argmax_inst__DOT__max_index;
        __Vdly__complete_transformer_decoder__DOT__embedding_inst__DOT__state = 0U;
        __Vdly__complete_transformer_decoder__DOT__embedding_inst__DOT__seq_idx = 0U;
        __Vdly__complete_transformer_decoder__DOT__embedding_inst__DOT__dim_idx = 0U;
        __Vdly__complete_transformer_decoder__DOT__embedding_inst__DOT__pipe_stage = 0U;
        vlSelfRef.complete_transformer_decoder__DOT__embed_done = 0U;
        vlSelfRef.complete_transformer_decoder__DOT__embed_valid = 0U;
        vlSelfRef.complete_transformer_decoder__DOT__embed_start 
            = __Vdly__complete_transformer_decoder__DOT__embed_start;
        vlSelfRef.complete_transformer_decoder__DOT__embedding_inst__DOT__pipe_stage 
            = __Vdly__complete_transformer_decoder__DOT__embedding_inst__DOT__pipe_stage;
        vlSelfRef.complete_transformer_decoder__DOT__embedding_inst__DOT__seq_idx 
            = __Vdly__complete_transformer_decoder__DOT__embedding_inst__DOT__seq_idx;
        vlSelfRef.complete_transformer_decoder__DOT__embedding_inst__DOT__dim_idx 
            = __Vdly__complete_transformer_decoder__DOT__embedding_inst__DOT__dim_idx;
        __Vdly__complete_transformer_decoder__DOT__projection_inst__DOT__state = 0U;
        __Vdly__complete_transformer_decoder__DOT__projection_inst__DOT__vocab_idx = 0U;
        __Vdly__complete_transformer_decoder__DOT__projection_inst__DOT__dim_idx = 0U;
        __Vdly__complete_transformer_decoder__DOT__projection_inst__DOT__logit_accumulator = 0U;
        __Vdly__complete_transformer_decoder__DOT__projection_inst__DOT__pipe_stage = 0U;
        vlSelfRef.complete_transformer_decoder__DOT__proj_done = 0U;
        vlSelfRef.complete_transformer_decoder__DOT__proj_valid = 0U;
    } else {
        vlSelfRef.cycle_count = ((IData)(1U) + vlSelfRef.cycle_count);
        __Vdly__complete_transformer_decoder__DOT__embed_start = 0U;
        __Vdly__complete_transformer_decoder__DOT__pos_start = 0U;
        __Vdly__complete_transformer_decoder__DOT__attn_start = 0U;
        __Vdly__complete_transformer_decoder__DOT__norm1_start = 0U;
        __Vdly__complete_transformer_decoder__DOT__ffn_start = 0U;
        __Vdly__complete_transformer_decoder__DOT__norm2_start = 0U;
        __Vdly__complete_transformer_decoder__DOT__proj_start = 0U;
        __Vdly__complete_transformer_decoder__DOT__argmax_start = 0U;
        if (((((((((0U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__current_state)) 
                   | (1U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__current_state))) 
                  | (2U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__current_state))) 
                 | (3U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__current_state))) 
                | (4U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__current_state))) 
               | (5U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__current_state))) 
              | (6U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__current_state))) 
             | (7U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__current_state)))) {
            if ((0U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__current_state))) {
                vlSelfRef.done = 0U;
                vlSelfRef.valid = 0U;
                if (vlSelfRef.start) {
                    __Vdly__complete_transformer_decoder__DOT__current_state = 1U;
                    __Vdly__complete_transformer_decoder__DOT__embed_start = 1U;
                }
            } else if ((1U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__current_state))) {
                if (((IData)(vlSelfRef.complete_transformer_decoder__DOT__embed_done) 
                     & (IData)(vlSelfRef.complete_transformer_decoder__DOT__embed_valid))) {
                    __Vdly__complete_transformer_decoder__DOT__current_state = 2U;
                    __Vdly__complete_transformer_decoder__DOT__pos_start = 1U;
                }
            } else if ((2U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__current_state))) {
                if (((IData)(vlSelfRef.complete_transformer_decoder__DOT__pos_done) 
                     & (IData)(vlSelfRef.complete_transformer_decoder__DOT__pos_valid))) {
                    __Vdly__complete_transformer_decoder__DOT__current_state = 3U;
                    __Vdly__complete_transformer_decoder__DOT__attn_start = 1U;
                }
            } else if ((3U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__current_state))) {
                if (((IData)(vlSelfRef.complete_transformer_decoder__DOT__attn_done) 
                     & (IData)(vlSelfRef.complete_transformer_decoder__DOT__attn_valid))) {
                    __Vdly__complete_transformer_decoder__DOT__current_state = 4U;
                    __Vdly__complete_transformer_decoder__DOT__norm1_start = 1U;
                }
            } else if ((4U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__current_state))) {
                if (((IData)(vlSelfRef.complete_transformer_decoder__DOT__norm1_done) 
                     & (IData)(vlSelfRef.complete_transformer_decoder__DOT__norm1_valid))) {
                    __Vdly__complete_transformer_decoder__DOT__current_state = 5U;
                    __Vdly__complete_transformer_decoder__DOT__ffn_start = 1U;
                }
            } else if ((5U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__current_state))) {
                if (((IData)(vlSelfRef.complete_transformer_decoder__DOT__ffn_done) 
                     & (IData)(vlSelfRef.complete_transformer_decoder__DOT__ffn_valid))) {
                    __Vdly__complete_transformer_decoder__DOT__current_state = 6U;
                    __Vdly__complete_transformer_decoder__DOT__norm2_start = 1U;
                }
            } else if ((6U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__current_state))) {
                if (((IData)(vlSelfRef.complete_transformer_decoder__DOT__norm2_done) 
                     & (IData)(vlSelfRef.complete_transformer_decoder__DOT__norm2_valid))) {
                    __Vdly__complete_transformer_decoder__DOT__current_state = 7U;
                    __Vdly__complete_transformer_decoder__DOT__proj_start = 1U;
                }
            } else if (((IData)(vlSelfRef.complete_transformer_decoder__DOT__proj_done) 
                        & (IData)(vlSelfRef.complete_transformer_decoder__DOT__proj_valid))) {
                __Vdly__complete_transformer_decoder__DOT__current_state = 8U;
                __Vdly__complete_transformer_decoder__DOT__argmax_start = 1U;
            }
        } else if ((8U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__current_state))) {
            if (((IData)(vlSelfRef.complete_transformer_decoder__DOT__argmax_done) 
                 & (IData)(vlSelfRef.complete_transformer_decoder__DOT__argmax_valid))) {
                __Vdly__complete_transformer_decoder__DOT__current_state = 9U;
            }
        } else if ((9U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__current_state))) {
            vlSelfRef.done = 1U;
            vlSelfRef.valid = 1U;
            if ((1U & (~ (IData)(vlSelfRef.start)))) {
                __Vdly__complete_transformer_decoder__DOT__current_state = 0U;
            }
        }
        vlSelfRef.complete_transformer_decoder__DOT__current_state 
            = __Vdly__complete_transformer_decoder__DOT__current_state;
        vlSelfRef.current_state_debug = vlSelfRef.complete_transformer_decoder__DOT__current_state;
        if ((0U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__argmax_inst__DOT__state))) {
            vlSelfRef.complete_transformer_decoder__DOT__argmax_done = 0U;
            vlSelfRef.complete_transformer_decoder__DOT__argmax_valid = 0U;
            if (vlSelfRef.complete_transformer_decoder__DOT__argmax_start) {
                __Vdly__complete_transformer_decoder__DOT__argmax_inst__DOT__state = 1U;
                __Vdly__complete_transformer_decoder__DOT__argmax_inst__DOT__current_idx = 0U;
                __Vdly__complete_transformer_decoder__DOT__argmax_inst__DOT__max_value 
                    = vlSelfRef.complete_transformer_decoder__DOT__final_logits[0U];
                __Vdly__complete_transformer_decoder__DOT__argmax_inst__DOT__max_index = 0U;
            }
        } else if ((1U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__argmax_inst__DOT__state))) {
            if (VL_GTS_III(16, ((0x27U >= (IData)(vlSelfRef.complete_transformer_decoder__DOT__argmax_inst__DOT__current_idx))
                                 ? vlSelfRef.complete_transformer_decoder__DOT__final_logits
                                [vlSelfRef.complete_transformer_decoder__DOT__argmax_inst__DOT__current_idx]
                                 : 0U), (IData)(vlSelfRef.complete_transformer_decoder__DOT__argmax_inst__DOT__max_value))) {
                __Vdly__complete_transformer_decoder__DOT__argmax_inst__DOT__max_value 
                    = ((0x27U >= (IData)(vlSelfRef.complete_transformer_decoder__DOT__argmax_inst__DOT__current_idx))
                        ? vlSelfRef.complete_transformer_decoder__DOT__final_logits
                       [vlSelfRef.complete_transformer_decoder__DOT__argmax_inst__DOT__current_idx]
                        : 0U);
                __Vdly__complete_transformer_decoder__DOT__argmax_inst__DOT__max_index 
                    = vlSelfRef.complete_transformer_decoder__DOT__argmax_inst__DOT__current_idx;
            }
            if ((0x27U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__argmax_inst__DOT__current_idx))) {
                vlSelfRef.predicted_token = vlSelfRef.complete_transformer_decoder__DOT__argmax_inst__DOT__max_index;
                __Vdly__complete_transformer_decoder__DOT__argmax_inst__DOT__state = 2U;
            } else {
                __Vdly__complete_transformer_decoder__DOT__argmax_inst__DOT__current_idx 
                    = (0x0000003fU & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__argmax_inst__DOT__current_idx)));
            }
        } else if ((2U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__argmax_inst__DOT__state))) {
            vlSelfRef.complete_transformer_decoder__DOT__argmax_done = 1U;
            vlSelfRef.complete_transformer_decoder__DOT__argmax_valid = 1U;
            if ((1U & (~ (IData)(vlSelfRef.complete_transformer_decoder__DOT__argmax_start)))) {
                __Vdly__complete_transformer_decoder__DOT__argmax_inst__DOT__state = 0U;
            }
        }
        vlSelfRef.complete_transformer_decoder__DOT__argmax_start 
            = __Vdly__complete_transformer_decoder__DOT__argmax_start;
        vlSelfRef.complete_transformer_decoder__DOT__argmax_inst__DOT__state 
            = __Vdly__complete_transformer_decoder__DOT__argmax_inst__DOT__state;
        vlSelfRef.complete_transformer_decoder__DOT__argmax_inst__DOT__current_idx 
            = __Vdly__complete_transformer_decoder__DOT__argmax_inst__DOT__current_idx;
        vlSelfRef.complete_transformer_decoder__DOT__argmax_inst__DOT__max_value 
            = __Vdly__complete_transformer_decoder__DOT__argmax_inst__DOT__max_value;
        vlSelfRef.complete_transformer_decoder__DOT__argmax_inst__DOT__max_index 
            = __Vdly__complete_transformer_decoder__DOT__argmax_inst__DOT__max_index;
        if ((0U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__embedding_inst__DOT__state))) {
            vlSelfRef.complete_transformer_decoder__DOT__embed_done = 0U;
            vlSelfRef.complete_transformer_decoder__DOT__embed_valid = 0U;
            if (vlSelfRef.complete_transformer_decoder__DOT__embed_start) {
                __Vdly__complete_transformer_decoder__DOT__embedding_inst__DOT__state = 1U;
                __Vdly__complete_transformer_decoder__DOT__embedding_inst__DOT__seq_idx = 0U;
                __Vdly__complete_transformer_decoder__DOT__embedding_inst__DOT__dim_idx = 0U;
                __Vdly__complete_transformer_decoder__DOT__embedding_inst__DOT__pipe_stage = 0U;
            }
        } else if ((1U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__embedding_inst__DOT__state))) {
            __Vdly__complete_transformer_decoder__DOT__embedding_inst__DOT__pipe_stage 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__embedding_inst__DOT__pipe_stage)));
            if ((2U <= (IData)(vlSelfRef.complete_transformer_decoder__DOT__embedding_inst__DOT__pipe_stage))) {
                __VdlyVal__complete_transformer_decoder__DOT__embedded_tokens__v0 
                    = vlSelfRef.complete_transformer_decoder__DOT__embedding_inst__DOT__embed_data;
                __VdlyDim0__complete_transformer_decoder__DOT__embedded_tokens__v0 
                    = vlSelfRef.complete_transformer_decoder__DOT__embedding_inst__DOT__dim_idx;
                __VdlyDim1__complete_transformer_decoder__DOT__embedded_tokens__v0 
                    = vlSelfRef.complete_transformer_decoder__DOT__embedding_inst__DOT__seq_idx;
                __VdlySet__complete_transformer_decoder__DOT__embedded_tokens__v0 = 1U;
                __Vdly__complete_transformer_decoder__DOT__embedding_inst__DOT__pipe_stage = 0U;
                if ((0x0fU == (IData)(vlSelfRef.complete_transformer_decoder__DOT__embedding_inst__DOT__dim_idx))) {
                    __Vdly__complete_transformer_decoder__DOT__embedding_inst__DOT__dim_idx = 0U;
                    if ((7U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__embedding_inst__DOT__seq_idx))) {
                        __Vdly__complete_transformer_decoder__DOT__embedding_inst__DOT__state = 2U;
                    } else {
                        __Vdly__complete_transformer_decoder__DOT__embedding_inst__DOT__seq_idx 
                            = (7U & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__embedding_inst__DOT__seq_idx)));
                    }
                } else {
                    __Vdly__complete_transformer_decoder__DOT__embedding_inst__DOT__dim_idx 
                        = (0x0000000fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.complete_transformer_decoder__DOT__embedding_inst__DOT__dim_idx)));
                }
            }
        } else if ((2U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__embedding_inst__DOT__state))) {
            vlSelfRef.complete_transformer_decoder__DOT__embed_done = 1U;
            vlSelfRef.complete_transformer_decoder__DOT__embed_valid = 1U;
            if ((1U & (~ (IData)(vlSelfRef.complete_transformer_decoder__DOT__embed_start)))) {
                __Vdly__complete_transformer_decoder__DOT__embedding_inst__DOT__state = 0U;
            }
        }
        vlSelfRef.complete_transformer_decoder__DOT__embed_start 
            = __Vdly__complete_transformer_decoder__DOT__embed_start;
        vlSelfRef.complete_transformer_decoder__DOT__embedding_inst__DOT__pipe_stage 
            = __Vdly__complete_transformer_decoder__DOT__embedding_inst__DOT__pipe_stage;
        vlSelfRef.complete_transformer_decoder__DOT__embedding_inst__DOT__seq_idx 
            = __Vdly__complete_transformer_decoder__DOT__embedding_inst__DOT__seq_idx;
        vlSelfRef.complete_transformer_decoder__DOT__embedding_inst__DOT__dim_idx 
            = __Vdly__complete_transformer_decoder__DOT__embedding_inst__DOT__dim_idx;
        if ((0U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__projection_inst__DOT__state))) {
            vlSelfRef.complete_transformer_decoder__DOT__proj_done = 0U;
            vlSelfRef.complete_transformer_decoder__DOT__proj_valid = 0U;
            if (vlSelfRef.complete_transformer_decoder__DOT__proj_start) {
                __Vdly__complete_transformer_decoder__DOT__projection_inst__DOT__state = 1U;
                __Vdly__complete_transformer_decoder__DOT__projection_inst__DOT__vocab_idx = 0U;
                __Vdly__complete_transformer_decoder__DOT__projection_inst__DOT__dim_idx = 0U;
                __Vdly__complete_transformer_decoder__DOT__projection_inst__DOT__logit_accumulator = 0U;
                __Vdly__complete_transformer_decoder__DOT__projection_inst__DOT__pipe_stage = 0U;
            }
        } else if ((1U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__projection_inst__DOT__state))) {
            __Vdly__complete_transformer_decoder__DOT__projection_inst__DOT__pipe_stage 
                = (7U & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__projection_inst__DOT__pipe_stage)));
            if ((2U <= (IData)(vlSelfRef.complete_transformer_decoder__DOT__projection_inst__DOT__pipe_stage))) {
                __Vdly__complete_transformer_decoder__DOT__projection_inst__DOT__logit_accumulator 
                    = (vlSelfRef.complete_transformer_decoder__DOT__projection_inst__DOT__logit_accumulator 
                       + VL_MULS_III(32, VL_EXTENDS_II(32,16, vlSelfRef.complete_transformer_decoder__DOT____Vcellinp__projection_inst__final_hidden_state
                                                       [vlSelfRef.complete_transformer_decoder__DOT__projection_inst__DOT__dim_idx]), 
                                     VL_EXTENDS_II(32,16, (IData)(vlSelfRef.complete_transformer_decoder__DOT__projection_inst__DOT__proj_data))));
                __Vdly__complete_transformer_decoder__DOT__projection_inst__DOT__pipe_stage = 0U;
                if ((0x0fU == (IData)(vlSelfRef.complete_transformer_decoder__DOT__projection_inst__DOT__dim_idx))) {
                    vlSelfRef.complete_transformer_decoder__DOT__projection_inst__DOT____Vlvbound_ha826efa1__0 
                        = (0x0000ffffU & VL_SHIFTRS_III(16,32,32, vlSelfRef.complete_transformer_decoder__DOT__projection_inst__DOT__logit_accumulator, 8U));
                    if ((0x27U >= (IData)(vlSelfRef.complete_transformer_decoder__DOT__projection_inst__DOT__vocab_idx))) {
                        __VdlyVal__complete_transformer_decoder__DOT__final_logits__v0 
                            = vlSelfRef.complete_transformer_decoder__DOT__projection_inst__DOT____Vlvbound_ha826efa1__0;
                        __VdlyDim0__complete_transformer_decoder__DOT__final_logits__v0 
                            = vlSelfRef.complete_transformer_decoder__DOT__projection_inst__DOT__vocab_idx;
                        __VdlySet__complete_transformer_decoder__DOT__final_logits__v0 = 1U;
                    }
                    __Vdly__complete_transformer_decoder__DOT__projection_inst__DOT__dim_idx = 0U;
                    __Vdly__complete_transformer_decoder__DOT__projection_inst__DOT__logit_accumulator = 0U;
                    if ((0x27U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__projection_inst__DOT__vocab_idx))) {
                        __Vdly__complete_transformer_decoder__DOT__projection_inst__DOT__state = 2U;
                    } else {
                        __Vdly__complete_transformer_decoder__DOT__projection_inst__DOT__vocab_idx 
                            = (0x0000003fU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.complete_transformer_decoder__DOT__projection_inst__DOT__vocab_idx)));
                    }
                } else {
                    __Vdly__complete_transformer_decoder__DOT__projection_inst__DOT__dim_idx 
                        = (0x0000000fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.complete_transformer_decoder__DOT__projection_inst__DOT__dim_idx)));
                }
            }
        } else if ((2U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__projection_inst__DOT__state))) {
            vlSelfRef.complete_transformer_decoder__DOT__proj_done = 1U;
            vlSelfRef.complete_transformer_decoder__DOT__proj_valid = 1U;
            if ((1U & (~ (IData)(vlSelfRef.complete_transformer_decoder__DOT__proj_start)))) {
                __Vdly__complete_transformer_decoder__DOT__projection_inst__DOT__state = 0U;
            }
        }
    }
    vlSelfRef.complete_transformer_decoder__DOT__proj_start 
        = __Vdly__complete_transformer_decoder__DOT__proj_start;
    vlSelfRef.complete_transformer_decoder__DOT__projection_inst__DOT__logit_accumulator 
        = __Vdly__complete_transformer_decoder__DOT__projection_inst__DOT__logit_accumulator;
    vlSelfRef.complete_transformer_decoder__DOT__projection_inst__DOT__pipe_stage 
        = __Vdly__complete_transformer_decoder__DOT__projection_inst__DOT__pipe_stage;
    if (__VdlySet__complete_transformer_decoder__DOT__final_logits__v0) {
        vlSelfRef.complete_transformer_decoder__DOT__final_logits[__VdlyDim0__complete_transformer_decoder__DOT__final_logits__v0] 
            = __VdlyVal__complete_transformer_decoder__DOT__final_logits__v0;
    }
    vlSelfRef.complete_transformer_decoder__DOT__projection_inst__DOT__vocab_idx 
        = __Vdly__complete_transformer_decoder__DOT__projection_inst__DOT__vocab_idx;
    vlSelfRef.complete_transformer_decoder__DOT__projection_inst__DOT__dim_idx 
        = __Vdly__complete_transformer_decoder__DOT__projection_inst__DOT__dim_idx;
    if (vlSelfRef.rst) {
        __Vdly__complete_transformer_decoder__DOT__positional_inst__DOT__state = 0U;
        __Vdly__complete_transformer_decoder__DOT__positional_inst__DOT__seq_idx = 0U;
        __Vdly__complete_transformer_decoder__DOT__positional_inst__DOT__dim_idx = 0U;
        __Vdly__complete_transformer_decoder__DOT__positional_inst__DOT__pipe_stage = 0U;
        vlSelfRef.complete_transformer_decoder__DOT__pos_done = 0U;
        vlSelfRef.complete_transformer_decoder__DOT__pos_valid = 0U;
        __Vdly__complete_transformer_decoder__DOT__positional_inst__DOT__temp_sum = 0U;
    } else if ((0U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__positional_inst__DOT__state))) {
        vlSelfRef.complete_transformer_decoder__DOT__pos_done = 0U;
        vlSelfRef.complete_transformer_decoder__DOT__pos_valid = 0U;
        if (vlSelfRef.complete_transformer_decoder__DOT__pos_start) {
            __Vdly__complete_transformer_decoder__DOT__positional_inst__DOT__state = 1U;
            __Vdly__complete_transformer_decoder__DOT__positional_inst__DOT__seq_idx = 0U;
            __Vdly__complete_transformer_decoder__DOT__positional_inst__DOT__dim_idx = 0U;
            __Vdly__complete_transformer_decoder__DOT__positional_inst__DOT__pipe_stage = 0U;
        }
    } else if ((1U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__positional_inst__DOT__state))) {
        __Vdly__complete_transformer_decoder__DOT__positional_inst__DOT__pipe_stage 
            = (3U & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__positional_inst__DOT__pipe_stage)));
        if ((2U <= (IData)(vlSelfRef.complete_transformer_decoder__DOT__positional_inst__DOT__pipe_stage))) {
            __Vdly__complete_transformer_decoder__DOT__positional_inst__DOT__temp_sum 
                = (0x0001ffffU & (VL_EXTENDS_II(17,16, vlSelfRef.complete_transformer_decoder__DOT__embedded_tokens
                                                [vlSelfRef.complete_transformer_decoder__DOT__positional_inst__DOT__seq_idx]
                                                [vlSelfRef.complete_transformer_decoder__DOT__positional_inst__DOT__dim_idx]) 
                                  + VL_EXTENDS_II(17,16, (IData)(vlSelfRef.complete_transformer_decoder__DOT__positional_inst__DOT__pos_data))));
            __VdlyVal__complete_transformer_decoder__DOT__position_encoded__v0 
                = (VL_LTS_III(32, 0x00007fffU, VL_EXTENDS_II(32,17, vlSelfRef.complete_transformer_decoder__DOT__positional_inst__DOT__temp_sum))
                    ? 0x00007fffU : (VL_GTS_III(32, 0xffff8000U, 
                                                VL_EXTENDS_II(32,17, vlSelfRef.complete_transformer_decoder__DOT__positional_inst__DOT__temp_sum))
                                      ? 0x00008000U
                                      : (0x0000ffffU 
                                         & vlSelfRef.complete_transformer_decoder__DOT__positional_inst__DOT__temp_sum)));
            __VdlyDim0__complete_transformer_decoder__DOT__position_encoded__v0 
                = vlSelfRef.complete_transformer_decoder__DOT__positional_inst__DOT__dim_idx;
            __VdlyDim1__complete_transformer_decoder__DOT__position_encoded__v0 
                = vlSelfRef.complete_transformer_decoder__DOT__positional_inst__DOT__seq_idx;
            __VdlySet__complete_transformer_decoder__DOT__position_encoded__v0 = 1U;
            __Vdly__complete_transformer_decoder__DOT__positional_inst__DOT__pipe_stage = 0U;
            if ((0x0fU == (IData)(vlSelfRef.complete_transformer_decoder__DOT__positional_inst__DOT__dim_idx))) {
                __Vdly__complete_transformer_decoder__DOT__positional_inst__DOT__dim_idx = 0U;
                if ((7U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__positional_inst__DOT__seq_idx))) {
                    __Vdly__complete_transformer_decoder__DOT__positional_inst__DOT__state = 2U;
                } else {
                    __Vdly__complete_transformer_decoder__DOT__positional_inst__DOT__seq_idx 
                        = (7U & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__positional_inst__DOT__seq_idx)));
                }
            } else {
                __Vdly__complete_transformer_decoder__DOT__positional_inst__DOT__dim_idx 
                    = (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__positional_inst__DOT__dim_idx)));
            }
        }
    } else if ((2U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__positional_inst__DOT__state))) {
        vlSelfRef.complete_transformer_decoder__DOT__pos_done = 1U;
        vlSelfRef.complete_transformer_decoder__DOT__pos_valid = 1U;
        if ((1U & (~ (IData)(vlSelfRef.complete_transformer_decoder__DOT__pos_start)))) {
            __Vdly__complete_transformer_decoder__DOT__positional_inst__DOT__state = 0U;
        }
    }
    vlSelfRef.complete_transformer_decoder__DOT__pos_start 
        = __Vdly__complete_transformer_decoder__DOT__pos_start;
    vlSelfRef.complete_transformer_decoder__DOT__positional_inst__DOT__pipe_stage 
        = __Vdly__complete_transformer_decoder__DOT__positional_inst__DOT__pipe_stage;
    vlSelfRef.complete_transformer_decoder__DOT__positional_inst__DOT__temp_sum 
        = __Vdly__complete_transformer_decoder__DOT__positional_inst__DOT__temp_sum;
    if (__VdlySet__complete_transformer_decoder__DOT__embedded_tokens__v0) {
        vlSelfRef.complete_transformer_decoder__DOT__embedded_tokens[__VdlyDim1__complete_transformer_decoder__DOT__embedded_tokens__v0][__VdlyDim0__complete_transformer_decoder__DOT__embedded_tokens__v0] 
            = __VdlyVal__complete_transformer_decoder__DOT__embedded_tokens__v0;
    }
    if (vlSelfRef.rst) {
        __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__state = 0U;
        __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__seq_idx = 0U;
        __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__dim_idx = 0U;
        __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__mean_acc = 0U;
        __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__var_acc = 0U;
        __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__pipe_stage = 0U;
        vlSelfRef.complete_transformer_decoder__DOT__norm1_done = 0U;
        vlSelfRef.complete_transformer_decoder__DOT__norm1_valid = 0U;
        __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__temp_sum = 0U;
        __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__diff = 0U;
        __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__diff_sq = 0U;
        __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__normalized = 0U;
        __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__with_gamma = 0U;
        __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__final_result = 0U;
        __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__variance = 0U;
    } else if ((0U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__state))) {
        vlSelfRef.complete_transformer_decoder__DOT__norm1_done = 0U;
        vlSelfRef.complete_transformer_decoder__DOT__norm1_valid = 0U;
        if (vlSelfRef.complete_transformer_decoder__DOT__norm1_start) {
            __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__state = 1U;
            __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__seq_idx = 0U;
            __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__dim_idx = 0U;
        }
    } else if ((1U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__state))) {
        __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__temp_sum 
            = (0x0001ffffU & (VL_EXTENDS_II(17,16, vlSelfRef.complete_transformer_decoder__DOT__attention_out
                                            [vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__seq_idx]
                                            [vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__dim_idx]) 
                              + VL_EXTENDS_II(17,16, vlSelfRef.complete_transformer_decoder__DOT__position_encoded
                                              [vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__seq_idx]
                                              [vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__dim_idx])));
        __VdlyVal__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__sum_data__v0 
            = (VL_LTS_III(32, 0x00007fffU, VL_EXTENDS_II(32,17, vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__temp_sum))
                ? 0x00007fffU : (VL_GTS_III(32, 0xffff8000U, 
                                            VL_EXTENDS_II(32,17, vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__temp_sum))
                                  ? 0x00008000U : (0x0000ffffU 
                                                   & vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__temp_sum)));
        __VdlyDim0__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__sum_data__v0 
            = vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__dim_idx;
        __VdlyDim1__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__sum_data__v0 
            = vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__seq_idx;
        __VdlySet__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__sum_data__v0 = 1U;
        if ((0x0fU == (IData)(vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__dim_idx))) {
            __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__dim_idx = 0U;
            if ((7U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__seq_idx))) {
                __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__state = 2U;
                __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__seq_idx = 0U;
                __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__mean_acc = 0U;
            } else {
                __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__seq_idx 
                    = (7U & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__seq_idx)));
            }
        } else {
            __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__dim_idx 
                = (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__dim_idx)));
        }
    } else if ((2U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__state))) {
        __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__mean_acc 
            = (vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__mean_acc 
               + VL_EXTENDS_II(32,16, vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__sum_data
                               [vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__seq_idx]
                               [vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__dim_idx]));
        if ((0x0fU == (IData)(vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__dim_idx))) {
            __VdlyVal__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__mean_val__v0 
                = (0x0000ffffU & VL_SHIFTRS_III(16,32,32, vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__mean_acc, 4U));
            __VdlyDim0__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__mean_val__v0 
                = vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__seq_idx;
            __VdlySet__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__mean_val__v0 = 1U;
            __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__dim_idx = 0U;
            __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__var_acc = 0U;
            __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__state = 3U;
        } else {
            __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__dim_idx 
                = (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__dim_idx)));
        }
    } else if ((3U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__state))) {
        __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__diff 
            = (VL_EXTENDS_II(32,16, vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__sum_data
                             [vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__seq_idx]
                             [vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__dim_idx]) 
               - VL_EXTENDS_II(32,16, vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__mean_val
                               [vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__seq_idx]));
        __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__var_acc 
            = (vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__var_acc 
               + vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__diff_sq);
        if ((0x0fU == (IData)(vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__dim_idx))) {
            __Vfunc_complete_transformer_decoder__DOT__layer_norm1_inst__DOT__improved_sqrt__8__x 
                = ((IData)(0x00000100U) + vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__variance);
            if ((0U == __Vfunc_complete_transformer_decoder__DOT__layer_norm1_inst__DOT__improved_sqrt__8__x)) {
                __Vfunc_complete_transformer_decoder__DOT__layer_norm1_inst__DOT__improved_sqrt__8__Vfuncout = 0U;
            } else {
                vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__improved_sqrt__Vstatic__approx 
                    = VL_SHIFTR_III(32,32,32, __Vfunc_complete_transformer_decoder__DOT__layer_norm1_inst__DOT__improved_sqrt__8__x, 1U);
                vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__improved_sqrt__Vstatic__new_approx 
                    = VL_SHIFTR_III(32,32,32, (vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__improved_sqrt__Vstatic__approx 
                                               + VL_DIV_III(32, __Vfunc_complete_transformer_decoder__DOT__layer_norm1_inst__DOT__improved_sqrt__8__x, vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__improved_sqrt__Vstatic__approx)), 1U);
                vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__improved_sqrt__Vstatic__approx 
                    = vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__improved_sqrt__Vstatic__new_approx;
                vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__improved_sqrt__Vstatic__new_approx 
                    = VL_SHIFTR_III(32,32,32, (vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__improved_sqrt__Vstatic__approx 
                                               + VL_DIV_III(32, __Vfunc_complete_transformer_decoder__DOT__layer_norm1_inst__DOT__improved_sqrt__8__x, vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__improved_sqrt__Vstatic__approx)), 1U);
                vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__improved_sqrt__Vstatic__approx 
                    = vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__improved_sqrt__Vstatic__new_approx;
                vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__improved_sqrt__Vstatic__new_approx 
                    = VL_SHIFTR_III(32,32,32, (vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__improved_sqrt__Vstatic__approx 
                                               + VL_DIV_III(32, __Vfunc_complete_transformer_decoder__DOT__layer_norm1_inst__DOT__improved_sqrt__8__x, vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__improved_sqrt__Vstatic__approx)), 1U);
                vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__improved_sqrt__Vstatic__approx 
                    = vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__improved_sqrt__Vstatic__new_approx;
                __Vfunc_complete_transformer_decoder__DOT__layer_norm1_inst__DOT__improved_sqrt__8__Vfuncout 
                    = (0x0000ffffU & vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__improved_sqrt__Vstatic__approx);
            }
            __VdlyVal__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__std_val__v0 
                = __Vfunc_complete_transformer_decoder__DOT__layer_norm1_inst__DOT__improved_sqrt__8__Vfuncout;
            __VdlyDim0__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__std_val__v0 
                = vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__seq_idx;
            __VdlySet__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__std_val__v0 = 1U;
            __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__dim_idx = 0U;
            __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__pipe_stage = 0U;
            __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__state = 4U;
            __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__variance 
                = VL_SHIFTRS_III(32,32,32, vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__var_acc, 4U);
        } else {
            __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__dim_idx 
                = (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__dim_idx)));
        }
        __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__diff_sq 
            = VL_SHIFTRS_III(32,32,32, VL_MULS_III(32, vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__diff, vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__diff), 8U);
    } else if ((4U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__state))) {
        __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__pipe_stage 
            = (7U & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__pipe_stage)));
        if ((2U <= (IData)(vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__pipe_stage))) {
            __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__normalized 
                = VL_DIVS_III(32, VL_SHIFTL_III(32,32,32, 
                                                (VL_EXTENDS_II(32,16, vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__sum_data
                                                               [vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__seq_idx]
                                                               [vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__dim_idx]) 
                                                 - 
                                                 VL_EXTENDS_II(32,16, vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__mean_val
                                                               [vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__seq_idx])), 8U), 
                              VL_EXTENDS_II(32,16, vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__std_val
                                            [vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__seq_idx]));
            __VdlyVal__complete_transformer_decoder__DOT__norm1_out__v0 
                = (VL_LTS_III(32, 0x00007fffU, vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__final_result)
                    ? 0x00007fffU : (VL_GTS_III(32, 0xffff8000U, vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__final_result)
                                      ? 0x00008000U
                                      : (0x0000ffffU 
                                         & vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__final_result)));
            __VdlyDim0__complete_transformer_decoder__DOT__norm1_out__v0 
                = vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__dim_idx;
            __VdlyDim1__complete_transformer_decoder__DOT__norm1_out__v0 
                = vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__seq_idx;
            __VdlySet__complete_transformer_decoder__DOT__norm1_out__v0 = 1U;
            __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__pipe_stage = 0U;
            __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__final_result 
                = (vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__with_gamma 
                   + VL_EXTENDS_II(32,16, (IData)(vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__beta_data)));
            if ((0x0fU == (IData)(vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__dim_idx))) {
                __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__dim_idx = 0U;
                if ((7U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__seq_idx))) {
                    __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__state = 5U;
                } else {
                    __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__seq_idx 
                        = (7U & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__seq_idx)));
                    __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__mean_acc = 0U;
                    __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__state = 2U;
                }
            } else {
                __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__dim_idx 
                    = (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__dim_idx)));
            }
            __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__with_gamma 
                = VL_SHIFTRS_III(32,32,32, VL_MULS_III(32, vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__normalized, 
                                                       VL_EXTENDS_II(32,16, (IData)(vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__gamma_data))), 8U);
        }
    } else if ((5U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__state))) {
        vlSelfRef.complete_transformer_decoder__DOT__norm1_done = 1U;
        vlSelfRef.complete_transformer_decoder__DOT__norm1_valid = 1U;
        if ((1U & (~ (IData)(vlSelfRef.complete_transformer_decoder__DOT__norm1_start)))) {
            __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__state = 0U;
        }
    }
    vlSelfRef.complete_transformer_decoder__DOT__norm1_start 
        = __Vdly__complete_transformer_decoder__DOT__norm1_start;
    vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__seq_idx 
        = __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__seq_idx;
    vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__mean_acc 
        = __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__mean_acc;
    vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__var_acc 
        = __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__var_acc;
    vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__pipe_stage 
        = __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__pipe_stage;
    vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__temp_sum 
        = __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__temp_sum;
    vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__diff 
        = __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__diff;
    vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__diff_sq 
        = __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__diff_sq;
    vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__normalized 
        = __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__normalized;
    vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__with_gamma 
        = __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__with_gamma;
    vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__final_result 
        = __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__final_result;
    vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__variance 
        = __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__variance;
    if (__VdlySet__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__mean_val__v0) {
        vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__mean_val[__VdlyDim0__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__mean_val__v0] 
            = __VdlyVal__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__mean_val__v0;
    }
    if (__VdlySet__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__std_val__v0) {
        vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__std_val[__VdlyDim0__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__std_val__v0] 
            = __VdlyVal__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__std_val__v0;
    }
    if (__VdlySet__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__sum_data__v0) {
        vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__sum_data[__VdlyDim1__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__sum_data__v0][__VdlyDim0__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__sum_data__v0] 
            = __VdlyVal__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__sum_data__v0;
    }
    if (vlSelfRef.rst) {
        __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__state = 0U;
        __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__seq_idx = 0U;
        __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__dim_idx = 0U;
        __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__mean_acc = 0U;
        __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__var_acc = 0U;
        __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__pipe_stage = 0U;
        vlSelfRef.complete_transformer_decoder__DOT__norm2_done = 0U;
        vlSelfRef.complete_transformer_decoder__DOT__norm2_valid = 0U;
        __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__temp_sum = 0U;
        __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__diff = 0U;
        __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__diff_sq = 0U;
        __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__normalized = 0U;
        __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__with_gamma = 0U;
        __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__final_result = 0U;
        __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__variance = 0U;
    } else if ((0U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__state))) {
        vlSelfRef.complete_transformer_decoder__DOT__norm2_done = 0U;
        vlSelfRef.complete_transformer_decoder__DOT__norm2_valid = 0U;
        if (vlSelfRef.complete_transformer_decoder__DOT__norm2_start) {
            __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__state = 1U;
            __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__seq_idx = 0U;
            __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__dim_idx = 0U;
        }
    } else if ((1U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__state))) {
        __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__temp_sum 
            = (0x0001ffffU & (VL_EXTENDS_II(17,16, vlSelfRef.complete_transformer_decoder__DOT__ffn_out
                                            [vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__seq_idx]
                                            [vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__dim_idx]) 
                              + VL_EXTENDS_II(17,16, vlSelfRef.complete_transformer_decoder__DOT__norm1_out
                                              [vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__seq_idx]
                                              [vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__dim_idx])));
        __VdlyVal__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__sum_data__v0 
            = (VL_LTS_III(32, 0x00007fffU, VL_EXTENDS_II(32,17, vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__temp_sum))
                ? 0x00007fffU : (VL_GTS_III(32, 0xffff8000U, 
                                            VL_EXTENDS_II(32,17, vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__temp_sum))
                                  ? 0x00008000U : (0x0000ffffU 
                                                   & vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__temp_sum)));
        __VdlyDim0__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__sum_data__v0 
            = vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__dim_idx;
        __VdlyDim1__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__sum_data__v0 
            = vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__seq_idx;
        __VdlySet__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__sum_data__v0 = 1U;
        if ((0x0fU == (IData)(vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__dim_idx))) {
            __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__dim_idx = 0U;
            if ((7U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__seq_idx))) {
                __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__state = 2U;
                __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__seq_idx = 0U;
                __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__mean_acc = 0U;
            } else {
                __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__seq_idx 
                    = (7U & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__seq_idx)));
            }
        } else {
            __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__dim_idx 
                = (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__dim_idx)));
        }
    } else if ((2U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__state))) {
        __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__mean_acc 
            = (vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__mean_acc 
               + VL_EXTENDS_II(32,16, vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__sum_data
                               [vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__seq_idx]
                               [vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__dim_idx]));
        if ((0x0fU == (IData)(vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__dim_idx))) {
            __VdlyVal__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__mean_val__v0 
                = (0x0000ffffU & VL_SHIFTRS_III(16,32,32, vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__mean_acc, 4U));
            __VdlyDim0__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__mean_val__v0 
                = vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__seq_idx;
            __VdlySet__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__mean_val__v0 = 1U;
            __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__dim_idx = 0U;
            __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__var_acc = 0U;
            __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__state = 3U;
        } else {
            __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__dim_idx 
                = (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__dim_idx)));
        }
    } else if ((3U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__state))) {
        __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__diff 
            = (VL_EXTENDS_II(32,16, vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__sum_data
                             [vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__seq_idx]
                             [vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__dim_idx]) 
               - VL_EXTENDS_II(32,16, vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__mean_val
                               [vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__seq_idx]));
        __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__var_acc 
            = (vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__var_acc 
               + vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__diff_sq);
        if ((0x0fU == (IData)(vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__dim_idx))) {
            __Vfunc_complete_transformer_decoder__DOT__layer_norm2_inst__DOT__improved_sqrt__9__x 
                = ((IData)(0x00000100U) + vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__variance);
            if ((0U == __Vfunc_complete_transformer_decoder__DOT__layer_norm2_inst__DOT__improved_sqrt__9__x)) {
                __Vfunc_complete_transformer_decoder__DOT__layer_norm2_inst__DOT__improved_sqrt__9__Vfuncout = 0U;
            } else {
                vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__improved_sqrt__Vstatic__approx 
                    = VL_SHIFTR_III(32,32,32, __Vfunc_complete_transformer_decoder__DOT__layer_norm2_inst__DOT__improved_sqrt__9__x, 1U);
                vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__improved_sqrt__Vstatic__new_approx 
                    = VL_SHIFTR_III(32,32,32, (vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__improved_sqrt__Vstatic__approx 
                                               + VL_DIV_III(32, __Vfunc_complete_transformer_decoder__DOT__layer_norm2_inst__DOT__improved_sqrt__9__x, vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__improved_sqrt__Vstatic__approx)), 1U);
                vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__improved_sqrt__Vstatic__approx 
                    = vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__improved_sqrt__Vstatic__new_approx;
                vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__improved_sqrt__Vstatic__new_approx 
                    = VL_SHIFTR_III(32,32,32, (vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__improved_sqrt__Vstatic__approx 
                                               + VL_DIV_III(32, __Vfunc_complete_transformer_decoder__DOT__layer_norm2_inst__DOT__improved_sqrt__9__x, vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__improved_sqrt__Vstatic__approx)), 1U);
                vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__improved_sqrt__Vstatic__approx 
                    = vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__improved_sqrt__Vstatic__new_approx;
                vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__improved_sqrt__Vstatic__new_approx 
                    = VL_SHIFTR_III(32,32,32, (vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__improved_sqrt__Vstatic__approx 
                                               + VL_DIV_III(32, __Vfunc_complete_transformer_decoder__DOT__layer_norm2_inst__DOT__improved_sqrt__9__x, vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__improved_sqrt__Vstatic__approx)), 1U);
                vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__improved_sqrt__Vstatic__approx 
                    = vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__improved_sqrt__Vstatic__new_approx;
                __Vfunc_complete_transformer_decoder__DOT__layer_norm2_inst__DOT__improved_sqrt__9__Vfuncout 
                    = (0x0000ffffU & vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__improved_sqrt__Vstatic__approx);
            }
            __VdlyVal__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__std_val__v0 
                = __Vfunc_complete_transformer_decoder__DOT__layer_norm2_inst__DOT__improved_sqrt__9__Vfuncout;
            __VdlyDim0__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__std_val__v0 
                = vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__seq_idx;
            __VdlySet__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__std_val__v0 = 1U;
            __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__dim_idx = 0U;
            __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__pipe_stage = 0U;
            __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__state = 4U;
            __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__variance 
                = VL_SHIFTRS_III(32,32,32, vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__var_acc, 4U);
        } else {
            __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__dim_idx 
                = (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__dim_idx)));
        }
        __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__diff_sq 
            = VL_SHIFTRS_III(32,32,32, VL_MULS_III(32, vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__diff, vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__diff), 8U);
    } else if ((4U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__state))) {
        __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__pipe_stage 
            = (7U & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__pipe_stage)));
        if ((2U <= (IData)(vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__pipe_stage))) {
            __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__normalized 
                = VL_DIVS_III(32, VL_SHIFTL_III(32,32,32, 
                                                (VL_EXTENDS_II(32,16, vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__sum_data
                                                               [vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__seq_idx]
                                                               [vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__dim_idx]) 
                                                 - 
                                                 VL_EXTENDS_II(32,16, vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__mean_val
                                                               [vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__seq_idx])), 8U), 
                              VL_EXTENDS_II(32,16, vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__std_val
                                            [vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__seq_idx]));
            __VdlyVal__complete_transformer_decoder__DOT__norm2_out__v0 
                = (VL_LTS_III(32, 0x00007fffU, vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__final_result)
                    ? 0x00007fffU : (VL_GTS_III(32, 0xffff8000U, vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__final_result)
                                      ? 0x00008000U
                                      : (0x0000ffffU 
                                         & vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__final_result)));
            __VdlyDim0__complete_transformer_decoder__DOT__norm2_out__v0 
                = vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__dim_idx;
            __VdlyDim1__complete_transformer_decoder__DOT__norm2_out__v0 
                = vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__seq_idx;
            __VdlySet__complete_transformer_decoder__DOT__norm2_out__v0 = 1U;
            __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__pipe_stage = 0U;
            __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__final_result 
                = (vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__with_gamma 
                   + VL_EXTENDS_II(32,16, (IData)(vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__beta_data)));
            if ((0x0fU == (IData)(vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__dim_idx))) {
                __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__dim_idx = 0U;
                if ((7U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__seq_idx))) {
                    __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__state = 5U;
                } else {
                    __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__seq_idx 
                        = (7U & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__seq_idx)));
                    __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__mean_acc = 0U;
                    __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__state = 2U;
                }
            } else {
                __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__dim_idx 
                    = (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__dim_idx)));
            }
            __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__with_gamma 
                = VL_SHIFTRS_III(32,32,32, VL_MULS_III(32, vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__normalized, 
                                                       VL_EXTENDS_II(32,16, (IData)(vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__gamma_data))), 8U);
        }
    } else if ((5U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__state))) {
        vlSelfRef.complete_transformer_decoder__DOT__norm2_done = 1U;
        vlSelfRef.complete_transformer_decoder__DOT__norm2_valid = 1U;
        if ((1U & (~ (IData)(vlSelfRef.complete_transformer_decoder__DOT__norm2_start)))) {
            __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__state = 0U;
        }
    }
    vlSelfRef.complete_transformer_decoder__DOT__norm2_start 
        = __Vdly__complete_transformer_decoder__DOT__norm2_start;
    vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__seq_idx 
        = __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__seq_idx;
    vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__mean_acc 
        = __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__mean_acc;
    vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__var_acc 
        = __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__var_acc;
    vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__pipe_stage 
        = __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__pipe_stage;
    vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__temp_sum 
        = __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__temp_sum;
    vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__diff 
        = __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__diff;
    vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__diff_sq 
        = __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__diff_sq;
    vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__normalized 
        = __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__normalized;
    vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__with_gamma 
        = __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__with_gamma;
    vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__final_result 
        = __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__final_result;
    vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__variance 
        = __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__variance;
    if (__VdlySet__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__mean_val__v0) {
        vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__mean_val[__VdlyDim0__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__mean_val__v0] 
            = __VdlyVal__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__mean_val__v0;
    }
    if (__VdlySet__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__std_val__v0) {
        vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__std_val[__VdlyDim0__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__std_val__v0] 
            = __VdlyVal__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__std_val__v0;
    }
    if (__VdlySet__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__sum_data__v0) {
        vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__sum_data[__VdlyDim1__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__sum_data__v0][__VdlyDim0__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__sum_data__v0] 
            = __VdlyVal__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__sum_data__v0;
    }
    if (__VdlySet__complete_transformer_decoder__DOT__norm2_out__v0) {
        vlSelfRef.complete_transformer_decoder__DOT__norm2_out[__VdlyDim1__complete_transformer_decoder__DOT__norm2_out__v0][__VdlyDim0__complete_transformer_decoder__DOT__norm2_out__v0] 
            = __VdlyVal__complete_transformer_decoder__DOT__norm2_out__v0;
    }
    if (vlSelfRef.rst) {
        __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__state = 0U;
        __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__seq_idx = 0U;
        __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__in_dim = 0U;
        __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__out_dim = 0U;
        __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__hidden_dim = 0U;
        __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__accumulator = 0U;
        __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__pipe_stage = 0U;
        vlSelfRef.complete_transformer_decoder__DOT__ffn_done = 0U;
        vlSelfRef.complete_transformer_decoder__DOT__ffn_valid = 0U;
        __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__with_bias = 0U;
    } else if ((0U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__state))) {
        vlSelfRef.complete_transformer_decoder__DOT__ffn_done = 0U;
        vlSelfRef.complete_transformer_decoder__DOT__ffn_valid = 0U;
        if (vlSelfRef.complete_transformer_decoder__DOT__ffn_start) {
            __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__state = 1U;
            __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__seq_idx = 0U;
            __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__in_dim = 0U;
            __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__hidden_dim = 0U;
            __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__accumulator = 0U;
            __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__pipe_stage = 0U;
        }
    } else if ((1U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__state))) {
        __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__pipe_stage 
            = (7U & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__pipe_stage)));
        if ((2U <= (IData)(vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__pipe_stage))) {
            __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__accumulator 
                = (vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__accumulator 
                   + VL_MULS_III(32, VL_EXTENDS_II(32,16, vlSelfRef.complete_transformer_decoder__DOT__norm1_out
                                                   [vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__seq_idx]
                                                   [vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__in_dim]), 
                                 VL_EXTENDS_II(32,16, (IData)(vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__w1_data))));
            __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__pipe_stage = 0U;
            if ((0x0fU == (IData)(vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__in_dim))) {
                __VdlyVal__complete_transformer_decoder__DOT__ffn_inst__DOT__hidden_data__v0 
                    = (VL_LTS_III(32, 0x00007fffU, vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__with_bias)
                        ? 0x00007fffU : (VL_GTS_III(32, 0U, vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__with_bias)
                                          ? 0U : (0x0000ffffU 
                                                  & vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__with_bias)));
                __VdlyDim0__complete_transformer_decoder__DOT__ffn_inst__DOT__hidden_data__v0 
                    = vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__hidden_dim;
                __VdlyDim1__complete_transformer_decoder__DOT__ffn_inst__DOT__hidden_data__v0 
                    = vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__seq_idx;
                __VdlySet__complete_transformer_decoder__DOT__ffn_inst__DOT__hidden_data__v0 = 1U;
                __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__in_dim = 0U;
                if ((0x1fU == (IData)(vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__hidden_dim))) {
                    __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__hidden_dim = 0U;
                    if ((7U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__seq_idx))) {
                        __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__state = 2U;
                        __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__seq_idx = 0U;
                        __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__out_dim = 0U;
                        __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__pipe_stage = 0U;
                    } else {
                        __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__seq_idx 
                            = (7U & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__seq_idx)));
                    }
                } else {
                    __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__hidden_dim 
                        = (0x0000001fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__hidden_dim)));
                }
                __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__with_bias 
                    = (VL_SHIFTRS_III(32,32,32, vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__accumulator, 8U) 
                       + VL_EXTENDS_II(32,16, (IData)(vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__b1_data)));
                __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__accumulator = 0U;
            } else {
                __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__in_dim 
                    = (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__in_dim)));
            }
        }
    } else if ((2U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__state))) {
        __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__pipe_stage 
            = (7U & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__pipe_stage)));
        if ((2U <= (IData)(vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__pipe_stage))) {
            __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__accumulator 
                = (vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__accumulator 
                   + VL_MULS_III(32, VL_EXTENDS_II(32,16, vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__hidden_data
                                                   [vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__seq_idx]
                                                   [vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__hidden_dim]), 
                                 VL_EXTENDS_II(32,16, (IData)(vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__w2_data))));
            __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__pipe_stage = 0U;
            if ((0x1fU == (IData)(vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__hidden_dim))) {
                __VdlyVal__complete_transformer_decoder__DOT__ffn_out__v0 
                    = (VL_LTS_III(32, 0x00007fffU, vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__with_bias)
                        ? 0x00007fffU : (VL_GTS_III(32, 0xffff8000U, vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__with_bias)
                                          ? 0x00008000U
                                          : (0x0000ffffU 
                                             & vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__with_bias)));
                __VdlyDim0__complete_transformer_decoder__DOT__ffn_out__v0 
                    = vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__out_dim;
                __VdlyDim1__complete_transformer_decoder__DOT__ffn_out__v0 
                    = vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__seq_idx;
                __VdlySet__complete_transformer_decoder__DOT__ffn_out__v0 = 1U;
                __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__hidden_dim = 0U;
                if ((0x0fU == (IData)(vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__out_dim))) {
                    __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__out_dim = 0U;
                    if ((7U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__seq_idx))) {
                        __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__state = 3U;
                    } else {
                        __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__seq_idx 
                            = (7U & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__seq_idx)));
                    }
                } else {
                    __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__out_dim 
                        = (0x0000000fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__out_dim)));
                }
                __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__with_bias 
                    = (VL_SHIFTRS_III(32,32,32, vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__accumulator, 8U) 
                       + VL_EXTENDS_II(32,16, (IData)(vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__b2_data)));
                __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__accumulator = 0U;
            } else {
                __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__hidden_dim 
                    = (0x0000001fU & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__hidden_dim)));
            }
        }
    } else if ((3U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__state))) {
        vlSelfRef.complete_transformer_decoder__DOT__ffn_done = 1U;
        vlSelfRef.complete_transformer_decoder__DOT__ffn_valid = 1U;
        if ((1U & (~ (IData)(vlSelfRef.complete_transformer_decoder__DOT__ffn_start)))) {
            __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__state = 0U;
        }
    }
    vlSelfRef.complete_transformer_decoder__DOT__ffn_start 
        = __Vdly__complete_transformer_decoder__DOT__ffn_start;
    vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__seq_idx 
        = __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__seq_idx;
    vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__accumulator 
        = __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__accumulator;
    vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__pipe_stage 
        = __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__pipe_stage;
    vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__with_bias 
        = __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__with_bias;
    if (__VdlySet__complete_transformer_decoder__DOT__norm1_out__v0) {
        vlSelfRef.complete_transformer_decoder__DOT__norm1_out[__VdlyDim1__complete_transformer_decoder__DOT__norm1_out__v0][__VdlyDim0__complete_transformer_decoder__DOT__norm1_out__v0] 
            = __VdlyVal__complete_transformer_decoder__DOT__norm1_out__v0;
    }
    if (__VdlySet__complete_transformer_decoder__DOT__ffn_inst__DOT__hidden_data__v0) {
        vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__hidden_data[__VdlyDim1__complete_transformer_decoder__DOT__ffn_inst__DOT__hidden_data__v0][__VdlyDim0__complete_transformer_decoder__DOT__ffn_inst__DOT__hidden_data__v0] 
            = __VdlyVal__complete_transformer_decoder__DOT__ffn_inst__DOT__hidden_data__v0;
    }
    if (__VdlySet__complete_transformer_decoder__DOT__ffn_out__v0) {
        vlSelfRef.complete_transformer_decoder__DOT__ffn_out[__VdlyDim1__complete_transformer_decoder__DOT__ffn_out__v0][__VdlyDim0__complete_transformer_decoder__DOT__ffn_out__v0] 
            = __VdlyVal__complete_transformer_decoder__DOT__ffn_out__v0;
    }
    if (vlSelfRef.rst) {
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__state = 0U;
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__head_start_signals = 0U;
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__seq_idx = 0U;
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__dim_idx = 0U;
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__in_dim = 0U;
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__out_dim = 0U;
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__pipe_stage = 0U;
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__proj_accumulator = 0U;
        vlSelfRef.complete_transformer_decoder__DOT__attn_done = 0U;
        vlSelfRef.complete_transformer_decoder__DOT__attn_valid = 0U;
    } else if ((0U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__state))) {
        vlSelfRef.complete_transformer_decoder__DOT__attn_done = 0U;
        vlSelfRef.complete_transformer_decoder__DOT__attn_valid = 0U;
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__head_start_signals = 0U;
        if (vlSelfRef.complete_transformer_decoder__DOT__attn_start) {
            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__state = 1U;
            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__head_start_signals = 0x0fU;
        }
    } else if ((1U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__state))) {
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__head_start_signals = 0U;
        if ((((IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__3__KET____DOT__head__done) 
              & ((IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__2__KET____DOT__head__done) 
                 & ((IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__1__KET____DOT__head__done) 
                    & (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__0__KET____DOT__head__done)))) 
             & ((IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__3__KET____DOT__head__valid) 
                & ((IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__2__KET____DOT__head__valid) 
                   & ((IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__1__KET____DOT__head__valid) 
                      & (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__0__KET____DOT__head__valid)))))) {
            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__state = 2U;
            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__seq_idx = 0U;
            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__dim_idx = 0U;
        }
    } else if ((2U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__state))) {
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__unnamedblk2__DOT__head_id 
            = (3U & ((IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__dim_idx) 
                     >> 2U));
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__unnamedblk2__DOT__local_dim 
            = (3U & (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__dim_idx));
        __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__concatenated__v0 
            = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs
            [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__unnamedblk2__DOT__head_id]
            [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__seq_idx]
            [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__unnamedblk2__DOT__local_dim];
        __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__concatenated__v0 
            = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__dim_idx;
        __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__concatenated__v0 
            = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__seq_idx;
        __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__concatenated__v0 = 1U;
        if ((0x0fU == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__dim_idx))) {
            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__dim_idx = 0U;
            if ((7U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__seq_idx))) {
                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__state = 3U;
                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__seq_idx = 0U;
                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__in_dim = 0U;
                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__out_dim = 0U;
                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__pipe_stage = 0U;
                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__proj_accumulator = 0U;
            } else {
                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__seq_idx 
                    = (7U & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__seq_idx)));
            }
        } else {
            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__dim_idx 
                = (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__dim_idx)));
        }
    } else if ((3U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__state))) {
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__pipe_stage 
            = (7U & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__pipe_stage)));
        if ((2U <= (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__pipe_stage))) {
            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__proj_accumulator 
                = (vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__proj_accumulator 
                   + VL_MULS_III(32, VL_EXTENDS_II(32,16, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__concatenated
                                                   [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__seq_idx]
                                                   [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__in_dim]), 
                                 VL_EXTENDS_II(32,16, (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__wo_data))));
            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__pipe_stage = 0U;
            if ((0x0fU == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__in_dim))) {
                __VdlyVal__complete_transformer_decoder__DOT__attention_out__v0 
                    = (0x0000ffffU & VL_SHIFTRS_III(16,32,32, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__proj_accumulator, 8U));
                __VdlyDim0__complete_transformer_decoder__DOT__attention_out__v0 
                    = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__out_dim;
                __VdlyDim1__complete_transformer_decoder__DOT__attention_out__v0 
                    = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__seq_idx;
                __VdlySet__complete_transformer_decoder__DOT__attention_out__v0 = 1U;
                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__in_dim = 0U;
                if ((0x0fU == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__out_dim))) {
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__out_dim = 0U;
                    if ((7U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__seq_idx))) {
                        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__state = 4U;
                    } else {
                        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__seq_idx 
                            = (7U & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__seq_idx)));
                    }
                } else {
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__out_dim 
                        = (0x0000000fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__out_dim)));
                }
                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__proj_accumulator = 0U;
            } else {
                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__in_dim 
                    = (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__in_dim)));
            }
        }
    } else if ((4U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__state))) {
        vlSelfRef.complete_transformer_decoder__DOT__attn_done = 1U;
        vlSelfRef.complete_transformer_decoder__DOT__attn_valid = 1U;
        if ((1U & (~ (IData)(vlSelfRef.complete_transformer_decoder__DOT__attn_start)))) {
            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__state = 0U;
        }
    }
    vlSelfRef.complete_transformer_decoder__DOT__attn_start 
        = __Vdly__complete_transformer_decoder__DOT__attn_start;
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__seq_idx 
        = __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__seq_idx;
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__dim_idx 
        = __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__dim_idx;
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__pipe_stage 
        = __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__pipe_stage;
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__proj_accumulator 
        = __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__proj_accumulator;
    if (__VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__concatenated__v0) {
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__concatenated[__VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__concatenated__v0][__VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__concatenated__v0] 
            = __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__concatenated__v0;
    }
    if (__VdlySet__complete_transformer_decoder__DOT__attention_out__v0) {
        vlSelfRef.complete_transformer_decoder__DOT__attention_out[__VdlyDim1__complete_transformer_decoder__DOT__attention_out__v0][__VdlyDim0__complete_transformer_decoder__DOT__attention_out__v0] 
            = __VdlyVal__complete_transformer_decoder__DOT__attention_out__v0;
    }
    if (((1U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__embedding_inst__DOT__state)) 
         & (0x0a00U > (IData)(vlSelfRef.complete_transformer_decoder__DOT__embedding_inst__DOT__embed_addr)))) {
        vlSelfRef.complete_transformer_decoder__DOT__embedding_inst__DOT__embed_data 
            = ((0x09ffU >= (IData)(vlSelfRef.complete_transformer_decoder__DOT__embedding_inst__DOT__embed_addr))
                ? vlSelfRef.complete_transformer_decoder__DOT__embedding_inst__DOT__embedding_memory__DOT__memory
               [vlSelfRef.complete_transformer_decoder__DOT__embedding_inst__DOT__embed_addr]
                : 0U);
    } else if ((1U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__embedding_inst__DOT__state))) {
        vlSelfRef.complete_transformer_decoder__DOT__embedding_inst__DOT__embed_data = 0U;
    }
    if (((1U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__projection_inst__DOT__state)) 
         & (0x0a00U > (IData)(vlSelfRef.complete_transformer_decoder__DOT__projection_inst__DOT__proj_addr)))) {
        vlSelfRef.complete_transformer_decoder__DOT__projection_inst__DOT__proj_data 
            = ((0x09ffU >= (IData)(vlSelfRef.complete_transformer_decoder__DOT__projection_inst__DOT__proj_addr))
                ? vlSelfRef.complete_transformer_decoder__DOT__projection_inst__DOT__proj_memory__DOT__memory
               [vlSelfRef.complete_transformer_decoder__DOT__projection_inst__DOT__proj_addr]
                : 0U);
    } else if ((1U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__projection_inst__DOT__state))) {
        vlSelfRef.complete_transformer_decoder__DOT__projection_inst__DOT__proj_data = 0U;
    }
    if ((1U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__positional_inst__DOT__state))) {
        vlSelfRef.complete_transformer_decoder__DOT__positional_inst__DOT__pos_data 
            = vlSelfRef.complete_transformer_decoder__DOT__positional_inst__DOT__pos_memory__DOT__memory
            [(0x0000007fU & (((IData)(vlSelfRef.complete_transformer_decoder__DOT__positional_inst__DOT__seq_idx) 
                              << 4U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__positional_inst__DOT__dim_idx)))];
    }
    if ((4U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__state))) {
        vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__beta_data 
            = vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__beta_memory__DOT__memory
            [vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__dim_idx];
        vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__gamma_data 
            = vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__gamma_memory__DOT__memory
            [vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__dim_idx];
    }
    vlSelfRef.complete_transformer_decoder__DOT____Vcellinp__projection_inst__final_hidden_state[0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__norm2_out
        [vlSelfRef.complete_transformer_decoder__DOT__last_pos][0U];
    vlSelfRef.complete_transformer_decoder__DOT____Vcellinp__projection_inst__final_hidden_state[1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__norm2_out
        [vlSelfRef.complete_transformer_decoder__DOT__last_pos][1U];
    vlSelfRef.complete_transformer_decoder__DOT____Vcellinp__projection_inst__final_hidden_state[2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__norm2_out
        [vlSelfRef.complete_transformer_decoder__DOT__last_pos][2U];
    vlSelfRef.complete_transformer_decoder__DOT____Vcellinp__projection_inst__final_hidden_state[3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__norm2_out
        [vlSelfRef.complete_transformer_decoder__DOT__last_pos][3U];
    vlSelfRef.complete_transformer_decoder__DOT____Vcellinp__projection_inst__final_hidden_state[4U] 
        = vlSelfRef.complete_transformer_decoder__DOT__norm2_out
        [vlSelfRef.complete_transformer_decoder__DOT__last_pos][4U];
    vlSelfRef.complete_transformer_decoder__DOT____Vcellinp__projection_inst__final_hidden_state[5U] 
        = vlSelfRef.complete_transformer_decoder__DOT__norm2_out
        [vlSelfRef.complete_transformer_decoder__DOT__last_pos][5U];
    vlSelfRef.complete_transformer_decoder__DOT____Vcellinp__projection_inst__final_hidden_state[6U] 
        = vlSelfRef.complete_transformer_decoder__DOT__norm2_out
        [vlSelfRef.complete_transformer_decoder__DOT__last_pos][6U];
    vlSelfRef.complete_transformer_decoder__DOT____Vcellinp__projection_inst__final_hidden_state[7U] 
        = vlSelfRef.complete_transformer_decoder__DOT__norm2_out
        [vlSelfRef.complete_transformer_decoder__DOT__last_pos][7U];
    vlSelfRef.complete_transformer_decoder__DOT____Vcellinp__projection_inst__final_hidden_state[8U] 
        = vlSelfRef.complete_transformer_decoder__DOT__norm2_out
        [vlSelfRef.complete_transformer_decoder__DOT__last_pos][8U];
    vlSelfRef.complete_transformer_decoder__DOT____Vcellinp__projection_inst__final_hidden_state[9U] 
        = vlSelfRef.complete_transformer_decoder__DOT__norm2_out
        [vlSelfRef.complete_transformer_decoder__DOT__last_pos][9U];
    vlSelfRef.complete_transformer_decoder__DOT____Vcellinp__projection_inst__final_hidden_state[10U] 
        = vlSelfRef.complete_transformer_decoder__DOT__norm2_out
        [vlSelfRef.complete_transformer_decoder__DOT__last_pos][10U];
    vlSelfRef.complete_transformer_decoder__DOT____Vcellinp__projection_inst__final_hidden_state[11U] 
        = vlSelfRef.complete_transformer_decoder__DOT__norm2_out
        [vlSelfRef.complete_transformer_decoder__DOT__last_pos][11U];
    vlSelfRef.complete_transformer_decoder__DOT____Vcellinp__projection_inst__final_hidden_state[12U] 
        = vlSelfRef.complete_transformer_decoder__DOT__norm2_out
        [vlSelfRef.complete_transformer_decoder__DOT__last_pos][12U];
    vlSelfRef.complete_transformer_decoder__DOT____Vcellinp__projection_inst__final_hidden_state[13U] 
        = vlSelfRef.complete_transformer_decoder__DOT__norm2_out
        [vlSelfRef.complete_transformer_decoder__DOT__last_pos][13U];
    vlSelfRef.complete_transformer_decoder__DOT____Vcellinp__projection_inst__final_hidden_state[14U] 
        = vlSelfRef.complete_transformer_decoder__DOT__norm2_out
        [vlSelfRef.complete_transformer_decoder__DOT__last_pos][14U];
    vlSelfRef.complete_transformer_decoder__DOT____Vcellinp__projection_inst__final_hidden_state[15U] 
        = vlSelfRef.complete_transformer_decoder__DOT__norm2_out
        [vlSelfRef.complete_transformer_decoder__DOT__last_pos][15U];
    if ((4U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__state))) {
        vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__beta_data 
            = vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__beta_memory__DOT__memory
            [vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__dim_idx];
        vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__gamma_data 
            = vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__gamma_memory__DOT__memory
            [vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__dim_idx];
    }
    if ((1U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__state))) {
        vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__w1_data 
            = vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__w1_memory__DOT__memory
            [(0x000001ffU & (((IData)(vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__in_dim) 
                              << 5U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__hidden_dim)))];
    }
    if (((1U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__state)) 
         & (0x0fU == (IData)(vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__in_dim)))) {
        vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__b1_data 
            = vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__b1_memory__DOT__memory
            [vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__hidden_dim];
    }
    if ((2U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__state))) {
        vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__w2_data 
            = vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__w2_memory__DOT__memory
            [(0x000001ffU & (VL_SHIFTL_III(9,9,32, (IData)(vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__hidden_dim), 4U) 
                             + (IData)(vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__out_dim)))];
    }
    if (((2U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__state)) 
         & (0x1fU == (IData)(vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__hidden_dim)))) {
        vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__b2_data 
            = vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__b2_memory__DOT__memory
            [vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__out_dim];
    }
    if ((3U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__state))) {
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__wo_data 
            = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__wo_memory__DOT__memory
            [(0x000000ffU & (((IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__in_dim) 
                              << 4U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__out_dim)))];
    }
    vlSelfRef.complete_transformer_decoder__DOT__embedding_inst__DOT__state 
        = __Vdly__complete_transformer_decoder__DOT__embedding_inst__DOT__state;
    vlSelfRef.complete_transformer_decoder__DOT__embedding_inst__DOT__embed_addr 
        = (0x00000fffU & (VL_SHIFTL_III(12,12,32, vlSelfRef.input_sequence
                                        [vlSelfRef.complete_transformer_decoder__DOT__embedding_inst__DOT__seq_idx], 4U) 
                          + (IData)(vlSelfRef.complete_transformer_decoder__DOT__embedding_inst__DOT__dim_idx)));
    vlSelfRef.complete_transformer_decoder__DOT__projection_inst__DOT__state 
        = __Vdly__complete_transformer_decoder__DOT__projection_inst__DOT__state;
    vlSelfRef.complete_transformer_decoder__DOT__projection_inst__DOT__proj_addr 
        = (0x00000fffU & (((IData)(0x00000028U) * (IData)(vlSelfRef.complete_transformer_decoder__DOT__projection_inst__DOT__dim_idx)) 
                          + (IData)(vlSelfRef.complete_transformer_decoder__DOT__projection_inst__DOT__vocab_idx)));
    vlSelfRef.complete_transformer_decoder__DOT__positional_inst__DOT__state 
        = __Vdly__complete_transformer_decoder__DOT__positional_inst__DOT__state;
    vlSelfRef.complete_transformer_decoder__DOT__positional_inst__DOT__seq_idx 
        = __Vdly__complete_transformer_decoder__DOT__positional_inst__DOT__seq_idx;
    vlSelfRef.complete_transformer_decoder__DOT__positional_inst__DOT__dim_idx 
        = __Vdly__complete_transformer_decoder__DOT__positional_inst__DOT__dim_idx;
    vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__state 
        = __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__state;
    vlSelfRef.complete_transformer_decoder__DOT__layer_norm1_inst__DOT__dim_idx 
        = __Vdly__complete_transformer_decoder__DOT__layer_norm1_inst__DOT__dim_idx;
    vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__state 
        = __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__state;
    vlSelfRef.complete_transformer_decoder__DOT__layer_norm2_inst__DOT__dim_idx 
        = __Vdly__complete_transformer_decoder__DOT__layer_norm2_inst__DOT__dim_idx;
    vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__in_dim 
        = __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__in_dim;
    vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__out_dim 
        = __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__out_dim;
    vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__state 
        = __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__state;
    vlSelfRef.complete_transformer_decoder__DOT__ffn_inst__DOT__hidden_dim 
        = __Vdly__complete_transformer_decoder__DOT__ffn_inst__DOT__hidden_dim;
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__state 
        = __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__state;
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__in_dim 
        = __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__in_dim;
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__out_dim 
        = __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__out_dim;
    if (vlSelfRef.rst) {
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__state = 0U;
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx = 0U;
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx2 = 0U;
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__embed_idx = 0U;
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__head_idx = 0U;
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__pipe_stage = 0U;
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__accumulator = 0U;
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__3__KET____DOT__head__done = 0U;
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__3__KET____DOT__head__valid = 0U;
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_start = 0U;
    } else {
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_start = 0U;
        if (((((((((0U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__state)) 
                   | (1U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__state))) 
                  | (2U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__state))) 
                 | (3U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__state))) 
                | (4U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__state))) 
               | (5U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__state))) 
              | (6U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__state))) 
             | (7U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__state)))) {
            if ((0U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__state))) {
                vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__3__KET____DOT__head__done = 0U;
                vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__3__KET____DOT__head__valid = 0U;
                if ((8U & (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_start_signals))) {
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__state = 1U;
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx = 0U;
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__embed_idx = 0U;
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__head_idx = 0U;
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__pipe_stage = 0U;
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__accumulator = 0U;
                }
            } else if ((1U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__state))) {
                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__pipe_stage 
                    = (7U & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__pipe_stage)));
                if ((2U <= (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__pipe_stage))) {
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__accumulator 
                        = (vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__accumulator 
                           + VL_MULS_III(32, VL_EXTENDS_II(32,16, vlSelfRef.complete_transformer_decoder__DOT__position_encoded
                                                           [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx]
                                                           [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__embed_idx]), 
                                         VL_EXTENDS_II(32,16, (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__wq_data))));
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__pipe_stage = 0U;
                    if ((0x0fU == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__embed_idx))) {
                        __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__Q__v0 
                            = (0x0000ffffU & VL_SHIFTRS_III(16,32,32, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__accumulator, 8U));
                        __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__Q__v0 
                            = (3U & (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__head_idx));
                        __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__Q__v0 
                            = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx;
                        __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__Q__v0 = 1U;
                        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__embed_idx = 0U;
                        if ((3U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__head_idx))) {
                            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__head_idx = 0U;
                            if ((7U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx))) {
                                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__state = 2U;
                                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx = 0U;
                            } else {
                                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx 
                                    = (7U & ((IData)(1U) 
                                             + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx)));
                            }
                        } else {
                            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__head_idx 
                                = (0x0000000fU & ((IData)(1U) 
                                                  + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__head_idx)));
                        }
                        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__accumulator = 0U;
                    } else {
                        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__embed_idx 
                            = (0x0000000fU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__embed_idx)));
                    }
                }
            } else if ((2U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__state))) {
                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__pipe_stage 
                    = (7U & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__pipe_stage)));
                if ((2U <= (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__pipe_stage))) {
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__accumulator 
                        = (vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__accumulator 
                           + VL_MULS_III(32, VL_EXTENDS_II(32,16, vlSelfRef.complete_transformer_decoder__DOT__position_encoded
                                                           [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx]
                                                           [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__embed_idx]), 
                                         VL_EXTENDS_II(32,16, (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__wk_data))));
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__pipe_stage = 0U;
                    if ((0x0fU == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__embed_idx))) {
                        __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__K__v0 
                            = (0x0000ffffU & VL_SHIFTRS_III(16,32,32, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__accumulator, 8U));
                        __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__K__v0 
                            = (3U & (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__head_idx));
                        __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__K__v0 
                            = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx;
                        __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__K__v0 = 1U;
                        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__embed_idx = 0U;
                        if ((3U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__head_idx))) {
                            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__head_idx = 0U;
                            if ((7U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx))) {
                                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__state = 3U;
                                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx = 0U;
                            } else {
                                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx 
                                    = (7U & ((IData)(1U) 
                                             + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx)));
                            }
                        } else {
                            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__head_idx 
                                = (0x0000000fU & ((IData)(1U) 
                                                  + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__head_idx)));
                        }
                        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__accumulator = 0U;
                    } else {
                        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__embed_idx 
                            = (0x0000000fU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__embed_idx)));
                    }
                }
            } else if ((3U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__state))) {
                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__pipe_stage 
                    = (7U & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__pipe_stage)));
                if ((2U <= (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__pipe_stage))) {
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__accumulator 
                        = (vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__accumulator 
                           + VL_MULS_III(32, VL_EXTENDS_II(32,16, vlSelfRef.complete_transformer_decoder__DOT__position_encoded
                                                           [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx]
                                                           [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__embed_idx]), 
                                         VL_EXTENDS_II(32,16, (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__wv_data))));
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__pipe_stage = 0U;
                    if ((0x0fU == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__embed_idx))) {
                        __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__V__v0 
                            = (0x0000ffffU & VL_SHIFTRS_III(16,32,32, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__accumulator, 8U));
                        __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__V__v0 
                            = (3U & (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__head_idx));
                        __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__V__v0 
                            = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx;
                        __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__V__v0 = 1U;
                        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__embed_idx = 0U;
                        if ((3U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__head_idx))) {
                            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__head_idx = 0U;
                            if ((7U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx))) {
                                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__state = 4U;
                                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx = 0U;
                                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx2 = 0U;
                                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__head_idx = 0U;
                            } else {
                                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx 
                                    = (7U & ((IData)(1U) 
                                             + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx)));
                            }
                        } else {
                            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__head_idx 
                                = (0x0000000fU & ((IData)(1U) 
                                                  + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__head_idx)));
                        }
                        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__accumulator = 0U;
                    } else {
                        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__embed_idx 
                            = (0x0000000fU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__embed_idx)));
                    }
                }
            } else if ((4U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__state))) {
                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__accumulator 
                    = ((0U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__head_idx))
                        ? VL_MULS_III(32, VL_EXTENDS_II(32,16, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__Q
                                                        [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx]
                                                        [
                                                        (3U 
                                                         & (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__head_idx))]), 
                                      VL_EXTENDS_II(32,16, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__K
                                                    [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx2]
                                                    [
                                                    (3U 
                                                     & (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__head_idx))]))
                        : (vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__accumulator 
                           + VL_MULS_III(32, VL_EXTENDS_II(32,16, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__Q
                                                           [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx]
                                                           [
                                                           (3U 
                                                            & (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__head_idx))]), 
                                         VL_EXTENDS_II(32,16, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__K
                                                       [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx2]
                                                       [
                                                       (3U 
                                                        & (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__head_idx))]))));
                if ((3U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__head_idx))) {
                    if (((IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx2) 
                         <= (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx))) {
                        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__unnamedblk2__DOT__scaled_score 
                            = (VL_SHIFTRS_III(32,32,32, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__accumulator, 2U) 
                               + VL_SHIFTRS_III(32,32,32, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__accumulator, 4U));
                        __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_scores__v0 
                            = (VL_LTS_III(32, 0x00007fffU, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__unnamedblk2__DOT__scaled_score)
                                ? 0x00007fffU : (VL_GTS_III(32, 0xffff8000U, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__unnamedblk2__DOT__scaled_score)
                                                  ? 0x00008000U
                                                  : 
                                                 (0x0000ffffU 
                                                  & vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__unnamedblk2__DOT__scaled_score)));
                        __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_scores__v0 
                            = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx2;
                        __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_scores__v0 
                            = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx;
                        __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_scores__v0 = 1U;
                    } else {
                        __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_scores__v1 
                            = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx2;
                        __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_scores__v1 
                            = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx;
                        __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_scores__v1 = 1U;
                    }
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__head_idx = 0U;
                    if ((7U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx2))) {
                        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx2 = 0U;
                        if ((7U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx))) {
                            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__state = 5U;
                            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_start = 1U;
                        } else {
                            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx 
                                = (7U & ((IData)(1U) 
                                         + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx)));
                        }
                    } else {
                        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx2 
                            = (7U & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx2)));
                    }
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__accumulator = 0U;
                } else {
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__head_idx 
                        = (0x0000000fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__head_idx)));
                }
            } else if ((5U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__state))) {
                if (vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_done) {
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__state = 6U;
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx = 0U;
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx2 = 0U;
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__head_idx = 0U;
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__accumulator = 0U;
                }
            } else if ((6U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__state))) {
                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__accumulator 
                    = ((0U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx2))
                        ? VL_MULS_III(32, VL_EXTENDS_II(32,16, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_weights
                                                        [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx]
                                                        [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx2]), 
                                      VL_EXTENDS_II(32,16, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__V
                                                    [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx2]
                                                    [
                                                    (3U 
                                                     & (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__head_idx))]))
                        : (vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__accumulator 
                           + VL_MULS_III(32, VL_EXTENDS_II(32,16, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_weights
                                                           [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx]
                                                           [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx2]), 
                                         VL_EXTENDS_II(32,16, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__V
                                                       [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx2]
                                                       [
                                                       (3U 
                                                        & (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__head_idx))]))));
                if ((7U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx2))) {
                    __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__3__KET____DOT__head__output_data__v0 
                        = (0x0000ffffU & VL_SHIFTRS_III(16,32,32, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__accumulator, 0x0000000cU));
                    __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__3__KET____DOT__head__output_data__v0 
                        = (3U & (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__head_idx));
                    __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__3__KET____DOT__head__output_data__v0 
                        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx;
                    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__3__KET____DOT__head__output_data__v0 = 1U;
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx2 = 0U;
                    if ((3U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__head_idx))) {
                        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__head_idx = 0U;
                        if ((7U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx))) {
                            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__state = 7U;
                        } else {
                            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx 
                                = (7U & ((IData)(1U) 
                                         + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx)));
                        }
                    } else {
                        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__head_idx 
                            = (0x0000000fU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__head_idx)));
                    }
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__accumulator = 0U;
                } else {
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx2 
                        = (7U & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx2)));
                }
            } else {
                vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__3__KET____DOT__head__done = 1U;
                vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__3__KET____DOT__head__valid = 1U;
                if ((1U & (~ ((IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_start_signals) 
                              >> 3U)))) {
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__state = 0U;
                }
            }
        }
    }
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx 
        = __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx;
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx2 
        = __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__seq_idx2;
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__pipe_stage 
        = __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__pipe_stage;
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__accumulator 
        = __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__accumulator;
    if (__VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__Q__v0) {
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__Q[__VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__Q__v0][__VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__Q__v0] 
            = __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__Q__v0;
    }
    if (__VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__K__v0) {
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__K[__VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__K__v0][__VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__K__v0] 
            = __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__K__v0;
    }
    if (__VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__V__v0) {
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__V[__VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__V__v0][__VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__V__v0] 
            = __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__V__v0;
    }
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__embed_idx 
        = __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__embed_idx;
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__head_idx 
        = __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__head_idx;
    if (__VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__3__KET____DOT__head__output_data__v0) {
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__3__KET____DOT__head__output_data[__VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__3__KET____DOT__head__output_data__v0][__VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__3__KET____DOT__head__output_data__v0] 
            = __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__3__KET____DOT__head__output_data__v0;
    }
    if (vlSelfRef.rst) {
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__state = 0U;
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx = 0U;
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx2 = 0U;
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__embed_idx = 0U;
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__head_idx = 0U;
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__pipe_stage = 0U;
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__accumulator = 0U;
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__2__KET____DOT__head__done = 0U;
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__2__KET____DOT__head__valid = 0U;
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_start = 0U;
    } else {
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_start = 0U;
        if (((((((((0U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__state)) 
                   | (1U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__state))) 
                  | (2U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__state))) 
                 | (3U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__state))) 
                | (4U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__state))) 
               | (5U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__state))) 
              | (6U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__state))) 
             | (7U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__state)))) {
            if ((0U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__state))) {
                vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__2__KET____DOT__head__done = 0U;
                vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__2__KET____DOT__head__valid = 0U;
                if ((4U & (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_start_signals))) {
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__state = 1U;
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx = 0U;
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__embed_idx = 0U;
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__head_idx = 0U;
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__pipe_stage = 0U;
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__accumulator = 0U;
                }
            } else if ((1U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__state))) {
                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__pipe_stage 
                    = (7U & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__pipe_stage)));
                if ((2U <= (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__pipe_stage))) {
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__accumulator 
                        = (vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__accumulator 
                           + VL_MULS_III(32, VL_EXTENDS_II(32,16, vlSelfRef.complete_transformer_decoder__DOT__position_encoded
                                                           [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx]
                                                           [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__embed_idx]), 
                                         VL_EXTENDS_II(32,16, (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__wq_data))));
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__pipe_stage = 0U;
                    if ((0x0fU == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__embed_idx))) {
                        __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__Q__v0 
                            = (0x0000ffffU & VL_SHIFTRS_III(16,32,32, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__accumulator, 8U));
                        __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__Q__v0 
                            = (3U & (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__head_idx));
                        __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__Q__v0 
                            = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx;
                        __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__Q__v0 = 1U;
                        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__embed_idx = 0U;
                        if ((3U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__head_idx))) {
                            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__head_idx = 0U;
                            if ((7U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx))) {
                                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__state = 2U;
                                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx = 0U;
                            } else {
                                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx 
                                    = (7U & ((IData)(1U) 
                                             + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx)));
                            }
                        } else {
                            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__head_idx 
                                = (0x0000000fU & ((IData)(1U) 
                                                  + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__head_idx)));
                        }
                        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__accumulator = 0U;
                    } else {
                        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__embed_idx 
                            = (0x0000000fU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__embed_idx)));
                    }
                }
            } else if ((2U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__state))) {
                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__pipe_stage 
                    = (7U & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__pipe_stage)));
                if ((2U <= (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__pipe_stage))) {
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__accumulator 
                        = (vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__accumulator 
                           + VL_MULS_III(32, VL_EXTENDS_II(32,16, vlSelfRef.complete_transformer_decoder__DOT__position_encoded
                                                           [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx]
                                                           [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__embed_idx]), 
                                         VL_EXTENDS_II(32,16, (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__wk_data))));
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__pipe_stage = 0U;
                    if ((0x0fU == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__embed_idx))) {
                        __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__K__v0 
                            = (0x0000ffffU & VL_SHIFTRS_III(16,32,32, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__accumulator, 8U));
                        __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__K__v0 
                            = (3U & (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__head_idx));
                        __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__K__v0 
                            = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx;
                        __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__K__v0 = 1U;
                        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__embed_idx = 0U;
                        if ((3U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__head_idx))) {
                            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__head_idx = 0U;
                            if ((7U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx))) {
                                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__state = 3U;
                                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx = 0U;
                            } else {
                                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx 
                                    = (7U & ((IData)(1U) 
                                             + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx)));
                            }
                        } else {
                            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__head_idx 
                                = (0x0000000fU & ((IData)(1U) 
                                                  + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__head_idx)));
                        }
                        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__accumulator = 0U;
                    } else {
                        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__embed_idx 
                            = (0x0000000fU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__embed_idx)));
                    }
                }
            } else if ((3U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__state))) {
                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__pipe_stage 
                    = (7U & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__pipe_stage)));
                if ((2U <= (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__pipe_stage))) {
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__accumulator 
                        = (vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__accumulator 
                           + VL_MULS_III(32, VL_EXTENDS_II(32,16, vlSelfRef.complete_transformer_decoder__DOT__position_encoded
                                                           [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx]
                                                           [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__embed_idx]), 
                                         VL_EXTENDS_II(32,16, (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__wv_data))));
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__pipe_stage = 0U;
                    if ((0x0fU == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__embed_idx))) {
                        __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__V__v0 
                            = (0x0000ffffU & VL_SHIFTRS_III(16,32,32, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__accumulator, 8U));
                        __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__V__v0 
                            = (3U & (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__head_idx));
                        __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__V__v0 
                            = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx;
                        __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__V__v0 = 1U;
                        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__embed_idx = 0U;
                        if ((3U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__head_idx))) {
                            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__head_idx = 0U;
                            if ((7U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx))) {
                                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__state = 4U;
                                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx = 0U;
                                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx2 = 0U;
                                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__head_idx = 0U;
                            } else {
                                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx 
                                    = (7U & ((IData)(1U) 
                                             + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx)));
                            }
                        } else {
                            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__head_idx 
                                = (0x0000000fU & ((IData)(1U) 
                                                  + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__head_idx)));
                        }
                        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__accumulator = 0U;
                    } else {
                        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__embed_idx 
                            = (0x0000000fU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__embed_idx)));
                    }
                }
            } else if ((4U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__state))) {
                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__accumulator 
                    = ((0U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__head_idx))
                        ? VL_MULS_III(32, VL_EXTENDS_II(32,16, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__Q
                                                        [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx]
                                                        [
                                                        (3U 
                                                         & (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__head_idx))]), 
                                      VL_EXTENDS_II(32,16, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__K
                                                    [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx2]
                                                    [
                                                    (3U 
                                                     & (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__head_idx))]))
                        : (vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__accumulator 
                           + VL_MULS_III(32, VL_EXTENDS_II(32,16, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__Q
                                                           [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx]
                                                           [
                                                           (3U 
                                                            & (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__head_idx))]), 
                                         VL_EXTENDS_II(32,16, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__K
                                                       [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx2]
                                                       [
                                                       (3U 
                                                        & (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__head_idx))]))));
                if ((3U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__head_idx))) {
                    if (((IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx2) 
                         <= (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx))) {
                        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__unnamedblk2__DOT__scaled_score 
                            = (VL_SHIFTRS_III(32,32,32, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__accumulator, 2U) 
                               + VL_SHIFTRS_III(32,32,32, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__accumulator, 4U));
                        __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_scores__v0 
                            = (VL_LTS_III(32, 0x00007fffU, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__unnamedblk2__DOT__scaled_score)
                                ? 0x00007fffU : (VL_GTS_III(32, 0xffff8000U, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__unnamedblk2__DOT__scaled_score)
                                                  ? 0x00008000U
                                                  : 
                                                 (0x0000ffffU 
                                                  & vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__unnamedblk2__DOT__scaled_score)));
                        __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_scores__v0 
                            = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx2;
                        __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_scores__v0 
                            = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx;
                        __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_scores__v0 = 1U;
                    } else {
                        __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_scores__v1 
                            = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx2;
                        __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_scores__v1 
                            = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx;
                        __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_scores__v1 = 1U;
                    }
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__head_idx = 0U;
                    if ((7U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx2))) {
                        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx2 = 0U;
                        if ((7U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx))) {
                            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__state = 5U;
                            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_start = 1U;
                        } else {
                            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx 
                                = (7U & ((IData)(1U) 
                                         + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx)));
                        }
                    } else {
                        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx2 
                            = (7U & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx2)));
                    }
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__accumulator = 0U;
                } else {
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__head_idx 
                        = (0x0000000fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__head_idx)));
                }
            } else if ((5U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__state))) {
                if (vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_done) {
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__state = 6U;
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx = 0U;
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx2 = 0U;
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__head_idx = 0U;
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__accumulator = 0U;
                }
            } else if ((6U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__state))) {
                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__accumulator 
                    = ((0U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx2))
                        ? VL_MULS_III(32, VL_EXTENDS_II(32,16, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_weights
                                                        [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx]
                                                        [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx2]), 
                                      VL_EXTENDS_II(32,16, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__V
                                                    [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx2]
                                                    [
                                                    (3U 
                                                     & (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__head_idx))]))
                        : (vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__accumulator 
                           + VL_MULS_III(32, VL_EXTENDS_II(32,16, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_weights
                                                           [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx]
                                                           [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx2]), 
                                         VL_EXTENDS_II(32,16, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__V
                                                       [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx2]
                                                       [
                                                       (3U 
                                                        & (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__head_idx))]))));
                if ((7U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx2))) {
                    __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__2__KET____DOT__head__output_data__v0 
                        = (0x0000ffffU & VL_SHIFTRS_III(16,32,32, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__accumulator, 0x0000000cU));
                    __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__2__KET____DOT__head__output_data__v0 
                        = (3U & (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__head_idx));
                    __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__2__KET____DOT__head__output_data__v0 
                        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx;
                    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__2__KET____DOT__head__output_data__v0 = 1U;
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx2 = 0U;
                    if ((3U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__head_idx))) {
                        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__head_idx = 0U;
                        if ((7U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx))) {
                            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__state = 7U;
                        } else {
                            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx 
                                = (7U & ((IData)(1U) 
                                         + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx)));
                        }
                    } else {
                        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__head_idx 
                            = (0x0000000fU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__head_idx)));
                    }
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__accumulator = 0U;
                } else {
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx2 
                        = (7U & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx2)));
                }
            } else {
                vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__2__KET____DOT__head__done = 1U;
                vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__2__KET____DOT__head__valid = 1U;
                if ((1U & (~ ((IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_start_signals) 
                              >> 2U)))) {
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__state = 0U;
                }
            }
        }
    }
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx 
        = __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx;
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx2 
        = __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__seq_idx2;
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__pipe_stage 
        = __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__pipe_stage;
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__accumulator 
        = __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__accumulator;
    if (__VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__Q__v0) {
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__Q[__VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__Q__v0][__VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__Q__v0] 
            = __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__Q__v0;
    }
    if (__VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__K__v0) {
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__K[__VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__K__v0][__VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__K__v0] 
            = __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__K__v0;
    }
    if (__VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__V__v0) {
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__V[__VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__V__v0][__VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__V__v0] 
            = __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__V__v0;
    }
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__embed_idx 
        = __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__embed_idx;
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__head_idx 
        = __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__head_idx;
    if (__VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__2__KET____DOT__head__output_data__v0) {
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__2__KET____DOT__head__output_data[__VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__2__KET____DOT__head__output_data__v0][__VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__2__KET____DOT__head__output_data__v0] 
            = __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__2__KET____DOT__head__output_data__v0;
    }
    if (vlSelfRef.rst) {
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__state = 0U;
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx = 0U;
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx2 = 0U;
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__embed_idx = 0U;
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__head_idx = 0U;
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__pipe_stage = 0U;
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__accumulator = 0U;
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__1__KET____DOT__head__done = 0U;
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__1__KET____DOT__head__valid = 0U;
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_start = 0U;
    } else {
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_start = 0U;
        if (((((((((0U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__state)) 
                   | (1U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__state))) 
                  | (2U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__state))) 
                 | (3U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__state))) 
                | (4U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__state))) 
               | (5U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__state))) 
              | (6U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__state))) 
             | (7U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__state)))) {
            if ((0U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__state))) {
                vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__1__KET____DOT__head__done = 0U;
                vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__1__KET____DOT__head__valid = 0U;
                if ((2U & (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_start_signals))) {
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__state = 1U;
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx = 0U;
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__embed_idx = 0U;
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__head_idx = 0U;
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__pipe_stage = 0U;
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__accumulator = 0U;
                }
            } else if ((1U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__state))) {
                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__pipe_stage 
                    = (7U & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__pipe_stage)));
                if ((2U <= (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__pipe_stage))) {
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__accumulator 
                        = (vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__accumulator 
                           + VL_MULS_III(32, VL_EXTENDS_II(32,16, vlSelfRef.complete_transformer_decoder__DOT__position_encoded
                                                           [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx]
                                                           [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__embed_idx]), 
                                         VL_EXTENDS_II(32,16, (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__wq_data))));
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__pipe_stage = 0U;
                    if ((0x0fU == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__embed_idx))) {
                        __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__Q__v0 
                            = (0x0000ffffU & VL_SHIFTRS_III(16,32,32, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__accumulator, 8U));
                        __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__Q__v0 
                            = (3U & (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__head_idx));
                        __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__Q__v0 
                            = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx;
                        __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__Q__v0 = 1U;
                        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__embed_idx = 0U;
                        if ((3U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__head_idx))) {
                            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__head_idx = 0U;
                            if ((7U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx))) {
                                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__state = 2U;
                                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx = 0U;
                            } else {
                                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx 
                                    = (7U & ((IData)(1U) 
                                             + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx)));
                            }
                        } else {
                            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__head_idx 
                                = (0x0000000fU & ((IData)(1U) 
                                                  + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__head_idx)));
                        }
                        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__accumulator = 0U;
                    } else {
                        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__embed_idx 
                            = (0x0000000fU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__embed_idx)));
                    }
                }
            } else if ((2U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__state))) {
                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__pipe_stage 
                    = (7U & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__pipe_stage)));
                if ((2U <= (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__pipe_stage))) {
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__accumulator 
                        = (vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__accumulator 
                           + VL_MULS_III(32, VL_EXTENDS_II(32,16, vlSelfRef.complete_transformer_decoder__DOT__position_encoded
                                                           [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx]
                                                           [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__embed_idx]), 
                                         VL_EXTENDS_II(32,16, (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__wk_data))));
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__pipe_stage = 0U;
                    if ((0x0fU == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__embed_idx))) {
                        __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__K__v0 
                            = (0x0000ffffU & VL_SHIFTRS_III(16,32,32, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__accumulator, 8U));
                        __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__K__v0 
                            = (3U & (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__head_idx));
                        __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__K__v0 
                            = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx;
                        __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__K__v0 = 1U;
                        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__embed_idx = 0U;
                        if ((3U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__head_idx))) {
                            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__head_idx = 0U;
                            if ((7U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx))) {
                                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__state = 3U;
                                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx = 0U;
                            } else {
                                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx 
                                    = (7U & ((IData)(1U) 
                                             + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx)));
                            }
                        } else {
                            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__head_idx 
                                = (0x0000000fU & ((IData)(1U) 
                                                  + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__head_idx)));
                        }
                        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__accumulator = 0U;
                    } else {
                        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__embed_idx 
                            = (0x0000000fU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__embed_idx)));
                    }
                }
            } else if ((3U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__state))) {
                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__pipe_stage 
                    = (7U & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__pipe_stage)));
                if ((2U <= (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__pipe_stage))) {
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__accumulator 
                        = (vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__accumulator 
                           + VL_MULS_III(32, VL_EXTENDS_II(32,16, vlSelfRef.complete_transformer_decoder__DOT__position_encoded
                                                           [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx]
                                                           [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__embed_idx]), 
                                         VL_EXTENDS_II(32,16, (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__wv_data))));
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__pipe_stage = 0U;
                    if ((0x0fU == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__embed_idx))) {
                        __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__V__v0 
                            = (0x0000ffffU & VL_SHIFTRS_III(16,32,32, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__accumulator, 8U));
                        __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__V__v0 
                            = (3U & (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__head_idx));
                        __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__V__v0 
                            = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx;
                        __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__V__v0 = 1U;
                        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__embed_idx = 0U;
                        if ((3U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__head_idx))) {
                            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__head_idx = 0U;
                            if ((7U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx))) {
                                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__state = 4U;
                                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx = 0U;
                                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx2 = 0U;
                                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__head_idx = 0U;
                            } else {
                                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx 
                                    = (7U & ((IData)(1U) 
                                             + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx)));
                            }
                        } else {
                            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__head_idx 
                                = (0x0000000fU & ((IData)(1U) 
                                                  + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__head_idx)));
                        }
                        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__accumulator = 0U;
                    } else {
                        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__embed_idx 
                            = (0x0000000fU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__embed_idx)));
                    }
                }
            } else if ((4U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__state))) {
                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__accumulator 
                    = ((0U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__head_idx))
                        ? VL_MULS_III(32, VL_EXTENDS_II(32,16, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__Q
                                                        [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx]
                                                        [
                                                        (3U 
                                                         & (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__head_idx))]), 
                                      VL_EXTENDS_II(32,16, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__K
                                                    [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx2]
                                                    [
                                                    (3U 
                                                     & (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__head_idx))]))
                        : (vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__accumulator 
                           + VL_MULS_III(32, VL_EXTENDS_II(32,16, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__Q
                                                           [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx]
                                                           [
                                                           (3U 
                                                            & (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__head_idx))]), 
                                         VL_EXTENDS_II(32,16, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__K
                                                       [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx2]
                                                       [
                                                       (3U 
                                                        & (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__head_idx))]))));
                if ((3U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__head_idx))) {
                    if (((IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx2) 
                         <= (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx))) {
                        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__unnamedblk2__DOT__scaled_score 
                            = (VL_SHIFTRS_III(32,32,32, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__accumulator, 2U) 
                               + VL_SHIFTRS_III(32,32,32, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__accumulator, 4U));
                        __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_scores__v0 
                            = (VL_LTS_III(32, 0x00007fffU, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__unnamedblk2__DOT__scaled_score)
                                ? 0x00007fffU : (VL_GTS_III(32, 0xffff8000U, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__unnamedblk2__DOT__scaled_score)
                                                  ? 0x00008000U
                                                  : 
                                                 (0x0000ffffU 
                                                  & vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__unnamedblk2__DOT__scaled_score)));
                        __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_scores__v0 
                            = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx2;
                        __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_scores__v0 
                            = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx;
                        __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_scores__v0 = 1U;
                    } else {
                        __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_scores__v1 
                            = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx2;
                        __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_scores__v1 
                            = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx;
                        __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_scores__v1 = 1U;
                    }
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__head_idx = 0U;
                    if ((7U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx2))) {
                        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx2 = 0U;
                        if ((7U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx))) {
                            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__state = 5U;
                            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_start = 1U;
                        } else {
                            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx 
                                = (7U & ((IData)(1U) 
                                         + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx)));
                        }
                    } else {
                        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx2 
                            = (7U & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx2)));
                    }
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__accumulator = 0U;
                } else {
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__head_idx 
                        = (0x0000000fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__head_idx)));
                }
            } else if ((5U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__state))) {
                if (vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_done) {
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__state = 6U;
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx = 0U;
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx2 = 0U;
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__head_idx = 0U;
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__accumulator = 0U;
                }
            } else if ((6U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__state))) {
                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__accumulator 
                    = ((0U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx2))
                        ? VL_MULS_III(32, VL_EXTENDS_II(32,16, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_weights
                                                        [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx]
                                                        [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx2]), 
                                      VL_EXTENDS_II(32,16, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__V
                                                    [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx2]
                                                    [
                                                    (3U 
                                                     & (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__head_idx))]))
                        : (vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__accumulator 
                           + VL_MULS_III(32, VL_EXTENDS_II(32,16, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_weights
                                                           [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx]
                                                           [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx2]), 
                                         VL_EXTENDS_II(32,16, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__V
                                                       [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx2]
                                                       [
                                                       (3U 
                                                        & (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__head_idx))]))));
                if ((7U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx2))) {
                    __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__1__KET____DOT__head__output_data__v0 
                        = (0x0000ffffU & VL_SHIFTRS_III(16,32,32, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__accumulator, 0x0000000cU));
                    __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__1__KET____DOT__head__output_data__v0 
                        = (3U & (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__head_idx));
                    __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__1__KET____DOT__head__output_data__v0 
                        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx;
                    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__1__KET____DOT__head__output_data__v0 = 1U;
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx2 = 0U;
                    if ((3U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__head_idx))) {
                        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__head_idx = 0U;
                        if ((7U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx))) {
                            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__state = 7U;
                        } else {
                            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx 
                                = (7U & ((IData)(1U) 
                                         + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx)));
                        }
                    } else {
                        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__head_idx 
                            = (0x0000000fU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__head_idx)));
                    }
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__accumulator = 0U;
                } else {
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx2 
                        = (7U & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx2)));
                }
            } else {
                vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__1__KET____DOT__head__done = 1U;
                vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__1__KET____DOT__head__valid = 1U;
                if ((1U & (~ ((IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_start_signals) 
                              >> 1U)))) {
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__state = 0U;
                }
            }
        }
    }
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx 
        = __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx;
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx2 
        = __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__seq_idx2;
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__pipe_stage 
        = __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__pipe_stage;
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__accumulator 
        = __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__accumulator;
    if (__VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__Q__v0) {
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__Q[__VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__Q__v0][__VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__Q__v0] 
            = __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__Q__v0;
    }
    if (__VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__K__v0) {
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__K[__VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__K__v0][__VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__K__v0] 
            = __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__K__v0;
    }
    if (__VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__V__v0) {
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__V[__VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__V__v0][__VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__V__v0] 
            = __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__V__v0;
    }
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__embed_idx 
        = __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__embed_idx;
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__head_idx 
        = __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__head_idx;
    if (__VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__1__KET____DOT__head__output_data__v0) {
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__1__KET____DOT__head__output_data[__VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__1__KET____DOT__head__output_data__v0][__VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__1__KET____DOT__head__output_data__v0] 
            = __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__1__KET____DOT__head__output_data__v0;
    }
    if (vlSelfRef.rst) {
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__state = 0U;
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx = 0U;
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx2 = 0U;
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__embed_idx = 0U;
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__head_idx = 0U;
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__pipe_stage = 0U;
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__accumulator = 0U;
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__0__KET____DOT__head__done = 0U;
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__0__KET____DOT__head__valid = 0U;
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_start = 0U;
    } else {
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_start = 0U;
        if (((((((((0U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__state)) 
                   | (1U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__state))) 
                  | (2U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__state))) 
                 | (3U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__state))) 
                | (4U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__state))) 
               | (5U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__state))) 
              | (6U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__state))) 
             | (7U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__state)))) {
            if ((0U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__state))) {
                vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__0__KET____DOT__head__done = 0U;
                vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__0__KET____DOT__head__valid = 0U;
                if ((1U & (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_start_signals))) {
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__state = 1U;
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx = 0U;
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__embed_idx = 0U;
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__head_idx = 0U;
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__pipe_stage = 0U;
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__accumulator = 0U;
                }
            } else if ((1U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__state))) {
                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__pipe_stage 
                    = (7U & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__pipe_stage)));
                if ((2U <= (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__pipe_stage))) {
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__accumulator 
                        = (vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__accumulator 
                           + VL_MULS_III(32, VL_EXTENDS_II(32,16, vlSelfRef.complete_transformer_decoder__DOT__position_encoded
                                                           [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx]
                                                           [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__embed_idx]), 
                                         VL_EXTENDS_II(32,16, (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__wq_data))));
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__pipe_stage = 0U;
                    if ((0x0fU == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__embed_idx))) {
                        __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__Q__v0 
                            = (0x0000ffffU & VL_SHIFTRS_III(16,32,32, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__accumulator, 8U));
                        __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__Q__v0 
                            = (3U & (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__head_idx));
                        __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__Q__v0 
                            = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx;
                        __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__Q__v0 = 1U;
                        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__embed_idx = 0U;
                        if ((3U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__head_idx))) {
                            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__head_idx = 0U;
                            if ((7U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx))) {
                                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__state = 2U;
                                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx = 0U;
                            } else {
                                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx 
                                    = (7U & ((IData)(1U) 
                                             + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx)));
                            }
                        } else {
                            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__head_idx 
                                = (0x0000000fU & ((IData)(1U) 
                                                  + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__head_idx)));
                        }
                        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__accumulator = 0U;
                    } else {
                        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__embed_idx 
                            = (0x0000000fU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__embed_idx)));
                    }
                }
            } else if ((2U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__state))) {
                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__pipe_stage 
                    = (7U & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__pipe_stage)));
                if ((2U <= (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__pipe_stage))) {
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__accumulator 
                        = (vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__accumulator 
                           + VL_MULS_III(32, VL_EXTENDS_II(32,16, vlSelfRef.complete_transformer_decoder__DOT__position_encoded
                                                           [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx]
                                                           [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__embed_idx]), 
                                         VL_EXTENDS_II(32,16, (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__wk_data))));
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__pipe_stage = 0U;
                    if ((0x0fU == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__embed_idx))) {
                        __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__K__v0 
                            = (0x0000ffffU & VL_SHIFTRS_III(16,32,32, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__accumulator, 8U));
                        __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__K__v0 
                            = (3U & (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__head_idx));
                        __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__K__v0 
                            = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx;
                        __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__K__v0 = 1U;
                        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__embed_idx = 0U;
                        if ((3U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__head_idx))) {
                            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__head_idx = 0U;
                            if ((7U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx))) {
                                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__state = 3U;
                                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx = 0U;
                            } else {
                                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx 
                                    = (7U & ((IData)(1U) 
                                             + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx)));
                            }
                        } else {
                            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__head_idx 
                                = (0x0000000fU & ((IData)(1U) 
                                                  + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__head_idx)));
                        }
                        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__accumulator = 0U;
                    } else {
                        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__embed_idx 
                            = (0x0000000fU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__embed_idx)));
                    }
                }
            } else if ((3U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__state))) {
                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__pipe_stage 
                    = (7U & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__pipe_stage)));
                if ((2U <= (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__pipe_stage))) {
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__accumulator 
                        = (vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__accumulator 
                           + VL_MULS_III(32, VL_EXTENDS_II(32,16, vlSelfRef.complete_transformer_decoder__DOT__position_encoded
                                                           [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx]
                                                           [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__embed_idx]), 
                                         VL_EXTENDS_II(32,16, (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__wv_data))));
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__pipe_stage = 0U;
                    if ((0x0fU == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__embed_idx))) {
                        __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__V__v0 
                            = (0x0000ffffU & VL_SHIFTRS_III(16,32,32, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__accumulator, 8U));
                        __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__V__v0 
                            = (3U & (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__head_idx));
                        __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__V__v0 
                            = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx;
                        __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__V__v0 = 1U;
                        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__embed_idx = 0U;
                        if ((3U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__head_idx))) {
                            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__head_idx = 0U;
                            if ((7U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx))) {
                                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__state = 4U;
                                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx = 0U;
                                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx2 = 0U;
                                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__head_idx = 0U;
                            } else {
                                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx 
                                    = (7U & ((IData)(1U) 
                                             + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx)));
                            }
                        } else {
                            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__head_idx 
                                = (0x0000000fU & ((IData)(1U) 
                                                  + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__head_idx)));
                        }
                        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__accumulator = 0U;
                    } else {
                        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__embed_idx 
                            = (0x0000000fU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__embed_idx)));
                    }
                }
            } else if ((4U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__state))) {
                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__accumulator 
                    = ((0U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__head_idx))
                        ? VL_MULS_III(32, VL_EXTENDS_II(32,16, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__Q
                                                        [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx]
                                                        [
                                                        (3U 
                                                         & (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__head_idx))]), 
                                      VL_EXTENDS_II(32,16, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__K
                                                    [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx2]
                                                    [
                                                    (3U 
                                                     & (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__head_idx))]))
                        : (vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__accumulator 
                           + VL_MULS_III(32, VL_EXTENDS_II(32,16, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__Q
                                                           [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx]
                                                           [
                                                           (3U 
                                                            & (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__head_idx))]), 
                                         VL_EXTENDS_II(32,16, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__K
                                                       [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx2]
                                                       [
                                                       (3U 
                                                        & (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__head_idx))]))));
                if ((3U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__head_idx))) {
                    if (((IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx2) 
                         <= (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx))) {
                        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__unnamedblk2__DOT__scaled_score 
                            = (VL_SHIFTRS_III(32,32,32, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__accumulator, 2U) 
                               + VL_SHIFTRS_III(32,32,32, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__accumulator, 4U));
                        __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_scores__v0 
                            = (VL_LTS_III(32, 0x00007fffU, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__unnamedblk2__DOT__scaled_score)
                                ? 0x00007fffU : (VL_GTS_III(32, 0xffff8000U, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__unnamedblk2__DOT__scaled_score)
                                                  ? 0x00008000U
                                                  : 
                                                 (0x0000ffffU 
                                                  & vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__unnamedblk2__DOT__scaled_score)));
                        __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_scores__v0 
                            = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx2;
                        __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_scores__v0 
                            = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx;
                        __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_scores__v0 = 1U;
                    } else {
                        __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_scores__v1 
                            = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx2;
                        __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_scores__v1 
                            = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx;
                        __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_scores__v1 = 1U;
                    }
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__head_idx = 0U;
                    if ((7U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx2))) {
                        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx2 = 0U;
                        if ((7U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx))) {
                            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__state = 5U;
                            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_start = 1U;
                        } else {
                            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx 
                                = (7U & ((IData)(1U) 
                                         + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx)));
                        }
                    } else {
                        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx2 
                            = (7U & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx2)));
                    }
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__accumulator = 0U;
                } else {
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__head_idx 
                        = (0x0000000fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__head_idx)));
                }
            } else if ((5U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__state))) {
                if (vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_done) {
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__state = 6U;
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx = 0U;
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx2 = 0U;
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__head_idx = 0U;
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__accumulator = 0U;
                }
            } else if ((6U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__state))) {
                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__accumulator 
                    = ((0U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx2))
                        ? VL_MULS_III(32, VL_EXTENDS_II(32,16, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_weights
                                                        [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx]
                                                        [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx2]), 
                                      VL_EXTENDS_II(32,16, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__V
                                                    [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx2]
                                                    [
                                                    (3U 
                                                     & (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__head_idx))]))
                        : (vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__accumulator 
                           + VL_MULS_III(32, VL_EXTENDS_II(32,16, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_weights
                                                           [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx]
                                                           [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx2]), 
                                         VL_EXTENDS_II(32,16, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__V
                                                       [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx2]
                                                       [
                                                       (3U 
                                                        & (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__head_idx))]))));
                if ((7U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx2))) {
                    __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__0__KET____DOT__head__output_data__v0 
                        = (0x0000ffffU & VL_SHIFTRS_III(16,32,32, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__accumulator, 0x0000000cU));
                    __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__0__KET____DOT__head__output_data__v0 
                        = (3U & (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__head_idx));
                    __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__0__KET____DOT__head__output_data__v0 
                        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx;
                    __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__0__KET____DOT__head__output_data__v0 = 1U;
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx2 = 0U;
                    if ((3U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__head_idx))) {
                        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__head_idx = 0U;
                        if ((7U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx))) {
                            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__state = 7U;
                        } else {
                            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx 
                                = (7U & ((IData)(1U) 
                                         + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx)));
                        }
                    } else {
                        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__head_idx 
                            = (0x0000000fU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__head_idx)));
                    }
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__accumulator = 0U;
                } else {
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx2 
                        = (7U & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx2)));
                }
            } else {
                vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__0__KET____DOT__head__done = 1U;
                vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__0__KET____DOT__head__valid = 1U;
                if ((1U & (~ (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_start_signals)))) {
                    __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__state = 0U;
                }
            }
        }
    }
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx 
        = __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx;
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx2 
        = __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__seq_idx2;
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__pipe_stage 
        = __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__pipe_stage;
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__accumulator 
        = __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__accumulator;
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_start_signals 
        = __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__head_start_signals;
    if (__VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__Q__v0) {
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__Q[__VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__Q__v0][__VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__Q__v0] 
            = __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__Q__v0;
    }
    if (__VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__K__v0) {
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__K[__VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__K__v0][__VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__K__v0] 
            = __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__K__v0;
    }
    if (__VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__V__v0) {
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__V[__VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__V__v0][__VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__V__v0] 
            = __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__V__v0;
    }
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__embed_idx 
        = __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__embed_idx;
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__head_idx 
        = __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__head_idx;
    if (__VdlySet__complete_transformer_decoder__DOT__position_encoded__v0) {
        vlSelfRef.complete_transformer_decoder__DOT__position_encoded[__VdlyDim1__complete_transformer_decoder__DOT__position_encoded__v0][__VdlyDim0__complete_transformer_decoder__DOT__position_encoded__v0] 
            = __VdlyVal__complete_transformer_decoder__DOT__position_encoded__v0;
    }
    if (__VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__0__KET____DOT__head__output_data__v0) {
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__0__KET____DOT__head__output_data[__VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__0__KET____DOT__head__output_data__v0][__VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__0__KET____DOT__head__output_data__v0] 
            = __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__0__KET____DOT__head__output_data__v0;
    }
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][0U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__3__KET____DOT__head__output_data[0U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][0U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__3__KET____DOT__head__output_data[0U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][0U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__3__KET____DOT__head__output_data[0U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][0U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__3__KET____DOT__head__output_data[0U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][1U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__3__KET____DOT__head__output_data[1U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][1U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__3__KET____DOT__head__output_data[1U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][1U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__3__KET____DOT__head__output_data[1U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][1U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__3__KET____DOT__head__output_data[1U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][2U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__3__KET____DOT__head__output_data[2U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][2U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__3__KET____DOT__head__output_data[2U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][2U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__3__KET____DOT__head__output_data[2U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][2U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__3__KET____DOT__head__output_data[2U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][3U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__3__KET____DOT__head__output_data[3U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][3U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__3__KET____DOT__head__output_data[3U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][3U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__3__KET____DOT__head__output_data[3U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][3U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__3__KET____DOT__head__output_data[3U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][4U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__3__KET____DOT__head__output_data[4U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][4U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__3__KET____DOT__head__output_data[4U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][4U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__3__KET____DOT__head__output_data[4U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][4U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__3__KET____DOT__head__output_data[4U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][5U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__3__KET____DOT__head__output_data[5U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][5U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__3__KET____DOT__head__output_data[5U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][5U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__3__KET____DOT__head__output_data[5U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][5U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__3__KET____DOT__head__output_data[5U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][6U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__3__KET____DOT__head__output_data[6U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][6U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__3__KET____DOT__head__output_data[6U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][6U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__3__KET____DOT__head__output_data[6U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][6U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__3__KET____DOT__head__output_data[6U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][7U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__3__KET____DOT__head__output_data[7U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][7U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__3__KET____DOT__head__output_data[7U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][7U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__3__KET____DOT__head__output_data[7U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][7U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__3__KET____DOT__head__output_data[7U][3U];
    if ((1U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__state))) {
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__wq_data 
            = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__wq_mem__DOT__memory
            [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__wq_addr];
    }
    if ((2U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__state))) {
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__wk_data 
            = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__wk_mem__DOT__memory
            [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__wq_addr];
    }
    if ((3U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__state))) {
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__wv_data 
            = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__wv_mem__DOT__memory
            [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__wq_addr];
    }
    if (vlSelfRef.rst) {
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__state = 0U;
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__row_idx = 0U;
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__col_idx = 0U;
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__max_val = 0xc000U;
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__exp_sum = 0U;
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_done = 0U;
    } else if ((0U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__state))) {
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_done = 0U;
        if (vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_start) {
            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__state = 1U;
            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__row_idx = 0U;
            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__col_idx = 0U;
            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__max_val 
                = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_scores[0U][0U];
        }
    } else if ((1U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__state))) {
        if (VL_GTS_III(16, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_scores
                       [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__row_idx]
                       [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__col_idx], (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__max_val))) {
            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__max_val 
                = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_scores
                [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__row_idx]
                [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__col_idx];
        }
        if ((7U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__col_idx))) {
            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__col_idx = 0U;
            if ((7U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__row_idx))) {
                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__state = 2U;
                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__row_idx = 0U;
                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__exp_sum = 0U;
            } else {
                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__row_idx 
                    = (7U & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__row_idx)));
            }
        } else {
            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__col_idx 
                = (7U & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__col_idx)));
        }
    } else if ((2U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__state))) {
        if ((0U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__col_idx))) {
            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__exp_sum = 0U;
        }
        __Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__6__x 
            = (0x0000ffffU & (vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_scores
                              [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__row_idx]
                              [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__col_idx] 
                              - (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__max_val)));
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__Vstatic__shifted_x 
            = (0x0000ffffU & VL_SHIFTRS_III(16,16,32, (IData)(__Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__6__x), 4U));
        __Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__6__Vfuncout 
            = (VL_GTS_III(32, 0xfffffff0U, VL_EXTENDS_II(32,16, (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__Vstatic__shifted_x)))
                ? 1U : (VL_LTS_III(32, 0x00000010U, 
                                   VL_EXTENDS_II(32,16, (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__Vstatic__shifted_x)))
                         ? 0x00000200U : (0x0000ffffU 
                                          & (VL_GTS_III(32, 0U, 
                                                        VL_EXTENDS_II(32,16, (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__Vstatic__shifted_x)))
                                              ? ((IData)(0x0040U) 
                                                 + 
                                                 VL_MULS_III(32, (IData)(3U), 
                                                             VL_EXTENDS_II(32,16, (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__Vstatic__shifted_x))))
                                              : ((IData)(0x0040U) 
                                                 + 
                                                 VL_MULS_III(32, (IData)(8U), 
                                                             VL_EXTENDS_II(32,16, (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__Vstatic__shifted_x))))))));
        if ((1U > (IData)(__Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__6__Vfuncout))) {
            __Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__6__Vfuncout = 1U;
        }
        __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__temp_exp__v0 
            = __Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__6__Vfuncout;
        __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__temp_exp__v0 
            = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__col_idx;
        __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__temp_exp__v0 = 1U;
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__exp_sum 
            = (vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__exp_sum 
               + VL_EXTEND_II(32,16, ([&]() {
                        __Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__7__x 
                            = (0x0000ffffU & (vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_scores
                                              [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__row_idx]
                                              [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__col_idx] 
                                              - (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__max_val)));
                        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__Vstatic__shifted_x 
                            = (0x0000ffffU & VL_SHIFTRS_III(16,16,32, (IData)(__Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__7__x), 4U));
                        __Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__7__Vfuncout 
                            = (VL_GTS_III(32, 0xfffffff0U, 
                                          VL_EXTENDS_II(32,16, (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__Vstatic__shifted_x)))
                                ? 1U : (VL_LTS_III(32, 0x00000010U, 
                                                   VL_EXTENDS_II(32,16, (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__Vstatic__shifted_x)))
                                         ? 0x00000200U
                                         : (0x0000ffffU 
                                            & (VL_GTS_III(32, 0U, 
                                                          VL_EXTENDS_II(32,16, (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__Vstatic__shifted_x)))
                                                ? ((IData)(0x0040U) 
                                                   + 
                                                   VL_MULS_III(32, (IData)(3U), 
                                                               VL_EXTENDS_II(32,16, (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__Vstatic__shifted_x))))
                                                : ((IData)(0x0040U) 
                                                   + 
                                                   VL_MULS_III(32, (IData)(8U), 
                                                               VL_EXTENDS_II(32,16, (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__Vstatic__shifted_x))))))));
                        if ((1U > (IData)(__Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__7__Vfuncout))) {
                            __Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__7__Vfuncout = 1U;
                        }
                    }(), (IData)(__Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__7__Vfuncout))));
        if ((7U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__col_idx))) {
            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__col_idx = 0U;
            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__state = 3U;
        } else {
            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__col_idx 
                = (7U & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__col_idx)));
        }
    } else if ((3U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__state))) {
        if (VL_LTS_III(32, 0U, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__exp_sum)) {
            vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__unnamedblk2__DOT__normalized 
                = VL_DIV_III(32, VL_SHIFTL_III(32,32,32, 
                                               VL_EXTENDS_II(32,16, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__temp_exp
                                                             [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__col_idx]), 0x0000000cU), 
                             (0x0000ffffU & vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__exp_sum));
            if ((0x00007fffU < vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__unnamedblk2__DOT__normalized)) {
                vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__unnamedblk2__DOT__normalized = 0x00007fffU;
            }
            __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_weights__v0 
                = (0x0000ffffU & vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__unnamedblk2__DOT__normalized);
            __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_weights__v0 
                = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__col_idx;
            __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_weights__v0 
                = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__row_idx;
            __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_weights__v0 = 1U;
        } else {
            __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_weights__v1 
                = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__col_idx;
            __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_weights__v1 
                = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__row_idx;
            __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_weights__v1 = 1U;
        }
        if ((7U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__col_idx))) {
            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__col_idx = 0U;
            if ((7U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__row_idx))) {
                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__state = 4U;
            } else {
                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__row_idx 
                    = (7U & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__row_idx)));
                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__state = 2U;
            }
        } else {
            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__col_idx 
                = (7U & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__col_idx)));
        }
    } else if ((4U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__state))) {
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_done = 1U;
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__state = 0U;
    }
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][0U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__2__KET____DOT__head__output_data[0U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][0U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__2__KET____DOT__head__output_data[0U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][0U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__2__KET____DOT__head__output_data[0U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][0U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__2__KET____DOT__head__output_data[0U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][1U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__2__KET____DOT__head__output_data[1U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][1U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__2__KET____DOT__head__output_data[1U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][1U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__2__KET____DOT__head__output_data[1U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][1U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__2__KET____DOT__head__output_data[1U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][2U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__2__KET____DOT__head__output_data[2U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][2U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__2__KET____DOT__head__output_data[2U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][2U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__2__KET____DOT__head__output_data[2U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][2U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__2__KET____DOT__head__output_data[2U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][3U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__2__KET____DOT__head__output_data[3U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][3U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__2__KET____DOT__head__output_data[3U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][3U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__2__KET____DOT__head__output_data[3U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][3U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__2__KET____DOT__head__output_data[3U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][4U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__2__KET____DOT__head__output_data[4U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][4U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__2__KET____DOT__head__output_data[4U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][4U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__2__KET____DOT__head__output_data[4U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][4U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__2__KET____DOT__head__output_data[4U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][5U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__2__KET____DOT__head__output_data[5U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][5U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__2__KET____DOT__head__output_data[5U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][5U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__2__KET____DOT__head__output_data[5U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][5U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__2__KET____DOT__head__output_data[5U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][6U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__2__KET____DOT__head__output_data[6U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][6U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__2__KET____DOT__head__output_data[6U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][6U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__2__KET____DOT__head__output_data[6U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][6U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__2__KET____DOT__head__output_data[6U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][7U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__2__KET____DOT__head__output_data[7U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][7U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__2__KET____DOT__head__output_data[7U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][7U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__2__KET____DOT__head__output_data[7U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][7U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__2__KET____DOT__head__output_data[7U][3U];
    if ((1U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__state))) {
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__wq_data 
            = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__wq_mem__DOT__memory
            [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__wq_addr];
    }
    if ((2U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__state))) {
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__wk_data 
            = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__wk_mem__DOT__memory
            [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__wq_addr];
    }
    if ((3U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__state))) {
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__wv_data 
            = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__wv_mem__DOT__memory
            [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__wq_addr];
    }
    if (vlSelfRef.rst) {
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__state = 0U;
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__row_idx = 0U;
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__col_idx = 0U;
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__max_val = 0xc000U;
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__exp_sum = 0U;
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_done = 0U;
    } else if ((0U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__state))) {
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_done = 0U;
        if (vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_start) {
            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__state = 1U;
            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__row_idx = 0U;
            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__col_idx = 0U;
            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__max_val 
                = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_scores[0U][0U];
        }
    } else if ((1U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__state))) {
        if (VL_GTS_III(16, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_scores
                       [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__row_idx]
                       [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__col_idx], (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__max_val))) {
            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__max_val 
                = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_scores
                [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__row_idx]
                [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__col_idx];
        }
        if ((7U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__col_idx))) {
            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__col_idx = 0U;
            if ((7U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__row_idx))) {
                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__state = 2U;
                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__row_idx = 0U;
                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__exp_sum = 0U;
            } else {
                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__row_idx 
                    = (7U & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__row_idx)));
            }
        } else {
            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__col_idx 
                = (7U & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__col_idx)));
        }
    } else if ((2U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__state))) {
        if ((0U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__col_idx))) {
            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__exp_sum = 0U;
        }
        __Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__4__x 
            = (0x0000ffffU & (vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_scores
                              [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__row_idx]
                              [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__col_idx] 
                              - (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__max_val)));
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__Vstatic__shifted_x 
            = (0x0000ffffU & VL_SHIFTRS_III(16,16,32, (IData)(__Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__4__x), 4U));
        __Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__4__Vfuncout 
            = (VL_GTS_III(32, 0xfffffff0U, VL_EXTENDS_II(32,16, (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__Vstatic__shifted_x)))
                ? 1U : (VL_LTS_III(32, 0x00000010U, 
                                   VL_EXTENDS_II(32,16, (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__Vstatic__shifted_x)))
                         ? 0x00000200U : (0x0000ffffU 
                                          & (VL_GTS_III(32, 0U, 
                                                        VL_EXTENDS_II(32,16, (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__Vstatic__shifted_x)))
                                              ? ((IData)(0x0040U) 
                                                 + 
                                                 VL_MULS_III(32, (IData)(3U), 
                                                             VL_EXTENDS_II(32,16, (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__Vstatic__shifted_x))))
                                              : ((IData)(0x0040U) 
                                                 + 
                                                 VL_MULS_III(32, (IData)(8U), 
                                                             VL_EXTENDS_II(32,16, (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__Vstatic__shifted_x))))))));
        if ((1U > (IData)(__Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__4__Vfuncout))) {
            __Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__4__Vfuncout = 1U;
        }
        __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__temp_exp__v0 
            = __Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__4__Vfuncout;
        __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__temp_exp__v0 
            = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__col_idx;
        __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__temp_exp__v0 = 1U;
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__exp_sum 
            = (vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__exp_sum 
               + VL_EXTEND_II(32,16, ([&]() {
                        __Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__5__x 
                            = (0x0000ffffU & (vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_scores
                                              [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__row_idx]
                                              [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__col_idx] 
                                              - (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__max_val)));
                        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__Vstatic__shifted_x 
                            = (0x0000ffffU & VL_SHIFTRS_III(16,16,32, (IData)(__Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__5__x), 4U));
                        __Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__5__Vfuncout 
                            = (VL_GTS_III(32, 0xfffffff0U, 
                                          VL_EXTENDS_II(32,16, (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__Vstatic__shifted_x)))
                                ? 1U : (VL_LTS_III(32, 0x00000010U, 
                                                   VL_EXTENDS_II(32,16, (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__Vstatic__shifted_x)))
                                         ? 0x00000200U
                                         : (0x0000ffffU 
                                            & (VL_GTS_III(32, 0U, 
                                                          VL_EXTENDS_II(32,16, (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__Vstatic__shifted_x)))
                                                ? ((IData)(0x0040U) 
                                                   + 
                                                   VL_MULS_III(32, (IData)(3U), 
                                                               VL_EXTENDS_II(32,16, (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__Vstatic__shifted_x))))
                                                : ((IData)(0x0040U) 
                                                   + 
                                                   VL_MULS_III(32, (IData)(8U), 
                                                               VL_EXTENDS_II(32,16, (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__Vstatic__shifted_x))))))));
                        if ((1U > (IData)(__Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__5__Vfuncout))) {
                            __Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__5__Vfuncout = 1U;
                        }
                    }(), (IData)(__Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__5__Vfuncout))));
        if ((7U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__col_idx))) {
            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__col_idx = 0U;
            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__state = 3U;
        } else {
            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__col_idx 
                = (7U & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__col_idx)));
        }
    } else if ((3U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__state))) {
        if (VL_LTS_III(32, 0U, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__exp_sum)) {
            vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__unnamedblk2__DOT__normalized 
                = VL_DIV_III(32, VL_SHIFTL_III(32,32,32, 
                                               VL_EXTENDS_II(32,16, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__temp_exp
                                                             [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__col_idx]), 0x0000000cU), 
                             (0x0000ffffU & vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__exp_sum));
            if ((0x00007fffU < vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__unnamedblk2__DOT__normalized)) {
                vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__unnamedblk2__DOT__normalized = 0x00007fffU;
            }
            __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_weights__v0 
                = (0x0000ffffU & vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__unnamedblk2__DOT__normalized);
            __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_weights__v0 
                = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__col_idx;
            __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_weights__v0 
                = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__row_idx;
            __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_weights__v0 = 1U;
        } else {
            __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_weights__v1 
                = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__col_idx;
            __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_weights__v1 
                = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__row_idx;
            __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_weights__v1 = 1U;
        }
        if ((7U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__col_idx))) {
            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__col_idx = 0U;
            if ((7U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__row_idx))) {
                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__state = 4U;
            } else {
                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__row_idx 
                    = (7U & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__row_idx)));
                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__state = 2U;
            }
        } else {
            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__col_idx 
                = (7U & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__col_idx)));
        }
    } else if ((4U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__state))) {
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_done = 1U;
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__state = 0U;
    }
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][0U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__1__KET____DOT__head__output_data[0U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][0U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__1__KET____DOT__head__output_data[0U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][0U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__1__KET____DOT__head__output_data[0U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][0U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__1__KET____DOT__head__output_data[0U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][1U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__1__KET____DOT__head__output_data[1U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][1U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__1__KET____DOT__head__output_data[1U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][1U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__1__KET____DOT__head__output_data[1U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][1U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__1__KET____DOT__head__output_data[1U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][2U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__1__KET____DOT__head__output_data[2U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][2U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__1__KET____DOT__head__output_data[2U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][2U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__1__KET____DOT__head__output_data[2U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][2U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__1__KET____DOT__head__output_data[2U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][3U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__1__KET____DOT__head__output_data[3U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][3U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__1__KET____DOT__head__output_data[3U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][3U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__1__KET____DOT__head__output_data[3U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][3U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__1__KET____DOT__head__output_data[3U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][4U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__1__KET____DOT__head__output_data[4U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][4U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__1__KET____DOT__head__output_data[4U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][4U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__1__KET____DOT__head__output_data[4U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][4U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__1__KET____DOT__head__output_data[4U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][5U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__1__KET____DOT__head__output_data[5U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][5U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__1__KET____DOT__head__output_data[5U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][5U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__1__KET____DOT__head__output_data[5U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][5U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__1__KET____DOT__head__output_data[5U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][6U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__1__KET____DOT__head__output_data[6U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][6U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__1__KET____DOT__head__output_data[6U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][6U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__1__KET____DOT__head__output_data[6U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][6U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__1__KET____DOT__head__output_data[6U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][7U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__1__KET____DOT__head__output_data[7U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][7U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__1__KET____DOT__head__output_data[7U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][7U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__1__KET____DOT__head__output_data[7U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][7U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__1__KET____DOT__head__output_data[7U][3U];
    if ((1U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__state))) {
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__wq_data 
            = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__wq_mem__DOT__memory
            [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__wq_addr];
    }
    if ((2U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__state))) {
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__wk_data 
            = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__wk_mem__DOT__memory
            [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__wq_addr];
    }
    if ((3U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__state))) {
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__wv_data 
            = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__wv_mem__DOT__memory
            [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__wq_addr];
    }
    if (vlSelfRef.rst) {
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__state = 0U;
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__row_idx = 0U;
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__col_idx = 0U;
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__max_val = 0xc000U;
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__exp_sum = 0U;
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_done = 0U;
    } else if ((0U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__state))) {
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_done = 0U;
        if (vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_start) {
            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__state = 1U;
            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__row_idx = 0U;
            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__col_idx = 0U;
            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__max_val 
                = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_scores[0U][0U];
        }
    } else if ((1U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__state))) {
        if (VL_GTS_III(16, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_scores
                       [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__row_idx]
                       [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__col_idx], (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__max_val))) {
            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__max_val 
                = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_scores
                [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__row_idx]
                [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__col_idx];
        }
        if ((7U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__col_idx))) {
            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__col_idx = 0U;
            if ((7U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__row_idx))) {
                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__state = 2U;
                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__row_idx = 0U;
                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__exp_sum = 0U;
            } else {
                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__row_idx 
                    = (7U & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__row_idx)));
            }
        } else {
            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__col_idx 
                = (7U & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__col_idx)));
        }
    } else if ((2U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__state))) {
        if ((0U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__col_idx))) {
            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__exp_sum = 0U;
        }
        __Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__2__x 
            = (0x0000ffffU & (vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_scores
                              [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__row_idx]
                              [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__col_idx] 
                              - (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__max_val)));
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__Vstatic__shifted_x 
            = (0x0000ffffU & VL_SHIFTRS_III(16,16,32, (IData)(__Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__2__x), 4U));
        __Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__2__Vfuncout 
            = (VL_GTS_III(32, 0xfffffff0U, VL_EXTENDS_II(32,16, (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__Vstatic__shifted_x)))
                ? 1U : (VL_LTS_III(32, 0x00000010U, 
                                   VL_EXTENDS_II(32,16, (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__Vstatic__shifted_x)))
                         ? 0x00000200U : (0x0000ffffU 
                                          & (VL_GTS_III(32, 0U, 
                                                        VL_EXTENDS_II(32,16, (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__Vstatic__shifted_x)))
                                              ? ((IData)(0x0040U) 
                                                 + 
                                                 VL_MULS_III(32, (IData)(3U), 
                                                             VL_EXTENDS_II(32,16, (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__Vstatic__shifted_x))))
                                              : ((IData)(0x0040U) 
                                                 + 
                                                 VL_MULS_III(32, (IData)(8U), 
                                                             VL_EXTENDS_II(32,16, (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__Vstatic__shifted_x))))))));
        if ((1U > (IData)(__Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__2__Vfuncout))) {
            __Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__2__Vfuncout = 1U;
        }
        __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__temp_exp__v0 
            = __Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__2__Vfuncout;
        __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__temp_exp__v0 
            = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__col_idx;
        __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__temp_exp__v0 = 1U;
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__exp_sum 
            = (vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__exp_sum 
               + VL_EXTEND_II(32,16, ([&]() {
                        __Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__3__x 
                            = (0x0000ffffU & (vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_scores
                                              [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__row_idx]
                                              [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__col_idx] 
                                              - (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__max_val)));
                        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__Vstatic__shifted_x 
                            = (0x0000ffffU & VL_SHIFTRS_III(16,16,32, (IData)(__Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__3__x), 4U));
                        __Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__3__Vfuncout 
                            = (VL_GTS_III(32, 0xfffffff0U, 
                                          VL_EXTENDS_II(32,16, (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__Vstatic__shifted_x)))
                                ? 1U : (VL_LTS_III(32, 0x00000010U, 
                                                   VL_EXTENDS_II(32,16, (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__Vstatic__shifted_x)))
                                         ? 0x00000200U
                                         : (0x0000ffffU 
                                            & (VL_GTS_III(32, 0U, 
                                                          VL_EXTENDS_II(32,16, (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__Vstatic__shifted_x)))
                                                ? ((IData)(0x0040U) 
                                                   + 
                                                   VL_MULS_III(32, (IData)(3U), 
                                                               VL_EXTENDS_II(32,16, (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__Vstatic__shifted_x))))
                                                : ((IData)(0x0040U) 
                                                   + 
                                                   VL_MULS_III(32, (IData)(8U), 
                                                               VL_EXTENDS_II(32,16, (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__Vstatic__shifted_x))))))));
                        if ((1U > (IData)(__Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__3__Vfuncout))) {
                            __Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__3__Vfuncout = 1U;
                        }
                    }(), (IData)(__Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__3__Vfuncout))));
        if ((7U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__col_idx))) {
            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__col_idx = 0U;
            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__state = 3U;
        } else {
            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__col_idx 
                = (7U & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__col_idx)));
        }
    } else if ((3U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__state))) {
        if (VL_LTS_III(32, 0U, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__exp_sum)) {
            vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__unnamedblk2__DOT__normalized 
                = VL_DIV_III(32, VL_SHIFTL_III(32,32,32, 
                                               VL_EXTENDS_II(32,16, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__temp_exp
                                                             [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__col_idx]), 0x0000000cU), 
                             (0x0000ffffU & vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__exp_sum));
            if ((0x00007fffU < vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__unnamedblk2__DOT__normalized)) {
                vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__unnamedblk2__DOT__normalized = 0x00007fffU;
            }
            __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_weights__v0 
                = (0x0000ffffU & vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__unnamedblk2__DOT__normalized);
            __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_weights__v0 
                = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__col_idx;
            __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_weights__v0 
                = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__row_idx;
            __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_weights__v0 = 1U;
        } else {
            __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_weights__v1 
                = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__col_idx;
            __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_weights__v1 
                = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__row_idx;
            __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_weights__v1 = 1U;
        }
        if ((7U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__col_idx))) {
            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__col_idx = 0U;
            if ((7U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__row_idx))) {
                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__state = 4U;
            } else {
                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__row_idx 
                    = (7U & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__row_idx)));
                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__state = 2U;
            }
        } else {
            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__col_idx 
                = (7U & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__col_idx)));
        }
    } else if ((4U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__state))) {
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_done = 1U;
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__state = 0U;
    }
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][0U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__0__KET____DOT__head__output_data[0U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][0U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__0__KET____DOT__head__output_data[0U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][0U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__0__KET____DOT__head__output_data[0U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][0U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__0__KET____DOT__head__output_data[0U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][1U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__0__KET____DOT__head__output_data[1U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][1U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__0__KET____DOT__head__output_data[1U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][1U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__0__KET____DOT__head__output_data[1U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][1U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__0__KET____DOT__head__output_data[1U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][2U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__0__KET____DOT__head__output_data[2U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][2U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__0__KET____DOT__head__output_data[2U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][2U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__0__KET____DOT__head__output_data[2U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][2U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__0__KET____DOT__head__output_data[2U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][3U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__0__KET____DOT__head__output_data[3U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][3U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__0__KET____DOT__head__output_data[3U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][3U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__0__KET____DOT__head__output_data[3U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][3U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__0__KET____DOT__head__output_data[3U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][4U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__0__KET____DOT__head__output_data[4U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][4U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__0__KET____DOT__head__output_data[4U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][4U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__0__KET____DOT__head__output_data[4U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][4U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__0__KET____DOT__head__output_data[4U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][5U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__0__KET____DOT__head__output_data[5U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][5U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__0__KET____DOT__head__output_data[5U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][5U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__0__KET____DOT__head__output_data[5U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][5U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__0__KET____DOT__head__output_data[5U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][6U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__0__KET____DOT__head__output_data[6U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][6U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__0__KET____DOT__head__output_data[6U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][6U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__0__KET____DOT__head__output_data[6U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][6U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__0__KET____DOT__head__output_data[6U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][7U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__0__KET____DOT__head__output_data[7U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][7U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__0__KET____DOT__head__output_data[7U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][7U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__0__KET____DOT__head__output_data[7U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][7U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__genblk1__BRA__0__KET____DOT__head__output_data[7U][3U];
    if ((1U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__state))) {
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__wq_data 
            = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__wq_mem__DOT__memory
            [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__wq_addr];
    }
    if ((2U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__state))) {
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__wk_data 
            = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__wk_mem__DOT__memory
            [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__wq_addr];
    }
    if ((3U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__state))) {
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__wv_data 
            = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__wv_mem__DOT__memory
            [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__wq_addr];
    }
    if (vlSelfRef.rst) {
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__state = 0U;
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__row_idx = 0U;
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__col_idx = 0U;
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__max_val = 0xc000U;
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__exp_sum = 0U;
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_done = 0U;
    } else if ((0U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__state))) {
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_done = 0U;
        if (vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_start) {
            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__state = 1U;
            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__row_idx = 0U;
            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__col_idx = 0U;
            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__max_val 
                = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_scores[0U][0U];
        }
    } else if ((1U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__state))) {
        if (VL_GTS_III(16, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_scores
                       [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__row_idx]
                       [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__col_idx], (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__max_val))) {
            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__max_val 
                = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_scores
                [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__row_idx]
                [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__col_idx];
        }
        if ((7U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__col_idx))) {
            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__col_idx = 0U;
            if ((7U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__row_idx))) {
                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__state = 2U;
                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__row_idx = 0U;
                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__exp_sum = 0U;
            } else {
                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__row_idx 
                    = (7U & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__row_idx)));
            }
        } else {
            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__col_idx 
                = (7U & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__col_idx)));
        }
    } else if ((2U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__state))) {
        if ((0U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__col_idx))) {
            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__exp_sum = 0U;
        }
        __Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__0__x 
            = (0x0000ffffU & (vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_scores
                              [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__row_idx]
                              [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__col_idx] 
                              - (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__max_val)));
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__Vstatic__shifted_x 
            = (0x0000ffffU & VL_SHIFTRS_III(16,16,32, (IData)(__Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__0__x), 4U));
        __Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__0__Vfuncout 
            = (VL_GTS_III(32, 0xfffffff0U, VL_EXTENDS_II(32,16, (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__Vstatic__shifted_x)))
                ? 1U : (VL_LTS_III(32, 0x00000010U, 
                                   VL_EXTENDS_II(32,16, (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__Vstatic__shifted_x)))
                         ? 0x00000200U : (0x0000ffffU 
                                          & (VL_GTS_III(32, 0U, 
                                                        VL_EXTENDS_II(32,16, (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__Vstatic__shifted_x)))
                                              ? ((IData)(0x0040U) 
                                                 + 
                                                 VL_MULS_III(32, (IData)(3U), 
                                                             VL_EXTENDS_II(32,16, (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__Vstatic__shifted_x))))
                                              : ((IData)(0x0040U) 
                                                 + 
                                                 VL_MULS_III(32, (IData)(8U), 
                                                             VL_EXTENDS_II(32,16, (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__Vstatic__shifted_x))))))));
        if ((1U > (IData)(__Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__0__Vfuncout))) {
            __Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__0__Vfuncout = 1U;
        }
        __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__temp_exp__v0 
            = __Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__0__Vfuncout;
        __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__temp_exp__v0 
            = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__col_idx;
        __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__temp_exp__v0 = 1U;
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__exp_sum 
            = (vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__exp_sum 
               + VL_EXTEND_II(32,16, ([&]() {
                        __Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__1__x 
                            = (0x0000ffffU & (vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_scores
                                              [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__row_idx]
                                              [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__col_idx] 
                                              - (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__max_val)));
                        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__Vstatic__shifted_x 
                            = (0x0000ffffU & VL_SHIFTRS_III(16,16,32, (IData)(__Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__1__x), 4U));
                        __Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__1__Vfuncout 
                            = (VL_GTS_III(32, 0xfffffff0U, 
                                          VL_EXTENDS_II(32,16, (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__Vstatic__shifted_x)))
                                ? 1U : (VL_LTS_III(32, 0x00000010U, 
                                                   VL_EXTENDS_II(32,16, (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__Vstatic__shifted_x)))
                                         ? 0x00000200U
                                         : (0x0000ffffU 
                                            & (VL_GTS_III(32, 0U, 
                                                          VL_EXTENDS_II(32,16, (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__Vstatic__shifted_x)))
                                                ? ((IData)(0x0040U) 
                                                   + 
                                                   VL_MULS_III(32, (IData)(3U), 
                                                               VL_EXTENDS_II(32,16, (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__Vstatic__shifted_x))))
                                                : ((IData)(0x0040U) 
                                                   + 
                                                   VL_MULS_III(32, (IData)(8U), 
                                                               VL_EXTENDS_II(32,16, (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__Vstatic__shifted_x))))))));
                        if ((1U > (IData)(__Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__1__Vfuncout))) {
                            __Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__1__Vfuncout = 1U;
                        }
                    }(), (IData)(__Vfunc_complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__enhanced_exp__1__Vfuncout))));
        if ((7U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__col_idx))) {
            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__col_idx = 0U;
            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__state = 3U;
        } else {
            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__col_idx 
                = (7U & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__col_idx)));
        }
    } else if ((3U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__state))) {
        if (VL_LTS_III(32, 0U, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__exp_sum)) {
            vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__unnamedblk2__DOT__normalized 
                = VL_DIV_III(32, VL_SHIFTL_III(32,32,32, 
                                               VL_EXTENDS_II(32,16, vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__temp_exp
                                                             [vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__col_idx]), 0x0000000cU), 
                             (0x0000ffffU & vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__exp_sum));
            if ((0x00007fffU < vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__unnamedblk2__DOT__normalized)) {
                vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__unnamedblk2__DOT__normalized = 0x00007fffU;
            }
            __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_weights__v0 
                = (0x0000ffffU & vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__unnamedblk2__DOT__normalized);
            __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_weights__v0 
                = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__col_idx;
            __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_weights__v0 
                = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__row_idx;
            __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_weights__v0 = 1U;
        } else {
            __VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_weights__v1 
                = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__col_idx;
            __VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_weights__v1 
                = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__row_idx;
            __VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_weights__v1 = 1U;
        }
        if ((7U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__col_idx))) {
            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__col_idx = 0U;
            if ((7U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__row_idx))) {
                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__state = 4U;
            } else {
                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__row_idx 
                    = (7U & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__row_idx)));
                __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__state = 2U;
            }
        } else {
            __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__col_idx 
                = (7U & ((IData)(1U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__col_idx)));
        }
    } else if ((4U == (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__state))) {
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_done = 1U;
        __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__state = 0U;
    }
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__state 
        = __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__state;
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__wq_addr 
        = (0x0000003fU & (((IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__embed_idx) 
                           << 2U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__head_idx)));
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_start 
        = __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_start;
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__state 
        = __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__state;
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__row_idx 
        = __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__row_idx;
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__col_idx 
        = __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__col_idx;
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__max_val 
        = __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__max_val;
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__exp_sum 
        = __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__exp_sum;
    if (__VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__temp_exp__v0) {
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__temp_exp[__VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__temp_exp__v0] 
            = __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__softmax_inst__DOT__temp_exp__v0;
    }
    if (__VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_scores__v0) {
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_scores[__VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_scores__v0][__VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_scores__v0] 
            = __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_scores__v0;
    }
    if (__VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_scores__v1) {
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_scores[__VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_scores__v1][__VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_scores__v1] = 0xc000U;
    }
    if (__VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_weights__v0) {
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_weights[__VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_weights__v0][__VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_weights__v0] 
            = __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_weights__v0;
    }
    if (__VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_weights__v1) {
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_weights[__VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_weights__v1][__VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__3__KET____DOT__head__DOT__attention_weights__v1] = 0U;
    }
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__state 
        = __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__state;
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__wq_addr 
        = (0x0000003fU & (((IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__embed_idx) 
                           << 2U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__head_idx)));
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_start 
        = __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_start;
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__state 
        = __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__state;
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__row_idx 
        = __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__row_idx;
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__col_idx 
        = __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__col_idx;
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__max_val 
        = __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__max_val;
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__exp_sum 
        = __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__exp_sum;
    if (__VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__temp_exp__v0) {
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__temp_exp[__VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__temp_exp__v0] 
            = __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__softmax_inst__DOT__temp_exp__v0;
    }
    if (__VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_scores__v0) {
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_scores[__VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_scores__v0][__VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_scores__v0] 
            = __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_scores__v0;
    }
    if (__VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_scores__v1) {
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_scores[__VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_scores__v1][__VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_scores__v1] = 0xc000U;
    }
    if (__VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_weights__v0) {
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_weights[__VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_weights__v0][__VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_weights__v0] 
            = __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_weights__v0;
    }
    if (__VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_weights__v1) {
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_weights[__VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_weights__v1][__VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__2__KET____DOT__head__DOT__attention_weights__v1] = 0U;
    }
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__state 
        = __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__state;
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__wq_addr 
        = (0x0000003fU & (((IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__embed_idx) 
                           << 2U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__head_idx)));
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_start 
        = __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_start;
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__state 
        = __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__state;
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__row_idx 
        = __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__row_idx;
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__col_idx 
        = __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__col_idx;
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__max_val 
        = __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__max_val;
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__exp_sum 
        = __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__exp_sum;
    if (__VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__temp_exp__v0) {
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__temp_exp[__VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__temp_exp__v0] 
            = __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__softmax_inst__DOT__temp_exp__v0;
    }
    if (__VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_scores__v0) {
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_scores[__VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_scores__v0][__VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_scores__v0] 
            = __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_scores__v0;
    }
    if (__VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_scores__v1) {
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_scores[__VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_scores__v1][__VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_scores__v1] = 0xc000U;
    }
    if (__VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_weights__v0) {
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_weights[__VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_weights__v0][__VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_weights__v0] 
            = __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_weights__v0;
    }
    if (__VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_weights__v1) {
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_weights[__VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_weights__v1][__VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__1__KET____DOT__head__DOT__attention_weights__v1] = 0U;
    }
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__state 
        = __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__state;
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__wq_addr 
        = (0x0000003fU & (((IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__embed_idx) 
                           << 2U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__head_idx)));
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_start 
        = __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_start;
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__state 
        = __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__state;
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__row_idx 
        = __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__row_idx;
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__col_idx 
        = __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__col_idx;
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__max_val 
        = __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__max_val;
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__exp_sum 
        = __Vdly__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__exp_sum;
    if (__VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__temp_exp__v0) {
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__temp_exp[__VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__temp_exp__v0] 
            = __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__softmax_inst__DOT__temp_exp__v0;
    }
    if (__VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_scores__v0) {
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_scores[__VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_scores__v0][__VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_scores__v0] 
            = __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_scores__v0;
    }
    if (__VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_scores__v1) {
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_scores[__VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_scores__v1][__VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_scores__v1] = 0xc000U;
    }
    if (__VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_weights__v0) {
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_weights[__VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_weights__v0][__VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_weights__v0] 
            = __VdlyVal__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_weights__v0;
    }
    if (__VdlySet__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_weights__v1) {
        vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_weights[__VdlyDim1__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_weights__v1][__VdlyDim0__complete_transformer_decoder__DOT__attention_inst__DOT__genblk1__BRA__0__KET____DOT__head__DOT__attention_weights__v1] = 0U;
    }
}

void Vcomplete_transformer_decoder___024root___eval_nba(Vcomplete_transformer_decoder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcomplete_transformer_decoder___024root___eval_nba\n"); );
    Vcomplete_transformer_decoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vcomplete_transformer_decoder___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vcomplete_transformer_decoder___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcomplete_transformer_decoder___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vcomplete_transformer_decoder___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vcomplete_transformer_decoder___024root___eval_phase__act(Vcomplete_transformer_decoder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcomplete_transformer_decoder___024root___eval_phase__act\n"); );
    Vcomplete_transformer_decoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vcomplete_transformer_decoder___024root___eval_triggers_vec__act(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vcomplete_transformer_decoder___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vcomplete_transformer_decoder___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

void Vcomplete_transformer_decoder___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcomplete_transformer_decoder___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vcomplete_transformer_decoder___024root___eval_phase__nba(Vcomplete_transformer_decoder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcomplete_transformer_decoder___024root___eval_phase__nba\n"); );
    Vcomplete_transformer_decoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vcomplete_transformer_decoder___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vcomplete_transformer_decoder___024root___eval_nba(vlSelf);
        Vcomplete_transformer_decoder___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vcomplete_transformer_decoder___024root___eval(Vcomplete_transformer_decoder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcomplete_transformer_decoder___024root___eval\n"); );
    Vcomplete_transformer_decoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vcomplete_transformer_decoder___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
            VL_FATAL_MT("rtl/complete_transformer_decoder.sv", 6, "", "DIDNOTCONVERGE: Input combinational region did not converge after '--converge-limit' of 100 tries");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        vlSelfRef.__VicoPhaseResult = Vcomplete_transformer_decoder___024root___eval_phase__ico(vlSelf);
        vlSelfRef.__VicoFirstIteration = 0U;
    } while (vlSelfRef.__VicoPhaseResult);
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vcomplete_transformer_decoder___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("rtl/complete_transformer_decoder.sv", 6, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vcomplete_transformer_decoder___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("rtl/complete_transformer_decoder.sv", 6, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 100 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactPhaseResult = Vcomplete_transformer_decoder___024root___eval_phase__act(vlSelf);
        } while (vlSelfRef.__VactPhaseResult);
        vlSelfRef.__VnbaPhaseResult = Vcomplete_transformer_decoder___024root___eval_phase__nba(vlSelf);
    } while (vlSelfRef.__VnbaPhaseResult);
}

#ifdef VL_DEBUG
void Vcomplete_transformer_decoder___024root___eval_debug_assertions(Vcomplete_transformer_decoder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcomplete_transformer_decoder___024root___eval_debug_assertions\n"); );
    Vcomplete_transformer_decoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");
    }
    if (VL_UNLIKELY(((vlSelfRef.rst & 0xfeU)))) {
        Verilated::overWidthError("rst");
    }
    if (VL_UNLIKELY(((vlSelfRef.start & 0xfeU)))) {
        Verilated::overWidthError("start");
    }
}
#endif  // VL_DEBUG
