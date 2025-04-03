CXX ?= g++

BUILD_DIR := ./build/linux/
EXE_NAME := traffic_light_fsa
EXE := $(BUILD_DIR)$(EXE_NAME)

SRC_DIR := ./SemaforAutomat/
SRC := $(wildcard $(SRC_DIR)*.cpp)
OBJ := $(patsubst $(SRC_DIR)%.cpp, $(BUILD_DIR)%.o, $(SRC))

run: build
	@echo "===== RUNING ====="
	$(EXE)

build: $(EXE)

$(EXE): $(OBJ)
	@echo "===== BUILDING EXECUTABLE ====="
	$(CXX) $(OBJ) -o $(EXE)

$(BUILD_DIR)%.o: $(SRC_DIR)%.cpp
	@echo "===== COMPILING CPP ====="
	$(CXX) $(CPPFLAGS) -c $< -o $@

all: 
	mkdir -p $(BUILD_DIR)

