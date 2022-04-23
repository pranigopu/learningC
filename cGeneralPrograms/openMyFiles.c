#include <stdio.h>
#include <string.h>

int main()
{
  char fileName[30];
  char last;
  char cmd[10];
  FILE *path;
  printf("\nFILE VIEWER\n\n");
  
  begin:
  printf("Enter your command: ");
  scanf("%s", cmd);
  
  if(strncmp(cmd, "openfile", 8) == 0) // strncmp() is a function that compares two strings. To see how such a function could work, see my program 'password'.
  {
    printf("Enter file name: ");
    scanf("%s", fileName);
    if(fopen(fileName, "r") == NULL)
    {
      printf("\nThe file '%s' does not exist\n\n", fileName);
      goto begin;
    }
    else
    {

      printf("\n\n------- %s -------\n\n", fileName);
      path = fopen(fileName, "r");
      last = 0;
      while(last != EOF) // EOF represents the 'End Of File' character
      {
        char line[1000]; // Clever way to ensure that 'line' is blank before it is filled with the contents of the file's next line
        fgets(line, 1000, path);
        printf(" %s", line);
        last = fgetc(path); // fgetc(path) is a function retrieving the current character of the current line in the file
        fseek(path, -1, 1); //VERY NECESSARY
      }
      fclose(path);
      printf("\n------- End Of File -------\n\n");
      goto begin;
    }
  }
  else if(strncmp(cmd, "about", 5) == 0)
  {
    printf("\nThis is a program capable of opening any file whose name you enter after the prompt.\n");
    printf("To open a file, enter the command 'openfile'.\n");
    printf("To exit the program, enter the command 'exit'.\n\n");
    goto begin;
  }
  else if(strncmp(cmd, "exit", 4) == 0)
  {
    printf("\nPROGRAM TERMINATED\n\n");
    return 0;
  }
  else
  {
    printf("Command not found\n");
    goto begin;
  }
}
