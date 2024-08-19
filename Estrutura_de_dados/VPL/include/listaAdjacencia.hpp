#ifndef LISTAADJACENCIA_HPP
#define LISTAADJACENCIA_HPP

#include <vector>
#include <list>

class ListaAdjacencia {
public:
    ListaAdjacencia();
    ListaAdjacencia(int numVertices);
    ~ListaAdjacencia();

    void adicionarAresta(int origem, int destino);
    void removerAresta(int origem, int destino);
    bool existeAresta(int origem, int destino);

    const std::list<int>& obterVizinhos(int vertice);
    int obterGrau(int vertice);
    int quantidadeVertices();

private:
    int numVertices;
    std::vector<std::list<int>> adjacencias;
};

#endif
