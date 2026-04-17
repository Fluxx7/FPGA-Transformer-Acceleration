`timescale 1ns/1ps

// ============================================================================
// POSITIONAL ENCODING MODULE - SYNTHESIS FIXED
// ============================================================================
module positional_encoding #(
    parameter SEQ_LEN = 8,
    parameter EMBED_DIM = 64
)(
    input wire clk,
    input wire rst,
    input wire start,
    input wire signed [15:0] embedded_input [0:SEQ_LEN-1][0:EMBED_DIM-1],
    output reg signed [15:0] position_encoded_output [0:SEQ_LEN-1][0:EMBED_DIM-1],
    output reg done,
    output reg valid
);

    localparam IDLE = 0, PROCESSING = 1, COMPLETE = 2;
    reg [1:0] state;
    reg [2:0] seq_idx;
    reg [5:0] dim_idx;
    reg [1:0] pipe_stage;
    
    wire [8:0] pos_addr;
    wire [15:0] pos_data;
    wire mem_enable;
    reg signed [16:0] temp_sum;
    
    assign pos_addr = seq_idx * EMBED_DIM + 9'(dim_idx);
    assign mem_enable = (state == PROCESSING);
    
    memory_module #(
        .ADDR_WIDTH(9), 
        .DATA_WIDTH(16), 
        .DEPTH(512), 
        .MEM_FILE("memory/positional_encoding.mem")
    ) pos_memory (
        .clk(clk), 
        .addr(pos_addr), 
        .data_out(pos_data), 
        .enable(mem_enable)
    );
    
    // Fixed: Initialize arrays in initial block
    initial begin
        integer i, j;
        for (i = 0; i < SEQ_LEN; i = i + 1) begin
            for (j = 0; j < EMBED_DIM; j = j + 1) begin
                position_encoded_output[i][j] = 0;
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
            temp_sum <= 0;
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
                        temp_sum <= embedded_input[seq_idx][dim_idx] + $signed(pos_data);
                        
                        if (temp_sum > 32767) 
                            position_encoded_output[seq_idx][dim_idx] <= 16'h7FFF;
                        else if (temp_sum < -32768) 
                            position_encoded_output[seq_idx][dim_idx] <= 16'h8000;
                        else 
                            position_encoded_output[seq_idx][dim_idx] <= temp_sum[15:0];
                        
                        pipe_stage <= 0;
                        
                        if (dim_idx == 6'(EMBED_DIM - 1)) begin
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
