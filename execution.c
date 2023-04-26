#include "main.h"
/**
 * _execve - function executes command
 * @av: argument
 * @command: argument
 * @args: argument
 * @environ: argument
 * Return: 0 on success
 */
int _execve(char *command, char **args, char **av, char **environ)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("error");
		return (1);
	}
	else if (child_pid == 0)
	{
		if (execve(command, args, environ) == -1)
		{
			_printf("%s: 1: %s: not found\n", av[0], command);
		}
	}
	else
	{
		wait(&status);
	}
	return (1);
}
