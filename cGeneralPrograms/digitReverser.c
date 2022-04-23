//DIGIT REVERSAL

#include <stdio.h>

int main()
{
  int n, temp, rev = 0, rem, zeroes = 0;
  printf("\nDIGIT REVERSER\n");
  printf("\nEnter a number: ");
  scanf("%d", &n); 

  temp = n;
  while(temp != 0)
  {
    rem = temp % 10;
    if(rem == 0)
    {
      zeroes++;
    }
    else
    {
      break;
    }
    temp /= 10;
  }

  temp = n;
  while(temp != 0)
  {
    rem = temp % 10;
    rev = (rev * 10) + rem;
    temp /= 10;
  }

  printf("\nReverse of digits: ");
  for(int i = 0; i < zeroes; i++)
  {
    printf("0");
  }
  printf("%d\n\n", rev);
  if(rev == n)
  {
    printf("Palindrome? Yes\n\n");
  }
  else
  {
    printf("Palindrome? No\n\n");
  }
  return 0;
}