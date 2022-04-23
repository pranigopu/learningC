#include <stdio.h>
#include <stdlib.h>
int main()
{
    char c;
    while(1)
    {
        system("/bin/stty raw");
        if((c = getchar()) == 27)
        {
            if(getchar() == '[')
            {    
                if((c = getchar()) == 'D')
                    printf("\nleft\n\b\b\b\b\b");
                else if(c == 'C')
                    printf("\nright\n\b\b\b\b\b");
                else if(c == 'A')
                    printf("\nup\n\b\b\b\b\b");
                else if(c == 'B')
                    printf("\ndown\n\b\b\b\b\b");
            }
        }
        else
            break;
    }
    system("/bin/stty cooked");
}
