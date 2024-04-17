#include "simple_shell.h"

/**
 * main - Entry point of the simple shell
 *
 * Return: Always returns 0
 */
int main(void)
{
    char *line;
    char **args;
    int status;

    do {
        printf("$ ");
        line = read_line();
        args = parse_line(line);
        status = execute_command(args);

        free(line);
        free(args);
    } while (status);

    return (EXIT_SUCCESS);
}
