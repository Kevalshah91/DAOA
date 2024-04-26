#include <stdio.h>
#include <limits.h>
#define N 5
#define INF 1000

int distance[N][N] = {
    {INF, 7, 3, 12, 8},
    {3, INF, 6, 14, 9},
    {5, 8, INF, 6, 18},
    {9, 3, 5, INF, 11},
    {18, 14, 9, 8, INF}
};

int visited[N];
int currentPath[N + 1];
int minPath[N + 1];
int minCost = INT_MAX;

void tsp(int node, int pathLength, int currentCost) {
    visited[node] = 1;
    currentPath[pathLength] = node;
    pathLength++;

    if (pathLength == N) {
        currentCost += distance[node][0];
        if (currentCost < minCost) {
            minCost = currentCost;
            for (int i = 0; i < N + 1; i++) {
                minPath[i] = currentPath[i];
            }
        }
    } 
    else {
        for (int i = 0; i < N; i++) {
            if (!visited[i]) {
                int newCost = currentCost + distance[node][i];
                if (newCost < minCost) {
                    tsp(i, pathLength, newCost);
                }
            }
        }
    }
    visited[node] = 0;
}

void main() {
    for (int i = 0; i < N; i++) {
        visited[i] = 0;
    }
    tsp(0, 0, 0);
    printf("Keval Shah 60009220061\n\n");
    printf("Path: ");
    for (int i = 0; i < N + 1; i++) {
        printf("%d", minPath[i] + 1);
        if (i < N) {
            printf(" -> ");
        } 
        else {
            printf("\n\n");
        }
    }
    printf("Final Cost: %d\n", minCost);
}