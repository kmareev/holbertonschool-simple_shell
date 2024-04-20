#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

extern char **environ;

char *read_line(void);
char **parse_line(char *line, char *delimiter);
int execute_command(char **args);
int print_env(void);
char *find_executable(char **args);

#endif
