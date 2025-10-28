/**
 * Exercise 2: 0/1 Knapsack Problem using Dynamic Programming
 * 
 * Problem: Given weights and values of n items, put these items in a knapsack
 * of capacity W to get the maximum total value in the knapsack.
 * 
 * Time Complexity: O(n*W)
 * Space Complexity: O(n*W)
 */

#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

// Dynamic Programming solution for 0/1 Knapsack
int knapsack(int W, int weights[], int values[], int n) {
    int **dp = (int **)malloc((n + 1) * sizeof(int *));
    if (dp == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return -1;
    }
    
    for (int i = 0; i <= n; i++) {
        dp[i] = (int *)malloc((W + 1) * sizeof(int));
        if (dp[i] == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            for (int j = 0; j < i; j++) {
                free(dp[j]);
            }
            free(dp);
            return -1;
        }
    }
    
    // Build table dp[][] in bottom-up manner
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            }
            else if (weights[i-1] <= w) {
                dp[i][w] = max(values[i-1] + dp[i-1][w - weights[i-1]], 
                              dp[i-1][w]);
            }
            else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    
    int result = dp[n][W];
    
    // Free allocated memory
    for (int i = 0; i <= n; i++) {
        free(dp[i]);
    }
    free(dp);
    
    return result;
}

// Space-optimized version using 1D array
int knapsack_optimized(int W, int weights[], int values[], int n) {
    int *dp = (int *)calloc(W + 1, sizeof(int));
    
    for (int i = 0; i < n; i++) {
        for (int w = W; w >= weights[i]; w--) {
            dp[w] = max(dp[w], values[i] + dp[w - weights[i]]);
        }
    }
    
    int result = dp[W];
    free(dp);
    return result;
}

int main() {
    int n, W;
    
    printf("=== 0/1 Knapsack Problem ===\n");
    printf("Enter number of items: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of items.\n");
        return 1;
    }
    
    int *values = (int *)malloc(n * sizeof(int));
    int *weights = (int *)malloc(n * sizeof(int));
    
    if (values == NULL || weights == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        free(values);
        free(weights);
        return 1;
    }
    
    printf("Enter values of items:\n");
    for (int i = 0; i < n; i++) {
        printf("Value of item %d: ", i + 1);
        scanf("%d", &values[i]);
    }
    
    printf("\nEnter weights of items:\n");
    for (int i = 0; i < n; i++) {
        printf("Weight of item %d: ", i + 1);
        scanf("%d", &weights[i]);
    }
    
    printf("\nEnter knapsack capacity: ");
    scanf("%d", &W);
    
    int max_value = knapsack(W, weights, values, n);
    printf("\nMaximum value that can be obtained: %d\n", max_value);
    
    int max_value_opt = knapsack_optimized(W, weights, values, n);
    printf("Verification (space-optimized): %d\n", max_value_opt);
    
    free(values);
    free(weights);
    
    return 0;
}
