#include <stdio.h>
#define MAX 10
/*
NOTES
A queue is a first in first out system.
Need indices for the first and last positions of the array
*/
int enqueue(int *, int);
int dequeue(int *, int);
void display(int *, int, int);
int main()
{
    int head = -1, tail = -1;
    int Q[MAX];
    while(1)
    {
        printf("\n1: Enqueue\n2: Dequeue\nx: Exit\n>> ");
        fseek(stdin, 0, SEEK_SET);
        switch(getchar())
        {
            case 'x':
            return 0;

            case '1':
            if(tail == MAX - 1)
            {
                printf("\nERROR: Queue is full\n");
                printf("\nEmpty queue?(y/n): ");
                fseek(stdin, 0, SEEK_SET);
                if(getchar() == 'y')
                {
                    head = -1;
                    tail = -1;
                    printf("\nEmptied\n\n");
                }
            }
            else
            {
                if(head == -1)
                    ++head;
                tail = enqueue(Q, tail);
            }
            break;

            case '2':
            if(tail < head)
            {
                printf("\nERROR: Queue is empty\n");
                head = -1;
                tail = -1;
            }
            else
                head = dequeue(Q, head);
            break;   
        }
        display(Q, head, tail);
    }
}
int enqueue(int *Q, int tail)
{
    printf("\nEnter value: ");
    scanf("%d", &Q[tail + 1]);
    return tail + 1;
}
int dequeue(int *Q, int head)
{
    return head + 1;
}
void display(int *Q, int head, int tail)
{
    if(head != -1)
    {
        for(head = head; head <= tail; ++head)
            printf("\n%d", Q[head]);
        printf("\n");
    }
}