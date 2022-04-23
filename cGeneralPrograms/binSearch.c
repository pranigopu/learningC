#include <stdio.h>
#define MAX 10
int N[MAX];
int max = 0;
int main()
{
    void sort(int*, int);
    int i, ub, lb, n;
    do
    {
        //Array input
        while(1)
        {
            printf("\nHow many elements to enter? ");
            scanf("%d", &max);
            if(max < 2 || max > MAX)
                printf("Enter a number between %d and %d", 1, MAX + 1);
            else
                break;
        }

        for(i = 0; i < max; i++)
        {
            printf("Element %d: ", i + 1);
            scanf("%d", &N[i]);
        }

        ub = max - 1;
        lb = 0;

        printf("\nEnter a value to search: ");
        scanf("%d", &n);
        
        //Sorting
        sort(N, max);
        printf("\nThe array has been sorted...\n");
        for(i = 0; i < max; i++)
        {
            printf("Element %d: %d\n", i + 1, N[i]);
        }
        
        printf("\n");

        //Finding the value
        while(lb <= ub)
        {
            i = (lb + ub) / 2;
            if(N[i] < n)
                lb = i + 1;
            else if(N[i] > n)
                ub = i - 1;
            else
            {
                printf("%d found at position %d\n", n, i + 1);
                goto NEXT;
            }
        }
        printf("\n%d has not been found\n", n);
        NEXT:
        printf("\n");
        fseek(stdin, 0, SEEK_SET);
        printf("\nEnter x to exit: ");
    } while(getchar() != 'x');
}
void sort(int* N, int max)
{
    int i, j, key;
    for(i = 1; i < max; i++)
    {
        key = N[i];
        j = i - 1;
        while(N[j] > key && j > -1)
        {
            N[j + 1] = N[j];
            j--;
        }
        N[j + 1] = key;
    }
}