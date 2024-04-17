#include "simple_shell.h"

/**
 * execute_command - Executes a shell command
 * @command: The command to be executed
 * Return: 1 if successful, otherwise -1
 */
int execute_command(char *command)
{
    if (command == NULL)
    {
        printf("\n");
        exit(EXIT_SUCCESS);
    }
    if (command[strlen(command) - 1] == '\n')
    {
        command[strlen(command) - 1] = '\0';
    }
    pid_t pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        char *argv[] = {command, NULL};
        if (execve(command, argv, environ) == -1)
        {
            perror("execve");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        int status;
        waitpid(pid, &status, 0);
    }
    return 1;
}
