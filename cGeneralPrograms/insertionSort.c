#include <stdio.h>
#define MAX 10
//option must be 1 for ascending, -1 for descending
void insertSort(int *A, int n, int option)
{
    int i, j, key;
    for(i = 1; i < n; i++)
    {
        key = A[i];
        j = i - 1;
        while(option * A[j] > option * key && j > -1)
        {
            A[j + 1] = A[j];
            j--;     
        }
        A[j + 1] = key;
    }
    printf("\nSorted\n\n");
}
int main()
{
    int i, n = 0;
    int A[MAX];
    while(1)
    {
        printf("------------------------------------\n");
        printf("Enter 1 to input into array\n");
        printf("Enter 2 to sort the array in ascending order\n");
        printf("Enter 3 to sort the array in descending order\n");
        printf("Enter 4 to view the array\n");
        printf("Enter -1 to exit\n");
        scanf("%d", &i);
        if((i == 2 || i == 3 || i == 4) && n == 0)
        {
            printf("\nNothing to sort or show\n\n");
            continue;
        }
        switch(i)
        {
            case 1:
                printf("\nHow many elements to enter? ");
                while(1)
                {
                    scanf("%d", &n);
                    if(n < 2 || n > MAX)
                        printf("You must enter a number between 1 and %d\n", MAX + 1);
                    else break;
                }
                printf("\n");
                for(i = 0; i < n; i++)
                {
                    printf("Element %d: ", i + 1);
                    scanf("%d", &A[i]);
                }
                printf("\n");
                break;
            case 2:
                insertSort(A, n, 1);
                break;
            case 3:
                insertSort(A, n, -1);
                break;
            case 4:
                printf("\n");
                for(i = 0; i < n; i++)
                {
                    printf("Element %d = %d\n", i + 1, A[i]);
                }
                printf("\n");
                break;
            case -1:
                printf("\nProgram ended\n\n");
                return 0;
            default:
                printf("\nInvalid option\n\n");
        }
    }
}