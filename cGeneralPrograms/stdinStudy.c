#include <stdio.h>
int main()
{
    char c;
    char s[30];
    char t[30];
    int op;
    float n;
    FILE *iof;
    printf("\nSTUDY ON STDIN\n\n");
    printf("0 for seeing whether getchar and gets take data from stdin\n");
    printf("1 for seeing how data is retrieved from the beginning of stdin\n");
    printf("2 for seeing how data is retrieved from the current position of stdin after each character input\n");
    printf("3 for seeing the file pointer's position after each character input\n");
    printf("4 for seeing how changing the pointer position affects the input process\n");
    printf("5 for seeing the file pointer taken until a newline character\n");
    printf("6 for inputting values and opening the stdin file in read mode\n\n");

    printf("Option ");
    scanf("%d", &op);
    switch(op)
    {
        case 0:
        printf("\nFor getchar:\n");
        fseek(stdin, 0, 0);
        putchar(getchar());
        printf("\n\nFor gets:\n");
        gets(s);
        fgets(t, 10, stdin);
        puts(t);
        break;
        case 1:
        for(int i = 0; i < 3; i++)
        {  
            char s[10];
            /* 
            I found out that taking the file pointer to the beginning of stdin makes the system take an input.
            This is the redundant code:

            fseek(stdin, 0, 1);
            printf("\n%d is the pointer's position in the file\n", fseek(stdin, 0, 0));
            scanf("%c", &c);
            
            */
            fseek(stdin, 0, 0);
            printf("\nNow %d is the pointer's position in the file\n", fseek(stdin, 0, 0));
            fgets(s, 10, stdin);
            puts(s);
        } 
        break;
        case 2:
        for(int i = 0; i < 3; i++)
        {   
            scanf("%c", &c);
            fgets(s, 10, stdin);
            puts(s);
        } 
        break;
        case 3:
        for(int i = 0; i < 3; i++)
        { 
            fseek(stdin, 0, 1);
            printf("\n%d is the pointer's current position in the file\n", fseek(stdin, 0, 1));
            scanf("%c", &c);
        } 
        break;
        case 4:
        scanf("%s", s);
        fseek(stdin, -1, 1);
        printf("%c\n", getchar());
        break;
        case 5:
        scanf("%c", &c);
        do
        {
            c = getchar();
            putchar(c);
            //getchar() retrieves data from the stdin file
        }
        while(c != 10 && c != -1);
        printf("(ends here)\n");
        printf("As you can see, the last character retrieved was a newline\n");
        break;
        case 6:
        printf("\nInput stuff\n");
        fseek(stdin, 0, 0);
        gets(s);
        fclose(stdin);
        iof = fopen("_stdinp", "a");
        fseek(iof, 0, 0);
        scanf("%s", s);
        fprintf(stdin, "%s", s);
        fclose(iof);
        iof = fopen("_stdinp", "r");
        fgets(s, 30, iof);
        printf("\n%s\n", s);
        fclose(iof);
        fopen("_stdinp", "w");
        fclose(iof);
        fgets(s, 30, stdin);
        printf("\n%s\n", s);
        break;
    }  
    printf("\n");
    return 0;
}