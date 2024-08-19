//cria para mim um programa que leia um número inteiro e cria uma arvore binaria completa com os proximos 5 filhos


#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <deque>
#include <forward_list>
#include <bitset>
#include <utility>
#include <iterator>
#include <functional>
#include <climits>
#include <cfloat>
#include <cstdint>
#include <cinttypes>
#include <cstddef>
#include <cassert>

using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}



void insert(Node* root, int data) {
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (!temp->left) {
            temp->left = newNode(data);
            break;
        } else {
            q.push(temp->left);
        }

        if (!temp->right) {
            temp->right = newNode(data);
            break;
        } else {
            q.push(temp->right);
        }
    }
}


void printLevelOrder(Node* root) {
    if (!root) {
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        cout << temp->data << " ";
        q.pop();

        if (temp->left) {
            q.push(temp->left);
        }

        if (temp->right) {
            q.push(temp->right);
        }
    }
}


int main() {
    Node* root = newNode(1);
    int n;
    cout << "Digite um numero inteiro: ";
    cin >> n;
    insert(root, n);
    insert(root, n+1);
    insert(root, n+2);
    insert(root, n+3);
    insert(root, n+4);
    insert(root, n+5);
    printLevelOrder(root);

    return 0;
}
