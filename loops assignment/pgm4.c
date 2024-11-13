#include <stdio.h>

int main() {
    int N, count = 0;

    // Input the integer
    printf("Enter an integer: ");
    scanf("%d", &N);

    // Handle the case when N is zero
    if (N == 0) {
        count = 1;  // Zero has 1 digit
    } else {
        // Count digits by dividing the number by 10
        while (N != 0) {
            N /= 10;  // Divide N by 10
            count++;  // Increment the count of digits
        }
    }

    // Output the result
    printf("The number of digits is: %d\n", count);

    return 0;
}