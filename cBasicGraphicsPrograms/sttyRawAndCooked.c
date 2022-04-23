//"stty" command to set the options for a terminal device interface
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
int main()
{
    system ("/bin/stty raw");
    if(getchar() == 'x')
        printf("\nHaha\n");
    system("/bin/stty cooked");
}
