#include <stdio.h>
#include "myArrayFunctions.h"
#define LIMIT 100
int charfreq(char *s, char c)
{
    int n = 0;
    for(int i = 0; s[i]; i++)
        if(s[i] == c)
            n++;
    return n;
}
int main()
{
    char s[LIMIT], record[LIMIT];
    record[0] = 0;
    int i, j, max = 0, temp, noc[LIMIT];
    printf("\nYour string: ");
    scanf("%s", s);
    temp = 0;
    for(i = 0; s[i]; i++)
    {
        for(j = 0; record[j]; j++)
            if(s[i] == record[j]) break;
        if(s[i] == record[j]) continue;
        record[temp] = s[i];
        record[temp + 1] = 0;
        noc[temp] = charfreq(s, s[i]);
        if(noc[temp] > max) max = noc[i];
        temp++;
    }
    temp = max;
    printf("\n");
    for(i = 0; i < max; i++)
    {
        for(j = 0; record[j]; j++)
            if(temp - noc[j] < 1) printf("| ");
            else printf("  ");
        temp--;
        printf("\n");
    }
    for(i = 0; record[i]; i++)
        printf("%c ", record[i]);
    printf("\n\n");
}