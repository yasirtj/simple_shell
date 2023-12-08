#include "header_shell.h"


/**
 * execute_prompt - executes command entered by user
 * @command: command entered by user
 * @arguments: command arguments
 * Return: Success
*/

/* void execute_prompt(const char *command, char **arguments[])
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		our_exit(1, "process creation failed!");
	}
	else if (child_pid == 0)
	{
		if (execve(command, *arguments, NULL) == -1)
		{
			our_exit(127, "command not found");
		}
		else
		{
			wait(NULL);
		}
	}
} */

/**
 * execute_cmd - Executes the command
 * @arg_vector: null terminated array of string that holds the command
 * Return: nothing
**/

/*void execute_cmd(char **arg_vector)
{
	char *cmd = NULL;

	if (arg_vector != NULL)
	{
		cmd = arg_vector[0];
	if (execve(cmd, arg_vector, NULL) == -1)
	{
		our_exit(127, "command not found!");
		};
	}
}*/
void excute_cmd(char *line, char **arr)
{
	pid_t id;
	id = fork();
	if(id == 0)
	{
		execve(line, arr, NULL);
	}
	else{
		wait(NULL);
	}
}

/**
 * main - main function
 * Return: Success
*/

/* int main(void)
{
	char *command = NULL;
	const char *command = "executable path";
	const char **arguments[] = {"executable path", "arg1", "arg2", NULL};

	execute_cmd(arguments);
	return (0);
} */
