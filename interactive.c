#include "simple_shell.h"

/**
 * interactive_mode - Runs the shell in interactive mode
 */
void interactive_mode(void)
{
	char *command;

	command = read_command();

	while (1)
	{
		execute_command(command);
		free(command);
		command = read_command();
	}
}
