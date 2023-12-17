#include "shell.h"

/**
 * _getenv - Get the value of an environment variable.
 * @variable: The name of the environment variable.
 * This function searches the environment variables for the specified
 * variable and returns its value. If the variable is not found, it
 * returns NULL.
 * Return: The value of the environment variable or NULL if not found.
 */

char *_getenv(char *variable)
{
	char *tmp, *key, *value, *env;
	int i;
	for (i = 0; environ[i]; i++)
	{
		tmp = custom_strdup(environ[i]);
		key = strtok(tmp, "=");
		if (custom_strcmp(key, variable) == 0)
		{
			value = strtok(NULL, "\n");
			env = custom_strdup(value);
			free(tmp);
			return (env);
		}
		free(tmp);
		tmp = NULL;
	}
	return (NULL);
}

