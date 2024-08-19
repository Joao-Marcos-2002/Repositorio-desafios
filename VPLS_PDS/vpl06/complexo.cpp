#include "complexo.h"

#include <cmath>

Complexo::Complexo(double a, double b) {
  mod_ = sqrt(a * a + b * b);
  arg_ = atan2(b, a);
}

double Complexo::real() {
  return mod_ * cos(arg_);
}

double Complexo::imag() {
  return mod_ * sin(arg_);
}

Complexo Complexo::conjugado() {
  Complexo c(0, 0);
  c.mod_ = mod_;
  c.arg_ = -arg_;
  return c;
}

Complexo Complexo::simetrico() {
  Complexo c(0, 0);
  c.mod_ = mod_;
  c.arg_ = arg_ + M_PI;
  return c;
}

Complexo Complexo::inverso() {
  Complexo i(0, 0);
  i.mod_ = 1.0 / mod_;
  i.arg_ = -arg_;
  return i;
}

Complexo Complexo::somar(Complexo y) {
  Complexo s(real() + y.real(), imag() + y.imag());
  return s;
}

Complexo Complexo::subtrair(Complexo y) {
  return this->somar(y.simetrico());
}

Complexo Complexo::multiplicar(Complexo y) {
  Complexo p(0, 0);
  p.mod_ = mod_ * y.mod_;
  p.arg_ = arg_ + y.arg_;
  return p;
}

Complexo Complexo::dividir(Complexo y) {
  return this->multiplicar(y.inverso());
}
