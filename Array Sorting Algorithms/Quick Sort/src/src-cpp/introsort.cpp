#include <iostream>
#include <algorithm>
using namespace std;

const int INSERTION_SORT_THRESHOLD = 16;

// Insertion sort for small subarrays
void insertionSort(int arr[], int left, int right) {
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
int medianOfThree(int arr[], int left, int right) {
    int mid = left + (right - left) / 2;

    if (arr[left] > arr[mid])
        swap(arr[left], arr[mid]);
    if (arr[left] > arr[right])
        swap(arr[left], arr[right]);
    if (arr[mid] > arr[right])
        swap(arr[mid], arr[right]);

    return arr[mid];
}

void introsortUtil(int arr[], int left, int right, int depthLimit) {
    while (right - left > INSERTION_SORT_THRESHOLD) {
        if (depthLimit == 0) {
            make_heap(arr + left, arr + right + 1);
            sort_heap(arr + left, arr + right + 1);
            return;
        }

        int pivot = medianOfThree(arr, left, right);
        int i = left, j = right;

        while (i <= j) {
            while (arr[i] < pivot) i++;
            while (arr[j] > pivot) j--;

            if (i <= j) {
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }

        depthLimit--;
        if (j - left > right - i) {
            introsortUtil(arr, i, right, depthLimit);
            right = j;
        } else {
            introsortUtil(arr, left, j, depthLimit);
            left = i;
        }
    }

    insertionSort(arr, left, right);
}

void introsort(int arr[], int left, int right) {
    int depthLimit = 2 * log(right - left);
    introsortUtil(arr, left, right, depthLimit);
}
