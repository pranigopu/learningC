#include <stdio.h>
struct test
{
    int a;
    float b;
    char c;
};
int main()
{
    struct test x;
    x.a = 2;
    x.b = 2.4;
    x.c = '!';
    struct test *sp;
    sp = &x; 
    printf("\n%p\n\n", sp - 1);
    printf("\n%p\n\n", sp);
    printf("\n%p\n\n", sp + 1);
}