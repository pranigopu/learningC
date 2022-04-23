#include <stdio.h>
int main()
{
    char cmd;
    printf("\nPRIME FINDER");
    printf("\nFind prime numbers x1, x2 ... xn where A ≤ xi ≤ B\n\n");
    do
    {
        int A = 1, B = 0; //B < A, so that the next while loop can be entered
        int i, j;
        int absi; //Abbreviation for 'absolute value of i'
        int check = 0;
        int linemark = 0; //linemark will only be used for formatting
        while(B < A)
        {
            printf("Enter A: ");
            fseek(stdin, 0, 0);
            scanf("%d", &A);
            printf("Enter B: ");
            fseek(stdin, 0, 0);
            scanf("%d", &B);
            if(B < A)
            printf("\nInvalid inputs: lower bound A must be less than or equal to upper bound B\n\n");
        }
        check = 0;
        printf("\nPrime numbers from %d to %d:\n\n", A, B);
        for(i = A; i < B + 1; i++)
        {
            absi = i;
            if(i < 0)
            absi *= -1;
            if(absi == 1 || absi == 0)
            {
                check++;
                continue;
            }
            for(j = 2; (j - 1) * (j - 1) < absi + 1; j++) //In the case of integers, saying (j - 1) < absi + 1 means (j - 1) ≤ absi
            /*
            It can be that... 
            ... while a number j is s.t. j * j < absi, the very next number j can be s.t. j * j > absi.
            E.g. 2 * 2 = 4 < 7, but 3 * 3 = 9 > 7
            ------------------------------------------------
            'check' is supposed to be 0 if the last possible factor is not an actual factor.
            Hence we must ensure the last j value which is not a factor of absi is s.t. j * j ≥ absi
            Hence, we must not terminate the loop when j * j > absi, otherwise 'check' may never become 0.
            Hence, we can verify for j - 1.
            In this way, we can verify if j * j ≥ absi before terminating the loop.

            The exact method is explained below.
            */
            {
                if(absi % j == 0)
                {
                    if(j == 1)
                    continue;
                    check++;
                    break;
                }
                else if(j * j / absi > 0)
                /*
                If j * j ≥ absi, it must mean that no further factors can be found for absi.
                This is because the factors of a number repeat after the square root of the number is exceeded.
                ------------------------------------------------
                If j * j ≥ absi, then
                j * j / absi ≥ 1, which, in the case of integer division, implies that
                j * j / absi > 0
                */
                {
                    check = 0;
                }
            }
            if(check == 0)
            {
                linemark++;          
                if(linemark == 10) //For formatting only  
                {
                    printf("\n\n");
                    linemark = 1;
                }
                printf("%d\t", i);
            }
        }
        if(B < A)
        {
            A = A + B;
            B = A - B;
            A = A - B;
            //Hence, B - A is always positive
        }
        if(check == B - A + 1)
        printf("No primes found");
        printf("\n\nEnter t to terminate: ");
        fseek(stdin, 0, SEEK_SET);
        scanf("%c", &cmd);
        printf("\n");
    } while(cmd != 't'); 
    printf("\nPROGRAM TERMINATED\n\n");
    return 0;
}