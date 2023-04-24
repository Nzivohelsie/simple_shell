#include "main.h"
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

	paths = getenv("PATH");
	path_length = strlen(paths);
	path_copy = malloc((path_length + 1) * sizeof(char));
	strcpy(path_copy, paths);
	command_length = strlen(command);
	token = strtok(path_copy, delimiter);
	while (token != NULL)
	{
		command_path = malloc(strlen(token) + command_length + 2);
		strcpy(command_path, token);
		strcat(command_path, "/");
		strcat(command_path, command);
		strcat(command_path, "\0");

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
