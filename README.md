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

Llamar a tu función get_next_line de manera repetida (por ejemplo, usando un
bucle) te permitirá leer el contenido del archivo hacia el que apunta el file descriptor,
línea a línea, hasta el final.

LEER hasta el salto de línea, 
devolver la línea actual,

• Asegúrate de que tu función se comporta adecuadamente cuando lea de un archivo
y cuando lea de stdin.

Ten en cuenta que la línea devuelta debe terminar con el caracter
n, excepto si se ha llegado al final del archivo y esté no termina con un caracter
n.

Añade todas las funciones de ayuda que necesites en el archivo get_next_line_utils.c

• Tu programa debe compilar con el flag -D BUFFER_SIZE=xx. Este flag se utilizará
para determinar el tamaño del buffer de las lecturas de tu get_next_line(). Este
parámetro será modificado por tus evaluadores y por Moulinette para probar tu
programa.

Debemos ser capaces de compilar este proyecto con y sin el flag -D
BUFFER_SIZE, junto a los flags habituales. Puedes elegir el valor por
defecto que prefieras.

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



