# I/O, arrays \& files
All the following notes are in the context of C unless explicitly stated otherwise.

## Input and Output (i/o)
There are two methods of i/o, formatted and unformatted.

### Formatted i/o
Such i/o can store, retrieve and display variables in different formats i.e. different data types. This enables you to manage and manipulate the data values according to the properties of certain data types. For example, it enables you to input integers that you can add, subtract, multiply and divide with other integers.

### Unformatted i/o
Here you will see the significance of formatted i/o, but also its limitations.
Unformatted i/o can only store, retrieve and display variables as characters or as strings, which are continuous sequences of characters. For example, you cannot input '10' for a variable 'num' and add it to 10 to get 20, because your input of  or is stored as a single character '1' or a string of the characters '1' and '0' i.e. '10', depending on what was your unformatted input function. 
<br><br>
The advantage of such i/o when inputting, storing and Outputting string variables is that you can input variables with blank spaces and display them as such. For example, if I inputted 'Pranav Gopal' into the array 'name' with a formatted input function, 'name' would only contain 'Pranav', and if I Outputted the variable, the Output would be 'Pranav'. But if I inputted the same with an unformatted input function, 'name' would contain 'Pranav Gopal' with the space, and if I Outputted the variable, the Output would be 'Pranav Gopal'. The disadvantage is that I will not be able to select a particular character from the string, as I can do with formatted i/o, or compare two variables where at least one is an unformatted input. Some formatted i/o functions in C
<br><br>
**scanf** which has the syntax 

```
scanf(“<format_specifier>”, &variable);
```

**printf** which has the syntax

```
printf(“<text> <format_specifier>”, variable);
```

Note that the format specifier is always preceded by a '\%' without space. Also note that multiple values can be inputted and Outputted as so:

```
scanf(“%d%d%d”, &num1, &num2, &num3);
printf(“The numbers are %d, %d, and %d.”, num1, num2, num3);
```

Say I inputted 1, 2 and 3 for num1, num2 and num3 respectively.<br><br>
**Output**:

```
The numbers are 1, 2 and 3.
```

Note that the order of the format specifiers must correspond to the order of the variables. This is crucial when you consecutively input or Output variables having different data types.
Also note that the address operator is not required for inputting strings. To see why, go to the next section “Strings and other arrays”.

#### Some unformatted i/o functions in C
**gets** i.e. 'get string', whose syntax is simply

```
gets(character_array);
```

**puts** i.e. 'put string', whose syntax is simply

```
puts(character_array);
```

## Variable declaration, scanf and printf
When a variable is declared, it is not automatically assigned to a memory address.
This is why the scanf('formatted scan') function requires that individual variables whose values are to be inputted must be preceded by the address operator '\&' to prevent input failure, because the identifier may or may not be attached to a memory address.
<br><br>
The printf ('formatted print') function does not require the address operator because any variable that can be printed must obviously have a value to print, which means it must already have a memory address, meaning the identifier is necessarily attached to an address, so the function's code need not bother with additional specification for the memory address.

## Strings and other arrays
An array is a set of a fixed number of variables of the same datatype stored such that their memory addresses are continuous.  A string is an array of characters.

### General arrays
When you declare an array, you assign a continuous set of memory addresses, and automatically assign an identifier for each of them, as shown below:

```
<datatype>  array_name[array_size];
```

For example:

```
int numbers[10]; // An array of 10 integers is formed
```

'array_size' denotes the number of memory addresses allocated and assigned to the same number of identifiers.  Each identifier in the array i.e. each element of the array is denoted as follows:

```
array_name[index]
```

For example:

```
numbers[2]; // The 3rd element in the array, the 1st being numbers[0]
```

'index' denotes the relative position of the element's memory address from the first memory address allocated to the array (which is assigned to the first element of the array). This ordering implies that the memory addresses are allocated to the array in a numerical order.

### Strings
A string is declared in the same way, with the datatype being 'character':

```
char string[string_size];
```

For example:

```
char car[50]; // An array of 50 characters
```

However, while they are arrays, strings can be initialised in a special way:

```
char car[50] = “ThrustSSC”;
```

There is a unique format specifier for strings as well, i.e. '\%'. Usage example:

