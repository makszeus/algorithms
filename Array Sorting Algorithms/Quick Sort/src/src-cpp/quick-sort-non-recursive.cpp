#include <iostream>
#include <stack>
using namespace std;

void quickSortNonRecursive(int arr[], int left, int right) {
    stack<int> stack;
    stack.push(left);
    stack.push(right);

    while (!stack.empty()) {
        right = stack.top();
        stack.pop();
        left = stack.top();
        stack.pop();

        int pivot = arr[(left + right) / 2];
        int i = left, j = right;

        do {
            while (arr[i] < pivot) i++;
            while (arr[j] > pivot) j--;

            if (i <= j) {
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
        } while (i <= j);

        if (left < j) {
            stack.push(left);
            stack.push(j);
        }
        if (i < right) {
            stack.push(i);
            stack.push(right);
        }
    }
}
