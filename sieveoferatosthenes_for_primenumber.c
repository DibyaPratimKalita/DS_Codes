#include <stdio.h>
#include <stdbool.h>

void sieveOfEratosthenes(int n) {
    bool prime[n+1];
    for (int i = 2; i <= n; i++)
        prime[i] = true;

    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    printf("Prime numbers from 2 to %d are:\n", n);
    for (int i = 2; i <= n; i++) {
        if (prime[i])
            printf("%d ", i);
    }
    printf("\n");
}

int main() {
    int n = 50; // Change 'n' to display primes up to a different number
    sieveOfEratosthenes(n);
    return 0;
}
