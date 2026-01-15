import cocotb
from cocotb.triggers import RisingEdge, Timer

class APBMaster:
    def __init__(self, dut):
        self.dut = dut

    async def write(self, addr, data):

        # SETUP phase (drive BEFORE edge)
        self.dut.PSEL.value    = 1
        self.dut.PENABLE.value = 0
        self.dut.PWRITE.value  = 1
        self.dut.PADDR.value   = addr
        self.dut.PWDATA.value  = data

        await RisingEdge(self.dut.PCLK)   # slave sees SETUP here

        # ACCESS phase
        self.dut.PENABLE.value = 1
        await RisingEdge(self.dut.PCLK)   # slave performs write here

        # Wait for ready (for future wait states)
        while self.dut.PREADY.value == 0:
            await RisingEdge(self.dut.PCLK)

        # End transfer
        self.dut.PSEL.value    = 0
        self.dut.PENABLE.value = 0
        self.dut.PWRITE.value  = 0




    async def read(self, addr):

        # SETUP
        self.dut.PSEL.value    = 1
        self.dut.PENABLE.value = 0
        self.dut.PWRITE.value  = 0
        self.dut.PADDR.value   = addr

        await RisingEdge(self.dut.PCLK)   # address latched

        # ACCESS
        self.dut.PENABLE.value = 1
        await RisingEdge(self.dut.PCLK)   # data valid here

        while self.dut.PREADY.value == 0:
            await RisingEdge(self.dut.PCLK)

        data = int(self.dut.PRDATA.value)

        self.dut.PSEL.value    = 0
        self.dut.PENABLE.value = 0

        return data



@cocotb.test()
async def apb_basic_test(dut):

    apb = APBMaster(dut)

    dut.PRESETn.value = 0
    await Timer(20, units="ns")
    dut.PRESETn.value = 1
    await RisingEdge(dut.PCLK) 
        # Initialize APB signals (VERY IMPORTANT)
    dut.PSEL.value    = 0
    dut.PENABLE.value = 0
    dut.PWRITE.value  = 0
    dut.PADDR.value   = 0
    dut.PWDATA.value  = 0


    await apb.write(0x1000, 0xA5)
    await apb.write(0x1004, 0x55)

    r0 = await apb.read(0x1000)
    r1 = await apb.read(0x1004)

    dut._log.info(f"REG0 = {hex(r0)}")
    dut._log.info(f"REG1 = {hex(r1)}")

    assert r0 == 0xA5
    assert r1 == 0x55
