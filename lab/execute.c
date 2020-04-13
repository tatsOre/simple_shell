#include "simple_shell.h"

/**
 * execute - Forks a child process and executes a new process
 * @args: user input array arguments
 * Return:  0 or 1 according file program execution
 */
int execute(char **args)
{
	pid_t child_pid;
	int status;

	child_pid = fork();

	if (child_pid < 0)
	{
		perror("Error: ");
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			if (errno == EACCES)
				exit(126);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
	return (0);
}
