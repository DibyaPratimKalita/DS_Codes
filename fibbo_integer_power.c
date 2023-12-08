#include <stdio.h>

// Function to compute integer power recursively
int power(int n, int e) {
    if (e == 0)
        return 1;
    else if (e % 2 == 0) {
        int temp = power(n, e / 2);
        return temp * temp;
    } else {
        int temp = power(n, (e - 1) / 2);
        return n * temp * temp;
    }
}

int main() {
    int base = 2; // Base number
    int exponent = 5; // Exponent
    int result = power(base, exponent);
    
    printf("%d raised to the power of %d is: %d\n", base, exponent, result);
    return 0;
}
