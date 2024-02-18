#include <stdio.h>
#include <stdlib.h>
// Function to add two matrices
void add(int n, int A[][n], int B[][n], int C[][n]) {
    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
    C[i][j] = A[i][j] + B[i][j];
}
// Function to subtract two matrices
void subtract(int n, int A[][n], int B[][n], int C[][n]) {
    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
    C[i][j] = A[i][j] - B[i][j];
}
// Strassen's algorithm for matrix multiplication
void strassen(int n, int A[][n], int B[][n], int C[][n]) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }
    int newSize = n / 2;
    int A11[newSize][newSize], A12[newSize][newSize],
    A21[newSize][newSize], A22[newSize][newSize];
    int B11[newSize][newSize], B12[newSize][newSize],
    B21[newSize][newSize], B22[newSize][newSize];
    int C11[newSize][newSize], C12[newSize][newSize],   
    C21[newSize][newSize], C22[newSize][newSize];
    int P1[newSize][newSize], P2[newSize][newSize],
    P3[newSize][newSize], P4[newSize][newSize],
    P5[newSize][newSize], P6[newSize][newSize],
    P7[newSize][newSize];
    int temp1[newSize][newSize], temp2[newSize][newSize];
    // Dividing matrices into sub-matrices
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }
// Calculating P1 to P7
    add(newSize, A11, A22, temp1);
    add(newSize, B11, B22, temp2);
    strassen(newSize, temp1, temp2, P1);
    add(newSize, A21, A22, temp1);
    strassen(newSize, temp1, B11, P2);
    subtract(newSize, B12, B22, temp1);
    strassen(newSize, A11, temp1, P3);
    subtract(newSize, B21, B11, temp1);
    strassen(newSize, A22, temp1, P4);
    add(newSize, A11, A12, temp1);
    strassen(newSize, temp1, B22, P5);
    subtract(newSize, A21, A11, temp1);
    add(newSize, B11, B12, temp2);
    strassen(newSize, temp1, temp2, P6);
    subtract(newSize, A12, A22, temp1);
    add(newSize, B21, B22, temp2);
    strassen(newSize, temp1, temp2, P7);
    // Calculating C matrices
    add(newSize, P1, P4, temp1);
    subtract(newSize, temp1, P5, temp2);
    add(newSize, temp2, P7, C11);
    add(newSize, P3, P5, C12);
    add(newSize, P2, P4, C21);
    add(newSize, P1, P3, temp1);
    subtract(newSize, temp1, P2, temp2);
    add(newSize, temp2, P6, C22);
    // Combining C matrices to form the result

    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
            }
        }
    }
// Function to print a matrix
void printMatrix(int n, int mat[][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", mat[i][j]);
            }
            printf("\n");
        }
}
// Function to take input for a matrix
void inputMatrix(int n, int mat[][n]) {
    printf("Enter the elements of the %dx%d matrix:\n", n,n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}
int main() {
    int n = 4; // Size of matrices is 4x4
    int A[n][n], B[n][n], C[n][n];
    printf("Keval 60009220061");
    printf("Enter the first matrix:\n");
    inputMatrix(n, A);
    printf("Enter the second matrix:\n");
    inputMatrix(n, B);
    strassen(n, A, B, C);
    printf("\nResult of matrix multiplication:\n");
    printMatrix(n, C);
    return 0;
}
