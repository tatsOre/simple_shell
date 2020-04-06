#include "holberton.h"

/**
  * sig_out - checks if the signal was SIGINT, then prints a \n and the prompt
  * @sign: the number of the signal
  * Return: nothing, void
  */
void sig_out(int sign)
{
	if (sign == SIGINT)
		write(STDOUT_FILENO, "\n$ ", 3);
}

/**
  * main - Creates a loop for to receive call functions
  * @argc: argument count
  * @argv: an array of pointers to chars, arguments
  * Return: 0, success, otherwise errors
  */

int main(__attribute__((unused)) int argc, char **argv)
{
	int loops, count;
	char *buffer;
	char **args;
	size_t len;

	loops = 1;

	signal(SIGINT, sig_out);
	while (1)
	{
		buffer = NULL;
		len = 0;
		args = NULL;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "mafe$ ", 6);
		if (getline(&buffer, &len, stdin) == EOF)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(EXIT_FAILURE);
		}
		count = countarg(buffer);
		args = _parser(buffer, count);
		if (_strcmp(args[0], "exit") == 0 &&
				(_strlen(args[0]) == _strlen("exit")))
		{
			if (exitfunc(args, buffer) == -1)
				errmess(argv, args, loops);
		}
		else if (args != NULL && args[0] != NULL)
		{
			if (translate(args) == -1)
				errmess(argv, args, loops);
		}
		free_function(1, buffer);
		free_function(2, args);
	}
	loops++;
	return (0);
}
