#include "main.h"
/**
 * _execve - function executes command
 * @av: argument
 */
void _execve(char **av)
{
	if (execve(av[0], av, NULL) == -1)
	{
		perror("Error");
	}
}
