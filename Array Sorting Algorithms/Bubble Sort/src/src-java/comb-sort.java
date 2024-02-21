import java.util.Arrays;

public class CombSort {
    public static void combSort(int[] arr) {
        int n = arr.length;
        int gap = n;
        double shrinkFactor = 1.3;
        boolean swapped = true;

        while (gap > 1 || swapped) {
            gap = Math.max(1, (int) (gap / shrinkFactor));
            swapped = false;

            for (int i = 0; i + gap < n; i++) {
                if (arr[i] > arr[i + gap]) {
                    int temp = arr[i];
                    arr[i] = arr[i + gap];
                    arr[i + gap] = temp;
                    swapped = true;
                }
            }
        }
    }

    // Example usage:
    public static void main(String[] args) {
        int[] arr = {64, 34, 25, 12, 22, 11, 90};
        combSort(arr);
        System.out.println("Sorted array: " + Arrays.toString(arr));
    }
}
