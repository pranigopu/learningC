#include <stdio.h>
#include <stdlib.h>
typedef struct list
{
    int info;
    struct list *link;
} node;
void display(node *ptr)
{
    int i = 1;
    printf("\n");
    while(ptr != NULL)
    {
        printf("Node %d: %d\n", i++, ptr -> info);
        ptr = ptr -> link;
    }
}
int main()
{
    node *head = NULL;
    node *tmp;
    int n = 1;
    do
    {
        printf("1: Create list\nx: exit\n>> ");
        fseek(stdin, 0, SEEK_SET);
        switch(getchar())
        {
            case '1':
            printf("Double enter to continue adding... \n");
            do
            {
                printf("Enter node %d: ", n);
                if(head == NULL)
                {
                    head = (node *)malloc(sizeof(node));
                    head -> link = NULL;
                    tmp = head;
                }
                else
                {
                    tmp -> link = (node *)malloc(sizeof(node));
                    tmp = tmp -> link;
                    tmp -> link = NULL;
                }
                scanf("%d", &tmp -> info);
                n++;
                printf("\nYour list so far: ");
                printf("\n------------");
                display(head);
                printf("------------\n");
                fseek(stdin, 0, SEEK_SET);
            } while(getchar() == '\n');
            break;

            case 'x':
            return 0;
        }
    } while(1);
}