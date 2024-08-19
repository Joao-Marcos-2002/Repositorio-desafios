#include <stdlib.h>
#include <stdio.h>

int main(void)
{
        int *p;
        int c = 0;
        while(c <= 128)
        {
                c++;
                p = malloc(128);
                printf("%ld\n", (long)p);
        }
        return (0);
}
