#include <stdio.h>
#include <string.h>

#define MAX_DIGITS 1025

void multiplyLargeNumbers(char num1[], char num2[], char result[]) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);

    // Initialize the result with zeros
    for (int i = 0; i < MAX_DIGITS; i++) {
        result[i] = '0';
    }
    result[MAX_DIGITS] = '\0';

    // Multiply each digit of the first number with each digit of the second number
    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int digit1 = num1[i] - '0';
            int digit2 = num2[j] - '0';
            int product = digit1 * digit2;

            // Add the product to the result at the appropriate position
            int position = i + j;
            while (product > 0) {
                product += result[position] - '0';
                result[position] = (product % 10) + '0';
                product /= 10;
                position++;
            }
        }
    }

    // Find the position of the first non-zero digit in the result
    int start = 0;
    while (result[start] == '0' && start < MAX_DIGITS) {
        start++;
    }

    // Shift the result to remove leading zeros
    if (start > 0) {
        for (int i = 0; i < MAX_DIGITS - start; i++) {
            result[i] = result[i + start];
        }
        for (int i = MAX_DIGITS - start; i < MAX_DIGITS; i++) {
            result[i] = '\0';
        }
    }
}

int main() {
    char num1[MAX_DIGITS], num2[MAX_DIGITS], result[MAX_DIGITS * 2];

    // Input the two large numbers as strings
    printf("Enter the first number: ");
    scanf("%s", num1);

    printf("Enter the second number: ");
    scanf("%s", num2);

    // Multiply the two large numbers
    multiplyLargeNumbers(num1, num2, result);

    // Display the result
    printf("Product: %s\n", result);

    return 0;
}
