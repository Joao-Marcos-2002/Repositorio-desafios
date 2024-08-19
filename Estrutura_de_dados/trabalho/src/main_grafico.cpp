#include <iostream>
#include "../include/grafo.hpp"
#include "../include/metodosOrdenacao.hpp"

using namespace std;


int main_grafico() {

    srand(time(NULL));
    struct timespec Time_Clock_Begin, Time_Clock_End;

    // c=metodo  n=qtd_vertices
    char c;
    int n;

    cin >> c >> n;

    // Cria um objeto da classe Grafo
    Grafo grafo(n);

    // Chame a função para ler a entrada e criar o grafo
    grafo.lerEntrada();


    if (c == 'b') {
    // Metodo da bolha (bubble sort). 
        clock_gettime(CLOCK_MONOTONIC, &(Time_Clock_Begin));
        MetodoOrdenacao::bubbleSort(grafo.getVertices());
        clock_gettime(CLOCK_MONOTONIC, &(Time_Clock_End));
        double tempoDecorrido = (Time_Clock_End.tv_sec - Time_Clock_Begin.tv_sec) +
        (Time_Clock_End.tv_nsec - Time_Clock_Begin.tv_nsec) / 1e9;

        cout << "tempo decorrido:" << tempoDecorrido;
        //pegar a diferença do tempo de inicio e fim, converter pra seg ou miliseg
        //se puder em python criar um csv e usar a biblioteca pandas pra plotar o gráfico

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

    for (int i = 0; i < n; ++i) {
        cout << grafo.getVertices()[i].cor << " ";
    }
    cout << endl;

    
    // Após a ordenação, avalie a coloração gulosamente
    bool coloracaoGulosa = grafo.avaliarColoracaoGulosa();

    if (coloracaoGulosa) {
        cout << "1" << endl;
    } else {
        cout << "0" << endl;
    }
    
}


