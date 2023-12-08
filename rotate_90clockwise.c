#include <stdio.h>

#define N 4

// Function to rotate a matrix 90 degrees clockwise
void rotateMatrix(int matrix[N][N]) {
    // Transpose the matrix
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            // Swap matrix[i][j] with matrix[j][i]
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    // Reverse each row
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N / 2; j++) {
            // Swap matrix[i][j] with matrix[i][N-1-j]
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][N - 1 - j];
            matrix[i][N - 1 - j] = temp;
        }
    }
}

// Function to display a matrix
void displayMatrix(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[N][N] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    printf("Original Matrix:\n");
    displayMatrix(matrix);

    // Rotate the matrix 90 degrees clockwise
    rotateMatrix(matrix);

    printf("\nMatrix after 90-degree clockwise rotation:\n");
    displayMatrix(matrix);

    return 0;
}