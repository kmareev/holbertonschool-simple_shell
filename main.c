#include "simple_shell.h"

/**
 * main - Entry point of the shell
 * @argc: The number of command-line arguments
 * @argv: An array containing the command-line arguments
 *
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        interactive_mode();
    }
    else if (argc == 2)
    {
        non_interactive_mode(argv[1]);
    }
    else
    {
        fprintf(stderr, "Usage: %s [command]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    return (0);
}
