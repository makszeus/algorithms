def quicksort_three_way(arr):
    if len(arr) <= 1:
        return arr

    pivot = arr[len(arr) // 2]
    low, mid, high = [], [], []

    for num in arr:
        if num < pivot:
            low.append(num)
        elif num == pivot:
            mid.append(num)
        else:
            high.append(num)

    return quicksort_three_way(low) + mid + quicksort_three_way(high)

# Example usage:
arr = [64, 34, 25, 12, 22, 11, 90]
sorted_arr = quicksort_three_way(arr)
print("Sorted array:", sorted_arr)

