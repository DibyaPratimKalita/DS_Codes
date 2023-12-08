#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIGITS 1025

int compare(char num1[], char num2[]) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);

    if (len1 > len2) {
        return 1;
    } else if (len1 < len2) {
        return -1;
    }

    return strcmp(num1, num2);
}

void subtract(char num1[], char num2[], char result[]) {
    int borrow = 0;
    int len1 = strlen(num1);
    int len2 = strlen(num2);

    for (int i = len1 - 1; i >= 0; i--) {
        int digit1 = num1[i] - '0';
        int digit2 = (i >= len1 - len2) ? num2[i - (len1 - len2)] - '0' : 0;

        int diff = digit1 - digit2 - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        result[i] = diff + '0';
    }

    // Remove leading zeros in the result
    int start = 0;
    while (result[start] == '0' && start < len1) {
        start++;
    }

    // Shift the result to remove leading zeros
    if (start > 0) {
        for (int i = 0; i < len1 - start; i++) {
            result[i] = result[i + start];
        }
        for (int i = len1 - start; i < len1; i++) {
            result[i] = '\0';
        }
    }
}

void divideLargeNumbers(char num1[], char num2[], char quotient[]) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);

    if (compare(num1, num2) < 0) {
        strcpy(quotient, "0");
        return;
    }

    char* remainder = (char*)malloc((len1 + 1) * sizeof(char));
    remainder[len1] = '\0';

    strcpy(remainder, num1);

    char* currentDividend = (char*)malloc((len2 + 1) * sizeof(char));
    currentDividend[len2] = '\0';

    int position = 0;

    while (position < len1 && compare(remainder, num2) >= 0) {
        int i;
        for (i = 0; i < len2 && position + i < len1; i++) {
            currentDividend[i] = remainder[position + i];
        }
        currentDividend[i] = '\0';

        while (compare(currentDividend, num2) >= 0) {
            subtract(currentDividend, num2, currentDividend);
            quotient[position]++;
        }

        position++;

        while (position < len1 && remainder[position] == '0') {
            position++;
        }
    }

    free(currentDividend);
    strcpy(quotient, quotient + (quotient[0] == '0'));

    free(remainder);
}

int main() {
    char num1[MAX_DIGITS], num2[MAX_DIGITS], quotient[MAX_DIGITS];

    // Input the two large numbers as strings
    printf("Enter the numerator: ");
    scanf("%s", num1);

    printf("Enter the denominator: ");
    scanf("%s", num2);

    // Divide the two large numbers
    divideLargeNumbers(num1, num2, quotient);

    // Display the result
    printf("Quotient: %s\n", quotient);

    return 0;