#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char buf[20]; // Aloque memória para buf com tamanho suficiente

int sum_to_n(int num)
{
    int i, sum = 0;
    for (i = 1; i <= num; i++)
        sum += i;
    return sum;
}

void printSum()
{
    char line[10];
    printf("Digite um número:\n");
    fgets(line, sizeof(line), stdin);
    if (line != NULL)
        strtok(line, "\n");
    sprintf(buf, "sum=%d", sum_to_n(atoi(line)));
    printf("%s\n", buf);
}

int main(void)
{
    printSum();
    return 0;
}
