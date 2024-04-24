#include "simple_shell.h"

/**
 * get_path - Finds the path to execute a command
 * @command: The command entered by the user
 * Return: return the command if it contains '/', the result of concatenation with PATH
 * or NULL if nothing is found
 */
char *get_path(char *command)
{
	int index = 0;
	char *entry = NULL;
	char *token = NULL;
	char *result = NULL;

	if (strchr(command, '/') != NULL)
		return strdup(command);

	if (getenv("PATH") == NULL || strlen(getenv("PATH")) == 0)
		return (NULL);

	while (environ[index])
	{
		entry = strdup(environ[index]);
		token = strtok(entry, "=");
		if (token && strcmp(token, "PATH") == 0)
		{
			token = strtok(NULL, "=");
			if (token && strcmp(token, "") != 0)
			{
				token = strtok(token, ":");

				while (token)
				{
					result = malloc(strlen(token) + strlen(command) + 2);
					if (result == NULL)
					{
						perror("Memory allocation failed");
						free(entry);
						return (NULL);
					}
					sprintf(result, "%s/%s", token, command);
					if (access(result, X_OK) == 0)
					{
						free(entry);
						return (result);
					}
					free(result);
					token = strtok(NULL, ":");
				}
			}
		}
		free(entry);
		index++;
	}
	return (NULL);
}
