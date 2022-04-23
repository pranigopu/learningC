#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "myArrayFunctions.h"
#define STACKMAX 50
#define OPMAX 50
#define VARMAX 10

//EXTERNAL VARIABLES
double v[STACKMAX];
int vi = 0;
char varName[VARMAX];
double varVal[VARMAX];
int vari = 0;

//FUNCTION PROTOTYPES
void push(double);
double pop(void);
int isNumber(char);
int isVar(char);
char extras(char, char*);

/*
Here is an example of postfix:
2 3 + 4 5 - * translates to (2 + 3) * (4 - 5)

Such a calculation needs the following steps to perform:
1. If number, push into stack and move to next index 
2. If operator, pop sufficient number of values from stack, and push result

NOTE: Spaces or tabs serve to differentiate numbers.
*/

int main()
{
    int i, j;
    char c = 0, s[OPMAX];
    double result;
    while(1)
    {
        for(i = 0; isNumber(c = getchar()) && i < OPMAX; i++) s[i] = c;
        if(i)
        {
            s[i] = '\0';
            push(atof(s));
            continue;
        }
        else if((i = isVar(c)) > -1) 
        {
            push(varVal[i]);
            continue;
        }
        switch(c)
        {
            case '+':
                push(pop() + pop());
                break;
            case '-':
                push(- pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '/':
                push(1 / pop() * pop());
                break;
            case '%':
                i = (int)pop();
                push((int)pop() % i);
                break; 
            case ' ': case '\t': case '\n':
                break;
            case 'x':
                return 0;
            default:
                c = extras(c, s);
        }
        if(c == '\n')
        {
            result = pop();
            printf("= %f\n", result);;
            printf("------------\n");
        }
        else if(c == '\0') 
        {
            fseek(stdin, 0, SEEK_SET);
            printf("------------\n");
        }
    }
    return 0;
}

void push(double x)
{
    if(vi < STACKMAX)
        v[vi++] = x; //Assign value, then increment index
    else
        printf("\nError: stack full, cannot push values.\n");
}
double pop(void)
{
    if(vi > 0)
        return v[--vi]; //Decrement index, then return value
    return 0;
}

int isNumber(char c)
{
    if((c >= '0' && c <= '9') || c == '.')
        return 1;
    else 
        return 0;
}

int isVar(char c)
{
    int i;
    for(i = 0; i < vari; i++)
        if(varName[i] == c)
            return i;
    return -1;
}

char extras(char c, char *s)
{
    int compare(char*, char*), i;
    double temp;
    for(i = 0, s[i++] = c; (c = getchar()) != ' ' && c != '\t' && c != '\n' && i < OPMAX + 1; i++)
        s[i] = c;
    s[i] = '\0';
    fseek(stdin, 0, SEEK_SET);
    if(compare(s, "sin") == 0)
    {
        push(sin(pop()));
        return '\n';
    }
    else if(compare(s, "cos") == 0)
    {
        push(cos(pop()));
        return '\n';
    }
    else if(compare(s, "pow") == 0)
    {
        temp = pop();
        push(pow(pop(), temp));
        return '\n';
    }
    else if(compare(s, "stacktop") == 0)
    {
        printf("Item on top of the stack: %f\n", v[vi]);
        printf("------------\n");
        return '\0';
    }
    else if(compare(s, "topcopy") == 0)
    {
        temp = pop();     
        push(temp);
        printf("\n%f\n", v[vi - 1]);
        return '\0';
    }
    else if(compare(s, "viewstack") == 0)
    {
        for(i = 0; i < vi; i++)
            printf("%f\n", v[i]);
        return '\0';
    }
    else if(compare(s, "variables") == 0)
    {
        for(i = 0; i < vari; i++)
            printf("%c: %f\n", varName[i], varVal[i]);
        return '\0';
    }
    else if(compare(s, "remove") == 0)
    {
        if(vari == 0)
        {
            printf("No variable has been created yet.\n");
            return '\0';
        }
        printf("You are about to delete a variable.\n");
        printf("Enter the variable to delete: ");
        while((s[0] = getchar()) == '\t' || s[0] == ' ');
        if(s[0] == '\n')
            printf("No variable chosen.\n");
        else
        {
            for(i = 0; i < vari; i++)
            {
                if(varName[i] == s[0])
                {
                    varName[i] = varName[vari - 1];
                    varVal[i] = varVal[vari - 1];
                    vari--;
                }
            }
        };
        return '\0';
    }
    else //New user-defined variables
    {
        if(vari >= VARMAX)
        {
            printf("Cannot store more new variables.\n");
            return '\0';

        }
        printf("Enter y to create new variable '%c': ", s[0]);
        if(getchar() != 'y')
        {
            fseek(stdin, 0, SEEK_SET);
            return '\0';
        }
        fseek(stdin, 0, SEEK_SET);
        varName[vari] = s[0];
        varVal[vari] = 0; //Default value
        int i = 0;
        printf("Assign a value to '%c': ", s[0]);
        while((s[0] = getchar()) == ' ' || s[0] == '\t');
        if(s[0] == '\n')
        {
            printf("Variable is unassigned, and defaults to zero\n");
            vari++;
            return '\0';
        }
        else
        {
            for(i = 1; isNumber(s[i] = getchar()) && i < OPMAX; i++);
            s[i] = '\0'; 
            varVal[vari] = atof(s);
            vari++;
            return '\0';
        }
    }
    return '\0';
}
int compare(char *s1, char *s2)
{
    int check = 0;
    for(int i = 0; s1[i] != '\0' || s2[i] != '\0'; i++)
    {
        check = s1[i] - s2[i];
        if(check != 0)
            break;
    }
    return check;
}