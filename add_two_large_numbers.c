/*Write a program to add two very large numbers. Also, analyze the time and space complexity.
Each number is represented as a string, and its upper limit is 1024 digits.*/

#include <stdio.h>
#include <string.h>

#define MAX_DIGITS 1025

void addLargeNumbers(char num1[], char num2[], char result[]) {
    int carry = 0;
    int i, j, k;

    // Make sure the result string is initially empty
    result[0] = '\0';

    // Start from the rightmost digit and move towards the left
    for (i = strlen(num1) - 1, j = strlen(num2) - 1, k = 0; i >= 0 || j >= 0 || carry > 0; i--, j--, k++) {
        // Extract digits from the input numbers (if available)
        int digit1 = (i >= 0) ? num1[i] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j] - '0' : 0;

        // Add the digits along with the carry from the previous step
        int sum = digit1 + digit2 + carry;

        // Calculate the new carry for the next step
        carry = sum / 10;

        // Update the result string with the current digit
        result[k] = (sum % 10) + '0';
    }

    // Make sure to terminate the result string
    result[k] = '\0';

    // Reverse the result string to get the correct order
    for (int start = 0, end = k - 1; start < end; start++, end--) {
        char temp = result[start];
        result[start] = result[end];
        result[end] = temp;
    }
}

int main() {
    char num1[MAX_DIGITS], num2[MAX_DIGITS], result[MAX_DIGITS + 1];

    // Input the two large numbers as strings
    printf("Enter the first number: ");
    scanf("%s", num1);

    printf("Enter the second number: ");
    scanf("%s", num2);

    // Add the two large numbers
    addLargeNumbers(num1, num2, result);

    // Display the result
    printf("Sum: %s\n", result);

    return 0;
}
/*Time Complexity Analysis:
The time complexity of this program is O(N), where N is the maximum number of digits in the input numbers. This is because the program iterates through each digit once, and the number of iterations is directly proportional to the number of digits.

Space Complexity Analysis:
The space complexity is O(N), where N is the maximum number of digits in the input numbers. This is due to the space required to store the input numbers and the result. The space complexity does not depend on the actual values of the numbers but only on their sizes.*/