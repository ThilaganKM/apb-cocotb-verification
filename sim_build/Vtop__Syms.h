// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTOP__SYMS_H_
#define VERILATED_VTOP__SYMS_H_  // guard

#include "verilated.h"
#include "verilated_vcd_c.h"

// INCLUDE MODEL CLASS

#include "Vtop.h"

// INCLUDE MODULE CLASSES
#include "Vtop___024root.h"

// DPI TYPES for DPI Export callbacks (Internal use)

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES) Vtop__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vtop* const __Vm_modelp;
    bool __Vm_dumping = false;  // Dumping is active
    VerilatedMutex __Vm_dumperMutex;  // Protect __Vm_dumperp
    VerilatedVcdC* __Vm_dumperp VL_GUARDED_BY(__Vm_dumperMutex) = nullptr;  /// Trace class for $dump*
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vtop___024root                 TOP;

    // SCOPE NAMES
    VerilatedScope* __Vscopep_tb;
    VerilatedScope* __Vscopep_tb__dut;
    VerilatedScope* __Vscopep_tb__dut__assert_penable_requires_psel;
    VerilatedScope* __Vscopep_tb__dut__assert_pready_one_cycle_pulse;
    VerilatedScope* __Vscopep_tb__dut__assert_pready_only_in_access;
    VerilatedScope* __Vscopep_tb__dut__assert_psel_stable_during_access;
    VerilatedScope* __Vscopep_tb__dut__assert_pslverr_for_invalid_addr;
    VerilatedScope* __Vscopep_tb__dut__assert_pslverr_only_on_completion;
    VerilatedScope* __Vscopep_tb__dut__assert_pwrite_stable_during_transfer;
    VerilatedScope* __Vscopep_tb__dut__assert_read_only_on_completion;
    VerilatedScope* __Vscopep_tb__dut__assert_wait_target_range;
    VerilatedScope* __Vscopep_tb__dut__assert_write_only_on_completion;
    VerilatedScope* __Vscopep_tb__dut__assert_xfer_active_implies_psel;
    VerilatedScope* __Vscopep_tb__dut__unnamedblk1;

    // SCOPE HIERARCHY
    VerilatedHierarchy __Vhier;

    // CONSTRUCTORS
    Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp);
    ~Vtop__Syms();

    // METHODS
    const char* name() const { return TOP.vlNamep; }
    void _traceDump();
    void _traceDumpOpen();
    void _traceDumpClose();
};

#endif  // guard
