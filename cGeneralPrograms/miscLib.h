//MY LIBRARY OF MISCELLANEOUS FUNCTIONS

#include <stdio.h>
//Table of contents
//INTEGER SWAP
//STRING TO INTEGER CONVERTER
//NUMERIC STRING TO INTEGER CONVERTER
//INTEGER TO BASE 'base' CHARACTER REPRESENTATION
//EXPAND A SHORTHAND RANGE

//INTEGER SWAP
void intswap(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

//STRING TO INTEGER CONVERTER
void stoi(char *s, int *n)
{
    int i = 0;
    *n = 0;
    while(s[i])
    {
        if(s[i] >= '0' && s[i] <= '9')
            *n = s[i] - '0' + *n * 10;
        i++;
    }
}

//NUMERIC STRING TO INTEGER
int numstoi(char *s, int *n)
{
    int i = 0;
    *n = 0;
    if(s[0] == '-')
        i = 1;
    while(s[i])
    {
        if(s[i] >= '0' && s[i] <= '9')
            *n = s[i] - '0' + *n * 10;
        else 
            return -1;
        i++;
    }
    return 0;
}

//INTEGER TO STRING
void itos(int n, char *s)
{
    int i, temp1, temp2;
    /*
    REVISION NOTE
    The following lines of code and any logic dependent on these have been scrapped:
    if((temp1 = n) < 0)
        n = -n;
    
    This line of code breaks apart when n is the most negative number.
    This is because, in this system at least, the absoute value of the minimum integer is one bit greater than the maximum integer.
    The revised code is not faced by any such obstacle, and can work on any system.
    */
    temp1 = n;
    i = 0;
    do
    {
        s[i++] = -(n % 10) + '0';
    } while((n /= 10) != 0);
    if(temp1 < 0)
        s[i++] = '-';
    s[i] = 0; 
    //NOTE: The string obtained is the reverse of what we want.
    //Reversing this string:
    temp1 = 0;
    while(s[temp1++]);
    for(i = 0; i < (temp1 - 1) / 2; i++)
    {
        temp2 = s[i];
        s[i] = s[temp1 - i - 2];
        s[temp1 - i - 2] = temp2;
    }
}

//INTEGER TO BASE 'base' CHARACTER REPRESENTATION
void itobs(int n, char *s, int base)
{
    int i = 0, temp;
    while(n > 0)
    {
        s[i++] = n % base + '0';
        n /= base;
    }
    s[i] = 0;
    n = 0;
    while(s[n++]);
    for(i = 0; i < (n - 1) / 2; i++)
    {
        temp = s[i];
        s[i] = s[n - i - 2];
        s[n - i - 2] = temp;
    }
}

//MODIFIED atof i.e. STRING TO FLOAT
double mod_stof(char *s)
{
    void getpower(char*, int*, int*, double*);
    int i, j, sign = 1;
    double val, power;
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
    if(s[i] == 'e' || s[i] == 'E') i++;
    switch(s[i])
    {
        case '-': 
        i++; 
        getpower(s, &i, &j, &power); 
        val /= power;
        break;
        case '+': 
        i++;
        default: 
        getpower(s, &i, &j, &power); 
        val *= power;
    }
    return sign * val;
}
void getpower(char *s, int *a, int *b, double *p)
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

//EXPAND A SHORTHAND RANGE
void expand(char *s1, char*s2)
{
    int i, k = 0;
    char min, max, j;
    for(i = 0; s1[i + 2]; i++)
    {
        if(s1[i + 1] == '-')
        {
            min = s1[i];
            max = s1[i + 2];
            if(s2[k - 1] == min)
                k--;
            for(j = min; j < max + 1; j++, k++)
                s2[k] = j;
        }
    }
    s2[k + 1] = 0;
}