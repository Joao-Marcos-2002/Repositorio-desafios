// #ifndef AVL_TREE_H


// class Node {

//     public:
//         int key;
//         int height;
//         Node* left;
//         Node* right;

//         Node(int l);
// };

// int altura(Node* node);

// int updateHeight(Node* node);

// int balancear(Node* node);

// Node* rotacaoDireita(Node* y);

// Node* rotacaoEsquerda(Node* x);

// Node* insert(Node* root, int key);

// Node* valorMinimo(Node* node);

// Node* deleteNode(Node* root, int key);

// void preOrderTransversal(Node* root);

// void preOrderTransversal(Node* root);

// void inOrderTransversal(Node* root);

// void postOrderTransversal(Node* root);


// #endif


#ifndef AVL_TREE_H
#define AVL_TREE_H

class Node {
public:
    int key;
    int height;
    Node* left;
    Node* right;

    Node(int l);
};

int altura(Node* node);

int updateHeight(Node* node);

int balancear(Node* node);

Node* rotacaoDireita(Node* y);

Node* rotacaoEsquerda(Node* x);

Node* insert(Node* root, int key);

Node* valorMinimo(Node* node);

Node* deleteNode(Node* root, int key);

void preOrderTransversal(Node* root);

void inOrderTransversal(Node* root);

void postOrderTransversal(Node* root);

#endif
