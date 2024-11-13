#include <stdio.h>

int main() {
    int a, b;
    
    // Input the range [a, b]
    printf("Enter the value of a (starting number): ");
    scanf("%d", &a);
    
    printf("Enter the value of b (ending number): ");
    scanf("%d", &b);
    
    // Check if a is less than or equal to b to avoid invalid range
    if (a > b) {
        printf("Invalid range! a should be less than or equal to b.\n");
        return 1;
    }

    // Loop through the integers from a to b
    printf("Integers in the interval [%d, %d] are:\n", a, b);
    for (int n = a; n <= b; n++) {
        printf("%d\n", n);
    }
    
    return 0;
}