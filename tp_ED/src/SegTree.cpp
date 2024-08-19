#include "../include/SegTree.hpp"

const Matriz INF = {1, 0, 0, 1}; //Matriz identidade

SegTree::SegTree(int q_instantes){
    v = new Matriz[q_instantes];
    segTree = new Matriz[4 * q_instantes];
    tamanho = 4 * q_instantes;

    for(int i = 0; i < q_instantes; i++){
        v[i] = Matriz(); 
    }

    build(1, 0, q_instantes - 1);
}

Matriz SegTree::build(int p, int l, int r){
    if(l == r) return segTree[p] = v[l];
    int m = (l+r)/2;
    Matriz temp;
    return segTree[p] = temp.multipicaMatriz(build(2*p, l, m), build(2*p+1, m+1, r));
}

Matriz SegTree::query(int a, int b, int p, int l, int r){
    if (b < l or r < a) return INF;
    if (a <= l and r <= b) return segTree[p];
    int m = (l+r)/2;
    Matriz temp;
    return temp.multipicaMatriz(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
}

Matriz SegTree::update(int i, Matriz x, int p, int l, int r) {
    if (i < l or r < i) return segTree[p];
    if (l == r) return segTree[p] = x;
    int m = (l+r)/2;
    Matriz temp;
    return segTree[p] = temp.multipicaMatriz(update(i, x, 2*p, l, m), update(i, x, 2*p+1, m+1, r));
}