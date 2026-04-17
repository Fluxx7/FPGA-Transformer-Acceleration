`timescale 1ns/1ps

// ============================================================================
// MULTI-HEAD ATTENTION - SYNTHESIS OPTIMIZED
// ============================================================================
module multi_head_attention #(
    parameter SEQ_LEN = 8,
    parameter EMBED_DIM = 64,
    parameter NUM_HEADS = 8,
    parameter HEAD_DIM = 8
)(
    input wire clk,
    input wire rst,
    input wire start,
    input wire signed [15:0] input_data [0:SEQ_LEN-1][0:EMBED_DIM-1],
    output reg signed [15:0] output_data [0:SEQ_LEN-1][0:EMBED_DIM-1],
    output reg done,
    output reg valid
);

    localparam IDLE = 0, PROCESS_HEADS = 1, CONCAT_OUTPUT = 2, OUTPUT_PROJ = 3, COMPLETE = 4;
    reg [2:0] state;

    reg [NUM_HEADS-1:0] head_start_signals;
    wire [NUM_HEADS-1:0] head_done_signals;
    wire [NUM_HEADS-1:0] head_valid_signals;
    wire signed [15:0] head_outputs [0:NUM_HEADS-1][0:SEQ_LEN-1][0:HEAD_DIM-1];

    reg signed [15:0] concatenated [0:SEQ_LEN-1][0:EMBED_DIM-1];

    reg [2:0] seq_idx;
    reg [5:0] dim_idx, in_dim, out_dim;
    reg [2:0] pipe_stage;
    reg signed [31:0] proj_accumulator;

    wire [11:0] wo_addr;
    wire [15:0] wo_data;
    wire mem_enable_wo;

    assign wo_addr = in_dim * EMBED_DIM + 12'(out_dim);
    assign mem_enable_wo = (state == OUTPUT_PROJ);

    memory_module #(
        .ADDR_WIDTH(12),
        .DATA_WIDTH(16),
        .DEPTH(4096),
        .MEM_FILE("memory/attention_wo.mem")
    ) wo_memory (
        .clk(clk),
        .addr(wo_addr),
        .data_out(wo_data),
        .enable(mem_enable_wo)
    );

    // All 8 attention heads with correct memory files
    attention_head #(
        .SEQ_LEN(SEQ_LEN), .EMBED_DIM(EMBED_DIM), .HEAD_DIM(HEAD_DIM),
        .WQ_FILE("memory/attention_wq_head0.mem"), .WK_FILE("memory/attention_wk_head0.mem"), .WV_FILE("memory/attention_wv_head0.mem")
    ) head0 (.clk(clk), .rst(rst), .start(head_start_signals[0]), .input_data(input_data),
            .output_data(head_outputs[0]), .done(head_done_signals[0]), .valid(head_valid_signals[0]));

    attention_head #(
        .SEQ_LEN(SEQ_LEN), .EMBED_DIM(EMBED_DIM), .HEAD_DIM(HEAD_DIM),
        .WQ_FILE("memory/attention_wq_head1.mem"), .WK_FILE("memory/attention_wk_head1.mem"), .WV_FILE("memory/attention_wv_head1.mem")
    ) head1 (.clk(clk), .rst(rst), .start(head_start_signals[1]), .input_data(input_data),
            .output_data(head_outputs[1]), .done(head_done_signals[1]), .valid(head_valid_signals[1]));

    attention_head #(
        .SEQ_LEN(SEQ_LEN), .EMBED_DIM(EMBED_DIM), .HEAD_DIM(HEAD_DIM),
        .WQ_FILE("memory/attention_wq_head2.mem"), .WK_FILE("memory/attention_wk_head2.mem"), .WV_FILE("memory/attention_wv_head2.mem")
    ) head2 (.clk(clk), .rst(rst), .start(head_start_signals[2]), .input_data(input_data),
            .output_data(head_outputs[2]), .done(head_done_signals[2]), .valid(head_valid_signals[2]));

    attention_head #(
        .SEQ_LEN(SEQ_LEN), .EMBED_DIM(EMBED_DIM), .HEAD_DIM(HEAD_DIM),
        .WQ_FILE("memory/attention_wq_head3.mem"), .WK_FILE("memory/attention_wk_head3.mem"), .WV_FILE("memory/attention_wv_head3.mem")
    ) head3 (.clk(clk), .rst(rst), .start(head_start_signals[3]), .input_data(input_data),
            .output_data(head_outputs[3]), .done(head_done_signals[3]), .valid(head_valid_signals[3]));

    attention_head #(
        .SEQ_LEN(SEQ_LEN), .EMBED_DIM(EMBED_DIM), .HEAD_DIM(HEAD_DIM),
        .WQ_FILE("memory/attention_wq_head4.mem"), .WK_FILE("memory/attention_wk_head4.mem"), .WV_FILE("memory/attention_wv_head4.mem")
    ) head4 (.clk(clk), .rst(rst), .start(head_start_signals[4]), .input_data(input_data),
            .output_data(head_outputs[4]), .done(head_done_signals[4]), .valid(head_valid_signals[4]));

    attention_head #(
        .SEQ_LEN(SEQ_LEN), .EMBED_DIM(EMBED_DIM), .HEAD_DIM(HEAD_DIM),
        .WQ_FILE("memory/attention_wq_head5.mem"), .WK_FILE("memory/attention_wk_head5.mem"), .WV_FILE("memory/attention_wv_head5.mem")
    ) head5 (.clk(clk), .rst(rst), .start(head_start_signals[5]), .input_data(input_data),
            .output_data(head_outputs[5]), .done(head_done_signals[5]), .valid(head_valid_signals[5]));

    attention_head #(
        .SEQ_LEN(SEQ_LEN), .EMBED_DIM(EMBED_DIM), .HEAD_DIM(HEAD_DIM),
        .WQ_FILE("memory/attention_wq_head6.mem"), .WK_FILE("memory/attention_wk_head6.mem"), .WV_FILE("memory/attention_wv_head6.mem")
    ) head6 (.clk(clk), .rst(rst), .start(head_start_signals[6]), .input_data(input_data),
            .output_data(head_outputs[6]), .done(head_done_signals[6]), .valid(head_valid_signals[6]));

    attention_head #(
        .SEQ_LEN(SEQ_LEN), .EMBED_DIM(EMBED_DIM), .HEAD_DIM(HEAD_DIM),
        .WQ_FILE("memory/attention_wq_head7.mem"), .WK_FILE("memory/attention_wk_head7.mem"), .WV_FILE("memory/attention_wv_head7.mem")
    ) head7 (.clk(clk), .rst(rst), .start(head_start_signals[7]), .input_data(input_data),
            .output_data(head_outputs[7]), .done(head_done_signals[7]), .valid(head_valid_signals[7]));

    // Fixed: Initialize arrays in initial block
    initial begin
        integer i, j;
        for (i = 0; i < SEQ_LEN; i = i + 1) begin
            for (j = 0; j < EMBED_DIM; j = j + 1) begin
                concatenated[i][j] = 0;
                output_data[i][j] = 0;
            end
        end
    end

    always @(posedge clk) begin
        if (rst) begin
            state <= IDLE;
            head_start_signals <= 0;
            seq_idx <= 0;
            dim_idx <= 0;
            in_dim <= 0;
            out_dim <= 0;
            pipe_stage <= 0;
            proj_accumulator <= 0;
            done <= 0;
            valid <= 0;
        end else begin
            case (state)
                IDLE: begin
                    done <= 0;
                    valid <= 0;
                    head_start_signals <= 0;
                    if (start) begin
                        state <= PROCESS_HEADS;
                        head_start_signals <= {NUM_HEADS{1'b1}};
                    end
                end

                PROCESS_HEADS: begin
                    head_start_signals <= 0;
                    if (&head_done_signals && (&head_valid_signals)) begin
                        state <= CONCAT_OUTPUT;
                        seq_idx <= 0;
                        dim_idx <= 0;
                    end
                end

                CONCAT_OUTPUT: begin
                    if (dim_idx < HEAD_DIM * NUM_HEADS) begin
                        reg [2:0] head_id;
                        reg [2:0] local_dim;
                        head_id = 3'(dim_idx / HEAD_DIM);
                        local_dim = 3'(dim_idx % HEAD_DIM);
                        concatenated[seq_idx][dim_idx] <= head_outputs[head_id][seq_idx][local_dim];
                    end else begin
                        concatenated[seq_idx][dim_idx] <= 16'h0;
                    end

                    if (dim_idx == 6'(EMBED_DIM - 1)) begin
                        dim_idx <= 0;
                        if (seq_idx == 3'(SEQ_LEN - 1)) begin
                            state <= OUTPUT_PROJ;
                            seq_idx <= 0;
                            in_dim <= 0;
                            out_dim <= 0;
                            pipe_stage <= 0;
                            proj_accumulator <= 0;
                        end else begin
                            seq_idx <= seq_idx + 1;
                        end
                    end else begin
                        dim_idx <= dim_idx + 1;
                    end
                end

                OUTPUT_PROJ: begin
                    pipe_stage <= pipe_stage + 1;

                    if (pipe_stage >= 2) begin
                        proj_accumulator <= proj_accumulator +
                            (concatenated[seq_idx][in_dim] * $signed(wo_data));
                        pipe_stage <= 0;

                        if (in_dim == 6'(EMBED_DIM - 1)) begin
                            output_data[seq_idx][out_dim] <= 16'(proj_accumulator >>> 8);
                            proj_accumulator <= 0;
                            in_dim <= 0;

                            if (out_dim == 6'(EMBED_DIM - 1)) begin
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
                            in_dim <= in_dim + 1;
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
