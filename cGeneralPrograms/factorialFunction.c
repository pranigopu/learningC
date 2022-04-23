#include <stdio.h>

int factorial(int n) // Declaration and definition of a function to find a number's factorial
{
  int count = 1, fac = 1; // 'n' has been initialised as the function's input parameter
  do// Ensures that input of 0 outputs as 1, because 0! = 1
  {
    fac = fac * count;
    count = count + 1;
   } while(count <= n);
  return fac;
}

int main()
{
  int n, fac;
  printf("Enter a number to get its factorial \n");
  scanf("%d", &n); // "%d" indicates the compiler to read the following integer value, and the '&n' syntax specifies memory address of 'n' 
  fac = factorial(n); // Calling the factorial function
  printf("The factorial is %d \n", fac);
  return 0; // Signals the termination of the 'main' function. '0' is not mandatory, any integer would do
}


/* Declaration and definition of a function can be done directly or separately. To do it separately, here is the syntax.

Declaration syntax: 
int factorial(int); //Note the semicolon used in the declaration

Definition syntax: 
int factorial(int n)
{
  ...statements...
}
*/

/*
Note that it is not necessary to create a separate factorial function.
The code can be directly implemented in the main function.
I just wanted to try out declaring my own function and calling it.
 */