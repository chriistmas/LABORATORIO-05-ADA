# Makefile for LABORATORIO-05-ADA Exercises

CC = gcc
CFLAGS = -Wall -Wextra -O2 -std=c11
EXERCISE_DIR = exercises
BUILD_DIR = build

# Source files
SOURCES = $(wildcard $(EXERCISE_DIR)/*.c)
# Executable names (without extension)
EXECUTABLES = $(patsubst $(EXERCISE_DIR)/%.c,$(BUILD_DIR)/%,$(SOURCES))

.PHONY: all clean run help

# Default target
all: $(BUILD_DIR) $(EXECUTABLES)

# Create build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Compile each exercise
$(BUILD_DIR)/%: $(EXERCISE_DIR)/%.c
	$(CC) $(CFLAGS) $< -o $@

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR)

# Help target
help:
	@echo "LABORATORIO-05-ADA Makefile"
	@echo "=============================="
	@echo "Available targets:"
	@echo "  make         - Compile all exercises"
	@echo "  make clean   - Remove compiled executables"
	@echo "  make help    - Show this help message"
	@echo ""
	@echo "Exercises:"
	@echo "  1. Fibonacci Sequence (Dynamic Programming)"
	@echo "  2. 0/1 Knapsack Problem"
	@echo "  3. Longest Common Subsequence (LCS)"
	@echo "  4. Coin Change Problem"
	@echo "  5. Matrix Chain Multiplication"
	@echo ""
	@echo "To run an exercise:"
	@echo "  ./build/01_fibonacci"
	@echo "  ./build/02_knapsack"
	@echo "  ./build/03_lcs"
	@echo "  ./build/04_coin_change"
	@echo "  ./build/05_matrix_chain"

# Individual exercise targets
fibonacci: $(BUILD_DIR) $(BUILD_DIR)/01_fibonacci

knapsack: $(BUILD_DIR) $(BUILD_DIR)/02_knapsack

lcs: $(BUILD_DIR) $(BUILD_DIR)/03_lcs

coin_change: $(BUILD_DIR) $(BUILD_DIR)/04_coin_change

matrix_chain: $(BUILD_DIR) $(BUILD_DIR)/05_matrix_chain
