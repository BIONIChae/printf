#include "main.h"

/**
 * get_width - Sums up the width.
 * @_format: Formatted string.
 * @i: Lists args.
 * @list: A list of args.
 *
 * Return: the width.
 */
int get_width(const char *_format, int *i, va_list list)
{
	int current_i;
	int width = 0;

	for (current_i = *i + 1; _format[current_i] != '\0'; current_i++)
	{
		if (is_digit(_format[current_i]))
		{
			width *= 10;
			width += _format[current_i] - '0';
		}
			else if (_format[current_i] == '*')
			{
				current_i++;
				width = va_arg(list, int);
				break;
			}
			else
				break;
	}

	*i = current_i - 1;

	return (width);
}
