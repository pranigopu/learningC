#include <stdio.h>
int main()
{
    printf("\nBITWISE NOT\n");
    printf("\n%d\n", ~ -1);
    printf("\n%d\n", ~ 32);
    printf("\nBITWISE AND\n");
    printf("\n%d\n", 24 & 25);
    printf("\n%d\n", 24 & 24);
    printf("\n%d\n", 24 & 23);
    printf("\nBITWISE OR\n");
    printf("\n%d\n", 24 | 25);
    printf("\n%d\n", 24 | 24);
    printf("\n%d\n", 24 | 23);
    printf("\nBITWISE XOR\n");
    printf("\n%d\n", 3 ^ 2);
    printf("\n%d\n", 4 ^ 5);
    printf("\n%d\n", 4 ^ 7);
    printf("\nBITWISE LEFT-SHIFT\n");
    printf("\n%d\n", 7 << 1);
    printf("\nBITWISE RIGHT-SHIFT\n");
    printf("\n%d\n", 7 >> 1);
    printf("\n");
}

/*
As you can see with the output:
- Bitwise operators compare individual bits.
- They return a binary sequence that represents an integer.

BITWISE SHIFTS
Left shift:
Shifts every bit from the most significant bit leftwards (away from units place), leaving units place as 0.
This is equivalent to multiplication by 2.

Right shift:
Shifts every bit from the least significant bit rightwards (away from most significant place), eliminating the least significant bit.
This is equivalent to integer division by 2.

*/