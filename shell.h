#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/wait.h>

#define DELIM " \t\n"
extern char **environ;

char *read_line(void);

char *custom_strdup(const char *str);
int custom_strcmp(char *s1, char *s2);
int custom_strlen(char *s);
char *custom_strcat(char *dest, char *src);
char *custom_strcpy(char *dest, char *src);

char **tokenizer(char *line);

int _execute(char **command, char **argv, int idx);
void freearray(char **arr);

char *_getenv(char *variable);

char *_getpath(char *command);

void print_error(char *name, char *cmd, int idx);

char *_itoa(int n);

void reverse_string(char *str, int len);

int is_builtin(char *command);
void handle_builtin(char **command, char **argv, int *status, int idx);
void exit_shell(char **command, char **argv int *status, int idx);
void print_env(char **command, int *status);

int is_positive_number(char *str);
int _itoa(char *str);




#endif

