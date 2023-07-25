import sys

def introsort(arr):
    max_depth = 2 * (len(arr)).bit_length()
    introsort_helper(arr, 0, len(arr) - 1, max_depth)

def introsort_helper(arr, start, end, max_depth):
    if end - start < 16:
        insertion_sort(arr, start, end)
        return

    if max_depth == 0:
        heapsort(arr, start, end)
        return

    pivot = partition(arr, start, end)
    introsort_helper(arr, start, pivot - 1, max_depth - 1)
    introsort_helper(arr, pivot + 1, end, max_depth - 1)

def partition(arr, start, end):
    pivot = arr[end]
    i = start - 1

    for j in range(start, end):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]

    arr[i + 1], arr[end] = arr[end], arr[i + 1]
    return i + 1

def insertion_sort(arr, start, end):
    for i in range(start + 1, end + 1):
        key = arr[i]
        j = i - 1
        while j >= start and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

def heapsort(arr, start, end):
    def heapify(arr, n, i):
        largest = i
        left = 2 * i + 1
        right = 2 * i + 2

        if left < n and arr[i] < arr[left]:
            largest = left

        if right < n and arr[largest] < arr[right]:
            largest = right

        if largest != i:
            arr[i], arr[largest] = arr[largest], arr[i]
            heapify(arr, n, largest)

    n = end - start + 1

    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)

    for i in range(n - 1, 0, -1):
        arr[start], arr[start + i] = arr[start + i], arr[start]
        heapify(arr, i, 0)

# Example usage:
arr = [64, 34, 25, 12, 22, 11, 90]
introsort(arr)
print("Sorted array:", arr)
