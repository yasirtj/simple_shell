#include "header_shell.h"

/**
 * exit - the custom exit function
 * Return: void
 */
/* void exit(void)
{
	const char *message = "Exiting the loop with custom exit...\n";
    write(STDOUT_FILENO, message, strlen(message));
}  */

/**
 * display - displays prompt to the user
 * Return: Success
 */
void display(void)
{
    char *line = NULL;
    size_t len = 0;
    int read_bytes;
    for (;;)
    {
			our_print("shell$ ");
			read_bytes = getline(&line, &len, stdin);

			if (read_bytes == -1)
			{
					our_print("\n");
					our_exit(1, "An error occured!\n");
					free(line);
			}
		}
}

/**
 * main - main function
 * Return: void
**/

/* int main(void)
{
    display();

    return (0);
}  */
