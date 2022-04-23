#include <stdio.h>

int main()
{
    char c;
    int i = 0;
    printf("\nEnter 1 to find the integer value of a character.");
    printf("\nEnter 2 to find the character for an integer value.");
    printf("\nEnter 3 to exit.\n");
    START:
    if(!(i + 1))
    printf("Invalid option. Re-enter: ");
    if(i + 1)
    printf("\nEnter any option: ");
    fseek(stdin, 0, 0);
    scanf("%d", &i);
    printf("\n");
    switch(i)
    {
        case 1:
        printf("Enter character: ");
        fseek(stdin, 0, 0);
        scanf("%c", &c);
        if(!(c - 10))
        {
            printf("The newline character is represented by the integer %d\n", c);
        }
        else if(!(c - 32))
        {
            printf("The blank space is represented by the integer %d\n", c);
        }
        else if(!c)
        {
            printf("The null character is represented by the integer %d\n", c);
        }
        else
        {
            printf("%c is represented by the integer %d\n", c, c);
        }
        i = 0;
        goto START;

        case 2:
        printf("Enter integer: ");
        scanf("%d", &i);
        c = i;
        if(!(c - 10))
        {
            printf("%d represents the newline character\n", i);
        }
        else if(!(c - 32))
        {
            printf("%d represents the blank space character\n", i);
        }
        else if(!c)
        {
            printf("%d represents the null character\n", i);
        }
        else
        {
            printf("%d represents the character %c\n", i, c);
        }
        i = 0;
        goto START;

        case 3:
        break;

        default:
        i = -1;
        goto START;
    }
    return 0;
}