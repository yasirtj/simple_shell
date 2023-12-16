#include "shell_header.h"

/**
 * main - main function
 * Return: Success
 */

int main(void)
{
	char *user_input = NULL;
	size_t cmd_size;

	cmd_size = 0;

	for (;;)
	{
		if (isatty(STDIN_FILENO))
		{
			view_prompt();
			write(1, "$ ", 2);
		}
		else
		{
			view_prompt();
		}
		user_input = malloc(sizeof(char) * MAX_INPUT_SIZE);

		if (user_input == NULL)
		{
			custom_exit(1, "Failed to allocate memory for user input\n");
		}
		read_user_input(user_input, cmd_size);
		free(user_input);
	}

	return (0);
}

