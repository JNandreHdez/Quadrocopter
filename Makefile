# Compiler
CC = g++
# Compiler flags
CFLAGS = -Wall -Wextra -pedantic -std=c++11
# Directories
SRC_DIR = src
BIN_DIR = bin
INC_DIR = $(SRC_DIR)/headers
# Source files
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
# Object files
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(BIN_DIR)/%.o,$(SRC_FILES))

# Default target
all: quadrocopter

# Target: quadrocopter
quadrocopter: $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $(BIN_DIR)/quadrocopter $^

# Rule to compile object files
$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

# Clean build files
clean:
	rm -f $(BIN_DIR)/*.o $(BIN_DIR)/quadrocopter