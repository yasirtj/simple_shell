#include "header_shell.h"


/**
 * execute_prompt - executes command entered by user
 * @command: command entered by user
 * @arguments: command arguments
 * Return: Success
*/

void execute_prompt(const char *command, char *const arguments[])
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		our_exit(1, "process creation failed!");
	}
	else if (child_pid == 0)
	{
		if (execve(command, (const char *const *)arguments, NULL) == -1)
		{
			our_exit(127, "command not found");
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
