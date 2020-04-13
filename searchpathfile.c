#include "simple_shell.h"

/**
  * getpathfile - Searches in an environment variable for a progr file path,
  * stores subdirs in an array, and validate if the prog file path is available
  * @args: user input array arguments
  * Return: 0 on success, -1 on failure
  */
int getpathfile(char **args)
{
	int index = 0;
	char **directories = malloc(sizeof(char *) * BUFFSIZE);
	char *path, *path_var;

	path = _strdup(_getenv("PATH"));

	if (path == NULL || directories == NULL)
	{
		free_function(1, path);
		return (-1);
	}

	path_var = strtok(path, "=:");

	while (path_var != NULL)
	{
		directories[index] = _strdup(path_var);

		if (directories[index] == NULL)
		{
			free_function(1, path);
			free_function(2, directories);
			return (-1);
		}

		path_var = strtok(NULL, "=:");
		index++;
	}

	directories[index] = path_var;

	if (searchdir(directories, args) == -1)
	{
		free_function(1, path);
		return (-1);
	}

	free_function(1, path);

	return (0);
}
