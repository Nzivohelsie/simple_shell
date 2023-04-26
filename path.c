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
	char *argument = command;

	paths = getenv("PATH");
	path_length = _strlen(paths);
	path_copy = malloc((path_length + 1) * sizeof(char));
	_strcpy(path_copy, paths);
	command_length = _strlen(command);
	command_path = (_split(path_copy, command_length, argument));
	free(path_copy);
	return (command_path);
}
