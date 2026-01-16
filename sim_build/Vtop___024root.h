// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ tb__DOT__PCLK;
    CData/*0:0*/ tb__DOT__PRESETn;
    CData/*0:0*/ tb__DOT__PSEL;
    CData/*0:0*/ tb__DOT__PENABLE;
    CData/*0:0*/ tb__DOT__PWRITE;
    CData/*0:0*/ tb__DOT__PREADY;
    CData/*0:0*/ tb__DOT__PSLVERR;
    CData/*0:0*/ tb__DOT__dut__DOT__PCLK;
    CData/*0:0*/ tb__DOT__dut__DOT__PRESETn;
    CData/*0:0*/ tb__DOT__dut__DOT__PSEL;
    CData/*0:0*/ tb__DOT__dut__DOT__PENABLE;
    CData/*0:0*/ tb__DOT__dut__DOT__PWRITE;
    CData/*0:0*/ tb__DOT__dut__DOT__PREADY;
    CData/*0:0*/ tb__DOT__dut__DOT__PSLVERR;
    CData/*2:0*/ tb__DOT__dut__DOT__wait_cnt;
    CData/*2:0*/ tb__DOT__dut__DOT__wait_target;
    CData/*0:0*/ tb__DOT__dut__DOT__xfer_done_next;
    CData/*0:0*/ tb__DOT__dut__DOT__xfer_active;
    CData/*0:0*/ tb__DOT__dut__DOT__pslverr_next;
    CData/*0:0*/ tb__DOT__dut__DOT___Vpast_5_1;
    CData/*0:0*/ tb__DOT__dut__DOT___Vpast_7_1;
    CData/*0:0*/ tb__DOT__dut__DOT___Vpast_11_1;
    CData/*0:0*/ tb__DOT__dut__DOT___Vpast_13_1;
    CData/*0:0*/ tb__DOT__dut__DOT___Vpast_14_1;
    CData/*0:0*/ tb__DOT__dut__DOT___Vpast_16_1;
    CData/*0:0*/ __Vsampled_TOP__tb__DOT__dut__DOT__PRESETn;
    CData/*0:0*/ __Vsampled_TOP__tb__DOT__dut__DOT__PREADY;
    CData/*0:0*/ __Vsampled_TOP__tb__DOT__dut__DOT__PSEL;
    CData/*0:0*/ __Vsampled_TOP__tb__DOT__dut__DOT__PENABLE;
    CData/*0:0*/ __Vsampled_TOP__tb__DOT__dut__DOT__xfer_done_next;
    CData/*0:0*/ __Vsampled_TOP__tb__DOT__dut__DOT__PWRITE;
    CData/*0:0*/ __Vsampled_TOP__tb__DOT__dut__DOT___Vpast_5_1;
    CData/*0:0*/ __Vsampled_TOP__tb__DOT__dut__DOT___Vpast_7_1;
    CData/*0:0*/ __Vsampled_TOP__tb__DOT__dut__DOT__xfer_active;
    CData/*2:0*/ __Vsampled_TOP__tb__DOT__dut__DOT__wait_target;
    CData/*0:0*/ __Vsampled_TOP__tb__DOT__dut__DOT___Vpast_11_1;
    CData/*0:0*/ __Vsampled_TOP__tb__DOT__dut__DOT___Vpast_13_1;
    CData/*0:0*/ __Vsampled_TOP__tb__DOT__dut__DOT__PSLVERR;
    CData/*0:0*/ __Vsampled_TOP__tb__DOT__dut__DOT___Vpast_14_1;
    CData/*0:0*/ __Vsampled_TOP__tb__DOT__dut__DOT___Vpast_16_1;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb__DOT__dut__DOT__PCLK__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb__DOT__dut__DOT__PRESETn__0;
    IData/*31:0*/ tb__DOT__PADDR;
    IData/*31:0*/ tb__DOT__PWDATA;
    IData/*31:0*/ tb__DOT__PRDATA;
    IData/*31:0*/ tb__DOT__dut__DOT__PADDR;
    IData/*31:0*/ tb__DOT__dut__DOT__PWDATA;
    IData/*31:0*/ tb__DOT__dut__DOT__PRDATA;
    IData/*31:0*/ tb__DOT__dut__DOT__addr_latched;
    IData/*31:0*/ tb__DOT__dut__DOT__unnamedblk1__DOT__rand_val;
    IData/*31:0*/ __Vsampled_TOP__tb__DOT__dut__DOT__addr_latched;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<IData/*31:0*/, 4> tb__DOT__dut__DOT__regfile;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VicoTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    VlDelayScheduler __VdlySched;

    // INTERNAL VARIABLES
    Vtop__Syms* vlSymsp;
    const char* vlNamep;

    // PARAMETERS
    static constexpr IData/*31:0*/ tb__DOT__dut__DOT__MAX_WAIT_CYCLES = 5U;
    static constexpr IData/*31:0*/ tb__DOT__dut__DOT__WAIT_CNT_W = 3U;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* namep);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
