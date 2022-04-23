#include <stdio.h>
#include <stdlib.h>
typedef struct list
{
    int info;
    struct list *link;
} node;
int count = 0;
node *insert(node *, int);
node *delete(node *, int);
void display(node *);
int main()
{
    node *head = NULL;
    int pos;
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
                if(head == NULL)
                    head = insert(head, 1);
                else
                    insert(head, count + 1);
                display(head);
                fseek(stdin, 0, SEEK_SET);
            } while(getchar() != 'x');
            break;

            case '1':
            display(head);
            do
            {
                printf("\nEnter position: ");
                scanf("%d", &pos);
                if(pos < 1 || pos > count + 1)
                    printf("\nERROR: Positions only available from %d to %d\n", 1, count + 1);
                else if(pos == 1)
                    head = insert(head, pos);
                else
                    insert(head, pos);
                display(head);
                fseek(stdin, 0, SEEK_SET);
            } while(getchar() != 'x');
            break;

            case '2':
            if(count == 0)
            {
                printf("\nERROR: Deletion not possible on empty list\n");
                break;
            }
            display(head);
            do
            {
                printf("\nEnter position: ");
                scanf("%d", &pos);
                if(pos < 1 || pos > count + 1)
                    printf("\nERROR: Positions only available from %d to %d\n", 1, count);
                else if(pos == 1)
                    head = delete(head, pos);
                else
                    delete(head, pos);
                display(head);
                fseek(stdin, 0, SEEK_SET);
            } while(getchar() != 'x');
            break;

            default:
            printf("\nERROR: Invalid option\n");
        }
    }
}
node *insert(node *ptr, int pos)
{
    node *tmp;
    int i;
    ++count;
    if(pos == 1)
    {  
        tmp = ptr;
        ptr = (node *)malloc(sizeof(node));
        ptr -> link = tmp;
        printf("\nEnter value: ");
        scanf("%d", &ptr -> info);
        return ptr; //Returns new head value so the head at the main function can update
    }
    else
    {
        for(i = 0; i < pos - 2; ++i) //Traversing until preceding position
            ptr = ptr -> link;
        /*
        NOTE:
        When traversing the list to insert at a position, note that in the first iteration, you are at the second node,
        assuming you started at the head pointer. Hence, at the nth iteration, you will have reached the (n + 1)th node.
        In this algorithm, to insert a node at position n, we must traverse until the (n - 1)th position. But if you perform
        (n - 1) iterations, we have seen that you will reach the nth position. But you will reach the (n - 1)th position if
        you do (n - 2) iterations.

        IN SUMMARY: 
        To insert at position n, we must reach position (n - 1), for which we need (n - 2) iterations.
        */
        tmp = ptr -> link; //tmp now stores the address of the node at the position the new node must be inserted in
        ptr -> link = (node *)malloc(sizeof(node)); //The new node's address is assigned to the link of the preceding node
        ptr = ptr -> link; //ptr now points to the newly created node
        ptr -> link = tmp; //The new node's link now points to the node which previously occupied its sequential position
        printf("\nEnter value: ");
        scanf("%d", &ptr -> info);
    }
    return NULL;
}
node *delete(node *ptr, int pos)
{
    node *tmp;
    int i;
    if(pos == 1)
    {
        tmp = ptr -> link;
        free(ptr);
        return tmp;
    }
    else
    {
        for(i = 0; i < pos - 2; ++i)
            ptr = ptr -> link;
        tmp = ptr -> link;
        ptr -> link = tmp-> link;
        free(tmp);
    }
    return NULL;
}
void display(node *ptr)
{
    int i = 1;
    if(ptr == NULL)
        return;
    else
    {
        printf("\nYour list... ");
        while(ptr != NULL)
        {
            printf("\nNode %d: %d", i++, ptr -> info);
            ptr = ptr -> link;
        }
        printf("\n");
    }
}