# APB Slave Verification Project (cocotb + Verilator)

## 1. Project Overview

This project implements **end-to-end functional verification of an APB (Advanced Peripheral Bus) slave** using **cocotb with Verilator**. The goal is to verify correctness, protocol compliance, robustness under random wait states, and error handling (PSLVERR), while achieving full functional and assertion coverage.

This is a **verification-focused project**, not a toy example, and mirrors real industry DV practices: assertions, coverage closure, stress testing, and regression cleanliness.

---

## 2. Verification Environment

### Tools Used

* **Simulator**: Verilator 5.x
* **Verification Framework**: cocotb (Python)
* **Language**: SystemVerilog (RTL + Assertions), Python (Testbench)

### Directory Structure

```
apb_dv/
├── rtl/
│   └── apb_slave.sv
├── tb/
│   ├── test_apb.py
│   ├── coverage.py
│   └── assertions.sv
├── sim_build/
├── Makefile
└── README.md
```

---

## 3. DUT Description

The DUT is an **APB slave** supporting:

* Read and write transactions
* Configurable random wait states
* Address decoding with valid/invalid address detection
* PSLVERR generation for invalid accesses

### Supported Registers

| Address | Register |
| ------- | -------- |
| 0x1000  | REG0     |
| 0x1004  | REG1     |
| 0x1008  | REG2     |
| 0x100C  | REG3     |

---

## 4. Testbench Architecture

The testbench is written in **cocotb** and consists of:

* APB master driver
* Monitors for transactions and wait cycles
* Reference model for data checking
* Functional coverage collection
* Protocol and design assertions (embedded in RTL)

---

## 5. Test Suite

### Implemented Tests

1. **Basic Functional Test**

   * Directed reads and writes
   * Data integrity check

2. **Coverage Stress Test**

   * Random addresses and data
   * Random wait cycles
   * Coverage closure to 100%

3. **Quick Sanity Test**

   * Lightweight regression-friendly test

4. **PSLVERR Test**

   * Valid vs invalid address accesses
   * PSLVERR assertion and clearing behavior

5. **Debug Wait Cycle Test**

   * Observes real wait cycle distribution
   * Validates stall + ACCESS cycle behavior

6. **RNG Test**

   * Confirms random wait cycle generator range

---

## 6. Assertions Implemented

### Protocol Assertions

* PADDR stable during ACCESS phase
* PWRITE stable during ACCESS phase
* PSLVERR asserted only after transfer completion

### Example Assertion

```systemverilog
property p_pwrite_stable_during_access;
  @(posedge PCLK) disable iff (!PRESETn)
  (PSEL && PENABLE) |-> $stable(PWRITE);
endproperty
```

### Key Debug Learnings

* `$rose()` used for level-based signals like PSLVERR
* Internal handshake signals preferred over raw bus signals
* Proper separation of SETUP vs ACCESS phases

---

## 7. Functional & Assertion Coverage

### Functional Coverage

* Wait state coverage (1–5 cycles)
* Read vs write coverage
* Address coverage
* Error vs non-error paths

### Assertion Coverage

* Successful APB transfer
* PSLVERR assertion path
* Min and max wait cycle completion

Coverage achieved: **100%**

---

## 8. Known Issues & Fixes (Learning Highlights)

| Issue                          | Resolution                                            |
| ------------------------------ | ----------------------------------------------------- |
| PSLVERR timing mismatch        | Fixed using `$rose()` and internal completion signals |
| PWRITE assertion false failure | Qualified with PENABLE                                |
| Wait cycle off-by-one          | Test updated to include ACCESS cycle                  |

---

## 9. Regression Status

Final regression result:

```
TESTS=5  PASS=5  FAIL=0
```

All tests and assertions pass cleanly.

---

## 10. Key Takeaways

* Realistic APB verification flow
* Assertion-driven debugging
* Coverage-driven test development
* Industry-aligned DV practices

## 🎯 Quick Project Overview

Implements an APB slave with:
- 4 memory-mapped registers (0x1000-0x100C)
- Configurable wait states (1-5 cycles)
- PSLVERR generation for invalid addresses
- Comprehensive SystemVerilog Assertions (SVA)

## 📊 Verification Strategy

### 1. **Functional Verification**
- Basic read/write operations
- Wait state randomization
- Data integrity checks

