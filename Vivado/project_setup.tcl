# =============================================================================
# project_setup.tcl
#
# Idempotent project-side setup for the mqp_real Vivado project. Run once
# from the Vivado Tcl Console with the project open:
#
#   source C:/MQP/FPGA-Transformer-Acceleration/Vivado/project_setup.tcl
#
# Applies three things:
#   1. Installs the pre-synth hook that stages weight .mem files into the
#      synth_1 run dir (so $readmemh calls in the RTL resolve).
#   2. Disables the stale incremental-synthesis reference checkpoint
#      (complete_transformer_decoder.dcp), which was captured when the top
#      module was the decoder. The top is now the block-design wrapper, so
#      the old DCP can't be reused -- Vivado falls back to full synth and
#      emits CRITICAL Synth 8-6895 every run until this is cleared.
#   3. Suppresses Synth 8-7071 / 8-7023 warnings for the rst_ps7_0_50M
#      proc_sys_reset instance. That IP exposes five reset outputs; this
#      AXI-Lite design only needs peripheral_aresetn. The other four
#      (mb_reset, bus_struct_reset, peripheral_reset, interconnect_aresetn)
#      are intentionally unconnected and the IP has no knob to remove them.
# =============================================================================

set repo_vivado_dir [file normalize [file dirname [info script]]]

# -----------------------------------------------------------------------------
# 1) Pre-synth .mem staging hook
#
# The wrapper module (which contains the decoder and every $readmemh call)
# is synthesized out-of-context in its own run, NOT in synth_1. The OOC run
# is named like "<bd_name>_transformer_axi_wrap_*_synth_1". synth_1 only
# stitches the BD together and doesn't load any .mem files itself, but we
# still install the hook there so it works for any future non-OOC build.
# -----------------------------------------------------------------------------
set hook [file join $repo_vivado_dir "stage_mem_files.tcl"]
if {![file exists $hook]} {
    puts "WARNING: stage_mem_files.tcl missing at $hook -- skipping hook install"
} else {
    # Always install on synth_1.
    set runs_to_hook [list synth_1]

    # Also install on every OOC synth run for the transformer wrapper.
    foreach r [get_runs -quiet "*transformer_axi_wrap*synth_1"] {
        lappend runs_to_hook [get_property NAME $r]
    }

    foreach run_name $runs_to_hook {
        set r [get_runs -quiet $run_name]
        if {[llength $r] == 0} {
            puts "project_setup: run $run_name not found -- skipping"
            continue
        }
        set_property STEPS.SYNTH_DESIGN.TCL.PRE $hook $r
        puts "project_setup: installed pre-synth hook on $run_name -> $hook"
    }
}

# -----------------------------------------------------------------------------
# 2) Drop the stale incremental-synth reference checkpoint
#
# The CRITICAL Synth 8-6895 warning comes from the INCREMENTAL_CHECKPOINT path
# pointing at a DCP captured when the top was the decoder (now the top is the
# BD wrapper). Clearing that path is the actual fix.
#
# AUTO_INCREMENTAL_CHECKPOINT is a boolean, but different Vivado versions
# accept different value tokens (0/1, false/true, FALSE/TRUE) -- some reject
# Tcl's native "false" with a "bad lexical cast" error. Try them in order and
# fall back to reset_property.
# -----------------------------------------------------------------------------
set synth_run [get_runs synth_1]

# Always clear the stale reference path.
if {[catch {get_property INCREMENTAL_CHECKPOINT $synth_run} cur_ref]} {
    set cur_ref ""
}
if {$cur_ref ne ""} {
    if {[catch {reset_property INCREMENTAL_CHECKPOINT $synth_run} err]} {
        # Some Vivado versions don't allow reset on that property; try empty.
        catch {set_property INCREMENTAL_CHECKPOINT "" $synth_run}
    }
    puts "project_setup: cleared INCREMENTAL_CHECKPOINT (was: $cur_ref)"
} else {
    puts "project_setup: INCREMENTAL_CHECKPOINT already empty"
}

# Best-effort disable of auto-incremental tracking. Skip silently if the
# property doesn't exist or rejects every value form in this Vivado version.
set disabled 0
foreach val {0 FALSE false} {
    if {![catch {set_property AUTO_INCREMENTAL_CHECKPOINT $val $synth_run}]} {
        set disabled 1
        puts "project_setup: AUTO_INCREMENTAL_CHECKPOINT -> $val"
        break
    }
}
if {!$disabled} {
    if {![catch {reset_property AUTO_INCREMENTAL_CHECKPOINT $synth_run}]} {
        puts "project_setup: reset AUTO_INCREMENTAL_CHECKPOINT to default"
    } else {
        puts "project_setup: AUTO_INCREMENTAL_CHECKPOINT not settable here -- skipping (clearing the reference path above is what actually silences Synth 8-6895)"
    }
}

# -----------------------------------------------------------------------------
# 3) Suppress benign proc_sys_reset unconnected-output warnings
#
# These message rules persist with the project. The -string filter scopes
# the suppression to messages mentioning the specific instance, so other
# legitimate Synth 8-7071 / 8-7023 warnings still surface.
# -----------------------------------------------------------------------------
set_msg_config -id {Synth 8-7071} -string {rst_ps7_0_50M} -suppress
set_msg_config -id {Synth 8-7023} -string {rst_ps7_0_50M} -suppress
puts "project_setup: suppressed Synth 8-7071 / 8-7023 for rst_ps7_0_50M"

puts "project_setup: done. Now run: reset_run synth_1; launch_runs synth_1"
