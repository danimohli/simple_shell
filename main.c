#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "executor.h"

/**
 * main - Entry point of the shell
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	while (1)
	{
		/* Display the prompt */
		printf("myshell$ ");
		fflush(stdout);

		/* Read the input line */
		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			printf("\nExiting shell...\n");
			break;
		}

		/* Remove newline character */
		line[strcspn(line, "\n")] = '\0';

		/* Exit condition */
		if (strcmp(line, "exit") == 0)
		{
			printf("Goodbye!\n");
			break;
		}

		/* Execute the command */
		execute_command(line);
	}

	free(line);
	return (0);
}
