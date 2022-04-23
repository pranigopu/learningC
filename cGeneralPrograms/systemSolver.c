// PROGRAM TO SOLVE ANY SYSTEM OF SIMULTANEOUS EQUATIONS
#include <stdio.h>
#include <stdlib.h>
int main()
{
  unsigned int p, q;
  float **s;
  system("clear");
  printf("\nSIMULTANEOUS EQUATIONS SOLVER\n\n");

  // SETTING THE NUMBER OF EQUATIONS AND VARIABLES
  printf("\nSolve for how many variables? ");
  scanf("%u", &p);
  if(p == 0)
  {
    printf("\nYou are asking for a constant equation! Use a calculator for that!\n\n");
    return 0;
  }
  else if(p > 10 || p < 0)
  {
    printf("\nOut of bounds!\n\n");
    return 0;
  }
  printf("Solve for how many equations? ");
  scanf("%u", &q);
  if(q == 0)
  {
    printf("\nNo equations? Okay then, see you later!\n\n");
    return 0;
  }
  else if(q > 10 || q < 0)
  {
    printf("\nOut of bounds!\n\n");
    return 0;
  }
  s = calloc((p + 1) * (q + 1),sizeof(float));
  (p == 1)? printf("\nPlease input for %u variable ", p) : printf("\nPlease input for %u variables ", p);
  (q == 1)? printf("and %u equation.\n", q) : printf("and %u equations.\n", q); 
  // The array that will essentially contain the system of q equations
  /* 
  Note that q + 1 is put as the no. of rows to preserve an empty row.
  This ensures that when there are more variables than equations, 
  the program will identify that there are infinite solutions using the analysis code.
  (The code is the 2nd loop in the SYSTEM ANALYSIS AND EVALUATION section)
  */ 

  // INPUTS OVER, PROCESS PREPARATIONS BEGIN
  float a, b;
  int i, j, k;

  // Ensuring the last buffer row is full of zeroes
  for(i = 0; i < p + 1; i++)
  {
    s[q][i] = 0;
  }

  // SYSTEM EQUATIONS INPUT LOOP
  for(i = 0; i < q; i++)
  {
    printf("\nEquation %d\n", i + 1);
    for(j = 0; j < p + 1; j++)
    {
      if(j == p)
      {
        printf("Constant sum = ");
      }
      else
      {
        printf("x%d coefficient = ", j + 1);
      }
      scanf("%f", &s[i][j]);
    }   
  }
  // PRINTING THE MATRIX FOR FUN
  printf("\n________________________________________________________________________________________________\n");
  printf("\nThe following augmented matrix is produced.\n\n");
  for(i = 0; i < q; i++)
  {
    for(j = 0; j < p + 1; j++)
    {
      if(j == p)
      {
        printf("|\t%f\t", s[i][j]);
      }
      else
      {
        printf("%f\t", s[i][j]);
      }
    }
    printf("\n\n");
  }
  printf("________________________________________________________________________________________________\n");

  // REDUCTION PROCESS 
  for(i = 0; i < q; i++)
  { 
    if(i > p - 1)
    break;

    a = 0;
    for(j = i; j < q; j++) // To check each row of column i for the leading row
    // j < q is appropriate because there are only q equations
    // j = i because the first row after one iteration is to be left aside so the reduction method can continue
    {
      if(s[j][i] != 0 && a == 0)
      {
        a = s[j][i];        
        for(k = i; k < p + 1; k++) // To switch the leading row and row i for every column k
        // k < p + 1 is appropriate because I want to switch whole rows i.e. whole equations and not just the coefficients
        // k = i is done because the overall function has already eliminated the coefficients of every non-leading row before column i 
        {
          b = s[i][k];
          s[i][k] = s[j][k];
          s[j][k] = b;
          s[i][k] /= a; 
          // Switching of rows column-by-column and dividing the new first row with the leading coefficient 
          /*
          IMPORTANT NOTE ON SWITCHING METHOD 
          It is important to note that the switching method

          a = a + b;
          b = a - b;
          a = a - b;

          is not suitable for this sitation.
          The reason is that when the first row is also the leading row, we get a situation as follows

          a = a + a;
          a = a - a; 
          a = a - a; 

          This makes 'a' equal to zero. 
          This happens when i = j, i.e. when the first row i is also the leading row j.
          This is why the temporary storage variable 'b' is used in my code.
          */
        }
      }  
    } 
    // Last stage of reduction iteration
    for(j = 0; j < q; j++) // j refers to row no.
    {
      if(j == i)
      continue; // This prevents the elimination of the leading row's leading coefficient
      b = s[j][i];
      for(k = i; k < p + 1; k++) // k refers to column no.
      {
        s[j][k] -= b * s[i][k];
        // Eliminating the leading coefficients of non-leading rows
        // Applying the eliminating multiplier throughout the row is what we would do for an equation, and the row represents an equation
      }
    }      
  }

  // PRESENTATION OF REDUCED EQUATIONS FOR FUN
  printf("\nThe system reduces to\n\n");
  for(i = 0; i < q; i++)
  {
    for(j = 0; j < p; j++)
    {
      if(j == 0)
      {
        (s[i][j] < 0)? printf("- %fx%d ", -1 * s[i][j], j + 1) : printf("  %fx%d ", s[i][j], j + 1);
      }
      else
      {
        (s[i][j] < 0)? printf("- %fx%d ", -1 * s[i][j], j + 1) : printf("+ %fx%d ", s[i][j], j + 1);
      }      
    }   
    printf(" = %f\n", s[i][p]);

  }

  // SYSTEM ANALYSIS AND EVALUATION
  //1. Checking thoroughly if each equation holds:
  for(i = q; i > -1; i--)
  {
    k = 0;
    for(j = 0; j < p - 1; j++)
    {
      if(s[i][j] != 0)
      {
        k = 1;
        break;
      }
    }
    if(k == 0 && s[i][p - 1] == 0)
    {
      printf("\nHence we see that the system of equations has no solutions.\n\n");
    }
  }

  //2. Checking if a leading coefficient is zero in one row and non-zero in the last
  // If yes, this means the attached variable can have infinite solutions AND can determine infinite solutions for the other variables as well
  /*
  EXPLANATION 
  Due to the reduction process, the columns containing leading coefficients have only zeroes in their other rows.
  Only if the rows could NOT be reduced due till the last variable would there NOT be a zero above a leading coefficient.
  This means there is more than one variable left in the final equation of the fully reduced system.
  Hence, the system must have infintite solutions.
  */ 
  for(i = 1; i < p; i++)
  {
    if (s[i][i] == 0 && s[i - 1][i] != 0)
    {
      printf("\nHence we see that infinite solutions exist for all variables.\n\n"); 
      return 0;  
    } 
  }
  
  //3. Evaluating the variables, if solutions exist and not all variables have infinite solutions 
  printf("\nHence we see that\n");  
  for(i = 0; i < p; i++)
  {
    s[i][i] = s[i][p] / s[i][i]; // Finding xi
    if(s[i][i] / s[i][i] != 1 && s[i][i] != 0) // Checking if s[i][i] is undefined
    {
      printf("\nx%d has infinite solutions", i + 1);
    }
    else
    {
      printf("\nx%d\t =\t%f", i + 1, s[i][i]);
    }    
  }
  printf("\n\n");
  return 0;
}