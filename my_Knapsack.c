#include <stdio.h>

#define MAX_ITEMS 5
#define MAX_WEIGHT 20

int knapSack(int weights[], int values[], int selected_bool[]) {
    int dp[MAX_ITEMS + 1][MAX_WEIGHT + 1];
    int i, w;

    // Build DP table
    for (i = 0; i <= MAX_ITEMS; i++) {
        for (w = 0; w <= MAX_WEIGHT; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i - 1] <= w)
                dp[i][w] = (values[i - 1] + dp[i - 1][w - weights[i - 1]]) > dp[i - 1][w] ? 
                           (values[i - 1] + dp[i - 1][w - weights[i - 1]]) : dp[i - 1][w];
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    // Trace back to find selected items
    int res = dp[MAX_ITEMS][MAX_WEIGHT];
    w = MAX_WEIGHT;
    for (i = MAX_ITEMS; i > 0 && res > 0; i--) {
        if (res == dp[i - 1][w])
            selected_bool[i - 1] = 0;
        else {
            selected_bool[i - 1] = 1;
            res -= values[i - 1];
            w -= weights[i - 1];
        }
    }

    return dp[MAX_ITEMS][MAX_WEIGHT];
}

int main() {
    char items[MAX_ITEMS] = {'A', 'B', 'C', 'D', 'E'};
    int values[MAX_ITEMS], weights[MAX_ITEMS], selected_bool[MAX_ITEMS] = {0};
    int i, max_profit;

    printf("Enter the values and weights for each item:\n");
    for (i = 0; i < MAX_ITEMS; i++) {
        printf("Enter value and weight for item %c: ", items[i]);
        scanf("%d %d", &values[i], &weights[i]);
    }

    max_profit = knapSack(weights, values, selected_bool);

    printf("\nMaximum profit: %d\n", max_profit);
    printf("Items that give the maximum profit: [");
    for (i = MAX_ITEMS - 1; i >= 0; i--) {
        if (selected_bool[i] == 1) {
            printf("%c", items[i]);
            if (i-1 > 0)
                printf(", ");
        }
    }
    printf("]\n");

    return 0;
}
