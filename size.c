#include "main.h"

/**
 * get_size - Sums up the size to cast the arg.
 * @_format: Formatted string.
 * @i: List of args.
 *
 * Return: The precision.
 */
int get_size(const char *_format, int *i)
{
	int current_i = *i + 1;
	int size = 0;

	if (_format[current_i] == 'l')
		size = SIZE_LONG;
	else if (_format[current_i] == 'h')
		size = SIZE_SHORT;

	if (size == 0)
		*i = current_i - 1;
	else
		*i = current_i;

	return (size);
}
