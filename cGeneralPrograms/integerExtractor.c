//This is mostly an exercise / fun program
//It extracts integers from strings, stores these integers and performs operations on these them 
#include <stdio.h>
#include <stdlib.h>
#include "miscLib.h"
#define START 4
#define EXTRACT 3
#define INSPECT 2
#define OPERATE 1
#define METHOD 0
int main()
{
    //Title, subtitles
    printf("\nINTEGER EXTRACTION AND OPERATION\n");
    printf("Extract integers from strings and operate on them\n");
    printf("Enter 0 to learn more\n\n");
    //All these following variables must hold their values, inputted or assigned, throughout the program.
    int a, n, r;
    int i, j, k, l; 
    char flag;
    l = 0;
    a = 20;
    n = 10;
    r = 10;
    flag = 0;
    while(1)//Yes, it is an infinite loop... in principle.
    {
        if(flag == -1)
        {
            printf("\nRESETTING");
            printf("\nCurrently,\n");
            printf("%d characters can be stored in one input\n%d integers can be stored in one run\n\n", a, n);
            a = 0;
            n = 0;
            r = 0;
            //These above assignments ensure that each of the following three loops can be entered.
            while(a < 1)
            {
                printf("Enter a new character limit: ");
                scanf("%d", &a);
                if(a < 1)
                printf("Invalid limit.\n");
            }
            while(n < 1)
            {
                printf("Enter a new integers storage limit: ");
                scanf("%d", &n);
                if(n < 1)
                printf("Invalid limit.\n");
            }
            while(r < 1)
            {
                printf("Enter a new results storage limit: ");
                scanf("%d", &r);
                if(r < 1)
                printf("Invalid limit.\n");
            }
            printf("\nNow,\n");
            printf("%d characters can be stored in one input\n%d integers can be stored in one run\n%d results can be stored in one run", a, n, r);
            printf("\n\n");
        }

        //Main program begins here.
        do 
        {
            char A[a]; 
            //Temporarily stores string inputs.
            //Is overwritten with every string input.
            int N[n]; 
            //Stores extracted integers for as long as this infinite loop is running.
            //Is overwritten with every round of extraction
            float R[r]; 
            //Stores results obtained from the operations for as long as this infinite loop is running.
            //Is overwritten after it is full
            char cmd = 0, method = 0, array = 0;
            for(i = 0; i < a; i++)
            {
                A[i] = 0;
            }
            for(i = 0; i < n; i++)
            {
                N[i] = 0;
            }
            for(i = 0; i < r; i++)
            {
                R[i] = 0;
            }
            flag = START;
            while(flag == START)
            {
                printf("________________________________________________\n");
                printf("\nYour command: ");
                fseek(stdin, 0, 0);
                scanf("%c", &cmd);
                switch(cmd)
                {
                    case '0':
                    printf("\n1 to input strings and extract integers from them");
                    printf("\n2 to inspect the storage of the extracted integers");
                    printf("\n3 to operate on the integers through reference");
                    printf("\n4 to inspect the storage of results");
                    printf("\nr to reset the storage capacities");
                    printf("\nc to clear the screen");
                    printf("\nx to exit");
                    printf("\n\n");
                    flag = START;
                    break;
                    
                    case '1':
                    printf("\n");
                    fseek(stdin, 0, 0);
                    flag = EXTRACT;
                    break;
                
                    case '3':
                    printf("\n");
                    fseek(stdin, 0, 0);
                    printf("------------------------------------\n");
                    flag = OPERATE;
                    break;
                
                    case 'r':
                    printf("\nWARNING: Resetting storage capacity settings erases all data from the arrays.");
                    printf("\n         Re-enter r to confirm reset: ");
                    fseek(stdin, 0, 0);
                    scanf("%c", &cmd);
                    if(cmd == 'r')
                    {
                        flag = -1;
                        fseek(stdin, 0, 0);
                    }
                    else
                    {
                        printf("You have cancelled the reset.\nArray data are intact.");
                        printf("\n\n");
                        flag = START;
                    }
                    break;

                    case 'c':
                    system("clear");
                    printf("\nINTEGER EXTRACTION AND OPERATION\n");
                    printf("Extract integers from strings and operate on them\n");
                    printf("Enter 0 to learn more\n\n");
                    flag = START;
                    break; 
                    
                    case 'x':
                    printf("\nYou have terminated the program.\n\n");
                    return 0;

                    default:
                    if(cmd == '2' || cmd == '4')
                    {
                        fseek(stdin, 0, 0);
                        flag = OPERATE;
                        method = -1;
                    }
                    else
                    {
                        printf("\nInvalid command.");
                        printf("\n\n");
                        flag = START;
                    }
                }
                if(flag == -1)
                break;
                //All the main commands play out below
                while(flag == EXTRACT)
                {
                    k = 0;
                    while(k > n || k < 1)
                    {
                        //printf("Enter 1 to overwrite previous strings");
                        //printf("Enter 2 to append to previous strings");

                        printf("How many strings to enter? ");
                        scanf("%s", A);
                        k = numIntify(A);
                        if(k > n || k < 1)
                        {
                            if(k == -1)
                            {
                                printf("\nNot an integer.");
                                printf("\n\n");
                            }
                            else
                            {
                                printf("\nPlease enter a number between 1 and %d.", n);
                                printf("\n\n");
                            }
                        }
                    }
                    for(i = 0; i < k; i++)
                    {
                        printf("String %d: ", i + 1);
                        scanf("%s", A);
                        N[i] = intify(A);
                    }
                    (k > 1)? printf("%d integers ", k) : printf("%d integer ", k);
                    (k > 1)? printf("have been extracted and stored.\n\n") : printf("has been extracted and stored.\n\n");
                    flag = START;
                }//EXTRACT while ends here

                while(flag == OPERATE)
                {
                    if(l > r - 1)
                    {
                        l = 0;
                        R[l] = 0;
                    }
                    if(method != -1)
                    {
                        printf("\nYour operation: ");
                        fseek(stdin, 0, 0);
                        scanf("%c", &cmd);
                    }
                    switch(cmd)
                    {
                        case'0':
                        printf("\n+ to add");
                        printf("\n- to subtract");
                        printf("\n* to multiply");
                        printf("\n/ to divide");
                        printf("\n2 to view the storage of extracted integers");
                        printf("\n4 to view the storage of results");
                        printf("\nx to exit operation mode");
                        printf("\n");
                        flag = OPERATE;
                        break;
                    
                        case '2':
                        for(int i = 0; i < n; i++)
                        {
                            printf("\nN[%d]\t=\t%d", i, N[i]);
                        }
                        printf("\n");
                        if(method == -1)
                        {
                            flag = START;
                        }
                        else
                        {
                            flag = OPERATE;
                        }
                        break;
                    
                        case '4':
                        for(i = 0; i < r; i++)
                        {
                            printf("\nR[%d]\t=\t%f", i, R[i]);
                        }
                        printf("\n\n");
                        if(method == -1)
                        {
                            flag = START;
                        }
                        else
                        {
                            flag = OPERATE;
                        }
                        break;

                        case 'x':
                        printf("\nYou have exited operation mode.");
                        printf("\n");
                        method = -1;//For formatting purposes
                        flag = START;
                        break;
                        
                        default:
                        switch(cmd)
                        {
                            case '+': case '-': case '*': case '/':
                            flag = METHOD;
                            break;

                            default:
                            printf("\nInvalid operation.");
                            printf("\n");
                            flag = OPERATE;
                            method = -2;
                        }
                    }
                    
                    while(flag == METHOD)
                    {
                        printf("\nMethod: ");
                        fseek(stdin, 0, 0);
                        scanf("%c", &method);
                        switch(method)
                        {
                            case '0':
                            printf("\n1\tfor range operations.");
                            printf("\n\tWith this, you can operate a range of numbers from any one array");
                            printf("\n\t- array of stored integers\n\t- array of stored results.");
                            
                            printf("\n\n2\tfor multiple operations.");
                            printf("\n\tWith this, you can operate on a set of specific numbers taken any pf the arrays.");
                            
                            printf("\n\nx\tto exit operation.");
                            printf("\n\tWith this, you can re-enter your operation");
                            printf("\n");
                            flag = METHOD;
                            break;
                            
                            case '1':
                            i = -1;
                            j = -1;
                            k = 0;
                            array = 0;
                            printf("\nOperate from\n");
                            while(array != 'R' && array != 'N')
                            {
                                printf("Array: ");
                                fseek(stdin, 0, 0);
                                scanf("%c", &array);
                                if(array != 'R' && array != 'N')
                                printf("You can only operate with the arrays 'R' and 'N'.\n");
                            }
                            k = (array == 'N')? n : r;
                            for(int x = 0; x < 2; x++)
                            {
                                if(x == 1)
                                printf("Operate until\n");
                                while(((x == 0)? i : j) < 0 || ((x == 0)? i : j) > k - 1)
                                {
                                    printf("Index %d: ", x + 1);
                                    scanf("%s", A);
                                    if(numIntify(A) == -1)
                                    {
                                        printf("Not an integer.\n");
                                        continue;
                                    }
                                    (x == 0)? (i = numIntify(A)) : (j = numIntify(A));
                                    if(((x == 0)? i : j) < 0 || ((x == 0)? i : j) > k - 1)
                                    printf("The index %d is out of bounds for the array %c.\n", ((x == 0)? i : j), array);   
                                }
                            } 
                            R[l] = (array == 'N')? N[i] : R[i]; 
                            //The above line is crucial for all operations other than addition, and works for addition too, of course.
                            //It designates a suitable 1st value for the result.
                            for(k = ((i < j)? i + 1 : i - 1); k != ((i < j)? j + 1 : j - 1); (i < j)? k++ : k--)
                            /*The direction of the loop's progression has been defined for each case, wherein the cases are
                            (1) i < j
                            (2) i > j
                            i = j does not matter, since if it is the case, the for loop will break without iterating even once.
                            This will leave the result equalling the ith element of the array, wgich is appropriate.
                            */
                            {
                                R[l] = arith(cmd, R[l], (array == 'N')? N[k] : R[k]);
                            }
                            printf("\nResult: %f\n(Stored in R[%d])", R[l], l);
                            l++; //Leaves a record of the previous result by moving to a new location to store the next result
                            printf("\n");
                            flag = OPERATE;
                            break;

                            case '2':
                            printf("\nHow many elements to enter? ");
                            scanf("%d", &k);
                            printf("\n");
                            for(i = 0; i < k; i++)
                            {
                                j = -1;
                                array = 0;
                                printf("Element %d\n", i + 1);
                                while(array != 'R' && array != 'N')
                                {
                                    printf("Array: ");
                                    fseek(stdin, 0, 0);
                                    scanf("%c", &array);
                                    if(array != 'R' && array != 'N')
                                    printf("You can only operate with the arrays 'R' and 'N'\n");
                                }
                                while(j < 0 || j > ((array == 'N')? n - 1 : r - 1))
                                {
                                    printf("Index: ");
                                    scanf("%s", A);
                                    j = numIntify(A);
                                    if(j == -1)
                                    {
                                        printf("\nNot an integer");
                                        printf("\n\n");
                                    }
                                    else if(j > ((array == 'N')? n - 1 : r - 1))
                                    {
                                        printf("\nThe index %d is out of bounds for the array %c.", j, array);   
                                        printf("\n\n");
                                    }
                                }
                                R[l] = arith(cmd, R[l], (array == 'N')? N[j] : R[j]);
                                printf("\n");
                            }
                            printf("\nResult: %f\n(Stored in R[%d])", R[l], l);
                            l++; //Leaves a record of the previous result by moving to a new location to store the next result
                            printf("\n");
                            flag = OPERATE;
                            break;

                            case 'x':
                            printf("\nYou have abandoned the operation.");
                            printf("\n");
                            flag = OPERATE;
                            break;

                            default:
                            printf("\nInvalid method.");
                            printf("\n");
                            flag = METHOD;
                        } 
                    }//METHOD while ends here
                    if(method > -1)
                    {
                        printf("------------------------------------\n");
                    }
                    else
                    {
                        method = 0;
                    }   
                }//OPERATE while ends here
            }//START while ends here
        } while(flag != -1);//2nd while ends here
    }
}

//It is true; goto had made my program much more unreadable
//I am happy to have implemented the program with loops