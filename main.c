#include "simple_shell.h"

/**
 * main - Entry point of the simple shell
 *
 * Return: Always returns 0
 */
int main(void)
{
	char *user_input = NULL;
	size_t input_length = 0;
	ssize_t input_read = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("$ ");
			fflush(stdout);
		}
		input_read = getline(&user_input, &input_length, stdin);
		if (input_read == EOF)
		{
			free(user_input);
			exit(0);
		}
		if (input_read > 0 && user_input[input_read - 1] == '\n')
		{
			user_input[input_read - 1] = '\0';
		}
		token_input(user_input);
	}
	free(user_input);
	return (0);
}
