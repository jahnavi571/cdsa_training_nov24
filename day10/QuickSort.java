import java.util.Arrays;

public class QuickSort {

    // Main function to sort the array
    public static void quickSort(int[] arr, int low, int high) {
        if (low < high) {
            // Find the pivot element such that the element at the pivot is
            // in the correct position
            int pi = partition(arr, low, high);

            // Recursively sort the elements before and after partition
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

    // Partition function to find the pivot index
    private static int partition(int[] arr, int low, int high) {
        // Choose the rightmost element as pivot
        int pivot = arr[high];
        int i = (low - 1); // Index of smaller element

        // Traverse through all elements, compare each with pivot
        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++; // Increment the index of smaller element
                swap(arr, i, j);
            }
        }

        // Swap the pivot element with the element at index i+1
        swap(arr, i + 1, high);
        return i + 1; // Return the partitioning index
    }

    // Helper function to swap two elements in the array
    private static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    // Main function to test quick sort
    public static void main(String[] args) {
        int[] arr = { 10, 7, 8, 9, 1, 5 };
        int n = arr.length;
        System.out.println("Original array: " + Arrays.toString(arr));

        // Call quickSort
        quickSort(arr, 0, n - 1);

        System.out.println("Sorted array: " + Arrays.toString(arr));
    }
}
