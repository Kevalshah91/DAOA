#include<stdio.h>

int tsp(int n,int dist[n][n],int visited,int current){
    // int visited;
    // int current;
    if(visited == (1<<n) -1){
        return dist[current][0]; // Return the distance from the current city back to the starting city
    }
    int min = 1000; 
    for(int i=0;i<n;i++){
        if(!(visited & (1<<i))){
            // Calculate the cost of visiting city 'i' from the current city
            int new_cost = dist[current][i] + tsp(n,dist,visited | (1<<i) , i);
            if(new_cost < min){
                min = new_cost;
            }
        }
    }
    return min;
}

void main(){
    int n=4;
    int dist[4][4] = {{0, 10, 15, 20}, 
                      {5, 0, 9, 10}, 
                      {6, 13, 0, 12}, 
                      {8, 8, 9, 0}};
    int c = tsp(n, dist, 1, 0);
    printf("Min cost : %d",c);
}