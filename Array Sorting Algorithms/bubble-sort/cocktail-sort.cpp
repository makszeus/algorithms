#include <iostream>

void cocktailSort(int arr[], int n) {
    bool swapped = true;
    int start = 0;
    int end = n - 1;

    while (swapped) {
        // Reset the swapped flag on entering the loop because it might be true from a previous iteration.
        swapped = false;

        // Perform the left-to-right pass (similar to Bubble Sort)
        for (int i = start; i < end; i++) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        // If no two elements were swapped, the array is already sorted.
        if (!swapped) {
            break;
        }

        // Mark the last element as sorted (reduce the effective array size by one)
        end--;

        // Perform the right-to-left pass (similar to Reverse Bubble Sort)
        for (int i = end - 1; i >= start; i--) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        // Mark the first element as sorted (increase the effective array size by one)
        start++;
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    cocktailSort(arr, n);

    std::cout << "\nSorted array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    return 0;
}
