# Dynamic Array
The size of the array in the simplest case is fixed and must be known in advance.</br>
<br>In practice, it is often convenient to use a dynamic array, which can be expanded as needed.</br>
<br>**A dynamic array** is a data structure that provides random access and allows you to add or remove elements.</br>

Suppose the array is initially empty, then n elements are added to it sequentially, and each time a new element is added to the end.</br>
<br>Organization of a dynamic array based on a static one:
  1. Naive approach
     Initially, the array consists of one free cell. Every time we need to change the size, we will do a realocation, i.e. allocate a new array and move all the elements from the old array to the new one.
     Let's calculate the total number of "extra" data movement operations: $0 + 1 + 2 + ... + (n - 1) = \frac{̣n*(n-1)}{2}$
  2. Expansion with a margin
     To reduce the number of reallocations, we will expand the array "with a margin", leaving empty cells that can be used in the next steps.
     The number of actually occupied memory cells will be called the logical size of the dynamic array. The total number of reserved cells will be called capacity
