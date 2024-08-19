#ifndef METODOS_ORDENACAO_HPP
#define METODOS_ORDENACAO_HPP

#include "grafo.hpp"

class MetodoOrdenacao {
public:
    static void bubbleSort(Vertice* vertices);
    static void selectionSort(Vertice* vertices);
    static void inserctionSort(Vertice* vertices);
    static void quickSort(Vertice* vertices, int esq, int dir);
    static void mergeSort(Vertice* vertices, int esq, int dir);
    static void heapSort(Vertice* vertices);
    static void proprioSort(Vertice* vertices);

private:
    static int partition(Vertice* vertices, int esq, int dir);
    static void merge(Vertice* vertices, int esq, int pivo, int dir);
    static void heapify(Vertice* vertices, int tam, int num);
};

#endif
