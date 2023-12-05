#include "shell.h"

/**
 * execute_prompt - executes command entered by user
 * @command: command entered by user
 * @arguments: command arguments
 * Return: Success
*/

void execute_prompt(const char *command, const char *const arguments[])
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		if (execve(command, arguments, NULL) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}

/**
 * main - main function
 * Return: nothing
*/
int main(void);
{
	const char *command = "executable path";
	char *const arguments[] = {"executable path", "arg1", "arg2", NULL};

	execute_prompt(command, arguments);
	return (0);
}