### 2. **Protocol Compliance**
- APB timing checks via SVA assertions
- Negative testing for protocol violations
- Reset recovery testing

### 3. **Coverage-Driven Verification**
- Wait state coverage (1-5 cycles)
- Transaction type coverage (read/write)
- Address space coverage
- Error condition coverage (PSLVERR)

### 4. **Assertion-Based Verification**
- 10+ SVA assertions for APB protocol compliance
- Design integrity assertions
- Error condition assertions

### Supported Operations
- **Write**: PSEL=1, PENABLE=0 → PENABLE=1 → wait N cycles → PREADY=1
- **Read**: Same as write, PRDATA valid when PREADY=1
- **Wait States**: Random 1-5 cycles per transaction
- **Error Handling**: PSLVERR=1 for invalid addresses

## 🛠️ Tools Used

- **RTL Simulator**: Verilator 5.044
- **Verification Framework**: cocotb 2.0.1
- **Language**: SystemVerilog (RTL), Python 3.12 (Tests)
- **Assertions**: SystemVerilog Assertions (SVA)

## 🚀 Getting Started

### Prerequisites
```bash
# Install Python virtual environment
python3 -m venv dv_env
source dv_env/bin/activate
pip install cocotb cocotb-test

# Install Verilator
# Ubuntu: sudo apt-get install verilator
# Or build from source: https://verilator.org/guide/latest/install.html
Run Tests
bash
# Run all tests
make

# Run specific test
make COCOTB_TESTCASE=apb_coverage_test

# Clean build
make clean
Test Results
Tests generate:

Console output with coverage reports

Waveforms (if tracing enabled)

Results.xml (JUnit format)

📈 Coverage Metrics
Coverage tracked:

Wait States: 1, 2, 3, 4, 5 cycles

Transaction Types: Read, Write

Addresses: 0x1000, 0x1004, 0x1008, 0x100C

Error Conditions: PSLVERR assertion

Target: 100% functional coverage

⚠️ Assertions Implemented
Protocol Assertions
PREADY only during ACCESS phase (PSEL=1, PENABLE=1)

Address stable during ACCESS phase

PENABLE requires PSEL

Write/Read only on transfer completion

PSEL stable during ACCESS phase

PWRITE stable during transfer

Design Assertions
xfer_active implies PSEL

wait_target within range (1-5)

PREADY one-cycle pulse

PSLVERR only with PREADY

PSLVERR for invalid addresses

🧪 Test Suite
Functional Tests
apb_coverage_test: Main coverage-driven test

apb_quick_test: Smoke/regression test

apb_debug_wait_cycles: Wait cycle distribution analysis

Negative Tests
Protocol violation tests

Reset during transfer

Invalid address access

Signal stability violations

Error Tests
apb_pslverr_test: PSLVERR generation and validation

📝 Key Learnings
APB Protocol Timing: Proper SETUP/ACCESS phase handling

Registered Handshakes: PREADY timing alignment with data

Coverage-Driven Verification: Tracking all wait states and scenarios

Assertion-Based Verification: Catching protocol violations early

Negative Testing: Testing error conditions and recovery

🔮 Future Enhancements
Performance Metrics: Throughput and latency analysis

Power-Aware Testing: Clock gating scenarios

Formal Verification: Property checking with SymbiYosys

UVM Integration: Convert to UVM testbench

CI/CD Pipeline: Automated regression with GitHub Actions

📚 References
AMBA APB Protocol Specification

cocotb Documentation

Verilator Documentation

SystemVerilog Assertions Tutorial

👤 Author
Your Name
DV Engineer
LinkedIn | GitHub

📄 License
MIT License - See LICENSE file for details

text

Also create a `Makefile` update:

```makefile
# Add to your existing Makefile
test-all: test-functional test-negative test-pslverr

test-functional:
	$(MAKE) COCOTB_TEST_MODULES=test_apb

test-negative:
	$(MAKE) COCOTB_TEST_MODULES=test_apb_negative

test-pslverr:
	$(MAKE) COCOTB_TEST_MODULES=test_apb COCOTB_TESTCASE=apb_pslverr_test

wave:
	gtkwave apb_wave.vcd &

clean-all:
	rm -rf sim_build results.xml apb_wave.vcd *.log

---

**Author**: Thilagan KM
