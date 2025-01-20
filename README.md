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

