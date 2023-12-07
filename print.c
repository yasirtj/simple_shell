#include "header_shell.h"

/**
 * our_print - prints to the STDOUT stream
 * @myprintfuntion: command or function
 * Return: nothing
*/

void our_print(const char *myprintfuntion)
	{
	write(STDOUT_FILENO, myprintfuntion, strlen(myprintfuntion));
		{
			write(1, &myprintfuntion, strlen(myprintfuntion));
		}
}
