//---------------------------------------------------------------------
// Arquivo	: vet.c
// Conteudo	: implementacao do AP 6 (formato VPL)
// Autor	: João Marcos R. TOlentino
// Historico	: 2023-10-06 - arquivo criado
//---------------------------------------------------------------------


Após rodar o "make all" 

deve-se executar dentro da pasta bin:

./pa6.out -opção

Opção -d:
Ex de saída:
Quantidade de vértices: 4
Quantidade de arestas: 2
Grau mínimo: 0
Grau máximo: 0


Opção -n:
EX:
Vizinhos do vértice 3: 2.



Opção -k

1 ou zero (se o grafo é completo ou não).


# Para compilar tudo basta rodar: "make all"


Estrutura padrão do projeto:

/bin
/include
/obj
/src
Makefile



Como dado na atividade:

“-d” Dados básicos: Deve imprimir na tela, um valor por linha: a quantidade de vértices e de arestas do grafo, o grau mínimo e o máximo.
“-n” Vizinhanças: Deve imprimir os vizinhos de cada um dos vértices. Todos os vizinhos de um vértice devem estar na mesma linha separados por um espaço em branco e encerrando com uma quebra de linha.
“-k” : Deve imprimir 1 caso o grafo de entrada seja um grafo completo e 0 caso contrário.
Recebe os dados de um grafo pela entrada padrão.
