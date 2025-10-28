/**
 * Exercise 1: Fibonacci Sequence using Dynamic Programming
 * 
 * Problem: Calculate the nth Fibonacci number efficiently using DP
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

#include <stdio.h>
#include <stdlib.h>

// Dynamic Programming approach - Tabulation (Bottom-Up)
long long fibonacci_dp(int n) {
    if (n <= 1) return n;
    
    long long *dp = (long long *)malloc((n + 1) * sizeof(long long));
    if (dp == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return -1;
    }
    dp[0] = 0;
    dp[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    long long result = dp[n];
    free(dp);
    return result;
}

// Space-optimized DP approach
long long fibonacci_optimized(int n) {
    if (n <= 1) return n;
    
    long long prev2 = 0, prev1 = 1, current;
    
    for (int i = 2; i <= n; i++) {
        current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }
    
    return prev1;
}

int main() {
    int n;
    
    printf("=== Fibonacci Sequence Calculator ===\n");
    printf("Enter the position n: ");
    if (scanf("%d", &n) != 1) {
        printf("Invalid input.\n");
        return 1;
    }
    
    if (n < 0) {
        printf("Please enter a non-negative integer.\n");
        return 1;
    }
    
    printf("\nUsing Dynamic Programming (Tabulation):\n");
    printf("Fibonacci(%d) = %lld\n", n, fibonacci_dp(n));
    
    printf("\nUsing Space-Optimized DP:\n");
    printf("Fibonacci(%d) = %lld\n", n, fibonacci_optimized(n));
    
    // Display first n Fibonacci numbers
    printf("\nFirst %d Fibonacci numbers:\n", n + 1);
    for (int i = 0; i <= n && i < 20; i++) {
        printf("F(%d) = %lld\n", i, fibonacci_optimized(i));
    }
    
    return 0;
}
