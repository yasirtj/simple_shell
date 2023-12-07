#include "header_shell.h"

/**
 * our_read - read input from user
 * @command: comman entered by user
 * @cmd_string_size: size of the command string
 * Return: Success
*/

void our_read(char *command, size_t cmd_string_size)
{
	size_t i;
	int newline_found = 0;


	if (getline(&command, &cmd_string_size, stdin) == -1)
	{
		our_exit(1, "An error occured!\n");
	}
	for (i = 0; i < cmd_string_size && !newline_found; i++)
	{
		if (command[i] == '\n')
		{
			command[i] = '\0';
			newline_found = 1;
		}
		free(command);
	}
}

/**
 * main - test read input
 * Return: Success
*/
/* int main(void)
{
	char *command = NULL;
	size_t size = 0;

	read(command, size);
	free(command);
	return (0);
}*/
