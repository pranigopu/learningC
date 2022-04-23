#include <stdio.h>
int main()
{
    unsigned int n, temp, digit;
    unsigned int pal_n = 0;
    do
    {
        printf("\nEnter a whole number to find it is a palindrome: ");
        scanf("%u", &n);
        temp = n;
        while(temp > 0)
        {
            digit = temp % 10;
            pal_n = pal_n * 10 + digit;
            temp /= 10;
        }
        if(n == pal_n)
        {
            printf("\n%u is a palindrome", n);
            if(n % 2 == 0)
                printf(" and also an even number.\n");
            else
                printf(" but not an even number.\n");
        }
        else
            printf("\n%u is not a palindrome.\n", n);
        printf("\nEnter x to exit, enter anything else to repeat... ");
        fseek(stdin, 0, 0);
    } while(getchar() != 'x');
    return 0;
}