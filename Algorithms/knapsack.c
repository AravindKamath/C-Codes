#include <stdio.h>

int knapsack(int weight[], int value[], int n, int capacity) {
    int dp[n + 1][capacity + 1];
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            }
            else if (weight[i - 1] <= w) {
                int a = value[i - 1] + dp[i - 1][w - weight[i - 1]];
                int b = dp[i - 1][w];
                dp[i][w] =  a > b ? a : b;
            }
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][capacity];
}

void main() {
    int weights[] = {1, 3, 4, 5};
    int values[] = {1, 4, 5, 7};
    int capacity = 7;
    printf("%d\t", knapsack(weights, values, 4, 7));
}