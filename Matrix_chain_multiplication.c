#include <stdio.h>
#define MAX 10000

int main() {
    int p[] = {2,3,4,2};
    int n = sizeof(p) / sizeof(p[0]);
    int m[n][n];
    int result;
    int bracket[n][n];
    int i, j, k, L, q;
    printf("Keval Shah 60009220061\n\n");
    for (i = 1; i < n; i++)
        m[i][i] = 0;

    for(L=2;L<n;L++) {
        for(i=1;i<n-L+1;i++) {
            j = i+L-1;
            m[i][j] = MAX;
            for(k=i;k<j;k++) {
                q = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];
                if (q<m[i][j]) {
                    m[i][j] = q;
                    bracket[i][j] = k;
                }
            }
        }
    }
    
    printf("Cost matrix:\n");
    for (i=1;i<n;i++) {
        for(j=1;j<n;j++) {
            if(j<i)
                printf("\t");
            else
                printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    result = m[1][n - 1];
    
    printf("Final comparisons to multiply %d matrices : %d\n\n",n-1 ,result);
    
    printf("Optimal Parenthesis matrix:\n");
    for (i = 1; i < n; i++) {
        for (j = 1; j < n; j++) {
            if (j < i)
                printf("\t");
            else if (i == j)
                printf("0\t");
            else
                printf("%d\t", bracket[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Optimal Parenthesis:\n");

    void printP(int i, int j, int n, int bracket[][n]) {
        if (i == j)
            printf("M%d", i);
        else {
            printf("(");
            printP(i, bracket[i][j], n, bracket);
            printP(bracket[i][j] + 1, j, n, bracket);
            printf(")");
        }
    }

    printP(1, n - 1, n, bracket);
    printf("\n");

    return 0;
}
