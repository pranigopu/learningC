#include <stdio.h>

int main()
{
  int n = 5;
  int m = 10;
  char s[n];
  char t[n];
  char *p;
  printf("\n\nThere are two arrays, s[%d] and t[%d]\n", n, n);
  printf("\n1. Unformatted string input test on s[%d]\n\nEnter something: ", n);
  gets(s); 
  printf("printf blank space display test: %s\n", s); // To see if formatted print will display even out-of-bounds characters by inputting more than 5 characters and seeing if they get outputted
  printf("printf retrieving 3rd character test: %c\nputchar retrieving 3rd character test: ", s[2]); // To see if unformatted input of strings will still allow me to retrieve particular characters trhough formatted output
  putchar(s[2]); // Testing unformatted character output
  printf("\n\n2. Formatted string input test on t[%d]\n\nEnter something: ", n);
  scanf("%s", t);
  printf("printf out-of-bounds display test: %s\nputs out-of-bounds display test: ", t); // To see if formatted scan and print will display even out-of-bounds characters by inputting more than 5 characters and seeing if they get outputted
  puts(t); 
  printf("\n\n3. Evidence of consecutive storage in arrays\nBelow are listed the memory addresses of the first %d elements of s[%d]\n\n", m, n);
  for(int i = 0; i < m; i++) // To see the evidence of consecutive storage in arrays, and to see if p = &s[i] for i > 5 will run or not
  {
    p = &s[i];
    printf("%p \n", p);
  }
  printf("\nTest terminated\n\n");
  return 0;
}
