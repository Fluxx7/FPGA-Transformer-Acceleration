// ============================================================================
// VERIFICATION TESTBENCH - DUMPS HARDWARE LOGITS FOR COMPARISON
// ============================================================================
module transformer_decoder_testbench;

    parameter CLK_PERIOD = 10;

    reg clk, rst, start;
    reg [4:0] input_sequence [0:7];
    wire [4:0] predicted_token;
    wire done, valid;
    wire [31:0] cycle_count;
    wire [3:0] current_state_debug;

    // We need to access the final_logits inside the DUT for dumping
    // This uses a hierarchical reference, which is for simulation only.
    wire signed [15:0] final_logits [0:24];
    assign final_logits = dut.final_logits;
    
    complete_transformer_decoder dut (
        .clk(clk), .rst(rst), .start(start),
        .input_sequence(input_sequence), 
        .predicted_token(predicted_token),
        .done(done), .valid(valid),
        .cycle_count(cycle_count), 
        .current_state_debug(current_state_debug)
    );

    initial clk = 0;
    always #(CLK_PERIOD/2) clk = ~clk;

    initial begin
        // --- FIXED: Declarations moved to the top of the block ---
        integer file_handle;
        integer i;

        // Test: "START the cat" - matches the Python verification script
        input_sequence[0] = 1;  // START
        input_sequence[1] = 3;  // the
        input_sequence[2] = 5;  // cat
        input_sequence[3] = 0;  input_sequence[4] = 0;
        input_sequence[5] = 0;  input_sequence[6] = 0;  input_sequence[7] = 0;
        
        rst = 1;
        start = 0;
        #(CLK_PERIOD * 5);
        rst = 0;
        #(CLK_PERIOD * 2);
        
        start = 1;
        #CLK_PERIOD;
        start = 0;
        
        wait(done && valid);
        
        // --- This is the new, critical part for verification ---
        file_handle = $fopen("hardware_logits.txt", "w");
        if (file_handle) begin
            $display("\nVerification: Dumping final hardware logits to hardware_logits.txt");
            for (i = 0; i < 25; i = i + 1) begin
                // Write the value as a signed decimal integer
                $fdisplay(file_handle, "%d", final_logits[i]);
            end
            $fclose(file_handle);
            $display("Verification: Logit dump complete.");
        end else begin
            $display("Error: Could not open hardware_logits.txt for writing.");
        end
        // --- End of new part ---

        #(CLK_PERIOD * 10);
        $finish;
    end

endmodule