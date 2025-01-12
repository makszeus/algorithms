#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>

const int INSERTION_SORT_THRESHOLD = 16;

// Insertion sort for small subarrays
void insertionSort(std::vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

// Median of three for choosing pivot
int medianOfThree(std::vector<int>& arr, int left, int right) {
    int mid = left + (right - left) / 2;

    if (arr[left] > arr[mid])
        std::swap(arr[left], arr[mid]);
    if (arr[left] > arr[right])
        std::swap(arr[left], arr[right]);
    if (arr[mid] > arr[right])
        std::swap(arr[mid], arr[right]);

    return arr[mid];
}

void quicksort(std::vector<int>& arr, int left, int right) {
    if (right - left <= INSERTION_SORT_THRESHOLD) {
        insertionSort(arr, left, right);
        return;
    }

    int pivot = medianOfThree(arr, left, right);
    int i = left, j = right;

    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;

        if (i <= j) {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (j > left) {
        std::thread leftThread(quicksort, std::ref(arr), left, j);
        leftThread.join();
    }
    if (i < right) {
        std::thread rightThread(quicksort, std::ref(arr), i, right);
        rightThread.join();
    }
}

int main() {
    std::vector<int> arr = {7, 2, 9, 1, 6, 4, 8, 3, 5};
    
    std::cout << "Unsorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    quicksort(arr, 0, arr.size() - 1);

    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
