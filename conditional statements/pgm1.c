#include <stdio.h>

int main() {
    int n;
    
    // Read input
    scanf("%d", &n);
    
    // Check if the number is between 1 and 9
    if (n >= 1 && n <= 9) {
        // Print the corresponding English word for numbers 1 to 9
        switch (n) {
            case 1: printf("one\n"); break;
            case 2: printf("two\n"); break;
            case 3: printf("three\n"); break;
            case 4: printf("four\n"); break;
            case 5: printf("five\n"); break;
            case 6: printf("six\n"); break;
            case 7: printf("seven\n"); break;
            case 8: printf("eight\n"); break;
            case 9: printf("nine\n"); break;
        }
    } else {
        // If number is greater than 9
        printf("Greater than 9\n");
    }
    
    return 0;
}