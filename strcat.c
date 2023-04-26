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
