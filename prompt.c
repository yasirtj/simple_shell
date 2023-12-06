#include "shell.h"

/**
 * exit - the custom exit function
 * Return: void
 */
void exit(void)
{
	const char *message = "Exiting the loop with custom exit...\n";
    write(STDOUT_FILENO, message, strlen(message));
}

/**
 * display_prompt - displays prompt to the user
 * Return: Success
 */
void display_prompt(void)
{
    char *line = NULL;
    size_t len = 0;

    for (;;)
    {
        our_print("simp_shell$ ");
        ssize_t read_bytes = getline(&line, &len, stdin);

        if (read_bytes == -1)
        {
            our_print("\n");
            free(line);
            exit();
        }
        free(line);
    }
}
