#include "main.h"
/**
 * _split - find path
 * @path_copy: argument
 * @command_length: argument
 * @command: argument
 * Return: path
 */
char *_split(char *path_copy, int command_length, char *command)
{
	char *command_path = NULL;
	char *token = NULL;
	struct stat statbuf;

	token = strtok(path_copy, ":");
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
			return (command_path);
		}
		token = strtok(NULL, ":");
	}
	if (stat(command, &statbuf) == 0)
	{
		command_path = malloc(command_length + 1);
		command_path = _strcpy(command_path, command);
		return (command_path);
	}
	command_path = malloc(command_length + 1);
	command_path = _strcpy(command_path, command);
	return (command_path);
}
