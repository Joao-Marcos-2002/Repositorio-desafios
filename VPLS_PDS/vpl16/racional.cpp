#include "racional.h"

#include <cmath>
#include <sstream>

using std::stringstream;

// Implementação usando o algoritmo de Euclides.
// Precondição: y > 0.
int MaximoDivisorComum(int x, int y) {
	x = abs(x);	// No caso do numerador ser negativo.
	while (y > 0) {
		int aux = y;
		y = x % y;
		x = aux;
	}
	return x;
}

void Racional::Simplificar() {
  if (denominador_ < 0) { 
    denominador_ = -denominador_; 
    numerador_ = -numerador_; 
  }
  int mdc = MaximoDivisorComum(numerador_, denominador_);
  if (mdc > 1) { 
    numerador_ /= mdc; 
    denominador_ /= mdc; 
  }
}

Racional::Racional() : Racional(0, 1) {
}

Racional::Racional(int n) : Racional(n, 1) {
}

Racional::Racional(int n, int d) : numerador_(n), denominador_(d) {
  if (d == 0) {
    throw ExcecaoDivisaoPorZero();
  }
  Simplificar();
}

int Racional::numerador() const {
  return numerador_;
}

int Racional::denominador() const {
  return denominador_;
}

Racional Racional::operator-() const {
  return Racional(-numerador(), denominador());
}

Racional Racional::operator+(Racional k) const {
  int den = denominador() * k.denominador();
  int num = numerador() * k.denominador() + k.numerador() * denominador();
  return Racional(num, den);
}

Racional Racional::operator-(Racional k) const {
  return (*this) + (-k);
}

Racional Racional::operator*(Racional k) const {
  int num = numerador() * k.numerador();
  int den = denominador() * k.denominador();
  return Racional(num, den);
}

Racional Racional::operator/(Racional k) const {
  if (this->denominador() == 0) {
    throw ExcecaoDivisaoPorZero();
  }
  return (*this) * Racional(k.denominador(), k.numerador());
}

Racional::operator float() const {
  return numerador() / (float) denominador();
}

Racional::operator string() const {
  stringstream out;
  out << numerador() << "/" << denominador();
  return out.str(); 
}

ostream& operator<<(ostream& out, Racional r) {
  out << r.numerador() << '/' << r.denominador();
  return out;
}

istream& operator>>(istream& in, Racional& r) {
  int num, den;
  in >> num >> den;
  r = Racional(num, den); 
  return in;
}