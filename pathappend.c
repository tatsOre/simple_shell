#include "simple_shell.h"

/**
 * path_append - Append program or command to the path
 * @path: PATH directory
 * @cmd: program file or command
 * Return: pointer to a PATH newly string or NULL on failure
 */

char *path_append(char *path, char *cmd)
{
	int len_path = 0, len_cmd = 0;
	char *full_path;

	if (path == NULL)
		path = "";
	if (cmd == NULL)
		cmd = "";
	full_path = malloc(((_strlen(path) + _strlen(cmd)) * sizeof(char)) + 2);
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

	while (cmd[len_cmd])
	{
		full_path[len_path + len_cmd] = cmd[len_cmd];
		len_cmd++;
	}
	full_path[len_path + len_cmd] = '\0';
	free_function(1, cmd);
	return (full_path);
}
