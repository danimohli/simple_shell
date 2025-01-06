#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

/* Function declarations */
void display_prompt(void);
char *read_input(void);
void strip_newline(char *line);
int handle_exit(char *line);

void execute_command(char *command);
void fork_and_execute(char *cmd_path, char *command);
void build_command_path(char *cmd, char **cmd_path);
void error_message(char *command);
void free_resources(char *line, char *cmd_path);
char **get_path_directories(void);
char *find_executable(char *command);
char *join_path(char *dir, char *command);
void free_path_list(char **path_list);
void path_error(char *command);

#endif
