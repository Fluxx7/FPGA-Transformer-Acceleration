`timescale 1ns/1ps

// ============================================================================
// OUTPUT PROJECTION MODULE - SYNTHESIS OPTIMIZED
// ============================================================================
module output_projection #(
    parameter VOCAB_SIZE = 40,
    parameter EMBED_DIM = 64
)(
    input wire clk,
    input wire rst,
    input wire start,
    input wire signed [15:0] final_hidden_state [0:EMBED_DIM-1],
    output reg signed [15:0] vocabulary_logits [0:VOCAB_SIZE-1],
    output reg done,
    output reg valid
);

    localparam IDLE = 0, COMPUTE = 1, COMPLETE = 2;
    localparam DIM_BITS = $clog2(EMBED_DIM);
    localparam VOCAB_BITS = $clog2(VOCAB_SIZE);
    reg [1:0] state;

    reg [VOCAB_BITS-1:0] vocab_idx;
    reg [DIM_BITS-1:0] dim_idx;
    reg signed [31:0] logit_accumulator;
    reg [2:0] pipe_stage;
    
    wire [11:0] proj_addr;
    wire [15:0] proj_data;
    wire mem_enable;
    
    assign proj_addr = 12'(dim_idx * VOCAB_SIZE + vocab_idx);
    assign mem_enable = (state == COMPUTE);
    
    memory_module #(
        .ADDR_WIDTH(12),
        .DATA_WIDTH(16),
        .DEPTH(2560),
        .MEM_FILE("memory/output_proj.mem")
    ) proj_memory (
        .clk(clk), 
        .addr(proj_addr), 
        .data_out(proj_data), 
        .enable(mem_enable)
    );
    
    // Fixed: Initialize arrays in initial block
    initial begin
        integer i;
        for (i = 0; i < VOCAB_SIZE; i = i + 1) begin
            vocabulary_logits[i] = 0;
        end
    end
    
    always @(posedge clk) begin
        if (rst) begin
            state <= IDLE;
            vocab_idx <= 0;
            dim_idx <= 0;
            logit_accumulator <= 0;
            pipe_stage <= 0;
            done <= 0;
            valid <= 0;
        end else begin
            case (state)
                IDLE: begin
                    done <= 0;
                    valid <= 0;
                    if (start) begin
                        state <= COMPUTE;
                        vocab_idx <= 0;
                        dim_idx <= 0;
                        logit_accumulator <= 0;
                        pipe_stage <= 0;
                    end
                end
                
                COMPUTE: begin
                    pipe_stage <= pipe_stage + 1;

                    if (pipe_stage >= 2) begin
                        pipe_stage <= 0;

                        if (dim_idx == DIM_BITS'(EMBED_DIM - 1)) begin
                            // Final iteration: fold this product into the stored result
                            // so the last element of final_hidden_state isn't optimized away.
                            vocabulary_logits[vocab_idx] <= 16'((logit_accumulator +
                                (final_hidden_state[dim_idx] * $signed(proj_data))) >>> 8);
                            logit_accumulator <= 0;
                            dim_idx <= 0;

                            if (vocab_idx == VOCAB_BITS'(VOCAB_SIZE - 1)) begin
                                state <= COMPLETE;
                            end else begin
                                vocab_idx <= vocab_idx + 1;
                            end
                        end else begin
                            logit_accumulator <= logit_accumulator +
                                (final_hidden_state[dim_idx] * $signed(proj_data));
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
