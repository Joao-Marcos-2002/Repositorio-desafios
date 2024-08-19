#ifndef VETOR_H_
#define VETOR_H_

#include <iostream> 
using namespace std;


#include <string>

using std::string;

// Define um vetor cujos índices variam em
// qualquer intervalo, inclusive negativos.
template<class Tipo> class Vetor {
  public:
    // Cria um vetor cujos índices variam de 'inicio' até 'fim'.
    // O valor associado aos índices é indefinido.
    // PRECONDIÇÃO: fim >= inicio.
    Vetor(int inicio, int fim) : inicio_(inicio), fim_(fim) {
      elementos_ = new Tipo[fim - inicio + 1];
    }

    // Redimensiona o vetor de forma que os índices passam a variar
    // de 'inicio2' até 'fim2'.
    // O valor associado aos índices que estão na interseção de
    // [inicio_, fim_] e [inicio2, fim2], não se alteram.
    // Já o valor dos demais índices é indefinido.  
    // PRECONDIÇÃO: fim2 >= inicio2.
    void Redimensionar(int inicio2, int fim2) {
      // Cria o novo vetor.
      Tipo* elementos2 = new Tipo[fim2 - inicio2 + 1];
      // Copia os índices na interseção para o novo vetor. 
      for (int i = inicio_; i <= fim_; i++) {
        if (inicio2 <= i && i <= fim2) {
          int j = i - inicio_;
          int j2 = i - inicio2;
          elementos2[j2] = elementos_[j];
        }
      }
      // Sobrescreve o vetor elementos_.
      delete [] elementos_;
      elementos_ = elementos2;
      inicio_ = inicio2;
      fim_ = fim2;
    }

    // Retorna uma referência a variável correspondente ao índice i.
    // Pode ser utilizado tanto para atribuir quanto para acessar valores.
    // PRECONDIÇÃO: i está dentro do intervalo de índices do vetor.
    Tipo& operator[](int i) { 
      int j = i - inicio_;  
      return elementos_[j];
    }

    // Desaloca a memória reservada para os elementos do vetor.
    ~Vetor() {
      delete [] elementos_;
    }
  private:
    int inicio_;  // Primeiro índice válido do vetor.
    int fim_;  // Último índice válido do vetor.
    Tipo* elementos_;  // Elementos do vetor.
};

#endif