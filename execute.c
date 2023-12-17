#include "shell.h"

/**
 * custom_execute - Execute a command.
 * @command: An array of strings representing the command and its arguments.
 * @argv: An array of strings representing the command-line arguments.
 * Return: The exit status of the command.
 */

int custom_execute(char **command, char **argv, int idx);

int custom_execute(char **command, char **argv, int idx)
{
	char *full_cmd;
	pid_t child;
	int status;

	full_cmd = _getpath(command[0]);
	if (!full_cmd)
	{
		print_error(argv[0], command[0], idx);
		freearray(command);
		return (127);
	}
	child = fork();
	if (child == 0)
	{
		if (execve(command[0], command, environ) == -1)
		{
			perror(argv[0]);
			freearray(command);
			exit(0);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		freearray(command);
	}
	return (WEXITSTATUS(status));
}


