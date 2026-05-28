`timescale 1ns/1ps

// ============================================================================
// ARGMAX MODULE - SYNTHESIS READY
// ============================================================================
module argmax #(
    parameter VOCAB_SIZE = 40
)(
    input wire clk,
    input wire rst,
    input wire start,
    input wire signed [15:0] input_logits [0:VOCAB_SIZE-1],
    output reg [$clog2(VOCAB_SIZE)-1:0] selected_token,
    output reg done,
    output reg valid
);

    localparam int IDX_BITS = $clog2(VOCAB_SIZE);
    localparam IDLE = 0, COMPARE = 1, COMPLETE = 2;
    reg [1:0] state;

    reg [IDX_BITS-1:0] current_idx;
    reg signed [15:0] max_value;
    reg [IDX_BITS-1:0] max_index;
    
    always @(posedge clk) begin
        if (rst) begin
            state <= IDLE;
            current_idx <= 0;
            max_value <= -16'h8000;
            max_index <= 0;
            selected_token <= 0;
            done <= 0;
            valid <= 0;
        end else begin
            case (state)
                IDLE: begin
                    done <= 0;
                    valid <= 0;
                    if (start) begin
                        state <= COMPARE;
                        current_idx <= 0;
                        max_value <= input_logits[0];
                        max_index <= 0;
                    end
                end
                
                COMPARE: begin
                    if (input_logits[current_idx] > max_value) begin
                        max_value <= input_logits[current_idx];
                        max_index <= current_idx;
                    end
                    
                    if (current_idx == IDX_BITS'(VOCAB_SIZE - 1)) begin
                        selected_token <= max_index;
                        state <= COMPLETE;
                    end else begin
                        current_idx <= current_idx + 1;
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
