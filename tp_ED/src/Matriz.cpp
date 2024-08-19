#include "Matriz.hpp"

Matriz::Matriz() : m11(0), m12(0), m21(0), m22(0) {}

Matriz::Matriz(long long a, long long b, long long c, long long d)
    : m11(a), m12(b), m21(c), m22(d) {}

Matriz::Matriz(unsigned long a, unsigned long b)
    : m11(static_cast<long long>(a)), m12(0), m21(0), m22(static_cast<long long>(b)) {}

Matriz Matriz::multipicaMatriz(const Matriz& a, const Matriz& b) {
    const long long nDigitos = 100000000;

    Matriz resultadoM;
    resultadoM.m11 = (a.m11 * b.m11 + a.m12 * b.m21) % nDigitos;
    resultadoM.m12 = (a.m11 * b.m12 + a.m12 * b.m22) % nDigitos;
    resultadoM.m21 = (a.m21 * b.m11 + a.m22 * b.m21) % nDigitos;
    resultadoM.m22 = (a.m21 * b.m12 + a.m22 * b.m22) % nDigitos;

    return resultadoM;
}
