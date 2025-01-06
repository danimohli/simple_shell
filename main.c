#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

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
			/* Handle EOF (Ctrl+D) */
			printf("\nExiting shell...\n");
			break;
		}

		/* Remove newline character from the input */
		line[strcspn(line, "\n")] = '\0';

		/* Exit condition */
		if (strcmp(line, "exit") == 0)
		{
			printf("Goodbye!\n");
			break;
		}

		/* For now, just echo the input */
		printf("You typed: %s\n", line);
	}

	free(line);
	return (0);
}
