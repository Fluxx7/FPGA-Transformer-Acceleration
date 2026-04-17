// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcomplete_transformer_decoder.h for the primary calling header

#include "Vcomplete_transformer_decoder__pch.h"

VL_ATTR_COLD void Vcomplete_transformer_decoder___024root___eval_final(Vcomplete_transformer_decoder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcomplete_transformer_decoder___024root___eval_final\n"); );
    Vcomplete_transformer_decoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vcomplete_transformer_decoder___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vcomplete_transformer_decoder___024root___eval_phase__stl(Vcomplete_transformer_decoder___024root* vlSelf);

VL_ATTR_COLD void Vcomplete_transformer_decoder___024root___eval_settle(Vcomplete_transformer_decoder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcomplete_transformer_decoder___024root___eval_settle\n"); );
    Vcomplete_transformer_decoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vcomplete_transformer_decoder___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("rtl/complete_transformer_decoder.sv", 6, "", "DIDNOTCONVERGE: Settle region did not converge after '--converge-limit' of 100 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        vlSelfRef.__VstlPhaseResult = Vcomplete_transformer_decoder___024root___eval_phase__stl(vlSelf);
        vlSelfRef.__VstlFirstIteration = 0U;
    } while (vlSelfRef.__VstlPhaseResult);
}

VL_ATTR_COLD void Vcomplete_transformer_decoder___024root___eval_triggers_vec__stl(Vcomplete_transformer_decoder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcomplete_transformer_decoder___024root___eval_triggers_vec__stl\n"); );
    Vcomplete_transformer_decoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered[0U]) 
                                     | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
}

VL_ATTR_COLD bool Vcomplete_transformer_decoder___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vcomplete_transformer_decoder___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcomplete_transformer_decoder___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vcomplete_transformer_decoder___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vcomplete_transformer_decoder___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcomplete_transformer_decoder___024root___trigger_anySet__stl\n"); );
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

