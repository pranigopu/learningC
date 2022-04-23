#include <stdio.h>
#include "miscLib.h"
#include <stdlib.h>
#include "intMath.h"
#include "intMathPlus.h"
#define X 9
#define Y 8
int bye()
{
    printf("\nGoodbye!\n\n");
    return 0;
}
int main()
{
    int N[X];
    char NON[Y];//Number of numbers, string 

    do
    {
        int i = 0;
        int non = 0;//Number of numbers, integer value
        long unsigned int ans;
        system("clear");
        printf("\nFIND HCF AND LCM\nEnter x anytime to exit\n\n");
        
        do
        {
            printf("How many numbers? ");
            fseek(stdin, 0, 0);
            scanf("%s", NON);
            if(NON[0] == 'x')
            return bye();
            if((NON[1] != 0) || (NON[0] < 50 || NON[0] > 57))
            printf("\nERROR: Please enter a number from 2 to %d only.\n\n", X);
            else
            non = NON[0] - 48;
        } while(non < 2 || non > 9);

        printf("\n");
        for(i = 0; i < non; i++)
        {
            while(1)
            {
                NON[Y - 1] = 0;
                printf("Number %d: ", i + 1);
                fseek(stdin, 0, 0);
                scanf("%s", NON);
                N[i] = numIntify(NON);
                if(NON[0] == 'x')
                return bye();
                if(N[i] != -1)
                {
                    if(NON[Y - 1])
                    printf("\nERROR: This number is too big for this program.\n\n");
                    else if(NON[0] != '-')
                    break;
                    else
                    printf("\nERROR: Restrict to positive integers only.\n\n");
                }
                else
                printf("\nERROR: Not a number.\n\n");
            }
        }

        printf("\nEnter 1 to find HCF");
        printf("\nEnter 2 to find HCF and see the prime factorisation.");
        printf("\nEnter 3 to find LCM");
        printf("\nEnter 4 to find LCM and see the prime factorisation.\n\nEnter one option: ");

        do
        {   fseek(stdin, 0, 0);
            scanf("%c", &NON[0]);
            
            switch(NON[0])
            {
                case '1':
                ans = hcf(N, non);
                non = 1;
                break;

                case '2':
                ans = hcfPlus(N, non);
                non = 1;
                break;

                case '3':
                ans = lcm(N, non);
                non = 1;
                break;

                case '4':
                ans = lcmPlus(N, non);
                non = 1;
                break;
                
                case 'x':
                return bye();

                default: 
                printf("\nERROR: Option unavailable.\n\nPlease enter one of the listed options: ");
                non = -1;
            }
        } while(non < 0);

        (NON[0] < '3')? printf("\n\nHCF ") : printf("\n\nLCM ");
        printf("= %lu\n\n", ans);

        printf("Enter any key except x to repeat... ");
        fseek(stdin, 0, 0);
        scanf("%c", &NON[0]);

    } while(NON[0] != 'x');

    return bye();
}