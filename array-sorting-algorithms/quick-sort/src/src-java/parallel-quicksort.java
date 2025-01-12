import java.util.Arrays;
import java.util.concurrent.ForkJoinPool;
import java.util.concurrent.RecursiveTask;

public class ParallelQuicksort {
    public static void parallelQuicksort(int[] arr) {
        ForkJoinPool pool = new ForkJoinPool();
        pool.invoke(new QuicksortTask(arr, 0, arr.length - 1));
        pool.shutdown();
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

    private static class QuicksortTask extends RecursiveTask<Void> {
        private static final int THRESHOLD = 16;
        private int[] arr;
        private int start;
        private int end;

        public QuicksortTask(int[] arr, int start, int end) {
            this.arr = arr;
            this.start = start;
            this.end = end;
        }

        @Override
        protected Void compute() {
            if (end - start < THRESHOLD) {
                insertionSort(arr, start, end);
            } else {
                int pivot = partition(arr, start, end);
                QuicksortTask left = new QuicksortTask(arr, start, pivot - 1);
                QuicksortTask right = new QuicksortTask(arr, pivot + 1, end);
                invokeAll(left, right);
            }

            return null;
        }

        private int partition(int[] arr, int start, int end) {
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
    }

    // Example usage:
    public static void main(String[] args) {
        int[] arr = {64, 34, 25, 12, 22, 11, 90};
        parallelQuicksort(arr);
        System.out.println("Sorted array: " + Arrays.toString(arr));
    }
}
