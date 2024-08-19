#include "japonesa.hpp"

#include <sstream>

using namespace std;

std::string Japonesa::descricao() const {
  /*
   * Note que aqui voce deve retornar uma descricao detalhada da comida
   * japonesa.
   *
   * Exemplos:
   * 1X Comida japonesa - Combo 1, 4 sushis, 5 temakis e 6 hots.
   * 1X Comida japonesa - Combo 2, 5 sushis, 6 temakis e 8 hots.
   */
  stringstream ss;
  ss << m_qtd << "X Comida japonesa - " << m_combinado << ", ";
  ss << m_sushis << " sushis, ";
  ss << m_temakis << " temakis e ";
  ss << m_hots << " hots.";
  return ss.str();
}

Japonesa::Japonesa(const std::string& combinado,
                   int sushis,
                   int temakis,
                   int hots,
                   int qtd,
                   float valor_unitario) {
  m_combinado = combinado;
  m_sushis = sushis;
  m_temakis = temakis; 
  m_hots = hots;
  m_qtd = qtd;
  m_valor_unitario = valor_unitario;
}