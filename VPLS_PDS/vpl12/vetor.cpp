 #include "vetor.h"

#include <string>

using std::string;

Vetor::Vetor(int inicio, int fim) : inicio_(inicio), fim_(fim) {
  if (fim < inicio) {
    throw IntervaloVazio{inicio, fim};
  }
  elementos_ = new string[fim - inicio + 1];
  inicializados_ = new bool[fim - inicio + 1];
}

void Vetor::atribuir(int i, string valor) {
  if (i < inicio_ || i > fim_) {
    throw IndiceInvalido{inicio_, fim_, i};
  }
  int j = i - inicio_;
  elementos_[j] = valor;
  inicializados_[j] = true;
}

string Vetor::valor(int i) const { 
  if (i < inicio_ || i > fim_) {
    throw IndiceInvalido{inicio_, fim_, i};
  }  
  int j = i - inicio_;  
  if (!inicializados_[j]) {
    throw IndiceNaoInicializado{i};
  }   
  return elementos_[j];
}

Vetor::~Vetor() {
  delete [] elementos_;
  delete [] inicializados_;
}