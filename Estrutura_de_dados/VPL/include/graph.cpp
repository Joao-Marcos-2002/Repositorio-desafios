#include "graph.hpp"
#include <iostream>

// Construtor do grafo.
Grafo::Grafo() {
    
}

// Destrutor do Grafo.
Grafo::~Grafo() {
}

void Grafo::InsereVertice() {

}

void Grafo::InsereAresta(int v, int w) {
    vertices.adicionarAresta(v, w);
}

int Grafo::QuantidadeVertices(int numVertices) {
    // Contagem de vértices.
    return numVertices;
    // return vertices.quantidadeVertices();
}

int Grafo::QuantidadeArestas(int numArestas) {
    // Implemente a contagem de arestas aqui, usando a ListaAdjacencia
    return numArestas;
}

int Grafo::GrauMinimo(int grauMinimo) {
    // Implemente o cálculo do grau mínimo aqui, usando a ListaAdjacencia
    return grauMinimo;
}

int Grafo::GrauMaximo(int grauMaximo) {
    // Implemente o cálculo do grau máximo aqui, usando a ListaAdjacencia
    return grauMaximo;
}

void Grafo::ImprimeVizinhos(int numVertices, const std::vector<std::vector<int>>& listaNumVizinhos) {
    std::cout << numVertices << std::endl;
    for (std::vector<int>::size_type v = 0; v < static_cast<std::vector<int>::size_type>(numVertices); v++) {
        for (std::vector<int>::size_type i = 0; i < listaNumVizinhos[v].size(); i++) {
            std::cout << listaNumVizinhos[v][i] << " ";
        }
        std::cout << std::endl; 
    }
}



bool Grafo::EhGrafoCompleto(int numArestas, int numVertices) {
    // Implemente a verificação de grafo completo aqui, se necessário

    if(numArestas == (numVertices * (numVertices - 1)) / 2) {
        return true;
    } else {
        return false;
    }
}
