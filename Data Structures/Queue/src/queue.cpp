#include <iostream>

using namespace std;

// Linked List Node
struct Node {
    int data;
    Node* next;
};

// Queue using Linked List
class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = nullptr;  // Initialize an empty queue
    }

    void enqueue(int data) {
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

    void dequeue() {
        if (isEmpty()) {
            cout << "Error: Queue is empty.\n";
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;
        if (front == nullptr) {
            rear = nullptr;  // Reset the rear pointer if the queue becomes empty
        }
    }

    int peek() {
        if (isEmpty()) {
            cout << "Error: Queue is empty.\n";
            return -1;
        }
        return front->data;
    }

    bool isEmpty() {
        return front == nullptr;
    }
};


int main() {

    // Example usage of Queue
    Queue queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    cout << "Queue: ";
    while (!queue.isEmpty()) {
        cout << queue.peek() << " ";  // Output: 1 2 3
        queue.dequeue();
    }
    cout << endl;
    
    return 0;
}
