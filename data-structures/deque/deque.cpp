#include <iostream>

using namespace std;

// Linked List Node
struct Node {
    int data;
    Node* next;
};

// Deque using Linked List
class Deque {
private:
    Node* front;
    Node* rear;

public:
    Deque() {
        front = rear = nullptr;  // Initialize an empty deque
    }

    void insertFront(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = front;

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            front = newNode;
        }
    }

    void insertRear(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Error: Deque is empty.\n";
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;
        if (front == nullptr) {
            rear = nullptr;  // Reset the rear pointer if the deque becomes empty
        }
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Error: Deque is empty.\n";
            return;
        }
        if (front == rear) {
            delete front;
            front = rear = nullptr;
            return;
        }
        Node* current = front;
        while (current->next != rear) {
            current = current->next;
        }
        delete rear;
        rear = current;
        rear->next = nullptr;
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Error: Deque is empty.\n";
            return -1;
        }
        return front->data;
    }

    int getRear() {
        if (isEmpty()) {
            cout << "Error: Deque is empty.\n";
            return -1;
        }
        return rear->data;
    }

    bool isEmpty() {
        return front == nullptr;
    }
};

int main() {

    // Example usage of Deque
    Deque deque;
    deque.insertFront(1);
    deque.insertFront(2);
    deque.insertRear(3);

    cout << "Deque: ";
    cout << deque.getFront() << " ";  // Output: 2
    cout << deque.getRear() << " ";   // Output: 3
    deque.deleteFront();
    cout << deque.getFront() << " ";  // Output: 1
    deque.deleteRear();
    cout << deque.getRear() << " ";   // Output: 1
    cout << endl;

    return 0;
}
