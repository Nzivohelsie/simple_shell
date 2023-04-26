#include "main.h"
/**
 * *_strcpy - copy string
 * @dest: parameter
 * @src: parameter
 * Return: pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	int le = 0;
	int i;
	char *p = dest;

	while (*(src + le) != '\0')
	{
		le++;
	}
	for (i = 0; i <= le; i++)
	{
		dest[i] = src[i];
	}
	return (p);
}
