#include "main.h"
/**
 * _execve - function executes command
 * @av: argument
 */
void _execve(char **av)
{
	char *command = NULL;
	extern char **environ;

	command = _path(av[0]);
	if (execve(command, av, environ) == -1)
	{
		perror("Error");
	}
}
