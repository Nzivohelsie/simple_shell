#include "main.h"
/**
 * main - entry point
 * Return: 0
 */
int main(void)
{
	pid_t child_pid;
	char *prompt = "simple_shell ";
	char *line = NULL;
	char **arguments = NULL;
	size_t k = 0;
	ssize_t num_read;
	char *path = NULL;

	while (1)
	{
		printf("%s", prompt);
		num_read = getline(&line, &k, stdin);
		if (num_read == -1)
		{
			free(line);
			free(*arguments);
			free(arguments);
			printf("\n");
			return (-1);
		}
		arguments = _strtok(line);
		if (*arguments != NULL)
		{
			if (strcmp(arguments[0], "exit") == 0)
			{
				free(*arguments);
				free(arguments);
				free(line);
				exit(0);
			}
			else if (strcmp(arguments[0], "env") == 0)
				_environ();
		}
		path = _path(arguments[0]);
		if (path != NULL)
		{
			child_pid = fork();
			if (child_pid == -1)
			{
				free(*arguments);
				free(arguments);
				return (1);
			}
			else if (child_pid == 0)
			{
				_execve(arguments);
				free(line);
				free(*arguments);
				free(arguments);
			}
			else
			{
				wait (NULL);
				free(*arguments);
				free(arguments);
			}
		}
		else
		{
			free(*arguments);
			free(arguments);
		}
	}
	free(*arguments);
	free(arguments);
	free(line);
	return (0);
}
