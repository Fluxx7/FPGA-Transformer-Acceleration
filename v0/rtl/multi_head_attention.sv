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
    localparam DIM_BITS      = $clog2(EMBED_DIM);
    localparam HEAD_BITS     = $clog2(HEAD_DIM);
    localparam SEQ_BITS      = $clog2(SEQ_LEN);        // [Claude]
    localparam HEAD_NUM_BITS = $clog2(NUM_HEADS);       // [Claude]
    localparam WO_ADDR_BITS  = 2 * DIM_BITS;           // [Claude] avoids computed-param casts in assign
    reg [2:0] state;

    reg [NUM_HEADS-1:0] head_start_signals;
    wire [NUM_HEADS-1:0] head_done_signals;
    wire [NUM_HEADS-1:0] head_valid_signals;
    wire signed [15:0] head_outputs [0:NUM_HEADS-1][0:SEQ_LEN-1][0:HEAD_DIM-1];

    reg signed [15:0] concatenated [0:SEQ_LEN-1][0:EMBED_DIM-1];

    reg [SEQ_BITS-1:0] seq_idx;     // [Claude] was [2:0], hardcoded for SEQ_LEN=8
    reg [DIM_BITS-1:0] dim_idx, in_dim, out_dim;
    reg [2:0] pipe_stage;
    reg signed [31:0] proj_accumulator;

    wire [2*DIM_BITS-1:0] wo_addr;
    wire [15:0] wo_data;
    wire mem_enable_wo;

    assign wo_addr = WO_ADDR_BITS'(in_dim) * WO_ADDR_BITS'(EMBED_DIM) + WO_ADDR_BITS'(out_dim); // [Claude]
    assign mem_enable_wo = (state == OUTPUT_PROJ);

    memory_module #(
        .ADDR_WIDTH(2*DIM_BITS),
        .DATA_WIDTH(16),
        .DEPTH(EMBED_DIM*EMBED_DIM),
        .MEM_FILE("memory/attention_wo.mem")
    ) wo_memory (
        .clk(clk),
        .addr(wo_addr),
        .data_out(wo_data),
        .enable(mem_enable_wo)
    );

    genvar head_num;
    generate 
        for (head_num = 0; head_num < NUM_HEADS; head_num++) begin
            attention_head #(
                    .SEQ_LEN(SEQ_LEN), .EMBED_DIM(EMBED_DIM), .HEAD_DIM(HEAD_DIM),
                    .WQ_FILE($sformatf("memory/attention_wq_head%0d.mem", head_num)), .WK_FILE($sformatf("memory/attention_wk_head%0d.mem", head_num)), .WV_FILE($sformatf("memory/attention_wv_head%0d.mem", head_num))
                ) head (.clk(clk), .rst(rst), .start(head_start_signals[head_num]), .input_data(input_data),
            .output_data(head_outputs[head_num]), .done(head_done_signals[head_num]), .valid(head_valid_signals[head_num]));
        end
    endgenerate

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
                        head_start_signals <= {NUM_HEADS{1'b1}}; // [Claude] was 255, hardcoded for 8 heads
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
                    begin // [Claude] bit-selects replace div/mod; avoids width warnings and is synthesis-friendly
                        reg [HEAD_NUM_BITS-1:0] head_id;
                        reg [HEAD_BITS-1:0] local_dim;
                        head_id = HEAD_NUM_BITS'(dim_idx[DIM_BITS-1:HEAD_BITS]);   // upper bits = which head
                        local_dim = dim_idx[HEAD_BITS-1:0];          // lower bits = offset within head
                        concatenated[seq_idx][dim_idx] <= head_outputs[head_id][seq_idx][local_dim];
                    end

                    if (dim_idx == DIM_BITS'(EMBED_DIM - 1)) begin
                        dim_idx <= 0;
                        if (seq_idx == SEQ_BITS'(SEQ_LEN - 1)) begin
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

                        if (in_dim == DIM_BITS'(EMBED_DIM - 1)) begin
                            output_data[seq_idx][out_dim] <= 16'(proj_accumulator >>> 8);
                            proj_accumulator <= 0;
                            in_dim <= 0;

                            if (out_dim == DIM_BITS'(EMBED_DIM - 1)) begin
                                out_dim <= 0;
                                if (seq_idx == SEQ_BITS'(SEQ_LEN - 1)) begin
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
