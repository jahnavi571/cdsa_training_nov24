#include <stdio.h>
#include <stdlib.h>  // For abs() function

// Function to update values of a and b
void update(int *a, int *b) {
    int sum = *a + *b;          // Calculate the sum of *a and *b
    int diff = abs(*a - *b);    // Calculate the absolute difference between *a and *b
    
    *a = sum;  // Set the value of *a to the sum
    *b = diff; // Set the value of *b to the absolute difference
}

int main() {
    int x, y;

    // Input values for x and y
    printf("Enter two integers: ");
    scanf("%d %d", &x, &y);

    // Call the update function
    update(&x, &y);

    // Output the updated values of x and y
    printf("Updated values: a = %d, b = %d\n", x, y);

    return 0;
}