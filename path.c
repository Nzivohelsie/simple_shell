#include "main.h"
/**
 * _path - function that handles the path
 * @command: character
 * Return: NULL
 */
char *_path(char *command)
{
	int path_length = 0, command_length = 0;
	char *path_copy = NULL, *command_path = NULL;
	char *paths = NULL;
