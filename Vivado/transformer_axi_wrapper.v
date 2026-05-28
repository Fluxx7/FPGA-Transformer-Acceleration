// =============================================================================
// AXI4-Lite Wrapper for complete_transformer_decoder (Verilog)
//
// Register Map (byte addresses):
//   0x00  CONTROL     [W]   bit 0 = start (self-clearing pulse), bit 1 = soft_rst
//   0x04  STATUS      [R]   bit 0 = done, bit 1 = valid,
//                           bits [TOK_HI:2] = predicted_token (width = $clog2(VOCAB_SIZE)),
//                           bits [TOK_HI+4:TOK_HI+1] = current_state_debug
//   0x08  CYCLE_COUNT [R]   32-bit cycle counter
//   0x0C  INPUT_SEQ_0 [W]   bits [4:0] = input_sequence[0]
//   0x10  INPUT_SEQ_1 [W]   bits [4:0] = input_sequence[1]
//   0x14  INPUT_SEQ_2 [W]   bits [4:0] = input_sequence[2]
//   0x18  INPUT_SEQ_3 [W]   bits [4:0] = input_sequence[3]
//   0x1C  INPUT_SEQ_4 [W]   bits [4:0] = input_sequence[4]
//   0x20  INPUT_SEQ_5 [W]   bits [4:0] = input_sequence[5]
//   0x24  INPUT_SEQ_6 [W]   bits [4:0] = input_sequence[6]
//   0x28  INPUT_SEQ_7 [W]   bits [4:0] = input_sequence[7]
// =============================================================================

