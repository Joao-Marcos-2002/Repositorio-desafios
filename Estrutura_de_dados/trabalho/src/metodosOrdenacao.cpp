#include <iostream>
#include "../include/metodosOrdenacao.hpp"

using namespace std;

void MetodoOrdenacao::bubbleSort(Vertice* vertices) {
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



void MetodoOrdenacao::selectionSort(Vertice* vertices) {
    Vertice* i, *j, *min;

    // Percorra a lista encadeada
    for (i = vertices; i != nullptr; i = i->proximo) {
        min = i;

        // Encontre o menor elemento no restante da lista
        for (j = i->proximo; j != nullptr; j = j->proximo) {
            if (j->cor < min->cor) {
                min = j;
            }
        }

        // Troque as cores dos vértices
        std::swap(i->cor, min->cor);
    }

    for (Vertice* k = vertices; k != nullptr; k = k->proximo) {
        cout << k->cor << " ";
    }
    cout << endl;
}

void MetodoOrdenacao::inserctionSort(Vertice* vertices) {
    for (Vertice* i = vertices->proximo; i != nullptr; i = i->proximo) {
        Vertice* chave = i;
        Vertice* j = i->proximo;

        while (j != nullptr && j->cor < chave->cor) {
            swap(j->cor, chave->cor);
            chave = j;
            j = j->proximo;
        }
    }
}

void MetodoOrdenacao::quickSort(Vertice* vertices, int esq, int dir) {
    if (esq < dir) {
        // Escolhe o pivô e obtém o índice após a partição
        int pivo = partition(vertices, esq, dir);

        // Ordena as partições à esquerda e à direita do pivô
        quickSort(vertices, esq, pivo);
        quickSort(vertices, pivo + 1, dir);
    }
}

int MetodoOrdenacao::partition(Vertice* vertices, int esq, int dir) {
    // Escolhe o pivô como o elemento do meio
    int meio = esq + (dir - esq) / 2;
    Vertice pivot = vertices[meio];

    // Inicializa os índices para percorrer a submatriz
    int i = esq - 1;
    int j = dir + 1;

    while (true) {
        // Encontra elemento maior que o pivô à esquerda
        do {
            i++;
        } while (vertices[i].cor < pivot.cor);

        // Encontra elemento menor que o pivô à direita
        do {
            j--;
        } while (vertices[j].cor > pivot.cor);

        // Se os índices se cruzarem, a partição está completa
        if (i >= j) {
            return j;
        }

        // Troca os elementos encontrados
        swap(vertices[i], vertices[j]);
    }
}

void MetodoOrdenacao::mergeSort(Vertice* vertices, int esq, int dir) {
    if (esq < dir) {
        int pivo = (esq + dir) / 2;
        mergeSort(vertices, esq, pivo);
        mergeSort(vertices, pivo + 1, dir);
        merge(vertices, esq, pivo, dir);
    }
}
void MetodoOrdenacao::merge(Vertice* vertices, int esq, int pivo, int dir) {
    int i1 = pivo - esq + 1;
    int i2 = dir - pivo;

    // Cria cópias temporárias das partições da esquerda e da direita
    Vertice* esqTemp = new Vertice[i1];
    Vertice* dirTemp = new Vertice[i2];

    // Copia os elementos para as cópias temporárias
    for (int i = 0; i < i1; ++i) {
        esqTemp[i] = vertices[esq + i];
    }
    for (int j = 0; j < i2; ++j) {
        dirTemp[j] = vertices[pivo + 1 + j];
    }

    // Índices para percorrer as cópias temporárias
    int i = 0, j = 0;
    int k = esq;

    // Mescla as cópias temporárias de volta no array original
    while (i < i1 && j < i2) {
        if (esqTemp[i].cor <= dirTemp[j].cor) {
            vertices[k] = esqTemp[i];
            i++;
        } else {
            vertices[k] = dirTemp[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes, se houver, das cópias temporárias para o array original
    while (i < i1) {
        vertices[k] = esqTemp[i];
        i++;
        k++;
    }
    while (j < i2) {
        vertices[k] = dirTemp[j];
        j++;
        k++;
    }

    // Libera a memória alocada para as cópias temporárias
    delete[] esqTemp;
    delete[] dirTemp;
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
