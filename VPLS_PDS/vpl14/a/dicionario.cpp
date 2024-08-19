#include "dicionario.h"

#include <string>

using std::string;

Dicionario::Dicionario() {
  // Nada a fazer.
}

int Dicionario::tamanho() {
  return elementos_.size();
}

bool Dicionario::pertence(string chave) {
  for (Elemento par : elementos_) {
    if (par.chave == chave) {
      return true;
    }
  }
  return false;
}

string Dicionario::menor() {
  // Conjectura que é o primeiro elemento.
  string m = elementos_.front().chave;
  // Em seguida, verifica se há algum menor.
  for (Elemento par : elementos_) {
    if (par.chave < m) {
      m = par.chave;
    }
  }
  return m;
}

string Dicionario::valor(string chave) {
  for (Elemento par : elementos_) {
    if (par.chave == chave) {
      return par.valor;
    }
  }  
}

void Dicionario::Inserir(string chave, string valor) {
  Elemento e{chave, valor};
  elementos_.push_back(e);
}

void Dicionario::Remover(string chave) {
  for (auto it = elementos_.begin(); it != elementos_.end(); it++) {
    if (it->chave == chave) {
      elementos_.erase(it);
      return;
    }
  }
}

void Dicionario::Alterar(string chave, string valor) {
  for (Elemento& par : elementos_) {
    if (par.chave == chave) {
      par.valor = valor;
      return;
    }
  }  
}

Dicionario::~Dicionario() {
  // Nada a fazer.  
}
