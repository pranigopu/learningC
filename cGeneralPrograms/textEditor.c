// BASIC TEXT EDITOR
#include <stdio.h>
#include <stdlib.h>
#include "myStrings.h"
int main()
{
  printf("\nBASIC TEXT EDITOR\n\nDefault file is 'myNotes.txt'\nEnter l to learn functionality\n");
  char file[20] = "myNotes.txt";
  char temp[20];
  char cmd;
  FILE *fp; // fp for 'file pointer'
  START:
  printf("\nEnter command: ");
  fseek(stdin, 0, 0);
  scanf("%c", &cmd);
  switch(cmd)
  {
    case 'f':
    printf("You are currently writing to '%s'.\n", file);
    printf("Enter a file name of your choice: ");
    scanf("%s", temp);
    if(compare(temp, "-", 1) != 0)
    {
      for(int i = 0; i < 20; i++)
      {
        file[i] = temp[i];
      }
      printf("You will now be writing to '%s'.\n", file);
      fp = fopen(file, "r");
      if(fp == 0) //0 for NULL character
      {
        printf("NOTE: The file '%s' is not yet created.\n      To create it, use the command 'w' to open the file in write mode.\n", file);
      }
      fclose(fp);
    }
    else
    {
      printf("You will still be writing to '%s'.\n", file);
      fclose(fp);
    }
    goto START;
    case 'l':
    printf("\nEnter r to read from a text file\n");
    printf("Enter w to write to a file\n");
    printf("\tPress enter twice to exit write mode.\n");
    printf("\tWhile in write mode, to enter a newline into the file:\n\t(1) Press enter after typing a line of text\n\t(2) Type e\n\t(3) Press enter\n\t(4) Type the next line of text\n");
    printf("Enter d to delete the contents of a file\n");
    printf("Enter f choose which file to write to\n");
    printf("Enter c to clear the screen's outputs\n");
    printf("Enter x to exit program\n");
    goto START; 
    case 'r':
    fp = fopen(file, "r");
    if(fp == 0) //0 for NULL character
    {
      printf("\nFile not found.\n");
      goto START;
    }
    cmd = 0;
    printf("\n");
    while(cmd != -1) //-1 is for the EOF character
    {
      char note[100];
      fgets(note, 100, fp);
      printf("%s", note);
      cmd = fgetc(fp);
      if(cmd != -1)
      fseek(fp, -1, 1); //VERY NECESSARY
    }
    printf("\n");
    goto START;
    case 'w':
    fp = fopen(file, "r");
    if(fp == NULL)
    {
      fp = fopen(file, "w");
    }
    fclose(fp);
    fp = fopen(file, "a");
    printf("Your note...\n");
    cmd = 0;
    while(cmd != 'x')
    {
      /* 
      gets(note);
      fprintf(fp, "%s", note);

      These two lines of code were what I used before.
      As a challenge, however, I tried and succeeded in achieve the same effect through scanf. 
      */
      while(1) 
      /*
      Yes, basically an infinite loop. 
      But I use 'break' statements within.
      This saves me from using extra flag variables.
      */
      {
        char note[100];
        scanf("%s", note);
        if(getchar() == 32) //32 is for blank space
        {
          fprintf(fp, "%s", note);
          fprintf(fp, " ");
        }
        else
        /*
        The scanf function will only stop reading a string when either a blank character or a newline character is reached.
        Hence, I only check for a blank space, knowing that an 'else' would imply a newline character.
        */
        {
          fprintf(fp, "%s", note);
          fprintf(fp, "\n");
          printf("Press x to finish.");
          scanf("%c", &cmd);
          break;
        }
      } 
    }
    fclose(fp);
    goto START;
    case 'd':
    printf("Enter d again to delete your file's contents: ");
    fseek(stdin, 0, 0);
    cmd = getchar();
    if(cmd == 'd')
    {
      fclose(fp);
      fp = fopen(file, "w");
      fclose(fp);
      printf("Contents deleted\n");
    }
    else
    {
      printf("Contents intact\n");
    }
    goto START;
    case 'c':
    printf("Enter c again to clear outputs from the screen: ");
    fseek(stdin, 0, 0);
    scanf("%c", &cmd);
    if(cmd == 'c')
    {
      system("clear");
      printf("\nBASIC TEXT EDITOR\n\nDefault file is 'myNotes.txt'\nEnter l to learn functionality\n");
    }
    goto START;
    case 'x':
    fclose(fp);
    printf("\nSee you next time!\n\n");
    return 0;
    default:
    printf("\nCommand not found.\n");
    goto START;
  }
}

  