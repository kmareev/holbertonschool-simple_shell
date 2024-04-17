#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

void display_prompt(void);
char *read_command(void);
int execute_command(char *command);
void interactive_mode(void);
void non_interactive_mode(char *command);

#endif
