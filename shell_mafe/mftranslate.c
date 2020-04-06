#include "holberton.h"

/**
  * translate - traduces args[0] and checks to see which function to send
  * @args: arguments
  * Return: nothing, void
  */
int translate(char **args)
{
	struct stat sb;

	if (searchbuiltin(args) == 0)
		return (0);
	searching(args);
	if (stat(args[0], &sb) == -1)
		return (-1);

	if (stat(args[0], &sb) == 0 && S_ISREG(sb.st_mode) == 0)
		return (-1);
	if (execute(args) == -1)
		return (-1);
	return (0);
}

/**
  * free_function - frees malloc'd spaces based on what number is passed
  * @n: signifies whether to free a single pointer or double pointer
  * Return: nothing, void
  */
void free_function(int n, ...)
{
	char **ptr2;
	char *ptr1;
	va_list valist;
	int i;

	va_start(valist, n);
	if (n == 1)
	{
		ptr1 = va_arg(valist, char *);
		if (ptr1 == NULL)
			return;
		free(ptr1);
	}
	if (n == 2)
	{
		ptr2 = va_arg(valist, char **);
		if (ptr2 == NULL)
			return;
		for (i = 0; ptr2[i] != NULL; i++)
			free(ptr2[i]);
		free(ptr2);
	}
	va_end(valist);
}

/**
  * errmess - prints an error message "not found"
  *
  * @argv: the list of pointers to argument variables
  * @args: the arguments collected by getline
  *@loops: the number of times the infinite loop has been executed
  *
  *Return: nothing, void
  */
void errmess(char **argv, char **args, int loops) /*mfshell*/
{
	char *space = ": ";
	char *err1 = "not found";

	write(STDERR_FILENO, argv[0], strlen(argv[0]));
	write(STDERR_FILENO, space, strlen(space));
	printfnum(loops);
	write(STDERR_FILENO, space, strlen(space));
	write(STDERR_FILENO, args[0], strlen(args[0]));
	write(STDERR_FILENO, space, strlen(space));
	write(STDERR_FILENO, err1, strlen(err1));
	write(STDERR_FILENO, "\n", 1);
}

/**
  * printfnum - prints numbers using write
  * @loops: The integer to print
  * Return: nothing, void
  */

void printfnum(int loops)
{
	int i;
	unsigned int n;
	char num;

	n = loops;
	i = 1;
	while ((n / i) > 9)
		i *= 10;
	while (i >= 1)
	{
		num = ((n / i) % 10) + '0';
		write(STDERR_FILENO, &num, 1);
		i /= 10;
	}
}
