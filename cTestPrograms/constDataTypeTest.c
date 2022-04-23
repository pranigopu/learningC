#include <stdio.h>
int main()
{
    const int roll = 23;
    printf("\nMy roll number is %d\n", roll);
    /*
    roll = 24;

    constTest.c:6:9: error: cannot assign to variable 'roll' with const-qualified type 'const int'
    roll = 24;
    ~~~ ^
    */
   const int value[3] = {0, 1, 2};
   printf("\n%d, %d, %d\n", value[0], value[1], value[2]);
   const char password[20] = "recursionl00p";
   printf("\nThe password is %s\n\n", password);
}