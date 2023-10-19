import java.util.Arrays;

public class CocktailSort {
    public static void cocktailSort(int[] arr) {
        boolean swapped;
        int n = arr.length;
        int start = 0;
        int end = n - 1;

        do {
            // Forward pass (Bubble sort from left to right)
            swapped = false;
            for (int i = start; i < end; i++) {
                if (arr[i] > arr[i + 1]) {
                    int temp = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = temp;
                    swapped = true;
                }
            }

            // If no elements were swapped, the array is already sorted
            if (!swapped) {
                break;
            }

            // Decrement end, as the largest element is now at the end of the array
            end--;

            // Backward pass (Bubble sort from right to left)
            swapped = false;
            for (int i = end - 1; i >= start; i--) {
                if (arr[i] > arr[i + 1]) {
                    int temp = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = temp;
                    swapped = true;
                }
            }

            // Increment start, as the smallest element is now at the start of the array
            start++;
        } while (swapped);
    }

    // Example usage:
    public static void main(String[] args) {
        int[] arr = {64, 34, 25, 12, 22, 11, 90};
        cocktailSort(arr);
        System.out.println("Sorted array: " + Arrays.toString(arr));
    }
}
