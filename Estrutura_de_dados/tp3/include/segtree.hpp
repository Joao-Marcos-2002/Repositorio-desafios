#ifndef SEGTREE_HPP
#define SEGTREE_HPP

class Matrix2x2 {
	public:
    int m11, m12, m21, m22;
    int first;
    int second;

    // Construor
    Matrix2x2(long long a, long long b, long long c, long long d) : m11(a), m12(b), m21(c), m22(d) {}

    // Construtor padrão.
    Matrix2x2() : m11(0), m12(0), m21(0), m22(0) {}
};

class Segtree {
public:
    long long m11, m12, m21, m22;
    int first;
    int second;

    // Construtor
    Segtree(int f, int s) : first(f), second(s) {}

    Segtree(long long a, long long b, long long c, long long d);
    Segtree();
    Segtree(int n);
    ~Segtree();
    Matrix2x2 build(int p, int l, int r);
    Matrix2x2 update(int i, int x, int p, int l, int r);
    Matrix2x2 query(int a, int b, int p, int l, int r);
    Matrix2x2 multMatrizes(Matrix2x2 a, Matrix2x2 b);
    Matrix2x2 combina(Matrix2x2 a, Matrix2x2 b);

private:
    static const int maxSize = 1e5 + 10;
    Matrix2x2* vet = new Matrix2x2[maxSize];
    Matrix2x2** tree = new Matrix2x2*[4 * maxSize];
    Matrix2x2* v = new Matrix2x2[maxSize];
};

#endif
