#include "main.h"
/**
 * main - entry point
 * Return: 0
 */
int main(void)
{
	char *prompt = "simple_shell ";
	char *line = NULL;
	char **arguments = NULL;
	size_t k = 0;
	ssize_t num_read;
	char *path = NULL;
	int i;

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
		if (*arguments != NULL)
		{
			if (_strcmp(arguments[0], "exit") == 0)
			{
				free(*arguments);
				free(arguments);
				free(line);
				exit(0);
			}
			else if (_strcmp(arguments[0], "env") == 0)
				_environ();
		}
		path = _path(arguments[0]);
		if (path != NULL)
		{
			_execve(path, arguments);
			free(path);
			for (i = 0; arguments[i] != NULL; i++)
			{
				free(arguments[i]);
			}
			free(arguments);
		}
		else
		{
			free(*arguments);
			free(arguments);
			free(path);
		}
	}
	free(*arguments);
	free(arguments);
	free(line);
	return (0);
}
