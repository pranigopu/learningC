#include <stdio.h>
#include <stdlib.h>
int main()
{
    int x = 0, y = 0, i;
    char c = 0;
    while((c  = getchar()) != 'x')
    {
        switch(c)
        {
            case 'w':
            if(y > 0)
                y--;
            break;
            
            case 's':
            y++;
            break;

            case 'a':
            if(x > 0)
                x--;
            break;

            case 'd':
            x++;
            break;

            case 'x':
            return 0;
        }
        system("clear");
        for(i = 0; i < y; i++)
            printf("\n");
        for(i = 0; i < x; i++)
            printf(" ");
        printf("^ ^\n");
        for(i = 0; i < x; i++)
            printf(" ");
        printf(" o\n");
        fseek(stdin, 0, 0);
    }
}