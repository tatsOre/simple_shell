#include "simple_shell.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
	char s1[] = "Hello";
	char s2[] = "World!";
	char *concat;
	char *s;

	printf("========strdup========\n");
	s = _strdup("Holberton");
	if (s == NULL)
	{
		printf("failed to allocate memory\n");
		return (1);
	}
	printf("%s\n", s);
	free(s);


	printf("========concat==========\n");
        concat = string_nconcat("Holberton ", "School", 4);
        printf("%s\n", concat);



	printf("==========strncomp ========\n");
	printf("%d\n", _strcmp(s1, s2));
	printf("%d\n", _strcmp(s2, s1));
	printf("%d\n", _strcmp(s1, s1));
	return (0);
}
