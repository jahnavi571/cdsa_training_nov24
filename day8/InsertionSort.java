public class InsertionSort {

    // Method to perform Insertion Sort
    public static void insertionSort(int[] array) {
        // Traverse through 1 to array.length
        for (int i = 1; i < array.length; i++) {
            int key = array[i];  // The element to be inserted
            int j = i - 1;

            // Move elements of array[0..i-1], that are greater than the key,
            // to one position ahead of their current position
            while (j >= 0 && array[j] > key) {
                array[j + 1] = array[j];
                j = j - 1;
            }
            array[j + 1] = key;  // Place the key at the correct position
        }
    }

    // Helper method to print the array
    public static void printArray(int[] array) {
        for (int i = 0; i < array.length; i++) {
            System.out.print(array[i] + " ");
        }
        System.out.println();
    }

    // Main method to test Insertion Sort
    public static void main(String[] args) {
        int[] array = {12, 11, 13, 5, 6};

        System.out.println("Original Array:");
        printArray(array);

        insertionSort(array);  // Sort the array using Insertion Sort

        System.out.println("Sorted Array:");
        printArray(array);
    }
}

