#include "main.h"

/**
 * display_prompt - Function to display the shel
 */
void display_prompt(void)
{
	write(STDOUT_FILENO, "myShell> ", 9);
}
/**
 * read_command - Function to read command
 * @command: command
 * Return: len of command
 */
ssize_t read_command(char *command)
{
	return (read(STDIN_FILENO, command, MAX_COMMAND_LENGTH));
}

/**
 * execute_command - Function to execute command
 * @command: execute comm
 */
void execute_command(char *command, char *args[])
{
	int status;
	pid_t pid = fork();

	if (pid < 0)
	{
		/* Fork failed */
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		/* Child process */
		if (execvp(command, args) == -1)
		{
			/* If execlp returns, an error occurred */
			perror("execvp");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* Parent process */
		waitpid(pid, &status, 0);
	}
}
