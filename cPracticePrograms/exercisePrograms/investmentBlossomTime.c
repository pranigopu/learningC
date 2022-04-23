#include <stdio.h>
int main()
{
  float machineEarn = 0, investEarn = 6000;
  int i = 1;
  while(++i)
  {
    investEarn *= 28 / 25;
    machineEarn = 1000 * i - 4000;
    if((machineEarn - investEarn) > 0)
    break;
  }
  printf("\n%d years is the minimum life the machine must have to be a more attractive investment than other investments.\n\n", i);
  return 0;
}