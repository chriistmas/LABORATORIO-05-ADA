# LABORATORIO-05-ADA

## Overview
This repository contains solved exercises for Laboratory 05 of the Analysis and Design of Algorithms (ADA) course. The exercises focus on **Dynamic Programming** techniques and classic algorithmic problems.

## Repository Structure
```
LABORATORIO-05-ADA/
├── exercises/           # Solved exercises
│   ├── 01_fibonacci.c
│   ├── 02_knapsack.c
│   ├── 03_lcs.c
│   ├── 04_coin_change.c
│   ├── 05_matrix_chain.c
│   └── README.md
├── Makefile            # Build configuration
└── README.md
```

## Exercises

### 1. Fibonacci Sequence (Dynamic Programming)
Implementation of Fibonacci number calculation using DP with both tabulation and space-optimized approaches.

### 2. 0/1 Knapsack Problem
Classic optimization problem to maximize value in a knapsack with weight constraint.

### 3. Longest Common Subsequence (LCS)
Finding the longest subsequence common to two sequences.

### 4. Coin Change Problem
Two variants: minimum coins needed and number of ways to make change.

### 5. Matrix Chain Multiplication
Finding the optimal order to multiply a chain of matrices.

## Quick Start

### Compilation
Compile all exercises:
```bash
make
```

Or compile individual exercises:
```bash
make fibonacci
make knapsack
make lcs
make coin_change
make matrix_chain
```

### Running Exercises
After compilation, executables are in the `build/` directory:
```bash
./build/01_fibonacci
./build/02_knapsack
./build/03_lcs
./build/04_coin_change
./build/05_matrix_chain
```

### Clean Build
Remove compiled files:
```bash
make clean
```

## Requirements
- GCC compiler
- Make utility
- Standard C library

## Topics Covered
- Dynamic Programming
- Optimization Problems
- Time and Space Complexity Analysis
- Algorithm Design Techniques

## Additional Information
For detailed information about each exercise, see [exercises/README.md](exercises/README.md).

## License
Educational purposes - ADA Course