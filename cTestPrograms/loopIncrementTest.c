#include <stdio.h>
int main()
{
    char s[5] = "abcd";
    int temp = 0;
    while(s[temp++]) printf("\n(Inside loop) temp = %d\n", temp);
     printf("\n(Out of loop) temp = %d\n", temp);
}