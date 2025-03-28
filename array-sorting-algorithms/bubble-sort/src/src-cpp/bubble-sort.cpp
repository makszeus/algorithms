#include <iostream>

void bubble_sort(int *arr, const int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    int arr[] = {5, 8, -1, 6, -7, 12, -2, 0, -3};
    constexpr int size = std::size(arr);
    bubble_sort(arr, size);
    for (const auto &i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}