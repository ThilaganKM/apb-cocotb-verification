module apb_slave (
    input  logic        PCLK,
    input  logic        PRESETn,
    input  logic        PSEL,
    input  logic        PENABLE,
    input  logic        PWRITE,
    input  logic [31:0] PADDR,
    input  logic [31:0] PWDATA,
    output logic [31:0] PRDATA,
    output logic        PREADY,
    output logic        PSLVERR
);

    // 4 memory mapped registers
    logic [31:0] regfile [0:3];

    // internal
    logic [31:0] addr_latched;

    //---------------------------------
    // Always ready (no wait states for now)
    //---------------------------------
    assign PREADY  = 1'b1;
    assign PSLVERR = 1'b0;

    //---------------------------------
    // Latch address in SETUP phase
    //---------------------------------
    always_ff @(posedge PCLK or negedge PRESETn) begin
        if (!PRESETn)
            addr_latched <= 32'b0;
        else if (PSEL && !PENABLE)
            addr_latched <= PADDR;
    end

    //---------------------------------
    // Write operation
    //---------------------------------
    always_ff @(posedge PCLK or negedge PRESETn) begin
        if (!PRESETn) begin
            regfile[0] <= 32'b0;
            regfile[1] <= 32'b0;
            regfile[2] <= 32'b0;
            regfile[3] <= 32'b0;
        end
        else if (PSEL && PENABLE && PWRITE) begin
            case (addr_latched)
                32'h1000: regfile[0] <= PWDATA;
                32'h1004: regfile[1] <= PWDATA;
                32'h1008: regfile[2] <= PWDATA;
                32'h100C: regfile[3] <= PWDATA;
            endcase
        end
    end

    //---------------------------------
    // Read operation
    //---------------------------------
    always_comb begin
        PRDATA = 32'b0;
        if (PSEL && PENABLE && !PWRITE) begin
            case (addr_latched)
                32'h1000: PRDATA = regfile[0];
                32'h1004: PRDATA = regfile[1];
                32'h1008: PRDATA = regfile[2];
                32'h100C: PRDATA = regfile[3];
            endcase
        end
    end

endmodule
