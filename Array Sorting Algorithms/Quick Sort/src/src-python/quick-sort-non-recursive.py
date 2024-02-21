def quicksort_non_recursive(arr):
    stack = [(0, len(arr) - 1)]

    while stack:
        start, end = stack.pop()

        if start >= end:
            continue

        pivot = partition(arr, start, end)

        if pivot > start + 1:
            stack.append((start, pivot - 1))

        if pivot < end - 1:
            stack.append((pivot + 1, end))

def partition(arr, start, end):
    pivot = arr[end]
    i = start - 1

    for j in range(start, end):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]

    arr[i + 1], arr[end] = arr[end], arr[i + 1]
    return i + 1

# Example usage:
arr = [64, 34, 25, 12, 22, 11, 90]
quicksort_non_recursive(arr)
print("Sorted array:", arr)
