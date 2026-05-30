`timescale 1ns/1ps

// ============================================================================
// SINGLE ATTENTION HEAD - SYNTHESIS OPTIMIZED
// ============================================================================
module attention_head #(
    parameter SEQ_LEN = 8,
    parameter EMBED_DIM = 64,
    parameter HEAD_DIM = 8,
    parameter WQ_FILE = "memory/attention_wq_head0.mem",
    parameter WK_FILE = "memory/attention_wk_head0.mem",
    parameter WV_FILE = "memory/attention_wv_head0.mem"
)(
    input wire clk,
    input wire rst,
    input wire start,
    input wire signed [15:0] input_data [0:SEQ_LEN-1][0:EMBED_DIM-1],
    output reg signed [15:0] output_data [0:SEQ_LEN-1][0:HEAD_DIM-1],
    output reg done,
    output reg valid
);

    localparam IDLE = 0, COMPUTE_Q = 1, COMPUTE_K = 2, COMPUTE_V = 3,
               ATTENTION_SCORES = 4, SOFTMAX = 5, APPLY_ATTENTION = 6, COMPLETE = 7;
    localparam DIM_BITS  = $clog2(EMBED_DIM);
    localparam HEAD_BITS = $clog2(HEAD_DIM);
    localparam WQ_BITS   = $clog2(EMBED_DIM * HEAD_DIM);
    reg [2:0] state;

    reg [2:0] seq_idx, seq_idx2;
    reg [DIM_BITS-1:0] embed_idx;
    reg [3:0] head_idx;
    reg [3:0] pipe_stage;

    // Q, K, V matrices
    reg signed [15:0] Q [0:SEQ_LEN-1][0:HEAD_DIM-1];
    reg signed [15:0] K [0:SEQ_LEN-1][0:HEAD_DIM-1];
    reg signed [15:0] V [0:SEQ_LEN-1][0:HEAD_DIM-1];

    // Attention computation
    reg signed [15:0] attention_scores [0:SEQ_LEN-1][0:SEQ_LEN-1];
    reg signed [15:0] attention_weights [0:SEQ_LEN-1][0:SEQ_LEN-1];

    reg signed [31:0] accumulator;

    // Memory interfaces for Q, K, V weights
    wire [WQ_BITS-1:0] wq_addr, wk_addr, wv_addr;
    wire [15:0] wq_data, wk_data, wv_data;
    wire mem_enable_q, mem_enable_k, mem_enable_v;

    assign wq_addr = WQ_BITS'(embed_idx * HEAD_DIM) + WQ_BITS'(head_idx);
    assign wk_addr = WQ_BITS'(embed_idx * HEAD_DIM) + WQ_BITS'(head_idx);
    assign wv_addr = WQ_BITS'(embed_idx * HEAD_DIM) + WQ_BITS'(head_idx);

    assign mem_enable_q = (state == COMPUTE_Q);
    assign mem_enable_k = (state == COMPUTE_K);
    assign mem_enable_v = (state == COMPUTE_V);

    memory_module #(.ADDR_WIDTH(WQ_BITS), .DATA_WIDTH(16), .DEPTH(EMBED_DIM*HEAD_DIM), .MEM_FILE(WQ_FILE))
        wq_mem (.clk(clk), .addr(wq_addr), .data_out(wq_data), .enable(mem_enable_q));
    memory_module #(.ADDR_WIDTH(WQ_BITS), .DATA_WIDTH(16), .DEPTH(EMBED_DIM*HEAD_DIM), .MEM_FILE(WK_FILE))
        wk_mem (.clk(clk), .addr(wk_addr), .data_out(wk_data), .enable(mem_enable_k));
    memory_module #(.ADDR_WIDTH(WQ_BITS), .DATA_WIDTH(16), .DEPTH(EMBED_DIM*HEAD_DIM), .MEM_FILE(WV_FILE))
        wv_mem (.clk(clk), .addr(wv_addr), .data_out(wv_data), .enable(mem_enable_v));

    // Softmax module
    reg softmax_start;
    wire softmax_done;

    enhanced_softmax softmax_inst (
        .clk(clk), .rst(rst), .start(softmax_start),
        .input_scores(attention_scores), .output_weights(attention_weights), .done(softmax_done)
    );

    // Fixed: Initialize arrays in initial block
    initial begin
        integer i, j;
        for (i = 0; i < SEQ_LEN; i = i + 1) begin
            for (j = 0; j < HEAD_DIM; j = j + 1) begin
                Q[i][j] = 0;
                K[i][j] = 0;
                V[i][j] = 0;
                output_data[i][j] = 0;
            end
            for (j = 0; j < SEQ_LEN; j = j + 1) begin
                attention_scores[i][j] = 0;
                attention_weights[i][j] = 0;
            end
        end
    end

    wire [31:0] next_accum = accumulator + (input_data[seq_idx][embed_idx] * $signed(wq_data));

    always @(posedge clk) begin
        if (rst) begin
            state <= IDLE;
            seq_idx <= 0;
            seq_idx2 <= 0;
            embed_idx <= 0;
            head_idx <= 0;
            pipe_stage <= 0;
            accumulator <= 0;
            done <= 0;
            valid <= 0;
            softmax_start <= 0;
        end else begin
            softmax_start <= 0;

            case (state)
                IDLE: begin
                    done <= 0;
                    valid <= 0;
                    if (start) begin
                        state <= COMPUTE_Q;
                        seq_idx <= 0;
                        embed_idx <= 0;
                        head_idx <= 0;
                        pipe_stage <= 0;
                        accumulator <= 0;
                    end
                end

                COMPUTE_Q: begin
                    pipe_stage <= pipe_stage + 1;

                    if (pipe_stage >= 2) begin
                        pipe_stage <= 0;

                        if (embed_idx == DIM_BITS'(EMBED_DIM - 1)) begin
                            Q[seq_idx][head_idx[HEAD_BITS-1:0]] <= 16'(next_accum >>> 8);
                            accumulator <= 0;
                            embed_idx <= 0;

                            if (head_idx == 4'(HEAD_DIM - 1)) begin
                                head_idx <= 0;
                                if (seq_idx == 3'(SEQ_LEN - 1)) begin
                                    state <= COMPUTE_K;
                                    seq_idx <= 0;
                                end else begin
                                    seq_idx <= seq_idx + 1;
                                end
                            end else begin
                                head_idx <= head_idx + 1;
                            end
                        end else begin
                            accumulator <= next_accum;
                            embed_idx <= embed_idx + 1;
                        end
                    end
                end

                COMPUTE_K: begin
                    pipe_stage <= pipe_stage + 1;

                    if (pipe_stage >= 2) begin
                        accumulator <= accumulator + (input_data[seq_idx][embed_idx] * $signed(wk_data));
                        pipe_stage <= 0;

                        if (embed_idx == DIM_BITS'(EMBED_DIM - 1)) begin
                            K[seq_idx][head_idx[HEAD_BITS-1:0]] <= 16'(accumulator >>> 8);
                            accumulator <= 0;
                            embed_idx <= 0;

                            if (head_idx == 4'(HEAD_DIM - 1)) begin
                                head_idx <= 0;
                                if (seq_idx == 3'(SEQ_LEN - 1)) begin
                                    state <= COMPUTE_V;
                                    seq_idx <= 0;
                                end else begin
                                    seq_idx <= seq_idx + 1;
                                end
                            end else begin
                                head_idx <= head_idx + 1;
                            end
                        end else begin
                            embed_idx <= embed_idx + 1;
                        end
                    end
                end

                COMPUTE_V: begin
                    pipe_stage <= pipe_stage + 1;

                    if (pipe_stage >= 2) begin
                        accumulator <= accumulator + (input_data[seq_idx][embed_idx] * $signed(wv_data));
                        pipe_stage <= 0;

                        if (embed_idx == DIM_BITS'(EMBED_DIM - 1)) begin
                            V[seq_idx][head_idx[HEAD_BITS-1:0]] <= 16'(accumulator >>> 8);
                            accumulator <= 0;
                            embed_idx <= 0;

                            if (head_idx == 4'(HEAD_DIM - 1)) begin
                                head_idx <= 0;
                                if (seq_idx == 3'(SEQ_LEN - 1)) begin
                                    state <= ATTENTION_SCORES;
                                    seq_idx <= 0;
                                    seq_idx2 <= 0;
                                    head_idx <= 0;
                                end else begin
                                    seq_idx <= seq_idx + 1;
                                end
                            end else begin
                                head_idx <= head_idx + 1;
                            end
                        end else begin
                            embed_idx <= embed_idx + 1;
                        end
                    end
                end

                ATTENTION_SCORES: begin
                    if (head_idx == 0) begin
                        accumulator <= Q[seq_idx][head_idx[HEAD_BITS-1:0]] * K[seq_idx2][head_idx[HEAD_BITS-1:0]];
                    end else begin
                        accumulator <= accumulator + (Q[seq_idx][head_idx[HEAD_BITS-1:0]] * K[seq_idx2][head_idx[HEAD_BITS-1:0]]);
                    end

                    if (head_idx == 4'(HEAD_DIM - 1)) begin
                        if (seq_idx2 <= seq_idx) begin
                            reg signed [31:0] scaled_score;
                            scaled_score = (accumulator >>> 2) + (accumulator >>> 4);

                            if (scaled_score > 32767) attention_scores[seq_idx][seq_idx2] <= 16'h7FFF;
                            else if (scaled_score < -32768) attention_scores[seq_idx][seq_idx2] <= 16'h8000;
                            else attention_scores[seq_idx][seq_idx2] <= scaled_score[15:0];
                        end else begin
                            attention_scores[seq_idx][seq_idx2] <= -16'h4000;
                        end

                        head_idx <= 0;
                        accumulator <= 0;

                        if (seq_idx2 == 3'(SEQ_LEN - 1)) begin
                            seq_idx2 <= 0;
                            if (seq_idx == 3'(SEQ_LEN - 1)) begin
                                state <= SOFTMAX;
                                softmax_start <= 1;
                            end else begin
                                seq_idx <= seq_idx + 1;
                            end
                        end else begin
                            seq_idx2 <= seq_idx2 + 1;
                        end
                    end else begin
                        head_idx <= head_idx + 1;
                    end
                end

                SOFTMAX: begin
                    if (softmax_done) begin
                        state <= APPLY_ATTENTION;
                        seq_idx <= 0;
                        seq_idx2 <= 0;
                        head_idx <= 0;
                        accumulator <= 0;
                    end
                end

                APPLY_ATTENTION: begin
                    if (seq_idx2 == 0) begin
                        accumulator <= (attention_weights[seq_idx][seq_idx2] * V[seq_idx2][head_idx[HEAD_BITS-1:0]]);
                    end else begin
                        accumulator <= accumulator + (attention_weights[seq_idx][seq_idx2] * V[seq_idx2][head_idx[HEAD_BITS-1:0]]);
                    end

                    if (seq_idx2 == 3'(SEQ_LEN - 1)) begin
                        output_data[seq_idx][head_idx[HEAD_BITS-1:0]] <= 16'(accumulator >>> 12);
                        seq_idx2 <= 0;
                        accumulator <= 0;

                        if (head_idx == 4'(HEAD_DIM - 1)) begin
                            head_idx <= 0;
                            if (seq_idx == 3'(SEQ_LEN - 1)) begin
                                state <= COMPLETE;
                            end else begin
                                seq_idx <= seq_idx + 1;
                            end
                        end else begin
                            head_idx <= head_idx + 1;
                        end
                    end else begin
                        seq_idx2 <= seq_idx2 + 1;
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
