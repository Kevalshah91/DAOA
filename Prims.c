#include <stdio.h>

void main() {
  int arr[5][5] = {
      {0, 1, 2, 0, 0},
      {1, 0, 0, 3, 0},
      {2, 0, 0, 6, 5},
      {0, 3, 6, 0, 4},
      {0, 0, 5, 4, 0}};
  int selected[100];
  int cut[100];
  int i, j, k;
  int cost, len_sel, len_cut, trav, flag;
  int min, mini, mincol;

  selected[0] = 0;
  len_sel = 1;
  cut[0] = 0;
  len_cut = 1;
  cost = 0;
  printf("Keval Shah 60009220061\n");

  while (len_cut < 5) {
    min = 1000;     // to represent a large number
    for (trav = 0; trav < len_sel; trav++) {
      int ccol = selected[trav];
      for (i = 0; i < 5; i++) {
        flag = 0;
        for (j = 0; j < len_cut; j++) {
          if (i == cut[j]) {
            flag = 1;
            break;  // Exit the loop once a match is found
          }
        }
        if (flag == 1) {
          continue;
        } 
        else {
          if (arr[i][ccol] < min && arr[i][ccol] != 0) {
            min = arr[i][ccol];
            mini = i;
            mincol = ccol;
          }
        }
      }
    }
    printf("Connecting %d to %d with cost %d \n", mincol+1, mini+1, min);
    selected[len_sel] = mini;
    len_sel++;
    cut[len_cut] = mini;
    len_cut++;
    cost = cost + min;
  }
  printf("Final cost is %d \n", cost);
}