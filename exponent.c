/*Write a program to perform (A[k][3])^n.*/

#include <stdio.h>



void powerSparseMatrix(int A[][3], int result[][3], int rowsA, int n) {
    // Initialize result matrix as an identity matrix
    for (int i = 0; i < rowsA; i++) {
        result[i][0] = A[i][0];
        result[i][1] = A[i][1];
        result[i][2] = A[i][2];
    }

    // Display matrix A
    printf("Matrix A:\n");
    for (int i = 0; i < rowsA; i++) {
        printf("%d %d %d\n", A[i][0], A[i][1], A[i][2]);
    }

    // Display result matrix before exponentiation
    printf("Result before exponentiation:\n");
    for (int i = 0; i < rowsA; i++) {
        printf("%d %d %d\n", result[i][0], result[i][1], result[i][2]);
    }

    // Perform matrix exponentiation
    for (int i = 2; i <= n; i++) {
        int temp[rowsA + rowsA][3];
        multiplySparseMatrices(result, A, temp, rowsA, rowsA);
        for (int j = 0; j < rowsA + rowsA; j++) {
            result[j][0] = temp[j][0];
            result[j][1] = temp[j][1];
            result[j][2] = temp[j][2];
        }
    }

    // Display result matrix after exponentiation
    printf("Result after exponentiation:\n");
    for (int i = 0; i < rowsA + rowsA; i++) {
        printf("%d %d %d\n", result[i][0], result[i][1], result[i][2]);
    }
}

int main() {
    // Example usage with hardcoded inputs
    int rowsA = 3, n = 3;

    // Sparse matrix A
    int A[3][3] = {
        {0, 0, 1},
        {1, 1, 2},
        {2, 2, 3}
    };

    // Assuming the matrix has compatible dimensions for exponentiation
    int result[rowsA + rowsA][3];
    powerSparseMatrix(A, result, rowsA, n);

    return 0;
}

