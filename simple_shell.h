#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

char *read_line(void);
char **parse_line(char *line);
int execute_command(char **args);
void print_env(void);
char *find_executable(char **args);

#endif
