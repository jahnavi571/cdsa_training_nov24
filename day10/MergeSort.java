import java.util.Arrays;

public class MergeSort {

    // Main function to sort the array
    public static void mergeSort(int[] arr) {
        if (arr.length < 2) {
            return; // Base case: a single element is already sorted
        }

        // Find the middle point and divide the array into two halves
        int mid = arr.length / 2;

        // Create left and right subarrays
        int[] left = Arrays.copyOfRange(arr, 0, mid);
        int[] right = Arrays.copyOfRange(arr, mid, arr.length);

        // Recursively sort both halves
        mergeSort(left);
        mergeSort(right);

        // Merge the sorted halves
        merge(arr, left, right);
    }

    // Merge two sorted arrays into a single sorted array
    private static void merge(int[] arr, int[] left, int[] right) {
        int i = 0, j = 0, k = 0;

        // Merge the two subarrays while comparing elements
        while (i < left.length && j < right.length) {
            if (left[i] <= right[j]) {
                arr[k++] = left[i++];
            } else {
                arr[k++] = right[j++];
            }
        }

        // Copy any remaining elements from left subarray
        while (i < left.length) {
            arr[k++] = left[i++];
        }

        // Copy any remaining elements from right subarray
        while (j < right.length) {
            arr[k++] = right[j++];
        }
    }

    // Main function to test merge sort
    public static void main(String[] args) {
        int[] arr = { 38, 27, 43, 3, 9, 82, 10 };
        System.out.println("Original array: " + Arrays.toString(arr));

        // Call mergeSort
        mergeSort(arr);

        System.out.println("Sorted array: " + Arrays.toString(arr));
    }
}

