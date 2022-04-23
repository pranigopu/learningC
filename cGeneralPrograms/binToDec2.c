#include <stdio.h>
#include <stdlib.h>
typedef struct list
{
    char ch;
    struct list *next;
    struct list *prev;
} node;

node *head = NULL, *tail = NULL;
int dec;

void append(char);
void clearlist();
void display();

void decToBin()
{
    while(dec > 0)
    {
        if((dec & 1) == 0)
            append('0');
        else
            append('1');
        dec = dec >> 1;
    }
}
void binToDec()
{
    node *temp;
    temp = head -> next;
    while(temp != NULL)
    {
        dec *= 2;
        if(temp -> ch == '1')
            ++dec;
        temp = temp -> next;
    }
}
int main()
{
    char c;
    head = (node*)malloc(sizeof(node));
    while(1)
    {
        dec = 0;
        tail = head;
        head -> next = NULL;
        head -> prev = NULL;
        printf("\n1: Bin to dec\n2: Dec to bin\nx: Exit\n>> ");
        fseek(stdin, 0, SEEK_SET);
        switch(getchar())
        {
            case '1':
            while(1)
            {           
                printf("\nEnter binary integer: ");
                fseek(stdin, 0, SEEK_SET);
                while((c = getchar()) == '0' || c == '1')
                    append(c);
                if(c == 'x')
                    break;
                else if(c != '\n')
                    printf("\nERROR: Not recognisably binary\n");
                else   
                {
                    binToDec();
                    printf("\nConversion: %d\n", dec);
                    break;
                }
            }
            break;

            case '2':
            printf("\nEnter decimal integer: ");
            while(1)
            {
                fseek(stdin, 0, SEEK_SET);
                while((c = getchar()) >= '0' && c <= '9')
                    dec = dec * 10 + c - '0';
                if(c == 'x')
                    break;
                else if(c != '\n')
                    printf("\nERROR: Not recognisably decimal\n");
                else   
                {
                    decToBin();
                    display();
                    break;
                }
            }
            break;

            case 'x':
            goto OUT;

            default:
            printf("\nERROR: Invalid option\n\n");
        }
    }
    OUT:
    return 0;
}
void append(char c)
{
    tail -> next = (node*)malloc(sizeof(node));
    tail -> next -> prev = tail;
    tail -> next -> next = NULL;
    tail -> next -> ch = c;
    tail = tail -> next;
}
void clearlist()
{
    node *ptr = head;
    head = head -> next;
    free(ptr);
    if(head -> next != NULL)
        clearlist();
}
void display()
{
    node *ptr = tail;
    printf("\nConversion: ");
    while(ptr -> prev != NULL)
    {
        printf("%c", ptr -> ch);
        ptr = ptr -> prev;
    }
    printf("\n");
}