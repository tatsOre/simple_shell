#include "holberton.h"

/**
  * search - pass args to all the search functions
  * @args: contains the commands to search
  * Return: -1 on failure, 0 on success
  */
int searching(char **args)
{
	char **command = NULL;
	int count;
	char *keep;

	keep = strdup(findpath("PATH"));
	if (keep == NULL)
		return (-1);
	count = countarg(keep);
	if (count == -1)
	{
		free_function(1, keep);
		return (-1);
	}
	equal_sign(&keep);
	command = _parser(keep, count);
	if (command == NULL)
	{
		free_function(1, keep);
		return (-1);
	}
	if (searchdir(command, args) == -1)
	{
		free_function(1, keep);
		return (-1);
	}
	free_function(1, keep);
	return (0);
}

/**
  * searchbuiltin - searches the builtins for their functions
  * @args: contains the command to search for
  * Return: 0 on success
  */
int searchbuiltin(char **args)
{
	builtin builtins[] = {
		{"env", print_env},
		{NULL, NULL}
	};

	int i, check;

	check = 0;
	for (i = 0; builtins[i].name != NULL; i++)
	{
		if (_strcmp(builtins[i].name, args[0]) == 0 &&
				strlen(builtins[i].name) == strlen(args[0]))
			check = builtins[i].func();
	}
	if (builtins[i].name == NULL)
		return (-1);
	return (check);
}

/**
  * searchdir - searches directories until a command is found
  * @command: contains pointers to all the directories in the PATH
  * @args: contains the argument to look for
  * Return: -1 on failure, 0 on success
  */
int searchdir(char **command, char **args)
{
	char *cwd;
	int i;
	struct stat sb;

	cwd = getcwd(NULL, 0);
	for (i = 0; command[i] != NULL; i++)
	{
		if (args[0][0] == '/')
			break;
		if (_strcmp(args[0], "./") == 0)
			break;
		chdir(command[i]);
		if (stat(args[0], &sb) == 0)
		{
			args[0] = strconcat(command[i], args[0]);
			if (args[0] == NULL)
			{
				free_function(1, cwd);
				free_function(2, command);
				return (-1);
			}
			break;
		}
	}
	chdir(cwd);
	free_function(1, cwd);
	if (command[i] == NULL)
	{
		free_function(2, command);
		return (-1);
	}
	free_function(2, command);
	return (0);
}
