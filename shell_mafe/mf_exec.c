#include "holberton.h"

/**
 * execute - Forks a child process and executes a new process
 *
 * @args: A pointer to an array of strings
 *
 * Return: An integer value indicating success or failure.
 */
int execute(char **args)
{
	pid_t child_pid;
	int status;

	child_pid = fork();

	if (child_pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
			exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
	}
	return (0);
}
