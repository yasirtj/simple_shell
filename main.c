#include "shell.h"

/**
 * main - Simple shell main function
 * @ac: Count of arguments
 * @argv: Arguments
 * Return: 0 always (success).
 */

int main(int ac, char **argv)
{
	char *line = NULL;
	char **command = NULL;
	int status = 0;
	int idx = 0;
	(void) ac;
	(void) argv;
	while (1)
	{
		line = read_input();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
			{
				write(STDOUT_FILENO, "\n", 1);
			}
			return(status);
		}
		idx++;
		command = tokenizer(line);
		if (!command)
			continue;
		status = custom_execute(command, argv, idx);
	
	}
}
