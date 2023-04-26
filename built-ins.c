#include "main.h"
/**
 * _builtin - function for built-in commands
 * @arguments: parameter
 * @line: character
 * @ac: argument
 * @av: argument
 * @env: parameter
 */
int _builtin(char **arguments, char *line, int ac, char **av, char **env)
{
	if (_strcmp(arguments[0], "exit") == 0)
	{
		free(line);
		_free(arguments);
