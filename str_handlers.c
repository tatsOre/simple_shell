#include "holberton.h"

/**
 * _strlen - returns the length of a string.
 * @str: string input.
 * Return: length of an string.
 */

int _strlen(char *str)
{
	int length = 0;

	while (str[length] != '\0')
		length++;

	return (length);
}

/**
 * *_strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * @str: string to duplicate.
 * Return: pointer to a new string which is a duplicate of the string,
 * NULL if str = NULL, NULL if insufficient memory was available
 */

char *_strdup(char *str)
{
	int i, length;
	char *new_string;

	length = _strlen(str);

	new_string = malloc((length + 1) * sizeof(char));

	if (new_string == NULL)
		return (NULL);

	for (i = 0 ; i < length ; i++)
	{
		new_string[i] = str[i];
	}

	new_string[i] = '\0';

	return (new_string);
}

/**
 * *_strncmp - compares two strings up to n bytes
 * @s1: first string
 * @s2: second string
 * @n: number of bytes to compare
 * Return: 0 if both strings are equal, a n or -n if they are not
 */

int _strncmp(char *s1, char *s2, int n)
{
	int ch = 0;

	while (s1[ch] && s2[ch] && ch < n)
	{
		if (s1[ch] != s2[ch])
		{
			return (s1[ch] - s2[ch]);
		}
		ch++;
	}
	return (0);
}


/**
 * *_strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 * Return: 0 if both strings are equal, a n or -n if they are not
 */

int _strcmp(char *s1, char *s2)
{
	int ch = 0;

	while ((s1[ch] && s2[ch]) && s1[ch] == s2[ch])
		ch++;

	return (s1[ch] - s2[ch]);
}

/**
 * *_strcpy - Copy the string pointed to by src, including null byte (\0),
 * @dest: destination
 * @src: source
 * Return: dest
 */
char *_strcpy(char *dest, char *src)
{
	int length = 0;

	while (src[length] != '\0')
	{
		dest[length] = src[length];
		length++;
	}
	dest[length] = '\0';

	return (dest);
}
