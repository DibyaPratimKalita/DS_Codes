/*Write a program to implement the power function for double without using the pow library
function. You can use math.h but cannot use the pow function.*/

#include <stdio.h>
#include <math.h>

double power(double base, int exponent) {
    if (exponent == 0) {
        return 1.0;
    }

    double result = 1.0;

    // Handle negative exponents
    if (exponent < 0) {
        base = 1.0 / base;
        exponent = -exponent;
    }

    for (int i = 0; i < exponent; i++) {
        result *= base;
    }

    return result;
}

int main() {
    double base;
    int exponent;

    printf("Enter the base: ");
    scanf("%lf", &base);

    printf("Enter the exponent: ");
    scanf("%d", &exponent);

    double result = power(base, exponent);

    printf("Result: %lf\n", result);

    return 0;
}