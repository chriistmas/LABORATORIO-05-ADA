# Exercises - LABORATORIO 05 ADA

This directory contains solved exercises for Laboratory 05 of Analysis and Design of Algorithms (ADA).

## Exercises Overview

All exercises are implemented in C and use **Dynamic Programming** techniques.

### Exercise 1: Fibonacci Sequence
**File:** `01_fibonacci.c`

Calculates the nth Fibonacci number using Dynamic Programming approaches:
- Tabulation (Bottom-Up) approach
- Space-optimized approach

**Time Complexity:** O(n)  
**Space Complexity:** O(n) for standard, O(1) for optimized

**How to run:**
```bash
./build/01_fibonacci
```

**Example:**
```
Enter the position n: 10
Fibonacci(10) = 55
```

---

### Exercise 2: 0/1 Knapsack Problem
**File:** `02_knapsack.c`

Given weights and values of n items, determines the maximum value that can be obtained by placing items in a knapsack of capacity W.

**Time Complexity:** O(n*W)  
**Space Complexity:** O(n*W) for standard, O(W) for optimized

**How to run:**
```bash
./build/02_knapsack
```

**Example:**
```
Enter number of items: 3
Values: 60 100 120
Weights: 10 20 30
Capacity: 50
Maximum value: 220
```

---

### Exercise 3: Longest Common Subsequence (LCS)
**File:** `03_lcs.c`

Finds the length and actual sequence of the longest common subsequence between two strings.

**Time Complexity:** O(m*n)  
**Space Complexity:** O(m*n)

**How to run:**
```bash
./build/03_lcs
```

**Example:**
```
Enter first sequence: AGGTAB
Enter second sequence: GXTXAYB
Length of LCS: 4
Longest Common Subsequence: GTAB
```

---

### Exercise 4: Coin Change Problem
**File:** `04_coin_change.c`

Solves two variants:
1. Minimum number of coins needed to make a target amount
2. Number of ways to make change for the target amount

**Time Complexity:** O(n*amount)  
**Space Complexity:** O(amount)

**How to run:**
```bash
./build/04_coin_change
```

**Example:**
```
Enter number of coin denominations: 3
Coins: 1 2 5
Target amount: 11
Minimum coins needed: 3
Coins used: 5 5 1
Number of ways: 11
```

---

### Exercise 5: Matrix Chain Multiplication
**File:** `05_matrix_chain.c`

Finds the optimal order to multiply a chain of matrices to minimize the total number of scalar multiplications. Also displays the optimal parenthesization.

**Time Complexity:** O(n³)  
**Space Complexity:** O(n²)

**How to run:**
```bash
./build/05_matrix_chain
```

**Example:**
```
Enter number of matrices: 3
Dimensions: 10 20 30 40
Matrix A: 10 x 20
Matrix B: 20 x 30
Matrix C: 30 x 40
Optimal Parenthesization: ((AB)C)
Minimum scalar multiplications: 18000
```

---

## Compilation

To compile all exercises:
```bash
make
```

To compile a specific exercise:
```bash
make fibonacci
make knapsack
make lcs
make coin_change
make matrix_chain
```

To clean build artifacts:
```bash
make clean
```

---

## Dynamic Programming Concepts

All exercises demonstrate key Dynamic Programming principles:

1. **Optimal Substructure:** The optimal solution contains optimal solutions to subproblems
2. **Overlapping Subproblems:** Same subproblems are solved multiple times
3. **Memoization/Tabulation:** Store solutions to avoid redundant computations

### Approach Types:
- **Top-Down (Memoization):** Recursive with caching
- **Bottom-Up (Tabulation):** Iterative table filling

---

## Author
Laboratory exercises for ADA course
