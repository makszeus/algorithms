# Radix Sort
Radix sort is a non-comparative integer sorting algorithm that sorts numbers by processing individual digits. It works based on the principle of "distributing" elements into buckets according to the value of each digit. It starts with the least significant digit (rightmost) and moves towards the most significant digit (leftmost), performing a stable sort at each iteration. Radix sort is often used to sort integers with fixed-width representations, such as integers stored in binary, decimal, or hexadecimal form.

### Complexity
The time complexity of Radix sort is $O(d * (n + k))$, where $n$ is the number of elements to be sorted, $d$ is the number of digits in the maximum number, and $k$ is the range of the input (base of the numbers, typically 10 for decimal representation). The algorithm performs counting sort for each digit (from the least significant to the most significant), and the inner counting sort takes $O(n + k)$ time for each digit.

The space complexity of the above implementation is $O(n + k)$ due to the extra array used in counting sort. In practice, the space complexity can be reduced to $O(k)$ if an in-place version of counting sort is used.

Let's understand how the Radix sort algorithm works step by step:

1. Preparation:
Obtain the maximum value "max" from the array to determine the maximum number of digits among all the numbers.
Initialize the "exp" variable to 1. It will be used to get the current digit position during the sorting process.

2. Sort by Digits:
We start sorting from the least significant digit (rightmost) and move towards the most significant digit (leftmost).
For each digit, from the least significant to the most significant, we use a stable sorting algorithm (counting sort) to distribute elements into buckets based on the value of the current digit.

3. Sorting through "Counting Sort":
Counting sort is a subroutine of the Radix sort algorithm used to sort elements based on a specific digit.
First, we create an auxiliary array "count" of size 10 (since we are using the decimal system).
We iterate through all elements of the array and increment the count for the corresponding digit by 1.
We calculate the cumulative sum in the "count" array to determine the positions of elements in the output array.
Create an output array "output" of the same size as the original array.
We iterate through the original array from right to left and distribute elements into the output array based on the current digit and their position in the "count" array.
Copy elements from "output" back into the original array to update it with the sorted elements.

4. Repeat for All Digits:
We repeat the sorting through counting sort for each digit, starting from the least significant digit (units) and ending with the most significant digit (the largest digit in "max").
After completing the last sorting for the most significant digit, the array will be fully sorted.

5. Result:
Upon completion of the Radix sort algorithm, the entire original array will be sorted in ascending order.

6. Example:
Let's consider an array [170, 45, 75, 90, 802, 24, 2, 66], and we want to sort it using Radix sort.

    - First, find the maximum value "max" from the array (802) and set "exp" to 1.
    - Start sorting from the least significant digit, which is the units (1st digit): After the first pass of counting sort: [170, 90, 802, 2, 24, 75, 45, 66]
    - Move on to the next digit, the tens (10th digit): After the second pass of counting sort: [802, 2, 24, 45, 66, 170, 75, 90]
    - After completing the sorting for the most significant digit, the array is fully sorted: [2, 24, 45, 66, 75, 90, 170, 802].
  
Thus, the array is successfully sorted using the Radix sort algorithm.
