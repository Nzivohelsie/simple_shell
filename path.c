#include "main.h"
/**
 * _path - function that handles the path
 * @command: character
 * Return: NULL
 */
char *_path(char *command)
{
	char *paths = NULL;
	int path_length = 0;
	char *path_copy = NULL;
	int command_length = 0;
	char *delimiter = ":";
	char *token = NULL;
	char *command_path = NULL;
	struct stat statbuf;

	if (command == NULL)
		return (NULL);
	paths = getenv("PATH");
	path_length = _strlen(paths);
	path_copy = malloc((path_length + 1) * sizeof(char));
	_strcpy(path_copy, paths);
	command_length = _strlen(command);
	token = strtok(path_copy, delimiter);
	while (token != NULL)
	{
		command_path = malloc(_strlen(token) + command_length + 2);
		_strcpy(command_path, token);
		_strcat(command_path, "/");
		_strcat(command_path, command);
		_strcat(command_path, "\0");

		if (stat(command_path, &statbuf) != 0)
		{
			free(command_path);
			command_path = NULL;
		}
		else
		{
			free(path_copy);
			return (command_path);
		}
		token = strtok(NULL, delimiter);
	}
	free(path_copy);
	if (stat(command, &statbuf) == 0)
		return (command);
	return (NULL);
}
