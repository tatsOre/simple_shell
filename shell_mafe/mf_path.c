#include "holberton.h"

/**
  * find_path - finds the PATH variable in the environment
  * @name: the name to look for PATH
  * Return: the string containing the whole PATH variable
  */
char *findpath(char *name)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strcmp(environ[i], name) == 0)
			break;
		else if (environ[i + 1] == NULL)
			perror("find path");
	}
	
	return (environ[i]);
}
