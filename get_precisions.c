#include "main.h"

/**
 * get_precision - Sums up the precision.
 * @_format: Formatted string.
 * @i: List of args.
 * @list: A list of arguments.
 *
 * Return: The precision.
 */
int get_precision(const char *_format, int *i, va_list list)
{
	int current_i = *i + 1;
	int precise = -1;

	if (_format[current_i] != '.')
	return (precise);

	precise = 0;

	for (current_i += 1; _format[current_i] != '\0'; current_i++)
	{
		if (is_digit(_format[current_i]))
	{
		precise *= 10;
		precise += _format[current_i] - '0';
	}
		else if (_format[current_i] == '*')
	{
		current_i++;
		precise = va_arg(list, int);
		break;
	}
	else
	break;
	}

	*i = current_i - 1;

	return (precise);
}
