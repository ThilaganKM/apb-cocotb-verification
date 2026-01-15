// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf);
VlCoroutine Vtop___024root___eval_initial__TOP__Vtiming__0(Vtop___024root* vlSelf);

void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root___eval_initial__TOP(vlSelf);
    Vtop___024root___eval_initial__TOP__Vtiming__0(vlSelf);
}

VlCoroutine Vtop___024root___eval_initial__TOP__Vtiming__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__PCLK = 0U;
    while (true) {
        co_await vlSelfRef.__VdlySched.delay(0x0000000000001388ULL, 
                                             nullptr, 
                                             "/home/thilagan/apb_dv/tb.sv", 
                                             18);
        vlSelfRef.tb__DOT__PCLK = (1U & (~ (IData)(vlSelfRef.tb__DOT__PCLK)));
    }
    co_return;}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void Vtop___024root___eval_triggers__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered
                                      [0U]) | (IData)((IData)(vlSelfRef.__VicoFirstIteration)));
    vlSelfRef.__VicoFirstIteration = 0U;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
}

bool Vtop___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__ico\n"); );
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

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__dut__DOT__PCLK = vlSelfRef.tb__DOT__PCLK;
    vlSelfRef.tb__DOT__dut__DOT__PRESETn = vlSelfRef.tb__DOT__PRESETn;
    vlSelfRef.tb__DOT__dut__DOT__PADDR = vlSelfRef.tb__DOT__PADDR;
    vlSelfRef.tb__DOT__dut__DOT__PWDATA = vlSelfRef.tb__DOT__PWDATA;
    vlSelfRef.tb__DOT__PREADY = vlSelfRef.tb__DOT__dut__DOT__PREADY;
    vlSelfRef.tb__DOT__PSLVERR = vlSelfRef.tb__DOT__dut__DOT__PSLVERR;
    vlSelfRef.tb__DOT__dut__DOT__PSEL = vlSelfRef.tb__DOT__PSEL;
    vlSelfRef.tb__DOT__dut__DOT__PENABLE = vlSelfRef.tb__DOT__PENABLE;
    vlSelfRef.tb__DOT__dut__DOT__PWRITE = vlSelfRef.tb__DOT__PWRITE;
    vlSelfRef.tb__DOT__dut__DOT__PRDATA = 0U;
    if ((((IData)(vlSelfRef.tb__DOT__dut__DOT__PSEL) 
          & (IData)(vlSelfRef.tb__DOT__dut__DOT__PENABLE)) 
         & (~ (IData)(vlSelfRef.tb__DOT__dut__DOT__PWRITE)))) {
        if ((0x00001000U == vlSelfRef.tb__DOT__dut__DOT__addr_latched)) {
            vlSelfRef.tb__DOT__dut__DOT__PRDATA = vlSelfRef.tb__DOT__dut__DOT__regfile
                [0U];
        } else if ((0x00001004U == vlSelfRef.tb__DOT__dut__DOT__addr_latched)) {
            vlSelfRef.tb__DOT__dut__DOT__PRDATA = vlSelfRef.tb__DOT__dut__DOT__regfile
                [1U];
        } else if ((0x00001008U == vlSelfRef.tb__DOT__dut__DOT__addr_latched)) {
            vlSelfRef.tb__DOT__dut__DOT__PRDATA = vlSelfRef.tb__DOT__dut__DOT__regfile
                [2U];
        } else if ((0x0000100cU == vlSelfRef.tb__DOT__dut__DOT__addr_latched)) {
            vlSelfRef.tb__DOT__dut__DOT__PRDATA = vlSelfRef.tb__DOT__dut__DOT__regfile
                [3U];
        }
    }
    vlSelfRef.tb__DOT__PRDATA = vlSelfRef.tb__DOT__dut__DOT__PRDATA;
}

void Vtop___024root___eval_ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered[0U])) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
    }
}

bool Vtop___024root___eval_phase__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VicoExecute;
    // Body
    Vtop___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = Vtop___024root___trigger_anySet__ico(vlSelfRef.__VicoTriggered);
    if (__VicoExecute) {
        Vtop___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    ((vlSelfRef.__VdlySched.awaitingCurrentTime() 
                                                      << 2U) 
                                                     | ((((~ (IData)(vlSelfRef.tb__DOT__dut__DOT__PRESETn)) 
                                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__PRESETn__0)) 
                                                         << 1U) 
                                                        | ((IData)(vlSelfRef.tb__DOT__dut__DOT__PCLK) 
                                                           & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__PCLK__0)))))));
    vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__PCLK__0 
        = vlSelfRef.tb__DOT__dut__DOT__PCLK;
    vlSelfRef.__Vtrigprevexpr___TOP__tb__DOT__dut__DOT__PRESETn__0 
        = vlSelfRef.tb__DOT__dut__DOT__PRESETn;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
}

