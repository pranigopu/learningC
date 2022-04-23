#include <stdio.h>
int setbits(int x, int p, int n, int y)
{
    int x1, y1, exp = 1;
    for(y1 = 0; exp >= x1; y1++)
        exp *= 2;
    x1 = x & ~(~(~(~0 << (y1 - p)) << n) << (p - n));
    /*
    Step-by-step:
    x1 = ~0 << (y1 - p);
    x1 = ~x1 << n;
    x1 = ~x1 << (p - n);
    x1 = ~x1 & x;
    */
    y1 = y << (p - n) & ~(~0 << p);
    return x1 | y1;
}
int invertbits(int x, int p, int n)
{
    int x1, x2, i, exp = 1;
    /*
    Step 1: Isolate the inversion of the target section
    1.1.Isolate the target section
    1.2.Invert isolated result
    1.3.Isolate the n elements off set from position 1 by p - n units
    */
   //1.1
    x1 = ~(~0 << n) << (p - n); //NOTE: x1 is an isolated sequence of n ones off set from position 1 by p - n units
    x2 = x & x1;
    
    //1.2 and 1.3
    x2 = x1 & ~x2;
    /*
    Step 2: Clear the target section in x to insert the inversion
    2.1.Find the magnitude of x
    2.2.Construct a binary sequence x1 such that - 
        a)The positions beyond the magnitude of x are zeroes
        b)The positions corresponding to the target section in x are zeroes
        c)Every other position is a one 
    2.3. Perform binary AND between x1 and x such that the target section in x is filled with zeroes
    */
    //2.1
    for(i = 0; exp >= x1; i++)
        exp *= 2;

    //2.2 and 2.3
    x1 = x & ~(~(~(~0 << (i - p)) << n) << (p - n));

    //Finishing step: Fill the cleared target section in x with the isolated inversion
    return x1 | x2;
}
int bitcount(unsigned int x)
{
    int bit;
    for(bit = 0; x != 0; x &= x - 1, bit++);
    return bit;
}
/*
int main()
{
    int x, y, z;
    x = 0333;
    y = 0271;
    z = setbits(x, 6, 4, y);
    printf("\nz = %o\n\n", z);
    x = 065;
    z = invertbits(x, 5, 4);
    printf("\nz = %o\n\n", z);
    z = bitcount(15u);
    printf("\nz = %d\n\n", z);
}
*/
