#include "shell.h"

/**
 * read_input - Read a line of input from the user.
 * Return: A pointer to the read line.
 */

char *read_input(void)
{
char *line = NULL;
size_t len = 0;
ssize_t n;
if (isatty(STDIN_FILENO))
{
write(STDOUT_FILENO, "$ ", 2);
}
n = getline(&line, &len, stdin);
if (n == -1)
{
free(line);
if (feof(stdin))
{
return (NULL);
}
else
{
perror("getline");
exit(EXIT_FAILURE);
}
}
return (line);
}

