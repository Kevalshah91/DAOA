#include <stdio.h>
#include <stdlib.h> 

int board[100];

int safe(int i, int k) {
    for (int j = 1; j < k; j++) {
        if (board[j] == i || abs(board[j] - i) == abs(k - j)) {
            return 0;
        }
    }
    return 1;
}

void n_queens(int k, int n) {
    if (k == n + 1) {
        printf("Possible Sequence: \n");
        for (int i = 1; i <= n; i++) {
            printf("%d ", board[i]);
        }
        printf("\n");
    } else {
        for (int i = 1; i <= n; i++) {
            if (safe(i, k)) {
                board[k] = i;
                n_queens(k + 1, n);
            }
        }
    }
}

int main() {
    int n;
    printf("Keval Shah 60009220061\n");
    printf("Give Value for N: ");
    scanf("%d", &n);
    n_queens(1, n); 
    return 0;
}
