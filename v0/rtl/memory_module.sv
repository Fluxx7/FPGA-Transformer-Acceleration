`timescale 1ns/1ps

// ============================================================================
// MEMORY MODULE - OPTIMIZED FOR 16-BIT DATA
// ============================================================================
module memory_module #(
    parameter ADDR_WIDTH = 10,
    parameter DATA_WIDTH = 16,
    parameter DEPTH = 1024,
    parameter MEM_FILE = ""
)(
    input wire clk,
    input wire [ADDR_WIDTH-1:0] addr,
    output reg [DATA_WIDTH-1:0] data_out,
    input wire enable
);

    reg [DATA_WIDTH-1:0] memory [0:DEPTH-1];
    
    initial begin
        if (MEM_FILE != "") begin
            $readmemh(MEM_FILE, memory);
            $display("Loaded %s into memory", MEM_FILE);
        end else begin
            integer i;
            for (i = 0; i < DEPTH; i = i + 1) begin
                memory[i] = 0;
            end
            $display("Warning: No memory file specified for %m");
        end
    end
    
    always @(posedge clk) begin
        if (enable && 32'(addr) < DEPTH) begin
            data_out <= memory[addr];
        end else if (enable) begin
            data_out <= 0;
        end
    end

endmodule
