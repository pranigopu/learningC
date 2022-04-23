#include <stdio.h>
int main()
{
    struct data
    {
        int a;
        float b;
        char c;
    };
    struct data x;
    printf("\nstruct data x.a = ");
    scanf("%d", &x.a);
    printf("struct data x.b = ");
    scanf("%f", &x.b);
    printf("struct data x.c = ");
    fseek(stdin, 0, 0);
    scanf("%c", &x.c);
    printf("\nThe structure unravelled...\n\n%d\t%f\t%c\n\n", x.a, x.b, x.c);
    return 0;
}