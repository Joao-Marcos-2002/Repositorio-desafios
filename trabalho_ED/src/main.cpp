#include <iostream>
#include "../include/segtree.hpp"

using namespace std;


int main()
{

    try {
        // Entrada de dados
        int n, q;
        cin >> n >> q;

        Segtree arvore(n);

        arvore.build(1, 0, n - 1);
        Matriz result = Matriz{1, 0, 0, 1};
        
        for (int i = 0; i < q; i++)
        {
            //Seleciona o metodo.
            char metodo;
            cin >> metodo;

            if (metodo == 'u')
            {
                // update
                int i;
                cin >> i; 
                Matriz x(0, 0);

                // Ler os elementos da matriz x
                cin >> x.m[0][0] >> x.m[0][1] >> x.m[1][0] >> x.m[1][1];

                arvore.update(i, x, 1, 0, n - 1);
            }
            else if (metodo == 'q')
            {
                // consulta
                int l, r, x, y;

                cin >> l >> r >> x >> y;

                auto result = arvore.query(l, r, 1, 0, n - 1);
                Matriz segunda(x, y);
                Matriz resultadoFinal = resultadoFinal.multMatriz(result, segunda);

                cout << resultadoFinal.m[0][0] << " " << resultadoFinal.m[1][0] << endl;
        
            } else {
                throw invalid_argument("Método inválido.");
            }
        }

    } catch (const exception& e) {
        cerr << "Erro: " << e.what() << endl;
        return 1; // Sair com código de erro
    }

        return 0;
    }