#include <stdio.h>

int countOccurrences(int *arr, int size, int target) {
    int count = 0;
    // Pointer to the first element of the array
    int *ptr = arr;

    // Iterate through the array using the pointer
    for (int i = 0; i < size; i++) {
        if (*ptr == target) {  // Dereference the pointer and compare
            count++;  // Increment the count if the element matches
        }
        ptr++;  // Move the pointer to the next element
    }

    return count;
}

int main() {
    int n, target;

    // Input the size of the array
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input the elements of the array
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input the target element to search for
    printf("Enter the element to count: ");
    scanf("%d", &target);

    // Call the function to count occurrences
    int count = countOccurrences(arr, n, target);

    // Output the result
    printf("The element %d appears %d times in the array.\n", target, count);

    return 0;
}