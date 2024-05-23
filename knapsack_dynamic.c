#include <stdio.h>

void main(){
    int weights[] = {2,3,3};
    int values[] = {1,2,4};
    int capacity = 6;
    int n = sizeof(values) / sizeof(values[0]);
    int dp[n + 1][capacity + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0){
                dp[i][w] = 0;
            }
            else if (weights[i - 1] <= w){
                if(values[i - 1] + dp[i - 1][w - weights[i - 1]] > dp[i - 1][w]){
                    dp[i][w] = values[i - 1] + dp[i - 1][w - weights[i - 1]];
                }
                else{
                    dp[i][w] = dp[i - 1][w];
                }
            }
            else{
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    printf("Table:\n\n");
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            printf("%d\t", dp[i][w]);
        }
        printf("\n");
    }

    printf("\nMaximum value: %d\n", dp[n][capacity]);
}
