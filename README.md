<!-- TO DO:

1. tests:
https://github.com/kodpe/gnl-station-tester

and mine mains, test.txt

2. leaks:
MAC: leaks --atExit -- ./a.out

Ubuntu:
valgrind --leak-check=full ./a.out
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./your_program
additionally: valgrind --tool=memcheck --leak-check=full --trace-children=yes ./your_program

3. del .txt, readme, a.out...

4. norm

5. check names

6. git add, commit, push

----------------------------------------------------------- -->

# get_next_line

### Task:

Write a function that returns the line read from a file descriptor.

### Function name and prototype:

*get_next_line*

char *get_next_line(int fd);

fd: file descriptor from which to read.

### Return value:

If all goes well: the line that was read.
On failure or if reading ends: NULL.

### Authorised functions:

read, malloc, free.

### Files to present:

get_next_line.c, 
get_next_line_utils.c,
get_next_line.h.


 * Repeated calls (e.g., using a loop) to your get_next_line() function should let you read the text file pointed to by the file descriptor, one line at a time till the end.
 * Your function should return the line that was read. If there is nothing else to read or if an error occurred, it should return NULL.
 * Make sure that your function works as expected both when reading a file and when reading from the standard input (stdin).
 * Please note that the returned line should include the terminating \n character, except if the end of file was reached and does not end with a \n character.
 * Because you will have to read files in get_next_line(), add this option to your compiler call: -D BUFFER_SIZE=n. It will define the buffer size for read(). The buffer size value will be modified in order to test your code.


LEER hasta el salto de línea, 
devolver la línea actual


• El programa se compilará de la siguiente forma (se utiliza como ejemplo un tamaño
de buffer de 42):
cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 <archivos>.c.

• Se considera que get_next_line() tiene un comportamiento indeterminado si el
archivo al que apunta el fd ha cambiado desde la última vez que se llamó, siempre
que read() no haya llegado al final del archivo.

• Se considera que get_next_line() tiene un comportamiento indeterminado cuando
lo que se lee es un archivo binario. Sin embargo, puedes implementar alguna manera
lógica de sortear este problema, si quieres.

1) Tanto el tamaño del buffer como el de la línea pueden tener
valores muy diferentes.
2) Un fd no solo apunta a archivos normales.

CHECKS (mains):
 * NO MEMORY LEAKS valgrind ./
 * ¿Funciona correctamente tu get_next_line si el BUFFER_SIZE es 9999?
	¿Y si es 1? ¿Qué tal con 10000000? ¿Sabes por qué?
 * only 3 NECESSARY files!
 * Norminette


## Static variable

A static variable is a variable with the lifetime for the entire run of the program. In our case, we will work with local static variables. 

It is initialized only once, no matter how many times its function is called, its value is retained and is accessible through many calls to the function in which it is declared. It can be used as a counter, for example.



