# Preprocessor directives & structures
All the following notes are in the context of C unless explicitly stated otherwise

## Basic definitions
Class is a definition to which one or more data objects can belong.

## Preprocessor
### Preprocessor directives
#### define
Provides an alias for a constant or a data structure

**Syntax**:

```
#define alias constant_or_datastructure
```

"alias" is a user-defined identifier.

**Example**:

```
#define ONE 1
#define mil 1000000
#define FL float
#define ca char
```

## Data structures and data types
### Data structures
A data structure is construct containing a defined set of data values, defining the relationships between these data values and determining the functions or operations that can be applied to the data values.
<br><br>
Examples of data structures:
Array, stack, queue, file...

### Data types
The concept of data type is derived from the concept of data structure, with the main difference being that data types define classes of objects, while data structures define a set of particular objects.

#### Abstract data type
An abstract data type is a class of objects defined by 

- a set of values
- a set of operations

An abstract data type is distinct from a data type, in that the former is a conceptual mathematical model that defines data types, while the latter is a definition that can be processed by a computer system.

#### Data type
A data type can be thought of as an implementation (complete or partial) of an abstract data type, in a computer system. The standalone definition is given at the end of this section.
<br><br>
The connection of data types to abstract data types can be seen as follows. Data values such as range and size define a datatype. For example:

- Range of integer datatype: (- 214783648) to (214783647)
- Size of integer datatype: 4

The values belonging to different data types can be subjected to different operations that may not be applicable to values of other data types. For example:

- Arithmetic and relational operations cannot be performed on strings.
- Modulus operator cannot be performed on floating point numbers.

Note, however, that the "set of defining values" and "the set of defining operators" can be used to define a set of properties, explained as follows. 
<br><br>
Different data types have different properties that define what values the objects belonging to the data type can and cannot take. For example:

- The smallest difference between two integers is 1, and if 1 is an integer, an integer cannot take the value 1.24.
- The difference between two floating point numbers can be less than 1, hence a floating point number can be 1.24.

(Note that 1 is a defining value for integers here)
<br><br>
Also, in the context of operations, note that float values cannot be converted to characters, while integers can be.

(Note that conversion from integers to corresponding ASCII values is a defining operation for integers here) <br><br> Note that these properties are determined by the way in which the respective values are stored and retrieved. <br><br>
In other terms, a data type is a set of attributes that inform the compiler or interpreter about the way in which the data values belonging to this data type must be treated.

#### Types of data types
##### Primitive data types
These data types can be one of the following:

- **Basic types**: data types that cannot be composed from other data types, and form the basis of data representation in a programming language.
- **Built-in types**: data types that are provided with definitions and support by the programming language itself.

Examples of basic data types:
int, float, char, string...
<br><br>
(Though a string can usually be considered a composite data type, it is supported as a distinct data type in C, which provides support such as format specifiers for entering whole strings, convenient methods to assign values to strings, built-in functions for comparing strings...)
<br><br>
Note that basic types are almost always value types.
Composite / compound data types
These data types are composed of other data types (which may be composite or primitive).
<br><br>
Composite data types can be user-defined.
<br><br>
(Even primitive data types may be, for some programming languages, but not for C)
Some keywords and their usages
<br><br>
**struct**:<br>
'struct' as in “structure”. This keyword is used for declaring composite data types. It defines a data type that can be used to group items of possibly different data types into a single data type.
<br><br>
A variable assigned to a data type defined through ‘struct’ i.e. a user-defined composite data type can be referred to by a single pointer.
<br><br>
**typedef**:<br>
"typedef" as in type definition.  yntax for declaration:

```
typedef struct identifier;
```