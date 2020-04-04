#include "simple_shell.h"

int main(int ac, char **av, char **env)
{
        char *input = NULL, **tokens;
        size_t length = 0;
        int read;
/* int status */

	(void)ac;
	(void)av;

	signal(SIGINT, SIG_DFL); /*check this crap */

        do {
                printf("$ ");
		read = getline(&input, &length, stdin);
                tokens = _parser(input);
                _executer(tokens, env);
		/*	status = _executer(tokens, env); */

        } while (read);

	free(input);
        free(tokens);

	return (0);
}

int _executer(char **args, char **env)
{
	unsigned int i = 0;
	struct stat st;
	pid_t child_pid;
	int status;

	while (args[i])
	{
		if (stat(args[i], &st) == 0)
		{

			child_pid = fork();

			if (child_pid == -1)
			{
				printf("Error:");
				return (EXIT_FAILURE);
			}
			if (child_pid == 0)
			{
				execve(args[i], args, env);
				printf("Command: %s\n", args[i]);
				return (EXIT_FAILURE);
			}
			else
			{
				wait(&status);
			}
		}
		else
		{
			printf("Command not found: %s\n", args[i]);
		}
		i++;
	}
	return (EXIT_FAILURE);
}


char **_parser(char *line)
{
	int buffsize = 64, index = 0;
	char **tokens, *token;

	tokens = malloc(buffsize * sizeof(char *));

	if (tokens == NULL)
	{
		exit(EXIT_FAILURE);
	}

	token = strtok(line, DELIMITER);

	while (token != NULL)
	{
		tokens[index] = token;
		index++;

		token = strtok(NULL, DELIMITER);
	}

	tokens[index] = NULL;

	return (tokens);
}
