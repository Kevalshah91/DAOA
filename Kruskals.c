#include <stdio.h>
void main() {
    int i, j, k;
    int val[100];
    int vali[100];
    int valj[100];
    int a[5][5] = {
          {0, 1, 2, 0, 0},
          {1, 0, 0, 3, 0},
          {2, 0, 0, 6, 5},
          {0, 3, 6, 0, 4},
          {0, 0, 5, 4, 0}};
    int leave;
    int cost = 0;

    printf("Keval Shah 60009220061\n");

    len_sel = 0;
    len_cut = 0;

    // Find the nearest neighbor for each vertex 
    for (i = 0; i < 5; i++) {
        int mini = 0;
        int minj = 0;
        int min = 100;

        for (j = 0; j < 5; j++) {
            if (a[i][j] < min && a[i][j] != 0) {
                min = a[i][j];
                mini = i;
                minj = j;
            }
        }

        val[i] = min;
        vali[i] = mini;
        valj[i] = minj;
    }

    // Avoid Cycle
    for (i = 0; i < 5; i++) {
        if (vali[i + 1] == valj[i] && vali[i] == valj[i + 1]) {
            leave = i;
        }
    }

    for (i = 0; i < 5; i++) {
        if (i != leave) {
            printf("Connecting %d to %d with cost %d\n", vali[i] + 1, valj[i] + 1, val[i]);
            cost += val[i];
        }
    }

    printf("Final cost is %d\n", cost);
}
