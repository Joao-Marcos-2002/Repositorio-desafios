#ifndef LISTAADJACENCIA_HPP
#define LISTAADJACENCIA_HPP

#include <iostream>
#include <list>
#include <vector>
#include "graph.hpp"


class ListaAdjacencia {
private:
    int numVertices;
    std::vector<std::list<int>> adjacencias;

public:
    ListaAdjacencia(int numVertices);

    void InsereVertice();
    void InsereAresta(int v, int w);

    int QuantidadeVertices();
    int QuantidadeArestas();
    int GrauMinimo();
    int GrauMaximo();
    void ImprimeVizinhos(int v);
    bool EhGrafoCompleto();
};

// ListaAdjacencia::ListaAdjacencia(int numVertices) {
//     this->numVertices = numVertices;
//     adjacencias.resize(numVertices);
// }

void ListaAdjacencia::InsereVertice() {
    numVertices++;
    adjacencias.resize(numVertices);
}

void ListaAdjacencia::InsereAresta(int v, int w) {
    adjacencias[v].push_back(w);
    adjacencias[w].push_back(v); // Se o grafo for não direcionado
}

int ListaAdjacencia::QuantidadeVertices() {
    return numVertices;
}

int ListaAdjacencia::QuantidadeArestas() {
    int numArestas = 0;
    for (int i = 0; i < numVertices; i++) {
        numArestas += adjacencias[i].size();
    }
    // Se o grafo for não direcionado
    return numArestas / 2; 
}

int ListaAdjacencia::GrauMinimo() {
    int grauMinimo = 0;
    for (int i = 0; i < numVertices; i++) {
        int grau = adjacencias[i].size();
        if (grau < grauMinimo) {
            grauMinimo = grau;
        }
    }
    return grauMinimo;
}

int ListaAdjacencia::GrauMaximo() {
    int grauMaximo = 0;
    for (int i = 0; i < numVertices; i++) {
        int grau = adjacencias[i].size();
        if (grau > grauMaximo) {
            grauMaximo = grau;
        }
    }
    return grauMaximo;
}

void ListaAdjacencia::ImprimeVizinhos(int v) {
    std::list<int>& vizinhos = adjacencias[v];
    for (int vizinho : vizinhos) {
        std::cout << vizinho << " ";
    }
}

// Verifica se o grafo eh: Kn
bool ListaAdjacencia::EhGrafoCompleto() {
    for (int i = 0; i < numVertices; i++) {
        if (adjacencias[i].size() != numVertices - 1) {
            return false;
        }
    }
    return true;
}

#endif

