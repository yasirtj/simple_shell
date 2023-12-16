
#include "shell.h"

/**
 * tokenizer - Tokenize a string into an array of strings.
 * @input: The input string to tokenize.
 * Return: An array of strings representing the tokens.
 */

char **tokenizer(char *input)
{
char *token = NULL, *tmp = NULL;
char **command = NULL;
int cpt = 0, i = 0;

if (!input)
return (NULL);
tmp = custom_strdup(input);


token = strtok(tmp, DELIM);
if (token == NULL)
{
free(input);
free(tmp);
return (NULL);
}

while (token)
{
cpt++;
token = strtok(NULL, DELIM);
}
free(tmp);
command = malloc(sizeof(char *) * (cpt + 1));
if (!command)
{
free(input);
return (NULL);
}
token = strtok(input, DELIM);
while (token)
{
command[i] = custom_strdup(token);
token = strtok(NULL, DELIM);
i++;
}
free(input);
command[i] = NULL;
return (command);
}
