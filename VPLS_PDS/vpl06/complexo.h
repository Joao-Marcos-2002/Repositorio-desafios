#ifndef COMPLEXO_H_
#define COMPLEXO_H_
 
// Representa um número complexo
// (https://pt.wikipedia.org/wiki/N%C3%BAmero_complexo)
class Complexo {
 public:
  Complexo(double a, double b);  // Cria o número complexo a + bi.
  double real();  // Retorna a parte real.
  double imag();  // Retorna a parte imaginária.
  Complexo conjugado();  // Retorna o conjugado de *this.
  Complexo simetrico();  // Retorna o simétrico de *this.
  Complexo inverso();  // Retorna o inverso multiplicativo de *this.
  Complexo somar(Complexo y);  // Retora *this + y.
  Complexo subtrair(Complexo y);  // Retora *this - y.
  Complexo multiplicar(Complexo y);  // Retora *this * y.
  Complexo dividir(Complexo y);  // Retora *this / y.

 private:
  // A implmentação atual utiliza representação polar/trigonométrica
  double mod_;  // Módulo do vetor que representa o número.
  double arg_;  // Argumento do vetor (em radianos) que representa o número.
};

#endif  // COMPLEXO_H_
