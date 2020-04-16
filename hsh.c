#include "simple_shell.h"

/**
 * main - Creates a loop for to receive user call functions, parse the input
 * and check program type to execute a program file if success
 * @argc: number of command line arguments
 * @argv: command line arguments
 * Return: 0, success, otherwise errors
 */
int main(int argc, char **argv)
{
	char *buffer, **args;
	size_t len;
	int loops = 1;
	(void)argc;

	signal(SIGINT, sighandle);

	while (1)
	{
		buffer = NULL, args = NULL;
		len = 0;

		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);

		if (getline(&buffer, &len, stdin) == EOF)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			free(buffer);
			return (0);
		}
		args = get_tokens(buffer);
		if (args != NULL && args[0] != NULL)
		{
			if (init_builtin(args, buffer, loops))
				continue;

			if (init_fileprogram(args) == -1)
				errmess(argv, args, loops);
		}
		free_function(1, buffer);
		free_function(2, args);
		loops++;
	}
	return (0);
}
