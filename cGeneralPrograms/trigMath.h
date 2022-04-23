#include <stdio.h>

//Table of contents
//SINE FUNCTION 
//COSINE FUNCTION

//Global variables
double pi = 355 / 113;

//SINE FUNCTION
float sine(float x)
{
    int i = 0;
    float sinx;
    
    if(x < 0)
    x = 2 * pi + x;

    while(x > (pi/ 2))
    {
        if(x > pi)
        {
            x -= pi;
            i++;
        }
        else if(x > pi/ 2)
        {
            x = pi - x;
        }
    }

    for(i = 1; i < 20; i++)
    {
        if(i % 2 == 1)
        {
            sinx += power(x, 2*i - 1) / factorial(2*i - 1);
        }
        else
        {
            sinx -= power(x, 2*i - 1) / factorial(2*i - 1);
        }  
    }
    return sinx;
}

//COSINE FUNCTION
float cosine(float x)
{
    int i = 0;
    float cosx;
    
    if(x < 0)
    x = 2 * pi + x;

    while(x > (pi/ 2))
    {
        if(x > pi)
        {
            x -= pi;
        }
        else if(x > pi/ 2)
        {
            x = pi - x;
        }
        i++;
    }

    for(i = 0; i < 20; i++)
    {
        if(i % 2 == 0)
        {
            cosx += power(x, 2*i) / factorial(2*i);
        }
        else
        {
            cosx -= power(x, 2*i) / factorial(2*i);
        }  
    }
    return cosx;
}