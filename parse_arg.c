#include "main.h"

/**
 * read_parse_execute - parser execute
 */
void read_parse_execute(void)
{
	char command[MAX_COMMAND_LENGTH];
	char *args[MAX_ARGS + 1];
	ssize_t bytes_read = read_command(command);

	if (bytes_read == -1)
	{
		/* Error reading input */
		perror("read");
		exit(EXIT_FAILURE);
	}
	else if (bytes_read == 0)
	{
		/* End of file condition (Ctrl+D) */
		write(STDOUT_FILENO, "\n", 1);
		exit(EXIT_SUCCESS);
	}

	/* Parse command */
	parse_command(command, args);

	/* Execute command */
	execute_command(args[0], args);
}

/**
 * parse_command - command parser
 * @command: command
 * @args: argument to commands
 */
void parse_command(char *command, char *args[])
{
	char *token;
	int x = 0;

	/* Remove trailing newline character */
	command[strcspn(command, "\n")] = '\0';

	/* Tokenize input to get command and arguments */
	token = strtok(command, " ");

	while (token != NULL && x < MAX_ARGS)
	{
		args[x++] = token;
		token = strtok(NULL, " ");
	}
	args[x] = NULL; /* Null-terminate the argument list */
}


