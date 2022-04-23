#include <stdio.h>
int main()
{
    char S[20], c;
    for(int i = 0; i < 20; i++)
        S[i] = 0;
    int nTemp, nFinal;
    printf("\nOptions:\n1 to check for most frequent character.\n2 to check for frequency of any character.\n3 to exit.\n\n");
    START:
    nTemp = 0;
    while((nTemp - 1) * (nTemp - 2) * (nTemp - 3))
    {
        printf("Your option: ");
        fseek(stdin, 0, 0);
        scanf("%d", &nTemp);
        if((nTemp - 1) * (nTemp - 2) * (nTemp - 3))
            printf("Invalid option.\n");
    }
    if(nTemp - 3)
    {
        printf("\nYour string: ");
        scanf("%s", S);
    }
    switch(nTemp)
    {
        case 1:
        nFinal = 0;
        for(int i = 0; i < 20; i++)
        {
            nTemp = 0;
            if(!S[i])
                break;
            for(int j = 0; j < 20; j++)
            {
                if(!S[j])
                break;
                if(S[i] == S[j])
                nTemp++;  
            }
            if((nTemp) > nFinal)
            {
                nFinal = nTemp;
                c = S[i];
            }
        }
        printf("\n%c is the most frequent character in the string %s, occurring %d times.", c, S, nFinal);
        break;
        
        case 2:
        nFinal = 0;
        printf("Your character: ");
        fseek(stdin, 0, 0);
        scanf("%c", &c);
        for(int i = 0; i < 20; i++)
        {
            if(S[i] == c)
            nFinal++;
        }
        printf("\n%c occurs %d times in %s.", c, nFinal, S);
        break;

        case 3:
        break;

        default:
        printf("Invalid option.\n");
        goto START;
    }
    printf("\n\n");
    return 0;
}