#include "header_shell.h"

/**
 * main - shell starting point 
 * Return: Success
*/

int main(void)
{
	char *command = NULL;
	size_t size = 0;

	display();
	read(command, size);
	free(command);
	return (0);
}
