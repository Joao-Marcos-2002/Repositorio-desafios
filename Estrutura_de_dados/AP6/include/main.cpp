#include <iostream>
#include <sstream>
#include "graph.hpp"
#include "listaAdjacencia.hpp"

int main(int argc, char *argv[]) {
    Grafo grafo;

    if (argc < 2) {
        std::cerr << "Uso: " << argv[0] << " <operacao> [argumentos]" << std::endl;
        return 1;
    }

    std::string operacao = argv[1];

    if (operacao == "-d") {
        std::cout << "Quantidade de vértices: " << grafo.QuantidadeVertices() << std::endl;
        std::cout << "Quantidade de arestas: " << grafo.QuantidadeArestas() << std::endl;
        std::cout << "Grau mínimo: " << grafo.GrauMinimo() << std::endl;
        std::cout << "Grau máximo: " << grafo.GrauMaximo() << std::endl;
    } else if (operacao == "-n") {
        for (int v = 0; v < grafo.QuantidadeVertices(); v++) {
            std::cout << "Vizinhos do vértice " << v << ": ";
            grafo.ImprimeVizinhos(v);
            std::cout << std::endl;
        }
    } else if (operacao == "-k") {
        int grafoCompleto = grafo.EhGrafoCompleto();
        std::cout << "O grafo é completo? " << grafoCompleto << std::endl;
    } else {
        std::cerr << "Operação inválida: " << operacao << std::endl;
        return 1;
    }

    return 0;
}
