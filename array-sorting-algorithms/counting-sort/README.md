# Counting Sort

Counting sort is a linear sorting algorithm that works well for integers or objects with a known range of values. It operates by counting the occurrences of each element in the input array and then reconstructing the sorted output based on the count information. Counting sort is not suitable for sorting floating-point numbers or data with a large range of values since it requires allocating an array of a size equal to the range of input values.

## Description:

1. Find the minimum and maximum values in the input array to determine the range of elements.
2. Create a "count" array of size equal to the range, initialized with all elements as 0.
3. Traverse the input array and count the occurrences of each element by incrementing the corresponding index in the "count" array.
4. Modify the "count" array to keep track of the cumulative counts.
5. Create an "output" array of the same size as the input array.
6. Traverse the input array from right to left and place each element in the correct position in the "output" array based on the count information. Decrement the count for that element to maintain stability in sorting.
7. Copy the elements from the "output" array back to the original input array to obtain the sorted result.

## Complexity:
The time complexity of Counting sort is $O(n + k)$, where $n$ is the number of elements in the input array and $k$ is the range of input. It performs a linear number of operations, making it highly efficient for small or bounded ranges of input values.

However, Counting sort requires additional space for the "count" and "output" arrays, making its space complexity $O(n + k)$. In scenarios where the range $k$ is significantly larger than the number of elements $n$, the space complexity becomes dominated by the range size.
