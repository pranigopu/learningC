#include <stdio.h>
int main()
{
    int N[10] = {9, 4, 6, 7, 8, 2, 1, 3, 0, 5};
    int *p = N;
    printf("\n%d\n\n", *(p + 1));
}