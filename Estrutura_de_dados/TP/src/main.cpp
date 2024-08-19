#include <iostream>
#include <cstring>
#include <string>
#include "../include/avaliarExp.hpp"
#include "../include/satisfabilidade.hpp"

using namespace std;




// Função para avaliar a expressão lógica
int avaliarExpressao(const char *exp, const char *valor) {
    int resultadoFinal = 0;
    int tam = strlen(exp);
        int valor0 = valor[0] - '0';
        int valor1 = valor[1] - '0';

    for (int i = 0; i < tam; i++) {
        if (exp[i] == ' ') {
            continue;
        }
        if (exp[i] == '0') {
            resultadoFinal = valor0;
        } else if (exp[i] == '1') {
            resultadoFinal = valor1;
        } else if (exp[i] == '~') {
            i++;
            int prox_valor = valor[exp[i] - '0'] - '0';
            prox_valor = !prox_valor;
            resultadoFinal = prox_valor;
        } else if (exp[i] == '&') {
            i++;
            if (exp[i] == ' ') {
                i++;
            }
            int prox_valor = valor[exp[i] - '0'] - '0';
            resultadoFinal = resultadoFinal && prox_valor;
        } else if (exp[i] == '|') {
            i++;
            if (exp[i] == ' ') {
                i++;
            }
            int prox_valor = valor[exp[i] - '0'] - '0';
            resultadoFinal = resultadoFinal || prox_valor;
        } else if (exp[i] == '(') {
            int contagemParenteses = 1;
            i++;
            while (contagemParenteses > 0) {
                if (exp[i] == '(') {
                    contagemParenteses++;
                } else if (exp[i] == ')') {
                    contagemParenteses--;
                }
                if (contagemParenteses < 0) {
                // Parênteses desbalanceados
                throw std::runtime_error("Parênteses desbalanceados");

                // cout << "Parenteses desbalanceados" << endl;
                return false;
            }
                i++;
            }
        }
    }


    return resultadoFinal;
}


// Função para verificar satisfabilidade da expressão
string satisfabilidade(const char *exp, const char *valor)
{
    int tam = strlen(exp);
    int tamanhoValor = strlen(valor);

    string copiaExp(exp);
    string copiaValor(valor);
    int k = 0;

    for (int i = 0; i < tamanhoValor; i++)
    {
        if (copiaValor[i] == 'e')
        {
            k = i;
            copiaValor[i] = '1';
        }
    }

    // Substituir dígitos na expressão pelos valores correspondentes
    for (int i = 0; i < tam; i++)
    {
        if (copiaExp[i] == '0')
        {
            copiaExp[i] = valor[0];
        }
        else if (copiaExp[i] == '1')
        {
            copiaExp[i] = valor[1];
        }
        else if (copiaExp[i] == '2')
        {
            copiaExp[i] = valor[2];
        }
    }

    // Avaliar a expressão
    int r = avaliarExpressao(copiaExp.c_str(), copiaValor.c_str());

    // Reverter a substituição de 'e' por '0' para a segunda avaliação
    for (int i = 0; i < tamanhoValor; i++)
    {
        if (i == k)
        {
            copiaValor[i] = '0';
        }
    }

    // Avaliar a expressão novamente
    int r2 = avaliarExpressao(copiaExp.c_str(), copiaValor.c_str());
    string resultado;

    // Verifica a satisfabilidade
    if (r == 1 || r2 == 1)
    {
        for (int i = 0; i < tamanhoValor; i++)
        {
            if (i == k)
            {
                if (r2 == 0)
                {
                    copiaValor[i] = '1';
                }
                else
                {
                    copiaValor[i] = 'a';
                }
            }
        }
        resultado = "1 " + string(copiaValor);
    }
    else if (r == 0)
    {
        resultado = "0";
    }
    return resultado;
}

int main(int argc, char *argv[])
{
    // Verifica os argumentos da linha de comando
    if (argc != 4 || (strcmp(argv[1], "-a") != 0 && strcmp(argv[1], "-s") != 0))
    {
        cout << "Uso: " << argv[0] << " -a/-s <expressao> <valor>" << endl;
        return 1;
    }

    const char *exp = argv[2];
    const char *valor = argv[3];

    if (strcmp(argv[1], "-a") == 0)
    {
        // Resolver o problema de avaliacao (opcao: -a).
        int r = avaliarExpressao(exp, valor);
        cout << r << endl;
    }
    else if (strcmp(argv[1], "-s") == 0)
    {
        // Resolver o problema de satisfabilidade (opcao: -s).
        string r = satisfabilidade(exp, valor);
        cout << r << endl;
    }

    return 0;
}
