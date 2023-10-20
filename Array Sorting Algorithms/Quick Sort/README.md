# Quick Sort
Quick Sort is an efficient recursive sorting algorithm that follows the "divide and conquer" principle. The algorithm selects a pivot element from the array and rearranges all elements smaller than the pivot to its left and all elements larger than the pivot to its right. It then recursively applies the same procedure to the left and right subarrays until all elements are in their correct positions.

## Complexity
1. Worst-case

   Suppose we partition an array such that one part contains $n - 1$ elements and the second part contains $1$. Since the partitioning procedure takes time $Θ(n)$, for the running time $T(n)$ we obtain the relation: $$T(n) = T(n − 1) + Θ(n) = \sum_{k=1}^n Θ(k) = Θ(\sum_{k=1}^n k) = Θ(n^2).$$ We see that for the maximum unbalanced partitioning, the running time is $Θ(n^2)$. In particular, this happens if the array is initially sorted.
  
2. The running time of the Quick sort algorithm is $O(n\log(n))$.

   ▹</br>
   Let X is the total number of comparisons of elements with the reference during the sorting operation. We need to calculate the total number of comparisons. Let's rename the array elements as $z_1...z_n$ where $z_i$ is the smallest element in order. We also introduce the set $z_{ij}={z_i,z_{i + 1}...z_j}$.
Note that each pair of elements is compared not more than once, since the element is compared with the reference element, and the reference element will no longer participate in the comparison after partitioning.
Since each pair of elements is compared at most once, the total number of comparisons is expressed as
$$X = \sum_{i=1}^{n−1} \sum_{j=i+1}^{n} X_{ij},$$ where $X_{ij} = 1$ if there was a comparison $z_i$ and $z_j$; $X_{ij} = 0$ if there was no comparison.</br>
Let's apply the expectation calculation operation to both parts of the equality and taking advantage of its linearity we obtain $$E[X]=E[\sum_{i=1}^{n−1} \sum_{j=i+1}^{n} X_{ij}] = \sum_{i=1}^{n−1} \sum_{j=i+1}^n E[X_{ij}]=\sum_{i=1}^{n−1} \sum_{j=i+1}^n Pr \\{z_i\text{ is compared to }z_j\\}.$$ It remains to calculate the value of $Pr {z_i\text{ is compared to }z_j}$ - probability that $z_i$ is compared to $z_j.$ Since it is assumed that all elements in the array are distinct, choosing $x$ as a reference element, subsequently no $z_i$ and $z_j$ for which $z_i < x < z_j.$ On the other hand, if $z_i$ is selected as a reference, it will be compared with every element $Z_{ij}$ except itself. Thus the elements $z_i$ and $z_j$ are compared if and only if the first element in the set $Z_{ij}$ one of them was selected as a reference element.
$$Pr{z_i\text{ is compared with }z_j} = Pr\\{\text{ the first reference element was }z_i\text{ or }z_j\\} = $$
$$= Pr\\{\text{ the first reference element was }z_i\\} + Pr\\{\text{ first anchor element was }z_j\\} = \frac{1}{j−i+1} + \frac{1}{j−i+1} = \frac{2}{j−i+1}.$$
$$E[X] = \sum_{i=1}^{n-1}\sum_{j=i+1}^{n} \frac{2}{j-i+1} = \sum_{i=1}^{n-1}\sum_{k=1}^{n-i} \frac{2}{k+1} < \sum_{i=1}^{n-1}\sum_{k=1}^{n-i} \frac{2}{k} = \sum_{i=1}^{n-1} O(\log(n)) = O(n\log(n)).$$
◃</br>
The expectation of the running time of the Quick sort will be $O(n\log(n))$.

## Modifications
1. Non-recursive implementation of Quick sort
   
   To perform Quick sort, you can use a stack that contains a list of actions to be performed as sortable subarrays. Each time a subarray needs to be processed, it is pushed out of the stack. After splitting the array, two subarrays requiring further processing are obtained and pushed onto the stack. The non-recursive implementation presented below uses the stack by replacing recursive calls by placing function parameters on the stack, and procedure calls and exits by a loop that fetches parameters from the stack and processes them until the stack is empty. We place the larger of the two subarrays on the stack first so that the maximum depth of the stack when sorting $N$ elements does not exceed the value of $log(n)$.

