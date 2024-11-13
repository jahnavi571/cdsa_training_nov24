#include <stdio.h>

void reverseArray(int *arr, int size) {
    int *start = arr;              // Pointer to the first element of the array
    int *end = arr + size - 1;     // Pointer to the last element of the array

    while (start < end) {
        // Swap the elements pointed to by start and end
        int temp = *start;
        *start = *end;
        *end = temp;

        // Move the pointers towards each other
        start++;
        end--;
    }
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

    // Call the function to reverse the array
    reverseArray(arr, n);

    // Print the reversed array
    printf("Reversed array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}