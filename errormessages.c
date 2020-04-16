#include "simple_shell.h"

/**
  * errmess - Prints an error message "not found"
  * @argv: argv[0] executable name
  * @args: user input array arguments
  * @loops : times that the loop has been executed
  * Return: Nothing
  */
void errmess(char **argv, char **args, int loops)
{
	char *space = ": ";
	char *err1 = "not found";

	write(STDERR_FILENO, argv[0], _strlen(argv[0]));
	write(STDERR_FILENO, space, _strlen(space));
	printfnum(loops);
	write(STDERR_FILENO, space, _strlen(space));
	write(STDERR_FILENO, args[0], _strlen(args[0]));
	write(STDERR_FILENO, space, _strlen(space));
	write(STDERR_FILENO, err1, _strlen(err1));
	write(STDERR_FILENO, "\n", 1);
}

/**
 * printfnum - prints numbers using write
 * @loops: Times that the loop has been executed
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

/**
 * _isdigit - checks to see if input is a number
 * @number: input to check
 * Return: returns 1 if is digit
 */
int _isdigit(char *number)
{
	int i = 0;

	if (number == NULL)
		return (0);

	while (number[i])
	{
		if (number[i] < 47 || number[i] > 57)
			return (0);
		i++;
	}
	return (1);

}
