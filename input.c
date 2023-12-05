#include "shell.h"

void read_command(char *command, size_t size)
{
    if (getline(&command, &size, stdin) == -1)
    {
        our_print("Error while reading input.\n");
        exit(EXIT_FAILURE);
    }
    int newline_found = 0;
    for (size_t i = 0; i < size && !newline_found; i++)
    {
        if (command[i] == '\n')
        {
            command[i] = '\0';
            newline_found = 1;
        }
    }
}
int main()
{
    char *command = NULL;
    size_t size = 0;

    read_command(command, size);

    free(command);

    return 0;
}
