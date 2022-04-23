//MY OWN MATH FUNCTIONS

#include <stdio.h>
//Table of contents
//ABSOLUTE VALUE FUNCTION
//SIMPLE ARITHMETIC USING OPERATIONAL SYMBOLS
//FACTORIAL FUNCTION
//POWER FUNCTION
//ROOT FUNCTION

//ABSOLUTE VALUE FUNCTION
float absolute(float n)
{
    if(n < 0)
    n *= -1;
    return n;
}

//SIMPLE ARITHMETIC USING OPERATIONAL SYMBOLS
float arith(char op, int a, int b)
{
    float ans;
    switch(op)
    {
        case '+':
        ans = a + b;
        break;
        case '-':
        ans = a - b;
        break;
        case '*':
        ans = a * b;
        break;
        case '/':
        ans = a / b;
        break;
        default:
        ans = 0;
    }
    return ans;
}

//FACTORIAL FUNCTION
long int factorial(unsigned int n)
{
    long int fac = 1;
    for(int i = 1; i < n + 1; i++)
    {
        fac *= i;
    }
    return fac;
}

//POWER FUNCTION
float power(float n, int m)
{
    float p = 1;
    for(int i = 0; i < m; i++)
    {
        p *= n;
    }
    return p;
}

// ROOT FUNCTION
float root(float n, int p)
{
    float max, min, last, i;

    if(power(n / p, p) > n)
    {
        max = n / p;
        min = max / 2;
        last = 0;
        while(power(min, p) <= n - 0.000001 || power(min, p) >= n + 0.000001)
        {
            if((int)(min * 1000000) == (int)(max * 1000000))
            break;
            /*
            NOTE ON THE ABOVE TWO LINES OF CODE
            Note that the loop condition is false when the root being calculated has achieved the specified degree of accuracy.
            I have specified the condition such that maximum 6 and minimum 5 decimal digits are accurate.

            Now, float values take maximum 6 decimal digits.
            However, sometimes, the roots being calculated may never achieve the false condition and escape the loop.
            
            For example, cube root of 81 gave an answer correct to 5 decimal digits, 
            4.326749, with the last 9 being rounded up.
            However, 4.326749^3 = 81.0000162353, which does not fall into the condition's false range,
            i.e. the value does not reache the range 80.999999 to 81.000001.

            Hoever, as float values can hold only 6 decimal digits, the answer never gets more accurate.
            This leads to an infinite loop, as the loop condition is always true, which means the right range is never avhieved.
            This also happened for 4th root of 729.
            
            To prevent this, I have included the code above this comment.
            It ensures that 
            (1) if the float value has reached the limit of its accuracy, and
            (2) if the loop condition is still not false,
                then the loop will break and NOT go on indefinitely.
            */

            if(power(min, p) > n)
            {
                max = min;
                min = (last + min) / 2;
            }
            else if(power(min, p) < n)
            {
                last = min;
                min = (max + min) / 2;
                
            }
            else 
            {
                break;
            }         
        }
        return min;
    }
    else if(power(n / p, p) < n)
    {
        min = n / p;
        max = n;
        last = n;
        while(power(max, p) <= n - 0.000001 || power(max, p) >= n + 0.000001)
        {
            if((int)(min * 1000000) == (int)(max * 1000000)) //See the note in the last loop
            break;
            if(power(max, p) > n)
            {
                last = max;
                max = (max + min) / 2; 
            }
            else if(power(max, p) < n)
            {
                min = max;
                max = (max + last) / 2;
            }
            else 
            {
                return max;
            }    
        }
        return max;
    }
    else
    {
        min = n / p;
        return min;    
    }
}