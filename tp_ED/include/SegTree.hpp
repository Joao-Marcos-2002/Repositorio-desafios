#ifndef SEGTREE_HPP
#define SEGTREE_HPP

#include "Matriz.hpp"  

class SegTree {
public:
    SegTree(int q_instantes);

    Matriz build(int p, int l, int r);
    Matriz query(int a, int b, int p, int l, int r);
    Matriz update(int i, Matriz x, int p, int l, int r);
    

private:
    Matriz* v;
    Matriz* segTree;
    int tamanho;         // seta tamanho da segment tree

    const Matriz INF = {1, 0, 0, 1};  // identidade

    // Matriz build(int p, int l, int r);
};

#endif 
