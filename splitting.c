#include "main.h"
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
