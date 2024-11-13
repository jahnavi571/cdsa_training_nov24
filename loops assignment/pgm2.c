#include <stdio.h>

int main() {
    int number, sum = 0;

    // Input a five-digit integer
    printf("Enter a five-digit integer: ");
    scanf("%d", &number);

    // Check if the number is five digits
    if (number < 10000 || number > 99999) {
        printf("Please enter a valid five-digit integer.\n");
        return 1;  // Exit the program with an error code
    }

    // Loop to extract and sum the digits
    while (number != 0) {
        sum += number % 10;  // Add the last digit
        number /= 10;         // Remove the last digit
    }

    // Output the result
    printf("The sum of the digits is: %d\n", sum);

    return 0;
}