#include "avl_tree.hpp"
#include <iostream>

using namespace std;

void preOrderTraversal(Node* root);
void inOrderTraversal(Node* root);
void postOrderTraversal(Node* root);

int main() {
    int num;
    cin >> num;

    Node* root = nullptr;

    for (int i = 0; i < num; i++) {
        char op;
        int chave;
        cin >> op >> chave; 

        if (op == 'i') {
            // insere nó.
            root = insert(root, chave);
        } else if (op == 'r') {
            // remove nó.
            root = deleteNode(root, chave);
        }
    }

    preOrderTraversal(root);
    cout << endl;

    inOrderTraversal(root);
    cout << endl;

    postOrderTraversal(root);
    cout << endl;
    


    return 0; 
}

