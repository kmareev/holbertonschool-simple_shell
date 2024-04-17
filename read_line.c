#include "simple_shell.h"

/**
 * read_line - Reads a line of input from the user
 *
 * Return: The line of input as a string
 */
char *read_line(void)
{
    char *line = NULL;
    ssize_t bufsize = 0;
    
    getline(&line, &bufsize, stdin);
    return (line);
}
