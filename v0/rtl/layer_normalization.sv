`timescale 1ns/1ps

// ============================================================================
// LAYER NORMALIZATION - SYNTHESIS OPTIMIZED
// ============================================================================
module layer_normalization #(
    parameter SEQ_LEN = 8,
    parameter EMBED_DIM = 64,
    parameter GAMMA_FILE = "memory/layernorm1_gamma.mem",
    parameter BETA_FILE = "memory/layernorm1_beta.mem"
)(
    input wire clk,
    input wire rst,
    input wire start,
    input wire signed [15:0] input_data [0:SEQ_LEN-1][0:EMBED_DIM-1],
    input wire signed [15:0] residual_data [0:SEQ_LEN-1][0:EMBED_DIM-1],
    output reg signed [15:0] output_data [0:SEQ_LEN-1][0:EMBED_DIM-1],
    output reg done,
    output reg valid
);

    localparam IDLE = 0, ADD_RESIDUAL = 1, COMPUTE_MEAN = 2,
               COMPUTE_VAR = 3, NORMALIZE = 4, COMPLETE = 5;
    localparam DIM_BITS = $clog2(EMBED_DIM);
    reg [2:0] state;

    reg [2:0] seq_idx;
    reg [DIM_BITS-1:0] dim_idx;
    reg signed [15:0] sum_data [0:SEQ_LEN-1][0:EMBED_DIM-1];
    reg signed [31:0] mean_acc, var_acc;
    reg signed [15:0] mean_val [0:SEQ_LEN-1];
    reg signed [15:0] std_val [0:SEQ_LEN-1];
    reg [2:0] pipe_stage;

    /* verilator lint_off BLKSEQ */
    function [15:0] improved_sqrt;
        input [31:0] x;
        reg [31:0] approx, new_approx;
        integer iter;
        begin
            if (x == 0) begin
                improved_sqrt = 0;
            end else begin
                approx = x >>> 1;
                for (iter = 0; iter < 3; iter = iter + 1) begin
                    new_approx = (approx + x / approx) >>> 1;
                    approx = new_approx;
                end
                improved_sqrt = approx[15:0];
            end
        end
    endfunction
    /* verilator lint_on BLKSEQ */

    reg signed [16:0] temp_sum;
    reg signed [31:0] diff, diff_sq, normalized, with_gamma, final_result;
    reg [31:0] variance;

    wire [DIM_BITS-1:0] param_addr;
    wire [15:0] gamma_data, beta_data;
    wire mem_enable;

    assign param_addr = dim_idx;
    assign mem_enable = (state == NORMALIZE);

    memory_module #(
        .ADDR_WIDTH(DIM_BITS), .DATA_WIDTH(16), .DEPTH(EMBED_DIM), .MEM_FILE(GAMMA_FILE)
    ) gamma_memory (
        .clk(clk), .addr(param_addr), .data_out(gamma_data), .enable(mem_enable)
    );

    memory_module #(
        .ADDR_WIDTH(DIM_BITS), .DATA_WIDTH(16), .DEPTH(EMBED_DIM), .MEM_FILE(BETA_FILE)
    ) beta_memory (
        .clk(clk), .addr(param_addr), .data_out(beta_data), .enable(mem_enable)
    );

    // Fixed: Initialize arrays in initial block
    initial begin
        integer i, j;
        for (i = 0; i < SEQ_LEN; i = i + 1) begin
            mean_val[i] = 0;
            std_val[i] = 0;
            for (j = 0; j < EMBED_DIM; j = j + 1) begin
                sum_data[i][j] = 0;
                output_data[i][j] = 0;
            end
        end
    end

    always @(posedge clk) begin
        if (rst) begin
            state <= IDLE;
            seq_idx <= 0;
            dim_idx <= 0;
            mean_acc <= 0;
            var_acc <= 0;
            pipe_stage <= 0;
            done <= 0;
            valid <= 0;

            temp_sum <= 0;
            diff <= 0;
            diff_sq <= 0;
            normalized <= 0;
            with_gamma <= 0;
            final_result <= 0;
            variance <= 0;
        end else begin
            case (state)
                IDLE: begin
                    done <= 0;
                    valid <= 0;
                    if (start) begin
                        state <= ADD_RESIDUAL;
                        seq_idx <= 0;
                        dim_idx <= 0;
                    end
                end

                ADD_RESIDUAL: begin
                    temp_sum <= input_data[seq_idx][dim_idx] + residual_data[seq_idx][dim_idx];

                    if (temp_sum > 32767)
                        sum_data[seq_idx][dim_idx] <= 16'h7FFF;
                    else if (temp_sum < -32768)
                        sum_data[seq_idx][dim_idx] <= 16'h8000;
                    else
                        sum_data[seq_idx][dim_idx] <= temp_sum[15:0];

                    if (dim_idx == DIM_BITS'(EMBED_DIM - 1)) begin
                        dim_idx <= 0;
                        if (seq_idx == 3'(SEQ_LEN - 1)) begin
                            state <= COMPUTE_MEAN;
                            seq_idx <= 0;
                            mean_acc <= 0;
                        end else begin
                            seq_idx <= seq_idx + 1;
                        end
                    end else begin
                        dim_idx <= dim_idx + 1;
                    end
                end

                COMPUTE_MEAN: begin
                    mean_acc <= mean_acc + 32'(sum_data[seq_idx][dim_idx]);

                    if (dim_idx == DIM_BITS'(EMBED_DIM - 1)) begin
                        mean_val[seq_idx] <= 16'(mean_acc >>> DIM_BITS);
                        dim_idx <= 0;
                        var_acc <= 0;
                        state <= COMPUTE_VAR;
                    end else begin
                        dim_idx <= dim_idx + 1;
                    end
                end

                COMPUTE_VAR: begin
                    diff <= 32'(sum_data[seq_idx][dim_idx]) - 32'(mean_val[seq_idx]);
                    diff_sq <= (diff * diff) >>> 8;
                    var_acc <= var_acc + diff_sq;

                    if (dim_idx == DIM_BITS'(EMBED_DIM - 1)) begin
                        variance <= var_acc >>> DIM_BITS;
                        std_val[seq_idx] <= improved_sqrt(variance + 32'd256);
                        dim_idx <= 0;
                        pipe_stage <= 0;
                        state <= NORMALIZE;
                    end else begin
                        dim_idx <= dim_idx + 1;
                    end
                end

                NORMALIZE: begin
                    pipe_stage <= pipe_stage + 1;

                    if (pipe_stage >= 2) begin
                        normalized <= ((32'(sum_data[seq_idx][dim_idx]) - 32'(mean_val[seq_idx])) << 8) / 32'(std_val[seq_idx]);
                        with_gamma <= (normalized * $signed(gamma_data)) >>> 8;
                        final_result <= with_gamma + 32'($signed(beta_data));

                        if (final_result > 32767)
                            output_data[seq_idx][dim_idx] <= 16'h7FFF;
                        else if (final_result < -32768)
                            output_data[seq_idx][dim_idx] <= 16'h8000;
                        else
                            output_data[seq_idx][dim_idx] <= final_result[15:0];

                        pipe_stage <= 0;

                        if (dim_idx == DIM_BITS'(EMBED_DIM - 1)) begin
                            dim_idx <= 0;
                            if (seq_idx == 3'(SEQ_LEN - 1)) begin
                                state <= COMPLETE;
                            end else begin
                                seq_idx <= seq_idx + 1;
                                mean_acc <= 0;
                                state <= COMPUTE_MEAN;
                            end
                        end else begin
                            dim_idx <= dim_idx + 1;
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
