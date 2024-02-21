# Knuth–Morris–Pratt Algorithm

The Knuth–Morris–Pratt (KMP) Algorithm is a linear time complexity algorithm used for pattern searching in strings. It was developed by Donald Knuth, Vaughan Pratt, and James H. Morris in 1977.

The KMP algorithm uses the concept of a "prefix table" or "failure function" to avoid unnecessary comparisons. When a mismatch occurs, the algorithm uses this table to skip over characters that it knows will anyway match.

The time complexity of the KMP algorithm is O(n), where n is the length of the text. This makes it highly efficient for pattern searching in large texts.

This repository contains an implementation of the KMP algorithm in multiple programming languages. Each implementation includes comments explaining the code for better understanding.
