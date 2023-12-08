/*Given m × n matrix containing double values. Write a program to find the summation of each
row and column.*/

#include <stdio.h>

#define ROWS 3
#define COLS 4

// Function to calculate the summation of each row and column
void calculateSummations(double matrix[ROWS][COLS], double rowSum[], double colSum[]) {
    // Initialize rowSum and colSum arrays with zeros
    for (int i = 0; i < ROWS; i++) {
        rowSum[i] = 0.0;
    }
    for (int j = 0; j < COLS; j++) {
        colSum[j] = 0.0;
    }

    // Calculate the summation of each row and column
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            rowSum[i] += matrix[i][j];
            colSum[j] += matrix[i][j];
        }
    }
}

// Function to display a matrix
void displayMatrix(double matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%.2f\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to display the summation of each row and column
void displaySummations(double rowSum[], double colSum[]) {
    printf("\nRow Summations:\n");
    for (int i = 0; i < ROWS; i++) {
        printf("Row %d: %.2f\n", i + 1, rowSum[i]);
    }

    printf("\nColumn Summations:\n");
    for (int j = 0; j < COLS; j++) {
        printf("Column %d: %.2f\n", j + 1, colSum[j]);
    }
}

int main() {
    double matrix[ROWS][COLS] = {
        {1.5, 2.5, 3.5, 4.5},
        {5.5, 6.5, 7.5, 8.5},
        {9.5, 10.5, 11.5, 12.5}
    };

    double rowSum[ROWS];
    double colSum[COLS];

    printf("Original Matrix:\n");
    displayMatrix(matrix);

    // Calculate the summation of each row and column
    calculateSummations(matrix, rowSum, colSum);

    // Display the summation of each row and column
    displaySummations(rowSum, colSum);

    return 0;
}