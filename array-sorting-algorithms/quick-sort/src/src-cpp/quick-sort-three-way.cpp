#include <iostream>
using namespace std;

void quickSortThreeWay(int arr[], int left, int right) {
    if (left < right) {
        int pivot = arr[left];
        int i = left + 1, lt = left, gt = right;

        while (i <= gt) {
            if (arr[i] < pivot)
                swap(arr[i++], arr[lt++]);
            else if (arr[i] > pivot)
                swap(arr[i], arr[gt--]);
            else
                i++;
        }

        quickSortThreeWay(arr, left, lt - 1);
        quickSortThreeWay(arr, gt + 1, right);
    }
}