```
printf(“The fastest cars is %s”, car);
```

**Output**:

```
The fastest car is ThrustSSC
```

To assign or input values into arrays, a recursive assignment or input loop may be needed, or specific elements have to be individually assigned or inputted. However, we can input strings using the formatted input function as follows:

```
scanf(“%s”, car);
```

The address operator cannot and need not be used for applying scanf to strings for two reasons, the first showing why it cannot be used, and second showing why it need not be used:
<br><br>
1.<br>
An array has a multitude of memory addresses, since it is not an individual variable, but an identifier referring to a set of consecutively placed variables.
<br><br>
2.<br>
The declaration of an array causes the automatic assignment of memory addresses to all the elements in the array, because declaring an array means allocating a continuous and consecutive set of memory addresses to an identifier.
<br><br>
Note, however, that this input provision does not exist for arrays of other datatypes. 

#### Formatted and unformatted strings
I am not able to find a precise distinction when it comes to strings. After running some test programs under the name test.c, all I can distinguish is that formatted strings end with a null character, a blank space or a newline character ('\n'), while unformatted strings end only with a newline character ('\n'). Both have consecutive memory allocation, both have defined bounds, both have definite memory addresses for their elements. 
<br><br>
In fact in both forms of inputs I was able to enter more characters than the size limit specified and retrieve the Output of all those characters, even the out-of-bounds ones, be it formatted or unformatted Output. This probably would not be possible if there was not enough available continuous memory spaces next to the character at the maximum index of the string.

## Decision control
### Switch-case-default statement
**Syntax**:

```
switch(integer_expression)
{
   case constant_1:
   statements;
   
   case constant_2:
   statements;
   
   <etc>…
   
   default:
   statements;
}
```

#### Components
As you can see, three keywords make up this control statement.
<br><br>
The 'integer expression' following the keyword 'switch' refers to any statement that returns an integer value, hence, it can be an integer constant or an expression (variable or constant) that returns an integer constant.
<br><br>
The keyword 'case' must be followed by a unique constant i.e. each 'case' statement within a control statement must be followed by a unique integer.
<br><br>
The function of the 'default' statement is to indicate what statements must be executed if none of the statements under any 'case' statement are executed.

#### Functionality
The control statement first evaluates the integer expression. The return value of this expression is compared to each constant following the 'case' statement. 
<br><br>
If a match is found, the statements under the particular 'case' statement AS WELL AS ALL THE STATEMENTS IN THE FOLLOWING 'CASE' STATEMENTS, including the statements under the 'default' statement are executed.
<br><br>
If no match is found in any of the 'case' statements', the statements under default are executed, by default.
<br><br>
**IMPORTANT**:<br>In order to make the code such that only the particular 'case' statement whose constant is matched to the integer expression, use the 'break' statement after any statements under the 'case' statement, within the 'case' statement's execution area of course.
<br><br>
**IMPORTANT**:<br>In the 'switch' and 'case' character expression and character constants respectively can also be used, because characters are stored as integers, as can be seen in the program 'formatConversionTest.c' (which is in the directory '~pranav/cPrograms').
<br><br>
If you use float values, you will get an error such as the following:

```
switchCaseDefaultTest.c:8:5: error: statement requires expression of integer type ('float' invalid)
	switch(c).
```                                                                

**FINAL NOTE**:<br>Execution of multiple statements under the 'case' statement DOES NOT require any flower brackets, unlike the 'if-else' control statement, because a 'case' statement is merely a kind of label, and not a code block. However, 'switch' defines a code block.

## Streams 
A stream is a reusable piece of code that enables a sequence of objects (usually bytes, but not necessarily so) to be accessed in sequential order.
<br><br>
A stream abstracts the complexity of dealing with data while providing useful operations to perform on the data, such as reading, writing and seeking.
<br><br>
A stream defines the source and destination for a certain set of data, and the particular transformation of data that needs to take place to and from the source and destination.

## File handling
The construct of a file is made of two main elements.
<br><br>
The first element is a variable of the type FILE, which is data structure defined in “stdio.h”, which enables the storage of information about a file. It includes:

- File name
- Current position in the file
- The mode in which the file is opened (read, write, append)
- Whether end of file has been reached

