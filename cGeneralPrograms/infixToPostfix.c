#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct _stack
{
    char element;
    struct _stack *link;
} stack;
//Stack top
stack *top = NULL;
//Postfix expression
char P[MAX];
int push(char c)
{
    stack *tmp = top;
    top = (stack *)malloc(sizeof(stack));
    if(top == NULL) //Stack overflow
        return 1;
    top -> element = c;
    top -> link = tmp;
    return 0;
}
char pop()
{
    char c;
    if(top == NULL) //Stack underflow
        return '\0';
    stack *tmp = top;
    c = top -> element;
    top = top -> link;
    free(tmp);
    return c;
}
int precedence(char c)
{
    switch(c)
    {
        case '+': case '-': 
        return 1;

        case '*': case '/':
        return 2;

        case '^':
        return 3;
    }
    return 0;
}
void display(char *P)
{
    int i;
    printf("\nEquivalent postfix expression:\n");
    for(i = 0; P[i] != ')'; i++)
        printf("%c  ", P[i]);
    printf("\n\n");
}
int main()
{
    /*
    1.
    Read expression from left to right.
    */
    int n, i = 0, openBrackets = 0;
    char c;
    push('(');
    printf("\nEnter infix expression:\n");
    fseek(stdin, 0, SEEK_SET);
    while(top != NULL && i < MAX - 2)
    {   
        while((c = getchar()) == ' ' || c == '\t');
        /*
        2.
        If operator encountered, as long as the previous character is not an operator, push operator to stack
        */
        if((n = precedence(c)) > 0)
        {
            if(precedence(top -> element) >= n)
            {
                printf("Consequent operators, hence an invalid infix expression.\n\n");
                return 0;
            }
            push(c);
        }
        /*
        3.
        If ')' encountered, then pop repeatedly and add to P until '(' encountered
        */
        else if(c == ')' || c == '\n')
        {
            openBrackets--;
            while((c = pop()) != '(')
                P[i++] = c;
        }
        /*
        4.
        If '(' encountered, push to stack
        */
        else if(c == '(')
        {
            openBrackets++;
            push('(');
        }
        /*
        5.
        If operand encountered, add to P
        */
        else
            P[i++] = c;
    }
    if(openBrackets != -1)
        printf("Unterminated brackets, hence an invalid expression.\n\n");
    else
    {
        P[i] = ')';
        display(P);
    }
    return 0;
}