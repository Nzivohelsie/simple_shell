#include "main.h"
/**
 * _execve - function executes command
 * @av: argument
 */
int _execve(char *command, char **av)
{
	pid_t child_pid;
	extern char **environ;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("error");
		return (1);
	}
	else if (child_pid == 0)
	{
		if (execve(command, av, environ) == -1)
		{
			perror("Error");
			return(1);
		}
	}
	else
	{
		wait(&status);
	}
	return(1);
}
