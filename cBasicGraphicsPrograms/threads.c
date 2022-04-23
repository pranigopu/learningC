#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
void gotoxy(int, int);    
int loadbar(void);
int main()
{
    pthread_t thread;
    system("clear");
    pthread_create(&thread, NULL, loadbar, NULL);
    
    pthread_join(thread, NULL);
    
    int i = 0;
    while(getchar() != 'x')
    {   
        gotoxy(i, 10);
        printf("X\n");
        i++;
    }

    system("clear");
}

void gotoxy(int x,int y)    
{
    printf("%c[%d;%df",27,y,x);
}
int loadbar()
{
    int i;
    for(i = 0; i < 3; i++)
    {
        getchar();
        gotoxy(1, 0);
        printf("%c\n", 'a' + i);
        sleep(1);

        gotoxy(2, 0);
        printf("%c\n", 'a' + i);
        sleep(1);

        gotoxy(3, 0);
        printf("%c\n", 'a' + i);
        sleep(1);
    }
}