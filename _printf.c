#include "main.h"

void print_buffer(char buff[], int *buff_index);

/**
 * _printf - The printf function
 * @fmt: The format
 * Return: characters
 */
int _printf(const char *fmt, ...)
{
	int i, printed = 0, printd_chars = 0;
	int flags, width, precision, size, buff_index = 0;
	va_list list;
	char buff[SIZE_OF_BUFF];

	if (fmt == NULL)
		return (-1);

	va_start(list, fmt);

	for (i = 0; fmt && fmt[i] != '\0'; i++)
	{
		if (fmt[i] != '%')
		{
			buff[buff_index++] = fmt[i];
			if (buff_index == SIZE_OF_BUFF)
				print_buffer(buff, &buff_index);
			printd_chars++;
		}
		else
		{
			print_buffer(buff, &buff_index);
			flags = get_flags(fmt, &i);
			width = get_width(fmt, &i, list);
			precision = get_precision(fmt, &i, list);
			size = get_size(fmt, &i);
			++i;
			printed = handle_print(fmt, &i, list, buff,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printd_chars += printed;
		}
	}

	print_buffer(buff, &buff_index);

	va_end(list);

	return (printd_chars);
}

/**
 * print_buffer - Writes the contents of the buffer.
 * @buff: Array of characters.
 * @buff_index: The length/Index at which to add a char.
 */
void print_buffer(char buff[], int *buff_index)
{
	if (*buff_index > 0)
		write(1, &buff[0], *buff_index);

	*buff_index = 0;
}
