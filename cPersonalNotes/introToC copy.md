# Introduction to programming in C

## Types of programming languages
**High-level**:<br>
 Such a programming language has a high degree of abstraction, i.e. significant parts of the computer system's processing of the language is automated since multiple processes are condensed in fewer statements. Its features:
 
- Often uses natural language elements e.g. English words and phrases.
- Requires more memory to run because many subroutines must be stored to enable the automation of processes.
- Always requires a compiler or an interpreter to convert the source code to machine code.
- More portable, i.e. can be run on different systems, because it does not closely map to any particular machine's processor instructions.

**Low-level**:<br>
Such a programming language has relatively less or no abstraction. This means that commands in a low-level language closely map to processor instructions. Its features:

- Numerous technical details, because more precise and elaborate instructions must be given to run a program.
- Contains relatively little or no natural language elements.
- An interpreter may be more suitable, or maybe a relatively simple compiler, since lesser conversion is required.
- Less portable, i.e. cannot be run on sufficiently different systems, because it closely maps to a particular kind of machine's processor instructions.

It must be noted that the words 'high' and 'low' are relative, i.e. they refer to the relative level of abstraction present between the programming language's codes and the machine's processes.

## History of C

The C programming language was developed by Dennis Ritchie to make the utilities of the Unix operating system at the Bell Laboratories of AT&T in USA in the year 1972. C started as an improvement of the language B, which was also created with the purpose of making utilities for Unix.
<br><br>
While Unix was initially implemented in assembly code, C was extensively used to implement the kernel of the Unix OS around a year after C was created, hence making that version of Unix the first OS to be implemented in a high-level language.
<br><br>
By 1978, C was further developed by Brian Kernighan and Ritchie, and this version of C was laid out in their book "The C programming language". Among the introduced features were:

- The standard input/output library, containing functions to perform input and output processes.
- The 'long integer' and 'unsigned integer' data types.
- Changes to compound assignment operators i.e. operators of the form '=<operator>', which were changed to the current form '<operator>='. This was done to avoid misinterpretation of the right-hand side when the negative sign was used.

C was eventually standardised and revised multiple times by organisations such as ANSI and ISO to bring it to its current version.

## Importance and applications of C

C is particularly effective because while it is sufficiently high-level to be portable, it also has only a thin layer of abstraction and hence, has many assembly language features, such as close mapping to processor instructions (though not as close as assembly languages themselves) and memory allocation. Hence, it can be used to create applications, but due to the availability of system-specific codes which can be used to access specific hardware addresses, system software can be efficiently implemented in C. 
<br><br>
Hence, the applications of C are diverse and numerous.
- Many compilers are written in C, since compilers need to convert source code to system-specific code, which C facilitates, to ultimately create an object code. 
- Many operating systems and utilities are implemented using C.
- Due to low abstraction, memory footprint and hence low run-time demand on system resources, C is often used to implement algorithms and data structures such as MATLAB and GNU Scientific Library respectively.
- C is used for embedded systems.

C is significant in that many later programming languages were influenced by C, particularly in terms of syntax, even when the type systems and program structures were very different, such as for object-oriented programming languages.