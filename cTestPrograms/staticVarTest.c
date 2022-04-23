#include <stdio.h>
int change(int s)
{
    s++;
    return s;
}

int main()
{
    int i, a = 1, b = 1;
    for(i = 0; i < 4; i++)
    {
        int a = 2;
        static int s = 2;
        printf("\n\na = %d", a);
        printf("\ns = %d", s);
        a++;
        s++;
    }
    printf("\n____________\n");

    static int s = 0;
    change(s);
    printf("\ns = %d\n\n", s);
    return 0;
}

//Static variables apparently do not get re-initialised.