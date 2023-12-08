#include <stdio.h>
#include <time.h>

// Dynamic programming method to find nth Fibonacci number
unsigned long long fibonacciDynamic(unsigned int n) {
    unsigned long long fib[n + 2];
    unsigned int i;

    fib[0] = 0;
    fib[1] = 1;
    for (i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib[n];
}

// Function to measure the execution time of the dynamic programming Fibonacci function
double measureTimeDynamic(unsigned int n) {
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    fibonacciDynamic(n);
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    return cpu_time_used;
}

// Function to compare the execution time of the dynamic programming Fibonacci function for different values of n
void compareExecutionTime() {
    int n_values[] = {5, 10, 50, 100, 500, 1000};  // Compare for different values of n
    int num_values = sizeof(n_values) / sizeof(n_values[0]);

    printf("Comparison of Execution Time for Dynamic Programming Fibonacci Method\n");
    printf("---------------------------------------------------------------------\n");
    printf("Value of n   |   Execution Time (in seconds)\n");
    printf("---------------------------------------------------------------------\n");

    for (int i = 0; i < num_values; i++) {
        double exec_time = measureTimeDynamic(n_values[i]);
        printf("%6d       |   %10f\n", n_values[i], exec_time);
    }
}

int main() {
    compareExecutionTime();
    return 0;
}
