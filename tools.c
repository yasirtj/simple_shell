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

/**
 * print_error - Print an error message to standard error.
 * @name: The name of the program or function generating the error.
 * @cmd: The specific command or item related to the error.
 * @idx: An index or numerical identifier associated with the error.
 *
 * This function prints a formatted error message to the standard error stream.
 * It includes information about the program or function name, the specific
 * command or item causing the error, and an index or numerical identifier
 * associated with the error. The error message is constructed and written to
 * standard error using the `write` system call. Additionally, memory allocated
 * for the index is freed before returning.
 *
 * Return: None.
 */

void print_error(char *name, char *cmd, int idx)
{
	char *index, mssg[] = ": not found\n";
	index = _itoa(idx);
	write(STDERR_FILENO, name, custom_strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, custom_strlen(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, custom_strlen(cmd));
	write(STDERR_FILENO, mssg, custom_strlen(mssg));
	free(index);
}
/**
 * _itoa - Convert an integer to a string.
 * @n: The integer to be converted.
 *
 * This function takes an integer and converts it into a string representation.
 * The resulting string is dynamically allocated and should be freed by the
 * caller when it is no longer needed.
 *
 * Return: A dynamically allocated string,
 * containing the integer representation,
 * or NULL on failure.
 */
char *_itoa(int n)
{
	char buffer[20];
	int i = 0;
	if (n == 0)
	{
		buffer[i++] = '0';
	}
	else
	{
		while (n > 0)
		{
			buffer[i++] = (n % 10) + '0';
			n /= 10;
		}
	}
	i++;
	buffer[i] = '0';
	reverse_string(buffer, i);
	return (custom_strdup(buffer));
}
/**
 * reverse_string - Reverse the characters in a string.
 * @str: The string to be reversed.
 * @len: The length of the string.
 * This function takes string,reverses the order of its characters in place.
 * swapping characters until the entire string is reversed.
 *
 * Return: None.
 */
void reverse_string(char *str, int len)
{
	char tmp;
	int start = 0;
	int end = len - 1;
	while (start < end)
	{
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		end--;
	}
}

