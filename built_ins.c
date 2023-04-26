#include "main.h"
/**
 * _builtin - exit
 * @arguments: argument
 * @line: argument
 * @ac: arguments
 * @av: argument
 * @env: argument
 * Return:1 on success
 */
int _builtin(char **arguments, char *line, int ac, char **av, char **env)
{
	if (_strcmp(arguments[0], "exit") == 0)
	{
		free(line);
		_free(arguments);
		exit(0);
	}
	else if (_strcmp(arguments[0], "env") == 0)
		_environ(ac, av, env);
	return (1);
}
