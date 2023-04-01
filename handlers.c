#include "main.h"

/**
 * handle_write_char - Writes a string.
 * @c: The char types.
 * @buff: The buffer array.
 * @flags:  Sums up the active flags.
 * @width: Width specifier.
 * @precision: Precision specifier.
 * @size: Size specifier.
 *
 * Return: Number of chars printed.
 */
int handle_write_char(char c, char buff[],
int flags, int width, int precision, int size)
{
	int i = 0;
	char padd = ' ';

	NOT_USED(precision);
	NOT_USED(size);

	if (flags & FUNC_ZERO)
		padd = '0';

	buff[i++] = c;
	buff[i] = '\0';

	if (width > 1)
	{
		buff[SIZE_OF_BUFF - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buff[SIZE_OF_BUFF - i - 2] = padd;

		if (flags & FUNC_MINUS)
			return (write(1, &buff[0], 1) +
				write(1, &buff[SIZE_OF_BUFF - i - 1], width - 1));

			return (write(1, &buff[SIZE_OF_BUFF - i - 1], width - 1) +
					write(1, &buff[0], 1));
	}

	return (write(1, &buff[0], 1));
}
/**
 * write_number - Prints a number.
 * @is_negative: List of negative arguments.
 * @index: char types.
 * @buff: Buffer array.
 * @flags:  Sums up active flags
 * @width: Width specifier.
 * @precision: Precision specifier.
 * @size: Size specifier.
 *
 * Return: Num of characters.
 */
int write_number(int is_negative, int index, char buff[],
		int flags, int width, int precision, int size)
{
	int length = SIZE_OF_BUFF - index - 1;
	char padd = ' ', extra_ch = 0;

	NOT_USED(size);

	if ((flags & FUNC_ZERO) && !(flags & FUNC_MINUS))
		padd = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & FUNC_PLUS)
		extra_ch = '+';
	else if (flags & FUNC_SPACE)
		extra_ch = ' ';

	return (write_num(index, buff, flags, width, precision,
		length, padd, extra_ch));
}

/**
 * write_num - Using a buffer, write an integer.
 * @index: Index at which the integer begins.
 * @buff: The buffer array.
 * @flags: Flags
 * @width: width specifier.
 * @precision: Precision specifier
 * @length: The number length.
 * @padd: Padding character.
 * @extra_c: Extra character.
 *
 * Return: Num of the character.
 */
int write_num(int index, char buff[],
	int flags, int width, int precision,
	int length, char padd, char extra_c)
{
	int i, padd_start = 1;

	if (precision == 0 && index == SIZE_OF_BUFF - 2
		&& buff[index] == '0' && width == 0)
		return (0);
	if (precision == 0 && index == SIZE_OF_BUFF - 2 && buff[index] == '0')
		buff[index] = padd = ' ';
	if (precision > 0 && precision < length)
		padd = ' ';
	while (precision > length)
		buff[--index] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			buff[i] = padd;
		buff[i] = '\0';
		if (flags & FUNC_MINUS && padd == ' ')
		{
			if (extra_c)
				buff[--index] = extra_c;
			return (write(1, &buff[index], length) + write(1, &buff[1], i - 1));
		}
		else if (!(flags & FUNC_MINUS) && padd == ' ')
		{
			if (extra_c)
				buff[--index] = extra_c;
			return (write(1, &buff[1], i - 1) + write(1, &buff[index], length));
		}
		else if (!(flags & FUNC_MINUS) && padd == '0')
		{
			if (extra_c)
				buff[--padd_start] = extra_c;
			return (write(1, &buff[padd_start], i - padd_start) +
				write(1, &buff[index], length - (1 - padd_start)));
		}
	}

	if (extra_c)
		buff[--index] = extra_c;
	return (write(1, &buff[index], length));
}

/**
 * write_unsgnd - Writes an unsigned integer.
 * @is_negative: Indicates if the int is negative.
 * @index: Index at which the number starts in the buffer
 * @buff: Array of characters.
 * @flags: Flags specifiers.
 * @width: Width specifier.
 * @precision: Precision specifier.
 * @size: Size specifier.
 *
 * Return: Num of written characters.
 */
int write_unsignd(int is_negative, int index,
		char buff[],
		int flags, int width, int precision, int size)
{
	int length = SIZE_OF_BUFF - index - 1, i = 0;
	char padd = ' ';

	NOT_USED(is_negative);
	NOT_USED(size);

	if (precision == 0 && index == SIZE_OF_BUFF - 2 && buff[index] == '0')
		return (0);

	if (precision > 0 && precision < length)
		padd = ' ';

	while (precision > length)
	{
		buff[--index] = '0';
		length++;
	}

	if ((flags & FUNC_ZERO) && !(flags & FUNC_MINUS))
		padd = '0';

	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			buff[i] = padd;

		buffer[i] = '\0';

		if (flags & FUNC_MINUS)
		{
			return (write(1, &buff[index], length) + write(1, &buff[0], i));
		}
		else
		{
			return (write(1, &buff[0], i) + write(1, &buff[index], length));
		}
	}

	return (write(1, &buff[index], length));
}

/**
 * write_pointer - Write a mem address.
 * @buff: Array of characters.
 * @index: Index at which the integer begins.
 * @length: Length of integer.
 * @width: Width specifier.
 * @flags: Flags specifier.
 * @padd: The padding.
 * @extra_c: Extra character.
 * @padd_start: Index at which padding begins.
 *
 * Return: Num of printed characters.
 */
int write_pointer(char buff[], int index, int length,
	int width, int flags, char padd, char extra_c, int padd_start)
{
	int i;

	if (width > length)
	{
		for (i = 3; i < width - length + 3; i++)
			buff[i] = padd;
		buff[i] = '\0';
		if (flags & FUNC_MINUS && padd == ' ')
		{
			buff[--index] = 'x';
			buff[--index] = '0';
			if (extra_c)
				buff[--index] = extra_c;
			return (write(1, &buff[index], length) + write(1, &buff[3], i - 3));
		}
		else if (!(flags & FUNC_MINUS) && padd == ' ')
		{
			buff[--index] = 'x';
			buff[--index] = '0';
			if (extra_c)
				buff[--index] = extra_c;
			return (write(1, &buff[3], i - 3) + write(1, &buff[index], length));
		}
		else if (!(flags & FUNC_MINUS) && padd == '0')
		{
			if (extra_c)
				buff[--padd_start] = extra_c;
			buff[1] = '0';
			buff[2] = 'x';
			return (write(1, &buff[padd_start], i - padd_start) +
				write(1, &buff[index], length - (1 - padd_start) - 2));
		}
	}
	buff[--index] = 'x';
	buff[--index] = '0';
	if (extra_c)
		buff[--index] = extra_c;
	return (write(1, &buff[index], SIZE_OF_BUFF - index - 1));
}
