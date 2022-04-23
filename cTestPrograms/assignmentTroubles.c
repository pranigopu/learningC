#include <stdio.h>
int main()
{
    int x = 10, y = 15; 
    /*
    TRIAL 1:
    if ( x % 2 = y % 3 )
    printf("\nWoops!\n");

    OUTPUT: 
    z.c:5:16: error: expression is not assignable
    if ( x % 2 = y % 3 )
         ~~~~~ ^
    */
   //____________________________________
   /*
   TRIAL 2:
   if ( 10 % x = y % 3 )
    printf("\nWoops!\n");

    OUTPUT:
    z.c:14:16: error: expression is not assignable
    if ( 10 % x = y % 3 )
         ~~~~~~ ^
    */
   //The error occurs in TRIAL 2 because assignment operator has less priority than any arithmetic operation, including modulus.
}