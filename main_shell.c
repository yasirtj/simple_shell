#include "header_shell.h"

/**
 * main - shell starting point
 * Return: Success
*/

int main(void)
{
	char *line = NULL;
	char *command = NULL, *delimeter = " ";
	size_t size = 0;
	char **tokens;
	(void)tokens;
    size_t len = 0;
    int read_bytes;

	display();
    for (;;)
    {
			our_print("shell$ ");
			read_bytes = getline(&line, &len, stdin);

			if (read_bytes == -1)
			{
					our_print("\n");
					our_exit(1, "An error occured!\n");
					free(line);
			}
		}

	our_read(command, size);
	tokens = cmd_tokenizer(command, delimeter);
	/* execute_cmd(tokens); */
/* 	free(command); */
	return (0);
}
