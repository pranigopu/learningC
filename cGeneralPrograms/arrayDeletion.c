#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int A[MAX];
int free_index = 0, error;
void delete(int pos)
{
	int i;
	for(i = pos; i < free_index - 1; i++)
		A[i] = A[i + 1];
	--free_index;
}
void errormsg(int n)
{
	error = n;
	switch(n)
	{
		case -1:
		printf("\nArray is empty. Only insertion is possible.\n");
		break;

		case 1:
		printf("\nERROR: Invalid number. Enter from 1 to %d only. Input cancelled.\n", MAX);
		break;

		case 10:
		printf("\nERROR: Invalid number. Enter from 0 to %d only. Input cancelled.\n", MAX - 1);
		break;

		case 2:
		printf("\nERROR: No value exists in the position. Deletion cancelled.\n");
		break;

		case 3:
		printf("\nERROR: The position does not contain the given value. Deletion cancelled.\n");
		break;

		case 4:
		printf("\nInvalid option\n");
		break;
	}
}
int main()
{
	int P[MAX];
	int val, i, j;
	printf("\nDELETION\n");
	do
	{
		error = 0;
		printf("\nChoose option:\n");
		printf("0 to exit.\n");
		printf("1 to insert values into array.\n");
		printf("2 to delete by position.\n");
		printf("3 to delete by value.\n");
		printf("4 to view array.\n");
		printf("5 to clear screen.\n");
		scanf("%d", &j);
		if(free_index == 0 && (j == 2 || j == 3))
			errormsg(-1);
		else
			switch(j)
			{
				case 0:
				errormsg(-2);
				break;

				case 1:
				errormsg(-3);
				printf("\nHow many values to enter? ");
				scanf("%d", &j);
				if(j < 1 || j > MAX)
					errormsg(1);
				else
				{
					for(i = 0; i < j; i++)
					{
						printf("A[%d] = ", i);
						scanf("%d", &A[i]);
					}
					free_index = j;
				}
					break;
				
				case 2:
				printf("\nEnter position: ");
				scanf("%d", &i);
				ONEPOS:
				if(i < 0 || i > MAX - 1)
					errormsg(10);
				else if(i >= free_index)
					errormsg(2);
				else
					delete(i);
				break;

				case 3:
				printf("\nDelete value: ");
				scanf("%d", &val);
				for(j = 0; j < free_index; j++)
					P[j] = -1;
				j = 0;
				for(i = 0; i < free_index; i++)
					if(A[i]	== val)
					{
						P[j] = i;
						++j;
					}
				if(P[1] > -1)
				{
					printf("\nValue found at positions\n");
					j = 0;
					while(P[j] != -1 && P[j - 1] != -1)
					{
						printf("%d\n", P[j]);
						++j;
					}
					printf("\nEnter\n-1 to delete at all positions\nPosition number to delete at a particular position\n");
					scanf("%d", &i);
					if(i == -1)
					{
						j = 0;
						while(P[j] != -1)
						{
							delete(P[j]);
							++j;
							if(P[j] != -1)
								--P[j];
						}
					}
					else
					{
						j = 0;
						while(P[j] != -1)
						{
							if(P[j] == i)
							{
								delete(P[j]);
								break;
							}
							else
								j++;
						}
						if(j == -1)
						{
							errormsg(3);
						}
					}
				}
				else 
				{
					j = 2;
					i = P[0];
					goto ONEPOS;
				}
				break;

				case 4:
				error = -1;
				if(free_index == 0)
					printf("\nThe array is empty\n");
				else
					for(i = 0; i < free_index; i++)
						printf("A[%d] = %d\n", i, A[i]);
				break;
				
				case 5:
				errormsg(-3);
				system("clear");
				printf("\nDELETION");
				break;

				default:
				errormsg(4);
			}
		if(error == 0)
			printf("Deletion successful.\n");
	} while(error != -2);
}
