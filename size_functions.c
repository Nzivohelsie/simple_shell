#include "main.h"

/**
 * get_size - calculates the size to cast the argument
 * @format: formatted string in which to print the arguments
 * @i: list of arguments to be printed
 *
 * Return: size
 */

int get_size(const char *format, int *i)
{
	int curr_i = *i + 1;
