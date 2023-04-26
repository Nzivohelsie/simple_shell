#include "main.h"
/**
 * main - entry point
 * @ac: argument
 * @av: argument
 * @env: argument
 * Return: 0
 */
int main(int ac, char **av, char **env)
{
	char *prompt = "simple_shell ", *line = NULL, *path = NULL;
	char **arguments = NULL;
	size_t k = 0;
	ssize_t num_read;

	while (1)
	{
		_printf("%s", prompt);
		num_read = getline(&line, &k, stdin);
		if (num_read == -1)
		{
			free(line);
			_printf("\n");
			return (-1);
		}
		arguments = _strtok(line);
		if (*arguments != NULL)
		{
			_builtin(arguments, line, ac, av, env);
			path = _path(arguments[0]);
			_execute(path, arguments, av, env);
		}
		else
			_free(arguments);
	}
	free(line);
	_free(arguments);
	return (0);
}
