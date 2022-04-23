#include <stdio.h>
#include "conversionMath.h"
#define MAX 9
int end(short);
int main()
{
    char bin[MAX];
    int i = 0;
    double ans = 0;
    scanf("%s", bin);
    while(bin[i] != 0 && i < MAX)
        i++;
    if(i == MAX)
        return end(2);
    ans = binToDec(bin);
    if(ans == -1)
        return end(1);
    printf("\nDecimal equivalent is %f\n\n", ans);
}
int end(short x)
{
    switch(x)
    {
        case 1:
        printf("\nThis is not a binary number.\n\n");
        return 0;
        case 2:
        printf("\nThis number is too big.\n\n");
    }
    return 0;
}