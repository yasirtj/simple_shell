#include "shell.h"

/**
 * freearray - Free memory allocated for a 2D array of strings.
 * @array: The 2D array to free.
 * This function frees both the array of pointers and the strings it points to.
 */

void freearray(char **array)
{
	int i;

	if (!array)
		return;

	for (i = 0; array[i]; i++)
	{
		if (array[i])
		{
			free(array[i]);
			array[i] = NULL;
		}
	}
	free(array);
	array = NULL;
}

