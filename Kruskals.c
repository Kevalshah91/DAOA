#include<stdio.h>
#include<limits.h>
#define inf 1000
#define V 5

int parent[V];

int find(int i){
    while(parent[i] != i){
        i = parent[i];
    }
    return i;
}

void union_set(int i,int j){
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

void main(){
    int i,j;
    int graph[V][V] = {
        {inf, 1, 7, inf, inf},
	    {1, inf, 5, 4, 3},
	    {7, 5, inf, inf, 6},
	    {inf, 4, inf, inf, 2},
	    {inf, 3, 6, 2, inf}};
    int mincost=0;
    for(i=0;i<V;i++){
        parent[i] = i;
    }
    int edge_count = 0;
    while(edge_count < V-1){
        int min = inf;
        int a = -1;
        int b = -1;
        for(i=0;i<V;i++){
            for(j=0;j<V;j++){
                if(find(i) != find(j) && graph[i][j] < min){
                    min = graph[i][j];
                    a=i;
                    b=j;
                }
            }
        }
        union_set(a,b);
        printf("\nEdge %d :  (%d : %d) , cost : %d \n ",edge_count , a, b, min);
        edge_count += 1;
        mincost += min;  
    }
    printf("Total cost : %d",mincost);
}
