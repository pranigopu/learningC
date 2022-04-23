#include <stdio.h>
int main()
{
    int p, q, r, s, t;
    int *pp;
    pp = &p;
    printf("\nThe location of p is %p", pp);
    pp = &q;
    printf("\nThe location of q is %p", pp);
    pp = &r;
    printf("\nThe location of r is %p", pp);
    pp = &s;
    printf("\nThe location of s is %p", pp);
    pp = &t;
    printf("\nThe location of t is %p\n\n", pp);
    return 0;
}