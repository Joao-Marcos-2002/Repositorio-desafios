#ifndef MATH
#define MATH

#ifndef MAXTAM
#define MAXTAM 5

#endif

typedef struct mat {
	double m[MAXTAM][MAXTAM];
	int tamx, tamy;
	int id;
} mat_tipo;


// Descricao: cria matriz com dimensoes tx X ty
// Entrada: mat, tx, ty, id
// Saida: mat
void criaMatriz(mat_tipo * mat, int tx, int ty, int id);

// Descricao: inicializa mat com valores nulos 
// Entrada: mat
// Saida: mat
void inicializaMatrizNula(mat_tipo * mat);

// Descricao: inicializa mat com valores aleatorios
// Entrada: mat 
// Saida: mat
void inicializaMatrizAleatoria(mat_tipo * mat);

// Descricao: acessa mat para fins de registro de acesso 
// Entrada: mat 
// Saida: mat
double acessaMatriz(mat_tipo * mat);

// Descricao: imprime a matriz com a identificacao de linhas e colunas
// Entrada: mat
// Saida: impressao na saida padrao (stdout) 
void imprimeMatriz(mat_tipo * mat);

// Descricao: salva a matriz em arquivo
// Entrada: mat
// Saida: out
void salvaMatriz(mat_tipo * mat, FILE * out);

// Descricao: atribui o valor v ao elemento (x,y) de mat
// Entrada: mat, x, y, v
// Saida: mat
void escreveElemento(mat_tipo * mat, int x, int y, double v);

// Descricao: retorna o elemento (x,y) de mat 
// Entrada: mat, x, y
// Saida: mat[x][y] 
double leElemento (mat_tipo * mat, int x, int y);

// Descricao: faz uma copia de src em dst
// Entrada: src, dst_id
// Saida: dst
void copiaMatriz(mat_tipo *src, mat_tipo * dst, int dst_id);

// Descricao: soma as matrizes a e b e armazena o resultado em c
// Entrada: a, b
// Saida: c
void somaMatrizes(mat_tipo *a, mat_tipo *b, mat_tipo *c);

// Descricao: multiplica as matrizes a e b e armazena o resultado em c
// Entrada: a,b
// Saida: c
void multiplicaMatrizes(mat_tipo *a, mat_tipo *b, mat_tipo *c);

// Descricao: transpoe a matriz a
// Entrada: a
// Saida: a
void transpoeMatriz(mat_tipo *a);

// Descricao: destroi a matriz a, que se torna inacessível
// Entrada: a
// Saida: a
void destroiMatriz(mat_tipo *a);



#endif