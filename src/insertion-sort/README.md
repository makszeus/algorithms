# Insertion Sort

The insertion sort algorithm is a simple sorting algorithm that builds the final sorted array one item at a time. It iterates through the input array, removing one element at a time and inserting it into the correct position in the sorted part of the array. Here are the best-case, worst-case, and average-case performances of the insertion sort algorithm:

### Best-case performance:
The best-case performance of the insertion sort algorithm occurs when the input array is already sorted. In this scenario, the algorithm simply checks each element once and finds that they are already in their correct positions. Therefore, the time complexity in the best case is $O(n)$, where $n$ is the number of elements in the array.

### Worst-case performance:
The worst-case performance of the insertion sort algorithm happens when the input array is sorted in reverse order (i.e., in descending order). In this situation, each element in the unsorted part of the array needs to be compared with and shifted (moved) to the correct position in the sorted part of the array. This results in the maximum number of comparisons and shifts. The time complexity in the worst case is $O(n^2)$, where $n$ is the number of elements in the array.

### Average-case performance:
The average-case performance of the insertion sort algorithm is also $O(n^2)$. On average, insertion sort requires approximately $n^2/4$ comparisons and $n^2/4$ shifts to sort an array of size $n$. Although this average-case analysis provides a better understanding of the algorithm's behavior than the worst-case analysis, it still demonstrates that the insertion sort is not the most efficient sorting algorithm for large input sizes.

Insertion sort is an "in-place" sorting algorithm and has an advantage for small input sizes and partially sorted arrays. However, for larger arrays, more efficient sorting algorithms like merge sort, quicksort, or heapsort are generally preferred due to their better average and worst-case performances.
