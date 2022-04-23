# MISCELLANEOUS NOTES

## Formatted scan function, and the need to pass pointers
The formatted scan function, scanf, is used to assign an input to a variable. If we simply pass the variable as an argument, we will only be sending its value, which will be assigned to a temporary new address for the function's execution. Hence, to allow the function to change the value in the specific address of the variable, you naturally pass its pointer, generally using a reference operator (& prefixed to the variable).

## Array identifier
Unlike regular variable identifiers, an array identifier is in fact a pointer that points to the address of the first index in the array. Note that an array is a data structure that occupies a contiguous memory space with equal sized divisions (the size of each division depends on the data type). Hence, a string identifier is also a pointer (to the address of the first character of the string) since a string in C is simply an array of characters that ends with a null character ('\0'). This is why in formatted scan function scanf, we don't use the reference operator \& (used as a prefix) (that, when used for a variable, returns the variable's address).

## Arrow key inputs
Arrow keys translate to a sequence of characters as follows:

- ESC 
- \[
- A (up), B (down), C (right) or D (left)

The escape character ESC appears on the terminal by ^\[.
You can reference  ESC by its ASCII value 27.

## Changing cursor position on console
You can change the cursor position in C by entering the following arguments in the ‘printf’ command:

```
%c[%d;%df”, 27, y, x
```

The set of arguments is what moves the cursor position, a the other arguments before and after it get printed accordingly. Examples of usage:

```
printf("%c[%d;%df", 27, y, x);
printf("%c[%d;%df", 27, 10, 30);
printf("\nHello %c[%d;%df World", 27, y, x);
```