/*Given an array A[]. We can convert the single-dimensional array into a 2D array (matrix) without
using a 2D array structure. Assume the representation is in row-major order. Write a program in c
to add, subtract, and multiply two such matrices without using 2D array structures. Note: The
resultant array must be in a single-dimensional array*/

#include <stdio.h>

#define ROWS 3
#define COLS 3

// Function to get the index of a matrix element in a 1D array
int getIndex(int row, int col) {
    return row * COLS + col;
}

// Function to add two matrices
void addMatrices(int A[], int B[], int result[]) {
    for (int i = 0; i < ROWS * COLS; i++) {
        result[i] = A[i] + B[i];
    }
}

// Function to subtract one matrix from another
void subtractMatrices(int A[], int B[], int result[]) {
    for (int i = 0; i < ROWS * COLS; i++) {
        result[i] = A[i] - B[i];
    }
}

// Function to multiply two matrices
void multiplyMatrices(int A[], int B[], int result[]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[getIndex(i, j)] = 0;

            for (int k = 0; k < COLS; k++) {
                result[getIndex(i, j)] += A[getIndex(i, k)] * B[getIndex(k, j)];
            }
        }
    }
}

// Function to display a matrix
void displayMatrix(int matrix[]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix[getIndex(i, j)]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int matrixA[ROWS * COLS] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int matrixB[ROWS * COLS] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int result[ROWS * COLS];

    // Add matrices
    addMatrices(matrixA, matrixB, result);
    printf("Sum of matrices:\n");
    displayMatrix(result);

    // Subtract matrices
    subtractMatrices(matrixA, matrixB, result);
    printf("Difference of matrices:\n");
    displayMatrix(result);

    // Multiply matrices
    multiplyMatrices(matrixA, matrixB, result);
    printf("Product of matrices:\n");
    displayMatrix(result);

    return 0;
}