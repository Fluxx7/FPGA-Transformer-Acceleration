# =============================================================================
# stage_mem_files.tcl
#
# Pre-synthesis hook that stages the transformer weight .mem files into the
# current synthesis run directory so $readmemh("memory/<file>.mem", ...) calls
# in the RTL resolve at synth time.
#
# RTL paths use the literal prefix "memory/", which is relative to the
# synthesis working directory (the run dir under <proj>.runs/synth_*/). The
# .mem files live in the repo at <repo>/memory/, so we copy them into a
# matching "memory/" subdir of the run dir before synth_design runs.
#
# Install once on the Vivado run (from the Vivado Tcl Console):
#   set_property STEPS.SYNTH_DESIGN.TCL.PRE \
#       C:/MQP/FPGA-Transformer-Acceleration/Vivado/stage_mem_files.tcl \
#       [get_runs synth_1]
#
# (Re-run after `reset_run synth_1` if Vivado clears the property.)
# =============================================================================

# Locate the .mem source dir relative to this script so the hook is portable
# regardless of where the Vivado project lives.
set script_dir [file normalize [file dirname [info script]]]
set mem_src    [file normalize [file join $script_dir ".." "memory"]]

if {![file isdirectory $mem_src]} {
    puts "ERROR: stage_mem_files.tcl could not find memory dir at $mem_src"
    return -code error "memory source directory missing"
}

# The pre-synth hook executes with cwd == the run directory.
file mkdir memory
set staged 0
foreach f [glob -nocomplain -directory $mem_src *.mem] {
    file copy -force $f [file join "memory" [file tail $f]]
    incr staged
}
puts "stage_mem_files.tcl: staged $staged .mem files from $mem_src into [pwd]/memory"
