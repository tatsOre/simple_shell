#include "simple_shell.h"

/**
 * _strlen - Counts the number of characters in an array of characters
 * @str: string
 * Return: length of the array characters
 */

int _strlen(char *str)
{
	int length = 0;

	while (str[length] != '\0')
		length++;
	return (length);
}

/**
 * _strcmp - Compares the value of chars in two different strings 1 by 1
 * @s1: first string
 * @s2: second string
 * Return: difference between the value in the strings
 */

int _strcmp(char *s1, char *s2)
{
	int ch = 0;

	while ((s1[ch] != '\0' && s2[ch] != '\0') && s1[ch] == s2[ch])
	{
		ch++;
	}
	return (s1[ch] - s2[ch]);
}

/**
 * *_strncmp - Compares two strings up to n bytes
 * @s1: first string
 * @s2: second string
 * @n: number of bytes to compare
 * Return: 0 if both strings are equal, a n or -n if they are not
 */

int _strncmp(char *s1, char *s2, int n)
{
	int difference = 0, index = 0;

	while ((s1[index] != '\0' && s2[index] != '\0') && index < n)
	{
		difference = s1[index] - s2[index];
		if (difference != 0)
			break;
		index++;
	}
	return (difference);
}

/**
 * *_strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * @str: string to duplicate
 * Return: pointer to a new string which is a duplicate of the string,
 * NULL if str = NULL, NULL if insufficient memory was available
 */

char *_strdup(char *str)
{
	int index, length;
	char *new_string;

	length = _strlen(str);

	new_string = malloc((length + 1) * sizeof(char));

	if (new_string == NULL)
		return (NULL);

	for (index = 0 ; index < length ; index++)
	{
		new_string[index] = str[index];
	}
	new_string[index] = '\0';

	return (new_string);
}

/**
  * _atoi - function that convert a string to an integer
  * @s: string to convert
  * Return: number
  */

int _atoi(char *s)
{
	int i, sign;
	unsigned int number;

	i = number = 0;
	sign = 1;
	for (; (!(s[i] >= 48 && s[i] <= 57)) && s[i] != '\0'; i++)
	{
		if (s[i] == 45)
			sign = sign * -1;

	}
	if (s[i] == '\0')
		return (number);
	for (; (s[i] >= 48 && s[i] <= 57) && s[i] != '\0'; i++)
	{
		number = (number * 10) + (s[i] - 48);
	}
	return (number * sign);
}
