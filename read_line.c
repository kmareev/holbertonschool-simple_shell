#include "simple_shell.h"

/**
 * read_line - Reads a line of input from the user
 *
 * Return: The line of input as a string
 */
char *read_line(void)
{
	char *line = NULL;
	ssize_t line_size = 0;

	if (getline(&line, &line_size, stdin) == -1)
	{
		if (feof(stdin))
		{
			free(line);
			return (NULL);
		}
		else
		{
			perror("getline");
			free(line);
			return (NULL);
		}
	}
	return (line);
}
