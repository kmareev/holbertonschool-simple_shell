#include "simple_shell.h"
#include <stdlib.h>
#include <unistd.h> 

/* External declaration for environ */
extern char **environ;

/**
 * execute_command - Executes a shell command
 * @command:The command to be executed
 * Return: 1 if successful, otherwise -1
 */
int execute_command(char *command)
{
	pid_t pid;

	if (command == NULL)
	{
		printf("\n");
		exit(EXIT_SUCCESS);
	}
	if (command[strlen(command) - 1] == '\n')
	{
		command[strlen(command) - 1] = '\0';
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		char **argv = malloc(2 * sizeof(char *));
		if (argv == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		argv[0] = command;
		argv[1] = NULL;
		if (execve(command, argv, environ) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
		free(argv);
	}
	else
	{
		int status;
		waitpid(pid, &status, 0);
	}
	return (1);
}
