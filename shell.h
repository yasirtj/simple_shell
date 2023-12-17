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

char *read_input(void);

char *custom_strdup(const char *str);
int custom_strcmp(char *s1, char *s2);
int custom_strlen(char *s);
char *custom_strcat(char *dest, char *src);
char *custom_strcpy(char *dest, char *src);

char **tokenizer(char *line);

int custom_execute(char **command, char **argv);
void freearray(char **arr);


#endif

