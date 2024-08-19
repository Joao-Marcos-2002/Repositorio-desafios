#include <iostream>

using namespace std;

int main(){

    // 1) Declare uma variável do tipo inteiro e atribua o valor '10'
    int i = 10;

    // 2) Declare um ponteiro para inteiros e inicialize com valor nulo (aka 'nullptr')
    int* ptr = nullptr; 

    // 3) Declare um vetor de inteiros e inicialize com valores de 9 a 0 (nessa ordem)
    int v[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};    

    // 4) Imprima o ENDEREÇO da variável declarada em (1)
    cout << &i << endl;

    // 5) Imprima o CONTEÚDO da variável declarada em (1)
    cout << i << endl;

    // 6) Imprima o ENDEREÇO da variável declarada em (2)
    cout << &ptr << endl;    
    
    // 7) Imprima o CONTEÚDO da variável declarada em (2)
    cout << ptr << endl;    

    // 8) Imprima o ENDEREÇO da variável declarada em (3)
    cout << &v << endl;

    // 9) Imprima o ENDEREÇO da primeira posição da variável declarada em (3)
    cout << &v[0] << endl;

    // 10) Imprima o CONTEÚDO da primeira posição da variável declarada em (3)
    cout << v[0] << endl;

    // 11) Atribua o ENDEREÇO da variável declarada em (1) à variável declarada em (2)
    ptr = &i;

    // 12) Imprima o CONTEÚDO da variável declarada em (2)
    cout << ptr << endl;

    // 13) Imprima o CONTEÚDO da varíavel que é apontada por (2)
    cout << *ptr << endl;

    // 14) Imprima o resultado da comparação do ENDEREÇO de (1) e do CONTEÚDO de (2)
    cout << (&i == ptr) << endl;

    // 15) Coloque o VALOR '5' na varíavel que é apontada pela variável de (2)
    *ptr = 5;

    // 16) Imprima o CONTEÚDO da variável declarada em (1)
    cout << i << endl;

    // 17) Atribua o CONTEÚDO da variável de (3) à variável de (2)
    ptr = v;

    // 18) Imprima o CONTEÚDO da variável declarada em (2) 
    cout << ptr << endl;

    // 19) Imprima o CONTEÚDO da variável que é apontada pela variável de (2)
    cout << *ptr << endl;

    // 20) Atribua o ENDEREÇO da primeira posição de (3) à variável de (2)
    ptr = &v[0];

    // 21) Imprima o CONTEÚDO da variável declarada em (2) 
    cout << ptr << endl;
    
    // 22) Imprima o CONTEÚDO da variável que é apontada pela variável de (2) 
    cout << *ptr << endl;

    // 23) Imprima os elementos de (3) a partir variável do vetor utilizando a notação [] (e.g. v[i])
    for (int j = 0; j < 10; j++) {
      cout << v[j] << (j<9?" ":"\n");
    }

    // 23) Imprima os elementos de (3) a partir variável do vetor utilizando a notação ponteiro/deslocamento (e.g. *(a3 + i))
    for (int j = 0; j < 10; j++) {
      cout << *(v + j) << (j<9?" ":"\n");
    }
    return 0;
}