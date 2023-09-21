#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class ArrayList {
private:
    T* arr;
    int capacity;
    int size;

public:
    ArrayList() : capacity(10), size(0) {
        arr = new T[capacity];
    }

    explicit ArrayList(int initialCapacity) : capacity(initialCapacity), size(0) {
        arr = new T[capacity];
    }

    ~ArrayList() {
        delete[] arr;
    }

    void resize() {
        capacity *= 2;
        T* newArr = new T[capacity];
        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }

    void insert(T value, int index) {
        if (index < 0 || index > size) {
            throw out_of_range("Invalid index");
        }

        if (size == capacity) {
            resize();
        }

        for (int i = size - 1; i >= index; i--) {
            arr[i + 1] = arr[i];
        }

        arr[index] = value;
        size++;
    }

    void append(T value) {
        insert(value, size);
    }

    void removeAt(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Invalid index");
        }

        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }

        size--;
    }

    void remove(T value) {
        int index = indexOf(value);
        if (index != -1) {
            removeAt(index);
        }
    }

    void clear() {
        size = 0;
    }

    bool contains(T value) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == value) {
                return true;
            }
        }
        return false;
    }

    int indexOf(T value) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == value) {
                return i;
            }
        }
        return -1;
    }

    T get(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Invalid index");
        }
        return arr[index];
    }

    void set(int index, T value) {
        if (index < 0 || index >= size) {
            throw out_of_range("Invalid index");
        }
        arr[index] = value;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }
};

int main() {
    ArrayList<int> list;
    list.append(10);
    list.append(20);
    list.append(30);

    cout << "Size: " << list.getSize() << endl;  // Output: Size: 3
    cout << "Is Empty: " << boolalpha << list.isEmpty() << endl;  // Output: Is Empty: false

    cout << "Elements: ";
    for (int i = 0; i < list.getSize(); i++) {
        cout << list.get(i) << " ";  // Output: Elements: 10 20 30
    }
    cout << endl;

    list.insert(15, 1);
    cout << "Elements: ";
    for (int i = 0; i < list.getSize(); i++) {
        cout << list.get(i) << " ";  // Output: Elements: 10 15 20 30
    }
    cout << endl;

    list.remove(20);
    cout << "Elements: ";
    for (int i = 0; i < list.getSize(); i++) {
        cout << list.get(i) << " ";  // Output: Elements: 10 15 30
    }
    cout << endl;

    list.set(2, 25);
    cout << "Elements: ";
    for (int i = 0; i < list.getSize(); i++) {
        cout << list.get(i) << " ";  // Output: Elements: 10 15 25
    }
    cout << endl;

    list.clear();
    cout << "Size: " << list.getSize() << endl;  // Output: Size: 0
    cout << "Is Empty: " << boolalpha << list.isEmpty() << endl;  // Output: Is Empty: true

    return 0;
}
