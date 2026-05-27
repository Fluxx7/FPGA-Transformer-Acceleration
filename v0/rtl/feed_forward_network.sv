`timescale 1ns/1ps

// ============================================================================
// FEED FORWARD NETWORK - SYNTHESIS OPTIMIZED
// ============================================================================
module feed_forward_network #(
    parameter SEQ_LEN = 8,
    parameter EMBED_DIM = 64,
    parameter FFN_DIM = 256
)(
    input wire clk,
    input wire rst,
    input wire start,
    input wire signed [15:0] input_data [0:SEQ_LEN-1][0:EMBED_DIM-1],
    output reg signed [15:0] output_data [0:SEQ_LEN-1][0:EMBED_DIM-1],
    output reg done,
    output reg valid
);

    localparam IDLE = 0, LINEAR1 = 1, LINEAR2 = 2, COMPLETE = 3;
    localparam DIM_BITS = $clog2(EMBED_DIM);
    localparam FFN_BITS = $clog2(FFN_DIM);
    reg [2:0] state;

    reg [2:0] seq_idx;
    reg [DIM_BITS-1:0] in_dim, out_dim;
    reg [FFN_BITS-1:0] hidden_dim;
    reg signed [31:0] accumulator;
    // ram_style "registers" tells Vivado to keep this as flip-flops instead
    // of trying to infer a 3D-RAM, which fixes Synth 8-11357 (3D-RAM runtime
    // warning at SEQ_LEN*FFN_DIM*16 bits). The write pattern (conditional
    // saturation on with_bias) isn't BRAM-inferrable, so "block" was being
    // rejected with Synth 8-7186; "registers" is the honest hint here.
    (* ram_style = "registers" *)
    reg signed [15:0] hidden_data [0:SEQ_LEN-1][0:FFN_DIM-1];
    reg [2:0] pipe_stage;

    wire [DIM_BITS+FFN_BITS-1:0] w1_addr, w2_addr;
    wire [FFN_BITS-1:0] b1_addr;
    wire [DIM_BITS-1:0] b2_addr;
    wire [15:0] w1_data, w2_data, b1_data, b2_data;
    wire mem_enable_w1, mem_enable_w2, mem_enable_b1, mem_enable_b2;

    assign w1_addr = in_dim * FFN_DIM + (DIM_BITS+FFN_BITS)'(hidden_dim);
    assign w2_addr = hidden_dim * EMBED_DIM + (DIM_BITS+FFN_BITS)'(out_dim);
    assign b1_addr = hidden_dim;
    assign b2_addr = out_dim;

    assign mem_enable_w1 = (state == LINEAR1);
    assign mem_enable_w2 = (state == LINEAR2);
    assign mem_enable_b1 = (state == LINEAR1 && in_dim == DIM_BITS'(EMBED_DIM - 1));
    assign mem_enable_b2 = (state == LINEAR2 && hidden_dim == FFN_BITS'(FFN_DIM - 1));

    memory_module #(.ADDR_WIDTH(DIM_BITS+FFN_BITS), .DATA_WIDTH(16), .DEPTH(EMBED_DIM*FFN_DIM), .MEM_FILE("memory/ffn_w1.mem"))
        w1_memory (.clk(clk), .addr(w1_addr), .data_out(w1_data), .enable(mem_enable_w1));
    memory_module #(.ADDR_WIDTH(FFN_BITS), .DATA_WIDTH(16), .DEPTH(FFN_DIM), .MEM_FILE("memory/ffn_b1.mem"))
        b1_memory (.clk(clk), .addr(b1_addr), .data_out(b1_data), .enable(mem_enable_b1));
    memory_module #(.ADDR_WIDTH(DIM_BITS+FFN_BITS), .DATA_WIDTH(16), .DEPTH(FFN_DIM*EMBED_DIM), .MEM_FILE("memory/ffn_w2.mem"))
        w2_memory (.clk(clk), .addr(w2_addr), .data_out(w2_data), .enable(mem_enable_w2));
    memory_module #(.ADDR_WIDTH(DIM_BITS), .DATA_WIDTH(16), .DEPTH(EMBED_DIM), .MEM_FILE("memory/ffn_b2.mem"))
        b2_memory (.clk(clk), .addr(b2_addr), .data_out(b2_data), .enable(mem_enable_b2));

    reg signed [31:0] with_bias;

    // Fixed: Initialize arrays in initial block
    initial begin
        integer i, j;
        for (i = 0; i < SEQ_LEN; i = i + 1) begin
            for (j = 0; j < FFN_DIM; j = j + 1) begin
                hidden_data[i][j] = 0;
            end
            for (j = 0; j < EMBED_DIM; j = j + 1) begin
                output_data[i][j] = 0;
            end
        end
    end

    always @(posedge clk) begin
        if (rst) begin
            state <= IDLE;
            seq_idx <= 0;
            in_dim <= 0;
            out_dim <= 0;
            hidden_dim <= 0;
            accumulator <= 0;
            pipe_stage <= 0;
            done <= 0;
            valid <= 0;
            with_bias <= 0;
        end else begin
            case (state)
                IDLE: begin
                    done <= 0;
                    valid <= 0;
                    if (start) begin
                        state <= LINEAR1;
                        seq_idx <= 0;
                        in_dim <= 0;
                        hidden_dim <= 0;
                        accumulator <= 0;
                        pipe_stage <= 0;
                    end
                end

                LINEAR1: begin
                    pipe_stage <= pipe_stage + 1;

                    if (pipe_stage >= 2) begin
                        accumulator <= accumulator + (input_data[seq_idx][in_dim] * $signed(w1_data));
                        pipe_stage <= 0;

                        if (in_dim == DIM_BITS'(EMBED_DIM - 1)) begin
                            with_bias <= (accumulator >>> 8) + 32'($signed(b1_data));

                            if (with_bias > 32767) begin
                                hidden_data[seq_idx][hidden_dim] <= 16'h7FFF;
                            end else if (with_bias < 0) begin
                                hidden_data[seq_idx][hidden_dim] <= 16'h0;
                            end else begin
                                hidden_data[seq_idx][hidden_dim] <= with_bias[15:0];
                            end

                            in_dim <= 0;
                            accumulator <= 0;

                            if (hidden_dim == FFN_BITS'(FFN_DIM - 1)) begin
                                hidden_dim <= 0;
                                if (seq_idx == 3'(SEQ_LEN - 1)) begin
                                    state <= LINEAR2;
                                    seq_idx <= 0;
                                    out_dim <= 0;
                                    pipe_stage <= 0;
                                end else begin
                                    seq_idx <= seq_idx + 1;
                                end
                            end else begin
                                hidden_dim <= hidden_dim + 1;
                            end
                        end else begin
                            in_dim <= in_dim + 1;
                        end
                    end
                end

                LINEAR2: begin
                    pipe_stage <= pipe_stage + 1;

                    if (pipe_stage >= 2) begin
                        accumulator <= accumulator + (hidden_data[seq_idx][hidden_dim] * $signed(w2_data));
                        pipe_stage <= 0;

                        if (hidden_dim == FFN_BITS'(FFN_DIM - 1)) begin
                            with_bias <= (accumulator >>> 8) + 32'($signed(b2_data));

                            if (with_bias > 32767)
                                output_data[seq_idx][out_dim] <= 16'h7FFF;
                            else if (with_bias < -32768)
                                output_data[seq_idx][out_dim] <= 16'h8000;
                            else
                                output_data[seq_idx][out_dim] <= with_bias[15:0];

                            hidden_dim <= 0;
                            accumulator <= 0;

                            if (out_dim == DIM_BITS'(EMBED_DIM - 1)) begin
                                out_dim <= 0;
                                if (seq_idx == 3'(SEQ_LEN - 1)) begin
                                    state <= COMPLETE;
                                end else begin
                                    seq_idx <= seq_idx + 1;
                                end
                            end else begin
                                out_dim <= out_dim + 1;
                            end
                        end else begin
                            hidden_dim <= hidden_dim + 1;
                        end
                    end
                end

                COMPLETE: begin
                    done <= 1;
                    valid <= 1;
                    if (!start) begin
                        state <= IDLE;
                    end
                end
            endcase
        end
    end

endmodule
