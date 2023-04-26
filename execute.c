#include "main.h"
/**
 * _execute - function that executes commands
 * @path: parameter
 * @arguments: parameter
 * @env: parameter
 * Return: 1
 */
int _execute(char *path, char **arguments, char **env)
{
		_execve(path, arguments, env);
