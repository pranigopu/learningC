//Looking at the 'not' operator, relational operators and 'if-else', stripped to the minimum
#include <stdio.h>
int main()
{
    int a, b;
    printf("\nFinding !a");
    printf("\nEnter a: ");
    scanf("%d", &a);
    printf("!a = %d\n", !a);

    printf("\nFinding a > b");
    printf("\nEnter a: ");
    scanf("%d", &a);
    printf("Enter b: ");
    scanf("%d", &b);
    printf("(a > b) = %d\n", a > b);

    printf("\nChecking if(a)");
    printf("\nEnter a: ");
    scanf("%d", &a);
    if(a)
    {
        printf("a is not 0\n\n");
    }
    else
    {
        printf("a is 0\n\n");
    }
    
    return 0;
}