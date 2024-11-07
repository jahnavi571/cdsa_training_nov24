#include <stdio.h>

int factorial(int n) {
    // Base case: if n is 0, return 1
    if (n == 0) {
        return 1;
    }
    // Recursive case: n * factorial(n-1)
    else {
        return n * factorial(n - 1);
    }
}










#include <stdio.h>

// Function to return the nth Fibonacci number
int fibonacci(int n) {
    if (n <= 1) {
        return n;  // Base case: Fibonacci of 0 or 1 is n itself
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);  // Recursive call for nth Fibonacci
    }
}

int main() {
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci Series: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));  // Call the fibonacci function for each term
    }
    return 0;
}

