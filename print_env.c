#include "simple_shell.h"

/**
 * print_env - Prints the environment variables
 *
 * This function prints all environment variables
 *
 * Return: no return
 */
void print_env(void)
{
	int i = 0;
	char *env_var = environ[0];

	while (env_var != NULL)
	{
		printf("%s\n", env_var);
		i++;
		env_var = environ[i];
	}
}
