#include <stdio.h>
int main()
{
  int option, n, i;
  float s = 0;
  i = 1;
  printf("\nEnter 1 to add series 1 + 4 + 7 - 10... (1st n terms)");
  printf("\nEnter 2 to add series 1/2 + 2/3 + 3/4 + 4/5... + n/(n+1)");
  printf("\nEnter 3 to add series 1 + 4 + 9 + 16... n^2");
  printf("\nEnter 4 to addseries 1/2 - 2/3 + 3/4 - 4/5... +- n/(n+1)\n\n");
  scanf("%d", &option);
  switch(option)
  {
    case 1:
    printf("\nn = ");
    scanf("%d", &n);
    while(i < n + 1)
    {
      s += 3;
      i++;
    }
    printf("\n%f\n\n", s);
    break;
    case 2:
    printf("\nn = ");
    scanf("%d", &n);
    while(i < n + 1)
    {
      s += (float)i / (i + 1);
      i++;
    }
    printf("\n%f\n\n", s);
    break;
    case 3:
    printf("\nn = ");
    scanf("%d", &n);
    while(i < n + 1)
    {
      s += i*i;;
      i++;
    }
    printf("\n%f\n\n", s);
    break;
    case 4:
    printf("\nn = ");
    scanf("%d", &n);
    while(i < n + 1)
    {
      if(i % 2 != 0)
      {
        s += (float)i / (i + 1);
      }
      else
      {
        s -= (float)i / (i + 1);
      }
      i++;
    }
    printf("\n%f\n\n", s);
    break;
    default:
    printf("\nNot an option\n\n");
  }  
  return 0;
}