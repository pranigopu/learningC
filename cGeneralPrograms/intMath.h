#include <stdio.h>

//Table of contents
//PRIME OR NOT
//NEXT PRIME FINDER
//CO-PRIME OR NOT

//HCF FINDER
//LCM FINDER

//PRIME OR NOT
int isPrime(int k)
{
    int i;
    for(i = 2; i * i <= k; i++)
    {
        if(!(k % i))
        {
            return 0;
        }
    }
    return 1;
}

//NEXT PRIME FINDER
int nextPrime(int k)
{
    int i, ans;
    if(k % 2)
    ans = k + 2;
    else
    ans = k + 1;
    do
    {
        for(i = 3; i * i <= ans; i++)
        {
            if(!(ans % i))
            {
                ans += 2;
                i = 0;
                break;
            }
        }
    } while(!i);
    return ans;
}

//CO-PRIME OR NOT
int areCoprime(int N[], int range)
{
    int i, j, k;
    while(1)
    {
        j = 1;
        int min = N[0];
        for(i = 0; i < range; i++)
        {
            if(N[i] < min)
            min = N[i];
        }
        if(k * k > min)
        break;
        for(i = 0; i < range; i++)
        {
            if(N[i] % k)
            j = 0;
        }
        if(j)
        return 0; //Are not co-prime
        else
        k = nextPrime(k);
    }
    return 1; //Are co-prime
}

//HCF FINDER
int hcf(int N[], int non)
{
    int i, j, k;
    int HCF = 1;
    j = 0;
    k = 2;
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
            j += N[i] % k;
        }
        /*
        If k does divide all the elements of N: 
        1.  Modify HCF
        2.  Reduce all elements of N by k
        3.  Check 3.1. If false, check 3.2.
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
            HCF *= k;
            for(i = 0; i < non; i++)
            {
                N[i] /= k;
                if(N[i] == 1)
                j = 1;
            }
            if(j)
            break;
        }
        else
        {
            k = nextPrime(k);
        }
    }
    return HCF;
}

//LCM FINDER
long unsigned int lcm(int N[], int non)
{
    int i, j, k, l;
    long unsigned int LCM = 1;
    k = 2;
    while(1)
    {
        l = 0;
        //Does k, a prime number, divide any of the elements of N?
        for(j = 0; j < non; j++)
        {
            if(N[j] % k == 0)
            {
                l = -1;
                N[j] /= k;
            }
            else if(l > -1)
            {
                l += N[j];
            }
        }
        if(l == -1)
        {
            LCM *= k;
        }
        else if(l > non)
        {
            k = nextPrime(k);
        }
        else
        {
            break;
        }
    }
    return LCM;
}