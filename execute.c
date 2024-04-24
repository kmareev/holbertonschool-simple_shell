#include "simple_shell.h"

/**
 * execute - Executes a command if it has executable permissions
 * @argv: Path to the executable file
 * @user_input: Input provided by the user to the shell
 * Return: None
 */
void execute(char *argv[], char *user_input)
{
	int child_status;
	int exit_status;
	pid_t child_pid;
	char *path;
	
	/**
	if (access(argv[0], X_OK) != 0)
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
		free(argv[0]);
		exit(127);
	}
	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Failed to fork\n");
		exit(2);
	}
	else if (child_pid == 0)
	{
		execve(argv[0], argv, environ);
		free(argv[0]);
		exit(0);
	}
	else
	{
		wait(&child_status);
		if (WIFEXITED(child_status))
		{
			exit_status = WEXITSTATUS(child_status);
			if (exit_status != 0)
			{
				free(argv[0]);
				free(user_input);
				exit(2);
			}
		}
	}*/

	if (strcmp(argv[0], "exit") == 0)
	{
		if (argv[1] == NULL)
		{
			free(user_input);
			exit(0);
		}
		else
		{
			fprintf(stderr, "Usage: exit\n");
			free(user_input);
			exit(1);
		}
	}
	else if (strcmp(argv[0], "env") == 0)
	{
		print_env();
		free(user_input);
		return;
	}
	
	path = get_path(argv[0]);
	
	if (path == NULL)
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
		free(user_input);
		exit(127);
	}
	if (access(path, X_OK) != 0)
	{
		fprintf(stderr, "./hsh: 1: %s: Permission denied\n", argv[0]);
		free(user_input);
		exit(126);
	}
	
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Failed to fork\n");
		free(user_input);
		exit(2);
	}
	else if (child_pid == 0)
	{
		execve(path, argv, environ);
		perror("execve");
		free(user_input);
		free(path);
		exit(127);
	}
	else
	{
		wait(&child_status);
		if (WIFEXITED(child_status))
		{
			exit_status = WEXITSTATUS(child_status);
			if (exit_status != 0)
			{
				fprintf(stderr, "./hsh: 1: %s: Exit status %d\n", argv[0], exit_status);
				free(user_input);
				free(path);
				exit(2);
			}
		}
	}
	free(path);
}
