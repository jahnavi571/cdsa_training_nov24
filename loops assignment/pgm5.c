#include <stdio.h>

int main() {
    int N, i;
    
    // Input the integer
    printf("Enter an integer: ");
    scanf("%d", &N);
    
    // Edge case: if N is less than 2, it is not prime
    if (N <= 1) {
        printf("No\n");
        return 0;
    }

    // Check divisibility from 2 to sqrt(N)
    i = 2;
    while (i * i <= N) {
        if (N % i == 0) {
            printf("No\n");
            return 0;
        }
        i++;
    }

    // If no divisors found, it's prime
    printf("Yes\n");

    return 0;
}