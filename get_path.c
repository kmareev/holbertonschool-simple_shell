#include "simple_shell.h"

/**
 * get_path - Finds the path to execute a command
 * @command: The command entered by the user
 * Return: return the command if it contains '/', the result of concatenation with PATH
 * or NULL if nothing is found
 */
char *get_path(char *command)
{
	int i = 0;
	char *token = NULL;
	char *cache;
	char *result = NULL;

	/**
	if (strchr(command, '/') != NULL)
		return strdup(command);

	while (environ[i])
	{
		cache = strdup(environ[i]);
		token = strtok(cache, "=");
		if (strcmp(token, "PATH") == 0)
		{
			token = strtok(NULL, "=");
			if (strcmp(token, "") == 0)
			{
				free(cache);
				return (NULL);
			}
			token = strtok(token, ":");
			while (token)
			{
				result = malloc(strlen(token) + strlen(command) + 2);
				if (result ==  NULL)
				{
					perror("Malloc is NULL");
					free(cache);
					return (NULL);
				}
				sprintf(result, "%s/%s", token, command);
				if (access(result, X_OK) == 0)
				{
					free(cache);
					return (result);
				}
				free(result);
				token = strtok(NULL, ":");
			}
		}
		free(cache);
		i++;
	}
	return (NULL);*/

	if (environ == NULL)
		return (NULL);

	while (environ[i])
	{
		cache = strdup(environ[i]);
		if (cache == NULL)
			return (NULL);

		token = strtok(cache, "=");
		if (token != NULL && strcmp(token, "PATH") == 0)
		{
			token = strtok(NULL, "=");
			if (token != NULL && strcmp(token) > 0)
			{
				token = strtok(token, ":");
				while (token)
				{
					result = malloc(strlen(token) + strlen(command) + 2);
					if (result == NULL)
					{
						perror("Malloc is NULL");
						free(cache);
						return (NULL);
					}
					sprintf(result, "%s/%s", token, command);
					if (access(result, X_OK) == 0)
					{
						free(cache);
						return (result);
					}
					free(result);
					token = strtok(NULL, ":");
				}
			}
			break;
		}
		free(cache);
        	i++;
	}
	return (NULL);
}
