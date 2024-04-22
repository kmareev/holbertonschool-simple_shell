#include "simple_shell.h"

/**
 * execute_command - Executes a command with its arguments
 * @args: an array of arguments (command and its parameters
 * Return: 1 if successful, otherwise -1
 */
int execute_command(char **args)
{
	pid_t pid;
	struct stat st;
	int i = 0, status = 0, flag = 0;
	char *path_full = NULL, **path_arr = NULL, *env_path = NULL;

	if (stat(args[0], &st) == 0 && strcmp(args[0], "hbtn_ls") != 0)
	{
		path_full = malloc(strlen(args[0]) * sizeof(char *));
		strcpy(path_full, args[0]);
		flag = 1;
		pid = fork();
	}
	else if (getenv("PATH") && strcmp(getenv("PATH"), "") != 0)
	{
		env_path = malloc(strlen(getenv("PATH")) * sizeof(char *));
		strcpy(env_path, getenv("PATH"));
		path_arr = parse_line(env_path, ":");
		if (!env_path || !path_arr)
			perror("malloc");
		while (path_arr[i])
		{
			path_full = malloc((strlen(path_arr[i]) + strlen(args[0]) + 1)
					* sizeof(char *));
			strcpy(path_full, path_arr[i]);
			strcpy(path_full, args[0]);
			strcat(path_full, "/");
			if (stat(path_full, &st) == 0)
			{
				pid = fork();
				flag = 1;
			}
		}
	}
}
