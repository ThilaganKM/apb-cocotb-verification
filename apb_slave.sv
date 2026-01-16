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

    localparam int MAX_WAIT_CYCLES = 5;  // Maximum wait cycles (0-5 inclusive)
    localparam int WAIT_CNT_W  = $clog2(MAX_WAIT_CYCLES + 1);

    logic [WAIT_CNT_W-1:0] wait_cnt;
    logic [WAIT_CNT_W-1:0] wait_target;
    
    logic [31:0] addr_latched;
    logic [31:0] regfile [0:3];
    logic        xfer_done_next;
    logic        xfer_active;
    logic        pslverr_next;


    
    // Detect when transfer will complete NEXT cycle
    assign xfer_done_next = (PSEL && PENABLE && (wait_cnt == wait_target));

    // ===================================================
    // APB PROTOCOL ASSERTIONS
    // ===================================================
    
    // APB Rule: PREADY can only be high during ACCESS phase
    property p_pready_only_in_access;
        @(posedge PCLK) disable iff (!PRESETn)
        PREADY |-> (PSEL && PENABLE);
    endproperty
    assert_pready_only_in_access: assert property (p_pready_only_in_access)
        else $error("[APB-ASSERT] PREADY asserted outside ACCESS phase");
    
    // APB Rule: Address must be stable during ACCESS phase
    property p_paddr_stable_during_access;
        @(posedge PCLK) disable iff (!PRESETn)
        (PSEL && PENABLE) |-> $stable(PADDR);
    endproperty

    // APB Rule: PENABLE must not assert without PSEL
    property p_penable_requires_psel;
        @(posedge PCLK) disable iff (!PRESETn)
        PENABLE |-> PSEL;
    endproperty
    assert_penable_requires_psel: assert property (p_penable_requires_psel)
        else $error("[APB-ASSERT] PENABLE asserted without PSEL");
    
    // APB Rule: Write/Read only on transfer completion
    property p_write_only_on_completion;
        @(posedge PCLK) disable iff (!PRESETn)
        (xfer_done_next && PWRITE) |-> (PSEL && PENABLE);
    endproperty
    assert_write_only_on_completion: assert property (p_write_only_on_completion)
        else $error("[APB-ASSERT] Write attempted without valid transfer");
    
    property p_read_only_on_completion;
        @(posedge PCLK) disable iff (!PRESETn)
        (xfer_done_next && !PWRITE) |-> (PSEL && PENABLE);
    endproperty
    assert_read_only_on_completion: assert property (p_read_only_on_completion)
        else $error("[APB-ASSERT] Read attempted without valid transfer");
    
    // APB Rule: PSEL should not change during ACCESS phase
    property p_psel_stable_during_access;
        @(posedge PCLK) disable iff (!PRESETn)
        (PSEL && PENABLE) |-> $stable(PSEL);
    endproperty
    assert_psel_stable_during_access: assert property (p_psel_stable_during_access)
        else $error("[APB-ASSERT] PSEL changed during ACCESS phase");
    
    // APB Rule: PWRITE should be stable from SETUP phase until transfer ends
    property p_pwrite_stable_during_transfer;
        @(posedge PCLK) disable iff (!PRESETn)
        (PSEL && PENABLE) |-> $stable(PWRITE);
    endproperty

    assert_pwrite_stable_during_transfer:
        assert property (p_pwrite_stable_during_transfer)
        else $error("[APB-ASSERT] PWRITE changed during ACCESS phase");

    
    // Internal Design Assertions
    property p_xfer_active_implies_psel;
        @(posedge PCLK) disable iff (!PRESETn)
        xfer_active |-> PSEL;
    endproperty
    assert_xfer_active_implies_psel: assert property (p_xfer_active_implies_psel)
        else $error("[DESIGN-ASSERT] xfer_active high without PSEL");
    
    property p_wait_target_range;
        @(posedge PCLK) disable iff (!PRESETn)
        (PSEL && !PENABLE) |-> (wait_target <= WAIT_CNT_W'(MAX_WAIT_CYCLES));
    endproperty
    assert_wait_target_range: assert property (p_wait_target_range)
        else $error("[DESIGN-ASSERT] wait_target exceeds MAX_WAIT_CYCLES");
    
    property p_pready_one_cycle_pulse;
        @(posedge PCLK) disable iff (!PRESETn)
        PREADY |=> !PREADY;
    endproperty
    assert_pready_one_cycle_pulse: assert property (p_pready_one_cycle_pulse)
        else $error("[DESIGN-ASSERT] PREADY asserted for more than 1 cycle");
    
    
    
    // ===================================================
    // PREADY and wait counter logic
    // ===================================================
    always_ff @(posedge PCLK or negedge PRESETn) begin
        if (!PRESETn) begin
            wait_cnt    <= '0;
            wait_target <= '0;
            PREADY      <= 1'b0;
            xfer_active <= 1'b0;
        end
        // NEW TRANSFER → RESET WAIT
        else if (PSEL && !PENABLE) begin
            wait_cnt    <= '0;
            PREADY      <= 1'b0;
            xfer_active <= 1'b1;
            
            // Random wait cycles 1-5
            begin
                logic [31:0] rand_val;
                rand_val = $urandom;
                wait_target <= WAIT_CNT_W'((rand_val % 6));  // 1-5
            end
        end
        // ACCESS PHASE → COUNT
        else if (PSEL && PENABLE && xfer_active) begin
            if (wait_cnt == wait_target) begin
                PREADY      <= 1'b1;
                xfer_active <= 1'b0;
                wait_cnt    <= wait_cnt;
            end else begin
                wait_cnt <= wait_cnt + 1'b1;
                PREADY   <= 1'b0;
            end
        end
        // Idle or transfer ended
        else begin
            PREADY <= 1'b0;
            if (!PSEL) begin
                xfer_active <= 1'b0;
                wait_cnt    <= '0;
            end
        end
    end

    // ===================================================
    // ADDRESS LATCH
    // ===================================================
    always_ff @(posedge PCLK or negedge PRESETn) begin
        if (!PRESETn) begin
            addr_latched <= 32'b0;
        end
        // latch on every SETUP phase
        else if (PSEL && !PENABLE) begin
            addr_latched <= PADDR;
        end
    end

    // ===================================================
    // PSLVERR Logic
    // ===================================================
    always_comb begin
        pslverr_next = 1'b0;
        
        // Set PSLVERR for invalid addresses on transfer completion
        if (xfer_done_next) begin
            case (addr_latched)
                32'h1000, 32'h1004, 32'h1008, 32'h100C: begin
                    // Valid addresses - no error
                    pslverr_next = 1'b0;
                end
                default: begin
                    // Invalid address - set error
                    pslverr_next = 1'b1;
                end
            endcase
        end
    end

    always_ff @(posedge PCLK or negedge PRESETn) begin
        if (!PRESETn) begin
            PSLVERR <= 1'b0;
        end else begin
            PSLVERR <= pslverr_next;
        end
    end

    // PSLVERR Assertions
    property p_pslverr_only_on_completion;
        @(posedge PCLK) disable iff (!PRESETn)
        $rose(PSLVERR) |-> $past(xfer_done_next);
    endproperty

    assert_pslverr_only_on_completion:
        assert property (p_pslverr_only_on_completion)
        else $error("[PSLVERR-ASSERT] PSLVERR asserted without transfer completion");




    property p_pslverr_for_invalid_addr;
        @(posedge PCLK) disable iff (!PRESETn)
        (xfer_done_next && !(addr_latched inside {32'h1000, 32'h1004, 32'h1008, 32'h100C})) |=> PSLVERR;
    endproperty
    assert_pslverr_for_invalid_addr: assert property (p_pslverr_for_invalid_addr)
        else $error("[PSLVERR-ASSERT] Invalid address didn't generate PSLVERR");

    // ===================================================
    // WRITE
    // ===================================================
    always_ff @(posedge PCLK or negedge PRESETn) begin
        if (!PRESETn) begin
            regfile[0] <= 32'b0;
            regfile[1] <= 32'b0;
            regfile[2] <= 32'b0;
            regfile[3] <= 32'b0;
        end
        // Write happens when transfer WILL complete next cycle
        else if (xfer_done_next && PWRITE) begin
            case (addr_latched)
                32'h1000: regfile[0] <= PWDATA;
                32'h1004: regfile[1] <= PWDATA;
                32'h1008: regfile[2] <= PWDATA;
                32'h100C: regfile[3] <= PWDATA;
                default: begin
                    // Invalid address - no write (PSLVERR already set)
                end
            endcase
        end
    end

    // ===================================================
    // READ
    // ===================================================
    always_ff @(posedge PCLK or negedge PRESETn) begin
        if (!PRESETn) begin
            PRDATA <= 32'b0;
        end
        // Update PRDATA when transfer WILL complete next cycle
        else if (xfer_done_next && !PWRITE) begin
            case (addr_latched)
                32'h1000: PRDATA <= regfile[0];
                32'h1004: PRDATA <= regfile[1];
                32'h1008: PRDATA <= regfile[2];
                32'h100C: PRDATA <= regfile[3];
                default:  PRDATA <= 32'b0;
            endcase
        end
        // Clear PRDATA when no transfer is active
        else if (!PSEL) begin
            PRDATA <= 32'b0;
        end
    end

endmodule