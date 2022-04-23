#include <stdio.h>
int main()
{
    unsigned int n, max, min;
    max = 0;
    min = 9;
    printf("\nEnter a number: ");
    scanf("%u", &n);
    unsigned int original = n;
    while(n > 0)
    {
        if(n % 10 > max)
        max = n % 10;
        if(n % 10 < min)
        min = n % 10;
        n /= 10;
    }
    printf("The largest digit is %u, and the smallest digit is %u\n\n", max, min);
    n = original % 2;
    switch(n)
    {
        case 1:
        for(int i = 0; i < max + 1; i++)
        {
            printf("%u * %d = %u\n", min, i, min * i);
        }
        break;
        case 0:
        min = 1;
        for(int i = 1; i < max + 1; i++)
        {
            min *= i;
        }
        printf("%u! = %u\n", max, min);
    }
    printf("\n");
    return 0;
}