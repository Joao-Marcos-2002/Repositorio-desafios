#include "pedido.hpp"

#include <sstream>

using namespace std;

Pedido::~Pedido() {
  for (auto x : m_produtos) {
    delete x;
  } 
}

void Pedido::setEndereco(const std::string& endereco) {
  m_endereco = endereco;
}

float Pedido::calculaTotal() const {
  float total = 0.0;
  for (auto x : m_produtos) {
    total += x->getQtd() * x->getValor();
  } 
  return total;
}

void Pedido::adicionaProduto(Produto* p) {
  m_produtos.push_back(p);
}

std::string Pedido::resumo() const {
  /**
   * Aqui voce deve percorrer a lista de produtos para criar um resumo completo
   * do pedido. A cada iteracao, utilize o metodo descricao de cada produto para
   * montar o resumo do pedido. Por fim, adicione o endereco de entrega.
   *
   */
  stringstream ss;
  for (auto p : m_produtos) { 
    ss << p->descricao() << endl;
  }
  ss << "Endereco: " << m_endereco << endl;
  return ss.str();
}