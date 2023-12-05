#include "shell.h"
void execute_prompt(const char *command, char *const arguments[])

{
	pid_t child_pid = fork();
	if(child_pid == -1)
	{
		perror("fork");
		exit (EXIT_FAILURE);
	}
	else if(child_pid == 0)
	{
		// In the child process
        if (execve(command, arguments, NULL) == -1)
		{
			perror("execve");
		exit (EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
int main();
{
    const char *command = "executable path";
    
    // Example arguments (replace with your actual arguments)
    char *const arguments[] = {"executable path", "arg1", "arg2", NULL};

    execute_prompt(command, arguments);

    return 0;
}
}