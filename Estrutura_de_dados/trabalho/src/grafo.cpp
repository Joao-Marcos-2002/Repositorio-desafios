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

        for (int j = 0; j < qtdVizinhos; ++j) {
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
    cout << "Cores após ordenação: ";
    for (int i = 0; i < numVertices; ++i) {
        cout << vertices[i].cor << " ";
    }
    cout << endl;

    for (int i = 0; i < numVertices; ++i) {
        int corAtual = vertices[i].cor;

        for (Aresta* aresta = vertices[i].listaArestas; aresta != nullptr; aresta = aresta->proximaAresta) {
            int corVizinho = vertices[aresta->vizinho].cor;

            if (corAtual == corVizinho) {
                cout << "Cores dos vértices " << i << " e " << aresta->vizinho << " são iguais." << endl;
                return false;
            }
        }
    }
    return true;
}



Vertice* Grafo::getVertices() {
    return vertices;
}
