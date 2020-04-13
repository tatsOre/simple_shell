#include "simple_shell.h"

/**
  * free_function - Frees malloc'd spaces based on what number is passed
  * @n: free a single pointer n(1) or double pointer n(2)
  * Return: Nothing
  */
void free_function(int n, ...)
{
	char **ptr2, *ptr1;
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