The second element is a file's content, which is an ordered and continuous sequence of bytes treated as one unit, containing data that has been written to the file and can be read from the file.

### File pointer
A file pointer points to the file's file structure object, not the file's contents. It is declared in a manner as follows:

```
FILE *pointer;
```

### File handling commands
#### fopen

Usage example:

```
pointer = fopen(“file_path”, “mode”);
```

<file_path> may be only the file name if the file is present in the same directory as the executable program using it.
<br><br>
Mode is the form in which you want to open the file, such as write, append or read. 
Write mode, "w", enables you to create a file with the specified file name if no file exists with the same name and path.
<br><br>
Returns the file's memory location, and makes the file available for the program to read from or write/append into. Hence, due to the nature of the return value, we can assign the file pointer 'pointer' to this function's return value. This way, we can use 'pointer' to refer to the file.
<br><br>
**The importance of fopen:**<br>
Recall that an identifier of a variable that is not a part of an array is not assigned to a memory address at the time of declaration. Similarly, a file name is not automatically assigned to the memory location of the file it names. By default, a file name is just a string, as seen here:
<br><br>
**Source code**:

```
#include <stdio.h>	
int main( )
{	 
   fprintf(“myNotes.txt", “\nGo to he…aven\n”)
   return 0;			   	 
}
```
				   		
**Output**:

```
z.c:4:13: warning: incompatible pointer types passing 'char [12]' to parameter of type 'FILE *' (aka 'struct __sFILE *').         															    			                         
      [-Wincompatible-pointer-types]											                              
    fprintf("myNotes.txt", “\nGot to he…aven\n”);									                              
            ^~~~~~~~~~~~~										                              
```

'fopen' is the function that establishes an input stream, Output stream, or both (depending on the mode given) between the file and the console. This is done by copying a file's contents from secondary storage to the main memory, from where the file's data is accessed. This allows access to the file, for reading and writing purposes.

#### fclose
Usage example:

```
fclose(file_pointer);
```

This causes the changes made to the file data stored in the main memory to replace the data in the file's storage location in the secondary memory, thereby committing it. As the name suggests, it also deallocates the stream between the file and the console, so that the stream is no longer accessible, and is hence closed.
<br><br>
**NOTE**: Ending the program before running this function will cause the changes made to the file to not be committed.

#### fprintf
Usage example:

```
fprintf(file_pointer_or_path, "text", arguments);
```

Writes strings and formatted constants into the file. Functionality is the same as 'printf', except the values are not written into the 'stdout' file but the specified file.

#### fscanf
Usage example:

```
fscanf(file_pointer_or_path, “format_specifiers”, variables_with_address_operator);
```

Reads strings and formatted constants from the file. Functionality is the same as 'scanf', except the values are not read from the 'stdin' file but the specified file.

#### fputc
Usage example:

```
fputc(file_pointer_or_path, character_constant);
```

#### fgetc
Usage example:

```
fgetc(file_pointer_or_path);
```

Reads the character from the the current position in the specified file. Functionality is the same as 'getchar', except the values are not read from the 'stdin' file but the specified file.

#### fputs
Usage example:

```
fputs(string_constant, file_pointer_or_path);
```

Writes a string of characters into the file. Functionality is the same as 'puts', except that the string is not Outputted but stored in the specified file.

#### fgets
Usage example:

```
fgets(string_variable, character_read_limit, file_pointer_or_path);
```

character_read_limt is the number characters that must be read from the file and assigned to the string variable, starting from the character in the current position in the file.
<br><br>
Reads a string of characters from the the current position in the specified file. Functionality is the same as 'gets', except the values are not read from the 'stdin' file but the specified file.

### 'Cleaning' stdin
**stdin**, which stands for standard input, actually denotes a file that contains anything you input. What is the nature of this file? To study this, I have written some programs, whose codes and results will be presented.
<br><br>
**Code 1**:<br>

```
char c;
scanf("%c", &c);
    do
    {   
        c = fgetc(stdin);
        putchar(c);
    } 
    while(c != 10 && c != -1);
```

This code is designed to retrieve and display every character in the **stdin** file, until a newline character or the end of file character is reached. This works like the getchar function.