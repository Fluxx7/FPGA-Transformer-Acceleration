# =============================================================================
# v0/Makefile -- Verilator builds for the transformer decoder and module tests.
#
# Targets:
#   make verilate                Build the full-pipeline sim
#   make sim                     Build + run the full-pipeline sim
#   make test-<module>           Build a standalone test for <module>
#   make tests                   Build every module test
#   make clean                   Wipe obj_dir/
#
# Model parameters can be overridden on the command line:
#   make test-layer_normalization EMBED_DIM=32 NUM_HEADS=8
#
# Each module test only receives the parameters its top module actually
# declares -- Verilator errors if you pass -G for a parameter the top
# doesn't have.
#
# Requires GNU make (macOS default `make` is GNU make 3.81 -- works fine).
# =============================================================================

EMBED_DIM   ?= 16
SEQ_LEN     ?= 8
VOCAB_SIZE  ?= 40
NUM_HEADS   ?= 4
FFN_DIM     ?= 128

OBJ_DIR     := obj_dir
RTL_DIR     := rtl
SIM_CPP_DIR := sim/cpp

# Convenience aliases so per-module PARAMS lines stay short and readable.
P_EMBED  := -GEMBED_DIM=$(EMBED_DIM)
P_SEQ    := -GSEQ_LEN=$(SEQ_LEN)
P_VOCAB  := -GVOCAB_SIZE=$(VOCAB_SIZE)
P_HEADS  := -GNUM_HEADS=$(NUM_HEADS)
P_FFN    := -GFFN_DIM=$(FFN_DIM)

# All parameters (used only by the full-pipeline top, which has every one).
ALL_PARAMS := $(P_EMBED) $(P_SEQ) $(P_VOCAB) $(P_HEADS) $(P_FFN)

VFLAGS := --cc --exe --build -Wall --public-flat-rw \
          -CFLAGS "-std=c++17"

RTL_SRCS := $(wildcard $(RTL_DIR)/*.sv)

.PHONY: all clean verilate sim tests
all: verilate

# -----------------------------------------------------------------------------
# Full-pipeline build
# -----------------------------------------------------------------------------
verilate: $(OBJ_DIR)/Vcomplete_transformer_decoder

$(OBJ_DIR)/Vcomplete_transformer_decoder: $(RTL_SRCS) $(SIM_CPP_DIR)/sim_main.cpp
	verilator $(VFLAGS) $(ALL_PARAMS) --top-module complete_transformer_decoder \
		$(RTL_SRCS) $(SIM_CPP_DIR)/sim_main.cpp

sim: verilate
	cd .. && v0/$(OBJ_DIR)/Vcomplete_transformer_decoder

# -----------------------------------------------------------------------------
# Per-module test config
#
# For each <module>:
#   <module>_RTL     := SystemVerilog files needed to elaborate <module>
#   <module>_PARAMS  := only the -G overrides <module>'s top declares
# -----------------------------------------------------------------------------
layer_normalization_RTL  := $(RTL_DIR)/layer_normalization.sv $(RTL_DIR)/memory_module.sv
layer_normalization_PARAMS := $(P_SEQ) $(P_EMBED)

enhanced_softmax_RTL     := $(RTL_DIR)/enhanced_softmax.sv $(RTL_DIR)/memory_module.sv
enhanced_softmax_PARAMS  := $(P_SEQ)

feed_forward_network_RTL := $(RTL_DIR)/feed_forward_network.sv $(RTL_DIR)/memory_module.sv
feed_forward_network_PARAMS := $(P_SEQ) $(P_EMBED) $(P_FFN)

attention_head_RTL       := $(RTL_DIR)/attention_head.sv $(RTL_DIR)/enhanced_softmax.sv $(RTL_DIR)/memory_module.sv
attention_head_PARAMS    := $(P_SEQ) $(P_EMBED)

multi_head_attention_RTL := $(RTL_DIR)/multi_head_attention.sv $(RTL_DIR)/attention_head.sv $(RTL_DIR)/enhanced_softmax.sv $(RTL_DIR)/memory_module.sv
multi_head_attention_PARAMS := $(P_SEQ) $(P_EMBED) $(P_HEADS)

positional_encoding_RTL  := $(RTL_DIR)/positional_encoding.sv $(RTL_DIR)/memory_module.sv
positional_encoding_PARAMS := $(P_SEQ) $(P_EMBED)

token_embedding_RTL      := $(RTL_DIR)/token_embedding.sv $(RTL_DIR)/memory_module.sv
token_embedding_PARAMS   := $(P_SEQ) $(P_EMBED)

output_projection_RTL    := $(RTL_DIR)/output_projection.sv $(RTL_DIR)/memory_module.sv
output_projection_PARAMS := $(P_EMBED) $(P_VOCAB)

argmax_RTL               := $(RTL_DIR)/argmax.sv
argmax_PARAMS            := $(P_VOCAB)

# -----------------------------------------------------------------------------
# Generic per-module build rule. Each instantiation generates:
#   test-<name>                                phony target
#   obj_dir/test_<name>/V<name>                actual binary
# -----------------------------------------------------------------------------
define build_module_test
.PHONY: test-$(1)
test-$(1): $(OBJ_DIR)/test_$(1)/V$(1)

$(OBJ_DIR)/test_$(1)/V$(1): $$($(1)_RTL) $(SIM_CPP_DIR)/test_$(1).cpp $(SIM_CPP_DIR)/common.h
	verilator $$(VFLAGS) $$($(1)_PARAMS) --top-module $(1) -Mdir $(OBJ_DIR)/test_$(1) \
		$$($(1)_RTL) $(SIM_CPP_DIR)/test_$(1).cpp
endef

$(eval $(call build_module_test,layer_normalization))
$(eval $(call build_module_test,enhanced_softmax))
$(eval $(call build_module_test,feed_forward_network))
$(eval $(call build_module_test,attention_head))
$(eval $(call build_module_test,multi_head_attention))
$(eval $(call build_module_test,positional_encoding))
$(eval $(call build_module_test,token_embedding))
$(eval $(call build_module_test,output_projection))
$(eval $(call build_module_test,argmax))

tests: test-layer_normalization test-enhanced_softmax test-feed_forward_network \
       test-attention_head test-multi_head_attention test-positional_encoding \
       test-token_embedding test-output_projection test-argmax

# -----------------------------------------------------------------------------
clean:
	rm -rf $(OBJ_DIR)
