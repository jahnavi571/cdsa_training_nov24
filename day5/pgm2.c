#include <stdio.h>

int main() {
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Duplicate elements in the array are:\n");
    int hasDuplicates = 0;  

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                printf("%d\n", arr[i]);
                hasDuplicates = 1;
                break;
            }
        }
    }

    if (!hasDuplicates) {
        printf("No duplicate elements found.\n");
    }

    return 0;
}