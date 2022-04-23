#include <stdio.h>

int main()
{
    float a, b, c;
    printf("\nTRIANGLE DEFINER\n\n");
    printf("Enter the lengths of three sides of a triangle to know its nature\n\n");
    printf("Side 1: ");
    scanf("%f", &a);
    printf("Side 2: ");
    scanf("%f", &b);
    printf("Side 3: ");
    scanf("%f", &c);

    printf("\n");

    if(a == b && a == c)
    {
        printf("This is an equilateral triangle.\n\n");
        return 0;
    }
    
    if(a > b && a > c)
    {
        a = a + c;
        c = a - c;
        a = a - c;
    }
    else if(b > a && b > c)
    {
        b = b + c;
        c = b - c;
        b = b - c;
    }

    if(c > a + b)
    {
        printf("This is not a valid triangle, as its longest side is smaller than the sum of the shorter sides.\n\n");
        return 0;
    }
    else if(a == b || a == c || b == c)
    {
        printf("This is an isoceles ");
        if(c * c == a * a + b * b)
        {
            printf("and right-angled triangle.\n\n");
        }
        else
        {
            printf("triangle.\n\n");
        }       
    }
    else if(c * c == a * a + b * b)
    {
        printf("This is a scalene right-angled triangle.\n\n");
    }
    else
    {
        printf("This is just a scalene triangle.\n\n");
    }
    
    return 0;
}