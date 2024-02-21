#include <iostream>
#include <vector>

void insertionSort(std::vector <int> &arr) {

    for (int i = 1; i < arr.size(); ++i) {

        int j = i - 1;
        while (j >= 0 and arr[j] > arr[j + 1]) {
            std::swap(arr[j], arr[j + 1]); j--;
        }

    }

}

int main() {

    std::vector <int> a = {88, 15, 26, -4, 84, -41, 75};
    insertionSort(a); for (const int &i : a) std::cout << i << " ";

    return 0;
}
