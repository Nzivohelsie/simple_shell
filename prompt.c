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
			printf("\n");
			return (-1);
		}
		arguments = _strtok(line);
		path = _path(arguments[0]);
		if (path != NULL)
		{
			child_pid = fork();
			if (child_pid == -1)
			{
				free(line);
				free(arguments);
				return (1);
			}
			else if (child_pid == 0)
			{
				_execve(arguments);
			}
			else
			{
				wait (NULL);
				free(path);
				free(*arguments);
				free(arguments);
			}
		}
		else
		{
			free(path);
			free(*arguments);
			free(arguments);
		}
	}
	free(path);
	free(arguments);
	free(line);
	return (0);
}
