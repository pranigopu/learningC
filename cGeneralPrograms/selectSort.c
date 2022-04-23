#include <stdio.h>
#define MAX 10
void selectSort(int *A, int last, int option)
{
    int i, j, temp;
    if(last == 0)
    {
        printf("Nothing to sort\n");
        return;
    }
    if(option == 2)
        for(i = 0; i < last; i++)
        {
            temp = i;
            for(j = i; j < last; j++)
                if(A[j] < A[temp])
                    temp = j;
            j = A[i];
            A[i] = A[temp];
            A[temp] = j;
        }
    else if(option == 3)
        for(i = 0; i < last; i++)
        {
            temp = i;
            for(j = i; j < last; j++)
                if(A[j] > A[temp])
                    temp = j;
            j = A[i];
            A[i] = A[temp];
            A[temp] = j;
        }
    printf("Sorted\n");
}
int main()
{
    int A[MAX];
    int i, last = 0;
    do
    {
        printf("\nEnter 0 to exit");
        printf("\nEnter 1 to enter elements");
        printf("\nEnter 2 to sort in ascending order");
        printf("\nEnter 3 to sort in descending order");
        printf("\nEnter 4 to view to array");
        printf("\n");
        scanf("%d", &i);
        printf("\n");
        switch(i)
        {
            case 0:
                break;
            case 1:
                do
                {
                    printf("Enter a number between 1 and %d", MAX + 1);
                    printf("\nHow many elements to input? ");
                    scanf("%d", &last);
                } while(last > MAX || last < 2);
                printf("Input elements\n");
                for(i = 0; i < last; i++)
                {
                    printf("Element %d: ", i + 1);
                    scanf("%d", &A[i]);
                }
                break;
            case 2: 
            case 3:
                selectSort(A, last, i);
                break;
            case 4:
                for(i = 0; i < last; i++)
                    printf("%d\n", A[i]);
                i = 4;
                break;
            default:
                printf("\nNot an option");
        }
    } while(i != 0);
}