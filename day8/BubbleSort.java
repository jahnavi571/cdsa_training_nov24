public class BubbleSort {

    // Method to perform Bubble Sort
    public static void bubbleSort(int[] arr) {
        int n = arr.length;

        // Outer loop for number of passes
        for (int i = 0; i < n - 1; i++) {
            // Flag to optimize and break early if no swaps are made
            boolean swapped = false;

            // Inner loop for comparing adjacent elements
            for (int j = 0; j < n - 1 - i; j++) {
                if (arr[j] > arr[j + 1]) {
                    // Swap if the element found is greater than the next element
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    swapped = true;
                }
            }

            // If no elements were swapped in the inner loop, the array is already sorted
            if (!swapped) {
                break;
            }
        }
    }

    // Method to print the array
    public static void printArray(int[] arr) {
        for (int num : arr) {
            System.out.print(num + " ");
        }
        System.out.println();
    }

    // Main method to test the sorting
    public static void main(String[] args) {
        int[] arr = { 64, 34, 25, 12, 22, 11, 90 };

        System.out.println("Original Array:");
        printArray(arr);

        // Call bubbleSort method
        bubbleSort(arr);

        System.out.println("Sorted Array:");
        printArray(arr);
    }
}

