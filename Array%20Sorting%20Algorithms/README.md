# Array Sorting Algorithms

| Algorithm      | Best Time Complexity     | Average Time Complexity  | Worst Time Complexity     | Space Complexity | Stability  |
|----------------|--------------------------|--------------------------|---------------------------|------------------|------------|
| Quicksort      | $$\color{orange}Ω(n\log(n))$$  |	 $$\color{orange}Θ(n\log(n))$$	|  $$\color{red}O(n^2)$$          |  $$\color{yellowgreen}O(log(n))$$ | No  |
| Mergesort      | $$\color{orange}Ω(n\log(n))$$	|  $$\color{orange}Θ(n\log(n))$$	|  $$\color{orange}O(n\log(n))$$	|  $$\color{yellowgreen}O(n)$$    | Yes   |
| Timsort        | $$\color{yellowgreen}Ω(n)$$	  |  $$\color{orange}Θ(n\log(n))$$	|  $$\color{orange}O(n\log(n))$$	|  $$\color{yellowgreen}O(n)$$    | Yes   |
| Heapsort       | $$\color{orange}Ω(n\log(n))$$	|  $$\color{orange}Θ(n\log(n))$$	|  $$\color{orange}O(n\log(n))$$	|  $$\color{green}Θ(1)$$          | No    |
| Bubble Sort    | $$\color{yellowgreen}Ω(n)$$	  |  $$\color{red}Θ(n^2)$$	        |  $$\color{red}O(n^2)$$	        |  $$\color{green}Θ(1)$$          | Yes   |
| Insertion Sort | $$\color{yellowgreen}Ω(n)$$	  |  $$\color{red}Θ(n^2)$$	        |  $$\color{red}O(n^2)$$	        |  $$\color{green}Θ(1)$$          | Yes   |
| Selection Sort | $$\color{red}Ω(n^2)$$          |  $$\color{red}Θ(n^2)$$	        |  $$\color{red}O(n^2)$$	        |  $$\color{green}Θ(1)$$          | No    |
| Tree Sort      | $$\color{orange}Ω(n\log(n))$$  |  $$\color{orange}Θ(n\log(n))$$	|  $$\color{red}O(n^2)$$	        |  $$\color{yellowgreen}Θ(n)$$    | Yes*  |
| Shell Sort     | $$\color{orange}Ω(n\log(n))$$	|  $$\color{red}Θ(n\(log(n))^2)$$	|  $$\color{red}O(n\(log(n))^2)$$	|  $$\color{green}Θ(1)$$          | No    |
| Bucket Sort    | $$\color{green}Ω(n+k)$$	      |  $$\color{green}Θ(n+k)$$        |	 $$\color{red}O(n^2)$$          |  $$\color{yellowgreen}Θ(n)$$    | No    |
| Radix Sort     | $$\color{green}Ω(nk)$$	        |  $$\color{green}Θ(nk)$$         |	 $$\color{green}O(nk)$$         |	 $$\color{yellowgreen}Θ(n+k)$$  | No    |
| Counting Sort  | $$\color{green}Ω(n+k)$$        |	 $$\color{green}Θ(n+k)$$        |	 $$\color{green}O(n+k)$$        |	 $$\color{yellowgreen}Θ(k)$$    | No    |
| Cubesort       | $$\color{yellowgreen}Ω(n)$$    |	 $$\color{orange}Θ(n\log(n))$$  |	 $$\color{orange}O(n\log(n))$$  |	 $$\color{yellowgreen}Θ(n)$$    | No    |

_*If implemented using a stable binary search tree_
