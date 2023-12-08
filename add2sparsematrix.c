/*Given two sparse matrix representation A[k][3] and B[k][3].
(a) Write a program to add A[k][3] and B[k][3].
*/
#include <stdio.h>

void addSparseMatrices(int A[][3], int B[][3], int result[][3], int rowsA, int rowsB) {
    // Initialize result matrix
    int i = 0, j = 0, k = 0;

    printf("Matrix A:\n");
    for (i = 0; i < rowsA; i++) {
        printf("%d %d %d\n", A[i][0], A[i][1], A[i][2]);
    }

    printf("Matrix B:\n");
    for (j = 0; j < rowsB; j++) {
        printf("%d %d %d\n", B[j][0], B[j][1], B[j][2]);
    }

    i = 0; // Reset i to 0 for the actual addition

    printf("Result of addition:\n");
    while (i < rowsA && j < rowsB) {
        if (A[i][0] < B[j][0] || (A[i][0] == B[j][0] && A[i][1] < B[j][1])) {
            result[k][0] = A[i][0];
            result[k][1] = A[i][1];
            result[k][2] = A[i][2];
            i++;
        } else if (A[i][0] > B[j][0] || (A[i][0] == B[j][0] && A[i][1] > B[j][1])) {
            result[k][0] = B[j][0];
            result[k][1] = B[j][1];
            result[k][2] = B[j][2];
            j++;
        } else {
            result[k][0] = A[i][0];
            result[k][1] = A[i][1];
            result[k][2] = A[i][2] + B[j][2];
            i++;
            j++;
        }
        printf("%d %d %d\n", result[k][0], result[k][1], result[k][2]);
        k++;
    }

    // Copy remaining elements from A, if any
    while (i < rowsA) {
        result[k][0] = A[i][0];
        result[k][1] = A[i][1];
        result[k][2] = A[i][2];
        i++;
        printf("%d %d %d\n", result[k][0], result[k][1], result[k][2]);
        k++;
    }

    // Copy remaining elements from B, if any
    while (j < rowsB) {
        result[k][0] = B[j][0];
        result[k][1] = B[j][1];
        result[k][2] = B[j][2];
        j++;
        printf("%d %d %d\n", result[k][0], result[k][1], result[k][2]);
        k++;
    }
}

int main() {
    // Example usage with hardcoded inputs
    int rowsA = 4, rowsB = 3;

    // Sparse matrices A and B
    int A[4][3] = {
        {0, 0, 3},
        {1, 1, 5},
        {2, 2, 2},
        {3, 3, 1}
    };

    int B[3][3] = {
        {0, 0, 2},
        {1, 1, 1},
        {2, 2, 4}
    };

    // Assuming the matrices have compatible dimensions for addition
    int result[rowsA + rowsB][3];
    addSparseMatrices(A, B, result, rowsA, rowsB);

    return 0;
}
