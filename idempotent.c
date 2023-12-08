#include <stdio.h>

#define SIZE 3

// Function to check if a matrix is idempotent
int isIdempotent(int matrix[SIZE][SIZE]) {
    int result[SIZE][SIZE] = {0};

    // Multiply the matrix by itself
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) {
                result[i][j] += matrix[i][k] * matrix[k][j];
            }
        }
    }

    // Check if the result is equal to the original matrix
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (matrix[i][j] != result[i][j]) {
                return 0; // Not idempotent
            }
        }
    }

    return 1; // Idempotent
}

// Function to display a matrix
void displayMatrix(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[SIZE][SIZE] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    printf("Original Matrix:\n");
    displayMatrix(matrix);

    if (isIdempotent(matrix)) {
        printf("\nThe matrix is idempotent.\n");
    } else {
        printf("\nThe matrix is not idempotent.\n");
    }

    return 0;
}