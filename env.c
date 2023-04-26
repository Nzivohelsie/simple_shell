#include "main.h"

/**
 * _environ - function to handle the built-in env
 *
 * Return: 1
 */
int _environ(int ac, char **av, char **env)
{
	unsigned int i;

	(void)av;
	(void)ac;
