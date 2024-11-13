#include <stdio.h>

int main() {
    int power = 2;  // Initialization (start from 2^1 which is 2)

    // While loop to print powers of 2 from 2^1 to 2^7
    while (power <= 128) {
        printf("%d\n", power);  // Print the current power of 2
        power *= 2;  // Update: Multiply by 2 to get the next power of 2
    }

    return 0;
}