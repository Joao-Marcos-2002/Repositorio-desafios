#include "avl_tree.hpp"
#include <iostream>

using namespace std;

// void printPreOrder(Node* root) {
//     if (root != nullptr) {
//         cout << root->key << " ";
//         printPreOrder(root->left);
//         printPreOrder(root->right);
//     }
// }

// void printInOrder(Node* root) {
//     if (root != nullptr) {
//         printInOrder(root->left);
//         cout << root->key << " ";
//         printInOrder(root->right);
//     }
// }

void printPostOrder(Node* root) {
    if (root != nullptr) {
        printPostOrder(root->left);
        printPostOrder(root->right);
        cout << root->key << " ";
    }
}


Node::Node(int k) : key(k), height(1), left(nullptr), right(nullptr) {}

int height(Node* node) {
    if (node == nullptr) return 0;
    return node->height;
}

int updateHeight(Node* node) {
    if (node == nullptr) return 0;
    return 1 + max(height(node->left), height(node->right));
}

int balanceFactor(Node* node) {
    if (node == nullptr) return 0;
    return height(node->left) - height(node->right);
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = updateHeight(y);
    x->height = updateHeight(x);

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = updateHeight(x);
    y->height = updateHeight(y);

    return y;
}

Node* insert(Node* root, int key) {
    if (root == nullptr) {
        return new Node(key);
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    } else {
        // Duplicate keys are not allowed
        return root;
    }

    root->height = updateHeight(root);

    int balance = balanceFactor(root);

    // Left Left Case
    if (balance > 1 && key < root->left->key) {
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && key > root->right->key) {
        return leftRotate(root);
    }

    // Left Right Case
    if (balance > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left Case
    if (balance < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}

Node* deleteNode(Node* root, int key) {
    if (root == nullptr) return root;

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == nullptr || root->right == nullptr) {
            Node* temp = root->left ? root->left : root->right;

            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else {
                *root = *temp;
            }

            delete temp;
        } else {
            Node* temp = minValueNode(root->right);

            root->key = temp->key;

            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == nullptr) return root;

    root->height = updateHeight(root);

    int balance = balanceFactor(root);

    // Left Left Case
    if (balance > 1 && balanceFactor(root->left) >= 0) {
        return rightRotate(root);
    }

    // Left Right Case
    if (balance > 1 && balanceFactor(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && balanceFactor(root->right) <= 0) {
        return leftRotate(root);
    }

    // Right Left Case
    if (balance < -1 && balanceFactor(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void preOrderTraversal(Node* root) {
    if (root != nullptr) {
        cout << root->key << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void inOrderTraversal(Node* root) {
    if (root != nullptr) {
        inOrderTraversal(root->left);
        cout << root->key << " ";
        inOrderTraversal(root->right);
    }
}

void postOrderTraversal(Node* root) {
    if (root != nullptr) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout << root->key << " ";
    }
}
