#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * main - entry point
 * Return: 0
 */
int main(void)
{
	char *prompt = "simple_shell ";
	char *line;
	size_t k = 0;
	ssize_t num_read;

	printf("%s", prompt);

	getline(&line, &k, stdin);
	printf("%s\n", line);

	free(line);
	return (0);

}
