// Arrays and pointers
// This program inputs and outputs your name and also outputs the memory address of the first character

#include <stdio.h>

int main()
{
  char name[50]; // String declaration
  char *pointer; // Pointer declaration
  printf("\nEnter your name please: ");
  scanf("%s", name); 

  /* 
  Note that a string is a type of array, and variables in arrays, unlike variables, are assigned memory addresses at the time of declaration. 
  Hence, 'scanf' doesn't require & operator for arrays and hence for strings.
  */

  printf("Hello there, %s!\n\n", name);
  pointer = &name[0]; 

  /* 
  SIDE NOTE
  Assigning 'pointer = &name;' leads to the following error:
  ---------------------------------------------------------------------------------------------------
  incompatible pointer types assigning to 'char *' from 'char (*)[50]' [-Wincompatible-pointer-types]
  pointer = &name;
          ^ ~~~~~
  ---------------------------------------------------------------------------------------------------
  The name of the array 'name' is itself a pointer, hence address of this pointer would not be the address of a character.
  Hence, the data types between 'pointer' and '&name' are incompatible.
  */
  
  printf("Both of the following outputs show the memory address of the first character in your name, which is %c.\n", name[0]);
  printf("%p\n", pointer);
  printf("%p\n\n", &name[0]); // This line of code is merely to demonstrate that '&var', where var is a variable, is also a pointer and needs the same format specifier
  return 0;
}
