#include <stdio.h>
int main()
{
  int n, q, i, j;
  float p, r, amt;
  //amt = p(1 + r/100)^nq

  for(i = 0; i < 10; i++)
  {
    printf("\nPrinciple = ");
    scanf("%f", &p);
    printf("Annual rate of interest = ");
    scanf("%f", &r);
    printf("Times compounded per annum = ");
    scanf("%d", &q);
    printf("Years = ");
    scanf("%d", &n);

    amt = p;
    for(j = 0; j < n * q; j++)
    {
      amt *= (1 + r / 100);
    }

    printf("\nAmount = %f", amt);
    printf("\n________________________\n");
  }
  printf("\n\n");
  return 0;
}