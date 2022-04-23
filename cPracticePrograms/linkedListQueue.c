#include <stdio.h>
#include <stdlib.h>
typedef struct list
{
    int info;
    struct list *link;
} queue;
queue *enqueue(queue *);
queue *dequeue(queue *);
void display(queue *);
int main()
{
    queue *head = NULL, *tail = NULL;
    while(1)
    {
        printf("\n1: Enqueue\n2: Dequeue\nx: Exit\n>> ");
        fseek(stdin, 0, SEEK_SET);
        switch(getchar())
        {
            case 'x':
            return 0;

            case '1':
            if(head == NULL)
            {
                head = (queue *)malloc(sizeof(queue));
                head -> link = NULL;
                tail = head;
                printf("\nEnter value: ");
                scanf("%d", &head -> info);
            }
            else
                tail = enqueue(tail);
            break;

            case '2':
            if(head == NULL)
                printf("\nERROR: Queue is empty\n");
            else
                head = dequeue(head);
            break;
        }
        display(head);
    }
}
queue *enqueue(queue *tail)
{
    tail -> link = (queue *)malloc(sizeof(queue));
    if(tail -> link == NULL)
        printf("\nERROR: Could not allocate memory from heap\n");
    else
    {
        tail = tail -> link;
        tail -> link = NULL;
        printf("\nEnter value: ");
        scanf("%d", &tail -> info);
    }
    return tail;

}
queue *dequeue(queue *head)
{
    queue *tmp;
    tmp = head;
    head = head -> link;
    free(tmp);
    return head;  
}
void display(queue *head)
{
    while(head != NULL)
    {
        printf("\n%d", head -> info);
        head = head -> link;
    }
    printf("\n");
}