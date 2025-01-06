#include "header.h"

/**
 * main - Entry point of the shell
 *
 * Return: Always 0 (Success)
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
			break;

		execute_command(line);
		free(line);
	}
	return (0);
}

void display_prompt(void)
{
	printf("myshell$ ");
	fflush(stdout);
}

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

void strip_newline(char *line)
{
	line[strcspn(line, "\n")] = '\0';
}

int handle_exit(char *line)
{
	if (strcmp(line, "exit") == 0)
	{
		printf("Goodbye!\n");
		return (1);
	}
	return (0);
}
