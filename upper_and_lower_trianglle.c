*Write a program to display a square matrix’s upper and lower triangular matrix*/
#include <stdio.h>

void displayUpperLowerTriangular(int matrix[10][10], int order) {
    int i, j;

    // Upper Triangular Matrix
    printf("Upper Triangular Matrix:\n");
    for (i = 0; i < order; i++) {
        for (j = 0; j < order; j++) {
            if (j >= i) {
                printf("%d ", matrix[i][j]);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    // Lower Triangular Matrix
    printf("\nLower Triangular Matrix:\n");
    for (i = 0; i < order; i++) {
        for (j = 0; j < order; j++) {
            if (j <= i) {
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

    displayUpperLowerTriangular(matrix, order);

    return 0;
}