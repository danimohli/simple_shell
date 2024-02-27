#include "main.h"
/**
 * main - Starting function for others
 * Return: 0 on Successful
 */
int main(void)
{
	while (1)
	{
		/* Display prompt */
		display_prompt();

		/* Read, parse, and execute command */
		read_parse_execute();
	}
	return (0);
}
