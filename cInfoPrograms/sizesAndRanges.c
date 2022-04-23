// PROGRAM TO PRINT THE SIZE OF THE RANGES OF DIFFERENT DATATYPES AND THE FULL RANGES OF THE SAME

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
  printf("\nPROGRAM TO PRINT THE SIZE OF THE RANGES OF DIFFERENT DATATYPES AND THE FULL RANGES OF THE SAME\n");
  // For character based datatypes

  printf("\n________________________________________________________________________\nCHARACTER BASED DATATYPES\n");
  printf("sizeof(char) = %lu\n", sizeof(char));
  printf("range of (char) is from %d to %d\n", CHAR_MIN, CHAR_MAX);
  //printf("range of (unsigned char) is from %lu to %lu\n", UCHAR_MIN, UCHAR_MAX);

  // For integer based datatypes

  printf("\n________________________________________________________________________\nINTEGER BASED DATATYPES\n");
  printf("\nsizeof(int) = %lu\n", sizeof(int));
  printf("range of (int) is from %d to %d\n", INT_MIN, INT_MAX);

  printf("\nsizeof(short) = %lu\n", sizeof(short));

  printf("\nsizeof(long int) = %lu\n", sizeof(long int));

  printf("\nsizeof(unsigned int) = %lu\n", sizeof(unsigned int));
  //printf("range of (unsigned int) is from 0 to %lu\n", UINT_MAX);

  // For float and double
  
  printf("\n________________________________________________________________________\nFLOAT AND DOUBLE\n");

  printf("\nsizeof(double) = %lu\n", sizeof(double));
  printf("\n<TEST>");
  printf("\nWhen using format specifier 'e' to print range, we get\n");
  printf("range of (double) is from %e to %e\n", DBL_MIN, DBL_MAX);
  printf("\nWhen using format specifier f to print range, we get\n");
  printf("range of (double) is from %f to %f\n", DBL_MIN, DBL_MAX);

  printf("<END OF TEST>\n\nsizeof(long double) = %lu\n", sizeof(long double));
  //printf("Range of (long double) is from %e to %e\n", LBL_MIN, LBL_MAX);

  printf("\nsizeof(float) = %lu\n", sizeof(float));
  printf("\n<TEST>");
  printf("\nWhen using format specifier e to print range, we get\n");
  printf("range of (float) is from %e to %e\n", FLT_MIN, FLT_MAX);
  printf("\nWhen using format specifier f to print range, we get\n");
  printf("range of (double) is from %f to %f\n<END OF TEST>\n\n", FLT_MIN, FLT_MAX);

  return 0;
}