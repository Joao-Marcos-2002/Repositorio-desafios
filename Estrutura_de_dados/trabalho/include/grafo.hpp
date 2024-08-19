#ifndef GRAFO_HPP
#define GRAFO_HPP

struct Aresta {
    int vizinho;
    Aresta* proximaAresta;

    Aresta(int v, Aresta* proxima = nullptr) : vizinho(v), proximaAresta(proxima) {}
};

struct Vertice {
    int cor;
    Aresta* listaArestas;  
    Vertice* proximo;
    Vertice() : cor(0), listaArestas(nullptr) {}
};

class Grafo {
public:
    Grafo(int n);
    ~Grafo();
    void lerEntrada();
    bool avaliarColoracaoGulosa();
    Vertice* getVertices();

private:
    Vertice* vertices;
    int numVertices;
};

#endif
