#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    if(n & 1)
        printf("\n%d is odd\n\n", n);
    else
        printf("\n%d is even\n\n", n);
}