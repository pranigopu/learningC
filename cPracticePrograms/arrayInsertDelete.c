#include <stdio.h>
#define MAX 20
int insert(int *, int, int);
int delete(int *, int, int);
void display(int *, int);
int main()
{
    int A[MAX];
    int free = 0, pos;
    while(1)
    {
        printf("\n------------------------");
        printf("\n0: Append\n1: Insert\n2: Delete\nx: Exit\n>> ");
        fseek(stdin, 0, SEEK_SET);
        switch(getchar())
        {
            case 'x':
            return 0;

            case '0':
            do
            {
                if(free >= MAX)
                {
                    printf("\nERROR: Cannot append to full array\n");
                    break;
                }
                printf("\nEnter value: ");
                scanf("%d", &A[free++]);
                display(A, free);
                fseek(stdin, 0, SEEK_SET);
            } while(getchar() != 'x');
            break;
            
            case '1':
            display(A, free);
            do
            {
                if(free >= MAX)
                {
                    printf("\nERROR: Cannot insert into full array\n");
                    break;
                }
                printf("\nEnter position: ");
                scanf("%d", &pos);
                if(pos < 1 || pos > free + 1)
                {
                    printf("\nERROR: Positions to insert available from %d to %d\n", 1, free + 1);
                    continue;
                }
                free = insert(A, free, pos - 1);
                display(A, free);
                fseek(stdin, 0, SEEK_SET);
            } while(getchar() != 'x');
            break;

            case '2':
            display(A, free);
            do
            {
                if(free <= 0)
                {
                    printf("\nERROR: Cannot delete from empty array\n");
                    break;
                }
                printf("\nEnter position: ");
                scanf("%d", &pos);
                if(pos < 1 || pos > free)
                {
                    printf("\nERROR: Positions to delete available from %d to %d\n", 1, free);
                    continue;
                }
                free = delete(A, free, pos - 1);
                display(A, free);
                fseek(stdin, 0, SEEK_SET);
            } while(getchar() != 'x');
            break;

            default:
            display(A, free);
        }
    }
}
int insert(int *A, int free, int pos)
{
    int i;
    for(i = free; i > pos; --i)
        A[i] = A[i - 1];
    printf("\nEnter value: ");
    scanf("%d", &A[i]);
    return free + 1;
}
int delete(int *A, int free, int pos)
{
    int i;
    for(i = pos; i < free - 1; ++i)
        A[i] = A[i + 1];
    return free - 1;
}
void display(int *A, int free)
{
    int i;
    if(free <= 0)
        printf("\n<EMPTY ARRAY>\n");
    else
    {
        printf("\nYour array... ");
        printf("\n---*---*---\n");
        for(i = 0; i < free; ++i)
            printf("\nElement %d: %d", i + 1, A[i]);
        printf("\n\n---*---*---\n");
    }
}