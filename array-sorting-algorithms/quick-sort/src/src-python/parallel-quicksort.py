import concurrent.futures

def parallel_quicksort(arr, workers=4):
    if len(arr) <= 1:
        return arr

    pivot = arr[len(arr) // 2]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]

    with concurrent.futures.ThreadPoolExecutor(max_workers=workers) as executor:
        futures = [
            executor.submit(parallel_quicksort, sub_arr, workers) for sub_arr in (left, right)
        ]

    sorted_left = futures[0].result()
    sorted_right = futures[1].result()

    return sorted_left + middle + sorted_right

# Example usage:
arr = [64, 34, 25, 12, 22, 11, 90]
sorted_arr = parallel_quicksort(arr)
print("Sorted array:", sorted_arr)
