# Selection Sort

Selection Sort is a simple comparison-based sorting algorithm. It divides the input array into two parts: the sorted part and the unsorted part. Initially, the sorted part is empty, and the unsorted part contains the entire array. The algorithm repeatedly selects the minimum element from the unsorted part and swaps it with the first element of the unsorted part. This process is repeated until the entire array becomes sorted.

Here's how the algorithm works step-by-step:

1. Find the minimum element in the unsorted part of the array.
2. Swap the minimum element with the first element of the unsorted part.
3. Expand the sorted part by moving the boundary one element to the right (i.e., increase the index of the sorted part by 1).
4. Repeat steps 1-3 until the entire array becomes sorted.

Algorithm Complexity:
Selection Sort has a time complexity of $O(n^2)$, where $n$ is the number of elements in the array. This is because for each element in the array, the algorithm needs to find the minimum element in the remaining unsorted part of the array (which requires scanning through the unsorted part), and then perform a swap operation. As a result, the number of operations increases rapidly with the size of the input array, making it inefficient for large datasets.

The algorithm also has a space complexity of $O(1)$ because it sorts the array in-place and does not require any additional memory allocation proportional to the size of the input array. Selection Sort is not considered to be efficient for large datasets due to its quadratic time complexity, but it can be useful for sorting small arrays or as an educational example of a sorting algorithm.
