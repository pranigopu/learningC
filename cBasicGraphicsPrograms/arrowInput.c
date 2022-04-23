#include <stdio.h>
#include <stdlib.h>
int main()
{
    char c[10];
    int i = 0;
    system("/bin/stty raw");
    scanf("%s", c);
    if(c[0] == 27 && c[1] == '[' && c[2] == 'D')
        printf("\nleft arrow\n");
    else if(c[0] == 27 && c[1] == '[' && c[2] == 'A')
        printf("\nup arrow\n");
    else if(c[0] == 27 && c[1] == '[' && c[2] == 'B')
        printf("\ndown arrow\n");
    else if(c[0] == 27 && c[1] == '[' && c[2] == 'C')
        printf("\nright arrow\n");
    printf("\n%d%c%c\n", c[0], c[1], c[2]);
    printf("\n");
    system("/bin/stty cooked");
}