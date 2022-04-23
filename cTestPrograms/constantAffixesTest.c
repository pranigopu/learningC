#include <stdio.h>
int main()
{
    /*
    printf("\n%d\n", 10000000000);

    Warning generated:
    constantSuffixesTest.c:4:22: warning: format specifies type 'int' but the argument has type 'long' [-Wformat]
    printf("\n%d\n", 10000000000);
              ~~     ^~~~~~~~~~~
              %ld
    Also,10000000000 is automatically taken as a long integer in this compliler.
    ------------------------------------------------
    Similarly,
    printf("\n%d\n", 3.1);

    Warning generated:
    constantSuffixesTest.c:14:21: warning: format specifies type 'int' but the argument has type 'double' [-Wformat]
    printf("\n%d\n", 3.1);
              ~~     ^~~
              %f
    */
   printf("\nUNSIGNED INTEGER SUFFIX TEST\n");
   printf("\n%u\n", -1u);
   printf("\n%u\n", 1u);

   printf("\nAUTOMATIC DOUBLE VALUE STORAGE REVEAL\n");
   printf("\n%0.32f\n", 3.13f);
   printf("\n%0.32f\n", 3.13);
   /*
   3.13 was automatically stored as double. 
   If I store it as float, you can see the difference in the precision of the outputs. 
   */

  printf("\nOCTAL PREFIX TEST\n");
  int temp = 037;
  printf("\n%o\n", temp);
  printf("\n%d\n", temp);

  printf("\nHEXADECIMAL PREFIX TEST\n");
  temp = 0x10;
  printf("\n%x\n", temp);
  printf("\n%d\n", temp);
  temp = 0xf;
  printf("\n%x\n", temp);
  printf("\n%d\n", temp);
  printf("\n");
  //Note: In the hexadecimal numbers, uppercase and lowercase letters mean the same.
}