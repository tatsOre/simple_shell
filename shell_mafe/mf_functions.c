#include "holberton.h"

/**
  * exitfunc - exits the shell
  * @args: the arguments getting passed to exit
  * args[1] is the number to exit
  * @buffer: a malloc'd space that needs to free before exit
  * Return: 0 on success
  */
int exitfunc(char **args, char *buffer)
{
	int number;

	number = 0;
	if (args[1] != NULL)
		number = atoi(args[1]);
	if (number == -1)
	{
		return (-1);
	}
	else
	{
		free_function(1, buffer);
		free_function(2, args);
		exit(number);
	}
}

/**
  * print_env - prints the environment
  * Return: 0 on success
  */
int print_env(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}


/**
  * strconcat - concatenate 2 strings in a new string
  * @s1: the first string
  * @s2: the second string
  * Return: The concatenated string
  */
char *strconcat(char *s1, char *s2)
{
	char *strcon;
	int i, j, count;

	j = 0;
	count = strlen(s1) + strlen(s2) + 2;
	strcon = malloc(sizeof(char) * count);
	if (strcon == NULL)
		return (NULL);
	for (i = 0; s1 && s1[i] != '\0'; i++)
	{
		strcon[j] = s1[i];
		j++;
	}
	if (j != 0)
	{
		strcon[j] = '/';
		j++;
	}
	for (i = 0; s2 && s2[i] != '\0'; i++)
	{
		strcon[j] = s2[i];
		j++;
	}
	strcon[j] = '\0';
	free_function(1, s2);
	return (strcon);
}

/**
  * _strcmp - compares the value of chars in two different strings 1 by 1
  * @s1: first string
  * @s2: second string
  * Return: The difference between the value in the strings
  */
int _strcmp(char *s1, char *s2)
{
	int difference, index;

	difference = index = 0;
	if (s1 == NULL || s2 == NULL)
		return (-1);
	while (s1[index] != '\0' && s2[index] != '\0')
	{
		difference = s1[index] - s2[index];
		if (difference != 0)
			break;
		index++;
	}
	return (difference);
}