//VOWEL COUNTER
//20-08-19
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int count;
    char W[20];
    do
    {
        count = 0;
        system("clear");
        printf("\nVOWEL COUNTER\n\nEnter string: ");
        scanf("%s", W);

        for(int i = 0; W[i] != '\0'; i++)
        {
            switch(W[i])
            {
                case 'A': case 'E': case 'I': case 'O': case 'U':
                case 'a': case 'e': case 'i': case 'o': case 'u':
                count++;
                break;
            }
        }
        printf("\n%d vowels have been found in the entered string.\n\n", count);
        
        fseek(stdin, 0, 0);
        printf("Enter c to continue: ");
        scanf("%c", &W[0]);
    }while(W[0] == 'c');
    printf("\nProgram terminated\n\n");
    return 0;
}