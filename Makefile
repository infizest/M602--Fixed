# Compiler
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -Iinclude  
LDFLAGS = -lcurl  

# Directories
SRC_DIR = src
BIN_DIR = bin
OBJ_DIR = build
INCLUDE_DIR = include

# Source and object files
SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC))
TARGET = $(BIN_DIR)/carbon_footprint

# Default target
all: $(TARGET)

# Build the final executable
$(TARGET): $(OBJ)
	@mkdir -p $(BIN_DIR)
	$(CXX) -o $@ $^ $(LDFLAGS)

# Compile each source file into an object file
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Create necessary directories
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Clean up compiled files
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)/*
