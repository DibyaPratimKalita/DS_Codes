/*Given two sparse matrix representation A[k][3] and B[k][3]. Write a program to add A[k][3] and
B[k][3].*/

#include<stdio.h>

#define MAX_TERMS 100

// Function to add two sparse matrices
void addSparseMatrices(int A[][3], int B[][3], int result[][3]) {
    int i = 1, j = 1, k = 0;
    
    // Check if matrices A and B are compatible for addition
    if (A[0][0] != B[0][0] || A[0][1] != B[0][1]) {
        printf("Matrices are not compatible for addition.\n");
        return;
    }

    // Initialize the result matrix header
    result[0][0] = A[0][0];
    result[0][1] = A[0][1];

    // Add matrices A and B
    while (i <= A[0][2] && j <= B[0][2]) {
        if (A[i][0] < B[j][0] || (A[i][0] == B[j][0] && A[i][1] < B[j][1])) {
            // Copy element from matrix A to result
            result[k][0] = A[i][0];
            result[k][1] = A[i][1];
            result[k][2] = A[i][2];
            i++;
        } else if (A[i][0] > B[j][0] || (A[i][0] == B[j][0] && A[i][1] > B[j][1])) {
            // Copy element from matrix B to result
            result[k][0] = B[j][0];
            result[k][1] = B[j][1];
            result[k][2] = B[j][2];
            j++;
        } else {
            // Add values from both matrices and copy to result
            result[k][0] = A[i][0];
            result[k][1] = A[i][1];
            result[k][2] = A[i][2] + B[j][2];
            i++;
            j++;
        }
        k++;
    }

    // Copy remaining elements from matrix A
    while (i <= A[0][2]) {
        result[k][0] = A[i][0];
        result[k][1] = A[i][1];
        result[k][2] = A[i][2];
        i++;
        k++;
    }

    // Copy remaining elements from matrix B
    while (j <= B[0][2]) {
        result[k][0] = B[j][0];
        result[k][1] = B[j][1];
        result[k][2] = B[j][2];
        j++;
        k++;
    }

    // Update the number of non-zero elements in the result matrix
    result[0][2] = k - 1;
}

// Function to display a sparse matrix
void displaySparseMatrix(int matrix[][3]) {
    int k = matrix[0][2];

    printf("Row\tColumn\tValue\n");

    for (int i = 1; i <= k; i++) {
        printf("%d\t%d\t%d\n", matrix[i][0], matrix[i][1], matrix[i][2]);
    }
}

int main() {
    int A[MAX_TERMS][3] = {
        {3, 4, 4}, // Number of rows, number of columns, number of non-zero elements
        {1, 1, 1},
        {2, 2, 2},
        {3, 3, 3},
        {3, 4, 4}
    };

    int B[MAX_TERMS][3] = {
        {3, 4, 4},
        {1, 1, 1},
        {2, 2, 2},
        {3, 3, 3},
        {3, 4, 4}
    };

    int result[MAX_TERMS][3];

    printf("Matrix A:\n");
    displaySparseMatrix(A);

    printf("\nMatrix B:\n");
    displaySparseMatrix(B);

    // Add matrices A and B
    addSparseMatrices(A, B, result);

    printf("\nSum of matrices A and B:\n");
    displaySparseMatrix(result);

    return 0;
}