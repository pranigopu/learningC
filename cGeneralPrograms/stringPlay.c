//STRING REVERSAL

#include <stdio.h>
#include <stdlib.h>
#include "myStrings.h"

int main()
{
    printf("\nSTRING PLAY\n(Enter 'learn' to know more)\n\n");
    int size = 30;
    char name[size];
    char temp[size];
    char option[10];
    int i, j, check;
    int lower, upper;

    printf("\nWhat");
    START:
    for(i = 0; i < size; i++)
    {
        name[i] = 0;
        temp[i] = 0;
    }
    printf(" do you want to do? ");
    scanf("%s", option);
    //CHECKING OPTIONS
    if(compare(option, "rev", 3) == 0)
    {
        goto OPTION1;
    }
    else if(compare(option, "seg", 3) == 0)
    {
        goto OPTION2;
    }
    else if(compare(option, "cmp", 3) == 0)
    {
        goto OPTION3;
    }
    else if(compare(option, "lgt", 3) == 0)
    {
        goto OPTION4;
    }
    else if(compare(option, "learn", 5) == 0)
    {
        printf("\n'rev'\t\tfor finding the reverse of a string");
        printf("\n'seg'\t\tfor segregating the string into integers, alphabets and special characters");
        printf("\n'cmp'\t\tfor comparing two strings");  
        printf("\n'lgt\t\t for finding the size of any string");
        printf("\n'cls'\t\tfor clearing the screen");        
        printf("\n'end'\t\tfor ending the program");
        printf("\n________________________________________________\n");
        printf("\nSo, what");
        goto START;
    }
    else if(compare(option, "cls", 3) == 0)
    {
        system("clear");
        printf("\nSTRING PLAY\n(Enter 'learn' to know more)\n\n");
        printf("\nWhat");
        goto START;
    }
    else if(compare(option, "end", 3) == 0)
    {
        printf("\nENDED\n\n");
        return 0;
    }
    else 
    {
        printf("\nNot an option\n\nWhat");
        goto START;
    }
    
    OPTION1:
    j = 0;
    printf("\n>> ");
    scanf("%s", name);
    printf("\n");
    //REVERSAL
    for(i = 0; i < size; i++)
    {
        printf("%c", name[size - 1 - i]);
        if(name[size - 1 - i] != 0)
        {
            temp[j] = name[size - 1 - i];
            j++;
        }
    }
    //CHECKING IF PALINDROME
    check = 0;
    for(i = 0; i < size; i++)
    {
        if(name[i] == temp[i])
        check++;
    }
    if(check == size)
    {
        printf("\nPalindrome? Yes");
        printf("\n________________________________________________\n");
    }
    else
    {
        printf("\nPalindrome? No");
        printf("\n________________________________________________\n");
    }
    printf("\nNow what");
    goto START;

   
    OPTION2:
    j = 0;
    printf("\nSpecifics? ");
    scanf("%s", option);
    //CHECKING SPECIFICS
    if(compare(option, "int", 3) == 0)
    {
        goto INTEGER;
    }
    else if(compare(option, "alpha", 5) == 0)
    {
        goto ALPHA;
    }
    else if(compare(option, "special", 7) == 0)
    {
        goto SPECIAL;
    }
    else if(compare(option, "all", 3) == 0)
    {
        j = 2;
        goto INTEGER;
    }
    else if(compare(option, "learn", 5) == 0)
    {
        printf("\n'int'\t\tfor segregating the integers from the rest of the string");
        printf("\n'alpha'\t\tfor segregating the alphabets from the rest of the string");
        printf("\n'special'\tfor segregating the special characters from the rest of the string");
        printf("\n'all'\t\tfor segregating all the above categories at once");
        printf("\n'end'\t\tfor ending the program\n");
        goto OPTION2;
    }
    else if(compare(option, "end", 3) == 0)
    {
        printf("\nENDED\n\n");
        return 0;
    }
    else 
    {
        printf("\nNot an option\n");
        goto OPTION2;
    }

    REST: 
    for(i = 0; i < size; i++)
    {
        if((name[i] < lower || name[i] > upper) && name[i] != 0)
        {
            //temp[j] = name[i];
            //j++;
            printf("%c", name[i]);
        }
    }
    printf("\n________________________________________________\n");
    printf("\nNow what");
    goto START;
    /* 
    If you wanted to store the order in another array
    for(i = 0; i < j; i++)
    {
        printf("%c", temp[i]);
    }
    printf("\n");
    return 0;
    */   

    INTEGER:
    if(j < 1 || j == 2)
    {
        printf("\n>> ");
        scanf("%s", name);
        printf("\n");
    }
    lower = 48;
    upper = 57;
    for(i = 0; i < size; i++)
    {
        if(name[i] > 47 && name[i] < 58)
        {
            //temp[j] = name[i];
            //j++;
            printf("%c", name[i]);      
        }
    }
    if(j != 1)
    printf(" ");
    if(j < 1)
    goto REST;
    
    ALPHA:
    if(j < 1)
    {
        printf("\n>> ");
        scanf("%s", name);
        printf("\n");
    }
    lower = 97;
    upper = 122;    
    for(i = 0; i < size; i++)
    {
        if(name[i] >  96 && name[i] < 123)
        {
            //temp[j] = name[i];
            //j++;
            printf("%c", name[i]);
        }
    }
    if(j != 1)
    printf(" ");
    if(j == 2)
    {
        goto SPECIAL;
    }
    else if(j < 1)
    {
        goto REST;
    }
    else
    {
        printf("\n________________________________________________\n");
        printf("\nNow what");
        goto START;
    }

    SPECIAL:
    if(j < 1)
    {
        printf("\n>> ");
        scanf("%s", name);
        printf("\n");
    }
    for(i = 0; i < size; i++)
    {
        if((name[i] <  97 || name[i] > 122) && (name[i] <  48 || name[i] > 57))
        {
            //temp[j] = name[i];
            //j++;
            printf("%c", name[i]);
        }
    }
    printf(" ");
    if(j == 2)
    {
        printf("\n________________________________________________\n");
        printf("\nNow what");
        goto START;
    }
    else
    {
        j = 1;
        goto INTEGER;
    }

    OPTION3:
    printf("\n>> ");
    scanf("%s", name);
    printf("\n>> ");
    scanf("%s", temp);
    for(i = 0; i < size; i++)
    {
        if(name[i] - temp[i] == 0)
        check++;
    }
    if(check == size)
    {
        printf("\nThe strings are equal");
        printf("\n________________________________________________\n");
    }
    else
    {
        printf("\nThe strings are not equal");
        printf("\n________________________________________________\n");
    }
    goto START;

    OPTION4:
    printf("\n>> ");
    scanf("%s", name);
    printf("\n");
    {
        char c;
        (length(name) > 1)? (c = 's') : (c = 0);
        printf("String length = %d character%c", length(name), c);
    }
    printf("\n________________________________________________\n");
    printf("\nNow what");
    goto START;
}