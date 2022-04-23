#include <stdio.h>
#define LIMIT 50
int main()
{
    char c, s[100];
    int wordCount = 0, i = 0, j, max = 0, temp;
    int wordLength[LIMIT];
    printf("\nEnter your line...\n");
    while(1)
    {
        scanf("%s", s);
        for(wordLength[i] = 0; s[wordLength[i]]; wordLength[i]++);
        if(wordLength[i] > max) max = wordLength[i];
        wordCount++;
        if((c = getchar()) == ' ' || c == '\t') 
            i++;
        else if(c == '\n') 
            break;
    }
    printf("\nWord count: %d\n", wordCount);
    printf("\nWord length histogram is given below...\n(Any special characters attached to a word are included in the length)\n\n");
    temp = max;
    for(i = 0; i < max + 1 && temp > 0; i++)
    {
        for(j = 0; j < wordCount; j++)
            if(temp - wordLength[j] < 1) 
                printf("|");
            else 
                printf(" ");
        printf("\n");
        temp--;
    }
    /*
    EXTRA:
    printf("\n");
    for(i = 0; i < wordCount; i++)
        printf("%d\t", i + 1);
    */
    printf("\n\n");
}