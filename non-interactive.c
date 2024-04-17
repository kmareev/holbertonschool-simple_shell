#include "simple_shell.h"

/**
 * non_interactive_mode - Runs the shell in non-interactive mode
 * @command: The command to be executed
 */
void non_interactive_mode(char *command)
{
    execute_command(command);
}
