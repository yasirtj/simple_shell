#include "shell_header.h"

/**
 * tokenize_cmd - parses and tokenizes user input
 * @string: user input
 * @delimeter: a delimeter
 * Return: pointer to pointer to null-terminated array of strings
 * which represents parsed user input
 */

char **tokenize_cmd(char *string, char *delimeter)
{
	char *generated_token;
	char **new_tokens;
	char *string_copy = NULL;
	int i = 0, number_of_tokens = 0;

	string_copy = malloc(strlen(string) + 1);
	if (string_copy == NULL)
	{
		custom_exit(1, "Failed to allocate memory!\n");
	}
	strcpy(string_copy, string);
	generated_token = strtok(string, delimeter);
	while (generated_token != NULL)
	{
		number_of_tokens++;
		generated_token = strtok(NULL, delimeter);
	}
	new_tokens = malloc(sizeof(char *) * (number_of_tokens + 1));
	if (new_tokens == NULL)
	{
		custom_exit(1, "Failed to allocate memory for your tokens");
	}
	generated_token = strtok(string_copy, delimeter);
	while (generated_token != NULL)
	{
		new_tokens[i] = malloc(sizeof(char) * (strlen(generated_token) + 1));
		if (new_tokens[i] == NULL)
		{
			custom_exit(1, "Failed to allocate memory for a token");
		}
		strcpy(new_tokens[i], generated_token);
		generated_token = strtok(NULL, delimeter);
		i++;
	}
	new_tokens[i] = NULL;
	free(string_copy);
	return (new_tokens);
}

