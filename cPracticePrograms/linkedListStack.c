#include <stdio.h>
#include <stdlib.h>
typedef struct list
{
    int info;
    struct list *link;
} stack;
int push(stack **top);
int pop(stack **top);
void display(stack *top);
int main()
{
    stack *top = NULL;
    while(1)
    {
        printf("\n1: Push\n2: Pop\nx: Exit\n>> ");
        fseek(stdin, 0, SEEK_SET);
        switch(getchar()) 
        {
            case 'x':
            return 0;

            case '1':
            do
            {
                if(push(&top))
                    break;
                display(top);
                fseek(stdin, 0, SEEK_SET);
            } while(getchar() != 'x');
            break;

            case '2':
            do
            {
                if(pop(&top))
                    break;
                display(top);
                fseek(stdin, 0, SEEK_SET);
            } while(getchar() != 'x');
            break;

            default:
            display(top);
        }
    }
}
int push(stack **top)
{
    stack *tmp;
    tmp = *top;
    *top = (stack *)malloc(sizeof(stack));
    if(*top == NULL)
    {
        printf("ERROR: Stack overflow\n");
        return 1;
    }
    (*top) -> link = tmp;
    printf("\nPush value: ");
    scanf("%d", &(*top) -> info);
    return 0;
}
int pop(stack **top)
{
    if(*top == NULL)
    {
        printf("ERROR: Stack underflow\n");
        return 1;
    }
    stack *tmp;
    tmp = *top;
    printf("\nPopped value: %d\n", (*top) -> info);
    *top = (*top) -> link;
    free(tmp);
    return 0;
}
void display(stack *top)
{
    printf("\nStack: ");
    while(top != NULL)
    {
        printf("\n%d", top -> info);
        top = top -> link;
    }
    printf("\n");
}