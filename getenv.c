#include "simple_shell.h"

/**
 * _getenv - Search in environment variable to find a specific variable name
 * @name: environment variable
 * Return: pointer to the corresponding value string
 */
char *_getenv(char *name)
{
	int index = 0;

	while (environ[index])
	{
		if (_strncmp(environ[index], name, _strlen(name)) == 0)
			return (environ[index] + (_strlen(name) + 1));

		++index;
	}
	return (NULL);
}
