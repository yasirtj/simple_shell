#include "shell.h"
void our_print(const char *myprintfuntion)
{
	write(STDOUT_FILENO, myprintfuntion, strlen(myprintfuntion));
			{
			write(1, &myprintfuntion, strlen(myprintfuntion));
            }
}