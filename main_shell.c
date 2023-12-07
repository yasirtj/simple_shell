#include "header_shell.h"

/**
 * main - shell starting point
 * Return: Success
*/

int main(void)
{
	char *command = NULL, *delimeter = " ";
	size_t size = 0;
	char **tokens;
	(void)tokens;

	display();
	our_read(command, size);
	tokens = cmd_tokenizer(command, delimeter);
	/* execute_cmd(tokens); */
/* 	free(command); */
	return (0);
}
