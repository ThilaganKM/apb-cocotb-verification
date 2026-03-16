# APB Slave — Functional Verification (cocotb + Verilator)

> Python-based functional verification of an APB slave with configurable wait states, PSLVERR error signaling, and coverage-driven test development using cocotb and Verilator.

**Tools:** Verilator 5.x · cocotb 2.0.1 · Python 3.12 · SystemVerilog (RTL + SVA)  
**Author:** Appalla Subrahmanya Karthikeya

---

## DUT — APB Slave

### Features

- 4 memory-mapped 32-bit registers
- Configurable random wait states (1–5 cycles per transaction)
- PSLVERR generation for invalid address accesses
- 10+ embedded SVA protocol assertions

### Register Map

| Address | Register |
|---------|----------|
| `0x1000` | REG0 |
| `0x1004` | REG1 |
| `0x1008` | REG2 |
| `0x100C` | REG3 |

Any address outside this range triggers `PSLVERR=1`.

### APB Transfer — Timing

```
         SETUP phase          ACCESS phase
         ───────────          ──────────────────────────────
PCLK  :  _____|‾‾‾‾‾|_______|‾‾‾‾‾|_______|‾‾‾‾‾|_______
PSEL  :  _______|‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾|________
PENABLE:  ______________|‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾|________
PREADY :  ____________________________|‾‾‾‾‾|____________
          ← 1 setup cycle →← N wait cycles →← done →
```

Wait states are generated using `$urandom % 6` — producing 1 to 5 cycles per transaction. The peripheral stalls by holding `PREADY=0` until `wait_cnt == wait_target`.

---

## Verification Architecture

```
┌─────────────────────────────────────────────┐
│              test_apb.py                    │
│                                             │
│  ┌─────────────────────────────────────┐    │
│  │           APBMaster                 │    │
│  │  - write(addr, data)               │    │
│  │  - read(addr) → data               │    │
│  │  - cleanup() between transactions  │    │
│  │  - records wait cycles per txn     │    │
│  └──────────────────┬──────────────────┘    │
│                     │                       │
│  ┌──────────────────▼──────────────────┐    │
│  │           APBCoverage               │    │
│  │  - wait_state_bins {1:0..5:0}      │    │
│  │  - transaction_types {R:0, W:0}    │    │
│  │  - addresses_seen (set)            │    │
│  │  - pslverr_count                   │    │
│  │  - record_transaction()            │    │
│  │  - get_coverage_report()           │    │
│  │  - is_full_coverage()              │    │
│  └─────────────────────────────────────┘    │
└─────────────────────────────────────────────┘
           │ cocotb virtual signals
           ▼
┌─────────────────────────────────────────────┐
│              apb_slave.sv (DUT)             │
│  + embedded SVA assertions                  │
└─────────────────────────────────────────────┘
```

### APBMaster Driver

The `APBMaster` class implements the APB master protocol in Python:

```python
async def write(self, addr, data):
    # SETUP phase
    dut.PSEL.value = 1; dut.PENABLE.value = 0
    dut.PWRITE.value = 1; dut.PADDR.value = addr
    await RisingEdge(dut.PCLK)
    # ACCESS phase
    dut.PENABLE.value = 1
    while dut.PREADY.value == 0:   # wait for PREADY
        wait_cycles += 1
        await RisingEdge(dut.PCLK)
    # record coverage, cleanup
```

Every transaction automatically records wait cycles, transaction type, address, and PSLVERR status into the coverage model.

---

## SVA Assertions (in RTL)

10+ protocol and design assertions embedded directly in `apb_slave.sv`:

| Assertion | Property |
|-----------|----------|
| `assert_pready_only_in_access` | PREADY can only be high when `PSEL && PENABLE` |
| `assert_penable_requires_psel` | PENABLE must not assert without PSEL |
| `assert_psel_stable_during_access` | PSEL must not change mid-transfer |
| `assert_pwrite_stable_during_transfer` | PWRITE must be stable through ACCESS phase |
| `assert_xfer_active_implies_psel` | Internal `xfer_active` flag requires PSEL |
| `assert_wait_target_range` | `wait_target` must not exceed MAX_WAIT_CYCLES |
| `assert_pready_one_cycle_pulse` | PREADY must deassert the cycle after it asserts |
| `assert_pslverr_only_on_completion` | PSLVERR only rises after transfer completion |
| `assert_pslverr_for_invalid_addr` | Invalid addresses must generate PSLVERR |

