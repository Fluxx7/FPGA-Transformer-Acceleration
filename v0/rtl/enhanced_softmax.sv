`timescale 1ns/1ps


// ============================================================================
// ENHANCED SOFTMAX MODULE - SYNTHESIS OPTIMIZED
// ============================================================================
module enhanced_softmax #(
    parameter SEQ_LEN = 8,
    parameter EXP_MEM = "memory/exp_lut.mem"
)(
    input wire clk,
    input wire rst,
    input wire start,
    input wire signed [15:0] input_scores [0:SEQ_LEN-1][0:SEQ_LEN-1],
    output reg signed [15:0] output_weights [0:SEQ_LEN-1][0:SEQ_LEN-1],
    output reg done
);

    localparam IDLE = 0, FIND_MAX = 1, EXP_DELAY = 2, COMPUTE_EXP = 3, NORMALIZE = 4, COMPLETE = 5;
    reg [2:0] state;
    reg [2:0] row_idx, col_idx;
    reg signed [15:0] max_val;
    reg signed [31:0] exp_sum;
    reg signed [15:0] temp_exp [0:SEQ_LEN-1];

    reg signed [15:0] exp_lookup;
    wire signed [15:0] clamped = (exp_lookup > 16'sd0) ? 
                                    16'sd0 :
                                    (exp_lookup < -16'sd2048) ? -16'sd2048 : exp_lookup;
    wire [5:0] exp_index = 6'((-clamped) >>> 5);

    wire [15:0] exp_val_raw;
    memory_module #(
        .ADDR_WIDTH(6), .DATA_WIDTH(16), .DEPTH(64), .MEM_FILE(EXP_MEM)
    ) exp_rom (
        .clk(clk), .addr(exp_index), .data_out(exp_val_raw), .enable(state == COMPUTE_EXP)
    );

    wire [15:0] exp_val = (exp_val_raw == 16'd0) ? 16'd1 : exp_val_raw;
    // Fixed: Initialize arrays in initial block
    initial begin
        integer i, j;
        for (i = 0; i < SEQ_LEN; i = i + 1) begin
            temp_exp[i] = 0;
            for (j = 0; j < SEQ_LEN; j = j + 1) begin
                output_weights[i][j] = 0;
            end
        end
    end

    always @(posedge clk) begin
        if (rst) begin
            state <= IDLE;
            row_idx <= 0;
            col_idx <= 0;
            max_val <= -16'h4000;
            exp_sum <= 0;
            exp_lookup <= 0;
            done <= 0;
        end else begin
            case (state)
                IDLE: begin
                    done <= 0;
                    if (start) begin
                        state <= FIND_MAX;
                        row_idx <= 0;
                        col_idx <= 0;
                        max_val <= input_scores[0][0];
                    end
                end

                FIND_MAX: begin
                    if (input_scores[row_idx][col_idx] > max_val) begin
                        max_val <= input_scores[row_idx][col_idx];
                    end

                    if (col_idx == 3'(SEQ_LEN - 1)) begin
                        col_idx <= 0;
                        if (row_idx == 3'(SEQ_LEN - 1)) begin
                            state <= COMPUTE_EXP;
                            row_idx <= 0;
                            exp_sum <= 0;
                            exp_lookup <= input_scores[row_idx][col_idx] - max_val;
                        end else begin
                            row_idx <= row_idx + 1;
                        end
                    end else begin
                        col_idx <= col_idx + 1;
                    end
                end

                EXP_DELAY: begin // one cycle delay for lookup to update
                    state <= COMPUTE_EXP;
                end

                COMPUTE_EXP: begin
                    temp_exp[col_idx] <= exp_val;
                    exp_sum <= exp_sum + 32'(exp_val);

                    if (col_idx == 3'(SEQ_LEN - 1)) begin
                        col_idx <= 0;
                        state <= NORMALIZE;
                    end else begin
                        col_idx <= col_idx + 1;
                        exp_lookup <= input_scores[row_idx][col_idx] - max_val;
                    end
                end

                NORMALIZE: begin
                    if (exp_sum > 0) begin
                        reg [31:0] normalized;
                        normalized = (32'(temp_exp[col_idx]) << 12) / 32'(exp_sum[15:0]);
                        if (normalized > 32'h7FFF) normalized = 32'h7FFF;
                        output_weights[row_idx][col_idx] <= normalized[15:0];
                    end else begin
                        output_weights[row_idx][col_idx] <= 0;
                    end

                    if (col_idx == 3'(SEQ_LEN - 1)) begin
                        col_idx <= 0;
                        if (row_idx == 3'(SEQ_LEN - 1)) begin
                            state <= COMPLETE;
                        end else begin
                            row_idx <= row_idx + 1;
                            exp_sum <= 0;
                            state <= COMPUTE_EXP;
                        end
                    end else begin
                        col_idx <= col_idx + 1;
                    end
                end

                COMPLETE: begin
                    done <= 1;
                    state <= IDLE;
                end
            endcase
        end
    end

endmodule
