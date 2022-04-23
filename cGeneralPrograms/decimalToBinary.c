#include <stdio.h>
int main()
{
    do
    {
        unsigned int n;
        int i = -1;
        char bin[30];
        printf("\nEnter a number to find its binary equivalent: ");
        scanf("%u", &n);
        printf("\nThe binary equivalent of %d is ", n);
        while(n > 0)
        {
            i++;
            if(n % 2 == 1)
                bin[i] = '1';
            else
                bin[i] = '0';
            n /= 2;
        }
        while(i > -1)
        {
            printf("%c", bin[i]);
            i--;
        }
        printf("\n\nEnter x to exit, enter anything else to repeat... ");
        fseek(stdin, 0, 0);
    } while(getchar() != 'x');
    return 0;
}