#include <stdio.h>
void gotoxy(int x,int y)    
{
    printf("%c[%d;%df",27,y,x);
}
 
int main ()
{
    int x=10, y=50;
    gotoxy(x,y); //move cursor position
    printf("Hello World!!!\n"); //print message
    return 0;
}