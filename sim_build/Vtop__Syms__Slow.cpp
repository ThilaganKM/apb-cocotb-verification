// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop__pch.h"

Vtop__Syms::Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup top module instance
    , TOP{this, namep}
{
    // Check resources
    Verilated::stackCheck(318);
    // Setup sub module instances
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    // Setup scopes
    __Vscopep_tb = new VerilatedScope{this, "tb", "tb", "tb", -9, VerilatedScope::SCOPE_MODULE};
    __Vscopep_tb__dut = new VerilatedScope{this, "tb.dut", "dut", "apb_slave", -9, VerilatedScope::SCOPE_MODULE};
    // Set up scope hierarchy
    __Vhier.add(0, __Vscopep_tb);
    __Vhier.add(__Vscopep_tb, __Vscopep_tb__dut);
    // Setup export functions - final: 0
    // Setup export functions - final: 1
    // Setup public variables
    __Vscopep_tb->varInsert("PADDR", &(TOP.tb__DOT__PADDR), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_tb->varInsert("PCLK", &(TOP.tb__DOT__PCLK), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_tb->varInsert("PENABLE", &(TOP.tb__DOT__PENABLE), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_tb->varInsert("PRDATA", &(TOP.tb__DOT__PRDATA), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_tb->varInsert("PREADY", &(TOP.tb__DOT__PREADY), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_tb->varInsert("PRESETn", &(TOP.tb__DOT__PRESETn), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_tb->varInsert("PSEL", &(TOP.tb__DOT__PSEL), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_tb->varInsert("PSLVERR", &(TOP.tb__DOT__PSLVERR), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_tb->varInsert("PWDATA", &(TOP.tb__DOT__PWDATA), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_tb->varInsert("PWRITE", &(TOP.tb__DOT__PWRITE), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_tb__dut->varInsert("PADDR", &(TOP.tb__DOT__dut__DOT__PADDR), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_tb__dut->varInsert("PCLK", &(TOP.tb__DOT__dut__DOT__PCLK), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_tb__dut->varInsert("PENABLE", &(TOP.tb__DOT__dut__DOT__PENABLE), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_tb__dut->varInsert("PRDATA", &(TOP.tb__DOT__dut__DOT__PRDATA), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_tb__dut->varInsert("PREADY", &(TOP.tb__DOT__dut__DOT__PREADY), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_tb__dut->varInsert("PRESETn", &(TOP.tb__DOT__dut__DOT__PRESETn), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_tb__dut->varInsert("PSEL", &(TOP.tb__DOT__dut__DOT__PSEL), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_tb__dut->varInsert("PSLVERR", &(TOP.tb__DOT__dut__DOT__PSLVERR), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_tb__dut->varInsert("PWDATA", &(TOP.tb__DOT__dut__DOT__PWDATA), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_tb__dut->varInsert("PWRITE", &(TOP.tb__DOT__dut__DOT__PWRITE), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_tb__dut->varInsert("addr_latched", &(TOP.tb__DOT__dut__DOT__addr_latched), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_tb__dut->varInsert("regfile", &(TOP.tb__DOT__dut__DOT__regfile), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 1, 1 ,0,3 ,31,0);
}

Vtop__Syms::~Vtop__Syms() {
    // Tear down scope hierarchy
    __Vhier.remove(0, __Vscopep_tb);
    __Vhier.remove(__Vscopep_tb, __Vscopep_tb__dut);
    // Clear keys from hierarchy map after values have been removed
    __Vhier.clear();
    // Tear down scopes
    VL_DO_CLEAR(delete __Vscopep_tb, __Vscopep_tb = nullptr);
    VL_DO_CLEAR(delete __Vscopep_tb__dut, __Vscopep_tb__dut = nullptr);
    // Tear down sub module instances
}
