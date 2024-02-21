import java.util.Arrays;

public class Introsort {
    public static void introsort(int[] arr) {
        int maxDepth = 2 * (int) Math.floor(Math.log(arr.length) / Math.log(2));
        introsortHelper(arr, 0, arr.length - 1, maxDepth);
    }

    public static void introsortHelper(int[] arr, int start, int end, int maxDepth) {
        if (end - start < 16) {
            insertionSort(arr, start, end);
            return;
        }

        if (maxDepth == 0) {
            heapsort(arr, start, end);
            return;
        }

        int pivot = partition(arr, start, end);
        introsortHelper(arr, start, pivot - 1, maxDepth - 1);
        introsortHelper(arr, pivot + 1, end, maxDepth - 1);
    }

    public static int partition(int[] arr, int start, int end) {
        int pivot = arr[end];
        int i = start - 1;

        for (int j = start; j < end; j++) {
            if (arr[j] <= pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        int temp = arr[i + 1];
        arr[i + 1] = arr[end];
        arr[end] = temp;
        return i + 1;
    }

    public static void insertionSort(int[] arr, int start, int end) {
        for (int i = start + 1; i <= end; i++) {
            int key = arr[i];
            int j = i - 1;

            while (j >= start && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }

            arr[j + 1] = key;
        }
    }

    public static void heapsort(int[] arr, int start, int end) {
        for (int i = end / 2 - 1; i >= start; i--) {
            heapify(arr, end - start + 1, i, start);
        }

        for (int i = end - start; i > start; i--) {
            int temp = arr[start];
            arr[start] = arr[start + i];
            arr[start + i] = temp;
            heapify(arr, i, start, start);
        }
    }

    public static void heapify(int[] arr, int n, int i, int start) {
        int largest = i;
        int left = 2 * i + 1 - start;
        int right = 2 * i + 2 - start;

        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }

        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }

        if (largest != i) {
            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;
            heapify(arr, n, largest, start);
        }
    }

    // Example usage:
    public static void main(String[] args) {
        int[] arr = {64, 34, 25, 12, 22, 11, 90};
        introsort(arr);
        System.out.println("Sorted array: " + Arrays.toString(arr));
    }
}
