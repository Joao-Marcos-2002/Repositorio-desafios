 #include "vetor.h"

#include <string>

using std::string;

Vetor::Vetor(int inicio, int fim) : inicio_(inicio) {
  elementos_ = new string[fim - inicio + 1];
}

void Vetor::atribuir(int i, string valor) {
  int j = i - inicio_;
  elementos_[j] = valor;
}

string Vetor::valor(int i) const { 
  int j = i - inicio_;     
  return elementos_[j];
}

Vetor::~Vetor() {
  delete [] elementos_;
}