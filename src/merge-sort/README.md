# Merge Sort

Merge sort is a popular comparison-based sorting algorithm that follows the divide-and-conquer approach. It divides the unsorted input array into smaller halves, sorts them recursively, and then merges the sorted halves to produce the final sorted array. The algorithm ensures stability, meaning that elements with equal values maintain their original relative order in the sorted output.

### Algorithm Steps:

1. Divide: The algorithm starts by dividing the unsorted array into two halves, roughly equal in size. This process is repeated recursively until the size of the array becomes 1 or 0, as a single element is considered sorted by itself.

2. Conquer: Once the array is divided into individual elements or sorted sub-arrays, the algorithm recursively sorts each sub-array using merge sort. This step continues until all the sub-arrays are sorted.

3. Merge: Finally, the sorted sub-arrays are merged back together to form a single sorted array. The merge process involves comparing elements from the left and right sub-arrays and arranging them in sorted order. This merging continues until all elements from both sub-arrays are merged into the final sorted array.

### Performance Analysis:

Best-case performance: The best-case scenario occurs when the input array is already sorted. Even in this case, merge sort divides the array into individual elements and then merges them. The best-case time complexity is $O(n*log(n))$, where $n$ is the number of elements in the input array.

Worst-case performance: The worst-case scenario arises when the input array is in reverse order. In this situation, the algorithm needs to perform comparisons for each element during the merging step. The worst-case time complexity of merge sort is $O(n*log(n))$, where $n$ is the number of elements in the input array.

Average-case performance: The average-case time complexity of merge sort is $O(n * log(n))$. Regardless of the initial order of elements, the divide-and-conquer approach ensures that the algorithm consistently divides and merges the array with a time complexity of $O(n * log(n))$ on average.

Merge sort's stable $O(n*log(n))$ time complexity for all cases makes it an efficient sorting algorithm, especially for large datasets. However, it requires additional space to create temporary arrays during the merging process, which can be a drawback for memory-constrained environments. Despite this limitation, merge sort is widely used due to its stable performance and ease of implementation.
