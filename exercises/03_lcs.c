/**
 * Exercise 3: Longest Common Subsequence (LCS) using Dynamic Programming
 * 
 * Problem: Find the length of the longest subsequence common to two sequences.
 * A subsequence is a sequence that appears in the same relative order,
 * but not necessarily contiguous.
 * 
 * Time Complexity: O(m*n)
 * Space Complexity: O(m*n)
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

// Dynamic Programming solution for LCS
int lcs_length(char *X, char *Y, int m, int n) {
    int **dp = (int **)malloc((m + 1) * sizeof(int *));
    for (int i = 0; i <= m; i++) {
        dp[i] = (int *)calloc(n + 1, sizeof(int));
    }
    
    // Build the LCS table in bottom-up fashion
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i-1] == Y[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    int result = dp[m][n];
    
    // Free memory
    for (int i = 0; i <= m; i++) {
        free(dp[i]);
    }
    free(dp);
    
    return result;
}

// Function to print the LCS
void print_lcs(char *X, char *Y, int m, int n) {
    int **dp = (int **)malloc((m + 1) * sizeof(int *));
    for (int i = 0; i <= m; i++) {
        dp[i] = (int *)calloc(n + 1, sizeof(int));
    }
    
    // Build the LCS table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i-1] == Y[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    // Backtrack to find the LCS
    int index = dp[m][n];
    char *lcs = (char *)malloc((index + 1) * sizeof(char));
    lcs[index] = '\0';
    
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i-1] == Y[j-1]) {
            lcs[index-1] = X[i-1];
            i--;
            j--;
            index--;
        }
        else if (dp[i-1][j] > dp[i][j-1]) {
            i--;
        }
        else {
            j--;
        }
    }
    
    printf("Longest Common Subsequence: %s\n", lcs);
    
    // Free memory
    for (int i = 0; i <= m; i++) {
        free(dp[i]);
    }
    free(dp);
    free(lcs);
}

int main() {
    char X[1000], Y[1000];
    
    printf("=== Longest Common Subsequence (LCS) ===\n");
    printf("Enter first sequence: ");
    scanf("%s", X);
    
    printf("Enter second sequence: ");
    scanf("%s", Y);
    
    int m = strlen(X);
    int n = strlen(Y);
    
    int length = lcs_length(X, Y, m, n);
    printf("\nLength of LCS: %d\n", length);
    
    print_lcs(X, Y, m, n);
    
    return 0;
}
