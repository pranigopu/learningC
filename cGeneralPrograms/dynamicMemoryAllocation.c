//INTRODUCING DYNAMIC MEMORY ALLOCATION
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *p;
    int i, n;
    printf("\nHow large must the array be?\nEnter the maximum number of elements: ");
    scanf("%d", &n);
    p = malloc(n * sizof(int));
    if(p == NULL)
    {
        printf("\nOops, insufficient storage!\n");
        return 0;
    }
    printf("\nNow enter the elements...\n");
    for(i = 0; i < n; i++)
    {
        printf("p[%d] = ", i);
        scanf("%d", &p[i]);
    }
    printf("\nHere are your elements...\n");
    for(i = 0; i < n; i++)
    {
        printf("p[%d] = %d\n", i, p[i]);
    }
    return 0;
}