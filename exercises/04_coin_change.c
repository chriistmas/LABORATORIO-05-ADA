/**
 * Exercise 4: Coin Change Problem using Dynamic Programming
 * 
 * Problem: Given a set of coin denominations and a target amount,
 * find the minimum number of coins needed to make that amount.
 * 
 * Time Complexity: O(n*amount)
 * Space Complexity: O(amount)
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

// DP solution for minimum coins needed
int coin_change_min(int coins[], int n, int amount) {
    int *dp = (int *)malloc((amount + 1) * sizeof(int));
    
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
        dp[i] = INT_MAX;
    }
    
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < n; j++) {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
    
    int result = (dp[amount] == INT_MAX) ? -1 : dp[amount];
    free(dp);
    return result;
}

// DP solution for number of ways to make change
long long coin_change_ways(int coins[], int n, int amount) {
    long long *dp = (long long *)calloc(amount + 1, sizeof(long long));
    dp[0] = 1;
    
    for (int i = 0; i < n; i++) {
        for (int j = coins[i]; j <= amount; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }
    
    long long result = dp[amount];
    free(dp);
    return result;
}

// Function to print the coins used
void print_coins_used(int coins[], int n, int amount) {
    int *dp = (int *)malloc((amount + 1) * sizeof(int));
    int *last_coin = (int *)malloc((amount + 1) * sizeof(int));
    
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
        dp[i] = INT_MAX;
        last_coin[i] = -1;
    }
    
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < n; j++) {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX) {
                if (dp[i - coins[j]] + 1 < dp[i]) {
                    dp[i] = dp[i - coins[j]] + 1;
                    last_coin[i] = j;
                }
            }
        }
    }
    
    if (dp[amount] == INT_MAX) {
        printf("Cannot make the amount with given coins.\n");
    } else {
        printf("Coins used: ");
        int current = amount;
        while (current > 0) {
            int coin_idx = last_coin[current];
            printf("%d ", coins[coin_idx]);
            current -= coins[coin_idx];
        }
        printf("\n");
    }
    
    free(dp);
    free(last_coin);
}

int main() {
    int n, amount;
    
    printf("=== Coin Change Problem ===\n");
    printf("Enter number of coin denominations: ");
    scanf("%d", &n);
    
    int *coins = (int *)malloc(n * sizeof(int));
    
    printf("Enter coin denominations:\n");
    for (int i = 0; i < n; i++) {
        printf("Coin %d: ", i + 1);
        scanf("%d", &coins[i]);
    }
    
    printf("\nEnter target amount: ");
    scanf("%d", &amount);
    
    int min_coins = coin_change_min(coins, n, amount);
    if (min_coins == -1) {
        printf("\nCannot make amount %d with given coins.\n", amount);
    } else {
        printf("\nMinimum coins needed: %d\n", min_coins);
        print_coins_used(coins, n, amount);
    }
    
    long long ways = coin_change_ways(coins, n, amount);
    printf("\nNumber of ways to make amount %d: %lld\n", amount, ways);
    
    free(coins);
    
    return 0;
}
