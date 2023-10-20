#include <iostream>

enum Color { RED, BLACK };

struct Node {
    int data;
    Color color;
    Node* left;
    Node* right;
    Node* parent;

    // Constructor
    explicit Node(int data) {
        this->data = data;
        color = RED;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
};

class RedBlackTree {
private:
    Node* root;

    // Function to perform a left rotate
    void leftRotate(Node* node) {
        Node* newParent = node->right;
        node->right = newParent->left;
        if (newParent->left != nullptr) {
            newParent->left->parent = node;
        }
        newParent->parent = node->parent;
        if (node->parent == nullptr) {
            root = newParent;
        } else if (node == node->parent->left) {
            node->parent->left = newParent;
        } else {
            node->parent->right = newParent;
        }
        newParent->left = node;
        node->parent = newParent;
    }

    // Function to perform a right rotate
    void rightRotate(Node* node) {
        Node* newParent = node->left;
        node->left = newParent->right;
        if (newParent->right != nullptr) {
            newParent->right->parent = node;
        }
        newParent->parent = node->parent;
        if (node->parent == nullptr) {
            root = newParent;
        } else if (node == node->parent->right) {
            node->parent->right = newParent;
        } else {
            node->parent->left = newParent;
        }
        newParent->right = node;
        node->parent = newParent;
    }

    // Function to fix the Red-Black Tree after insertion
    void fixInsert(Node* node) {
        while (node != root && node->parent->color == RED) {
            if (node->parent == node->parent->parent->left) {
                Node* uncle = node->parent->parent->right;
                if (uncle != nullptr && uncle->color == RED) {
                    node->parent->color = BLACK;
                    uncle->color = BLACK;
                    node->parent->parent->color = RED;
                    node = node->parent->parent;
                } else {
                    if (node == node->parent->right) {
                        node = node->parent;
                        leftRotate(node);
                    }
                    node->parent->color = BLACK;
                    node->parent->parent->color = RED;
                    rightRotate(node->parent->parent);
                }
            } else {
                Node* uncle = node->parent->parent->left;
                if (uncle != nullptr && uncle->color == RED) {
                    node->parent->color = BLACK;
                    uncle->color = BLACK;
                    node->parent->parent->color = RED;
                    node = node->parent->parent;
                } else {
                    if (node == node->parent->left) {
                        node = node->parent;
                        rightRotate(node);
                    }
                    node->parent->color = BLACK;
                    node->parent->parent->color = RED;
                    leftRotate(node->parent->parent);
                }
            }
        }
        root->color = BLACK;
    }

    // Function to insert a node with a given value
    void insertNode(Node* node, int data) {
        if (data < node->data) {
            if (node->left != nullptr) {
                insertNode(node->left, data);
                return;
            } else {
                node->left = new Node(data);
                node->left->parent = node;
                fixInsert(node->left);}
        } else if (data >= node->data) {
            if (node->right != nullptr) {
                insertNode(node->right, data);
                return;
            } else {
                node->right = new Node(data);
                node->right->parent = node;
                fixInsert(node->right);
            }
        }
    }

    // Function to print the Red-Black Tree using in-order traversal
    void inOrderPrint(Node* node) const {
        if (node == nullptr) {
            return;
        }
        inOrderPrint(node->left);
        std::cout << node->data << " ";
        inOrderPrint(node->right);
    }

public:
    // Constructor
    RedBlackTree() {
        root = nullptr;
    }

    // Function to insert a value into the Red-Black Tree
    void insert(int data) {
        if (root == nullptr) {
            root = new Node(data);
            root->color = BLACK;
        } else {
            insertNode(root, data);
        }
    }

    // Function to print the Red-Black Tree
    void print() const {
        inOrderPrint(root);
        std::cout << '\n';
    }
};

int main() {
    RedBlackTree tree;

    tree.insert(7);
    tree.insert(3);
    tree.insert(18);
    tree.insert(10);
    tree.insert(22);
    tree.insert(8);
    tree.insert(11);
    tree.insert(26);

    tree.print();

    return 0;
}
