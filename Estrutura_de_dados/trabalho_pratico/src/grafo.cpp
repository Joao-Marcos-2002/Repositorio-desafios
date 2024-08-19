#include <iostream>
#include "../include/grafo.hpp"

using namespace std;

Grafo::Grafo(int n) : numVertices(n), vertices(nullptr) {
    vertices = new Vertice[numVertices];
}

Grafo::~Grafo() {
    for (int i = 0; i < numVertices; ++i) {
        Aresta* atual = vertices[i].listaArestas;
        while (atual) {
            Aresta* proxima = atual->proximaAresta;
            delete atual;
            atual = proxima;
        }
    }
    delete[] vertices;
}

void Grafo::lerEntrada() {
    for (int i = 0; i < numVertices; ++i) {
        int qtdVizinhos;
        cin >> qtdVizinhos;

        for (int j = 0; j < qtdVizinhos; j++) {
            int adjcVertice;
            cin >> adjcVertice;

            // Adiciona a aresta à lista de arestas do vértice
            vertices[i].listaArestas = new Aresta(adjcVertice, vertices[i].listaArestas);
        }

        int corEscolhida;
        cin >> corEscolhida;
        vertices[i].cor = corEscolhida;
    }
}

bool Grafo::avaliarColoracaoGulosa() {
    for (int i = 0; i < numVertices; i++) {
        Aresta* atual = vertices[i].listaArestas;

        while (atual != nullptr) {
            int indiceVizinho = atual->vizinho;
            int corVizinho = vertices[indiceVizinho].cor;

            // Verifica se corVizinho é maior ou igual à cor do vértice
            if (corVizinho >= vertices[i].cor) {
                return false;  
            }

            // Avança para o próximo vizinho
            atual = atual->proximaAresta;
        }
    }
    return true;
}

Vertice* Grafo::getVertices() {
    return vertices;
}