module transformer_axi_wrapper #(
    parameter integer C_S_AXI_DATA_WIDTH = 32,
    parameter integer C_S_AXI_ADDR_WIDTH = 6,
    // Transformer parameters -- must match Python model.py Config.
    parameter integer VOCAB_SIZE = 40,
    parameter integer EMBED_DIM  = 16,
    parameter integer SEQ_LEN    = 8,
    parameter integer NUM_HEADS  = 4,
    parameter integer FFN_DIM    = 128
)(
    // AXI4-Lite slave interface
    input  wire                                S_AXI_ACLK,
    input  wire                                S_AXI_ARESETN,
    // Write address channel
    input  wire [C_S_AXI_ADDR_WIDTH-1:0]      S_AXI_AWADDR,
    input  wire [2:0]                          S_AXI_AWPROT,
    input  wire                                S_AXI_AWVALID,
    output wire                                S_AXI_AWREADY,
    // Write data channel
    input  wire [C_S_AXI_DATA_WIDTH-1:0]      S_AXI_WDATA,
    input  wire [(C_S_AXI_DATA_WIDTH/8)-1:0]  S_AXI_WSTRB,
    input  wire                                S_AXI_WVALID,
    output wire                                S_AXI_WREADY,
    // Write response channel
    output wire [1:0]                          S_AXI_BRESP,
    output wire                                S_AXI_BVALID,
    input  wire                                S_AXI_BREADY,
    // Read address channel
    input  wire [C_S_AXI_ADDR_WIDTH-1:0]      S_AXI_ARADDR,
    input  wire [2:0]                          S_AXI_ARPROT,
    input  wire                                S_AXI_ARVALID,
    output wire                                S_AXI_ARREADY,
    // Read data channel
    output wire [C_S_AXI_DATA_WIDTH-1:0]      S_AXI_RDATA,
    output wire [1:0]                          S_AXI_RRESP,
    output wire                                S_AXI_RVALID,
    input  wire                                S_AXI_RREADY
);

    // -------------------------------------------------------------------------
    // AXI-Lite internal signals
    // -------------------------------------------------------------------------
    reg  aw_en;
    reg  [C_S_AXI_ADDR_WIDTH-1:0] axi_awaddr;
    reg  axi_awready, axi_wready, axi_bvalid;
    reg  [1:0]                     axi_bresp;
    reg  [C_S_AXI_ADDR_WIDTH-1:0] axi_araddr;
    reg  axi_arready, axi_rvalid;
    reg  [C_S_AXI_DATA_WIDTH-1:0] axi_rdata;
    reg  [1:0]                     axi_rresp;

    // Sink for AXI4-Lite bits that this slave deliberately ignores.
    // Protection signals (AxPROT), unused upper WDATA bits, and high WSTRB bits
    // are part of the bus protocol but not needed by this register map; tying
    // them into a discarded wire silences "unconnected port" warnings.
    (* DONT_TOUCH = "true" *) wire _axi_unused = &{1'b1,
        S_AXI_AWPROT,
        S_AXI_ARPROT,
        S_AXI_WDATA[C_S_AXI_DATA_WIDTH-1:5],
        S_AXI_WSTRB[(C_S_AXI_DATA_WIDTH/8)-1:1]};

    assign S_AXI_AWREADY = axi_awready;
    assign S_AXI_WREADY  = axi_wready;
    assign S_AXI_BRESP   = axi_bresp;
    assign S_AXI_BVALID  = axi_bvalid;
    assign S_AXI_ARREADY = axi_arready;
    assign S_AXI_RDATA   = axi_rdata;
    assign S_AXI_RRESP   = axi_rresp;
    assign S_AXI_RVALID  = axi_rvalid;

    // -------------------------------------------------------------------------
    // Decoder interface registers
    // -------------------------------------------------------------------------
    reg                    soft_rst_reg;
    reg                    start_reg;
    reg [SEQ_LEN*6-1:0]   input_seq_flat;   // packed: token i at bits [i*6+5 : i*6]

    // Width of predicted_token must match argmax/decoder ($clog2(VOCAB_SIZE))
    localparam integer TOK_BITS = $clog2(VOCAB_SIZE);
    wire [TOK_BITS-1:0] predicted_token;
    wire        done, valid;
    wire [31:0] cycle_count;
    wire [3:0]  current_state_debug;

    // Sticky latches for done/valid/predicted_token.
    //
    // The decoder's FINISHED state only asserts done/valid for one cycle before
    // bouncing back to IDLE (because start_reg is a self-clearing pulse, so
    // !start is true immediately on entry to FINISHED). At any non-trivial
    // software polling interval the AXI host would never observe done=1.
    // We latch the rising edge here so software can poll at its leisure.
    //
    // Latches clear on: hard reset, soft reset, or a new start pulse.
    reg                  done_latched;
    reg                  valid_latched;
    reg [TOK_BITS-1:0]   predicted_token_latched;

    wire rst_internal = ~S_AXI_ARESETN | soft_rst_reg;

    // -------------------------------------------------------------------------
    // Decoder instantiation
    // -------------------------------------------------------------------------
    complete_transformer_decoder #(
        .VOCAB_SIZE(VOCAB_SIZE),
        .EMBED_DIM (EMBED_DIM),
        .SEQ_LEN   (SEQ_LEN),
        .NUM_HEADS (NUM_HEADS),
        .FFN_DIM   (FFN_DIM)
    ) decoder_inst (
        .clk                 (S_AXI_ACLK),
        .rst                 (rst_internal),
        .start               (start_reg),
        .input_sequence_flat (input_seq_flat),
        .predicted_token     (predicted_token),
        .done                (done),
        .valid               (valid),
        .cycle_count         (cycle_count),
        .current_state_debug (current_state_debug)
    );

    // -------------------------------------------------------------------------
    // Sticky done/valid/predicted_token latches (see declaration comment).
    // Cleared by: hard reset, soft_rst_reg, or a new start_reg pulse.
    // -------------------------------------------------------------------------
    always @(posedge S_AXI_ACLK) begin
        if (~S_AXI_ARESETN || soft_rst_reg || start_reg) begin
            done_latched            <= 1'b0;
            valid_latched           <= 1'b0;
            predicted_token_latched <= {TOK_BITS{1'b0}};
        end else if (done && valid) begin
            done_latched            <= 1'b1;
            valid_latched           <= 1'b1;
            predicted_token_latched <= predicted_token;
        end
    end

    // -------------------------------------------------------------------------
    // Write address handshake
    // -------------------------------------------------------------------------
    always @(posedge S_AXI_ACLK) begin
        if (~S_AXI_ARESETN) begin
            axi_awready <= 1'b0;
            aw_en <= 1'b1;
        end else begin
            if (~axi_awready && S_AXI_AWVALID && S_AXI_WVALID && aw_en) begin
                axi_awready <= 1'b1;
                aw_en <= 1'b0;
            end else if (S_AXI_BREADY && axi_bvalid) begin
                aw_en <= 1'b1;
                axi_awready <= 1'b0;
            end else begin
                axi_awready <= 1'b0;
            end
        end
    end

    always @(posedge S_AXI_ACLK) begin
        if (~S_AXI_ARESETN)
            axi_awaddr <= 0;
        else if (~axi_awready && S_AXI_AWVALID && S_AXI_WVALID && aw_en)
            axi_awaddr <= S_AXI_AWADDR;
    end

    // -------------------------------------------------------------------------
    // Write data handshake
    // -------------------------------------------------------------------------
    always @(posedge S_AXI_ACLK) begin
        if (~S_AXI_ARESETN)
            axi_wready <= 1'b0;
        else if (~axi_wready && S_AXI_WVALID && S_AXI_AWVALID && aw_en)
            axi_wready <= 1'b1;
        else
            axi_wready <= 1'b0;
    end

    // -------------------------------------------------------------------------
    // Write logic
    // -------------------------------------------------------------------------
    wire slv_reg_wren = axi_wready && S_AXI_WVALID && axi_awready && S_AXI_AWVALID;

    always @(posedge S_AXI_ACLK) begin
        if (~S_AXI_ARESETN) begin
            soft_rst_reg   <= 1'b0;
            start_reg      <= 1'b0;
            input_seq_flat <= {SEQ_LEN*6{1'b0}};
        end else begin
            soft_rst_reg <= 1'b0;  // default: clear each cycle
            start_reg    <= 1'b0;  // default: self-clear each cycle

            if (slv_reg_wren) begin
                case (axi_awaddr[5:2])
                    4'd0: begin  // CONTROL
                        if (S_AXI_WSTRB[0]) begin
                            start_reg    <= S_AXI_WDATA[0];
                            soft_rst_reg <= S_AXI_WDATA[1];
                        end
                    end
                    // 6-bit slots: must match the decoder's
                    // `input_sequence_flat[gi*6 +: 6]` unpack.
                    4'd3:  if (S_AXI_WSTRB[0]) input_seq_flat[0*6 +: 6] <= S_AXI_WDATA[5:0];
                    4'd4:  if (S_AXI_WSTRB[0]) input_seq_flat[1*6 +: 6] <= S_AXI_WDATA[5:0];
                    4'd5:  if (S_AXI_WSTRB[0]) input_seq_flat[2*6 +: 6] <= S_AXI_WDATA[5:0];
                    4'd6:  if (S_AXI_WSTRB[0]) input_seq_flat[3*6 +: 6] <= S_AXI_WDATA[5:0];
                    4'd7:  if (S_AXI_WSTRB[0]) input_seq_flat[4*6 +: 6] <= S_AXI_WDATA[5:0];
                    4'd8:  if (S_AXI_WSTRB[0]) input_seq_flat[5*6 +: 6] <= S_AXI_WDATA[5:0];
                    4'd9:  if (S_AXI_WSTRB[0]) input_seq_flat[6*6 +: 6] <= S_AXI_WDATA[5:0];
                    4'd10: if (S_AXI_WSTRB[0]) input_seq_flat[7*6 +: 6] <= S_AXI_WDATA[5:0];
                    default: ;
                endcase
            end
        end
    end

    // -------------------------------------------------------------------------
    // Write response
    // -------------------------------------------------------------------------
    always @(posedge S_AXI_ACLK) begin
        if (~S_AXI_ARESETN) begin
            axi_bvalid <= 1'b0;
            axi_bresp  <= 2'b00;
        end else if (axi_awready && S_AXI_AWVALID && ~axi_bvalid && axi_wready && S_AXI_WVALID) begin
            axi_bvalid <= 1'b1;
            axi_bresp  <= 2'b00;
        end else if (S_AXI_BREADY && axi_bvalid) begin
            axi_bvalid <= 1'b0;
        end
    end

    // -------------------------------------------------------------------------
    // Read address handshake
    // -------------------------------------------------------------------------
    always @(posedge S_AXI_ACLK) begin
        if (~S_AXI_ARESETN)
            axi_arready <= 1'b0;
        else if (~axi_arready && S_AXI_ARVALID)
            axi_arready <= 1'b1;
        else
            axi_arready <= 1'b0;
    end

    always @(posedge S_AXI_ACLK) begin
        if (~S_AXI_ARESETN)
            axi_araddr <= 0;
        else if (~axi_arready && S_AXI_ARVALID)
            axi_araddr <= S_AXI_ARADDR;
    end

    // -------------------------------------------------------------------------
    // Read logic
    // -------------------------------------------------------------------------
    always @(posedge S_AXI_ACLK) begin
        if (~S_AXI_ARESETN) begin
            axi_rvalid <= 1'b0;
            axi_rresp  <= 2'b00;
        end else if (axi_arready && S_AXI_ARVALID && ~axi_rvalid) begin
            axi_rvalid <= 1'b1;
            axi_rresp  <= 2'b00;
        end else if (axi_rvalid && S_AXI_RREADY) begin
            axi_rvalid <= 1'b0;
        end
    end

    always @(posedge S_AXI_ACLK) begin
        if (~S_AXI_ARESETN) begin
            axi_rdata <= 0;
        end else if (~axi_rvalid) begin
            case (axi_araddr[5:2])
                // Report the *latched* done/valid/predicted_token so software
                // doesn't have to catch the 1-cycle FINISHED pulse. The
                // current_state_debug field reflects the live FSM state.
                4'd0: axi_rdata <= {30'b0, valid_latched, done_latched};
                4'd1: axi_rdata <= {{(32-2-TOK_BITS-4){1'b0}}, current_state_debug, predicted_token_latched, valid_latched, done_latched};
                4'd2: axi_rdata <= cycle_count;
                4'd3:  axi_rdata <= {26'b0, input_seq_flat[0*6 +: 6]};
                4'd4:  axi_rdata <= {26'b0, input_seq_flat[1*6 +: 6]};
                4'd5:  axi_rdata <= {26'b0, input_seq_flat[2*6 +: 6]};
                4'd6:  axi_rdata <= {26'b0, input_seq_flat[3*6 +: 6]};
                4'd7:  axi_rdata <= {26'b0, input_seq_flat[4*6 +: 6]};
                4'd8:  axi_rdata <= {26'b0, input_seq_flat[5*6 +: 6]};
                4'd9:  axi_rdata <= {26'b0, input_seq_flat[6*6 +: 6]};
                4'd10: axi_rdata <= {26'b0, input_seq_flat[7*6 +: 6]};
                default: axi_rdata <= 32'hDEADBEEF;
            endcase
        end
    end

endmodule
