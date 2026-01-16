`timescale 1ns/1ps

module tb;
    logic PCLK;
    logic PRESETn;
    logic PSEL;
    logic PENABLE;
    logic PWRITE;
    logic [31:0] PADDR;
    logic [31:0] PWDATA;
    logic [31:0] PRDATA;
    logic PREADY;
    logic PSLVERR;

    // Clock generation
    initial begin
        PCLK = 0;
        forever #5 PCLK = ~PCLK;  // 10ns period = 100MHz
    end

    // Instantiate DUT
    apb_slave dut (
        .PCLK(PCLK),
        .PRESETn(PRESETn),
        .PSEL(PSEL),
        .PENABLE(PENABLE),
        .PWRITE(PWRITE),
        .PADDR(PADDR),
        .PWDATA(PWDATA),
        .PRDATA(PRDATA),
        .PREADY(PREADY),
        .PSLVERR(PSLVERR)
    );

    // VCD dump for debugging
    initial begin
        $dumpfile("apb_wave.vcd");
        $dumpvars(0, tb);
    end

    // Monitor for assertions (prints when assertions fire)
    initial begin
        $display("[TB] Starting APB slave testbench");
    end

    // End simulation after timeout
    initial begin
        #1000000;  // 1ms timeout
        $display("[TB] Simulation timeout");
        $finish;
    end
endmodule