#include "pizza.hpp"

#include <sstream>

using namespace std;

std::string Pizza::descricao() const {
  // TODO: Implemente este metodo.
  /*
   * Note que aqui voce deve retornar uma descricao detalhada da pizza.
   *
   * Exemplos:
   * 2X Pizza Calabresa, 4 pedacos e borda recheada.
   * 2X Pizza Calabresa, 4 pedacos sem borda recheada.
   */
  stringstream ss;
  ss << m_qtd << "X Pizza " << m_sabor << ", ";
  if (m_borda_recheada) {
    ss << m_pedacos << " pedacos e borda recheada.";
  } else {
    ss << m_pedacos << " pedacos e sem borda recheada.";
  }
  return ss.str();
}

Pizza::Pizza(const std::string& sabor,
             int pedacos,
             bool borda_recheada,
             int qtd,
             float valor_unitario) {
  m_sabor = sabor; 
  m_pedacos = pedacos;
  m_borda_recheada = borda_recheada; 
  m_qtd = qtd;
  m_valor_unitario = valor_unitario;
}