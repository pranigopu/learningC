#include <stdio.h>
#include <stdlib.h>
typedef struct list
{
    int info;
    struct list* link;
} node;

char getnum(int *);
void makelist(node *);
void display(node *);
void searchlist(node *, int);

int main()
{
    do
    {
        int val;
        node *head;

        head = (node*)malloc(sizeof(node));
        makelist(head);
        
        display(head);
        printf("\n");
        
        //Searching for a value
        printf("\nEnter search value: ");
        scanf("%d", &val);
        searchlist(head, val);
        
        //Continue or not?
        fseek(stdin, 0, SEEK_SET);
        printf("\nEnter x to exit... ");
    } while(getchar() != 'x');
}
char getnum(int *p)
{
    char c;
    int n = 0, sign = 1;
    while((c = getchar()) == ' ' || c == '\t');
    if(c == 'x')
        return 'x';
    if(c == '-')
    {
        sign = -1;
        while((c = getchar()) == ' ' || c == '\t');
    }
    if(c >= '0' && c <= '9')
        n = c - '0';
    else
        return 'n';
    while((c = getchar()) >= '0' && c <= '9')
    {
        n = n * 10 + c - '0';
    }
    if(c == ' ' || c == '\t')
        while((c = getchar()) == ' ' || c == '\t');
    if(c == '\n')
    {
        *p = sign * n;
        return 'y';
    }
    else
        return 'n';
    return 0;
}
void makelist(node *head)
{
    int i, val;
    char c;
    node *temp;
    
    i = 1;

    //Create a list
    printf("\n\nEnter x to exit data entry mode... \n\n");
    while(1)
    {
        //Integer input with validation and 'x' check
        while(1)
        {
            printf("Store value %d: ", i);
            fseek(stdin, 0, SEEK_SET);
            c = getnum(&val);
            if(c == 'n')
                printf("\nERROR: Not an integer\n\n");
            else
            {
                i++;
                break;
            }
        }
        if(c != 'x')    
        {
            head -> info = val;
            head -> link = (node*)malloc(sizeof(node));
            temp = head;
            head = head -> link;
        }
        else
        {
            temp -> link = NULL;
            break;
        }
    }
}
void display(node *head)
{
    int i = 1;
    while(head != NULL)
    {
        printf("\nItem %d: %d", i++, head -> info);
        head = head -> link;
    }
}
void searchlist(node *head, int val)
{
    int i = 1;

    while(head != NULL)
    {
        if(head -> info == val)
        {
            printf("\nFound %d in node %d\n", val, i);
            return;
        }
        head = head -> link;
        i++;
    }
    printf("\n%d was not found in the list\n", val);
}