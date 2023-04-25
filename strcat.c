#include "main.h"
/**
 * _strcat - append string 1 onto string 2
 * @dest: sting 2
 * @src: string 1
 * Return: pointer to dest
 */
char *_strcat(char *dest, char *src)
{
	int a, b, i;
	int l = 0;
	int le = 0;
	char *p = dest;

	for (a = 0; dest[a] != '\0'; a++)
		le++;
	for (b = 0; src[b] != '\0'; b++)
		l++;
	for (i = 0; i < le; i++)
		dest[i] = dest[i];
	for (i = le; i <= (le + l); i++)
	{
		dest[i] = *src;
		src++;
	}
	return (p);
}
