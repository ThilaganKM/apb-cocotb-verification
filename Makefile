SIM ?= verilator
TOPLEVEL = tb
MODULE = test_apb

VERILOG_SOURCES = \
	$(PWD)/apb_slave.sv \
	$(PWD)/tb.sv

# Pass timing explicitly to Verilator
EXTRA_ARGS += --sv --trace --timing

include $(shell cocotb-config --makefiles)/Makefile.sim

# ===========================================
# Custom Test Targets (ADD THESE AT THE END)
# ===========================================

# Run specific tests
test-coverage:
	$(MAKE) COCOTB_TEST_MODULES=test_apb COCOTB_TESTCASE=apb_coverage_test

test-quick:
	$(MAKE) COCOTB_TEST_MODULES=test_apb COCOTB_TESTCASE=apb_quick_test

test-pslverr:
	$(MAKE) COCOTB_TEST_MODULES=test_apb COCOTB_TESTCASE=apb_pslverr_test

test-debug:
	$(MAKE) COCOTB_TEST_MODULES=test_apb COCOTB_TESTCASE=apb_debug_wait_cycles

test-rng:
	$(MAKE) COCOTB_TEST_MODULES=test_apb COCOTB_TESTCASE=apb_check_rng

# Run all tests
test-all: test-coverage test-quick test-pslverr test-debug test-rng

# Run with waveform generation
test-wave:
	$(MAKE) EXTRA_ARGS+="--trace --trace-structs"

# Open waveforms
wave:
	gtkwave apb_wave.vcd &

# Clean everything including waveforms
clean-all:
	rm -rf sim_build results.xml apb_wave.vcd *.log *.vcd *.fst

.PHONY: test-coverage test-quick test-pslverr test-debug test-rng test-all test-wave wave clean-all