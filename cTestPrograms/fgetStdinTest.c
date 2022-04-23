#include <stdio.h>
int main()
{
    char in[10][100];
    char c;
    int i = 0, j = 0;
    while(i < 10)
    {
        fseek(stdin, 0, 0);
        fgets(in[i], 100, stdin);
        i++;
    }
    for(j = 0; j < i; j++)
    printf("%s", in[j]);
    printf("\n");
}