#include <stdio.h>
#define MAXVARS

//External variables
float val[30];
int val_index = 0;
char buffer;

//getch: takes input from the buffer if the buffer is not empty, or the user, if it is
char getch(void)
{
	char tempc;
	if(buffer == '\0')
		return getchar();
	tempc = buffer;
	buffer = '\0';
	return tempc;
}

//ungetch: adds extra input characters to the buffer to be retrieved later
void ungetch(char c)
{
		buffer = c;
}

//push: adds a number to the stack named 'val'
void push(float n)
{
	val[val_index++] = n;
}

//pop: removes the most recent element from the stack named 'val'
int pop(void)
{
	return val[--val_index];
}

//getnum: allows the input of numbers, with type validation and accomodation for spaces and tabs
char getnum(void)
{
	char c;
	float n;
	float fpf = 10; //fpf for 'floating point factor'
	short sign;
	while((c = getch()) == ' ' || c == '\t');
	if(c == '-')
	{
		c = getch();
		sign = -1;
	}
	else
		sign  = 1;	
	if(c < '0' || c > '9')
		return c;
	n = c - '0';
	while((c = getch()) >= '0' && c <= '9')
		n = n * 10 + c - '0';
	if(c == '.')
		while((c = getch()) >= '0' && c <= '9')
		{	
			n = n + (c - '0') / fpf;
			fpf *= 10;
		}
	push(n * sign);
	ungetch(c);
	return '\0';
}
//------------------------------------------------------------
int main()
{
	printf("\nBASIC CALCULATOR\nEnter '_' to exit\n\n");
	char c;
	do
	{
		printf("\n");
		val_index = 0;
		buffer = '\0';

		char op = '\t';
		int i = 0;
		float temp;

		while(1)
		{
			//Number / variable input
			c = getnum();
			if(c == '\0')							
				switch(op)
				{
					case '+':
						push(pop() + pop());
						break;
						
					case '-':
						push(-pop() + pop());
						break;
					
					case '*':
						push(pop() * pop());
						break;

					case '/':
						temp = pop();
						push(pop() / temp);
						break;
						
					case '\t':
						break;

					default:
						printf("\nError: unrecognised operators.\n");
						c = '-';
				}
			else if(c == '\n')
			{
				printf("= %d\n", pop());
				break;
			}
			else if(c != '_')
			{
				printf("\nError: a number was expected.\n");
				break;
			}
			if(c == '_' || c == '-')
				break;

			//Operator input
			while((op = getch()) == ' ' || op == '\t');
			if(op == '\n')
				ungetch(op);
		}
		printf("");
		//printf("\nEnter x to exit...");
		//fseek(stdin, 0, 0);
	} while(c != '_');
	printf("\n");
	return 0;
}