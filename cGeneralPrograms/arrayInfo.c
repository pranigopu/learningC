#include <stdio.h>
int main()
{
    int N[10];
    int i, max;
    static int counts[4];
    do
    {
        printf("\nHow many numbers do you want to input? ");
        scanf("%d", &max);
        printf("\nEnter into the array... \n");
        for(i = 0; i < max; i++)
        {
            printf("Value %d: ", i + 1);
            scanf("%d", &N[i]);
            if(N[i] % 2 == 0)
                counts[0]++;
            else
                counts[1]++;
            if(N[i] > 0)
                counts[2]++;
            else if(N[i] < 0)
                counts[3]++;
        }
        printf("\n\nEven numbers: %d", counts[0]);
        printf("\nOdd numbers: %d", counts[1]);
        printf("\nPositive numbers: %d", counts[2]);
        printf("\nNegative numbers: %d", counts[3]);
        
        int top = 0;
        printf("\n\nHere is a graph representing these counts:\n(Order is even, odd, positive, negative)\n\n");
        for(i = 0; i < 4; i++)
        {
            if(counts[i] > top)
                top = counts[i];
        }
        
        while(top > 0)
        {
            for(i = 0; i < 4; i++)
            {
                if(top <= counts[i])
                    printf("|");
                else
                    printf(" ");
            }
            top--;
            printf("\n");
        }
        printf("\nEnter x to exit, enter anything else to repeat... ");
        fseek(stdin, 0, 0);
    } while(getchar() != 'x');
    return 0;
}