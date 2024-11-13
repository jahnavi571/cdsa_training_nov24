#include <stdio.h>
#include <stdlib.h>

// Function to calculate the GCD of two numbers
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to compare two integers (used for sorting)
int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);  // Sorting in descending order
}

int main() {
    int n;

    // Input the size of the array
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input the elements of the array
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Edge case: If there are less than 2 numbers, no valid pair exists
    if (n < 2) {
        printf("Not enough elements to form a valid pair.\n");
        return 0;
    }

    // Sort the array in descending order to easily find the largest and second-largest numbers
    qsort(arr, n, sizeof(int), compare);

    // Find the maximum sum of two distinct integers
    int max_sum = arr[0] + arr[1];

    // The second-largest integer is arr[1] after sorting
    int second_largest = arr[1];

    // Calculate the GCD of the maximum sum and the second-largest integer
    int result = gcd(max_sum, second_largest);

    // Output the result
    printf("Maximum sum of two distinct integers: %d\n", max_sum);
    printf("GCD of the maximum sum with the second-largest integer: %d\n", result);

    return 0;
}