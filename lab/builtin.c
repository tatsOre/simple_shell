#include "simple_shell.h"

/**
  * init_builtin - Init built-in functions
  * @args: user input array arguments
  * @buffer: getline malloc'd user input
  * Return: 0 on exit, 1 to continue with the program
  */
int init_builtin(char **args, char *buffer)
{
	if (_strcmp(args[0], "env") == 0)
	{
		shb_env();
		free_function(1, buffer), free_function(2, args);
		return (1);
	}
	else if (_strcmp(args[0], "exit") == 0)
		shb_exit(args, buffer);

	else if (_strcmp(args[0], "cd") == 0)
	{
		shb_cd(args);
		free_function(1, buffer), free_function(2, args);
		return (1);
	}
	return (0);
}

/**
  * shb_exit - Function that exits the Simple Shell
  * @args: user input array arguments
  * args[1] is the number to exit   * READ ABOUT exit -1 *
  * @buffer: getline malloc'd user input
  * Return: Nothing
  */
int shb_exit(char **args, char *buffer)
{
	int status = 0;

	if (args[1] != NULL)
	{
		status = _atoi(args[1]);
	}
	if (status == -1)
	{
		return (-1);
	}
	else
	{
		free_function(1, buffer), free_function(2, args);
		exit(status);
	}
}

/**
  * shb_env - Prints the global environment variable
  * Return: Nothing
  */
void shb_env(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	};
}


/**
  * shb_cd - Change directory according argument
  * @args: user input array arguments  * HANDLE ERRORS *
  * Return: Nothing
  */
void shb_cd(char **args)
{
	char *home = _getenv("HOME");
	char *previous = _getenv("OLDPWD");

	if ((args[1] == NULL && home) || (args[1][0] == '~' && home))
	{
		chdir(home);
	}
	else if (args[1][0] == '-' && previous)
	{
		chdir(previous); /* this does not work properly */
	}
	else if (chdir(args[1]) != 0)
	{
		perror("hsh"); /* if directory does not exist */
	}
}

/**
 * sighandle - This program allows ctrl+C to be
 * printed and new line with enter is pressed
 * @sign: int
 * Return: void
 */
void sighandle(int sign)
{
	if (sign == SIGINT)
		write(STDOUT_FILENO, "\n$ ", 3);
}
