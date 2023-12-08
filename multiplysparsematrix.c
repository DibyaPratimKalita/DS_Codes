/*Write a program to multiply A[k][3] and B[k][3]*/

#include <stdio.h>

void multiplySparseMatrices(int A[][3], int B[][3], int result[][3], int rowsA, int rowsB) {
    // Implementation of matrix multiplication
    // ...
}

int main() {
    // Example usage with hardcoded inputs
    int rowsA = 3, rowsB = 3;

    // Sparse matrices A and B
    int A[3][3] = {
        {0, 0, 1},
        {1, 1, 2},
        {2, 2, 3}
    };

    int B[3][3] = {
        {0, 0, 2},
        {1, 1, 1},
        {2, 2, 4}
    };

    printf("Matrix A:\n");
    for (int i = 0; i < rowsA; i++) {
        printf("%d %d %d\n", A[i][0], A[i][1], A[i][2]);
    }

    printf("Matrix B:\n");
    for (int j = 0; j < rowsB; j++) {
        printf("%d %d %d\n", B[j][0], B[j][1], B[j][2]);
    }

    // Assuming the matrices have
