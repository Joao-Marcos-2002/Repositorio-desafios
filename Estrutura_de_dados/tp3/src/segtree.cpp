#include <iostream>
#include "../include/segtree.hpp"

using namespace std;

//Construtor
Segtree::Segtree(long long a, long long b, long long c, long long d) : m11(a), m12(b), m21(c), m22(d) {

}



Segtree::Segtree(int n) {
    int maxSize = 1e5 + 10;
    maxSize = n + 10;  
    vet = new Matrix2x2[maxSize];
    tree = new Matrix2x2*[4 * maxSize];
    v = new Matrix2x2[maxSize];
}

//Destrutor
Segtree::~Segtree() {

}

// construtor
Segtree::Segtree() {
	
}

// Build
Matrix2x2 Segtree::build(int p, int l, int r) {
    if(l == r) return vet[p] = v[l];
    int m = (l + r) / 2;

    return vet[p] = combina(build(2*p, l, m), build(2*p+1, m+1, r));
}

// Query
Matrix2x2 Segtree::query(int a, int b, int p, int l, int r) {
    // Verifica se os intervalos sao disjuntos
    if(b < l || r < a) return Matrix2x2();  
    if(a <= l && r <= b) return vet[p]; 

    int m = (l + r) / 2;

    return combina(query(a, b, 2*p, l, m), query(a, b, 2*p + 1, m + 1, r));

}


Matrix2x2 Segtree::multMatrizes(Matrix2x2 a, Matrix2x2 b) {
    unsigned long long int num = 10000000000; 

    // Retorno da multiplicacao da matriz 2x2 aqui.
    return Matrix2x2 {
        static_cast<long long>((a.m11 * b.m11 + a.m12 * b.m21) % num),
        static_cast<long long>((a.m11 * b.m12 + a.m12 * b.m22) % num),
        static_cast<long long>((a.m11 * b.m11 + a.m22 * b.m21) % num),
        static_cast<long long>((a.m21 * b.m12 + a.m22 * b.m22) % num)
    };
}

Matrix2x2 Segtree::update(int i, int x, int p, int l, int r) {
    if (i < l || r < i) return vet[p];
    if (l == r) return vet[p] = {x, 1, 0, 0}; // Inicialização simplificada.

    int m = (l + r) / 2;
    return vet[p] = multMatrizes(update(i, x, 2*p, l, m),
                            update(i, x, 2*p+1, m+1, r));
}

Matrix2x2 Segtree::combina(Matrix2x2 a, Matrix2x2 b) {
    if (a.first < b.first) return a;
    if (b.first < a.first) return b;
    
    // Apenas soma os elementos da matriz.
    return Matrix2x2{
        a.m11 + b.m11,
        a.m12 + b.m12,
        a.m21 + b.m21,
        a.m22 + b.m22
    };
}




