#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

void display(void);
void read(char *command, size_t size);
void our_print(const char *myprintfuntion);
char **cmd_tokenizer(char *string, char *delimeter);
void execute_prompt(const char *command, const char *const arguments[]);

void exit(int status_code, const char * error_msg);

#endif
