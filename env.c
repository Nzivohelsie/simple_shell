#include "main.h"

/**
 * _environ - function to handle the environment
 *
 * Return: 1
 */
int _environ(void)
{
	extern char **environ;
	int i = 0;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
	return (1);
}
