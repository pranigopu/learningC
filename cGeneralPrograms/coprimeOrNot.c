#include <stdio.h>
#include "intMath.h"
int main()
{
    int A[3];
    scanf("%d%d", &A[0], &A[1]);
    printf("Are coprime? %d\n", areCoprime(A, 2));
    return 0;
}