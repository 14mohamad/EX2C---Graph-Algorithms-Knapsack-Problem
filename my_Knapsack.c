#include <stdio.h>

#define MAX_WEIGHT 20
#define ARRAY_SIZE 5

int max(int a, int b) 
{ 
    return (a > b)? a : b; 
}


int knapSack(int weights[], int values[], int selected_bool[])
{
    int i, w;
    int K[ARRAY_SIZE + 1][MAX_WEIGHT + 1];

    for (i = 0; i <= ARRAY_SIZE; i++) {
        for (w = 0; w <= MAX_WEIGHT; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (weights[i - 1] <= w)
                K[i][w] = max(values[i - 1] + K[i - 1][w - weights[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    int res = K[ARRAY_SIZE][MAX_WEIGHT];
    w = MAX_WEIGHT;
    for (i = ARRAY_SIZE; i > 0 && res > 0; i--) {
        if (res == K[i - 1][w])
            continue;
        else {
            selected_bool[i - 1] = 1;
            res -= values[i - 1];
            w -= weights[i - 1];
        }
    }
    return K[ARRAY_SIZE][MAX_WEIGHT];
}



int main() {
    char items[] = {'A', 'B', 'C', 'D', 'E'};
    int values[] = {35, 60, 100, 120, 130};
    int weights[] = {2, 5, 6, 9, 7};
    int selected_bool[ARRAY_SIZE] = {0}; // Array to track selected items

    int maxProfit = knapSack(weights, values, selected_bool);
    printf("Maximum profit: %d\nItems that give the maximum profit: [", maxProfit);
    
    int firstItemPrinted = 0;
    for (int i = ARRAY_SIZE - 1; i >= 0; i--) {
        if (selected_bool[i]) {
            if (firstItemPrinted)
                printf(", ");
            printf("%c", items[i]);
            firstItemPrinted = 1;
        }
    }
    printf("]\n");

    return 0;
}