*program to print the principal and secondary principal diagonal matrix*/
#include <stdio.h>

void displayDiagonalMatrices(int matrix[10][10], int order) {
    int i, j;

    // Principal Diagonal Matrix
    printf("Principal Diagonal Matrix:\n");
    for (i = 0; i < order; i++) {
        for (j = 0; j < order; j++) {
            if (i == j) {
                printf("%d ", matrix[i][j]);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    // Secondary Principal Diagonal Matrix
    printf("\nSecondary Principal Diagonal Matrix:\n");
    for (i = 0; i < order; i++) {
        for (j = 0; j < order; j++) {
            if (i + j == order - 1) {
                printf("%d ", matrix[i][j]);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int main() {
    int matrix[10][10], order, i, j;

    printf("Enter the order of the square matrix: ");
    scanf("%d", &order);

    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < order; i++) {
        for (j = 0; j < order; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    displayDiagonalMatrices(matrix, order);

    return 0;
}