def comb_sort(arr):
    n = len(arr)
    gap = n
    shrink_factor = 1.3
    swapped = True

    while gap > 1 or swapped:
        gap = max(1, int(gap / shrink_factor))
        swapped = False

        for i in range(n - gap):
            if arr[i] > arr[i + gap]:
                arr[i], arr[i + gap] = arr[i + gap], arr[i]
                swapped = True

# Example usage:
arr = [64, 34, 25, 12, 22, 11, 90]
comb_sort(arr)
print("Sorted array:", arr)
