// Testing format conversion of characters to integers and vice versa, characters to float and vice versa, and integer to float and vice versa
#include <stdio.h>

int main()
{
  printf("\nCHARACTERS AND INTEGERS\n");
  char c;
  printf("\nEnter a character: ");
  scanf("%c", &c);
  printf("%c is %d and %c is %d\n", c, c, c + 1, c + 1);
  /*
  When a digit was entered in character format:  

  Enter a character: 4
  4 is 52 and 5 is 53 

  */

  int i;
  printf("\n\nEnter an integer: ");
  scanf("%d", &i);
  printf("%d is %c and %d is %c\n", i, i, i + 1, i + 1);

  printf("\nEXPONENTIAL NOTATION\n");
  printf("\n%e\n\n", 0.0003);
}

// OTHER RESULTS

/*
1.  Trying conversion from character to float datatype:
  
      scanf(%c", &c);
      printf("%d);

    Complilation result:

      formatConversionTest.c:11:27: warning: format specifies type 'double' but the argument has type 'char' [-Wformat]
        printf("%c is %f\n", c, c);
                  ~~        ^
 
2.  Trying conversion from float to integer datatype:
  
      scanf(%f", &f);
      printf("%d\n", f);

    Complilation result:

      formatConversionTest.c:23:16: warning: format specifies type 'int' but the argument has type 'float' [-Wformat]
        printf("%d\n", f);
                  ~~   ^

3.  Trying conversion from integer to float:

        printf("%f\n", i);

    Compilation result:

      formatConversionTest.c:21:16: warning: format specifies type 'double' but the argument has type 'int' [-Wformat]
        printf("%f", i);
                ~~   ^
 */

// CONCLUSION: Only character and integer datatypes are compatible to each other