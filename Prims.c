#include<stdio.h>
#include<stdbool.h>
#define V 5
#define max 10000
void main(){
    int i,j;
    int graph[V][V]={
        { 0, 2, 0, 6, 0 },
        { 2, 0, 3, 8, 5 },
        { 0, 3, 0, 0, 7 },
        { 6, 8, 0, 0, 9 },
        { 0, 5, 7, 9, 0 }};
    int src = 0;
    int n=0;
    int x,y,min;
    bool visited[V];
    // initialise 
    for(i=0;i<V;i++){
        visited[i]=false;
    }
    visited[src]=true;
    while(n<V-1){
        x=0;
        y=0;
        min = max;
        for(i=0;i<V;i++){
            if(visited[i]){      // if already visited
                for(j=0;j<V;j++){
                    if(!visited[j] && graph[i][j] && graph[i][j] < min){     //If next node not visited and path exits and path less than min
                        min = graph[i][j];
                        x=i;
                        y=j;
                    }
                }
            }
        }
        printf("%d -> %d  cost  : %d\n",x,y,graph[x][y]);
        visited[y] = true;
        n++;
    }

}
