#include <stdio.h>

//Table of contents
//HCF FINDER WITH FORMATTED OUTPUT
//LCM FINDER WITH FORMATTED OUTPUT

//HCF FINDER WITH FORMATTED OUTPUT
int hcfPlus(int N[], int non)
{
    int i, j, k;
    int HCF = 1;
    k = 2;

    printf("\nFINDING HCF...\n____________");
    for(j = 0; (j < non && j < 10); j++)
    {
        printf("_________");
    }
    printf("\n");

    while(1)
    {
        int min = N[0];
        for(i = 0; i < non; i++)
        {
            if(N[i] < min)
            min = N[i];
        }
        if(k * k > min)
        break;
        j = 0;
        //Does k, a prime number, divide all the elements of N?
        for(i = 0; i < non; i++)
        {
            j += N[j] % k;
        }
        /*
        If k does divide all the elements of N: 
        1.  Modify HCF
        2.  Reduce all elements of N by k
        3.  Check 2.1. If false, check 2.2.
            3.1.  All elements of N are reduced to a co-prime state
            3.2.  At least one element of N is reduced to 1
        
        If either 3.1 or 3.2 are true, then HCF has been found, so break process.
        If neither are true: 
        -  find the next prime
        -  assign it to k
        -  continue the process.
        */
        if(j == 0)
        {
            printf("\n%d\t:\t", k);
            HCF *= k;
            for(i = 0; i < non; i++)
            {
                printf("%d\t", N[j]);
                N[i] /= k;
                if(N[i] == 1)
                j = 1;
            }
            if(j == 1)
            break;
            printf("\n");
        }
        else
        {
            k = nextPrime(k);
        }
    }
    printf("\n1\t:\t");
    for(i = 0; i < non; i++)
    {
        printf("%d\t", N[i]);
    }
    
    printf("\n____________");
    for(i = 0; (i < non && i < 10); i++)
    {
        printf("_________");
    }

    return HCF;
}

//LCM FINDER WITH FORMATTED OUTPUT
int lcmPlus(int N[], int non)
{
    int i, j, k, l;
    long unsigned int LCM = 1;
    k = 2;

    printf("\nFINDING LCM...\n____________");
    for(i = 0; (i < non && i < 10); i++)
    {
        printf("_________");
    }
    printf("\n");

    while(1)
    {
        l = 0;
        //Does k, a prime number, divide any of the elements of N?
        for(j = 0; j < non; j++)
        {
            if(N[j] % k == 0)
            {
                l = -1;
            }
            else if(l > -1)
            {
                l += N[j];
            }
        }
        if(l == -1)
        {
            printf("\n%d\t:\t", k);
            for(j = 0; j < non; j++)
            {
                if(N[j] % k == 0)
                {
                    printf("%d\t", N[j]);
                    N[j] /= k;
                }
                else
                {
                    printf("%d\t", N[j]);
                }
            }
            printf("\n");
            LCM *= k;
        }
        else if(l > non)
        {
            k = nextPrime(k);
        }
        else
        {
            printf("\n1\t:\t");
            for(j = 0; j < non; j++)
            {
                printf("1\t");
            }
            break;
        }
    }

    printf("\n____________");
    for(i = 0; (i < non && i < 10); i++)
    {
        printf("_________");
    }

    printf("\n\n(Iterations: %d)", i);

    return LCM;
}