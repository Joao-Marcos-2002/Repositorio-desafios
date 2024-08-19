#include <iostream>
#include "../include/grafo.hpp"
#include "../include/metodosOrdenacao.hpp"

using namespace std;


int main() {

    // c=metodo  n=qtd_vertices
    char c;
    int n;

    cin >> c >> n;

    // Cria um objeto da classe Grafo
    Grafo grafo(n);

    // Chame a função para ler a entrada e criar o grafo
    grafo.lerEntrada();

    
    // cout << "Antes da Ordenação: " << endl;
    // for (int i = 0; i < n; ++i) {
    //     cout << grafo.getVertices()[i].cor << " ";
    // }
    // cout << endl;

    if (c == 'b') {
    // Metodo da bolha (bubble sort). 
        MetodoOrdenacao::bubbleSort(grafo.getVertices());

    } else if (c == 's') {
        // Metodo da selecao (selection sort).
        MetodoOrdenacao::selectionSort(grafo.getVertices());
    } else if (c == 'i') {
        // Metodo da insercao (inserction sort).
        MetodoOrdenacao::inserctionSort(grafo.getVertices());
    } else if (c == 'q') {
        // Quicksort
        MetodoOrdenacao::quickSort(grafo.getVertices(), 0, n - 1);
    } else if (c == 'm') {
        // mergesort
        MetodoOrdenacao::mergeSort(grafo.getVertices(), 0, n - 1);
    } else if (c == 'p') {
        // heapsort
        MetodoOrdenacao::heapSort(grafo.getVertices());
    } else if (c == 'y') {
    // metodo proprio de ordenacao.
        MetodoOrdenacao::proprioSort(grafo.getVertices());
    }

    // Após a ordenação, avalie a coloração gulosamente
    bool coloracaoGulosa = grafo.avaliarColoracaoGulosa();

    // cout << "Depois da ordenacao" << endl;
    // for (int i = 0; i < n; ++i) {
    //     cout << grafo.getVertices()[i].cor << " ";
    // }
    // cout << endl;

    if (coloracaoGulosa) {
        cout << "1" << endl;
    } else {
        cout << "0" << endl;
    }
    
}


