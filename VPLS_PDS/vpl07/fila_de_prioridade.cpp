#include "fila_de_prioridade.h"

#include <list>
#include <string>
#include <vector>

using std::string;
using std::vector;

void FilaDePrioridade::Adicionar(Pessoa p) {
  auto it = lista_.begin();
  while (it != lista_.end() && it->prioridade >= p.prioridade) {
    it++;
  }
  lista_.insert(it, p);
}

string FilaDePrioridade::RemoverMaiorPrioridade() {
  string nome = lista_.front().nome;
  lista_.pop_front();
  return nome;
}

void FilaDePrioridade::Remover(string nome) {
  for (auto it = lista_.begin(); it != lista_.end(); it++) {
    if (it->nome == nome) {
      lista_.erase(it);
      return;  // Depois da remoção it não é mais válido.
    }
  }
}

int FilaDePrioridade::tamanho() {
  return lista_.size();
}

vector<string> FilaDePrioridade::listar() {
  vector<string> v;
  for (auto p : lista_) {
    v.push_back(p.nome);
  }
  return v; 
}