#include "simple_shell.h"

/**
 * path_concat - function that concatenates PATH and CMD
 * @path: PATH
 * @command: command to concatenate to PATH
 * Return: pointer to a PATH newly string
 * return NULL on failure
 */

char *path_concat(char *path, char *command)
{
	int len_path = 0, len_cmd = 0;
	char *full_path;

	if (path == NULL)
		path = "";

	if (command == NULL)
		command = "";

	full_path = malloc(((_strlen(path) + _strlen(command)) * sizeof(char)) + 2);

	if (full_path == NULL)
		return (NULL);

	while (path[len_path])
	{
		full_path[len_path] = path[len_path];
		len_path++;
	}

	if (path[len_path - 1] != '/')
	{
		full_path[len_path] = '/';
		len_path++;
	}

	while (command[len_cmd])
	{
		full_path[len_path + len_cmd] = command[len_cmd];
		len_cmd++;
	}

	full_path[len_path + len_cmd] = '\0';

	return (full_path);
}
