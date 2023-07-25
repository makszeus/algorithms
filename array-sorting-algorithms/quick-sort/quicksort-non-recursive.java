import java.util.Arrays;
import java.util.Stack;

public class QuicksortNonRecursive {
    public static void quicksortNonRecursive(int[] arr) {
        Stack<Integer> stack = new Stack<>();
        stack.push(0);
        stack.push(arr.length - 1);

        while (!stack.isEmpty()) {
            int end = stack.pop();
            int start = stack.pop();

            if (start >= end) {
                continue;
            }

            int pivot = partition(arr, start, end);

            if (pivot > start + 1) {
                stack.push(start);
                stack.push(pivot - 1);
            }

            if (pivot < end - 1) {
                stack.push(pivot + 1);
                stack.push(end);
            }
        }
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

    // Example usage:
    public static void main(String[] args) {
        int[] arr = {64, 34, 25, 12, 22, 11, 90};
        quicksortNonRecursive(arr);
        System.out.println("Sorted array: " + Arrays.toString(arr));
    }
}
