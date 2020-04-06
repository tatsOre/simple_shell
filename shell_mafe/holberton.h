#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdarg.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/**
  * struct built - contains variables with builtin information
  * @name: the name of the builtin
  * @func: the function pointer to the builtin
  */
typedef struct built
{
	char *name;
	int (*func)(void);
} builtin;

extern char **environ; /*The variable environ points to an array of pointers
                        to strings called the "environment"*/

int countarg(char *buffer);
char **_parser(char *buffer, int size);
int exitfunc(char **args, char *buffer);
void errmess(char **argv, char **args, int loops);
int translate(char **args);
void free_function(int n, ...);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
int searchdir(char **command, char **args);
int searchbuiltin(char **args);
int print_env(void);
int execute(char **args);
int searching(char **args);
char *findpath(char *name);
char *strconcat(char *s1, char *s2);
void equal_sign(char **s);
void printfnum(int loops);
void sig_out(int sign);

#endif
