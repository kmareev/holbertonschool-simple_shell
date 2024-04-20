#include "simple_shell.h"

/**
 * parse_line - Parses a line of input into tokens
 * @line: The line of input to be parsed
 * @delimiter: use to tokenize the string
 *
 * Return: An array of token, with the last element as NULL
 */
char **parse_line(char *line, char *delimiter)
{
	int token_count = 0;
	char *token;
	char **tokens = malloc(strlen(line) * sizeof(char *));

	if (!tokens)
		return (NULL);
	token = strtok(line, delimiter);

	while (token)
	{
		tokens[token_count] = strdup(token);
		if (!tokens[token_count])
		{
			free(token);
			free(tokens[token_count]);
			fprintf(stderr, "Token duplication failed.");
			exit(EXIT_FAILURE);
		}
		token_count++;
		token = strtok(NULL, delimiter);
	}
	free(token);
	tokens[token_count] = NULL;
	return (tokens);
}
