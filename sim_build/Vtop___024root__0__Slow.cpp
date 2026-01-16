// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__PCLK__0 
        = vlSelfRef.tb__DOT__dut__DOT__PCLK;
    vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__PRESETn__0 
        = vlSelfRef.tb__DOT__dut__DOT__PRESETn;
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial__TOP\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->_vm_contextp__->dumpfile("apb_wave.vcd"s);
    vlSymsp->_traceDumpOpen();
    VL_WRITEF_NX("[TB] Starting APB slave testbench\n",0);
}

VL_ATTR_COLD void Vtop___024root___eval_final(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_final\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("/home/thilagan/apb_dv/tb.sv", 3, "", "Settle region did not converge after 100 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
    } while (Vtop___024root___eval_phase__stl(vlSelf));
}

VL_ATTR_COLD void Vtop___024root___eval_triggers__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered
                                      [0U]) | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
    vlSelfRef.__VstlFirstIteration = 0U;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
}

VL_ATTR_COLD bool Vtop___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vtop___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__stl\n"); );
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

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtop___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = Vtop___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        Vtop___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

bool Vtop___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

bool Vtop___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge tb.dut.PCLK)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(negedge tb.dut.PRESETn)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->tb__DOT__PCLK = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17829247089749607885ull);
    vlSelf->tb__DOT__PRESETn = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 658200015297248573ull);
    vlSelf->tb__DOT__PSEL = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9380389336945894153ull);
    vlSelf->tb__DOT__PENABLE = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4070838848877612273ull);
    vlSelf->tb__DOT__PWRITE = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3630847930058728204ull);
    vlSelf->tb__DOT__PADDR = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15456074774235383449ull);
    vlSelf->tb__DOT__PWDATA = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11573698826740242340ull);
    vlSelf->tb__DOT__PRDATA = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6994026042078388301ull);
    vlSelf->tb__DOT__PREADY = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1053476772438961381ull);
    vlSelf->tb__DOT__PSLVERR = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1067606044798523819ull);
    vlSelf->tb__DOT__dut__DOT__PCLK = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8852212907763837380ull);
    vlSelf->tb__DOT__dut__DOT__PRESETn = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2695388668498323946ull);
    vlSelf->tb__DOT__dut__DOT__PSEL = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5735070643825359142ull);
    vlSelf->tb__DOT__dut__DOT__PENABLE = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 55329011388308855ull);
    vlSelf->tb__DOT__dut__DOT__PWRITE = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2646973554784103022ull);
    vlSelf->tb__DOT__dut__DOT__PADDR = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10277271582582118263ull);
    vlSelf->tb__DOT__dut__DOT__PWDATA = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15541085599552565147ull);
    vlSelf->tb__DOT__dut__DOT__PRDATA = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9186053927512734094ull);
    vlSelf->tb__DOT__dut__DOT__PREADY = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5947668891065063622ull);
    vlSelf->tb__DOT__dut__DOT__PSLVERR = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15981066531538993887ull);
    vlSelf->tb__DOT__dut__DOT__wait_cnt = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 3997117025159583119ull);
    vlSelf->tb__DOT__dut__DOT__wait_target = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 1334509828636456656ull);
    vlSelf->tb__DOT__dut__DOT__addr_latched = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9172220546097492905ull);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->tb__DOT__dut__DOT__regfile[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14493446850900023233ull);
    }
    vlSelf->tb__DOT__dut__DOT__xfer_done_next = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 202892457913151503ull);
    vlSelf->tb__DOT__dut__DOT__xfer_active = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5963342442981236514ull);
    vlSelf->tb__DOT__dut__DOT__pslverr_next = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6927523350989196337ull);
    vlSelf->tb__DOT__dut__DOT___Vpast_5_1 = 0;
    vlSelf->tb__DOT__dut__DOT___Vpast_7_1 = 0;
    vlSelf->tb__DOT__dut__DOT___Vpast_11_1 = 0;
    vlSelf->tb__DOT__dut__DOT___Vpast_13_1 = 0;
    vlSelf->tb__DOT__dut__DOT___Vpast_14_1 = 0;
    vlSelf->tb__DOT__dut__DOT___Vpast_16_1 = 0;
    vlSelf->tb__DOT__dut__DOT__unnamedblk1__DOT__rand_val = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8949733274158309568ull);
    vlSelf->__Vsampled_TOP__tb__DOT__dut__DOT__PRESETn = 0;
    vlSelf->__Vsampled_TOP__tb__DOT__dut__DOT__PREADY = 0;
    vlSelf->__Vsampled_TOP__tb__DOT__dut__DOT__PSEL = 0;
    vlSelf->__Vsampled_TOP__tb__DOT__dut__DOT__PENABLE = 0;
    vlSelf->__Vsampled_TOP__tb__DOT__dut__DOT__xfer_done_next = 0;
    vlSelf->__Vsampled_TOP__tb__DOT__dut__DOT__PWRITE = 0;
    vlSelf->__Vsampled_TOP__tb__DOT__dut__DOT___Vpast_5_1 = 0;
    vlSelf->__Vsampled_TOP__tb__DOT__dut__DOT___Vpast_7_1 = 0;
    vlSelf->__Vsampled_TOP__tb__DOT__dut__DOT__xfer_active = 0;
    vlSelf->__Vsampled_TOP__tb__DOT__dut__DOT__wait_target = 0;
    vlSelf->__Vsampled_TOP__tb__DOT__dut__DOT___Vpast_11_1 = 0;
    vlSelf->__Vsampled_TOP__tb__DOT__dut__DOT___Vpast_13_1 = 0;
    vlSelf->__Vsampled_TOP__tb__DOT__dut__DOT__PSLVERR = 0;
    vlSelf->__Vsampled_TOP__tb__DOT__dut__DOT___Vpast_14_1 = 0;
    vlSelf->__Vsampled_TOP__tb__DOT__dut__DOT___Vpast_16_1 = 0;
    vlSelf->__Vsampled_TOP__tb__DOT__dut__DOT__addr_latched = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__PCLK__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__PRESETn__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
}
