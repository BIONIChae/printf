#include "main.h"

/**
 * handle_print - Writes an argument based on its data type.
 * @fmt: Formatted string.
 * @list: List of args.
 * @index: The index.
 * @buff: Buffer array.
 * @flags: Sums up active flags
 * @width: The width.
 * @precision: Specifies the precision.
 * @size: Size specifier.
 *
 * Return: Either 1 or 2;
 */
int handle_print(const char *fmt, int *index, va_list list, char buff[],
	int flags, int width, int precision, int size)
{
	int i, unknow_len = 0, printd_chars = -1;
	fmt_t format_types[] = {
				{'c', print_char}, {'s', print_string}, {'%', print_percent},
				{'i', print_int}, {'d', print_int}, {'b', print_binary},
				{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
				{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
				{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
				};

	for (i = 0; format_types[i].fmt != '\0'; i++)
	{
		if (fmt[*index] == format_types[i].fmt)
		{
			if (fmt[*index] == 'i' || fmt[*index] == 'd')
			{
				return (print_int(list, buff, width, flags, precision, size));
			}
			return (format_types[i].fn(list, buff, flags, width, precision, size));
		}
	}

	if (format_types[i].fmt == '\0')
	{
		if (fmt[*index] == '\0')
			return (-1);

		unknow_len += write(1, "%%", 1);

		if (fmt[*index - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*index);
			while (fmt[*index] != ' ' && fmt[*index] != '%')
				--(*index);
			if (fmt[*index] == ' ')
				--(*index);
			return (1);
		}

		unknow_len += write(1, &fmt[*index], 1);
		return (unknow_len);
	}

	return (printd_chars);
}
