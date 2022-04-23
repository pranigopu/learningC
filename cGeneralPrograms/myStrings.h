#include <stdio.h>

//Table Of Contents
//STRING COMPARISON
//STRING LENGTH CHECK
//STRING CONCATENATE
//INDEX OF RIGHTMOST OCCURRENCE OF CHARACTER PATTERN\\

//----------------------------------------------
//STRING COMPARISON
int compare(char A[], char B[], int n)
{
    int check = 0;
    for(int i = 0; i < n; i++)
    {
        check = A[i] - B[i];
        if(check != 0)
        break;
    }
    return check;
}
//----------------------------------------------
//STRING LENGTH CHECK
int length(char A[])
{
    int i = 0;
    while(A[i])
    {
        i++;
    }
    return i - 1;
}
//----------------------------------------------
//STRING CONCATENATE
int concat(char A[], int arraySize_A, char B[])
{
    int i = 0, j = 0;
    i = length(A);
    while(B[j] || i < arraySize_A)
    {
        A[i] = B[j];
        j++;
        i++;
    }
    return 0;
}

//INDEX OF RIGHTMOST OCCURRENCE OF CHARACTER PATTERN
int rightoccurindex(char *s, char *t)
{
    int i = 0;
    int j = 0;
    while(s[i])
        i++;
    while(t[j])
        j++;
    while(j && i--)
        if(s[i] == t[j - 1])
            j--;
    if(j == 0)
        return i;
    else    
        return -1;  
}