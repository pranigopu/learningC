#include <stdio.h>
int fac(int);
int main()
{
    int n;
    printf("\nEnter number: ");
    scanf("%d", &n);
    printf("Factorial of %d is %d\n\n", n, fac(n));
}
int fac(int n)
{
    if(n < 2)
        return 1;
    return n * fac(n - 1);
}