#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#define BUFFSIZE 1024
#define DELIMITER " :\n\t\r"
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

/*global environment variable */
extern char **environ;

int init_fileprogram(char **args);
int init_builtin(char **args, char *buffer);
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
char **getpathdirectory(char *path);

/* Built-ins Functions */
void shb_env(void);
void shb_exit(char **args, char *buffer);

/* Simple Shell Handlers */
void sig_out(int sign);
void sighandle(int sign);
void free_function(int n, ...);
void errmess(char **argv, char **args, int loops);
int countarg(char *buffer);
char **get_tokens(char *buffer);
void printfnum(int num);

#endif /* SIMPLE_SHELL_H */
