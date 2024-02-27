#include "main.h"
/**
 * main - The starting function for all function
 * Return: 0 on succesful
 */
int main(void)
{
	ssize_t bytes_read;
	char command[MAX_COMMAND_LENGTH];

	while (1)
	{
		display_prompt();
		bytes_read = read_command(command);
		if (bytes_read == -1)
		{
			perror("read");
			exit(EXIT_FAILURE);
		}
		else if (bytes_read == 0)
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}

		command[strcspn(command, "\n")] = '\0';
		execute_command(command);
	}
	return (0);
}
