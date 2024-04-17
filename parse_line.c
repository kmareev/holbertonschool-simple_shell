#include "simple_shell.h"

/**
 * parse_line - Parses a line of input into tokens
 * @line: The line of input to be parsed
 *
 * Return: An array of tokens (words)
 */
char **parse_line(char *line)
{
	char **tokens = malloc(BUFFER_SIZE * sizeof(char *));
	char *token;
	int position = 0;

	if (!tokens)
	{
		fprintf(stderr, "Allocation error\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, " \n");
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		token = strtok(NULL, " \n");
	}
	tokens[position] = NULL;
	return (tokens);
}
