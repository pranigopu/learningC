#include <stdio.h>

void openfile(char fileName[], int label)
{
    FILE *path;
    char last;
    if(fopen(fileName, "r") == NULL)
    {
      printf("\nThe file '%s' has not been created yet.\n\n", fileName);
    }
    else
    {
      if(label)
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
      if(label)
        printf("\n------- End Of File -------\n\n");
    }
}