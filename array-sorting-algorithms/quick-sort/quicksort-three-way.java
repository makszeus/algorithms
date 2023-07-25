import java.util.Arrays;

public class QuicksortThreeWay {
    public static void quicksortThreeWay(int[] arr) {
        if (arr.length <= 1) {
            return;
        }

        int pivot = arr[arr.length / 2];
        int i = 0, j = 0, k = arr.length - 1;

        while (j <= k) {
            if (arr[j] < pivot) {
                swap(arr, i, j);
                i++;
                j++;
            } else if (arr[j] > pivot) {
                swap(arr, j, k);
                k--;
            } else {
                j++;
            }
        }

        quicksortThreeWay(Arrays.copyOfRange(arr, 0, i));
        quicksortThreeWay(Arrays.copyOfRange(arr, k + 1, arr.length));
    }

    private static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    // Example usage:
    public static void main(String[] args) {
        int[] arr = {64, 34, 25, 12, 22, 11, 90};
        quicksortThreeWay(arr);
        System.out.println("Sorted array: " + Arrays.toString(arr));
    }
}
