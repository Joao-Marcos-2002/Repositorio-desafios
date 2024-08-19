#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "listaAdjacencia.hpp"


class Grafo{
    public:
        Grafo();
        // Grafo(int numVertices);
        ~Grafo();

        void InsereVertice();
        void InsereAresta(int v, int w);

        int QuantidadeVertices(int numVertices);
        int QuantidadeArestas(int numArestas);

        int GrauMinimo(int grauMinimo);
        int GrauMaximo(int grauMaximo);

        void ImprimeVizinhos(int v, const std::vector<std::vector<int>>& listaNumVizinho);
        bool EhGrafoCompleto(int numArestas, int numVertices);
        
    private:
        
        /*  Você deve implementar ListaAdjacencia como um TAD que irá armazenar
         * os dados do grafo. Lembrando que este TAD deve ser uma lista 
         * encadeada
         */
        ListaAdjacencia vertices;
};

#endif