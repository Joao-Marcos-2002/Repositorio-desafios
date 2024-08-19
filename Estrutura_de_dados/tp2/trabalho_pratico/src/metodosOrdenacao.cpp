#include <iostream>
#include "../include/metodosOrdenacao.hpp"

using namespace std;

void MetodoOrdenacao::bubbleSort(Vertice* vertices) {
    Vertice* i, *j;
    bool troca;

    for (i = vertices; i != nullptr; i = i->proximo) {
        troca = false;

        for (j = vertices; j->proximo != nullptr; j = j->proximo) {
            if (j->cor < j->proximo->cor) {
                swap(j->cor, j->proximo->cor);
                troca = true;
            }
        }

        if (!troca) {
            break;  // Se não houve troca, a lista está ordenada
        }
    }
}

void MetodoOrdenacao::selectionSort(Vertice* vertices) {
    Vertice* i, *j, *min;

    for (i = vertices; i != nullptr; i = i->proximo) {
        min = i;

        for (j = i->proximo; j != nullptr; j = j->proximo) {
            if (j->cor > min->cor) {
                min = j;
            }
        }

        if (min != i) {
            swap(i->cor, min->cor);
        }
    }
}

void MetodoOrdenacao::inserctionSort(Vertice* vertices) {
    Vertice* i, *j;
    Vertice* chave;

    for (i = vertices->proximo; i != nullptr; i = i->proximo) {
        chave = i;
        j = i->anterior;

        while (j != nullptr && j->cor > chave->cor) {
            swap(j->cor, chave->cor);
            chave = j;
            j = j->anterior;
        }
    }
}

void MetodoOrdenacao::quickSort(Vertice* vertices, int esq, int dir) {
    if (esq < dir) {
        int pivo = partition(vertices, esq, dir);
        quickSort(vertices, esq, pivo);
        quickSort(vertices, pivo + 1, dir);
    }
}

int MetodoOrdenacao::partition(Vertice* vertices, int esq, int dir) {
    Vertice* pivot = &vertices[esq];
    int i = esq - 1;
    int j = dir + 1;

    while (true) {
        do {
            i++;
        } while (vertices[i].cor < pivot->cor);

        do {
            j--;
        } while (vertices[j].cor > pivot->cor);

        if (i >= j) {
            return j;
        }

        swap(vertices[i], vertices[j]);
    }
}

void MetodoOrdenacao::mergeSort(Vertice* vertices, int esq, int dir) {
    if (esq < dir) {
        int pivo = esq + (dir - esq) / 2;
        mergeSort(vertices, esq, pivo);
        mergeSort(vertices, pivo + 1, dir);
        merge(vertices, esq, pivo, dir);
    }
}

void MetodoOrdenacao::merge(Vertice* vertices, int esq, int pivo, int dir) {
    int n1 = pivo - esq + 1;
    int n2 = dir - pivo;

    Vertice* temp1 = new Vertice[n1];
    Vertice* temp2 = new Vertice[n2];

    for (int i = 0; i < n1; i++) {
        temp1[i] = vertices[esq + i];
    }
    for (int j = 0; j < n2; j++) {
        temp2[j] = vertices[pivo + 1 + j];
    }

    int i = 0, j = 0, k = esq;

    while (i < n1 && j < n2) {
        if (temp1[i].cor >= temp2[j].cor) {
            vertices[k] = temp1[i];
            i++;
        } else {
            vertices[k] = temp2[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        vertices[k] = temp1[i];
        i++;
        k++;
    }

    while (j < n2) {
        vertices[k] = temp2[j];
        j++;
        k++;
    }

    delete[] temp1;
    delete[] temp2;
}

void MetodoOrdenacao::heapSort(Vertice* vertices) {
    int tamanho = 0;
    for (Vertice* i = vertices; i != nullptr; i = i->proximo) {
        tamanho++;
    }

    for (int i = tamanho / 2 - 1; i >= 0; i--) {
        heapify(vertices, tamanho, i);
    }

    for (int j = tamanho - 1; j > 0; j--) {
        swap(vertices[0].cor, vertices[j].cor);
        heapify(vertices, j, 0);
    }
}

void MetodoOrdenacao::proprioSort(Vertice* vertices) {
    bool troca;
    Vertice* temp;

    do {
        troca = false;
        temp = vertices;

        while (temp != nullptr && temp->proximo != nullptr) {
            if (temp->cor > temp->proximo->cor) {
                swap(temp->cor, temp->proximo->cor);
                troca = true;
            }
            temp = temp->proximo;
        }
    } while (troca);
}

void MetodoOrdenacao::heapify(Vertice* vertices, int tam, int num) {
    int itemMaior = num;
    int esq = 2 * num + 1;
    int dir = 2 * num + 2;

    if (esq < tam && vertices[esq].cor > vertices[itemMaior].cor) {
        itemMaior = esq;
    }

    if (dir < tam && vertices[dir].cor > vertices[itemMaior].cor) {
        itemMaior = dir;
    }

    if (num != itemMaior) {
        swap(vertices[num].cor, vertices[itemMaior].cor);
        heapify(vertices, tam, itemMaior);
    }
}

