/*Write a program to divide x/y
up to nth decimal point. Also, analyze the time and space complexity.
For instance, x=22, y=7, and n=1000.*/

#include <stdio.h>

void divide(int x, int y, int n) {
    int quotient = x / y;
    int remainder = (x % y) * 10; // Bring down the first digit after the decimal point
    int decimalPlaces = 0;

    printf("%d.", quotient);

    while (decimalPlaces < n) {
        quotient = remainder / y;
        remainder = (remainder % y) * 10;
        printf("%d", quotient);

        decimalPlaces++;

        if (remainder == 0) {
            break; // No remainder left, so no need to continue
        }
    }

    printf("\n");
}

int main() {
    int x = 22, y = 7, n = 1000;

    divide(x, y, n);

    return 0;
}
/*Time Complexity Analysis:
The time complexity of this program is O(n), where n is the specified number of decimal places. The loop iterates through each decimal place until the desired precision is achieved.

Space Complexity Analysis:
The space complexity is O(1) because the program uses a constant amount of additional space regardless of the input. The variables used (quotient, remainder, decimalPlaces) are independent of the size of the input.*/



