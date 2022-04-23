 #include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void gotoxy(int x,int y)    
{
    printf("%c[%d;%df",27,y,x);
}
void main()
{
    system("clear");
    /*
    Apparently, you need '\n' after any set of characters you want to print
    before the sleep function. 
    
    If you executed the code below without adding '\n'at the end of each string, 
    the 3 asterisks will be printed after the execution of the sleep function calls.
    */
    gotoxy(1, 0);
    printf("*\n");
    sleep(1);

    gotoxy(2, 0);
    printf("*\n");
    sleep(1);

    gotoxy(3, 0);
    printf("*\n");
    sleep(1);
    system("clear");
}