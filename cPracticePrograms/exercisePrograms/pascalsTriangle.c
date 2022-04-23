#include <stdio.h>
int main()
{
  int i, j;
  int pw11 = 1, temp = 1;
  for(i = 1; i < 6; i++)
  {
    for(j = 5 - i; j > 0; j--)
    printf("   ");

    while(temp > 0)
    {
      printf("%d     ", temp % 10);
      temp /= 10;
    }

    pw11 *= 11;
    temp = pw11;
    printf("\n");
  }
  return 0;
}