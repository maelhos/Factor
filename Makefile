# Default is x86_64
.PHONY: default
default: build

cpp_source_files := $(shell find src -name *.cpp)

CPLUS_INCLUDE_PATH := include

OUT_NAME := Factor


.PHONY: build
build: $(cpp_object_files)
	@echo "[CPP Files] :"
	@echo $(cpp_source_files)
	@g++ -I $(CPLUS_INCLUDE_PATH)  $(cpp_source_files) -o $(OUT_NAME) -lgmpxx -lgmp -lmpfr
	

CLEAN:
	@rm -rfv build/
	@mkdir build
	@echo "CLEAN"