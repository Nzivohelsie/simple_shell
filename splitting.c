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
	char *pointer = str;

	str_copy = malloc((strlen(pointer) + 1) * sizeof(char));
	strcpy(str_copy, pointer);
	token = strtok(pointer, delimiter);
	while (token != NULL)
	{
		strings++;
		token = strtok(NULL, delimiter);
	}
	strings++;
	argv = malloc(strings * sizeof(char *));
	if (argv == NULL)
	{
		free(str_copy);
		return (NULL);
	}
	token = strtok(str_copy, delimiter);
	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc((strlen(token) + 1) * sizeof(char));
		strcpy(argv[i], token);
		token = strtok(NULL, delimiter);
	}
	argv[i] = NULL;
	free(str_copy);
	return (argv);
}
