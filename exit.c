#include "header_shell.h"

/**
 * exit_execution - exits current execution
 * @status_code: status code
 * @error_msg :error message
 * Return: Success
*/

void exit_execution(int status_code, const char *error_msg)
{
	if (error_msg != NULL)
	{
		write(STDOUT_FILENO, error_msg, strlen(error_msg));
	}
	exit(status_code);
}
