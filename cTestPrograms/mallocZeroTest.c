#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *s;
    int i = 0;
    s = malloc(0);
    while(i > -1)
    {
        printf("\n%d\n", s[i]);
        i++;
    }
}