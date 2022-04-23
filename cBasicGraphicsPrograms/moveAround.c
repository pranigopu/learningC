#include <stdio.h>
#include <stdlib.h>
void gotoxy(int x, int y)
{
    printf("%c[%d;%df", 27, y, x);
}
int main()
{
    char c;
    int x = 50, y = 17;
    system("clear");
    gotoxy(x, y);
    printf("X");
    system("/bin/stty raw");
    while(1)
    {
        if((c = getchar()) == 27)
        {
            if((c = getchar()) == '[')
            {
                gotoxy(x, y);
                printf(" ");
                if((c = getchar()) == 'A')
                {
                    if(y < 2)
                        continue;
                    else
                        y -= 1;
                }
                else if(c == 'B')
                {
                    if(y > 33)
                        continue;
                    else
                        y += 1;
                }
                else if(c == 'C')
                {
                     if(x > 100)
                         continue;
                     else
                         x += 2;
                }
                else if(c == 'D')
                {
                    if(x < 2)
                        continue;
                    else
                        x -= 2;
                }
            }
            gotoxy(x, y);
            printf("X");
        }
        else
            break;
    }
    system("clear");
    system("/bin/stty cooked");
}

/*
NOTES
Note that output is first passed to a buffer file, then to the screen.
So, if you set your cursor a position and print two items in the same position, the 2nd item will be printed to the right of the 1st. 
*/