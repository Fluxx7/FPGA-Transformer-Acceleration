`timescale 1ns/1ps

// ============================================================================
// LAYER NORMALIZATION - SYNTHESIS OPTIMIZED
// ============================================================================
module layer_normalization #(
    parameter SEQ_LEN = 8,
    parameter EMBED_DIM = 16,
    parameter GAMMA_FILE = "memory/layernorm1_gamma.mem",
    parameter BETA_FILE = "memory/layernorm1_beta.mem",
    parameter RSQRT_MEM = "memory/rsqrt_lut.mem"
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
               COMPUTE_VAR = 3, VAR_RSQRT_DELAY = 4, NORMALIZE = 5, COMPLETE = 6;
    localparam DIM_BITS = $clog2(EMBED_DIM);
    reg [2:0] state;

    reg [2:0] seq_idx;
    reg [DIM_BITS-1:0] dim_idx;
    reg signed [15:0] sum_data [0:SEQ_LEN-1][0:EMBED_DIM-1];
    reg signed [31:0] mean_acc;
    wire signed [31:0] next_mean_acc;
    reg signed [15:0] mean_val [0:SEQ_LEN-1];
    reg [1:0] pipe_stage;
   

    logic signed [16:0] temp_sum;
    reg signed [31:0] normalized, with_gamma, final_result;
    

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

    

    function automatic [4:0] leading_bit; 
        // note: 0 and 1 will both return 0
        // this is only used on var_lookup, which has an epsilon of 1 added to it so it's not a problem here
        input [31:0] x;
        integer i;
        begin
            leading_bit = 5'd0;
            for (i = 0; i < 32; i = i + 1) begin
                if (x[i] == 1'b1) leading_bit = i[4:0];
            end
        end
    endfunction


    // For COMPUTE_VAR
    logic signed [31:0] diff;
    logic signed [47:0] var_acc;
    reg [31:0] var_lookup;

    // For COMPUTE_VAR_RSQRT
    wire [4:0] k = leading_bit(var_lookup);
    wire [4:0] n_even = {k[4:1], 1'b0};
    /* verilator lint_off UNUSEDSIGNAL */
    wire [31:0] m_shift =   ((n_even >= 5'd4) 
                            ? (var_lookup >> (n_even - 6'd4))
                            : (var_lookup << (6'd4 - n_even)));
    wire [5:0] rsqrt_index = m_shift[5:0];
    /* verilator lint_on UNUSEDSIGNAL */
    wire [15:0] rsqrt_var;
    wire signed [31:0] rsqrt_signed = $signed({16'b0, rsqrt_var});

    memory_module #(
        .ADDR_WIDTH(6), .DATA_WIDTH(16), .DEPTH(64), .MEM_FILE(RSQRT_MEM)
    ) rsqrt_rom (
        .clk(clk), .addr(rsqrt_index), .data_out(rsqrt_var), .enable(state == VAR_RSQRT_DELAY)
    );

    // Fixed: Initialize arrays in initial block
    initial begin
        integer i, j;
        for (i = 0; i < SEQ_LEN; i = i + 1) begin
            mean_val[i] = 0;
            for (j = 0; j < EMBED_DIM; j = j + 1) begin
                sum_data[i][j] = 0;
                output_data[i][j] = 0;
            end
        end
    end

    // Using wires for intermediate values to avoid off-by-one errors
    assign temp_sum = input_data[seq_idx][dim_idx] + residual_data[seq_idx][dim_idx];
    assign next_mean_acc = mean_acc + 32'(sum_data[seq_idx][dim_idx]);
    assign diff = 32'(sum_data[seq_idx][dim_idx]) - 32'(mean_val[seq_idx]);

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

            normalized <= 0;
            with_gamma <= 0;
            final_result <= 0;
            var_lookup <= 0;
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
                    if (dim_idx == DIM_BITS'(EMBED_DIM - 1)) begin
                        mean_val[seq_idx] <= 16'(next_mean_acc >>> DIM_BITS);
                        dim_idx <= 0;
                        var_acc <= 0;
                        state <= COMPUTE_VAR;
                    end else begin
                        mean_acc <= next_mean_acc;
                        dim_idx <= dim_idx + 1;
                    end
                end

                COMPUTE_VAR: begin
                    if (dim_idx == DIM_BITS'(EMBED_DIM - 1)) begin
                        var_lookup <= 32'((var_acc + (diff * diff)) >>> (DIM_BITS + 8)) + 1;
                        dim_idx <= 0;
                        pipe_stage <= 0;
                        state <= VAR_RSQRT_DELAY;
                    end else begin
                        var_acc <= var_acc + (diff * diff);
                        dim_idx <= dim_idx + 1;
                    end
                end

                VAR_RSQRT_DELAY: begin // one cycle delay for mem read to update
                    state <= NORMALIZE;
                end



                NORMALIZE: begin
                    pipe_stage <= pipe_stage + 1;

                    case (pipe_stage)
                        0: normalized <= ((32'(sum_data[seq_idx][dim_idx]) - 32'(mean_val[seq_idx]))  * rsqrt_signed) >>> (11 + k[4:1]);
                        1: with_gamma <= (normalized * $signed(gamma_data)) >>> 8;
                        2: final_result <= with_gamma + 32'($signed(beta_data));
                        3: begin
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
                    endcase
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
