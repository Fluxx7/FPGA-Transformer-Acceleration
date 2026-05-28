# =============================================================================
# build_sim.ps1 -- PowerShell equivalent of v0/Makefile's `verilate` target.
#
# Builds the Verilator simulation of complete_transformer_decoder. Run from
# the v0/ directory:
#
#     pwsh -File .\build_sim.ps1
#   or, if pwsh is your default shell:
#     .\build_sim.ps1
#
# Requires verilator + a C++17-capable g++ on PATH. The output binary lands at
# obj_dir\Vcomplete_transformer_decoder(.exe).
# =============================================================================

$ErrorActionPreference = "Stop"

$TopModule = "complete_transformer_decoder"
$RtlDir    = "rtl"
$SimCpp    = "sim\cpp\sim_main.cpp"
$ObjDir    = "obj_dir"

# Verify verilator is reachable up front -- the error from `verilator` itself
# is a parser stack trace, not a "command not found" message.
if (-not (Get-Command verilator -ErrorAction SilentlyContinue)) {
    Write-Error "verilator not found on PATH. Install via scoop/choco/msys2 and re-open the terminal."
}

# PowerShell doesn't auto-expand globs the way bash does; gather sources explicitly.
$RtlSrcs = Get-ChildItem -Path $RtlDir -Filter *.sv | Select-Object -ExpandProperty FullName
if (-not $RtlSrcs) {
    Write-Error "no RTL sources found under $RtlDir/"
}

Write-Host "--- Building $TopModule with $($RtlSrcs.Count) RTL files ---"

$verilatorArgs = @(
    "--cc", "--exe", "--build", "-Wall",
    "--top-module", $TopModule,
    "-CFLAGS", "-std=c++17"
) + $RtlSrcs + @($SimCpp)

& verilator @verilatorArgs
if ($LASTEXITCODE -ne 0) {
    Write-Error "verilator failed with exit code $LASTEXITCODE"
}

# Verilator emits the binary with or without .exe depending on host.
$candidates = @(
    (Join-Path $ObjDir "V$TopModule.exe"),
    (Join-Path $ObjDir "V$TopModule")
)
$built = $candidates | Where-Object { Test-Path $_ } | Select-Object -First 1
if ($built) {
    Write-Host "--- Built: $built ---"
} else {
    Write-Warning "verilator returned 0 but no binary found in $ObjDir/"
}
