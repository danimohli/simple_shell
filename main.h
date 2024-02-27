#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGS 10

void parse_command(char *command, char *args[]);
void read_parse_execute(void);
void display_prompt(void);
ssize_t read_command(char *command);
void execute_command(char *command, char *args[]);

#endif
