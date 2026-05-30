# Makefile for v0 Transformer Decoder — Verilator simulation

TOP_MODULE  = complete_transformer_decoder
RTL_DIR     = rtl
SIM_CPP     = sim/cpp/sim_main.cpp
OBJ_DIR     = obj_dir

# All RTL source files
RTL_SRCS    = $(wildcard $(RTL_DIR)/*.sv)

# Verilator flags
VERILATOR_FLAGS = --cc --exe --build -Wall --public-flat-rw\
                  --top-module $(TOP_MODULE) \
                  -CFLAGS "-std=c++17"

.PHONY: all verilate sim clean

all: sim

# Elaborate / compile with Verilator
verilate: $(OBJ_DIR)/V$(TOP_MODULE)

$(OBJ_DIR)/V$(TOP_MODULE): $(RTL_SRCS) $(SIM_CPP)
	verilator $(VERILATOR_FLAGS) $(RTL_SRCS) $(SIM_CPP)

# Run the simulation (from Hardware_PC/ so $readmemh paths resolve)
sim: $(OBJ_DIR)/V$(TOP_MODULE)
	cd .. && v0/$(OBJ_DIR)/V$(TOP_MODULE)

clean:
	rm -rf $(OBJ_DIR)