```code
     void quicksort(a: T[n], int l, int r)
     stack< pair<int,int> > s   
     s.push(l, r)
     while (s.isNotEmpty)
        (l, r) = s.pop()
        if (r ⩽ l)
           continue
        int i = partition(a, l, r)
        if (i - l > r - i) 
           s.push(l, i - 1)
           s.push(i + 1, r)
        else
           s.push(i + 1, r)
           s.push(l, i - 1)
```
   Alternatively, you can use the usual recursive version, in which, instead of recursively calling the splitting procedure for both found subarrays after splitting the array, the recursive call is made only for the smaller subarray, and the larger one is processed in a loop within the same procedure call.</br>
   From the efficiency point of view, there is practically no difference in the average case: the overhead for an additional recursive call and for organizing the comparison of subarray and loop lengths are of approximately the same order. But the recursion depth will never exceed $log(n)$, and in the worst case of degenerate partitioning it will not exceed $1$ at all. All processing will take place in the loop of the first recursion level.

2. Improved Quick Sort

   Choosing the median of the first, middle, and last elements as the separating element and cutting off the recursion of smaller subarrays can result in a significant increase in the efficiency of quicksort. median function
  returns the index of the element that is the median of three elements. After that, it and the middle element of the array are swapped, while the median becomes the separating element. Small arrays (length $M=11$ and less) are ignored during the splitting process, then insertion sort is used to end the sort.

```code
  const int M = 10
  void quicksort(a: T[n], int l, int r)
     if (r - l ⩽ M)
        insertion(a, l, r)
        return
     int med = median(a[l], a[(l + r) / 2], a[r])
     swap(a[med], a[(l + r) / 2])
     int i = partition(a, l, r)
     quicksort(a, l, i)
     quicksort(a, i + 1, r)
```

   In general, you can apply any heuristics to choose the pivot. For example, in the standard implementation in Java, the middle of 7 elements, evenly distributed throughout the array, is chosen as the separating element.

3. Quick sort with three parts

   When the array to be sorted has many duplicate keys, previous implementations of quicksort can be greatly improved. For example, an array that consists of equal keys does not need to be further sorted at all, but previous implementations continue the splitting process by processing smaller and smaller subarrays, no matter how large the source file is. The program is based on the division of the array into three parts: into elements smaller than the separating element $a[l] ... a[i]$, elements equal to the separating element $a[i+1]…a[j−1]$, and elements greater than the separating element $a[j]…a[r]$. The sort is then completed with two recursive calls.

   Array elements equal to the separating element are between $l$ and $p$ and between $q$ and $r$. In the separating loop, when the lookup pointers stop changing and the values of $i$ are exchanged and $j$, each of these elements is checked for equality to the separating element. If the element currently on the left is equal to the separating element, then using the exchange operation it is placed on the left side of the array, if the element that is now on the right is equal to the separating element, then as a result of the exchange operation it is placed on the right side of the array. After the pointers intersect, the elements equal to the separating element and located at different ends of the array, after the exchange operation, fall into their final positions. After that, the specified keys can be excluded from the subarrays for which subsequent recursive calls are made.

```code
     void quicksort(a: T[n], int l, int r)
     T v = a[r]
     if (r ⩽ l)
        return
     int i = l
     int j = r - 1
     int p = l - 1
     int q = r
     while (i ⩽ j) 
        while (a[i] < v) 
           i++
        while (a[j] > v) 
           j--
        if (i ⩾ j)
           break
        swap(a[i], a[j])
        if (a[i] == v)
           p++
           swap(a[p], a[i])
        i++
        if (a[j] == v)
           q--
           swap(a[q], a[j])
        j--
     swap(a[i], a[r])
     j = i - 1
     i++
     for (int k = l; k ⩽ p; k++, j--) 
        swap(a[k], a[j])
     for (int k = r - 1; k ⩾ q; k--, i++) 
        swap(a[k], a[i]) 
     quicksort(a, l, j) 
     quicksort(a, i, r)
```
4. Parallel sort
  
   Another optimization is a parallel sort based on quick sort. Let the initial data set be located on the first processor, the algorithm starts from it. Then the original array will be divided into two parts, the smaller of which will be transferred to another free processor, the larger one will remain on the original for further processing. Further, both parts will again be divided and again large parts will remain on the two original ones, and the smaller ones will be sent to other processors. This is the speedup of the algorithm. When all processors are involved, all parts will be sorted in parallel by a sequential algorithm.

5. Introsort

   To prevent quick sort from degrading to $O(n^2)$ for bad input, you can also use the Introsort sorting algorithm. It uses quicksort and switches to heapsort when the recursion depth exceeds some predetermined level (for example, the logarithm of the number of elements sorted). Since after several iterations of quicksort using different heuristics, the array is more likely to be "almost sorted", heapsort can finish the job fairly quickly. Also, heapsort is good because it requires $O(1)$ additional memory, as opposed to, for example, merge sort, which would require $O(n)$ additional memory.   
