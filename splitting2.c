#include "main.h"
/**
 * _split - splitting tokens
 * @path_copy: parameter
 * @command_length: parameter
 * @command: parameter
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
