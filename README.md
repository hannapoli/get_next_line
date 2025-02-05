# get_next_line ✍️


### 🚀 Task:
---
Write a function that returns the line read from a file descriptor.
___

### 📝 Function name and prototype:

*get_next_line*

`char *get_next_line(int fd);`

fd: a file descriptor from which to read.


### ↩️ Return value:

If all goes well: the line that was read.
On failure or if reading ends: NULL.


### 🛂 Authorised functions:

read, malloc, free.


### 📮 Files to present:

 * get_next_line.c, 
 * get_next_line_utils.c (for the standard string functions),
 * get_next_line.h.
   

### 📝 Details:

 * Repeated calls (e.g., using a loop) to your get_next_line() function should let you read the text file pointed to by the file descriptor, one line at a time till the end.

 * Your function should return the line that was read. If there is nothing else to read or if an error occurred, it should return NULL.
 * Make sure that your function works as expected both when reading a file and when reading from the standard input (stdin).

 * The returned line should include the terminating \n character, except if the end of file was reached and does not end with a \n character.

 * Because you will have to read files in get_next_line(), add this option to your compiler call: -D BUFFER_SIZE=n. It will define the buffer size for read(). The buffer size value will be modified in order to test your code.

 * Both the buffer size and the line size can have very different values.
   

 ### 🌟 Bonus part:

 The function has to be able to handle multiple file descriptors at once. That is, if you have three fds available for reading, you should be able to use get_next_line once on each of them in alternation. It should not lose the reading thread of each of the fds.

 
### ⚙️ Essentials:

#### Static variable

**A static variable** is a variable with the lifetime for the entire run of the program. In our case, we will work with a local static variable. 

It is initialized only once, no matter how many times its function is called, its value is retained and it is accessible through many calls to the function in which it is declared.


#### A File Descriptor: int fd

**fd** is an int variable that identifies an open file.

**Standard file descriptors** are 3 predefined identifiers used in Unix-like operating systems:

 * 0: standard input (stdin), reading user input from the terminal.
 * 1: standard output (stdout), writing to the terminal.
 * 2: standard error (stderr), writing an error to the terminal.
   

### ▶️ Compiling:
`cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 your_files.c.`


### 🔎 Checking leaks:
MAC:

`leaks --atExit -- ./your_program`

Ubuntu:

`valgrind --leak-check=full ./your_program`

`valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./your_program`

`valgrind --tool=memcheck --leak-check=full --trace-children=yes ./your_program`



