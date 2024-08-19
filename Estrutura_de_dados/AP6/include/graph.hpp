#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "listaAdjacencia.hpp"



class Grafo{
    public:
        Grafo();
        ~Grafo();

        void InsereVertice();
        void InsereAresta(int v, int w);

        int QuantidadeVertices();
        int QuantidadeArestas();

        int GrauMinimo();
        int GrauMaximo();

        void ImprimeVizinhos(int v);
        bool EhGrafoCompleto();
        
    private:
        
        /*  Você deve implementar ListaAdjacencia como um TAD que irá armazenar
         * os dados do grafo. Lembrando que este TAD deve ser uma lista 
         * encadeada
         */
        ListaAdjacencia vertices;
};

#endif