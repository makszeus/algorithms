def radix_sort(arr):
    max_value = max(arr)
    exp = 1

    while max_value // exp > 0:
        counting_sort_radix(arr, exp)
        exp *= 10

def counting_sort_radix(arr, exp):
    n = len(arr)
    output = [0] * n
    counting_arr = [0] * 10

    for num in arr:
        index = num // exp
        counting_arr[index % 10] += 1

    for i in range(1, 10):
        counting_arr[i] += counting_arr[i - 1]

    i = n - 1
    while i >= 0:
        index = arr[i] // exp
        output[counting_arr[index % 10] - 1] = arr[i]
        counting_arr[index % 10] -= 1
        i -= 1

    for i in range(n):
        arr[i] = output[i]

# Example usage:
arr = [170, 45, 75, 90, 802, 24, 2, 66]
radix_sort(arr)
print("Sorted array:", arr)
