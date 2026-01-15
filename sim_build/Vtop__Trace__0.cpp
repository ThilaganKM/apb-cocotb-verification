// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0\n"); );
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vtop___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    bufp->chgBit(oldp+0,(vlSelfRef.tb__DOT__PCLK));
    bufp->chgBit(oldp+1,(vlSelfRef.tb__DOT__PRESETn));
    bufp->chgBit(oldp+2,(vlSelfRef.tb__DOT__PSEL));
    bufp->chgBit(oldp+3,(vlSelfRef.tb__DOT__PENABLE));
    bufp->chgBit(oldp+4,(vlSelfRef.tb__DOT__PWRITE));
    bufp->chgIData(oldp+5,(vlSelfRef.tb__DOT__PADDR),32);
    bufp->chgIData(oldp+6,(vlSelfRef.tb__DOT__PWDATA),32);
    bufp->chgIData(oldp+7,(vlSelfRef.tb__DOT__PRDATA),32);
    bufp->chgBit(oldp+8,(vlSelfRef.tb__DOT__PREADY));
    bufp->chgBit(oldp+9,(vlSelfRef.tb__DOT__PSLVERR));
    bufp->chgBit(oldp+10,(vlSelfRef.tb__DOT__dut__DOT__PCLK));
    bufp->chgBit(oldp+11,(vlSelfRef.tb__DOT__dut__DOT__PRESETn));
    bufp->chgBit(oldp+12,(vlSelfRef.tb__DOT__dut__DOT__PSEL));
    bufp->chgBit(oldp+13,(vlSelfRef.tb__DOT__dut__DOT__PENABLE));
    bufp->chgBit(oldp+14,(vlSelfRef.tb__DOT__dut__DOT__PWRITE));
    bufp->chgIData(oldp+15,(vlSelfRef.tb__DOT__dut__DOT__PADDR),32);
    bufp->chgIData(oldp+16,(vlSelfRef.tb__DOT__dut__DOT__PWDATA),32);
    bufp->chgIData(oldp+17,(vlSelfRef.tb__DOT__dut__DOT__PRDATA),32);
    bufp->chgBit(oldp+18,(vlSelfRef.tb__DOT__dut__DOT__PREADY));
    bufp->chgBit(oldp+19,(vlSelfRef.tb__DOT__dut__DOT__PSLVERR));
    bufp->chgIData(oldp+20,(vlSelfRef.tb__DOT__dut__DOT__regfile[0]),32);
    bufp->chgIData(oldp+21,(vlSelfRef.tb__DOT__dut__DOT__regfile[1]),32);
    bufp->chgIData(oldp+22,(vlSelfRef.tb__DOT__dut__DOT__regfile[2]),32);
    bufp->chgIData(oldp+23,(vlSelfRef.tb__DOT__dut__DOT__regfile[3]),32);
    bufp->chgIData(oldp+24,(vlSelfRef.tb__DOT__dut__DOT__addr_latched),32);
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Locals
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
