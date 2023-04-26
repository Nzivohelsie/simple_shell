#include "main.h"

/**
 * _environ - function to handle built-in env
 *@ac: argument
 *@av: argument
 *@env: argument
 * Return: 1
 */
int _environ(int ac, char **av, char **env)
{
	unsigned int i;

	(void)av;
	(void)ac;
	i = 0;
	while (env[i] != NULL)
	{
		_printf("%s\n", env[i]);
		i++;
	}
	return (1);
}
