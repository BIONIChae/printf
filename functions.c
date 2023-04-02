#include "main.h"

/**
 * print_char - Prints a character
 * @types: Lists args.
 * @buff: Buffer array.
 * @flags: Finds active flags.
 * @width: the width.
 * @precision: The precision.
 * @size: Size specifier.
 *
 * Return: Num of characters.
 */
int print_char(va_list types, char buff[],
int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buff, flags, width, precision, size));
}

/**
 * print_string - Print string.
 * @types: Lists arguments.
 * @buff: The buffer array.
 * @flags:  Finds active flags.
 * @width: The width.
 * @precision: Specifies the precision.
 * @size: Size specifier.
 *
 * Return: Num of characters.
 */
int print_string(va_list types, char buff[],
	int flags, int width, int precision, int size)
{
	int length = 0, i;
	char *str = va_arg(types, char *);

	NOT_USED(buff);
	NOT_USED(flags);
	NOT_USED(width);
	NOT_USED(precision);
	NOT_USED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "	  ";
	}

	while (str[length] != '\0')
		length++;

			if (precision >= 0 && precision < length)
				length = precision;

	if (width > length)
	{
		if (flags & FLAG_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
				for (i = width - length; i > 0; i--)
					write(1, " ", 1);
				write(1, &str[0], length);
						return (width);
				}
		}

		return (write(1, str, length));
}
/**
 * print_percent - Prints a % sign
 * @types: List of args.
 * @buff: Buffer array.
 * @flags:  Sums up active flags.
 * @width: The width.
 * @precision: Specifies the precision.
 * @size: Size specifier.
 *
 * Return: Num of characters.
 */
int print_percent(va_list types, char buff[],
		int flags, int width, int precision, int size)
{
		NOT_USED(types);
		NOT_USED(buff);
		NOT_USED(flags);
		NOT_USED(width);
		NOT_USED(precision);
		NOT_USED(size);
		return (write(1, "%%", 1));
}

/**
 * print_int - Print integer.
 * @types: List of args.
 * @buff: Buffer array.
 * @flags:  Sums up active flags.
 * @width: the width.
 * @precision: Specifies the precision.
 * @size: Size specifier.
 *
 * Return: Num of characters.
 */
int print_int(va_list types, char buff[],
		int width, int flags, int precision, int size)
{
		int i = SIZE_OF_BUFF - 2;
		int is_negative = 0;
		long int n = va_arg(types, long int);
		unsigned long int num;

		n = convert_size_number(n, size);

			if (n == 0)
				buff[i--] = '0';

			buff[SIZE_OF_BUFF - 1] = '\0';
		num = (unsigned long int) n;

			if (n < 0)
		{
				num = (unsigned long int)((-1) * n);
				is_negative = 1;
		}

			while (num > 0)
		{
				buff[i--] = (num % 10) + '0';
				num /= 10;
		}

		i++;

		return (write_number(is_negative, i, buff, flags, width, precision, size));
}

/**
 * print_binary - Prints an unsigned number.
 * @types: List of args.
 * @buff: Buffer array.
 * @flags:  Sum up active flags
 * @width: the width.
 * @precision: Specifies the precision.
 * @size: Size specifier.
 * Return: Num of characters.
 */
int print_binary(va_list types, char buff[],
		int flags, int width, int precision, int size)
{
		unsigned int x, y, i, sum;
		unsigned int a[32];
		int count;

		NOT_USED(buff);
		NOT_USED(flags);
		NOT_USED(width);
		NOT_USED(precision);
		NOT_USED(size);

		x = va_arg(types, unsigned int);
		y = 2147483648;
		a[0] = x / y;
			for (i = 1; i < 32; i++)
		{
				y /= 2;
				a[i] = (x / y) % 2;
		}
			for (i = 0, sum = 0, count = 0; i < 32; i++)
		{
				sum += a[i];
					if (sum || i == 31)
				{
						char z = '0' + a[i];

						write(1, &z, 1);
						count++;
				}
		}
		return (count);
}
