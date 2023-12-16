#include "shell.h"

/**
 * custom_execute - Execute a command.
 * @command: An array of strings representing the command and its arguments.
 * @argv: An array of strings representing the command-line arguments.
 * Return: The exit status of the command.
 */

int custom_execute(char **command, char **argv);

int custom_execute(char **command, char **argv)
{
	pid_t child;
	int status;

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


