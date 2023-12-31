import java.util.Arrays;

public class OddEvenSort {
    public static void oddEvenSort(int[] arr) {
        int n = arr.length;
        boolean sorted = false;

        while (!sorted) {
            sorted = true;

            // Sort odd-indexed elements
            for (int i = 1; i < n - 1; i += 2) {
                if (arr[i] > arr[i + 1]) {
                    int temp = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = temp;
                    sorted = false;
                }
            }

            // Sort even-indexed elements
            for (int i = 0; i < n - 1; i += 2) {
                if (arr[i] > arr[i + 1]) {
                    int temp = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = temp;
                    sorted = false;
                }
            }
        }
    }

    // Example usage:
    public static void main(String[] args) {
        int[] arr = {64, 34, 25, 12, 22, 11, 90};
        oddEvenSort(arr);
        System.out.println("Sorted array: " + Arrays.toString(arr));
    }
}
