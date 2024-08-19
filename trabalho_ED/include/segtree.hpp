#ifndef SEGTREE_HPP
#define SEGTREE_HPP

struct Matriz
{   
    // inicializa uma identidade.
    long unsigned int m[2][2] = {{1, 0}, {0, 1}};

    Matriz multMatriz(Matriz a, Matriz b)
    {
        unsigned long long int num = 100000000;
        // Retorno da multiplicacao da matriz 2x2.
        return Matriz{
            (a.m[0][0] * b.m[0][0] + a.m[0][1] * b.m[1][0]) % num,
            (a.m[0][0] * b.m[0][1] + a.m[0][1] * b.m[1][1]) % num,
            (a.m[1][0] * b.m[0][0] + a.m[1][1] * b.m[1][0]) % num,
            (a.m[1][0] * b.m[0][1] + a.m[1][1] * b.m[1][1]) % num};
    }


    // Construtor que inicializa a matriz com os valores x, 0, y, 0
    Matriz(long unsigned int x, long unsigned int y)
    {
        m[0][0] = x;
        m[0][1] = 0;
        m[1][0] = y;
        m[1][1] = 0;
    }

    Matriz()
    {
        // Inicialize os elementos da matriz com valores padrão ou deixe-os não inicializados
        m[0][0] = 1;
        m[0][1] = 0;
        m[1][0] = 0;
        m[1][1] = 1;
    }

    // Construtor com 4 parametros.
    Matriz(long unsigned int a, long unsigned int b, long unsigned int c, long unsigned int d)
    {
        m[0][0] = a;
        m[0][1] = b;
        m[1][0] = c;
        m[1][1] = d;
    }
};

class Segtree
{
public:
    long long m11, m12, m21, m22;
    int first;
    int second;

    Segtree(int n);
    ~Segtree();
    Segtree(int l, int r);
    Matriz build(int p, int l, int r);
    Matriz update(int i, Matriz x, int p, int l, int r);
    Matriz query(int a, int b, int p, int l, int r);
    Matriz multMatrizes(Matriz a, Matriz b);

private:
    Matriz *seg;
    Matriz *v;
    int qtdInstantes;

};

#endif
