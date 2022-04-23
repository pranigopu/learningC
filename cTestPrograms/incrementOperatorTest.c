#include <stdio.h>
int main()
{
    int i = 0;
    printf("\n%d\n", i++ == 1);
    printf("\n%d\n", i++ == 1);

    i = 0;

    printf("\n%d\n", i++ * 1);
    printf("\n%d\n\n", i * 1);

    i = 0;
}