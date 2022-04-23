#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LAST 10

int pos[LAST + 1][2];

void gotoxy(int, int);
void leftshift(void);
int arrowin(int*, int*);

int main()
{
    int i = 0, x = 2, y = 1;
    char body[LAST + 1];
    char c;

    for(i = 0; i < LAST + 1; ++i)
    {
        pos[i][0] = x;
        pos[i][1] = y;
    }
    body[0] = ' ';
    for(i = 1; i < LAST; ++i)
    {
        body[i] = 'o';
    }
    body[LAST] = 'o';

    system("/bin/stty raw");
    system("clear");

    while(1)
    {
        if(arrowin(&x, &y) == 0)
            break;
        leftshift();
        pos[LAST][0] = x;
        pos[LAST][1] = y;
        ++i;
        for(i = 0; i < LAST + 1; ++i)
        {
            gotoxy(pos[i][0], pos[i][1]);
            printf("%c", body[i]);
        }
    }
    system("/bin/stty cooked");
    system("clear");
}

//FUNCTION DEFINITIONS

void gotoxy(int x,int y)    
{
    printf("%c[%d;%df",27,y,x);
}

void leftshift()
{
    int i;
        for(i = 0; i < LAST; ++i)
        {
            pos[i][0] = pos[i + 1][0];
            pos[i][1] = pos[i + 1][1];
        }
}

int arrowin(int *x, int *y)
{
    char c;
    if((c = getchar()) == 27)
    {
        if(getchar() == '[')
        {    
            if((c = getchar()) == 'D')
            {
                if(*x > 2)
                    *x -= 2;
            }
            else if(c == 'C')
            {
                if(*x < 100)
                    *x += 2;
            }
            else if(c == 'A')
            {
                if(*y > 2)
                    *y -= 1;
            }
            else if(c == 'B')
            {
                if(*y < 34)
                    *y += 1;
            }
        }
    }
    else
        return 0;
    return 1;
}