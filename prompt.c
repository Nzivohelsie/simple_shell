#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
 * main - entry point
 * Return: 0
 */
int main(void)
{
	pid_t child_pid;
	char *prompt = "simple_shell ";
	char *line;
	char **argv;
	size_t k = 0;
	ssize_t num_read;

	while (1)
	{
		printf("%s", prompt);

		num_read = getline(&line, &k, stdin);
		if (num_read == -1)
			return (-1);
		printf("%s\n", line);
		argv = &line;
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		else if (child_pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error:");
			}
		}
		else
			wait (NULL);
	}
	free(line);
	return (0);
}
