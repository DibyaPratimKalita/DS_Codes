#include <stdio.h>
#include <stdbool.h>

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1)
        return false;
    
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}

// Function to display prime numbers up to n
void displayPrimes(int n) {
    printf("Prime numbers from 2 to %d are:\n", n);
    for (int i = 2; i <= n; i++) {
        if (isPrime(i))
            printf("%d ", i);
    }
    printf("\n");
}

int main() {
    int n = 50; // Change 'n' to display primes up to a different number
    displayPrimes(n);
    return 0;
}
