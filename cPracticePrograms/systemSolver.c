#include <stdio.h>
#include <stdlib.h>
#define MAX 20
void inputeqs(float *, int, int);
void display(float *, int, int);
int reduced(float *, int, int, int);
void reducesys(float *, int, int);
int main()
{
    float SYS[MAX * MAX];
    int eqs, vars, i;
    do
    {
        system("clear");
        printf("\nSIMULTANEOUS EQUATIONS SOLVER\n");
        while(1)
        {
            printf("\nNumber of variables? ");
            scanf("%d", &vars);
            if(vars + 1 > MAX)
                printf("\nThis program can only handle %d variables :(\n", MAX - 1);
            else if(vars == 0)
            {
                printf("\nThat would be a constant expression :/\n");
                goto END;
            }
            else if(vars < 0)
                printf("\nNow what is that supposed to mean >:(\n");
            else
                break;
        }
        while(1)
        {
            printf("\nNumber of equations? ");
            scanf("%d", &eqs);
            if(eqs > MAX)
                printf("\nThis program can only handle %d equations\n", MAX);
            else if(eqs < 1)
            {
                printf("\nLooks like you don't want to solve anything\n");
                goto END;
            }
            else
                break;
        }
        inputeqs(SYS, eqs, vars);
        printf("\nYour system...\n");
        display(SYS, eqs, vars);
        reducesys(SYS, eqs, vars);
        printf("\nAfter reduction... \n");
        display(SYS, eqs, vars);
        for(i = 0; i < eqs; ++i)
        {
            if(reduced(SYS, eqs, vars, i) == -1)
            {
                printf("\nNo solutions");
                goto END;
            }
        }
        if(reduced(SYS, eqs, vars, 0) == 1)
        {
            for(i = 0; i < vars && i < eqs; ++i)
            {
                if(SYS[i + i * (vars + 1)] == 0)
                    printf("\nx%d has infinite solutions", i + 1);
                else
                    printf("\nx%d = %f", i + 1, SYS[vars + i * (vars + 1)]);
            }
        }
        else
            printf("\nInfinte solutions");
        END:
        printf("\n\n");
        fseek(stdin, 0, SEEK_SET);
        printf("Enter x to exit... ");
    } while(getchar() != 'x');
    printf("\nGOODBYE\n\n");
}
void inputeqs(float *SYS, int eqs, int vars)
{
    int i, j;
    printf("\n");
    for(i = 0; i < eqs; ++i)
    {
        printf("\nEquation %d\n", i + 1);
        for(j = 0; j < vars + 1; ++j)
        {
            if(j < vars)
                printf("x%d coefficient:\t", j + 1);
            else
                printf("Constant sum:\t");
            scanf("%f", &SYS[j + i * (vars + 1)]);
        }
    }
}
void display(float *SYS, int eqs, int vars)
{
    int i, j;
    for(i = 0; i < eqs; ++i)
    {
        printf("\n");
        for(j = 0; j < vars + 1; ++j)
        {
            if(j < vars)
                printf("%f\t", SYS[j + i * (vars + 1)]);
            else 
                printf("| %f\t", SYS[j + i * (vars + 1)]);
        }
    }
    printf("\n");      
}
int reduced(float *SYS, int eqs, int vars, int i)
{
    int j;    
    for(j = i + 1; j < vars; ++j)
        if(SYS[j + i * (vars + 1)] != 0)
            return 0;
    j = i;
    if(j > vars - 1)
        --j;
    if(SYS[j + i * (vars + 1)] == 0 && SYS[vars + i * (vars + 1)] != 0)
        return -1;
    else 
        return 1;
}
void reducesys(float *SYS, int eqs, int vars)
{
    void headswitch(float *, int, int, int);
    void reduceqs(float *, int, int, int);
    int head; //Current row and column
    int i;
    float temp;
    for(head = 0; head < eqs && head < vars; ++head)
    {   
        headswitch(SYS, eqs, vars, head);
        temp = SYS[head + head * (vars + 1)];
        if(temp == 0)
            continue;
        for(i = head; i < vars + 1; ++i)
            SYS[i + head * (vars + 1)] /= temp;
        for(i = 0; i < eqs; ++i)
            if(i != head)
                reduceqs(SYS, vars, i, head);
    }
}
void headswitch(float *SYS, int eqs, int vars, int head)
{
    int i = head, j;
    float temp;
    while(SYS[head + i * (vars + 1)] == 0 && i++ < eqs);
    if(i != head)
    {
        for(j = head; j < vars + 1; ++j)
        {
            temp = SYS[j + i * (vars + 1)];
            SYS[j + i * (vars + 1)] = SYS[j + head * (vars + 1)];
            SYS[j + head * (vars + 1)] = temp;
        }
    }
}
void reduceqs(float *SYS, int vars, int i, int head)
{
    int j;
    float multiplier;
    multiplier = SYS[head + i * (vars + 1)];
    for(j = head; j < vars + 1; ++j)
        SYS[j + i * (vars + 1)] -= multiplier * SYS[j + head * (vars + 1)];
}