/* main.c */
#include "shell.h"

/**
 * display_prompt - Displays the shell prompt.
 */
void display_prompt(void)
{
	printf("myshell$ ");
	fflush(stdout);
}

/**
 * read_input - Reads a line of input from the user.
 *
 * Return: Pointer to the input string, or NULL on EOF.
 */
char *read_input(void)
{
	char *line = NULL;
	size_t len = 0;

	if (getline(&line, &len, stdin) == -1)
	{
		free(line);
		printf("\nExiting shell...\n");
		return (NULL);
	}
	return (line);
}

/**
 * strip_newline - Removes the newline character from the input.
 * @line: The input string.
 */
void strip_newline(char *line)
{
	line[strcspn(line, "\n")] = '\0';
}

/**
 * handle_exit - Handles the "exit" command.
 * @line: The input string.
 *
 * Return: 1 if the command is "exit", 0 otherwise.
 */
int handle_exit(char *line)
{
	if (strcmp(line, "exit") == 0)
	{
		printf("Goodbye!\n");
		return (1);
	}
	return (0);
}

/**
 * main - Entry point of the shell program.
 *
 * Return: Always 0.
 */
int main(void)
{
	char *line;

	while (1)
	{
		display_prompt();
		line = read_input();

		if (!line)
			break;

		strip_newline(line);

		if (handle_exit(line))
		{
			free(line);
			break;
		}

		execute_command(line);
		free(line);
	}
	return (0);
}
