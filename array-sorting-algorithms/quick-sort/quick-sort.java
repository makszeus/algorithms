public class QuickSort {
    public static int[] quickSort(int[] arr) {
        if (arr.length <= 1) {
            return arr;
        }

        int pivot = arr[arr.length / 2];
        List<Integer> left = new ArrayList<>();
        List<Integer> middle = new ArrayList<>();
        List<Integer> right = new ArrayList<>();

        for (int num : arr) {
            if (num < pivot) {
                left.add(num);
            } else if (num == pivot) {
                middle.add(num);
            } else {
                right.add(num);
            }
        }

        int[] sortedLeft = quickSort(left.stream().mapToInt(i -> i).toArray());
        int[] sortedRight = quickSort(right.stream().mapToInt(i -> i).toArray());

        System.arraycopy(sortedLeft, 0, arr, 0, sortedLeft.length);
        for (int i = 0; i < middle.size(); i++) {
            arr[sortedLeft.length + i] = middle.get(i);
        }
        System.arraycopy(sortedRight, 0, arr, sortedLeft.length + middle.size(), sortedRight.length);

        return arr;
    }

    // Example usage:
    public static void main(String[] args) {
        int[] arr = {64, 34, 25, 12, 22, 11, 90};
        int[] sortedArr = quickSort(arr);
        System.out.println("Sorted array: " + Arrays.toString(sortedArr));
    }
}
