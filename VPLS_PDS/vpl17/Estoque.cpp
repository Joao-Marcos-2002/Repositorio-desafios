#include <iostream>
#include <map>
#include <string>

#include "Estoque.hpp"

using namespace std;

void Estoque::add_mercadoria(const std::string& mercadoria, unsigned int qtd) {
  estoque_[mercadoria] += qtd;
}

void Estoque::sub_mercadoria(const std::string& mercadoria, unsigned int qtd) {
  auto it = estoque_.find(mercadoria);
  if (it == estoque_.end()) {
    cout << mercadoria << " inexistente" << endl;
  } else if (qtd > it->second) {
    cout << mercadoria << " insuficiente" << endl;
  } else {
    estoque_[mercadoria] -= qtd;
  }
}

unsigned int Estoque::get_qtd(const std::string& mercadoria) const {
  unsigned int qtd = estoque_.find(mercadoria)->second;
  return qtd;
}

void Estoque::imprime_estoque() const {
  for (auto x : estoque_) {
    cout << x.first << ", " << x.second << endl;
  }
}

Estoque& Estoque::operator += (const Estoque& rhs) {
  for (auto x: rhs.estoque_) {
    add_mercadoria(x.first, x.second);
  }
  return *this;
}

Estoque& Estoque::operator -= (const Estoque& rhs) {
  for (auto x: rhs.estoque_) {
    sub_mercadoria(x.first, x.second);
  }
  return *this;
}

bool operator < (Estoque& lhs, Estoque& rhs) {
for (auto [l_mercadoria, l_qtd] : lhs.estoque_) {
    auto r_it = rhs.estoque_.find(l_mercadoria);
    if (r_it == rhs.estoque_.end() || !(r_it->second > l_qtd)) {
      return false;
    }
  }
  return true;
}

bool operator > (Estoque& lhs, Estoque& rhs) {
  for (auto [r_mercadoria, r_qtd] : rhs.estoque_) {
    auto l_it = lhs.estoque_.find(r_mercadoria);
    if (l_it == lhs.estoque_.end() || !(l_it->second > r_qtd)) {
      return false;
    }
  }
  return true;
}