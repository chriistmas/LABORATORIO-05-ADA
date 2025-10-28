/**
 * Exercise 5: Matrix Chain Multiplication using Dynamic Programming
 * 
 * Problem: Given a sequence of matrices, find the most efficient way to multiply them.
 * The problem is not actually to perform the multiplications, but merely to decide
 * in which order to perform the multiplications to minimize the total number of
 * scalar multiplications.
 * 
 * Time Complexity: O(n^3)
 * Space Complexity: O(n^2)
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

// Matrix Chain Multiplication using DP
int matrix_chain_order(int dimensions[], int n) {
    // n is the number of matrices
    // dimensions array has n+1 elements
    
    int **dp = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        dp[i] = (int *)calloc(n, sizeof(int));
    }
    
    // l is chain length
    for (int l = 2; l <= n; l++) {
        for (int i = 0; i < n - l + 1; i++) {
            int j = i + l - 1;
            dp[i][j] = INT_MAX;
            
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k+1][j] + 
                          dimensions[i] * dimensions[k+1] * dimensions[j+1];
                
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }
    
    int result = dp[0][n-1];
    
    // Free memory
    for (int i = 0; i < n; i++) {
        free(dp[i]);
    }
    free(dp);
    
    return result;
}

// Function to print optimal parenthesization
void print_optimal_parens(int i, int j, int **s, char *name) {
    if (i == j) {
        printf("%c%d", *name, i);
        (*name)++;
    } else {
        printf("(");
        print_optimal_parens(i, s[i][j], s, name);
        print_optimal_parens(s[i][j] + 1, j, s, name);
        printf(")");
    }
}

// Matrix Chain Order with printing parenthesization
int matrix_chain_order_with_parens(int dimensions[], int n) {
    int **dp = (int **)malloc(n * sizeof(int *));
    int **s = (int **)malloc(n * sizeof(int *));
    
    for (int i = 0; i < n; i++) {
        dp[i] = (int *)calloc(n, sizeof(int));
        s[i] = (int *)calloc(n, sizeof(int));
    }
    
    for (int l = 2; l <= n; l++) {
        for (int i = 0; i < n - l + 1; i++) {
            int j = i + l - 1;
            dp[i][j] = INT_MAX;
            
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k+1][j] + 
                          dimensions[i] * dimensions[k+1] * dimensions[j+1];
                
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }
    
    int result = dp[0][n-1];
    
    printf("\nOptimal Parenthesization: ");
    char name = 'A';
    print_optimal_parens(0, n-1, s, &name);
    printf("\n");
    
    // Free memory
    for (int i = 0; i < n; i++) {
        free(dp[i]);
        free(s[i]);
    }
    free(dp);
    free(s);
    
    return result;
}

int main() {
    int n;
    
    printf("=== Matrix Chain Multiplication ===\n");
    printf("Enter number of matrices: ");
    scanf("%d", &n);
    
    int *dimensions = (int *)malloc((n + 1) * sizeof(int));
    
    printf("\nEnter dimensions (for n matrices, enter n+1 dimensions):\n");
    printf("Example: For matrices A(10x20), B(20x30), C(30x40)\n");
    printf("         Enter: 10 20 30 40\n\n");
    
    for (int i = 0; i <= n; i++) {
        printf("Dimension %d: ", i);
        scanf("%d", &dimensions[i]);
    }
    
    printf("\nMatrix dimensions:\n");
    for (int i = 0; i < n; i++) {
        printf("Matrix %c: %d x %d\n", 'A' + i, dimensions[i], dimensions[i+1]);
    }
    
    int min_operations = matrix_chain_order_with_parens(dimensions, n);
    printf("\nMinimum number of scalar multiplications: %d\n", min_operations);
    
    free(dimensions);
    
    return 0;
}
