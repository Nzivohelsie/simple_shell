#include "main.h"
/**
 * _strlen - length of string
 * @s: parameter
 * Return: length of string
 */
int _strlen(char *s)
{
	int le;

	le = 0;
	while (*s != '\0')
	{
		le++;
		s++;
	}
	return (le);
}
