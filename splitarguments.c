#include "simple_shell.h"

/**
 * get_tokens - Breaks input into a series of tokens using a string
 * delimiter and store them in an array of strings
 * @buffer: getline malloc'd user input
 * Return: A pointer to an array of strings
 */

char **get_tokens(char *buffer)
{
	char **token_list = malloc(sizeof(char *) * countarg(buffer));
	char *token;
	int index = 0;

	if (buffer == NULL || token_list == NULL)
	{
		free_function(2, token_list);
		return (NULL);
	}
	token = strtok(buffer, DELIMITER);

	while (token != NULL)
	{
		token_list[index] = _strdup(token);

		if (token_list[index] == NULL)
		{
			free_function(2, token_list);
			return (NULL);
		}

		token = strtok(NULL, DELIMITER);

		index++;
	}

	token_list[index] = token;

	return (token_list);
}

/**
 * countarg - Counts the number of user input array arguments
 * @buffer: getline malloc'd user input
 * Return: number of arguments
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
