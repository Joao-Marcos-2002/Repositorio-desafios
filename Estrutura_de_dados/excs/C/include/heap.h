#ifndef HEAP_HPP
#define HEAP_HPP

/*  Você pode inserir os includes necessários para que sua classe funcione.
 * Alteracoes no arquivo so podem ser feitas quando explicitadas
 */

typedef struct s_heap{
    int tamanho;
    int* dados;
} Heap;

Heap* NovoHeap(int maxsize);
void DeletaHeap(Heap* h);

void Inserir(Heap* h, int x);
int Remover(Heap* h);

int GetAncestral(Heap* h, int posicao);
int GetSucessorEsq(Heap* h, int posicao);
int GetSucessorDir(Heap* h, int posicao);

//Retorna 1 caso h esteja vazio, 0 caso contrário.
int Vazio(Heap* h); 

/* Funções necessárias para implementar o Heapify recursivo
 * Você pode apagar elas caso decida implementar o Heapify iterativo
 */
void HeapifyPorBaixo(Heap* h, int posicao);
void HeapifyPorCima(Heap* h, int posicao);

#endif