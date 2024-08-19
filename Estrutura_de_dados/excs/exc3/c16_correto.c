#include <stdio.h>
#include <stdlib.h>

int actual_calc(int a, int b) {
  int c;
  
  if (b != 0) {
    c = a / b;
  } else {
    printf("Erro: Divisão por zero não é permitida.\n");
    // Trate o erro de acordo com a necessidade do seu programa.
  }
  printf("c %d", c);
  return 0;
}
int calc(){
  int a;
  int b;
  a=13;
  b=0;
  actual_calc(a, b);
  return 0;
}

int main(){
  calc();
  return 0;
}
