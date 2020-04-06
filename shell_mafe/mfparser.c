#include "holberton.h"

/**
 * countarg - Counts the number of arguments in the string returned by getline
 * @buffer: A pointer to a string
 * Return: length
 */
int countarg(char *buffer)
{
	int i, count, flag, j;
	char *delimiter = " :";

	flag = i = 0;
	count = 1;
	if (buffer == NULL)
		return (count);
	while (buffer[i] != '\0')
	{
		for (j = 0; delimiter[j] != '\0'; j++)
		{
			if (buffer[i] == delimiter[j] && flag == 0)
			{
				count++;
				flag = 1;
				break;
			}
		}
		if (delimiter[j] == '\0')
			flag = 0;
		i++;
	}
	return (count + 1);
}

/**
 * _parser - parses the arguments passed into token and passes
 * them to a buffer
 *
 * @buffer: A pointer to a string entered into the command line
 * @size: An unsigned integer indicating the number of arguments
 *
 * Return: A pointer to an array of strings.
 */
char **_parser(char *buffer, int size)
{
	char **token_list = malloc(sizeof(char *) * size);
	char *token;
	int i = 0;
	char *delimiter = " :'\n''\t''\r'";

	if (buffer == NULL || token_list == NULL)
		return (NULL);
	token = strtok(buffer, delimiter);
	while (token != NULL)
	{
		token_list[i] = strdup(token);
		if (token_list[i] == NULL)
		{
			free_function(2, token_list);
			return (NULL);
		}
		token = strtok(NULL, delimiter);
		i++;
	}
	token_list[i] = token;
	return (token_list);
}


/**
  * equal_sign - eliminates of chars up until and including the
  * equal sign in the environment string
  * @s: the string to modify
  * Return: Nothing, void
  */
void equal_sign(char **s)
{
	int i = 0;

	while (s[0][i] != '=')
	{
		s[0][i] = ':';
		i++;
	}
	s[0][i] = ':';
}
