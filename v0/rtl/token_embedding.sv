`timescale 1ns/1ps

// ============================================================================
// TOKEN EMBEDDING MODULE - SYNTHESIS FIXED
// ============================================================================
module token_embedding #(
    parameter EMBED_DIM = 64,
    parameter SEQ_LEN = 8
)(
    input wire clk,
    input wire rst,
    input wire start,
    input wire [5:0] input_tokens [0:SEQ_LEN-1],
    output reg signed [15:0] embedded_output [0:SEQ_LEN-1][0:EMBED_DIM-1],
    output reg done,
    output reg valid
);

    localparam IDLE = 0, PROCESSING = 1, COMPLETE = 2;
    localparam DIM_BITS = $clog2(EMBED_DIM);
    reg [1:0] state;
    reg [2:0] seq_idx;
    reg [DIM_BITS-1:0] dim_idx;
    reg [1:0] pipe_stage;
    
    wire [11:0] embed_addr;
    wire [15:0] embed_data;
    wire mem_enable;
    
    assign embed_addr = input_tokens[seq_idx] * EMBED_DIM + 12'(dim_idx);
    assign mem_enable = (state == PROCESSING);
    
    memory_module #(
        .ADDR_WIDTH(12),
        .DATA_WIDTH(16),
        .DEPTH(2560),
        .MEM_FILE("memory/embedding.mem")
    ) embedding_memory (
        .clk(clk), 
        .addr(embed_addr), 
        .data_out(embed_data), 
        .enable(mem_enable)
    );
    
    // Fixed: Initialize arrays in initial block, not in always block
    initial begin
        integer i, j;
        for (i = 0; i < SEQ_LEN; i = i + 1) begin
            for (j = 0; j < EMBED_DIM; j = j + 1) begin
                embedded_output[i][j] = 0;
            end
        end
    end
    
    always @(posedge clk) begin
        if (rst) begin
            state <= IDLE;
            seq_idx <= 0;
            dim_idx <= 0;
            pipe_stage <= 0;
            done <= 0;
            valid <= 0;
        end else begin
            case (state)
                IDLE: begin
                    done <= 0;
                    valid <= 0;
                    if (start) begin
                        state <= PROCESSING;
                        seq_idx <= 0;
                        dim_idx <= 0;
                        pipe_stage <= 0;
                    end
                end
                
                PROCESSING: begin
                    pipe_stage <= pipe_stage + 1;
                    
                    if (pipe_stage >= 2) begin
                        embedded_output[seq_idx][dim_idx] <= $signed(embed_data);
                        pipe_stage <= 0;
                        
                        if (dim_idx == DIM_BITS'(EMBED_DIM - 1)) begin
                            dim_idx <= 0;
                            if (seq_idx == 3'(SEQ_LEN - 1)) begin
                                state <= COMPLETE;
                            end else begin
                                seq_idx <= seq_idx + 1;
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
