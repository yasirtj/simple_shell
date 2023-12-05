#include "shell.h"

/**
 * read_command - read input from user
 * @command: comman entered by user
 * @cmd_string_size: size of the command string
 * Return: Success
*/

void read_command(char *command, size_t cmd_string_size)
{
	size_t i;
	int newline_found = 0;
	char *delimeter = " ";

	display_prompt();
	if (getline(&command, &cmd_string_size, stdin) == -1)
	{
		our_print("Error while reading input.\n");
		exit(1);
	}

	for (i = 0; i < cmd_string_size && !newline_found; i++)
	{
		if (command[i] == '\n')
		{
			command[i] = '\0';
			newline_found = 1;
		}
	}
	cmd_tokenizer(command, delimeter);
}

/**
 * main - test read input
 * Return: Success
*/

int main(void)
{
	char *command = NULL;
	size_t size = 0;

	read_command(command, size);
	free(command);
	return (0);
}
