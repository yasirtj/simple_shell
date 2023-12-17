#include "shell.h"

/**
 * _getpath - Find the full path of a command in the PATH environment.
 * @command: The name of the command.
 *
 * This function searches the directories specified in the PATH environment
 * variable to find the full path of the given command. If the command is
 * found, it returns the full path; otherwise, it returns NULL.
 *
 * Return: The full path of the command or NULL if not found.
 */

char *_getpath(char *command)
{
	char *path_env, *full_cmd, *dir;
	int i;
	struct stat st;
	char *custom_strcopy(char *dest, char *src);
	for (i = 0; command[i]; i++)
	{
		if (command[i] == '/')
		{
			if (stat(command, &st) == 0)
				return (custom_strdup(command));

			return (NULL);
		}
	}
	path_env = _getenv("PATH");
	if (!path_env)
		return (NULL);
	dir = strtok(path_env, ":");
	while (dir)
	{
		full_cmd = malloc(custom_strlen(dir) + custom_strlen(command) + 2);
		if (full_cmd)
		{
			custom_strcopy(full_cmd, dir);
			custom_strcat(full_cmd, "/");
			custom_strcat(full_cmd, command);
			if (stat(full_cmd, &st) == 0)
			{
				free(path_env);
				return (full_cmd);
			}
			free(full_cmd);
			full_cmd = NULL;
			dir = strtok(NULL, ":");
		}
	}
	free(path_env);
	return (NULL);
}

