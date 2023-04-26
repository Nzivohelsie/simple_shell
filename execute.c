#include "main.h"
/**
 * _execute - execute
 * @path: path
 * @arguments: argumeent
 * @av: argument
 * @env: argument
 * Return: 1
 */
int _execute(char *path, char **arguments, char **av, char **env)
{
		_execve(path, arguments, av, env);
		free(path);
		_free(arguments);
	return (1);
}
