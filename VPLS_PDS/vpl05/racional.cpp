#include "racional.h"

#include <cmath>
#include <iostream>

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
  Simplificar();
}

int Racional::numerador() const {
  return numerador_;
}

int Racional::denominador() const {
  return denominador_;
}

Racional Racional::simetrico() const {
  return Racional(-numerador(), denominador());
}

Racional Racional::somar(Racional k) const {
  int den = denominador() * k.denominador();
  int num = numerador() * k.denominador() + k.numerador() * denominador();
  return Racional(num, den);
}

Racional Racional::subtrair(Racional k) const {
  return this->somar(k.simetrico());
}

Racional Racional::multiplicar(Racional k) const {
  int num = numerador() * k.numerador();
  int den = denominador() * k.denominador();
  return Racional(num, den);
}

Racional Racional::dividir(Racional k) const {
  return this->multiplicar(Racional(k.denominador(), k.numerador()));
}

