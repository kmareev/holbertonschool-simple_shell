#include "simple_shell.h"

/*
 * print_env - Prints the environment
 * @void: void
 * Return: 0 on success
 */
int print_env(void)
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
