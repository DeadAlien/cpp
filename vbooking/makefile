# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

# Directories
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Source file and object file
SRC = $(SRC_DIR)/bike.cpp
OBJ = $(OBJ_DIR)/bike.o

# Executable name
TARGET = $(BIN_DIR)/vbooking

# Default target
all: $(TARGET)

# Create the target executable
$(TARGET): $(OBJ)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source file into object file
$(OBJ): $(SRC)
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Run the program
run: all
	./$(TARGET)

# Phony targets
.PHONY: all clean run

