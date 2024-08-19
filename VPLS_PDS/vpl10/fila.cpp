#include "fila.h"

# include <string>

using std::string;

Fila::Fila() {
  primeiro_ = nullptr;
  ultimo_ = nullptr;
}

string Fila::primeiro() {
  return primeiro_->chave;
}

string Fila::ultimo() {
  return ultimo_->chave;
}

bool Fila::vazia() {
  return (primeiro_ == nullptr);
}

void Fila::Inserir(string k) {
  if (vazia()) {
    primeiro_ = ultimo_ = new No{k, nullptr};
  } else {
    ultimo_ = ultimo_->proximo = new No{k, nullptr};
  }
}

void Fila::Remover() {
  No* removido = primeiro_;
  if (removido == ultimo_) {
    primeiro_ = ultimo_ = nullptr;
  } else {
    primeiro_ = primeiro_->proximo;
  }
  delete removido;
}

int Fila::tamanho() {
  int n = 0;
  for (No* i = primeiro_; i != nullptr; i = i->proximo) {
    n++;
  }
  return n;
}

Fila::~Fila() {
  while(!vazia()) {
    Remover();
  }
}