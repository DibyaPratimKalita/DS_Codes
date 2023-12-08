/*Write a program in c to validate whether a given sudoku solution is valid or not.*/
#include <stdio.h>
#include <stdbool.h>

#define SIZE 9

// Function to check if a number can be placed at a given position in the Sudoku grid
bool isValid(int board[SIZE][SIZE], int row, int col, int num) {
    // Check if the number is not already present in the current row and column
    for (int i = 0; i < SIZE; i++) {
        if (board[row][i] == num || board[i][col] == num) {
            return false;
        }
    }

    // Check if the number is not already present in the current 3x3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    return true; // The number can be placed at the given position
}

// Function to validate the Sudoku solution
bool isValidSudoku(int board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] != 0) {
                // Check if the number at the current position is valid
                if (!isValid(board, i, j, board[i][j])) {
                    return false;
                }
            }
        }
    }
    return true; // The Sudoku solution is valid
}

int main() {
    int sudoku[SIZE][SIZE] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    if (isValidSudoku(sudoku)) {
        printf("The Sudoku solution is valid.\n");
    } else {
        printf("The Sudoku solution is not valid.\n");
    }

    return 0;
}
