#include <iostream>
#include <stdexcept> 
#include <new>       
#include "../include/grafo.hpp"
#include "../include/metodosOrdenacao.hpp"

using namespace std;

int main() {
    try {
        char c;
        int n;

        cin >> c >> n;

        if (n <= 0) {
            throw invalid_argument("O número de vértices deve ser maior que zero.");
        }

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
        } else {
            throw invalid_argument("Opção de método de ordenação inválida.");
        }

        bool coloracaoGulosa = grafo.avaliarColoracaoGulosa();

        if (coloracaoGulosa) {
            cout << "1" << endl;
        } else {
            cout << "0" << endl;
        }
    } catch (const exception& e) {
        cerr << "Exceção capturada: " << e.what() << endl;
        return 1; 
    } catch (...) {
        cerr << "Exceção desconhecida capturada." << endl;
        return 1; 
    }

    return 0; 
}
