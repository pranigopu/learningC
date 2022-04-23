#include <stdio.h>
void f(char *s, int *a, int *b, double *p)
{
    int i = *a;
    int j = *b;
    double power = *p;
    for(j = 0; s[i] >= '0' && s[i] <= '9'; i++)
        j = j * 10 + s[i] - '0';
    for(power = 1, i = 0; i < j; i++)
        power *= 10;
    *a = i;
    *b = j;
    *p = power;
}
int main()
{
    int i, j, k, sign = 1;
    double val, power;
    char s[30];
    scanf("%s", s);
    for(i = 0; s[i] == ' '; i++);
    sign = (s[i] == '-')? -1 : 1;
    if(s[i] == '-' || s[i] == '+') i++;
    for(val = 0; s[i] >= '0' && s[i] <= '9'; i++)
        val = val * 10 + s[i] - '0';
    if(s[i] == '.') i++;
    for(power = 10; s[i] >= '0' && s[i] <= '9'; i++)
    {
        val += (s[i] - '0') / power;
        power *= 10;
    }
    printf("\nval = %f\n", val);
    if(s[i] == 'e' || s[i] == 'E') i++;
    switch(s[i])
    {
        case '-': 
        i++; 
        f(s, &i, &j, &power); 
        val /= power;
        break;
        case '+': 
        i++;
        default: 
        f(s, &i, &j, &power); 
        val *= power;
    }
    printf("\n%f\n", sign * val);
}