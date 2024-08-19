#ifndef MATRIZ_HPP
#define MATRIZ_HPP

class Matriz {
public:
    long long m11, m12, m21, m22;

    long long c_m11() const { return m11; }
    long long c_m21() const { return m21; }

    Matriz();
    Matriz(long long a, long long b, long long c, long long d);
    Matriz(unsigned long a, unsigned long b);
    Matriz multipicaMatriz(const Matriz& a, const Matriz& b);
   
};

#endif 
