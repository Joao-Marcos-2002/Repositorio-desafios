#include <iostream>
#include "../include/segtree.hpp"

using namespace std;

//Construtor
Segtree::Segtree(int n) {
    qtdInstantes = n;
    v= new Matriz[qtdInstantes];
    seg = new Matriz[4 * qtdInstantes];

    for (int i = 0; i < qtdInstantes; i++) {
        v[i] = Matriz();
    }
}

//Destrutor
Segtree::~Segtree() {
    delete[] seg;
    delete[] v;
}

Segtree::Segtree(int l, int r) {
    
}

// Multiplicacao Mat::
Matriz Segtree::multMatrizes(Matriz a, Matriz b) {
    unsigned long long int num = 100000000;
        // Retorno da multiplicacao da matriz 2x2.
        return Matriz {
            (a.m[0][0] * b.m[0][0] + a.m[0][1] * b.m[1][0]) % num,
            (a.m[0][0] * b.m[0][1] + a.m[0][1] * b.m[1][1]) % num,
            (a.m[1][0] * b.m[0][0] + a.m[1][1] * b.m[1][0]) % num,
            (a.m[1][0] * b.m[0][1] + a.m[1][1] * b.m[1][1]) % num
        };
}

// Build
Matriz Segtree::build(int p, int l, int r) {
    if(l == r) return seg[p]= v[l];
    int m = (l + r) / 2;

    //retorna a matriz construida.
    return seg[p] = multMatrizes(build(2*p, l, m), build(2*p+1, m+1, r));
}

// Query
Matriz Segtree::query(int a, int b, int p, int l, int r) {
    // Verifica se os intervalos sao disjuntos
    if(b < l || r < a) return Matriz(1, 0, 0, 1);  
    if(a <= l && r <= b) return seg[p]; 

    int m = (l + r) / 2;

    return multMatrizes(query(a, b, 2*p, l, m), query(a, b, 2*p + 1, m + 1, r));

}
// Update
Matriz Segtree::update(int i, Matriz x, int p, int l, int r) {
    if (i < l || r < i) return seg[p];
    if (l == r) return seg[p] = x;

    int med = (l + r) / 2;
    return seg[p] = multMatrizes(update(i, x, 2*p, l, med),
                            update(i, x, 2*p+1, med+1, r));
}


