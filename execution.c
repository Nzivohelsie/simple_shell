#include "main.h"
/**
 * main - function executes command
 * Return: 0
 */
void _execve(char **av)
{
	if (execve(av[0], av, NULL) == -1)
	{
		perror("Error");
	}
}
