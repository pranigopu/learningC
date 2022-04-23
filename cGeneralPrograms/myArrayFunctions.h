#include <stdio.h>

//Table of contents
//LINEAR SEARCH
//BINARY SEARCH
//SELECTION SORT
//FREE AN ARRAY INDEX
//PRINT INTEGER ARRAY

//LINEAR SEARCH
int linSearch(int N[], int searchSize, int searchVal)
{
    int i;
    for(i =  0; i < searchSize; i++)
    {
        if(N[i] == searchVal) 
        return i;
    }
    return -1;
}

/*
int binSearch1(int N[], int searchSize, int searchVal)
{
    int min, mid, max;
    min = 0;
    mid = 1;
    max = searchSize - 1;
    while(mid != min)
    {
        mid = (min + max) / 2;
        if(searchVal < N[mid])
            max = mid - 1;
        else
            min = mid;
    }
    if(N[mid] == searchVal)
        return min;
    return -1;
}
*/

int binSearch(int N[], int searchSize, int searchVal)
{
    int min, mid, max;
    min = 0;
    max = searchSize - 1;
    while(min < max + 1)
    {
        mid = (min + max) / 2;
        if(searchVal < N[mid])
            max = mid - 1;
        else if(searchVal > N[mid])
            min = mid + 1;
        else 
            return mid;
    }
    return -1;
}

//SELECTION SORT
void selectSort(int A[] /* int *p */, int arraySize, int ascending1_descending0)
{
    int m;
    int i, j;
    for(i = 0; i < arraySize; i++)
    {
        m = i;
        for(j = i; j < arraySize; j++)
        {
            //if((option)? (*(p + j) < *(p + m)) : (*(p + j) > *(p + m)))
            if((ascending1_descending0)? (A[j] < A[m]) : (A[i] > A[m]))
            m = j; 
        }
        /*
        j = *(p + m);
        *(p + m) = *(p + i);
        *(p + i) = j;
        */
       j = A[m];
       A[m] = A[i];
       A[i] = j;
    }
}

//FREE AN ARRAY INDEX
int freeArrayIndex(int A[], int arraySize, int index)
{
    int k, temp;
    for(k = 0; k < arraySize; k++)
    {
        if(A[k] == 0)
        {
            temp = A[index];
            A[index] = 0;
            A[k] = temp;
            return 1;
        }
    }
    return 0;
}

//PRINT INTEGER ARRAY
void arrayPrint(double A[], int arraySize, int option)
{
    int i;
    printf("\n");
    for(i = 0; i < arraySize; i++)
    { 
        printf("%f", A[i]);
        (option)? printf("\n") : printf("\t");
    }
    printf("\n");
}

//ASSIGN INTEGER ARRAY
void arrayAssign(int A[], int arraySize, int B[])
{
    int i;
    for(i = 0; i < arraySize; i++)
    {
        A[i] = B[i];
    }
}

//SET INTEGER ARRAY TO SOME VALUE
void arraySet(int A[],  int arraySize, int x)
{
    int i;
    for(i = 0; i < arraySize; i++)
    {
        A[i] = x;
    }
}

//SET INTEGER ARRAY TO SOME VALUE
void stringSet(char A[],  int arraySize, int x)
{
    int i;
    for(i = 0; i < arraySize; i++)
    {
        A[i] = x;
    }
}