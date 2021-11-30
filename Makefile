# Default is x86_64
.PHONY: default
default: build

cpp_source_files := $(shell find src -name *.cpp)
cpp_object_files := $(patsubst src/%.cpp, build/%.o, $(cpp_source_files))

CPLUS_INCLUDE_PATH := include

OUT_NAME := Factor

$(cpp_object_files): build/%.o : src/%.cpp
	@mkdir -p $(dir $@) && \
	g++ -g -c -pthread -I $(CPLUS_INCLUDE_PATH) -lgmpxx -lgmp -lmpfr $(patsubst build/%.o, src/%.cpp, $@) -o $@

.PHONY: build
build: $(cpp_object_files)
	@echo "[CPP Files] :"
	@echo $(cpp_source_files)
	@echo "[CPP OBJ Files] :"
	@echo $(cpp_object_files)
	@g++ -g -o $(OUT_NAME) $(cpp_object_files) -lgmp -lgmpxx -lmpfr

CLEAN:
	@rm -rfv build/
	@mkdir build
	@echo "CLEAN"