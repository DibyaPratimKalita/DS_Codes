#include <stdio.h>

// Function to multiply two matrices and store the result in 'result'
void multiplyMatrix(unsigned long long a[2][2], unsigned long long b[2][2], unsigned long long result[2][2]) {
    result[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0];
    result[0][1] = a[0][0] * b[0][1] + a[0][1] * b[1][1];
    result[1][0] = a[1][0] * b[0][0] + a[1][1] * b[1][0];
    result[1][1] = a[1][0] * b[0][1] + a[1][1] * b[1][1];
}

// Function to perform matrix exponentiation
void matrixPower(unsigned long long matrix[2][2], unsigned long long n, unsigned long long result[2][2]) {
    if (n <= 1) {
        result[0][0] = matrix[0][0];
        result[0][1] = matrix[0][1];
        result[1][0] = matrix[1][0];
        result[1][1] = matrix[1][1];
        return;
    }

    unsigned long long temp[2][2];
    matrixPower(matrix, n / 2, temp);
    multiplyMatrix(temp, temp, result);

    if (n % 2 != 0) {
        unsigned long long temp2[2][2];
        multiplyMatrix(result, matrix, temp2);
        result[0][0] = temp2[0][0];
        result[0][1] = temp2[0][1];
        result[1][0] = temp2[1][0];
        result[1][1] = temp2[1][1];
    }
}

// Function to compute nth Fibonacci number using matrix multiplication
unsigned long long fibonacciMatrix(unsigned int n) {
    if (n == 0)
        return 0;

    unsigned long long baseMatrix[2][2] = {{1, 1}, {1, 0}};
    unsigned long long result[2][2];

    matrixPower(baseMatrix, n - 1, result);

    return result[0][0];
}

int main() {
    int n = 10; // Change 'n' to find nth Fibonacci number
    printf("Fibonacci number at position %d is %llu\n", n, fibonacciMatrix(n));
    return 0;
}
