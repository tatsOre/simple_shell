#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#define BUFFSIZE 64
#define DELIMITER " \t\r\n\a"
#define  _GNU_SOURCE

#include <stdarg.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

/*global environment variable */
extern char **environ;

int init_fileprogram(char **args);
int init_builtin(char **args, char *buffer, int loops);
int searchdir(char **command, char **args);
int execute(char **args);


/* String Handlers */
int _strlen(char *str);
int _strncmp(char *s1, char *s2, int n);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);

/* Path & Search Handlers */
char *path_append(char *path, char *command);
char *_getenv(char *name);
int getpathfile(char **args);

/* Built-ins Functions */
void shb_env(void);
int shb_exit(char **args, char *buffer, int loops);
void shb_cd(char **args);

/* Simple Shell Handlers */
void sighandle(int sign);
void free_function(int n, ...);
void errmess(char **argv, char **args, int loops);
int countarg(char *buffer);
char **get_tokens(char *buffer);
void printfnum(int num);
int _atoi(char *arg);
int _isdigit(char *number);

#endif /* SIMPLE_SHELL_H */
