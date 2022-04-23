#include <stdio.h>
int main()
{
    char c;
    char s[10];
    char t[10];
    int op;
    float n;
    printf("\nSTUDY ON STDIN\n\n");
    printf("1 for seeing how the stdin pointer position changes with getchar in a loop and goto\n");
    printf("2 for seeing how the stdin pointer position changes with scanf in a loop and goto\n");
    printf("3 for seeing how stdin stores integer and float values\n");
    printf("4 for seeing how stdin deals with formatted and unformatted inputs\n\n");
    printf("5 for seeing how putchar interacts with stdin\n\n");
    printf("Option ");
    scanf("%d", &op);
    switch(op)
    {
        case 1:
        op = 0;
        printf("\n\nIn a goto loop:");
        CASE6:
        c = getchar();
        putchar(c);
        //getchar() retrieves data from the stdin file
        if(op < 5)
        {
            op++;
            printf("\ncount = %d\n", op);
            goto CASE6;
        }
        printf("\n\nNow in a for loop:");
        for(op = 0; op < 5; op++)
        {
            c = getchar();
            putchar(c);
            printf("count = %d\n", op);
        }
        break;
        case 2:
        op = 0;
        printf("\n\nIn a goto loop:\n");
        CASE7:
        scanf("%c", &c);
        putchar(c);
        //getchar() retrieves data from the stdin file
        if(op < 5)
        {
            op++;
            printf("\ncount = %d\n", op);
            goto CASE7;
        }
        printf("\n\nNow in a for loop:\n");
        for(op = 0; op < 5; op++)
        {
            scanf("%c", &c);
            putchar(c);
            printf("\ncount = %d\n", op + 1);
        }
        break;
        case 3:
        printf("\nInteger input: ");
        scanf("%d", &op);
        fgets(s, 10, stdin);
        printf("\n%s\n", s);
        fseek(stdin, 0, 0);
        printf("\nFloating point input: ");
        scanf("%f", &n);
        fgets(s, 10, stdin);
        printf("\n%s\n", s);
        break;
        case 4:
        printf("\n\nscanf for string\n");
        scanf("%s", s);
        fgets(t, 10, stdin);
        puts(t);
        printf("\n\ngets for string\n");
        gets(s);
        fgets(t, 10, stdin);
        printf("\n%s\n", t);
        printf("\n\nscanf for character\n");
        fseek(stdin, 0, 0);
        scanf("%c", &c);
        fgetc(stdin);
        printf("\n%s\n", t);
        printf("\n\ngetchar for character\n");
        fseek(stdin, 0, 0);
        getchar();
        printf("\n%s\n", fgetc(stdin));
        break;
    }  
    printf("\n");
    return 0;
}