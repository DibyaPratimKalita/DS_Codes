#include <stdio.h>

#define ROWS 4
#define COLS 4

// Function to print matrix elements in diagonal order
void printDiagonalOrder(int matrix[ROWS][COLS]) {
    for (int line = 1; line <= (ROWS + COLS - 1); line++) {
        int start_col = (line <= ROWS) ? 0 : line - ROWS;
        int count = (line <= ROWS) ? line : (ROWS + COLS - 1) - line;

        for (int j = 0; j < count; j++) {
            printf("%d ", matrix[start_col + j][line - start_col - j - 1]);
        }
    }
}

// Function to display a matrix
void displayMatrix(int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[ROWS][COLS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    printf("Original Matrix:\n");
    displayMatrix(matrix);

    printf("\nMatrix Elements in Diagonal Order:\n");
    printDiagonalOrder(matrix);

    return 0;
}