#include <iostream>
#include <iomanip>  // Para usar std::setprecision.

#include "complexo.h"

using namespace std;

void Imprimir(Complexo k) {
  cout << std::setprecision(2) << std::fixed;
  if (k.imag() == 0) {
    cout << k.real() << endl;
  } else if (k.imag() > 0) {
    cout << k.real() << " + " << k.imag() << "i " << endl;
  } else {
    cout << k.real() << " - " << -k.imag() << "i " << endl;
  }
}

Complexo Executar(char op, Complexo x, Complexo y) {
  if (op == '+') {
    return x.somar(y);
  } else if (op == '-') {
    return x.subtrair(y);
  } else if (op == '*') {
    return x.multiplicar(y);
  } else {  // op == '/'
    return x.dividir(y);
  }
}

int main () {
  cout << "Digite uma operação (+, -, *, /): " << endl;
  char op;
  cin >> op;
  cout << "Digite o primeiro operando: " << endl;
  double r1, i1;
  cin >> r1 >> i1;
  Complexo c1(r1, i1);
  cout << "Digite o segundo perando operando: " << endl;
  double r2, i2;
  cin >> r2 >> i2;
  Complexo c2(r2, i2);
  Complexo resultado(0, 0);
  cout << "Resultado: " << endl;
  resultado = Executar(op, c1, c2);
  Imprimir(resultado);
  return 0;
}