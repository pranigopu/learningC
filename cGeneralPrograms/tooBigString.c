#include <stdio.h>
int main()
{
    char W[2];
    fseek(stdin, 0, 0);
    scanf("%s", W);
    if(W[1] != 0)
    printf("\nToo big!\n\n");
    else
    printf("\nFine!\n\n");
    return 0;
}