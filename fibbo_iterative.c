#include <stdio.h>
#include <time.h>

// Iterative method to find nth Fibonacci number
unsigned long long fibonacciIterative(unsigned int n) {
    unsigned long long a = 0, b = 1, temp;
    if (n == 0)
        return a;
    for (unsigned int i = 2; i <= n; i++) {
        temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

// Function to measure the execution time of the iterative Fibonacci function
double measureTimeIterative(unsigned int n) {
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    fibonacciIterative(n);
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    return cpu_time_used;
}

// Function to compare the execution time of the iterative Fibonacci function for different values of n
void compareExecutionTime() {
    int n_values[] = {5, 10, 15, 20, 25, 30};  // Compare for different values of n
    int num_values = sizeof(n_values) / sizeof(n_values[0]);

    printf("Comparison of Execution Time for Iterative Fibonacci Method\n");
    printf("----------------------------------------------------------\n");
    printf("Value of n   |   Execution Time (in seconds)\n");
    printf("----------------------------------------------------------\n");

    for (int i = 0; i < num_values; i++) {
        double exec_time = measureTimeIterative(n_values[i]);
        printf("%6d       |   %10f\n", n_values[i], exec_time);
    }
}

int main() {
    compareExecutionTime();
    return 0;
}
