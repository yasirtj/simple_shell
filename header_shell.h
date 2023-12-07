#ifndef HEADER_SHELL_H
#define HEADER_SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void display(void);
void our_read(char *command, size_t size);
void read_input(char *command, size_t size);
void our_print(const char *myprintfuntion);
char **cmd_tokenizer(char *string, char *delimeter);
void execute_prompt(const char *command, char const *arguments[]);

void our_exit(int status_code, const char * error_msg);
void exit_execution(int status_code, const char * error_msg);

#endif
