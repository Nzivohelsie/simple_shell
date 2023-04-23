#include "main.h"
/**
 * main - entry point
 * Return: 0
 */
int main(void)
{
	pid_t child_pid;
	char *prompt = "simple_shell ";
	char *line;
	char **arguments;
	size_t k;
	ssize_t num_read;

	while (1)
	{
		printf("%s", prompt);

		line = malloc(k * sizeof(char));
		num_read = getline(&line, &k, stdin);
		if (num_read == -1)
		{
			printf("\n");
			return (-1);
		}

		arguments = _strtok(line);

		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		else if (child_pid == 0)
		{
			_execve(arguments);
		}
		else
			wait (NULL);
	}
	free(arguments);
	free(line);
	return (0);
}
