public class CountingSort {
    public static int[] countingSort(int[] arr) {
        int max = Arrays.stream(arr).max().getAsInt();
        int min = Arrays.stream(arr).min().getAsInt();
        int[] countingArr = new int[max - min + 1];

        for (int num : arr) {
            countingArr[num - min]++;
        }

        int[] sortedArr = new int[arr.length];
        int sortedIndex = 0;
        for (int i = 0; i < countingArr.length; i++) {
            while (countingArr[i] > 0) {
                sortedArr[sortedIndex++] = i + min;
                countingArr[i]--;
            }
        }

        return sortedArr;
    }

    // Example usage:
    public static void main(String[] args) {
        int[] arr = {64, 34, 25, 12, 22, 11, 90};
        int[] sortedArr = countingSort(arr);
        System.out.println("Sorted array: " + Arrays.toString(sortedArr));
    }
}
