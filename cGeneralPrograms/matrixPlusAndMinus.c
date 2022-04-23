#include <stdio.h>
#include <stdlib.h>
#define max 20
int main()
{
    do
    {
        system("clear");
        int M[2][max][max], ANS[2][max][max];
        int i, j, k, row, col;
        printf("\n\t\t\t\t\tMATRIX ADDTITION AND SUBTRACTION\n");
        printf("\n------------------------------------\nROWS AND COLUMNS SPECIFICATION");
        while(1)
        {
            int ROW[2], COL[2];
            for(i = 0; i < 2; i++)
            {
                printf("\n\nMATRIX %d:\n", i + 1);
                while(1)
                {
                    printf("How many rows? ");
                    scanf("%d", &ROW[i]);
                    if(ROW[i] < 1 || ROW[i] > max)
                        printf("ERROR: Out of bounds. Re-enter value...\n");
                    else
                        break;
                }
                while(1)
                {
                    printf("How many columns? ");
                    scanf("%d", &COL[i]);
                    if(COL[i] < 1 || COL[i] > max)
                        printf("ERROR: Out of bounds. Re-enter value...\n");
                    else
                        break;
                }
            }
            if(ROW[0] - ROW[1] + COL[0]- COL[1] == 0)
            {
                row = ROW[1];
                col = COL[1];
                break;
            }   
            else
                printf("\nERROR: Row and column lengths do not match. Re-enter the values...\n");
        } 

        printf("\n-----------------------------------\nDATA ENTRY");
        for(i = 0; i < 2; i++)
        {
            printf("\n\nMATRIX %d:\n", i + 1);;
            for(j = 0; j < row; j++)
            for(k = 0; k < col; k++)
            {
                printf("[%d][%d] = ", j, k);
                scanf("%d", &M[i][j][k]);
            }
        }

        for(i = 0; i < row; i++)
        for(j = 0; j < col; j++)
        {
            ANS[0][i][j] = M[0][i][j] + M[1][i][j];
            ANS[1][i][j] = M[0][i][j] - M[1][i][j];
        }
        printf("\n------------------------------------\n");
        for(i = 0; i < 2; i++)
        {
            (i == 0)? printf("ADDITION RESULT MATRIX:\n\n") : printf("SUBTRACTION RESULT MATRIX:\n\n");
            for(j = 0; j < row; j++)
            {
                for(k = 0; k < col; k++)
                {
                    printf("%d\t", ANS[i][j][k]);
                }
                printf("\n\n");
            }
        }
        printf("Enter x to exit... ");
        fseek(stdin, 0, 0);
    } while(getchar() != 'x');
    printf("\nGoodbye\n\n");
    return 0;
}