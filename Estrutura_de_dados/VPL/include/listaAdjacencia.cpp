#include "listaAdjacencia.hpp"

ListaAdjacencia::ListaAdjacencia() {
    
}

ListaAdjacencia::ListaAdjacencia(int numVertices) : numVertices(numVertices), adjacencias(numVertices) {
}

ListaAdjacencia::~ListaAdjacencia() {
    // Implemente aqui a destruição adequada, se necessário
}

void ListaAdjacencia::adicionarAresta(int origem, int destino) {
    adjacencias[origem].push_back(destino);
}

void ListaAdjacencia::removerAresta(int origem, int destino) {
    adjacencias[origem].remove(destino);
}

bool ListaAdjacencia::existeAresta(int origem, int destino) {
    for (int v : adjacencias[origem]) {
        if (v == destino) {
            return true;
        }
    }
    return false;
}

const std::list<int>& ListaAdjacencia::obterVizinhos(int vertice) {
    return adjacencias[vertice];
}

int ListaAdjacencia::obterGrau(int vertice) {
    return adjacencias[vertice].size();
}

int ListaAdjacencia::quantidadeVertices() {
    return adjacencias.size();
}
