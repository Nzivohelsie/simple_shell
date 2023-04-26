#include "main.h"
/**
 * main - entry point
 * @ac: parameter
 * @av: argument
 * @env: parameter
 * Return: 0
 */
int main(int ac, char **av, char **env)
{
	char *prompt = "simple_shell ", *line = NULL, *path = NULL;
	char **arguments = NULL;
	size_t k = 0;
	ssize_t num_read;

	while (1)
	{
		_printf("%s", prompt);
		num_read = getline(&line, &k, stdin);
		if (num_read == -1)
		{
