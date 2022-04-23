//LINEAR SEARCH
//20-08-19
#include <stdio.h>
#include <stdlib.h>
#define xx 20
int main()
{
    int searchVal = 0, searchSize = 0, i = 0;
    char c = 0;
    int N[xx];
    while(1)
    {
        system("clear");
        printf("\nLINEAR SEARCH\n");
        printf("\nHow many numbers to enter? ");
        while(searchSize < 1 || searchSize > xx)
        {
            scanf("%d", &searchSize);
            if(searchSize < 1 || searchSize > xx)
            printf("\nInput out of bounds.\n\nEnter an integer from 1 to %d: ", xx);
        }

        for(i = 0; i < searchSize; i++)
        {
            printf("\nElement %d: ", i + 1);
            scanf("%d", &N[i]);
        }
        printf("\n%d elements have been entered into the array.", searchSize);
        printf("\n________________________________________________\n");
        printf("\nEnter value to search: ");
        scanf("%d", &searchVal);

        for(i =  0; i < searchSize; i++)
        {
            if(N[i] == searchVal)
            {
                c = 1;
                break;
            }
        }
        if(i + 1 == searchSize && c == 0)
        {
            printf("\n%d has not been found in the array.", searchVal);
        }
        else
        {
            printf("\n%d has been found in the position %d in the array.", searchVal, i + 1);
        }
        printf("\n________________________________________________\n");
        
        printf("\nEnter c to continue: ");
        fseek(stdin, 0, 0);
        scanf("%c", &c);
        if(c != 'c')
        break;
    }
    printf("________________________________________________\n");
    printf("\nProgram terminated\n\n");
    return 0;
}