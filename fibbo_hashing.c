#include <stdio.h>
#define MAX 100

// Initializing the hash table to store Fibonacci numbers
unsigned long long fibHash[MAX] = {0};

// Function to calculate nth Fibonacci number using hashing
unsigned long long fibonacciHash(unsigned int n) {
    if (n <= 1)
        return n;

    if (fibHash[n] != 0)  // Check if the value is already computed and stored
        return fibHash[n];

    fibHash[n] = fibonacciHash(n - 1) + fibonacciHash(n - 2); // Calculate and store in the hash table
    return fibHash[n];
}

int main() {
    int n = 10; // Change 'n' to find nth Fibonacci number
    printf("Fibonacci number at position %d is %llu\n", n, fibonacciHash(n));
    return 0;
}
