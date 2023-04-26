#include "main.h"
/**
 * _execve - function that executes command
 * @av: argument
 */
int _execve(char *command, char **av, char **environ)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("error");
		return (1);
