#include "main.h"

/**
 * print_unsigned - Prints an unsigned integer.
 * @types: List of args.
 * @buff: Buffer array.
 * @flags:  Sums up active flags
 * @width: The width
 * @precision: Precision specifier.
 * @size: Size specifier.
 *
 * Return: Num of characters.
 */
int print_unsigned(va_list types, char buff[],
	int flags, int width, int precision, int size)
{
	int i = SIZE_OF_BUFF - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsignd(num, size);

	if (num == 0)
		buff[i--] = '0';

	buff[SIZE_OF_BUFF - 1] = '\0';

	while (num > 0)
	{
		buff[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsignd(0, i, buff, flags, width, precision, size));
}

/**
 * print_octal - Prints an unsigned int in octal notation.
 * @types: List of args.
 * @buff: Buffer array.
 * @flags:  Sums up active flags.
 * @width: The width.
 * @precision: Precision specifier.
 * @size: Size specifier.
 *
 * Return: Num of characters.
 */
int print_octal(va_list types, char buff[],
	int flags, int width, int precision, int size)
{

	int i = SIZE_OF_BUFF - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	NOT_USED(width);

	num = convert_size_unsignd(num, size);

	if (num == 0)
		buff[i--] = '0';

	buff[SIZE_OF_BUFF - 1] = '\0';

	while (num > 0)
	{
		buff[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & FLAG_HASH && init_num != 0)
		buff[i--] = '0';

	i++;

	return (write_unsignd(0, i, buff, flags, width, precision, size));
}

/**
 * print_hexadecimal - Prints an unsigned int in hexadecimal notation.
 * @types: List of args.
 * @buff: Buffer array.
 * @flags:  Sums active flags
 * @width: The width.
 * @precision: Precision specifier.
 * @size: Size specifier.
 * Return: Num of characters.
 */
int print_hexadecimal(va_list types, char buff[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buff,
		flags, 'x', width, precision, size));
}

/**
 * print_hexa_upper - Prints an unsigned int in upper hexadecimal notation.
 * @types: List of args.
 * @buff: Buffer array.
 * @flags:  Sum of active flags.
 * @width: The width.
 * @precision: Precision specifier.
 * @size: Size specifier.
 *
 * Return: Num of chars.
 */
int print_hexa_upper(va_list types, char buff[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buff,
		flags, 'X', width, precision, size));
}

/**
 * print_hexa - Prints a hexadecimal int in lower/upper.
 * @types: List of args.
 * @map_to: Array of values to map the int to.
 * @buff: Buffer array.
 * @flags:  Sums up active flags.
 * @flag_ch: Calculates active flags.
 * @width: The width.
 * @precision: Precision specifier.
 * @size: Size specifier.
 *
 * Return: Number of chars printed
 */
int print_hexa(va_list types, char map_to[], char buff[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = SIZE_OF_BUFF - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	NOT_USED(width);

	num = convert_size_unsignd(num, size);

	if (num == 0)
		buff[i--] = '0';

	buff[SIZE_OF_BUFF - 1] = '\0';

	while (num > 0)
	{
		buff[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & FLAG_HASH && init_num != 0)
	{
		buff[i--] = flag_ch;
		buff[i--] = '0';
	}

	i++;

	return (write_unsignd(0, i, buff, flags, width, precision, size));
}
