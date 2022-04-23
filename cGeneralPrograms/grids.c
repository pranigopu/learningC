#include <stdio.h>
int main()
{
    int i, j;
    int A[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    printf("\n");
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            printf("%d ", A[3 * i + j]);
            if(j != 2)
            printf("| ");
        }
        printf("\n-");
        for(j = 0; j < 2; j++)
        {
            printf("-+--");
        }
        printf("\n");
    }
    printf("\n\n");
}