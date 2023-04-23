#include "main.h"
#include <string.h>

char **_strtok(char *str)
{
	str_copy = malloc(chars_read * sizeof(char));
	strcpy(str_copy, str);
	token = strtok(str, " \n");
	while (token != NULL)
	{
		strings++;
		token = strtok(NULL, " ");
	}
	strings++;
	argv = malloc(strings * sizeof(char*));
	token = strtok(str_copy, " \n");
	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(strlen(token) * sizeof(char));
		strcpy(argv[i], token);
		token = strtok(NULL, " ");
	}
	argv[i] = NULL;
	free(str_copy);
	return (argv);
}
