#include <stdio.h>
#define MAX 1000     // to represent infinity
void main(){
    int V = 4;
    int d[20][20];
    int i,j,k;
    
    int g[20][20] = {
        {0, 8, MAX,1},
        {MAX, 0,1 ,MAX},
        {4,MAX, 0, MAX},
        {MAX,2,9, 0}
    };
    printf("Keval Shah 60009220061\n");
    // Initialize
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(i==j){
                d[i][j] = 0;
            }
            else{
                d[i][j] = g[i][j];
            }
        }
    }
    // algo
    for(k=0;k<V;k++){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(d[i][k] != MAX && d[k][j] != MAX && d[i][j] > d[i][k] + d[k][j]){
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
    
    printf("Result : \n");
    for(i=0;i<V;i++){
        for(j=0;j<V;j++){
            if (d[i][j] == MAX) {
                printf("INF\t");
            } 
            else {
                printf("%d\t", d[i][j]);
            }
        }
        printf("\n");
    }
    
}