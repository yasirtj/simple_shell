#include "header_shell.h"

/**
 * exit - exits current execution
 * @status_code: status code
 * @error_msg :error message
 * Return: Success
*/

void exit(int status_code, const char * error_msg)
{
	if (error_msg != NULL)
	{
		    write(STDOUT_FILENO, error_msg, strlen(error_msg));
	}
	exit(status_code, error_msg);
}
