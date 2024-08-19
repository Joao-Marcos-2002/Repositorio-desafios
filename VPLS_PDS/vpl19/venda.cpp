#include "venda.hpp"

#include <iomanip>
#include <iostream>

using namespace std;

Venda::~Venda() {
  for (auto x : m_pedidos) {
    delete x;
  } 
}

void Venda::adicionaPedido(Pedido* p) {
  m_pedidos.push_back(p);
}

void Venda::imprimeRelatorio() const {
   /**
   * Aqui voce tem que percorrer a lista de todos os pedidos e imprimir o resumo
   * de cada um. Por ultimo, devera ser exibido o total de venda e a quantidade
   * de pedidos processados.
   */
  float total_de_vendas = 0.0;
  int contador_de_pedidos = 0;
  cout << std::fixed;
  cout << std::setprecision(2);
  for (auto pedido : m_pedidos) { 
    cout << "Pedido " << ++contador_de_pedidos << endl;
    cout << pedido->resumo();
    total_de_vendas += pedido->calculaTotal();  
  }
  cout << "Relatorio de Vendas" << endl;
  cout << "Total de vendas: R$ " << total_de_vendas << endl;
  cout << "Total de pedidos: " << contador_de_pedidos << endl;  
}