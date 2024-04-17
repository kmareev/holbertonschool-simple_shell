#include "simple_shell.h"

/**
 * interactive_mode - Runs the shell in interactive mode
 */
void interactive_mode(void)
{
    while (1)
    {
        display_prompt();
        char *command = read_command();
        execute_command(command);
        free(command);
    }
}
