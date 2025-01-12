def counting_sort(arr):
    max_value = max(arr)
    min_value = min(arr)
    counting_arr = [0] * (max_value - min_value + 1)

    for num in arr:
        counting_arr[num - min_value] += 1

    sorted_arr = []
    for i in range(len(counting_arr)):
        for j in range(counting_arr[i]):
            sorted_arr.append(i + min_value)

    return sorted_arr

# Example usage:
arr = [64, 34, 25, 12, 22, 11, 90]
sorted_arr = counting_sort(arr)
print("Sorted array:", sorted_arr)
