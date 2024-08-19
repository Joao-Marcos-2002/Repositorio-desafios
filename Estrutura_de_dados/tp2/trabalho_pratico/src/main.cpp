#include <iostream>
#include <stdexcept> 
#include <new>       
#include "../include/grafo.hpp"
#include "../include/metodosOrdenacao.hpp"

using namespace std;

int main() {
    
        char c;
        int n;

        cin >> c >> n;

        Grafo grafo(n);
        grafo.lerEntrada();

        if (c == 'b') {
            MetodoOrdenacao::bubbleSort(grafo.getVertices());
        } else if (c == 's') {
            MetodoOrdenacao::selectionSort(grafo.getVertices());
        } else if (c == 'i') {
            MetodoOrdenacao::inserctionSort(grafo.getVertices());
        } else if (c == 'q') {
            MetodoOrdenacao::quickSort(grafo.getVertices(), 0, n - 1);
        } else if (c == 'm') {
            MetodoOrdenacao::mergeSort(grafo.getVertices(), 0, n - 1);
        } else if (c == 'p') {
            MetodoOrdenacao::heapSort(grafo.getVertices());
        } else if (c == 'y') {
            MetodoOrdenacao::proprioSort(grafo.getVertices());
        }

        bool coloracaoGulosa = grafo.avaliarColoracaoGulosa();

        if (coloracaoGulosa) {
            cout << "1" << endl;
        } else {
            cout << "0" << endl;
        }
    
    return 0; 
}
