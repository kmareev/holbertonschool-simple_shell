#include "simple_shell.h"

/**
 * main - Entry point of the simple shell
 *
 * Return: Always returns 0
 */
int main(void)
{
	int turn = 0, i = 0;
	char *line = NULL;
	char **args = NULL;

	while (1)
	{
		line = read_line();
		if (!line)
			break;
		args = parse_line(line, " \n\t");
		free(line);
		if (!args[0])
		{
			for (i = 0; args[i]; i++)
				free(args[i]);
			free(args);
			exit(turn);
		}
		else if (strcmp(args[0], "env") == 0)
		{
			for (i = 0; args[i]; i++)
			free(args[i]);
			free(args);
			print_env();
			continue;
		}
		else if (strcmp(args[0], "exit") == 0 && args[1] == NULL)
		{
			for (i = 0; args[i]; i++)
				free(args[i]);
			free(args);
			exit(turn);
		}
		turn = execute_command(args);

		for (i = 0; args[i]; i++)
			free(args[i]);
		free(args);
	}
	free (line);
	if (turn)
		exit(turn);
	return (0);
}
