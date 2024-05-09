#include<stdio.h>
#include<stdbool.h>
#define V 6
#define MAX 10000
void main(){
    int i,j;
    int graph[V][V] = {
        {0, 7, 9, 0, 0, 14},
        {7, 0, 10, 15, 0, 0},
        {9, 10, 0, 11, 0, 2},
        {0, 15, 11, 0, 6, 0},
        {0, 0, 0, 6, 0, 9},
        {14, 0, 2, 0, 9, 0}
    };
    int dist[V];
    bool visited[V];
    // Initialise
    for(i=0;i<V;i++){
        dist[i] = MAX;
        visited[i] = false;
    }
    int src = 0;
    dist[src]=0;
    for(int count=0;count<V-1;count++){
        int u=-1;
        for(i=0;i<V;i++){
            if(!visited[i] && (u==-1 || dist[i] < dist[u])){
                u=i;
            }
        }
        visited[u] = true;
        for(int v=0;v<V;v++){
            if(!visited[v] && graph[u][v] && dist[u] != MAX){
                if(dist[u] + graph[u][v] < dist[v]){
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }

    printf("Vertex Distance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}