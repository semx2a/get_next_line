# Get Next Line

![Static Badge](https://img.shields.io/badge/lang-fr-red?labelColor=blue&link=https%3A%2F%2Fgithub.com%2Fsemx2a%2Fget_next_line%2Fblob%2Fmain%2FREADME.fr.md)

## Summary
This project aims to develop the `get_next_line` function, capable of reading lines with a limited buffer size from a file descriptor. This project is written in C.

## Git Repository Contents

- `get_next_line.h`: Header file containing the prototype of the `get_next_line` function.
- `get_next_line.c`: Implementation of the main function.
- `get_next_line_utils.c`: Utility file containing additional functions necessary for the implementation of `get_next_line`.

## Acquired Skills

### C Programming

- Development of a complex function in the C language.
- Adherence to the `42 School` C coding standard to ensure code quality and readability.
- Robust handling of undefined behaviors and error cases.

### Compilation and Makefile

- Makefile to automate the project compilation.
- Use of flags `-Wall`, `-Wextra`, and `-Werror`.
- Use of flags `-g3` and `-fsanitize=address` for debugging.

### Memory Management

- Dynamic memory allocation using `malloc`.
- Freeing memory once operations are completed or in case of errors to prevent leaks.
- Use of `valgrind` to check for residual memory leaks.

### String Handling

- Reading and storing strings.
- Parsing the string to check for the end of a line defined by a newline character `\n` or end of file `EOF`.
- Reuse of the file descriptor to read the file line by line once the function is recalled, returning the remainder of the previous line if a newline is found.

### Static Variables

- Definition of a `BUFFER_SIZE` before compilation to set a constant buffer size.
- Use of a static variable to store the remainder of the previous line if a newline is found.

### File Handling

- Reading lines from a file descriptor.
- Handling various use cases, such as end of file or reading errors.
- Multiple file descriptors handling with a constant array of strings.
