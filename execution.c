#include "main.h"
/**
 * _execve - function executes command
 * @av: argument
 */
void _execve(char *command, char **av)
{
	extern char **environ;

	if (execve(command, av, environ) == -1)
	{
		perror("Error");
	}
}
