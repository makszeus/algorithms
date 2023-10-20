#include <iostream>

using namespace std;

// Linked List Node
struct Node {
    int data;
    Node* next;
};

// Stack using Linked List
class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;  // Initialize an empty stack
    }

    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Error: Stack is empty.\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Error: Stack is empty.\n";
            return -1;
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};



int main() {
    // Example usage of Stack
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << "Stack: ";
    while (!stack.isEmpty()) {
        cout << stack.peek() << " ";  // Output: 3 2 1
        stack.pop();
    }
    cout << endl;


    return 0;
}
