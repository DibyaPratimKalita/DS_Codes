/*Write a program in c to create a MineSweeper algorithm to place mines in random places on the
board. You are supposed to create hints based on the mine placement on the board.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10
#define NUM_MINES 15

// Function to initialize the Minesweeper board
void initializeBoard(int board[BOARD_SIZE][BOARD_SIZE]) {
    // Initialize all cells to 0
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }
}

// Function to print the Minesweeper board
void printBoard(int board[BOARD_SIZE][BOARD_SIZE]) {
    printf("Minesweeper Board:\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == -1) {
                printf("* "); // Mine
            } else {
                printf("%d ", board[i][j]); // Hint
            }
        }
        printf("\n");
    }
}

// Function to place mines randomly on the board
void placeMines(int board[BOARD_SIZE][BOARD_SIZE]) {
    int minesPlaced = 0;

    while (minesPlaced < NUM_MINES) {
        int row = rand() % BOARD_SIZE;
        int col = rand() % BOARD_SIZE;

        // Place mine if the cell is not already a mine
        if (board[row][col] != -1) {
            board[row][col] = -1; // -1 represents a mine
            minesPlaced++;
        }
    }
}

// Function to update hints on the board based on mine placement
void updateHints(int board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] != -1) { // Skip mines
                int count = 0;

                // Check adjacent cells
                for (int x = -1; x <= 1; x++) {
                    for (int y = -1; y <= 1; y++) {
                        int newRow = i + x;
                        int newCol = j + y;

                        // Check if the cell is within bounds and contains a mine
                        if (newRow >= 0 && newRow < BOARD_SIZE && newCol >= 0 && newCol < BOARD_SIZE &&
                            board[newRow][newCol] == -1) {
                            count++;
                        }
                    }
                }

                board[i][j] = count; // Update hint
            }
        }
    }
}

int main() {
    int minesweeperBoard[BOARD_SIZE][BOARD_SIZE];

    // Seed for random number generation
    srand(time(NULL));

    initializeBoard(minesweeperBoard);
    placeMines(minesweeperBoard);
    updateHints(minesweeperBoard);
    printBoard(minesweeperBoard);

    return 0;
}