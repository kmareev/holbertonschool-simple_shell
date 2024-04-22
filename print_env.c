#include "simple_shell.h"

/**
 * print_env - Prints the enivornment variables
 *
 * This function prints all environemnt variables
 *
 * Return: Always return 0.
 */
void print_env(void)
{
	int i = 0;
	char *str = environ[0];

	while (str != NULL)
	{
		printf("%s\n", str);
		i++;
		str = environ[i];
	}
	return (0);
}