VL_ATTR_COLD void Vcomplete_transformer_decoder___024root___stl_sequent__TOP__0(Vcomplete_transformer_decoder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcomplete_transformer_decoder___024root___stl_sequent__TOP__0\n"); );
    Vcomplete_transformer_decoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.current_state_debug = vlSelfRef.complete_transformer_decoder__DOT__current_state;
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head0__DOT__wq_addr 
        = (0x000001ffU & (((IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head0__DOT__embed_idx) 
                           << 3U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head0__DOT__head_idx)));
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head1__DOT__wq_addr 
        = (0x000001ffU & (((IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head1__DOT__embed_idx) 
                           << 3U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head1__DOT__head_idx)));
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head2__DOT__wq_addr 
        = (0x000001ffU & (((IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head2__DOT__embed_idx) 
                           << 3U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head2__DOT__head_idx)));
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head3__DOT__wq_addr 
        = (0x000001ffU & (((IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head3__DOT__embed_idx) 
                           << 3U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head3__DOT__head_idx)));
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head4__DOT__wq_addr 
        = (0x000001ffU & (((IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head4__DOT__embed_idx) 
                           << 3U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head4__DOT__head_idx)));
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head5__DOT__wq_addr 
        = (0x000001ffU & (((IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head5__DOT__embed_idx) 
                           << 3U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head5__DOT__head_idx)));
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head6__DOT__wq_addr 
        = (0x000001ffU & (((IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head6__DOT__embed_idx) 
                           << 3U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head6__DOT__head_idx)));
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head7__DOT__wq_addr 
        = (0x000001ffU & (((IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head7__DOT__embed_idx) 
                           << 3U) + (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head7__DOT__head_idx)));
    vlSelfRef.complete_transformer_decoder__DOT__projection_inst__DOT__proj_addr 
        = (0x000007ffU & (((IData)(0x00000019U) * (IData)(vlSelfRef.complete_transformer_decoder__DOT__projection_inst__DOT__dim_idx)) 
                          + (IData)(vlSelfRef.complete_transformer_decoder__DOT__projection_inst__DOT__vocab_idx)));
    vlSelfRef.complete_transformer_decoder__DOT__embedding_inst__DOT__embed_addr 
        = (0x000007ffU & (VL_SHIFTL_III(11,11,32, vlSelfRef.input_sequence
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
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_valid_signals 
        = ((0x0eU & (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_valid_signals)) 
           | (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__valid));
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_done_signals 
        = ((0x0eU & (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_done_signals)) 
           | (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__done));
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][0U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__output_data[0U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][0U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__output_data[0U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][0U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__output_data[0U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][0U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__output_data[0U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][0U][4U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__output_data[0U][4U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][0U][5U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__output_data[0U][5U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][0U][6U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__output_data[0U][6U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][0U][7U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__output_data[0U][7U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][1U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__output_data[1U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][1U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__output_data[1U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][1U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__output_data[1U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][1U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__output_data[1U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][1U][4U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__output_data[1U][4U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][1U][5U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__output_data[1U][5U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][1U][6U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__output_data[1U][6U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][1U][7U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__output_data[1U][7U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][2U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__output_data[2U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][2U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__output_data[2U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][2U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__output_data[2U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][2U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__output_data[2U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][2U][4U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__output_data[2U][4U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][2U][5U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__output_data[2U][5U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][2U][6U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__output_data[2U][6U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][2U][7U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__output_data[2U][7U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][3U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__output_data[3U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][3U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__output_data[3U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][3U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__output_data[3U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][3U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__output_data[3U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][3U][4U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__output_data[3U][4U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][3U][5U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__output_data[3U][5U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][3U][6U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__output_data[3U][6U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][3U][7U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__output_data[3U][7U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][4U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__output_data[4U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][4U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__output_data[4U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][4U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__output_data[4U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][4U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__output_data[4U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][4U][4U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__output_data[4U][4U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][4U][5U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__output_data[4U][5U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][4U][6U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__output_data[4U][6U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][4U][7U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__output_data[4U][7U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][5U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__output_data[5U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][5U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__output_data[5U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][5U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__output_data[5U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][5U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__output_data[5U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][5U][4U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__output_data[5U][4U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][5U][5U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__output_data[5U][5U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][5U][6U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__output_data[5U][6U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][5U][7U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__output_data[5U][7U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][6U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__output_data[6U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][6U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__output_data[6U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][6U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__output_data[6U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][6U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__output_data[6U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][6U][4U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__output_data[6U][4U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][6U][5U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__output_data[6U][5U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][6U][6U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__output_data[6U][6U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][6U][7U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__output_data[6U][7U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][7U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__output_data[7U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][7U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__output_data[7U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][7U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__output_data[7U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][7U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__output_data[7U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][7U][4U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__output_data[7U][4U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][7U][5U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__output_data[7U][5U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][7U][6U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__output_data[7U][6U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][7U][7U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__output_data[7U][7U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_valid_signals 
        = ((0x0dU & (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_valid_signals)) 
           | ((IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__valid) 
              << 1U));
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_done_signals 
        = ((0x0dU & (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_done_signals)) 
           | ((IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__done) 
              << 1U));
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][0U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__output_data[0U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][0U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__output_data[0U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][0U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__output_data[0U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][0U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__output_data[0U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][0U][4U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__output_data[0U][4U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][0U][5U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__output_data[0U][5U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][0U][6U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__output_data[0U][6U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][0U][7U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__output_data[0U][7U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][1U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__output_data[1U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][1U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__output_data[1U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][1U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__output_data[1U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][1U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__output_data[1U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][1U][4U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__output_data[1U][4U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][1U][5U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__output_data[1U][5U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][1U][6U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__output_data[1U][6U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][1U][7U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__output_data[1U][7U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][2U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__output_data[2U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][2U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__output_data[2U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][2U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__output_data[2U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][2U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__output_data[2U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][2U][4U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__output_data[2U][4U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][2U][5U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__output_data[2U][5U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][2U][6U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__output_data[2U][6U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][2U][7U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__output_data[2U][7U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][3U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__output_data[3U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][3U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__output_data[3U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][3U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__output_data[3U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][3U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__output_data[3U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][3U][4U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__output_data[3U][4U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][3U][5U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__output_data[3U][5U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][3U][6U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__output_data[3U][6U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][3U][7U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__output_data[3U][7U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][4U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__output_data[4U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][4U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__output_data[4U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][4U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__output_data[4U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][4U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__output_data[4U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][4U][4U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__output_data[4U][4U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][4U][5U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__output_data[4U][5U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][4U][6U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__output_data[4U][6U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][4U][7U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__output_data[4U][7U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][5U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__output_data[5U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][5U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__output_data[5U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][5U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__output_data[5U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][5U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__output_data[5U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][5U][4U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__output_data[5U][4U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][5U][5U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__output_data[5U][5U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][5U][6U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__output_data[5U][6U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][5U][7U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__output_data[5U][7U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][6U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__output_data[6U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][6U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__output_data[6U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][6U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__output_data[6U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][6U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__output_data[6U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][6U][4U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__output_data[6U][4U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][6U][5U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__output_data[6U][5U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][6U][6U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__output_data[6U][6U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][6U][7U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__output_data[6U][7U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][7U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__output_data[7U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][7U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__output_data[7U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][7U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__output_data[7U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][7U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__output_data[7U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][7U][4U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__output_data[7U][4U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][7U][5U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__output_data[7U][5U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][7U][6U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__output_data[7U][6U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][7U][7U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__output_data[7U][7U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_valid_signals 
        = ((0x0bU & (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_valid_signals)) 
           | ((IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__valid) 
              << 2U));
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_done_signals 
        = ((0x0bU & (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_done_signals)) 
           | ((IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__done) 
              << 2U));
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][0U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__output_data[0U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][0U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__output_data[0U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][0U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__output_data[0U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][0U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__output_data[0U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][0U][4U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__output_data[0U][4U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][0U][5U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__output_data[0U][5U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][0U][6U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__output_data[0U][6U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][0U][7U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__output_data[0U][7U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][1U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__output_data[1U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][1U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__output_data[1U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][1U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__output_data[1U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][1U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__output_data[1U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][1U][4U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__output_data[1U][4U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][1U][5U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__output_data[1U][5U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][1U][6U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__output_data[1U][6U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][1U][7U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__output_data[1U][7U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][2U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__output_data[2U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][2U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__output_data[2U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][2U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__output_data[2U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][2U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__output_data[2U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][2U][4U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__output_data[2U][4U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][2U][5U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__output_data[2U][5U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][2U][6U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__output_data[2U][6U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][2U][7U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__output_data[2U][7U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][3U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__output_data[3U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][3U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__output_data[3U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][3U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__output_data[3U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][3U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__output_data[3U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][3U][4U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__output_data[3U][4U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][3U][5U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__output_data[3U][5U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][3U][6U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__output_data[3U][6U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][3U][7U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__output_data[3U][7U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][4U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__output_data[4U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][4U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__output_data[4U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][4U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__output_data[4U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][4U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__output_data[4U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][4U][4U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__output_data[4U][4U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][4U][5U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__output_data[4U][5U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][4U][6U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__output_data[4U][6U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][4U][7U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__output_data[4U][7U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][5U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__output_data[5U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][5U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__output_data[5U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][5U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__output_data[5U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][5U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__output_data[5U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][5U][4U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__output_data[5U][4U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][5U][5U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__output_data[5U][5U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][5U][6U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__output_data[5U][6U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][5U][7U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__output_data[5U][7U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][6U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__output_data[6U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][6U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__output_data[6U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][6U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__output_data[6U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][6U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__output_data[6U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][6U][4U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__output_data[6U][4U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][6U][5U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__output_data[6U][5U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][6U][6U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__output_data[6U][6U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][6U][7U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__output_data[6U][7U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][7U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__output_data[7U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][7U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__output_data[7U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][7U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__output_data[7U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][7U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__output_data[7U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][7U][4U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__output_data[7U][4U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][7U][5U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__output_data[7U][5U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][7U][6U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__output_data[7U][6U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][7U][7U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__output_data[7U][7U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_valid_signals 
        = ((7U & (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_valid_signals)) 
           | ((IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__valid) 
              << 3U));
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_done_signals 
        = ((7U & (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_done_signals)) 
           | ((IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__done) 
              << 3U));
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][0U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__output_data[0U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][0U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__output_data[0U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][0U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__output_data[0U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][0U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__output_data[0U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][0U][4U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__output_data[0U][4U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][0U][5U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__output_data[0U][5U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][0U][6U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__output_data[0U][6U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][0U][7U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__output_data[0U][7U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][1U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__output_data[1U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][1U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__output_data[1U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][1U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__output_data[1U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][1U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__output_data[1U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][1U][4U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__output_data[1U][4U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][1U][5U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__output_data[1U][5U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][1U][6U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__output_data[1U][6U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][1U][7U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__output_data[1U][7U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][2U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__output_data[2U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][2U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__output_data[2U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][2U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__output_data[2U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][2U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__output_data[2U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][2U][4U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__output_data[2U][4U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][2U][5U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__output_data[2U][5U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][2U][6U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__output_data[2U][6U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][2U][7U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__output_data[2U][7U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][3U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__output_data[3U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][3U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__output_data[3U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][3U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__output_data[3U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][3U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__output_data[3U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][3U][4U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__output_data[3U][4U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][3U][5U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__output_data[3U][5U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][3U][6U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__output_data[3U][6U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][3U][7U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__output_data[3U][7U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][4U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__output_data[4U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][4U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__output_data[4U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][4U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__output_data[4U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][4U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__output_data[4U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][4U][4U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__output_data[4U][4U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][4U][5U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__output_data[4U][5U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][4U][6U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__output_data[4U][6U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][4U][7U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__output_data[4U][7U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][5U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__output_data[5U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][5U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__output_data[5U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][5U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__output_data[5U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][5U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__output_data[5U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][5U][4U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__output_data[5U][4U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][5U][5U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__output_data[5U][5U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][5U][6U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__output_data[5U][6U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][5U][7U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__output_data[5U][7U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][6U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__output_data[6U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][6U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__output_data[6U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][6U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__output_data[6U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][6U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__output_data[6U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][6U][4U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__output_data[6U][4U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][6U][5U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__output_data[6U][5U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][6U][6U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__output_data[6U][6U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][6U][7U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__output_data[6U][7U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][7U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__output_data[7U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][7U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__output_data[7U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][7U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__output_data[7U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][7U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__output_data[7U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][7U][4U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__output_data[7U][4U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][7U][5U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__output_data[7U][5U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][7U][6U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__output_data[7U][6U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][7U][7U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__output_data[7U][7U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_valid_signals 
        = ((0x0eU & (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_valid_signals)) 
           | (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__valid));
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_done_signals 
        = ((0x0eU & (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_done_signals)) 
           | (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__done));
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][0U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__output_data[0U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][0U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__output_data[0U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][0U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__output_data[0U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][0U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__output_data[0U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][0U][4U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__output_data[0U][4U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][0U][5U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__output_data[0U][5U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][0U][6U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__output_data[0U][6U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][0U][7U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__output_data[0U][7U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][1U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__output_data[1U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][1U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__output_data[1U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][1U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__output_data[1U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][1U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__output_data[1U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][1U][4U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__output_data[1U][4U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][1U][5U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__output_data[1U][5U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][1U][6U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__output_data[1U][6U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][1U][7U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__output_data[1U][7U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][2U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__output_data[2U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][2U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__output_data[2U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][2U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__output_data[2U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][2U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__output_data[2U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][2U][4U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__output_data[2U][4U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][2U][5U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__output_data[2U][5U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][2U][6U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__output_data[2U][6U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][2U][7U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__output_data[2U][7U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][3U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__output_data[3U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][3U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__output_data[3U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][3U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__output_data[3U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][3U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__output_data[3U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][3U][4U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__output_data[3U][4U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][3U][5U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__output_data[3U][5U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][3U][6U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__output_data[3U][6U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][3U][7U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__output_data[3U][7U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][4U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__output_data[4U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][4U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__output_data[4U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][4U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__output_data[4U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][4U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__output_data[4U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][4U][4U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__output_data[4U][4U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][4U][5U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__output_data[4U][5U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][4U][6U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__output_data[4U][6U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][4U][7U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__output_data[4U][7U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][5U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__output_data[5U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][5U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__output_data[5U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][5U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__output_data[5U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][5U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__output_data[5U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][5U][4U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__output_data[5U][4U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][5U][5U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__output_data[5U][5U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][5U][6U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__output_data[5U][6U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][5U][7U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__output_data[5U][7U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][6U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__output_data[6U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][6U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__output_data[6U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][6U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__output_data[6U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][6U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__output_data[6U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][6U][4U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__output_data[6U][4U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][6U][5U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__output_data[6U][5U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][6U][6U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__output_data[6U][6U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][6U][7U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__output_data[6U][7U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][7U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__output_data[7U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][7U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__output_data[7U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][7U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__output_data[7U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][7U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__output_data[7U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][7U][4U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__output_data[7U][4U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][7U][5U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__output_data[7U][5U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][7U][6U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__output_data[7U][6U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[0U][7U][7U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__output_data[7U][7U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_valid_signals 
        = ((0x0dU & (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_valid_signals)) 
           | ((IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__valid) 
              << 1U));
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_done_signals 
        = ((0x0dU & (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_done_signals)) 
           | ((IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__done) 
              << 1U));
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][0U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__output_data[0U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][0U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__output_data[0U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][0U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__output_data[0U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][0U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__output_data[0U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][0U][4U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__output_data[0U][4U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][0U][5U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__output_data[0U][5U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][0U][6U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__output_data[0U][6U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][0U][7U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__output_data[0U][7U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][1U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__output_data[1U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][1U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__output_data[1U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][1U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__output_data[1U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][1U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__output_data[1U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][1U][4U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__output_data[1U][4U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][1U][5U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__output_data[1U][5U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][1U][6U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__output_data[1U][6U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][1U][7U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__output_data[1U][7U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][2U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__output_data[2U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][2U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__output_data[2U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][2U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__output_data[2U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][2U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__output_data[2U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][2U][4U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__output_data[2U][4U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][2U][5U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__output_data[2U][5U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][2U][6U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__output_data[2U][6U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][2U][7U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__output_data[2U][7U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][3U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__output_data[3U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][3U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__output_data[3U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][3U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__output_data[3U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][3U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__output_data[3U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][3U][4U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__output_data[3U][4U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][3U][5U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__output_data[3U][5U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][3U][6U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__output_data[3U][6U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][3U][7U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__output_data[3U][7U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][4U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__output_data[4U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][4U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__output_data[4U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][4U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__output_data[4U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][4U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__output_data[4U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][4U][4U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__output_data[4U][4U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][4U][5U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__output_data[4U][5U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][4U][6U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__output_data[4U][6U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][4U][7U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__output_data[4U][7U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][5U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__output_data[5U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][5U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__output_data[5U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][5U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__output_data[5U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][5U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__output_data[5U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][5U][4U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__output_data[5U][4U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][5U][5U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__output_data[5U][5U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][5U][6U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__output_data[5U][6U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][5U][7U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__output_data[5U][7U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][6U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__output_data[6U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][6U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__output_data[6U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][6U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__output_data[6U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][6U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__output_data[6U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][6U][4U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__output_data[6U][4U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][6U][5U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__output_data[6U][5U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][6U][6U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__output_data[6U][6U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][6U][7U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__output_data[6U][7U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][7U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__output_data[7U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][7U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__output_data[7U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][7U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__output_data[7U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][7U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__output_data[7U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][7U][4U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__output_data[7U][4U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][7U][5U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__output_data[7U][5U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][7U][6U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__output_data[7U][6U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[1U][7U][7U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__output_data[7U][7U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_valid_signals 
        = ((0x0bU & (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_valid_signals)) 
           | ((IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__valid) 
              << 2U));
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_done_signals 
        = ((0x0bU & (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_done_signals)) 
           | ((IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__done) 
              << 2U));
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][0U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__output_data[0U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][0U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__output_data[0U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][0U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__output_data[0U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][0U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__output_data[0U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][0U][4U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__output_data[0U][4U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][0U][5U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__output_data[0U][5U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][0U][6U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__output_data[0U][6U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][0U][7U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__output_data[0U][7U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][1U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__output_data[1U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][1U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__output_data[1U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][1U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__output_data[1U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][1U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__output_data[1U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][1U][4U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__output_data[1U][4U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][1U][5U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__output_data[1U][5U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][1U][6U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__output_data[1U][6U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][1U][7U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__output_data[1U][7U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][2U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__output_data[2U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][2U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__output_data[2U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][2U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__output_data[2U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][2U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__output_data[2U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][2U][4U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__output_data[2U][4U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][2U][5U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__output_data[2U][5U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][2U][6U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__output_data[2U][6U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][2U][7U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__output_data[2U][7U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][3U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__output_data[3U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][3U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__output_data[3U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][3U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__output_data[3U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][3U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__output_data[3U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][3U][4U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__output_data[3U][4U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][3U][5U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__output_data[3U][5U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][3U][6U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__output_data[3U][6U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][3U][7U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__output_data[3U][7U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][4U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__output_data[4U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][4U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__output_data[4U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][4U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__output_data[4U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][4U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__output_data[4U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][4U][4U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__output_data[4U][4U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][4U][5U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__output_data[4U][5U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][4U][6U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__output_data[4U][6U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][4U][7U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__output_data[4U][7U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][5U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__output_data[5U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][5U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__output_data[5U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][5U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__output_data[5U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][5U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__output_data[5U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][5U][4U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__output_data[5U][4U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][5U][5U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__output_data[5U][5U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][5U][6U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__output_data[5U][6U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][5U][7U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__output_data[5U][7U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][6U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__output_data[6U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][6U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__output_data[6U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][6U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__output_data[6U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][6U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__output_data[6U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][6U][4U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__output_data[6U][4U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][6U][5U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__output_data[6U][5U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][6U][6U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__output_data[6U][6U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][6U][7U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__output_data[6U][7U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][7U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__output_data[7U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][7U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__output_data[7U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][7U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__output_data[7U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][7U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__output_data[7U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][7U][4U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__output_data[7U][4U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][7U][5U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__output_data[7U][5U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][7U][6U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__output_data[7U][6U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[2U][7U][7U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__output_data[7U][7U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_valid_signals 
        = ((7U & (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_valid_signals)) 
           | ((IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__valid) 
              << 3U));
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_done_signals 
        = ((7U & (IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_done_signals)) 
           | ((IData)(vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__done) 
              << 3U));
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][0U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__output_data[0U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][0U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__output_data[0U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][0U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__output_data[0U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][0U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__output_data[0U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][0U][4U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__output_data[0U][4U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][0U][5U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__output_data[0U][5U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][0U][6U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__output_data[0U][6U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][0U][7U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__output_data[0U][7U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][1U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__output_data[1U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][1U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__output_data[1U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][1U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__output_data[1U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][1U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__output_data[1U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][1U][4U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__output_data[1U][4U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][1U][5U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__output_data[1U][5U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][1U][6U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__output_data[1U][6U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][1U][7U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__output_data[1U][7U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][2U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__output_data[2U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][2U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__output_data[2U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][2U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__output_data[2U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][2U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__output_data[2U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][2U][4U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__output_data[2U][4U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][2U][5U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__output_data[2U][5U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][2U][6U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__output_data[2U][6U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][2U][7U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__output_data[2U][7U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][3U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__output_data[3U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][3U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__output_data[3U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][3U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__output_data[3U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][3U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__output_data[3U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][3U][4U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__output_data[3U][4U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][3U][5U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__output_data[3U][5U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][3U][6U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__output_data[3U][6U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][3U][7U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__output_data[3U][7U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][4U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__output_data[4U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][4U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__output_data[4U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][4U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__output_data[4U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][4U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__output_data[4U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][4U][4U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__output_data[4U][4U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][4U][5U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__output_data[4U][5U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][4U][6U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__output_data[4U][6U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][4U][7U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__output_data[4U][7U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][5U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__output_data[5U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][5U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__output_data[5U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][5U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__output_data[5U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][5U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__output_data[5U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][5U][4U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__output_data[5U][4U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][5U][5U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__output_data[5U][5U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][5U][6U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__output_data[5U][6U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][5U][7U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__output_data[5U][7U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][6U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__output_data[6U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][6U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__output_data[6U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][6U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__output_data[6U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][6U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__output_data[6U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][6U][4U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__output_data[6U][4U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][6U][5U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__output_data[6U][5U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][6U][6U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__output_data[6U][6U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][6U][7U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__output_data[6U][7U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][7U][0U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__output_data[7U][0U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][7U][1U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__output_data[7U][1U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][7U][2U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__output_data[7U][2U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][7U][3U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__output_data[7U][3U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][7U][4U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__output_data[7U][4U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][7U][5U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__output_data[7U][5U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][7U][6U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__output_data[7U][6U];
    vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[3U][7U][7U] 
        = vlSelfRef.complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__output_data[7U][7U];
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

VL_ATTR_COLD void Vcomplete_transformer_decoder___024root___eval_stl(Vcomplete_transformer_decoder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcomplete_transformer_decoder___024root___eval_stl\n"); );
    Vcomplete_transformer_decoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        Vcomplete_transformer_decoder___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD bool Vcomplete_transformer_decoder___024root___eval_phase__stl(Vcomplete_transformer_decoder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcomplete_transformer_decoder___024root___eval_phase__stl\n"); );
    Vcomplete_transformer_decoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    Vcomplete_transformer_decoder___024root___eval_triggers_vec__stl(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vcomplete_transformer_decoder___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = Vcomplete_transformer_decoder___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        Vcomplete_transformer_decoder___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

bool Vcomplete_transformer_decoder___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vcomplete_transformer_decoder___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcomplete_transformer_decoder___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(Vcomplete_transformer_decoder___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

bool Vcomplete_transformer_decoder___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vcomplete_transformer_decoder___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcomplete_transformer_decoder___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vcomplete_transformer_decoder___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vcomplete_transformer_decoder___024root___ctor_var_reset(Vcomplete_transformer_decoder___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcomplete_transformer_decoder___024root___ctor_var_reset\n"); );
    Vcomplete_transformer_decoder__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18209466448985614591ull);
    vlSelf->start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9867861323841650631ull);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->input_sequence[__Vi0] = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 2557709653514853004ull);
    }
    vlSelf->predicted_token = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 8575329963259011807ull);
    vlSelf->done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10296494685231209730ull);
    vlSelf->valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4944192500720994163ull);
    vlSelf->cycle_count = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 812857792956672393ull);
    vlSelf->current_state_debug = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 16940262916852791614ull);
    vlSelf->complete_transformer_decoder__DOT__current_state = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 1407430763473524226ull);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 16; ++__Vi1) {
            vlSelf->complete_transformer_decoder__DOT__embedded_tokens[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 5844422592052120212ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 16; ++__Vi1) {
            vlSelf->complete_transformer_decoder__DOT__position_encoded[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 5134395829792889691ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 16; ++__Vi1) {
            vlSelf->complete_transformer_decoder__DOT__attention_out[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 3109538887492711717ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 16; ++__Vi1) {
            vlSelf->complete_transformer_decoder__DOT__norm1_out[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 11855927503095035039ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 16; ++__Vi1) {
            vlSelf->complete_transformer_decoder__DOT__ffn_out[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 715714594674332668ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 16; ++__Vi1) {
            vlSelf->complete_transformer_decoder__DOT__norm2_out[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 15192216579104394946ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 25; ++__Vi0) {
        vlSelf->complete_transformer_decoder__DOT__final_logits[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 1188891881299990043ull);
    }
    vlSelf->complete_transformer_decoder__DOT__embed_start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 701581964485029417ull);
    vlSelf->complete_transformer_decoder__DOT__pos_start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1783919157595644082ull);
    vlSelf->complete_transformer_decoder__DOT__attn_start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2441035093559136941ull);
    vlSelf->complete_transformer_decoder__DOT__norm1_start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10146588198354211580ull);
    vlSelf->complete_transformer_decoder__DOT__ffn_start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2943775579509610833ull);
    vlSelf->complete_transformer_decoder__DOT__norm2_start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17465700570439206826ull);
    vlSelf->complete_transformer_decoder__DOT__proj_start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10488845211186042636ull);
    vlSelf->complete_transformer_decoder__DOT__argmax_start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15242307937136495819ull);
    vlSelf->complete_transformer_decoder__DOT__embed_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15228647567084378033ull);
    vlSelf->complete_transformer_decoder__DOT__pos_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7687861538282638502ull);
    vlSelf->complete_transformer_decoder__DOT__attn_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8975111322415222308ull);
    vlSelf->complete_transformer_decoder__DOT__norm1_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3306796074115810440ull);
    vlSelf->complete_transformer_decoder__DOT__ffn_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5560850818493456913ull);
    vlSelf->complete_transformer_decoder__DOT__norm2_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15938606410092826861ull);
    vlSelf->complete_transformer_decoder__DOT__proj_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4510096114078952813ull);
    vlSelf->complete_transformer_decoder__DOT__argmax_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7874677173186979236ull);
    vlSelf->complete_transformer_decoder__DOT__embed_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10660707697165229160ull);
    vlSelf->complete_transformer_decoder__DOT__pos_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6259637039372431993ull);
    vlSelf->complete_transformer_decoder__DOT__attn_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4955908860394931795ull);
    vlSelf->complete_transformer_decoder__DOT__norm1_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12944751317093613616ull);
    vlSelf->complete_transformer_decoder__DOT__ffn_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11651559886993385096ull);
    vlSelf->complete_transformer_decoder__DOT__norm2_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14700385890431404647ull);
    vlSelf->complete_transformer_decoder__DOT__proj_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4849921473861494008ull);
    vlSelf->complete_transformer_decoder__DOT__argmax_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6155082903775622681ull);
    vlSelf->complete_transformer_decoder__DOT__last_pos = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 1640165224440424447ull);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->complete_transformer_decoder__DOT____Vcellinp__projection_inst__final_hidden_state[__Vi0] = 0;
    }
    vlSelf->complete_transformer_decoder__DOT__embedding_inst__DOT__state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 13622021808358492334ull);
    vlSelf->complete_transformer_decoder__DOT__embedding_inst__DOT__seq_idx = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 9941837458514407431ull);
    vlSelf->complete_transformer_decoder__DOT__embedding_inst__DOT__dim_idx = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 16500873399998844852ull);
    vlSelf->complete_transformer_decoder__DOT__embedding_inst__DOT__pipe_stage = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 2594685416138061009ull);
    vlSelf->complete_transformer_decoder__DOT__embedding_inst__DOT__embed_addr = VL_SCOPED_RAND_RESET_I(11, __VscopeHash, 13166641265086625480ull);
    vlSelf->complete_transformer_decoder__DOT__embedding_inst__DOT__embed_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 14188099233532191385ull);
    for (int __Vi0 = 0; __Vi0 < 1600; ++__Vi0) {
        vlSelf->complete_transformer_decoder__DOT__embedding_inst__DOT__embedding_memory__DOT__memory[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 13087173306483106230ull);
    }
    vlSelf->complete_transformer_decoder__DOT__positional_inst__DOT__state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 15114811848629550213ull);
    vlSelf->complete_transformer_decoder__DOT__positional_inst__DOT__seq_idx = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 11089365746220749406ull);
    vlSelf->complete_transformer_decoder__DOT__positional_inst__DOT__dim_idx = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 2280740888114501483ull);
    vlSelf->complete_transformer_decoder__DOT__positional_inst__DOT__pipe_stage = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 12555118773785758355ull);
    vlSelf->complete_transformer_decoder__DOT__positional_inst__DOT__pos_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 1874185365863751319ull);
    vlSelf->complete_transformer_decoder__DOT__positional_inst__DOT__temp_sum = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 4572295869209705987ull);
    for (int __Vi0 = 0; __Vi0 < 512; ++__Vi0) {
        vlSelf->complete_transformer_decoder__DOT__positional_inst__DOT__pos_memory__DOT__memory[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 10230696646505727734ull);
    }
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 2340597522516771173ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head_start_signals = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 14730211288942131941ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head_done_signals = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 16313109105174936849ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head_valid_signals = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 2862735327121327564ull);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 8; ++__Vi1) {
            for (int __Vi2 = 0; __Vi2 < 8; ++__Vi2) {
                vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head_outputs[__Vi0][__Vi1][__Vi2] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 688763301702021557ull);
            }
        }
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 16; ++__Vi1) {
            vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__concatenated[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 16941229822862431996ull);
        }
    }
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__seq_idx = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 2277157942122490785ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__dim_idx = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 1664618490988333815ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__in_dim = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 15016614366961216798ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__out_dim = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 10500617828755859813ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__pipe_stage = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 14132405102037123648ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__proj_accumulator = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18358965285570054896ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__wo_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 11417876001829632908ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__valid = 0;
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__done = 0;
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 8; ++__Vi1) {
            vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head0__output_data[__Vi0][__Vi1] = 0;
        }
    }
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__valid = 0;
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__done = 0;
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 8; ++__Vi1) {
            vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head1__output_data[__Vi0][__Vi1] = 0;
        }
    }
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__valid = 0;
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__done = 0;
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 8; ++__Vi1) {
            vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head2__output_data[__Vi0][__Vi1] = 0;
        }
    }
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__valid = 0;
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__done = 0;
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 8; ++__Vi1) {
            vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head3__output_data[__Vi0][__Vi1] = 0;
        }
    }
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__valid = 0;
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__done = 0;
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 8; ++__Vi1) {
            vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head4__output_data[__Vi0][__Vi1] = 0;
        }
    }
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__valid = 0;
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__done = 0;
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 8; ++__Vi1) {
            vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head5__output_data[__Vi0][__Vi1] = 0;
        }
    }
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__valid = 0;
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__done = 0;
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 8; ++__Vi1) {
            vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head6__output_data[__Vi0][__Vi1] = 0;
        }
    }
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__valid = 0;
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__done = 0;
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 8; ++__Vi1) {
            vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT____Vcellout__head7__output_data[__Vi0][__Vi1] = 0;
        }
    }
    for (int __Vi0 = 0; __Vi0 < 4096; ++__Vi0) {
        vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__wo_memory__DOT__memory[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 11405151438638065636ull);
    }
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head0__DOT__state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 5049535453767261644ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head0__DOT__seq_idx = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 11683640176762760431ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head0__DOT__seq_idx2 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 5783124668939135899ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head0__DOT__embed_idx = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 6771980990101083518ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head0__DOT__head_idx = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 17398139772784824604ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head0__DOT__pipe_stage = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 12221555429878384275ull);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 8; ++__Vi1) {
            vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head0__DOT__Q[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4530883379001424073ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 8; ++__Vi1) {
            vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head0__DOT__K[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 18085478390406893277ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 8; ++__Vi1) {
            vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head0__DOT__V[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 13371386525294928738ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 8; ++__Vi1) {
            vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head0__DOT__attention_scores[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 5943070805585041348ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 8; ++__Vi1) {
            vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head0__DOT__attention_weights[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 3520691217026775103ull);
        }
    }
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head0__DOT__accumulator = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12773668816201368925ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head0__DOT__wq_addr = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 16977667219294285162ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head0__DOT__wq_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4524539096864606612ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head0__DOT__wk_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9563385569854411609ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head0__DOT__wv_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 15724102131461851558ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head0__DOT__softmax_start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17047510972604821943ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head0__DOT__softmax_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10403954465725493341ull);
    for (int __Vi0 = 0; __Vi0 < 512; ++__Vi0) {
        vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head0__DOT__wq_mem__DOT__memory[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 16006707177408795835ull);
    }
    for (int __Vi0 = 0; __Vi0 < 512; ++__Vi0) {
        vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head0__DOT__wk_mem__DOT__memory[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 1052781629702173514ull);
    }
    for (int __Vi0 = 0; __Vi0 < 512; ++__Vi0) {
        vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head0__DOT__wv_mem__DOT__memory[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 12336746405071983326ull);
    }
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head0__DOT__softmax_inst__DOT__state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 11478683352933067551ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head0__DOT__softmax_inst__DOT__row_idx = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 9527313314798041223ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head0__DOT__softmax_inst__DOT__col_idx = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 8984256907565613035ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head0__DOT__softmax_inst__DOT__max_val = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 17688106182113283531ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head0__DOT__softmax_inst__DOT__exp_sum = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7925224685639230754ull);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head0__DOT__softmax_inst__DOT__temp_exp[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 6649002038332561853ull);
    }
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head1__DOT__state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 4257397343114230503ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head1__DOT__seq_idx = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 1195645379078729563ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head1__DOT__seq_idx2 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 15858679993772744544ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head1__DOT__embed_idx = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 9035781902218040187ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head1__DOT__head_idx = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 8383544489387368671ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head1__DOT__pipe_stage = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 13689167643377462993ull);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 8; ++__Vi1) {
            vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head1__DOT__Q[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9836017205112266101ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 8; ++__Vi1) {
            vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head1__DOT__K[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 17045680882366808308ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 8; ++__Vi1) {
            vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head1__DOT__V[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 15463767732876913276ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 8; ++__Vi1) {
            vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head1__DOT__attention_scores[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 5704016339716383870ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 8; ++__Vi1) {
            vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head1__DOT__attention_weights[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 12271452962789043282ull);
        }
    }
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head1__DOT__accumulator = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11555525656672431532ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head1__DOT__wq_addr = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 11684254780891201364ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head1__DOT__wq_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9200479534717273623ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head1__DOT__wk_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 7953653208607641277ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head1__DOT__wv_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 7159314843939377511ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head1__DOT__softmax_start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8181870943774209524ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head1__DOT__softmax_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6041329378875899856ull);
    for (int __Vi0 = 0; __Vi0 < 512; ++__Vi0) {
        vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head1__DOT__wq_mem__DOT__memory[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 6666446884472147583ull);
    }
    for (int __Vi0 = 0; __Vi0 < 512; ++__Vi0) {
        vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head1__DOT__wk_mem__DOT__memory[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 3384334392727667229ull);
    }
    for (int __Vi0 = 0; __Vi0 < 512; ++__Vi0) {
        vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head1__DOT__wv_mem__DOT__memory[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 13701890842256848760ull);
    }
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head1__DOT__softmax_inst__DOT__state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 4221443235298678167ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head1__DOT__softmax_inst__DOT__row_idx = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 16180768206373383076ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head1__DOT__softmax_inst__DOT__col_idx = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 7787692101739393227ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head1__DOT__softmax_inst__DOT__max_val = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 3243739247207199422ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head1__DOT__softmax_inst__DOT__exp_sum = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1117442999721541317ull);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head1__DOT__softmax_inst__DOT__temp_exp[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 16098230078309827514ull);
    }
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head2__DOT__state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 14284291249953634997ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head2__DOT__seq_idx = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 11943576874367859953ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head2__DOT__seq_idx2 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 18211522428312718590ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head2__DOT__embed_idx = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 2751318488246275162ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head2__DOT__head_idx = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 9338453570613321013ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head2__DOT__pipe_stage = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 6420101847905830682ull);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 8; ++__Vi1) {
            vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head2__DOT__Q[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 14337291560027590091ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 8; ++__Vi1) {
            vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head2__DOT__K[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 15350026000094833531ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 8; ++__Vi1) {
            vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head2__DOT__V[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 1464157876978797812ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 8; ++__Vi1) {
            vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head2__DOT__attention_scores[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 13909066141793870882ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 8; ++__Vi1) {
            vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head2__DOT__attention_weights[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 17439764893406758167ull);
        }
    }
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head2__DOT__accumulator = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14923766190381338288ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head2__DOT__wq_addr = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 6309943224169176381ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head2__DOT__wq_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9327323376317718178ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head2__DOT__wk_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4528988991924247903ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head2__DOT__wv_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 13749876976353599148ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head2__DOT__softmax_start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15612753102358735248ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head2__DOT__softmax_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14194544753483266ull);
    for (int __Vi0 = 0; __Vi0 < 512; ++__Vi0) {
        vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head2__DOT__wq_mem__DOT__memory[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 10059277893752830522ull);
    }
    for (int __Vi0 = 0; __Vi0 < 512; ++__Vi0) {
        vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head2__DOT__wk_mem__DOT__memory[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9810197121285356906ull);
    }
    for (int __Vi0 = 0; __Vi0 < 512; ++__Vi0) {
        vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head2__DOT__wv_mem__DOT__memory[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 16687205582666784948ull);
    }
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head2__DOT__softmax_inst__DOT__state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 13761891246997228469ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head2__DOT__softmax_inst__DOT__row_idx = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 3746106347432306592ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head2__DOT__softmax_inst__DOT__col_idx = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 5083547582495276259ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head2__DOT__softmax_inst__DOT__max_val = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9177671297382371224ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head2__DOT__softmax_inst__DOT__exp_sum = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8448335353356694746ull);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head2__DOT__softmax_inst__DOT__temp_exp[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 5251732358709231703ull);
    }
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head3__DOT__state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 3089889625135563380ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head3__DOT__seq_idx = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 411770310472355257ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head3__DOT__seq_idx2 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 9775177846997406721ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head3__DOT__embed_idx = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 8628135713613160345ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head3__DOT__head_idx = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 9519980452201609817ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head3__DOT__pipe_stage = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 13634090742663600822ull);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 8; ++__Vi1) {
            vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head3__DOT__Q[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 788640669372320434ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 8; ++__Vi1) {
            vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head3__DOT__K[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 2890362801753417625ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 8; ++__Vi1) {
            vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head3__DOT__V[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 2993332733243449537ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 8; ++__Vi1) {
            vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head3__DOT__attention_scores[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 6890430756203761085ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 8; ++__Vi1) {
            vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head3__DOT__attention_weights[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 2822366865839268316ull);
        }
    }
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head3__DOT__accumulator = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13130771217863124308ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head3__DOT__wq_addr = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 8569715946858288844ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head3__DOT__wq_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 8172385358082216157ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head3__DOT__wk_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 2208422668000163226ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head3__DOT__wv_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 1284339584722937171ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head3__DOT__softmax_start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11783494554470931912ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head3__DOT__softmax_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 820899568804414400ull);
    for (int __Vi0 = 0; __Vi0 < 512; ++__Vi0) {
        vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head3__DOT__wq_mem__DOT__memory[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 3660238856361916911ull);
    }
    for (int __Vi0 = 0; __Vi0 < 512; ++__Vi0) {
        vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head3__DOT__wk_mem__DOT__memory[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 2943759531830391565ull);
    }
    for (int __Vi0 = 0; __Vi0 < 512; ++__Vi0) {
        vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head3__DOT__wv_mem__DOT__memory[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 13091788370144058310ull);
    }
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head3__DOT__softmax_inst__DOT__state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 10521094381914430563ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head3__DOT__softmax_inst__DOT__row_idx = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 4020747793202005205ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head3__DOT__softmax_inst__DOT__col_idx = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 17097335038283690067ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head3__DOT__softmax_inst__DOT__max_val = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 3871777587452732143ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head3__DOT__softmax_inst__DOT__exp_sum = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10435658463374255627ull);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head3__DOT__softmax_inst__DOT__temp_exp[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4894220272827843532ull);
    }
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head4__DOT__state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 1018681421461555064ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head4__DOT__seq_idx = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 9643556214507157286ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head4__DOT__seq_idx2 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 9469920621990446324ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head4__DOT__embed_idx = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 7213703792681478212ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head4__DOT__head_idx = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 11836061975003715160ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head4__DOT__pipe_stage = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 17027748142814427015ull);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 8; ++__Vi1) {
            vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head4__DOT__Q[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 16355801830047947835ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 8; ++__Vi1) {
            vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head4__DOT__K[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 7983415001104598884ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 8; ++__Vi1) {
            vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head4__DOT__V[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 29853760940656773ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 8; ++__Vi1) {
            vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head4__DOT__attention_scores[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 7823154433869206383ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 8; ++__Vi1) {
            vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head4__DOT__attention_weights[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9625531023645292507ull);
        }
    }
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head4__DOT__accumulator = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2557489834616054265ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head4__DOT__wq_addr = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 12784286187575352970ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head4__DOT__wq_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 8379464539724707677ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head4__DOT__wk_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 17277406469710941456ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head4__DOT__wv_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 15617484723221104167ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head4__DOT__softmax_start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11244344156176344216ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head4__DOT__softmax_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12309449976415511562ull);
    for (int __Vi0 = 0; __Vi0 < 512; ++__Vi0) {
        vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head4__DOT__wq_mem__DOT__memory[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 1761943075354119052ull);
    }
    for (int __Vi0 = 0; __Vi0 < 512; ++__Vi0) {
        vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head4__DOT__wk_mem__DOT__memory[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 179474580255837891ull);
    }
    for (int __Vi0 = 0; __Vi0 < 512; ++__Vi0) {
        vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head4__DOT__wv_mem__DOT__memory[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 1002006052865502930ull);
    }
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head4__DOT__softmax_inst__DOT__state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 16341222310388431273ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head4__DOT__softmax_inst__DOT__row_idx = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 5632186994885328647ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head4__DOT__softmax_inst__DOT__col_idx = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 7681428255586047504ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head4__DOT__softmax_inst__DOT__max_val = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 186498951707852785ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head4__DOT__softmax_inst__DOT__exp_sum = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12209456479212223336ull);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head4__DOT__softmax_inst__DOT__temp_exp[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 15150866763357688566ull);
    }
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head5__DOT__state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 7415241531928677746ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head5__DOT__seq_idx = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 15987438433229432530ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head5__DOT__seq_idx2 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 6994532147622140665ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head5__DOT__embed_idx = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 12757865772438473902ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head5__DOT__head_idx = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 9806793411094238610ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head5__DOT__pipe_stage = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 15455497780154169452ull);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 8; ++__Vi1) {
            vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head5__DOT__Q[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 18140128231593351250ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 8; ++__Vi1) {
            vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head5__DOT__K[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 12753720310602254567ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 8; ++__Vi1) {
            vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head5__DOT__V[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 2106296787106159821ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 8; ++__Vi1) {
            vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head5__DOT__attention_scores[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 897049034965944012ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 8; ++__Vi1) {
            vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head5__DOT__attention_weights[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 3716208191372488102ull);
        }
    }
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head5__DOT__accumulator = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 315905396023675728ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head5__DOT__wq_addr = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 3639489047053350666ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head5__DOT__wq_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 5288520358354367140ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head5__DOT__wk_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 206013655037875371ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head5__DOT__wv_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 13893867509402144744ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head5__DOT__softmax_start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6139459009599166509ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head5__DOT__softmax_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15561902463555192873ull);
    for (int __Vi0 = 0; __Vi0 < 512; ++__Vi0) {
        vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head5__DOT__wq_mem__DOT__memory[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 5232321220840719136ull);
    }
    for (int __Vi0 = 0; __Vi0 < 512; ++__Vi0) {
        vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head5__DOT__wk_mem__DOT__memory[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 11641033557277736191ull);
    }
    for (int __Vi0 = 0; __Vi0 < 512; ++__Vi0) {
        vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head5__DOT__wv_mem__DOT__memory[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 14609566190927849202ull);
    }
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head5__DOT__softmax_inst__DOT__state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 15302136115217816766ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head5__DOT__softmax_inst__DOT__row_idx = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 663159213696747697ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head5__DOT__softmax_inst__DOT__col_idx = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 16881952483678736517ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head5__DOT__softmax_inst__DOT__max_val = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 11024467672619259335ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head5__DOT__softmax_inst__DOT__exp_sum = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9091132109346645550ull);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head5__DOT__softmax_inst__DOT__temp_exp[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9766719047242896971ull);
    }
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head6__DOT__state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 11036773535313395465ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head6__DOT__seq_idx = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 8889071450562966501ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head6__DOT__seq_idx2 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 14080916746724305499ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head6__DOT__embed_idx = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 15755769494815855314ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head6__DOT__head_idx = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 1945451954266401058ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head6__DOT__pipe_stage = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 8449278475780485035ull);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 8; ++__Vi1) {
            vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head6__DOT__Q[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9369002907802321306ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 8; ++__Vi1) {
            vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head6__DOT__K[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 7885423105240017033ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 8; ++__Vi1) {
            vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head6__DOT__V[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 5749739252732861282ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 8; ++__Vi1) {
            vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head6__DOT__attention_scores[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 798438366002367931ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 8; ++__Vi1) {
            vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head6__DOT__attention_weights[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 8957053136986996677ull);
        }
    }
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head6__DOT__accumulator = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13340264484518238987ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head6__DOT__wq_addr = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 5885834195349094943ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head6__DOT__wq_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 12440068639808546892ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head6__DOT__wk_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 14773993724861294020ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head6__DOT__wv_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 18062308183054724799ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head6__DOT__softmax_start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4554095107598261443ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head6__DOT__softmax_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1760160947960700451ull);
    for (int __Vi0 = 0; __Vi0 < 512; ++__Vi0) {
        vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head6__DOT__wq_mem__DOT__memory[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 10817528045963405020ull);
    }
    for (int __Vi0 = 0; __Vi0 < 512; ++__Vi0) {
        vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head6__DOT__wk_mem__DOT__memory[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4317025483173326114ull);
    }
    for (int __Vi0 = 0; __Vi0 < 512; ++__Vi0) {
        vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head6__DOT__wv_mem__DOT__memory[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 493296345965380243ull);
    }
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head6__DOT__softmax_inst__DOT__state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 1289856124014252514ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head6__DOT__softmax_inst__DOT__row_idx = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 15401836060632216225ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head6__DOT__softmax_inst__DOT__col_idx = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 5585157916907914262ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head6__DOT__softmax_inst__DOT__max_val = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 16468595914174015815ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head6__DOT__softmax_inst__DOT__exp_sum = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3144151189381802434ull);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head6__DOT__softmax_inst__DOT__temp_exp[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 10205349161430240770ull);
    }
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head7__DOT__state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 427523884709158334ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head7__DOT__seq_idx = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 11280347921609080823ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head7__DOT__seq_idx2 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 7080016558651328385ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head7__DOT__embed_idx = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 641252709152230326ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head7__DOT__head_idx = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 17297961889194425062ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head7__DOT__pipe_stage = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 2494085370784298500ull);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 8; ++__Vi1) {
            vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head7__DOT__Q[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 18358319023913308056ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 8; ++__Vi1) {
            vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head7__DOT__K[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 7428621970091664896ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 8; ++__Vi1) {
            vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head7__DOT__V[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 14892817645716850059ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 8; ++__Vi1) {
            vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head7__DOT__attention_scores[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 8042434217093130603ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 8; ++__Vi1) {
            vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head7__DOT__attention_weights[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 2539623705015246389ull);
        }
    }
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head7__DOT__accumulator = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5289021507124535192ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head7__DOT__wq_addr = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 12507870204281829378ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head7__DOT__wq_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 12169793625059148439ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head7__DOT__wk_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 15660022355578076540ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head7__DOT__wv_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 11488994797145244762ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head7__DOT__softmax_start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12180598817875981030ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head7__DOT__softmax_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12668018983343133966ull);
    for (int __Vi0 = 0; __Vi0 < 512; ++__Vi0) {
        vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head7__DOT__wq_mem__DOT__memory[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 14188172195895774385ull);
    }
    for (int __Vi0 = 0; __Vi0 < 512; ++__Vi0) {
        vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head7__DOT__wk_mem__DOT__memory[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4807864864209809366ull);
    }
    for (int __Vi0 = 0; __Vi0 < 512; ++__Vi0) {
        vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head7__DOT__wv_mem__DOT__memory[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 350632002398246333ull);
    }
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head7__DOT__softmax_inst__DOT__state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 2701176392782467644ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head7__DOT__softmax_inst__DOT__row_idx = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 16548886511598005180ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head7__DOT__softmax_inst__DOT__col_idx = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 10980093480577813208ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head7__DOT__softmax_inst__DOT__max_val = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 11945367314479101317ull);
    vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head7__DOT__softmax_inst__DOT__exp_sum = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16139431828960269798ull);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->complete_transformer_decoder__DOT__attention_inst__DOT__head7__DOT__softmax_inst__DOT__temp_exp[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 12412470486204776804ull);
    }
    vlSelf->complete_transformer_decoder__DOT__layer_norm1_inst__DOT__state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 12329422834520350793ull);
    vlSelf->complete_transformer_decoder__DOT__layer_norm1_inst__DOT__seq_idx = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 10066934590738459802ull);
    vlSelf->complete_transformer_decoder__DOT__layer_norm1_inst__DOT__dim_idx = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 14548416854866645651ull);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 16; ++__Vi1) {
            vlSelf->complete_transformer_decoder__DOT__layer_norm1_inst__DOT__sum_data[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 2365826212495495552ull);
        }
    }
    vlSelf->complete_transformer_decoder__DOT__layer_norm1_inst__DOT__mean_acc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16007504283060391114ull);
    vlSelf->complete_transformer_decoder__DOT__layer_norm1_inst__DOT__var_acc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16562698421773470101ull);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->complete_transformer_decoder__DOT__layer_norm1_inst__DOT__mean_val[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 11857637797470453016ull);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->complete_transformer_decoder__DOT__layer_norm1_inst__DOT__std_val[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 14538072751556889326ull);
    }
    vlSelf->complete_transformer_decoder__DOT__layer_norm1_inst__DOT__pipe_stage = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 13031894908850033818ull);
    vlSelf->complete_transformer_decoder__DOT__layer_norm1_inst__DOT__temp_sum = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 808811339877500490ull);
    vlSelf->complete_transformer_decoder__DOT__layer_norm1_inst__DOT__diff = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13477390394193068178ull);
    vlSelf->complete_transformer_decoder__DOT__layer_norm1_inst__DOT__diff_sq = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4425754805387322650ull);
    vlSelf->complete_transformer_decoder__DOT__layer_norm1_inst__DOT__normalized = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3895229934649625180ull);
    vlSelf->complete_transformer_decoder__DOT__layer_norm1_inst__DOT__with_gamma = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8737850441534091183ull);
    vlSelf->complete_transformer_decoder__DOT__layer_norm1_inst__DOT__final_result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3044496854033573672ull);
    vlSelf->complete_transformer_decoder__DOT__layer_norm1_inst__DOT__variance = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7149744528863894552ull);
    vlSelf->complete_transformer_decoder__DOT__layer_norm1_inst__DOT__gamma_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 3154248134791779020ull);
    vlSelf->complete_transformer_decoder__DOT__layer_norm1_inst__DOT__beta_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 6479978315991358893ull);
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->complete_transformer_decoder__DOT__layer_norm1_inst__DOT__gamma_memory__DOT__memory[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 12545838840141943973ull);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->complete_transformer_decoder__DOT__layer_norm1_inst__DOT__beta_memory__DOT__memory[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 13300290926594472041ull);
    }
    vlSelf->complete_transformer_decoder__DOT__ffn_inst__DOT__state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 9042728069195796526ull);
    vlSelf->complete_transformer_decoder__DOT__ffn_inst__DOT__seq_idx = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 9812303032590194999ull);
    vlSelf->complete_transformer_decoder__DOT__ffn_inst__DOT__in_dim = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 5099013045647074887ull);
    vlSelf->complete_transformer_decoder__DOT__ffn_inst__DOT__out_dim = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 475216982621214569ull);
    vlSelf->complete_transformer_decoder__DOT__ffn_inst__DOT__hidden_dim = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10478185909973250737ull);
    vlSelf->complete_transformer_decoder__DOT__ffn_inst__DOT__accumulator = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15267047661065579492ull);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 32; ++__Vi1) {
            vlSelf->complete_transformer_decoder__DOT__ffn_inst__DOT__hidden_data[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 7059463469490241239ull);
        }
    }
    vlSelf->complete_transformer_decoder__DOT__ffn_inst__DOT__pipe_stage = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 7725084973144709623ull);
    vlSelf->complete_transformer_decoder__DOT__ffn_inst__DOT__w1_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 7394411336128456581ull);
    vlSelf->complete_transformer_decoder__DOT__ffn_inst__DOT__w2_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 16078059148658740907ull);
    vlSelf->complete_transformer_decoder__DOT__ffn_inst__DOT__b1_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 13978001219086497667ull);
    vlSelf->complete_transformer_decoder__DOT__ffn_inst__DOT__b2_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9250303140691208733ull);
    vlSelf->complete_transformer_decoder__DOT__ffn_inst__DOT__with_bias = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14121894936887017316ull);
    for (int __Vi0 = 0; __Vi0 < 16384; ++__Vi0) {
        vlSelf->complete_transformer_decoder__DOT__ffn_inst__DOT__w1_memory__DOT__memory[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 11091864711506753968ull);
    }
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->complete_transformer_decoder__DOT__ffn_inst__DOT__b1_memory__DOT__memory[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 7142941714927575646ull);
    }
    for (int __Vi0 = 0; __Vi0 < 16384; ++__Vi0) {
        vlSelf->complete_transformer_decoder__DOT__ffn_inst__DOT__w2_memory__DOT__memory[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 3644003186553033734ull);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->complete_transformer_decoder__DOT__ffn_inst__DOT__b2_memory__DOT__memory[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 1411530892362172063ull);
    }
    vlSelf->complete_transformer_decoder__DOT__layer_norm2_inst__DOT__state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 18049247565568356536ull);
    vlSelf->complete_transformer_decoder__DOT__layer_norm2_inst__DOT__seq_idx = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 15499221956066439598ull);
    vlSelf->complete_transformer_decoder__DOT__layer_norm2_inst__DOT__dim_idx = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 4036643573239093179ull);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 16; ++__Vi1) {
            vlSelf->complete_transformer_decoder__DOT__layer_norm2_inst__DOT__sum_data[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 829360335978631192ull);
        }
    }
    vlSelf->complete_transformer_decoder__DOT__layer_norm2_inst__DOT__mean_acc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8729706341401190216ull);
    vlSelf->complete_transformer_decoder__DOT__layer_norm2_inst__DOT__var_acc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 581607290410453355ull);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->complete_transformer_decoder__DOT__layer_norm2_inst__DOT__mean_val[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 1724903377347956351ull);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->complete_transformer_decoder__DOT__layer_norm2_inst__DOT__std_val[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 11198096976557339399ull);
    }
    vlSelf->complete_transformer_decoder__DOT__layer_norm2_inst__DOT__pipe_stage = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 2634608815670473820ull);
    vlSelf->complete_transformer_decoder__DOT__layer_norm2_inst__DOT__temp_sum = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 11308476933759108360ull);
    vlSelf->complete_transformer_decoder__DOT__layer_norm2_inst__DOT__diff = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3426157009644245603ull);
    vlSelf->complete_transformer_decoder__DOT__layer_norm2_inst__DOT__diff_sq = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2328405715169006457ull);
    vlSelf->complete_transformer_decoder__DOT__layer_norm2_inst__DOT__normalized = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6535198260607130885ull);
    vlSelf->complete_transformer_decoder__DOT__layer_norm2_inst__DOT__with_gamma = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2175219713611871713ull);
    vlSelf->complete_transformer_decoder__DOT__layer_norm2_inst__DOT__final_result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 141773035874581578ull);
    vlSelf->complete_transformer_decoder__DOT__layer_norm2_inst__DOT__variance = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 218076469295419078ull);
    vlSelf->complete_transformer_decoder__DOT__layer_norm2_inst__DOT__gamma_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 2594559916725607853ull);
    vlSelf->complete_transformer_decoder__DOT__layer_norm2_inst__DOT__beta_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 3995601647310777465ull);
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->complete_transformer_decoder__DOT__layer_norm2_inst__DOT__gamma_memory__DOT__memory[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 7011374155671026641ull);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->complete_transformer_decoder__DOT__layer_norm2_inst__DOT__beta_memory__DOT__memory[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 14037969849293741663ull);
    }
    vlSelf->complete_transformer_decoder__DOT__projection_inst__DOT____Vlvbound_h188df00a__0 = 0;
    vlSelf->complete_transformer_decoder__DOT__projection_inst__DOT__state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 17814250794509323605ull);
    vlSelf->complete_transformer_decoder__DOT__projection_inst__DOT__vocab_idx = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 16357333361685827599ull);
    vlSelf->complete_transformer_decoder__DOT__projection_inst__DOT__dim_idx = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 15630977751391636543ull);
    vlSelf->complete_transformer_decoder__DOT__projection_inst__DOT__logit_accumulator = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8578483770200121993ull);
    vlSelf->complete_transformer_decoder__DOT__projection_inst__DOT__pipe_stage = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 10575446631327221810ull);
    vlSelf->complete_transformer_decoder__DOT__projection_inst__DOT__proj_addr = VL_SCOPED_RAND_RESET_I(11, __VscopeHash, 5240825145917978967ull);
    vlSelf->complete_transformer_decoder__DOT__projection_inst__DOT__proj_data = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 1103941302865051885ull);
    for (int __Vi0 = 0; __Vi0 < 1600; ++__Vi0) {
        vlSelf->complete_transformer_decoder__DOT__projection_inst__DOT__proj_memory__DOT__memory[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 8742614440247312857ull);
    }
    vlSelf->complete_transformer_decoder__DOT__argmax_inst__DOT__state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 4145940606324569983ull);
    vlSelf->complete_transformer_decoder__DOT__argmax_inst__DOT__current_idx = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 6909826310706429847ull);
    vlSelf->complete_transformer_decoder__DOT__argmax_inst__DOT__max_value = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 6857451670204564309ull);
    vlSelf->complete_transformer_decoder__DOT__argmax_inst__DOT__max_index = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 8188264415641414885ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
}
