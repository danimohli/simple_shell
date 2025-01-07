#ifndef SHELL_H
#define SHELL_H

/* Standard Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <signal.h>
#include <sys/stat.h>

/* Global Variables */
extern char **environ;

/* Function Prototypes */
void display_prompt(void);
char *read_input(void);
void strip_newline(char *line);
int handle_exit(char *line);
void execute_command(char *command);
char **get_path_directories(void);
char *find_executable(char *command);
void free_path_list(char **path_list);
void fork_and_execute(char *cmd_path, char *command);

#endif /* SHELL_H */
