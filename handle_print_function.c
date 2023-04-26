#include "main.h"

/**
 * handle_unknown - Handles unknown format specifiers
 * @fmt: Formatted string in which to print the arguments.
 * @ind: Pointer to index of current character being processed in fmt.
 *
 * Return: Number of characters printed.
 */

int handle_unknown(const char *fmt, int *ind)
{
	int unknown_len = 0;

	/* Print the percent sign and any preceding space */
	unknown_len += write(1, "%%", 1);
	if (fmt[*ind - 1] == ' ')
		unknown_len += write(1, " ", 1);

	/* If a width is specified, skip the unknown format specifier */
	else if (fmt[*ind] == ' ')
	{
		while (fmt[*ind] == ' ')
			(*ind)++;
		(*ind)--;
	}

	/* Otherwise, print the unknown format specifier */
	else
		unknown_len += write(1, &fmt[*ind], 1);

	return (unknown_len);
}
/**
 * handle_print - Prints an argument based on its type
 * @fmt: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @ind: Pointer to index of current character being processed in fmt.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: Number of characters printed or -1 on failure.
