#include <stdio.h>
#include <stdlib.h>

#define N 4

// Function to count the number of inversions in the puzzle
int getInvCount(int *arr){
    int inv_count = 0;
    for (int i = 0; i < N * N - 1; i++){
        for (int j = i + 1; j < N * N; j++){
            if (arr[j] && arr[i] && arr[i] > arr[j])
                inv_count++;
        }
    }
    return inv_count;
}

// Function to find the position of the blank tile '0'
int findXPosition(int puzzle[N][N]){
    for (int i = N - 1; i >= 0; i--)
        for (int j = N - 1; j >= 0; j--)
            if (puzzle[i][j] == 0)
                return N - i;
}

// Function to check if the puzzle is solvable
int isSolvable(int puzzle[N][N]){
    int invCount = getInvCount((int *)puzzle);
    if (N & 1) // For odd grid size
        return !(invCount & 1);
    else // For even grid size
    {
        int pos = findXPosition(puzzle);
        if (pos & 1)
            return !(invCount & 1);
        else
            return invCount & 1;
    }
}

// Function to calculate the Manhattan distance for a tile
int getManhattanDistance(int value, int row, int col){
    if (value == 0) // Blank tile has no distance
        return 0;
    int goalRow = (value - 1) / N;
    int goalCol = (value - 1) % N;
    return abs(row - goalRow) + abs(col - goalCol); // Manhattan distance calculation
}

// Function to calculate the total cost of the puzzle
int calculateTotalCost(int puzzle[N][N]){
    int totalCost = 0;
    totalCost += getInvCount((int *)puzzle); // Inversion count contributes to the cost
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            totalCost += getManhattanDistance(puzzle[i][j], i, j); // Manhattan distance of each tile contributes to the cost
    return totalCost;
}

void main(){
    int puzzle[N][N] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 0, 11},
        {13, 14, 15, 12}};

    if (!isSolvable(puzzle)){
        printf("Not Solvable\n");
    }

    int totalCost = calculateTotalCost(puzzle);
    printf("Total Cost: %d\n", totalCost);
}
