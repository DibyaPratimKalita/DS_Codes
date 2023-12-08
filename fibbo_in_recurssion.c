#include <stdio.h>
#include <time.h>

// Recursive method to find nth Fibonacci number
unsigned long long fibonacciRecursive(unsigned int n) {
    if (n <= 1)
        return n;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

// Function to measure the execution time of the recursive Fibonacci function
double measureTimeRecursive(unsigned int n) {
    clock_t start, end;
    double cpu_time_used;
    
    start = clock();
    fibonacciRecursive(n);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    return cpu_time_used;
}

// Function to compare the execution time of the recursive Fibonacci function for different values of n
void compareExecutionTime() {
    int n_values[] = {5, 10, 15, 20, 25, 30};  // Compare for different values of n
    int num_values = sizeof(n_values) / sizeof(n_values[0]);

    printf("Comparison of Execution Time for Recursive Fibonacci Method\n");
    printf("----------------------------------------------------------\n");
    printf("Value of n   |   Execution Time (in seconds)\n");
    printf("----------------------------------------------------------\n");

    for (int i = 0; i < num_values; i++) {
        double exec_time = measureTimeRecursive(n_values[i]);
        printf("%6d       |   %10f\n", n_values[i], exec_time);
    }
}

int main() {
    compareExecutionTime();
    return 0;
}
