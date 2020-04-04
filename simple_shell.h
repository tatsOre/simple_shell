#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#define _GNU_SOURCE
#define DELIMITER " \n"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>

char **_parser(char *line);
int _executer(char **args, char **env);


/* String Handling Functions */
int _strlen(char *str);
char *_strdup(char *str);
int _strncmp(char *s1, char *s2, int n);
int _strcmp(char *s1, char *s2);

/* Handler Functions */
char *path_concat(char *path, char *cmd);

#endif /* SIMPLE_SHELL_H */
