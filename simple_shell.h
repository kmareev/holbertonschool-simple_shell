#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdarg.h>
#include <stddef.h>


extern char **environ;

void token_input(char *input);
void execute(char *argv[], char *user_input);
char *get_path(char *cmd);
void print_env(void);

#endif