---

## Test Suite

| Test | Description | Transactions |
|------|-------------|-------------|
| `apb_coverage_test` | Main coverage-driven test — writes all registers with corner-case data patterns, reads back, verifies data integrity, checks all wait states covered | 48 |
| `apb_quick_test` | Smoke test for regression — 2 writes + 2 reads, fast pass/fail | 4 |
| `apb_pslverr_test` | PSLVERR validation — valid and invalid address accesses, verifies error signaling and clearing | 5 |
| `apb_debug_wait_cycles` | Wait cycle distribution analysis across 100 transactions | 100 |
| `apb_check_rng` | RNG range verification — confirms $urandom generates 1–5 cycles as designed | 50 |

### Data Corner Cases Tested

```python
test_patterns = [
    (0x1000, 0xDEADBEEF),   # Walking pattern
    (0x1004, 0xCAFEBABE),
    (0x1008, 0xF00DF00D),
    (0x100C, 0xBAADF00D),
    (0x1000, 0x55555555),   # Alternating 0101
    (0x1004, 0xAAAAAAAA),   # Alternating 1010
    (0x1008, 0xFFFFFFFF),   # All ones
    (0x100C, 0x00000000),   # All zeros
    ...
]
```

---

## Coverage Results

| Coverage Bin | Target | Result |
|-------------|--------|--------|
| Wait state = 1 cycle | Hit | ✓ |
| Wait state = 2 cycles | Hit | ✓ |
| Wait state = 3 cycles | Hit | ✓ |
| Wait state = 4 cycles | Hit | ✓ |
| Wait state = 5 cycles | Hit | ✓ |
| Write transactions | Hit | ✓ |
| Read transactions | Hit | ✓ |
| Address 0x1000 | Hit | ✓ |
| Address 0x1004 | Hit | ✓ |
| Address 0x1008 | Hit | ✓ |
| Address 0x100C | Hit | ✓ |
| PSLVERR path | Hit | ✓ |
| **Total functional coverage** | | **100%** |

---

## Regression Results

```
TESTS=5  PASS=5  FAIL=0

UVM_ERROR  : 0
Assertion failures : 0
Coverage   : 100%
```

---

## Key Debugging Notes

| Issue | Root Cause | Fix |
|-------|-----------|-----|
| PSLVERR timing mismatch | Sampled `PSLVERR` level instead of edge | Used `$rose()` and internal `xfer_done_next` signal |
| PWRITE assertion false failure | Assertion not qualified with ACCESS phase | Added `PENABLE` qualifier to property |
| Wait cycle off-by-one | Not accounting for ACCESS cycle in count | Updated test to include ACCESS cycle in wait count |
| Signal contamination between tests | `PWRITE`/`PADDR` not cleared between transactions | Added `cleanup()` method to APBMaster |

---

## How to Run

### Prerequisites

```bash
python3 -m venv dv_env
source dv_env/bin/activate
pip install cocotb

# Verilator (Ubuntu)
sudo apt-get install verilator
```

### Commands

```bash
# Run all tests
make

# Run specific test
make COCOTB_TESTCASE=apb_coverage_test
make COCOTB_TESTCASE=apb_quick_test
make COCOTB_TESTCASE=apb_pslverr_test
make COCOTB_TESTCASE=apb_debug_wait_cycles
make COCOTB_TESTCASE=apb_check_rng

# Clean
make clean
```

---

## Why cocotb + Verilator

This project deliberately uses a different verification stack from the UVM-based projects to demonstrate tool versatility:

- **cocotb** allows verification logic in Python — faster test development, easier data processing, access to Python libraries for analysis
- **Verilator** compiles SystemVerilog to C++ for fast simulation — ideal for coverage-driven testing with many transactions
- **SVA in RTL** — assertions embedded in the DUT itself catch protocol violations regardless of which testbench is used

This combination mirrors the open-source and startup DV stack, complementing the QuestaSim + UVM experience from the RISC-V and AHB-APB projects.
