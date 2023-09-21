#include <iostream>

using namespace std;

// Linked List Node
template <typename T>
struct Node {
    T data;
    Node* next;

    explicit Node(T value) : data(value), next(nullptr) {}
};

// Singly Linked List
template <typename T>
class LinkedList {
private:
    Node<T>* head;
    int size;

public:
    LinkedList() : head(nullptr), size(0) {}

    // Insert at the beginning of the list
    void insertAtHead(T value) {
        auto* newNode = new Node<T>(value);
        newNode->next = head;
        head = newNode;
        size++;
    }

    // Insert at the end of the list
    void insertAtTail(T value) {
        auto* newNode = new Node<T>(value);

        if (head == nullptr) {
            head = newNode;
        } else {
            Node<T>* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
        size++;
    }

    // Insert at a specific position
    void insertAtPosition(int position, T value) {
        if (position < 0 || position > size) {
            cout << "Error: Invalid position.\n";
            return;
        }

        if (position == 0) {
            insertAtHead(value);
        } else if (position == size) {
            insertAtTail(value);
        } else {
            auto* newNode = new Node<T>(value);
            Node<T>* current = head;
            for (int i = 1; i < position; i++) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
            size++;
        }
    }

    // Delete the first occurrence of a value
    void deleteByValue(T value) {
        if (head == nullptr) {
            cout << "Error: List is empty.\n";
            return;
        }

        if (head->data == value) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            size--;
            return;
        }

        Node<T>* current = head;
        while (current->next != nullptr && current->next->data != value) {
            current = current->next;
        }
        if (current->next == nullptr) {
            cout << "Error: Value not found.\n";
            return;
        }
        Node<T>* temp = current->next;
        current->next = current->next->next;
        delete temp;
        size--;
    }

    // Get the value at a specific position
    T getValue(int position) {
        if (position < 0 || position >= size) {
            cout << "Error: Invalid position.\n";
            return T();
        }

        Node<T>* current = head;
        for (int i = 0; i < position; i++) {
            current = current->next;
        }
        return current->data;
    }

    // Update the value at a specific position
    void updateValue(int position, T newValue) {
        if (position < 0 || position >= size) {
            cout << "Error: Invalid position.\n";
            return;
        }

        Node<T>* current = head;
        for (int i = 0; i < position; i++) {
            current = current->next;
        }
        current->data = newValue;
    }

    // Reverse the linked list
    void reverse() {
        Node<T>* prev = nullptr;
        Node<T>* current = head;
        Node<T>* next;

        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    }

    // Print the linked list
    void print() {
        Node<T>* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Get the size of the linked list
    int getSize() {
        return size;
    }

    // Check if the linked list is empty
    bool isEmpty() {
        return size == 0;
    }

    // Clear the linked list
    void clear() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        size = 0;
    }
};

int main() {
    LinkedList<int> linkedList;
    linkedList.insertAtHead(3);
    linkedList.insertAtHead(2);
    linkedList.insertAtHead(1);

    linkedList.print();  // Output: 1 2 3

    linkedList.insertAtTail(4);
    linkedList.insertAtTail(5);

    linkedList.print();  // Output: 1 2 3 4 5

    linkedList.insertAtPosition(3, 100);

    linkedList.print();  // Output: 1 2 3 100 4 5

    linkedList.updateValue(4, 200);

    linkedList.print();  // Output: 1 2 3 100 200 5

    linkedList.deleteByValue(3);

    linkedList.print();  // Output: 1 2 100 200 5

    int value = linkedList.getValue(2);
    cout << "Value at position 2: " << value << endl;  // Output: Value at position 2: 100

    cout << "Size of the linked list: " << linkedList.getSize() << endl;  // Output: Size of the linked list: 5

    linkedList.reverse();

    linkedList.print();  // Output: 5 200 100 2 1

    linkedList.clear();

    linkedList.print();  // Output: (empty)

    return 0;
}
