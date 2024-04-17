#include<stdio.h>
#include<string.h>

int LCS[100][100];

void lcs(char x[100], char y[100], int len_x, int len_y) {
    int i, j;
    for (i = 0; i <= len_x; i++) {
        LCS[i][0] = 0;
    }
    for (j = 0; j <= len_y; j++) {
        LCS[0][j] = 0;
    }
    for (i = 1; i <= len_x; i++) {
        for (j = 1; j <= len_y; j++) {
            if (x[i - 1] == y[j - 1]) {
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
            } else {
                if (LCS[i - 1][j] > LCS[i][j - 1]) {
                    LCS[i][j] = LCS[i - 1][j];
                } else {
                    LCS[i][j] = LCS[i][j - 1];
                }
            }
        }
    }
}

void printLCS(char x[100], char y[100], int m, int n) {
    if (m == 0 || n == 0) {
        return;
    } else if (x[m - 1] == y[n - 1]) {
        printLCS(x, y, m - 1, n - 1);
        printf("%c", x[m - 1]);
    } else {
        if (LCS[m - 1][n] > LCS[m][n - 1]) {
            printLCS(x, y, m - 1, n);
        } else {
            printLCS(x, y, m, n - 1);
        }
    }
}

int main(){
    char x[100], y[100];
    int i, j, m, n;
    printf("Keval Shah 60009220061\n");
    printf("Enter the two strings:\n");
    scanf("%s", x);
    scanf("%s", y);
    m = strlen(x);
    n = strlen(y);
    lcs(x, y, m, n);
    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            printf("%d ", LCS[i][j]);
        }
        printf("\n");
    }
    printf("LCS Sequence:\n");
    printLCS(x, y, m, n);
    printf("\n");
    return 0;
}
