#include "main.h"

/**
 * main - reads line
 * @ac: number of items in av
 * @av: null terminated string of string
 * Return: Success
**/
int main(int ac, char **av);

int main(int ac, char **av)
{
	char *buffer = NULL, *buffer_copy = NULL;
	int chars_read, i = 0;
	size_t buffer_length = 0;
	const char *delim = " \n";
	int number_of_tokens = 0;
	char *token;

	(void)ac;
	printf("$ ");
	chars_read = getline(&buffer, &buffer_length, stdin);
	buffer_copy = malloc(sizeof(char) * chars_read);

	if (buffer_copy == NULL)
	{
		perror("memory allocation error");
		return (-1);
	}
	strcpy(buffer_copy, buffer);
	if (chars_read == -1)
	{
		perror("Exiting..");
		exit(EXIT_FAILURE);
	}
	else
	{
		token = strtok(buffer, delim);

		while (token != NULL)
		{
			number_of_tokens++;
			token = strtok(NULL, delim);
		}
		number_of_tokens++;
		av = malloc(sizeof(char *) * number_of_tokens);

		token = strtok(buffer_copy, delim);
		for (i = 0; token != NULL; i++)
		{
			av[i] = malloc(sizeof(char) * strlen(token));
			strcpy(av[i], token);
			token = strtok(NULL, delim);
		}

		av[i] = NULL;

		free(buffer);
		free(av);
		free(buffer_copy);
	}

	return (0);
}
