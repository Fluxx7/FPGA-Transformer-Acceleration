`timescale 1ns/1ps


// ============================================================================
// ENHANCED SOFTMAX MODULE - SYNTHESIS OPTIMIZED
// ============================================================================
module enhanced_softmax #(
    parameter SEQ_LEN = 8
)(
    input wire clk,
    input wire rst,
    input wire start,
    input wire signed [15:0] input_scores [0:SEQ_LEN-1][0:SEQ_LEN-1],
    output reg signed [15:0] output_weights [0:SEQ_LEN-1][0:SEQ_LEN-1],
    output reg done
);

    /* verilator lint_off BLKSEQ */
    function [15:0] enhanced_exp;
        input signed [15:0] x;
        reg signed [15:0] shifted_x;
        begin
            shifted_x = x >>> 4;
            if (shifted_x < -16) enhanced_exp = 1;
            else if (shifted_x > 16) enhanced_exp = 512;
            else if (shifted_x < 0) enhanced_exp = 64 + (shifted_x * 3);
            else enhanced_exp = 64 + (shifted_x * 8);

            if (enhanced_exp < 1) enhanced_exp = 1;
        end
    endfunction
    /* verilator lint_on BLKSEQ */

    localparam IDLE = 0, FIND_MAX = 1, COMPUTE_EXP = 2, NORMALIZE = 3, COMPLETE = 4;
    reg [2:0] state;
    reg [2:0] row_idx, col_idx;
    reg signed [15:0] max_val;
    reg signed [31:0] exp_sum;
    reg signed [15:0] temp_exp [0:SEQ_LEN-1];

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
                        end else begin
                            row_idx <= row_idx + 1;
                        end
                    end else begin
                        col_idx <= col_idx + 1;
                    end
                end

                COMPUTE_EXP: begin
                    if (col_idx == 0) exp_sum <= 0;

                    temp_exp[col_idx] <= enhanced_exp(input_scores[row_idx][col_idx] - max_val);
                    exp_sum <= exp_sum + 32'(enhanced_exp(input_scores[row_idx][col_idx] - max_val));

                    if (col_idx == 3'(SEQ_LEN - 1)) begin
                        col_idx <= 0;
                        state <= NORMALIZE;
                    end else begin
                        col_idx <= col_idx + 1;
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
