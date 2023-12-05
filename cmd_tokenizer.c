#include "shell.h"
/**
 * cmd_tokenizer - parses and tokenizes command into tokens
 * @string: command
 * @delimeter: delimeter
 * Return: pointer to Null terminated string containing next token
*/
char **cmd_tokenizer(char *string, char *delimeter)
{
	char *cmd_token, *copy_of_string;
	char **array_of_tokens;
	int i, number_of_tokens = 0;

	copy_of_string = strdup(string);
	if (copy_of_string == NULL)
	{
		perror("couldn't duplicate string");
		exit(1);
	}
	cmd_token = strtok(copy_of_string, delimeter);
	while (cmd_token != NULL)
	{
		number_of_tokens++;
		cmd_token = strtok(NULL, delimeter);
	}
	free(copy_of_string);
	array_of_tokens = malloc((number_of_tokens + 1) * sizeof(char *));
	if (array_of_tokens == NULL)
	{
		perror("failed to allocate memory for your command!");
		exit(1);
	}
	cmd_token = strtok(string, delimeter);
	for (i = 0; i < number_of_tokens; i++)
	{
		array_of_tokens[i] = strdup(cmd_token);
		if (array_of_tokens[i] == NULL)
		{
			perror("failed to duplicate string");
			exit(1);
		}
		cmd_token = strtok(NULL, delimeter);
	}
	array_of_tokens[number_of_tokens] = NULL;
	return (array_of_tokens);
}

/**
 * main - main
 * Return: nothing
**/
/* int main(void)
{
	int i;
	char input[] = "ls -l -a";
	char **tokens = cmd_tokenizer(input, " ");

	for (i = 0; tokens[i] != NULL; i++)
	{
		printf("Token %d: %s\n", i + 1, tokens[i]);
		free(tokens[i]);
	}
	free(tokens);
	return (0);
} */
