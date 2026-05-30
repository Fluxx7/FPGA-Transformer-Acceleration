`timescale 1ns/1ps

// ============================================================================
// COMPLETE TRANSFORMER DECODER - SYNTHESIS READY
// ============================================================================
module complete_transformer_decoder #(
    parameter VOCAB_SIZE = 40,
    parameter EMBED_DIM = 16, // must be power of 2
    parameter SEQ_LEN = 8,
    parameter NUM_HEADS = 4,
    parameter FFN_DIM = 128
)(
    input wire clk,
    input wire rst,
    input wire start,
    input wire [SEQ_LEN*6-1:0] input_sequence_flat,
    output reg [$clog2(VOCAB_SIZE)-1:0] predicted_token,
    output reg done,
    output reg valid,
    output reg [31:0] cycle_count,
    output wire [3:0] current_state_debug
);

    localparam IDLE = 0, EMBEDDING = 1, POSITIONAL = 2, ATTENTION = 3,
               LAYER_NORM1 = 4, FEED_FORWARD = 5, LAYER_NORM2 = 6,
               OUTPUT_PROJ = 7, ARGMAX = 8, FINISHED = 9;
    reg [3:0] current_state;
    
    // Unpack flat input into internal SV unpacked array
    wire [5:0] input_sequence [0:SEQ_LEN-1];
    genvar gi;
    generate
        for (gi = 0; gi < SEQ_LEN; gi = gi + 1) begin : unpack_seq
            assign input_sequence[gi] = input_sequence_flat[gi*6 +: 6];
        end
    endgenerate
    
    assign current_state_debug = current_state;
    
    // Data flow arrays
    reg signed [15:0] embedded_tokens [0:SEQ_LEN-1][0:EMBED_DIM-1];
    reg signed [15:0] position_encoded [0:SEQ_LEN-1][0:EMBED_DIM-1];
    reg signed [15:0] attention_out [0:SEQ_LEN-1][0:EMBED_DIM-1];
    reg signed [15:0] norm1_out [0:SEQ_LEN-1][0:EMBED_DIM-1];
    reg signed [15:0] ffn_out [0:SEQ_LEN-1][0:EMBED_DIM-1];
    reg signed [15:0] norm2_out [0:SEQ_LEN-1][0:EMBED_DIM-1];
    reg signed [15:0] final_logits [0:VOCAB_SIZE-1];
    
    // Control signals
    reg embed_start, pos_start, attn_start, norm1_start, ffn_start, norm2_start, proj_start, argmax_start;
    wire embed_done, pos_done, attn_done, norm1_done, ffn_done, norm2_done, proj_done, argmax_done;
    wire embed_valid, pos_valid, attn_valid, norm1_valid, ffn_valid, norm2_valid, proj_valid, argmax_valid;
    
    // Find last non-zero token position
    reg [2:0] last_pos;
    integer k;
    always @(*) begin
        last_pos = 0;
        for (k = 0; k < SEQ_LEN; k = k + 1) begin
            if (input_sequence[k] != 0) last_pos = 3'(k);
        end
    end
    
    // Module instantiations
    token_embedding #(
        .EMBED_DIM(EMBED_DIM), 
        .SEQ_LEN(SEQ_LEN)
    ) embedding_inst (
        .clk(clk), .rst(rst), .start(embed_start),
        .input_tokens(input_sequence), 
        .embedded_output(embedded_tokens), 
        .done(embed_done), .valid(embed_valid)
    );

    positional_encoding #(
        .EMBED_DIM(EMBED_DIM), 
        .SEQ_LEN(SEQ_LEN)
    ) positional_inst (
        .clk(clk), .rst(rst), .start(pos_start),
        .embedded_input(embedded_tokens), 
        .position_encoded_output(position_encoded), 
        .done(pos_done), .valid(pos_valid)
    );

    multi_head_attention #(
        .NUM_HEADS(NUM_HEADS), 
        .EMBED_DIM(EMBED_DIM), 
        .SEQ_LEN(SEQ_LEN)
    ) attention_inst (
        .clk(clk), .rst(rst), .start(attn_start),
        .input_data(position_encoded), 
        .output_data(attention_out), 
        .done(attn_done), .valid(attn_valid)
    );

    layer_normalization #(
        .EMBED_DIM(EMBED_DIM), 
        .SEQ_LEN(SEQ_LEN),
        .GAMMA_FILE("memory/layernorm1_gamma.mem"),
        .BETA_FILE("memory/layernorm1_beta.mem")
    ) layer_norm1_inst (
        .clk(clk), .rst(rst), .start(norm1_start),
        .input_data(attention_out), 
        .residual_data(position_encoded), 
        .output_data(norm1_out), 
        .done(norm1_done), .valid(norm1_valid)
    );

    feed_forward_network #(
        .EMBED_DIM(EMBED_DIM), 
        .SEQ_LEN(SEQ_LEN),
        .FFN_DIM(FFN_DIM)
    ) ffn_inst (
        .clk(clk), .rst(rst), .start(ffn_start),
        .input_data(norm1_out), 
        .output_data(ffn_out), 
        .done(ffn_done), .valid(ffn_valid)
    );

    layer_normalization #(
        .EMBED_DIM(EMBED_DIM), 
        .SEQ_LEN(SEQ_LEN),
        .GAMMA_FILE("memory/layernorm2_gamma.mem"),
        .BETA_FILE("memory/layernorm2_beta.mem")
    ) layer_norm2_inst (
        .clk(clk), .rst(rst), .start(norm2_start),
        .input_data(ffn_out), 
        .residual_data(norm1_out), 
        .output_data(norm2_out), 
        .done(norm2_done), .valid(norm2_valid)
    );

    output_projection #(
        .EMBED_DIM(EMBED_DIM), 
        .VOCAB_SIZE(VOCAB_SIZE)
    ) projection_inst (
        .clk(clk), .rst(rst), .start(proj_start),
        .final_hidden_state(norm2_out[last_pos]), 
        .vocabulary_logits(final_logits), 
        .done(proj_done), .valid(proj_valid)
    );

    argmax #(
        .VOCAB_SIZE(VOCAB_SIZE)
    ) argmax_inst (
        .clk(clk), .rst(rst), .start(argmax_start),
        .input_logits(final_logits), 
        .selected_token(predicted_token), 
        .done(argmax_done), .valid(argmax_valid)
    );

    // Cycle counter
    always @(posedge clk) begin
        if (rst) begin
            cycle_count <= 0;
        end else begin
            cycle_count <= cycle_count + 1;
        end
    end

    // Fixed: Initialize arrays in initial block
    initial begin
        integer i, j;
        for (i = 0; i < SEQ_LEN; i = i + 1) begin
            for (j = 0; j < EMBED_DIM; j = j + 1) begin
                embedded_tokens[i][j] = 16'h0;
                position_encoded[i][j] = 16'h0;
                attention_out[i][j] = 16'h0;
                norm1_out[i][j] = 16'h0;
                ffn_out[i][j] = 16'h0;
                norm2_out[i][j] = 16'h0;
            end
        end
        for (j = 0; j < VOCAB_SIZE; j = j + 1) begin
            final_logits[j] = 16'h0;
        end
    end

    // Main control FSM
    always @(posedge clk) begin
        if (rst) begin
            current_state <= IDLE;
            done <= 0;
            valid <= 0;
            
            {embed_start, pos_start, attn_start, norm1_start, 
             ffn_start, norm2_start, proj_start, argmax_start} <= 8'b0;
        end else begin
            {embed_start, pos_start, attn_start, norm1_start, 
             ffn_start, norm2_start, proj_start, argmax_start} <= 8'b0;
            
            case (current_state)
                IDLE: begin
                    done <= 0;
                    valid <= 0;
                    if (start) begin
                        current_state <= EMBEDDING;
                        embed_start <= 1;
                    end
                end

                EMBEDDING: begin
                    if (embed_done && embed_valid) begin
                        current_state <= POSITIONAL;
                        pos_start <= 1;
                    end
                end

                POSITIONAL: begin
                    if (pos_done && pos_valid) begin
                        current_state <= ATTENTION;
                        attn_start <= 1;
                    end
                end

                ATTENTION: begin
                    if (attn_done && attn_valid) begin
                        current_state <= LAYER_NORM1;
                        norm1_start <= 1;
                    end
                end

                LAYER_NORM1: begin
                    if (norm1_done && norm1_valid) begin
                        current_state <= FEED_FORWARD;
                        ffn_start <= 1;
                    end
                end

                FEED_FORWARD: begin
                    if (ffn_done && ffn_valid) begin
                        current_state <= LAYER_NORM2;
                        norm2_start <= 1;
                    end
                end

                LAYER_NORM2: begin
                    if (norm2_done && norm2_valid) begin
                        current_state <= OUTPUT_PROJ;
                        proj_start <= 1;
                    end
                end

                OUTPUT_PROJ: begin
                    if (proj_done && proj_valid) begin
                        current_state <= ARGMAX;
                        argmax_start <= 1;
                    end
                end

                ARGMAX: begin
                    if (argmax_done && argmax_valid) begin
                        current_state <= FINISHED;
                    end
                end

                FINISHED: begin
                    done <= 1;
                    valid <= 1;
                    if (!start) begin
                        current_state <= IDLE;
                    end
                end
            endcase
        end
    end

endmodule

 
