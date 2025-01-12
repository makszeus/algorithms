import java.util.Arrays;

public class RadixSort {
    public static void radixSort(int[] arr) {
        int max = Arrays.stream(arr).max().getAsInt();
        int exp = 1;

        while (max / exp > 0) {
            countingSortRadix(arr, exp);
            exp *= 10;
        }
    }

    public static void countingSortRadix(int[] arr, int exp) {
        int n = arr.length;
        int[] output = new int[n];
        int[] countingArr = new int[10];

        for (int num : arr) {
            countingArr[(num / exp) % 10]++;
        }

        for (int i = 1; i < 10; i++) {
            countingArr[i] += countingArr[i - 1];
        }

        for (int i = n - 1; i >= 0; i--) {
            output[countingArr[(arr[i] / exp) % 10] - 1] = arr[i];
            countingArr[(arr[i] / exp) % 10]--;
        }

        System.arraycopy(output, 0, arr, 0, n);
    }

    // Example usage:
    public static void main(String[] args) {
        int[] arr = {170, 45, 75, 90, 802, 24, 2, 66};
        radixSort(arr);
        System.out.println("Sorted array: " + Arrays.toString(arr));
    }
}
