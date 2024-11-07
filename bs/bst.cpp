#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

class BST {
    Node *root;
    
public:
    BST() {
        root = nullptr;
    }
    void insert(int value) {
        root = insertNode(root, value);
    }
    bool search(int value) {
        return searchNode(root, value);
    }
    void deleteValue(int value) {
        root = deleteNode(root, value);
    }
    void inorder() {
        inorderTraversal(root);
        cout << endl;
    }

private:
    Node* insertNode(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->data) {
            node->left = insertNode(node->left, value);
        } else if (value > node->data) {
            node->right = insertNode(node->right, value);
        }
        return node;
    }
    bool searchNode(Node* node, int value) {
        if (node == nullptr) {
            return false;
        }
        if (node->data == value) {
            return true;
        }
        if (value < node->data) {
            return searchNode(node->left, value);
        } else {
            return searchNode(node->right, value);
        }
    }
    Node* findMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
    Node* deleteNode(Node* node, int value) {
        if (node == nullptr) {
            return node;
        }
        if (value < node->data) {
            node->left = deleteNode(node->left, value);
        } else if (value > node->data) {
            node->right = deleteNode(node->right, value);
        } else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }
    void inorderTraversal(Node* node) {
        if (node != nullptr) {
            inorderTraversal(node->left);
            cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }
};

int main() {
    BST tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);
    tree.inorder();
    tree.deleteValue(3);
    tree.inorder();
    tree.deleteValue(5);
    tree.inorder();
    return 0;
}
