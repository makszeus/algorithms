# Bubble Sort

Bubble Sort is a simple comparison-based sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. The pass through the list is repeated until the list is sorted.
Time Complexity:

1. Worst Case: $O(n^2)$ - Occurs when the input array is in reverse order, and each element needs to be compared and swapped in each pass.
2. Best Case: $O(n)$ - Occurs when the input array is already sorted, and the algorithm makes only one pass through the array without any swaps.
3. Average Case: $O(n^2)$ - On average, Bubble Sort will perform approximately $(n^2)/2$ operations.</br>
<br>Memory Complexity: Bubble Sort is an in-place sorting algorithm, meaning it does not require any additional memory allocation. Hence, it has a memory complexity of $O(1)$.</br>

# Odd-Even Sort
Odd-Even Sort is a variation of the Bubble Sort algorithm that compares and swaps elements in odd and even indexed positions alternatively. It repeatedly performs odd and even phases until the array becomes sorted.
Time Complexity:

1. Worst Case: $O(n^2)$ - Similar to Bubble Sort, it occurs when the input array is in reverse order.
2. Best Case: $O(n)$ - Occurs when the input array is already sorted, and the algorithm makes only one pass through the array without any swaps.
3. Average Case: $O(n^2)$ - On average, Odd-Even Sort will perform approximately $(n^2)/2$ operations.</br>
<br>Memory Complexity: Odd-Even Sort is an in-place sorting algorithm, so it also has a memory complexity of $O(1)$.</br>

# Comb Sort
Comb Sort is a variation of Bubble Sort that compares elements that are farther apart. It uses a gap value that shrinks at each iteration until it reaches 1, where the algorithm performs a final pass similar to Bubble Sort.
Time Complexity:

1. Worst Case: $O(n^2)$ - Occurs when the input array is in reverse order and requires a full pass for each gap size.
2. Best Case: $O(n*log(n))$ - Occurs when the input array is already sorted, and the gap value reduces quickly due to the "shrink factor."
3. Average Case: $O(n^2/2^p)$, where $p$ is the number of increments used. In general, it is considered better than $O(n^2)$ but not as good as $O(n*log(n))$.</br>
<br>Memory Complexity: Comb Sort is an in-place sorting algorithm, and its memory complexity is $O(1)$.</br>

# Cocktail Sort (Bidirectional Bubble Sort)
Cocktail Sort is a bidirectional variation of Bubble Sort, which sorts the list in both directions alternatively. It starts with the first element and goes forward, and then it reverses the direction and goes backward, repeatedly.
Time Complexity:

1. Worst Case: $O(n^2)$ - Occurs when the input array is in reverse order, and each element needs to be compared and swapped in each pass.
2. Best Case: $O(n)$ - Occurs when the input array is already sorted, and the algorithm makes only one pass through the array without any swaps.
3. Average Case: $O(n^2)$ - On average, Cocktail Sort will perform approximately $(n^2)/2$ operations.</br>
<br>Memory Complexity: Cocktail Sort is an in-place sorting algorithm, so it also has a memory complexity of $O(1)$.</br>

It's important to note that while these sorting algorithms may have different time complexities in theory, their practical performance can vary depending on the specific implementation and the size and distribution of the input data. For larger datasets, more efficient sorting algorithms like Merge Sort or Quick Sort are generally preferred due to their better average and worst-case time complexities.
