#include "main.h"

/**
 * print_pointer - Prints the value of a pointer var.
 * @types: List of args.
 * @buff: Buffer array.
 * @flags:  Calculates active flags
 * @width: The width.
 * @precision: Precision specifier.
 * @size: Size specifier.
 *
 * Return: Num of chars.
 */

int print_pointer(va_list types, char buff[],
	int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int index = SIZE_OF_BUFF - 2, length = 2, padd_start = 1;
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *address = va_arg(types, void *);

	NOT_USED(width);
	NOT_USED(size);

	if (address == NULL)
		return (write(1, "(nil)", 5));

	buff[SIZE_OF_BUFF - 1] = '\0';
	NOT_USED(precision);

	num_addrs = (unsigned long) address;

	while (num_addrs > 0)
	{
		buff[index--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}
	if ((flags & FLAG_ZERO) && !(flags & FLAG_MINUS))
		padd = '0';
	if (flags & FLAG_PLUS)
		extra_c = '+', length++;
	else if (flags & FLAG_SPACE)
		extra_c = ' ', length++;

	index++;
	return (write_pointer(buff, index, length,
		width, flags, padd, extra_c, padd_start));
}

/**
 * print_non_printable - Writes ascii codes in hexa of non-printable chars.
 * @types: List of args.
 * @buff: Buffer array.
 * @flags:  Sums up active flags
 * @width: The width.
 * @precision: Precision specifier.
 * @size: Size specifier.
 * Return: Num of characters.
 */
int print_non_printable(va_list types, char buff[],
	int flags, int width, int precision, int size)
{
	int i = 0, offset = 0;
	char *str = va_arg(types, char *);

	NOT_USED(flags);
	NOT_USED(width);
	NOT_USED(precision);
	NOT_USED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buff[i + offset] = str[i];
		else
			offset += append_hexa_code(str[i], buff, i + offset);

		i++;
	}

	buff[i + offset] = '\0';

	return (write(1, buff, i + offset));
}

/**
 * print_reverse - Prints reverse string.
 * @types: List of args.
 * @buff: Buffer arrays.
 * @flags:  Sums up active flags
 * @width: The width.
 * @precision: Precision specifier.
 * @size: Size specifier.
 *
 * Return: Num of characters.
 */

int print_reverse(va_list types, char buff[],
	int flags, int width, int precision, int size)
{
	char *str;
	int i, count = 0;

	NOT_USED(buff);
	NOT_USED(flags);
	NOT_USED(width);
	NOT_USED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		NOT_USED(precision);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}

/**
 * print_rot13string - Print a string in rot13.
 * @types: List of args.
 * @buff: Buffer array.
 * @flags:  Sum up active flags
 * @width: The width.
 * @precision: Precision specifier.
 * @size: Size specifier
 *
 * Return: Num of characters.
 */
int print_rot13string(va_list types, char buff[],
	int flags, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	NOT_USED(buff);
	NOT_USED(flags);
	NOT_USED(width);
	NOT_USED(precision);
	NOT_USED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
