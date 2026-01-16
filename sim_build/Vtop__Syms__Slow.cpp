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
    Verilated::stackCheck(322);
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
    __Vscopep_tb__dut__assert_penable_requires_psel = new VerilatedScope{this, "tb.dut.assert_penable_requires_psel", "assert_penable_requires_psel", "<null>", -9, VerilatedScope::SCOPE_OTHER};
    __Vscopep_tb__dut__assert_pready_one_cycle_pulse = new VerilatedScope{this, "tb.dut.assert_pready_one_cycle_pulse", "assert_pready_one_cycle_pulse", "<null>", -9, VerilatedScope::SCOPE_OTHER};
    __Vscopep_tb__dut__assert_pready_only_in_access = new VerilatedScope{this, "tb.dut.assert_pready_only_in_access", "assert_pready_only_in_access", "<null>", -9, VerilatedScope::SCOPE_OTHER};
    __Vscopep_tb__dut__assert_psel_stable_during_access = new VerilatedScope{this, "tb.dut.assert_psel_stable_during_access", "assert_psel_stable_during_access", "<null>", -9, VerilatedScope::SCOPE_OTHER};
    __Vscopep_tb__dut__assert_pslverr_for_invalid_addr = new VerilatedScope{this, "tb.dut.assert_pslverr_for_invalid_addr", "assert_pslverr_for_invalid_addr", "<null>", -9, VerilatedScope::SCOPE_OTHER};
    __Vscopep_tb__dut__assert_pslverr_only_on_completion = new VerilatedScope{this, "tb.dut.assert_pslverr_only_on_completion", "assert_pslverr_only_on_completion", "<null>", -9, VerilatedScope::SCOPE_OTHER};
    __Vscopep_tb__dut__assert_pwrite_stable_during_transfer = new VerilatedScope{this, "tb.dut.assert_pwrite_stable_during_transfer", "assert_pwrite_stable_during_transfer", "<null>", -9, VerilatedScope::SCOPE_OTHER};
    __Vscopep_tb__dut__assert_read_only_on_completion = new VerilatedScope{this, "tb.dut.assert_read_only_on_completion", "assert_read_only_on_completion", "<null>", -9, VerilatedScope::SCOPE_OTHER};
    __Vscopep_tb__dut__assert_wait_target_range = new VerilatedScope{this, "tb.dut.assert_wait_target_range", "assert_wait_target_range", "<null>", -9, VerilatedScope::SCOPE_OTHER};
    __Vscopep_tb__dut__assert_write_only_on_completion = new VerilatedScope{this, "tb.dut.assert_write_only_on_completion", "assert_write_only_on_completion", "<null>", -9, VerilatedScope::SCOPE_OTHER};
    __Vscopep_tb__dut__assert_xfer_active_implies_psel = new VerilatedScope{this, "tb.dut.assert_xfer_active_implies_psel", "assert_xfer_active_implies_psel", "<null>", -9, VerilatedScope::SCOPE_OTHER};
    __Vscopep_tb__dut__unnamedblk1 = new VerilatedScope{this, "tb.dut.unnamedblk1", "unnamedblk1", "<null>", -9, VerilatedScope::SCOPE_OTHER};
    // Set up scope hierarchy
    __Vhier.add(0, __Vscopep_tb);
    __Vhier.add(__Vscopep_tb, __Vscopep_tb__dut);
    __Vhier.add(__Vscopep_tb__dut, __Vscopep_tb__dut__unnamedblk1);
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
    __Vscopep_tb__dut->varInsert("MAX_WAIT_CYCLES", const_cast<void*>(static_cast<const void*>(&(TOP.tb__DOT__dut__DOT__MAX_WAIT_CYCLES))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
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
    __Vscopep_tb__dut->varInsert("WAIT_CNT_W", const_cast<void*>(static_cast<const void*>(&(TOP.tb__DOT__dut__DOT__WAIT_CNT_W))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_tb__dut->varInsert("addr_latched", &(TOP.tb__DOT__dut__DOT__addr_latched), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_tb__dut->varInsert("pslverr_next", &(TOP.tb__DOT__dut__DOT__pslverr_next), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_tb__dut->varInsert("regfile", &(TOP.tb__DOT__dut__DOT__regfile), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 1, 1 ,0,3 ,31,0);
    __Vscopep_tb__dut->varInsert("wait_cnt", &(TOP.tb__DOT__dut__DOT__wait_cnt), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,2,0);
    __Vscopep_tb__dut->varInsert("wait_target", &(TOP.tb__DOT__dut__DOT__wait_target), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,2,0);
    __Vscopep_tb__dut->varInsert("xfer_active", &(TOP.tb__DOT__dut__DOT__xfer_active), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_tb__dut->varInsert("xfer_done_next", &(TOP.tb__DOT__dut__DOT__xfer_done_next), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_tb__dut__unnamedblk1->varInsert("rand_val", &(TOP.tb__DOT__dut__DOT__unnamedblk1__DOT__rand_val), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
}

Vtop__Syms::~Vtop__Syms() {
    // Tear down scope hierarchy
    __Vhier.remove(0, __Vscopep_tb);
    __Vhier.remove(__Vscopep_tb, __Vscopep_tb__dut);
    __Vhier.remove(__Vscopep_tb__dut, __Vscopep_tb__dut__unnamedblk1);
    // Clear keys from hierarchy map after values have been removed
    __Vhier.clear();
    if (__Vm_dumping) _traceDumpClose();
    // Tear down scopes
    VL_DO_CLEAR(delete __Vscopep_tb, __Vscopep_tb = nullptr);
    VL_DO_CLEAR(delete __Vscopep_tb__dut, __Vscopep_tb__dut = nullptr);
    VL_DO_CLEAR(delete __Vscopep_tb__dut__assert_penable_requires_psel, __Vscopep_tb__dut__assert_penable_requires_psel = nullptr);
    VL_DO_CLEAR(delete __Vscopep_tb__dut__assert_pready_one_cycle_pulse, __Vscopep_tb__dut__assert_pready_one_cycle_pulse = nullptr);
    VL_DO_CLEAR(delete __Vscopep_tb__dut__assert_pready_only_in_access, __Vscopep_tb__dut__assert_pready_only_in_access = nullptr);
    VL_DO_CLEAR(delete __Vscopep_tb__dut__assert_psel_stable_during_access, __Vscopep_tb__dut__assert_psel_stable_during_access = nullptr);
    VL_DO_CLEAR(delete __Vscopep_tb__dut__assert_pslverr_for_invalid_addr, __Vscopep_tb__dut__assert_pslverr_for_invalid_addr = nullptr);
    VL_DO_CLEAR(delete __Vscopep_tb__dut__assert_pslverr_only_on_completion, __Vscopep_tb__dut__assert_pslverr_only_on_completion = nullptr);
    VL_DO_CLEAR(delete __Vscopep_tb__dut__assert_pwrite_stable_during_transfer, __Vscopep_tb__dut__assert_pwrite_stable_during_transfer = nullptr);
    VL_DO_CLEAR(delete __Vscopep_tb__dut__assert_read_only_on_completion, __Vscopep_tb__dut__assert_read_only_on_completion = nullptr);
    VL_DO_CLEAR(delete __Vscopep_tb__dut__assert_wait_target_range, __Vscopep_tb__dut__assert_wait_target_range = nullptr);
    VL_DO_CLEAR(delete __Vscopep_tb__dut__assert_write_only_on_completion, __Vscopep_tb__dut__assert_write_only_on_completion = nullptr);
    VL_DO_CLEAR(delete __Vscopep_tb__dut__assert_xfer_active_implies_psel, __Vscopep_tb__dut__assert_xfer_active_implies_psel = nullptr);
    VL_DO_CLEAR(delete __Vscopep_tb__dut__unnamedblk1, __Vscopep_tb__dut__unnamedblk1 = nullptr);
    // Tear down sub module instances
}

void Vtop__Syms::_traceDump() {
    const VerilatedLockGuard lock{__Vm_dumperMutex};
    __Vm_dumperp->dump(VL_TIME_Q());
}

void Vtop__Syms::_traceDumpOpen() {
    const VerilatedLockGuard lock{__Vm_dumperMutex};
    if (VL_UNLIKELY(!__Vm_dumperp)) {
        __Vm_dumperp = new VerilatedVcdC();
        __Vm_modelp->trace(__Vm_dumperp, 0, 0);
        const std::string dumpfile = _vm_contextp__->dumpfileCheck();
        __Vm_dumperp->open(dumpfile.c_str());
        __Vm_dumping = true;
    }
}

void Vtop__Syms::_traceDumpClose() {
    const VerilatedLockGuard lock{__Vm_dumperMutex};
    __Vm_dumping = false;
    VL_DO_CLEAR(delete __Vm_dumperp, __Vm_dumperp = nullptr);
}
