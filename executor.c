#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "executor.h"

/**
 * execute_command - Executes a given command using execve
 * @command: The command to execute
 */
void execute_command(char *command)
{
	pid_t pid;
	int status;
	char *argv[2];
	char *envp[] = {NULL};

	/* Prepare arguments */
	argv[0] = command;
	argv[1] = NULL;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return;
	}
	if (pid == 0)
	{
		/* In child process */
		if (execve(command, argv, envp) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* In parent process */
		if (waitpid(pid, &status, 0) == -1)
		{
			perror("waitpid");
		}
	}
}
