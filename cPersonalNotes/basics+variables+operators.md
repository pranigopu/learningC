# Basics, variables \& operators
## Basic definitions
- **Identifier** is the symbolic name given to a variable, function or data structure..
- **Variable** is a memory location, connected to an identifier, that stores a known or unknown quantity of information termed as a value that can be altered to some degree.
- **Constant** is a particular unit of data, and cannot hold any other data. For examples:
	- 1 cannot be 2
	- a’ cannot be ‘b’
- **Code block** is a section of code treated as a separate unit wherein the variables declared outside the block remain declared inside the block but the variables declared inside the block become undeclared outside the block.

## More on variables
### Features of a variable
- **Storage**: the location in which a variable is stored
- **Default initial value**: the value a variable holds before it is initialised or assigned a value.
- **Scope**: the extent to which a declared variable remains declared.
- **Life**: the extent to which a defined variable retains its value.

### Storage classes for variables
A storage class is the way in which storage of a variable occurs. There are 4 storage classes:

#### Automatic storage
Default storage method

- **Storage**: memory
- **Default initial value**: garbage value
- **Scope**: the block in which the variable is declared
- **Life**: while control remains within the function in which the variable is defined

### Register storage
Store using “register” keyword before the declaration keyword, as in

```
register int k;
```

It allows for quicker access of variables. It is less optimal for storing many variables, since CPU registers are scarce and can be needed by many other processes.

- **Storage**: the central processing unit’s registers
- **Default initial value**: garbage value
- **Scope**: the block in which the variable is declared
- **Life**: while control remains within the function in which the variable is defined

#### Static storage
Store using “static” keyword before the declaration keyword, as in

```
static int k;
```

- **Storage**: memory
- **Default initial value**: zero
- **Scope**: the block in which the variable is declared
- **Life**: value persists between different function calls from the same function.

#### External storage
Two methods of declaring external storage variables. The first is to declare outside every function in a program’s code. This makes the variable globally available to all the code in the source file.

```
int k;
int main(){...}
```
 The second is to declare using “extern” keyword before the declaration keyword. This is used when a variable is defined in another source file (that has been included within the current source file) and needs to be declared within the current source file. Note that this is not necessary from a code execution point of view. Rather, this method is used to increase code readability by informing the person reading the current source files about the variables that are defined elsewhere.

```
extern int k;
```

- **Storage**: memory
- **Default initial value**: zero
- **Scope**: the whole program
- **Life**: value persists throughout the program’s execution.

## Some unique operators

### Address operator
This is denoted by \&  preceding a variable without space. Its operations:

- Retrieving the memory address of the variable
- Creating a memory address for the variable if no address exists