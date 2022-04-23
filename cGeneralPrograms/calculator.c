#include <stdio.h>
#include "myMath.h"
#include "trigMath.h"
#include "myStrings.h"
#include "fileHandling.h"
FILE *fp;
int main()
{
    char op[6];
    printf("\nCALCULATOR\n(Enter know to know more)\n");
    float n, m;
    if(fopen("calculationLog.txt", "r") == 0)
        fp = fopen("calculationLog.txt", "w");
    else 
        fp = fopen("calculationLog.txt", "a");
    START:
    printf("\n>> ");
    scanf("%s", op);
    if(compare(op, "kno", 4) == 0)
    {
        printf("\nBASIC\nadd for addition\nmul for multiplication\ndiv for division\n");
        printf("\nADVANCED\npower for nth power\nroot for nth root\nftl for factorial\n");
        printf("\nTRIGONOMETRIC\nsin for sine\ncos for cosine\n");
        printf("\nOTHERS\nhist for seeing past calculations\nend for ending the program\n");
    }
    else if(compare(op, "add", 3) == 0)
    {
        scanf("%f", &n);
        scanf("%f", &m);
        printf("result = %f\n\n", n + m);
        fprintf(fp, "%f + %f = %f\n", n, m, n + m);
    }
    else if(compare(op, "mul", 3) == 0)
    {
        scanf("%f", &n);
        scanf("%f", &m);
        printf("result = %f\n\n", n * m);
        fprintf(fp, "%f * %f = %f\n", n, m, n * m);
    }
    else if(compare(op, "div", 3) == 0)
    {
        scanf("%f", &n);
        scanf("%f", &m);
        printf("result = %f\n\n", n / m);
        fprintf(fp, "%f / %f = %f\n", n, m, n * m);
    }
    else if(compare(op, "pow", 3) == 0)
    {
        float result;
        scanf("%f", &n);
        scanf("%f", &m);
        result = power(n, m);
        printf("result = %f\n\n", m);
        fprintf(fp, "%f ^ %f = %f\n", n, m, result);
    }
    else if(compare(op, "root", 4) == 0)
    {
        float result;
        scanf("%f", &n);
        scanf("%f", &m);
        result = root(n, m);
        printf("result = %f\n\n", m);
        fprintf(fp, "%f ^ (1 / %f) = %f\n", n, m, result);
    }
    else if(compare(op, "ftl", 3) == 0)
    {
        unsigned int p;
        long int q;
        scanf("%u", &p);
        q = factorial(p);
        printf("result = %li\n\n", q);
        fprintf(fp, "%u! = %li\n", p, q);
    }
    else if(compare(op, "sin", 3) == 0)
    {
        scanf("%f", &n);
        m = sine(n);
        printf("result = %f\n\n", m);
        fprintf(fp, "sin(%f) = %f\n", n, m);
    }
    else if(compare(op, "cos", 3) == 0)
    {
        scanf("%f", &n);
        m = cosine(n);
        printf("result = %f\n\n", m);
        fprintf(fp, "cos(%f) = %f\n", n, m);
    }
    else if(compare(op, "end", 3) == 0)
    {
        printf("\nENDED\n\n");
        fclose(fp);
        return 0;
    }
    else if(compare(op, "hist", 4) == 0)
    {
        openfile("calculationLog.txt", 0);
    }
    else 
    {
        printf("\nInvalid command\n");
    }
    fclose(fp);
    fp = fopen("calculationLog.txt", "a");
    goto START;
}