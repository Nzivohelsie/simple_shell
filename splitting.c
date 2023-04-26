#include "main.h"
#include <string.h>
/**
 * _strtok - splitting commands into tokens
 * @str: string
 * Return: 0
 */
char **_strtok(char *str)
{
	char *str_copy = NULL;
	char *token = NULL;
	char **argv = NULL;
	int strings = 0;
	int i;
	char *delimiter = " \n";

	if (str == NULL)
		return (NULL);
	str_copy = malloc((_strlen(str) + 1) * sizeof(char));
	_strcpy(str_copy, str);
	token = strtok(str, delimiter);
	while (token != NULL)
	{
		strings++;
		token = strtok(NULL, delimiter);
	}
	strings++;
	argv = malloc(strings * sizeof(char *));
	token = strtok(str_copy, delimiter);
	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc((_strlen(token) + 1) * sizeof(char));
		_strcpy(argv[i], token);
		token = strtok(NULL, delimiter);
	}
	argv[i] = NULL;
	free(str_copy);
	return (argv);
}
