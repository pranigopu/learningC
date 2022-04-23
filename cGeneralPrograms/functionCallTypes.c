#include <stdio.h>
int main()
{
    void vswap(int, int);
    void rswap(int*, int*);
    printf("\nCOMPARING CALL BY VALUE AND CALL BY REFERENCE\n\n");
    int a, b;
    printf("a = ");
    scanf("%d", &a);
    printf("b = ");
    scanf("%d", &b);

    vswap(a, b);
    printf("\nIn main:\na = %d\nb = %d\n", a, b);

    rswap(&a, &b);
    printf("\nIn main:\na = %d\nb = %d\n\n", a, b);
}
void vswap(int a, int  b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
    printf("\nIn call-by-value swap function:\na = %d\nb = %d", a, b);
}
void rswap(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    printf("\nIn call-by-value swap function:\na = %d\nb = %d", *a, *b);
}