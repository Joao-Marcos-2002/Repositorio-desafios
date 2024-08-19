#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

// Definie um tipo Matriz.
typedef vector<vector<int>> Matriz;

// Retorna uma matriz (l x c) lida da entrada padrão.
Matriz Ler(int l, int c) {
  Matriz m(l, vector<int>(c));
  for (int i = 0; i < l; i++) {
    for (int j = 0; j < c; j++) {
      cin >> m[i][j];
    }
  }
  return m;
}

// Imprime uma matriz da saída padrão.
void Imprimir(const Matriz& m) {
  for (auto linha : m) {
    for (auto celula : linha) {
      cout << celula << " ";
    }
    cout << endl;
  }
}

// Retorna o resultado da multiplicação de 'p' e 'q';
Matriz Multiplicar(Matriz p, Matriz q) {
  int l1 = p.size();  // #linhas de p.
  int l2 = q.size();  // #colunas (resp. #linhas) de p (resp. q).
  int c2 = q[0].size();  // #colunas de q.
  Matriz m(l1, vector<int>(c2));
  for (int i = 0; i < l1; i++) {
    for (int j = 0; j < c2; j++) {
      int soma = 0;
      for (int k = 0; k < l2; k++) {
        soma += p[i][k] * q[k][j];
      }
      m[i][j] = soma;
    }
  }
  return m;
}

int main() {
  int l1;  // #linhas da primeira matriz.
  int l2;  // #colunas (resp. #linhas) da primeira (resp. segunda) matriz.
  int c2;  // #colunas da segunda matriz.
  // Lê as dimensões das matrizes;
  cin >> l1 >> l2 >> c2;

  Matriz m1 = Ler(l1, l2);
  Matriz m2 = Ler(l2, c2);
  Matriz m3 = Multiplicar(m1, m2);
  Imprimir(m3); 
  return 0;
}
