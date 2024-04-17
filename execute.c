#include "simple_shell.h"

/**
 * execute_command - Executes a command with its arguments
 * @args: an array of arguments (command and its parameters)
 * Return: 1 if successful, otherwise -1
 */

int execute_command(char *args)
{
	pid_t pid, wpid;
	int status;

	pid = fork();
	if (pid == 1)
	{
		perror("fork");
		return (-1);
	}
	else if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("execvp");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		do {
			wpid = waitpid(pid, &status, WUNTRACED);
			if (wpid == -1)
			{
				perror("waitpid");
				return (-1);
			}
		}

		while (!WIFEXITED(status) && !WIFSIGNALED(status))
			;
	}

	return (1);
}