bool Vtop___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__act\n"); );
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

void Vtop___024root___act_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___act_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__dut__DOT__PCLK = vlSelfRef.tb__DOT__PCLK;
}

void Vtop___024root___eval_act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((4ULL & vlSelfRef.__VactTriggered[0U])) {
        Vtop___024root___act_sequent__TOP__0(vlSelf);
    }
}

void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VdlyVal__tb__DOT__dut__DOT__regfile__v0;
    __VdlyVal__tb__DOT__dut__DOT__regfile__v0 = 0;
    CData/*0:0*/ __VdlySet__tb__DOT__dut__DOT__regfile__v0;
    __VdlySet__tb__DOT__dut__DOT__regfile__v0 = 0;
    IData/*31:0*/ __VdlyVal__tb__DOT__dut__DOT__regfile__v1;
    __VdlyVal__tb__DOT__dut__DOT__regfile__v1 = 0;
    CData/*0:0*/ __VdlySet__tb__DOT__dut__DOT__regfile__v1;
    __VdlySet__tb__DOT__dut__DOT__regfile__v1 = 0;
    IData/*31:0*/ __VdlyVal__tb__DOT__dut__DOT__regfile__v2;
    __VdlyVal__tb__DOT__dut__DOT__regfile__v2 = 0;
    CData/*0:0*/ __VdlySet__tb__DOT__dut__DOT__regfile__v2;
    __VdlySet__tb__DOT__dut__DOT__regfile__v2 = 0;
    IData/*31:0*/ __VdlyVal__tb__DOT__dut__DOT__regfile__v3;
    __VdlyVal__tb__DOT__dut__DOT__regfile__v3 = 0;
    CData/*0:0*/ __VdlySet__tb__DOT__dut__DOT__regfile__v3;
    __VdlySet__tb__DOT__dut__DOT__regfile__v3 = 0;
    CData/*0:0*/ __VdlySet__tb__DOT__dut__DOT__regfile__v4;
    __VdlySet__tb__DOT__dut__DOT__regfile__v4 = 0;
    // Body
    __VdlySet__tb__DOT__dut__DOT__regfile__v0 = 0U;
    __VdlySet__tb__DOT__dut__DOT__regfile__v1 = 0U;
    __VdlySet__tb__DOT__dut__DOT__regfile__v2 = 0U;
    __VdlySet__tb__DOT__dut__DOT__regfile__v3 = 0U;
    __VdlySet__tb__DOT__dut__DOT__regfile__v4 = 0U;
    if (vlSelfRef.tb__DOT__dut__DOT__PRESETn) {
        if ((((IData)(vlSelfRef.tb__DOT__dut__DOT__PSEL) 
              & (IData)(vlSelfRef.tb__DOT__dut__DOT__PENABLE)) 
             & (IData)(vlSelfRef.tb__DOT__dut__DOT__PWRITE))) {
            if ((0x00001000U == vlSelfRef.tb__DOT__dut__DOT__addr_latched)) {
                __VdlyVal__tb__DOT__dut__DOT__regfile__v0 
                    = vlSelfRef.tb__DOT__dut__DOT__PWDATA;
                __VdlySet__tb__DOT__dut__DOT__regfile__v0 = 1U;
            } else if ((0x00001004U == vlSelfRef.tb__DOT__dut__DOT__addr_latched)) {
                __VdlyVal__tb__DOT__dut__DOT__regfile__v1 
                    = vlSelfRef.tb__DOT__dut__DOT__PWDATA;
                __VdlySet__tb__DOT__dut__DOT__regfile__v1 = 1U;
            } else if ((0x00001008U == vlSelfRef.tb__DOT__dut__DOT__addr_latched)) {
                __VdlyVal__tb__DOT__dut__DOT__regfile__v2 
                    = vlSelfRef.tb__DOT__dut__DOT__PWDATA;
                __VdlySet__tb__DOT__dut__DOT__regfile__v2 = 1U;
            } else if ((0x0000100cU == vlSelfRef.tb__DOT__dut__DOT__addr_latched)) {
                __VdlyVal__tb__DOT__dut__DOT__regfile__v3 
                    = vlSelfRef.tb__DOT__dut__DOT__PWDATA;
                __VdlySet__tb__DOT__dut__DOT__regfile__v3 = 1U;
            }
        }
        if (((IData)(vlSelfRef.tb__DOT__dut__DOT__PSEL) 
             & (~ (IData)(vlSelfRef.tb__DOT__dut__DOT__PENABLE)))) {
            vlSelfRef.tb__DOT__dut__DOT__addr_latched 
                = vlSelfRef.tb__DOT__dut__DOT__PADDR;
        }
    } else {
        __VdlySet__tb__DOT__dut__DOT__regfile__v4 = 1U;
        vlSelfRef.tb__DOT__dut__DOT__addr_latched = 0U;
    }
    if (__VdlySet__tb__DOT__dut__DOT__regfile__v0) {
        vlSelfRef.tb__DOT__dut__DOT__regfile[0U] = __VdlyVal__tb__DOT__dut__DOT__regfile__v0;
    }
    if (__VdlySet__tb__DOT__dut__DOT__regfile__v1) {
        vlSelfRef.tb__DOT__dut__DOT__regfile[1U] = __VdlyVal__tb__DOT__dut__DOT__regfile__v1;
    }
    if (__VdlySet__tb__DOT__dut__DOT__regfile__v2) {
        vlSelfRef.tb__DOT__dut__DOT__regfile[2U] = __VdlyVal__tb__DOT__dut__DOT__regfile__v2;
    }
    if (__VdlySet__tb__DOT__dut__DOT__regfile__v3) {
        vlSelfRef.tb__DOT__dut__DOT__regfile[3U] = __VdlyVal__tb__DOT__dut__DOT__regfile__v3;
    }
    if (__VdlySet__tb__DOT__dut__DOT__regfile__v4) {
        vlSelfRef.tb__DOT__dut__DOT__regfile[0U] = 0U;
        vlSelfRef.tb__DOT__dut__DOT__regfile[1U] = 0U;
        vlSelfRef.tb__DOT__dut__DOT__regfile[2U] = 0U;
        vlSelfRef.tb__DOT__dut__DOT__regfile[3U] = 0U;
    }
    vlSelfRef.tb__DOT__dut__DOT__PRDATA = 0U;
    if ((((IData)(vlSelfRef.tb__DOT__dut__DOT__PSEL) 
          & (IData)(vlSelfRef.tb__DOT__dut__DOT__PENABLE)) 
         & (~ (IData)(vlSelfRef.tb__DOT__dut__DOT__PWRITE)))) {
        if ((0x00001000U == vlSelfRef.tb__DOT__dut__DOT__addr_latched)) {
            vlSelfRef.tb__DOT__dut__DOT__PRDATA = vlSelfRef.tb__DOT__dut__DOT__regfile
                [0U];
        } else if ((0x00001004U == vlSelfRef.tb__DOT__dut__DOT__addr_latched)) {
            vlSelfRef.tb__DOT__dut__DOT__PRDATA = vlSelfRef.tb__DOT__dut__DOT__regfile
                [1U];
        } else if ((0x00001008U == vlSelfRef.tb__DOT__dut__DOT__addr_latched)) {
            vlSelfRef.tb__DOT__dut__DOT__PRDATA = vlSelfRef.tb__DOT__dut__DOT__regfile
                [2U];
        } else if ((0x0000100cU == vlSelfRef.tb__DOT__dut__DOT__addr_latched)) {
            vlSelfRef.tb__DOT__dut__DOT__PRDATA = vlSelfRef.tb__DOT__dut__DOT__regfile
                [3U];
        }
    }
    vlSelfRef.tb__DOT__PRDATA = vlSelfRef.tb__DOT__dut__DOT__PRDATA;
}

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vtop___024root___timing_resume(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___timing_resume\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((4ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vtop___024root___trigger_orInto__act(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_orInto__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vtop___024root___eval_phase__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VactExecute;
    // Body
    Vtop___024root___eval_triggers__act(vlSelf);
    Vtop___024root___trigger_orInto__act(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    __VactExecute = Vtop___024root___trigger_anySet__act(vlSelfRef.__VactTriggered);
    if (__VactExecute) {
        Vtop___024root___timing_resume(vlSelf);
        Vtop___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

void Vtop___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vtop___024root___eval_phase__nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vtop___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vtop___024root___eval_nba(vlSelf);
        Vtop___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            Vtop___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
            VL_FATAL_MT("/home/thilagan/apb_dv/tb.sv", 1, "", "Input combinational region did not converge after 100 tries");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
    } while (Vtop___024root___eval_phase__ico(vlSelf));
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("/home/thilagan/apb_dv/tb.sv", 1, "", "NBA region did not converge after 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("/home/thilagan/apb_dv/tb.sv", 1, "", "Active region did not converge after 100 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
        } while (Vtop___024root___eval_phase__act(vlSelf));
    } while (Vtop___024root___eval_phase__nba(vlSelf));
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
