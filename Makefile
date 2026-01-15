SIM ?= verilator
TOPLEVEL = tb
MODULE = test_apb

VERILOG_SOURCES = \
	$(PWD)/apb_slave.sv \
	$(PWD)/tb.sv

# Pass timing explicitly to Verilator
EXTRA_ARGS += --sv --trace --timing

include $(shell cocotb-config --makefiles)/Makefile.sim
