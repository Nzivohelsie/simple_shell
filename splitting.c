#include "main.h"
#include <string.h>
/**
 * _strtok - splitting commands into tokens
 * @str: string
 * Return: 0
 */
char **_strtok(char *str)
{
	char *str_copy;
	char *token;
	char **argv;
	int strings = 0;
	int i;

	str_copy = malloc(strlen(str) * sizeof(char));
	strcpy(str_copy, str);
	token = strtok(str, " \n");
	while (token != NULL)
	{
		strings++;
		token = strtok(NULL, " \n");
	}
	strings++;
	argv = malloc(strings * sizeof(char *));
	token = strtok(str_copy, " \n");
	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(strlen(token) * sizeof(char));
		strcpy(argv[i], token);
		token = strtok(NULL, " \n");
	}
	argv[i] = NULL;
	free(str_copy);
	return (argv);
}
