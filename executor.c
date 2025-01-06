#include "header.h"

/* Function definitions */
void execute_command(char *command)
{
	char *cmd_path = find_executable(command);
	if (!cmd_path)
	{
		error_message(command);
		return;
	}
	fork_and_execute(cmd_path, command);
	free(cmd_path);
}

void fork_and_execute(char *cmd_path, char *command)
{
	pid_t pid = fork();
	int status;

	if (pid == -1)
	{
		perror("fork");
		return;
	}
	if (pid == 0)
	{
		char *argv[] = {command, NULL};
		if (execve(cmd_path, argv, environ) == -1)
			perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}

void build_command_path(char *cmd, char **cmd_path)
{
	*cmd_path = strdup(cmd);
}

void error_message(char *command)
{
	fprintf(stderr, "%s: command not found\n", command);
}

void free_resources(char *line, char *cmd_path)
{
	free(line);
	free(cmd_path);
}
