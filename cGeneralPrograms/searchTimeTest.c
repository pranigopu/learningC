#include <stdio.h>
#include <time.h>
#include "myArrayFunctions.h"
clock_t start, stop;
int n, N[20] = {6, 2, 8, 10, 23, 363, 24, 76, 33, 100, 1000, 54, 67, 87, 98, 22, 11, 13, 54, 700};
void f1(int n)
{
    start = clock();
    binSearch(N, 20, n);
    stop = clock();
    printf("\nExecution time: %f s\n", (double)(stop - start) / CLOCKS_PER_SEC);
}
void f2(int n)
{
    start = clock();
    binSearch(N, 20, n);
    stop = clock();
    printf("\nExecution time: %f s\n", (double)(stop - start) / CLOCKS_PER_SEC);
}
int main()
{
    void f1(int);
    void f2(int);
    f1(-2);
    f2(-2);
    return 0;
}