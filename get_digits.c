#include "main.h"

/**
 * is_printable - Checks if a character is printable.
 * @c: The character.
 *
 * Return: 1 if @c is printable, otherwise 0.
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - Append ascii in hexa-decimal code to the buffer.
 * @buff: Array of characters.
 * @index: Index to start appending.
 * @ascii_code: The ASCII CODE.
 * Return: Always 3.
 */
int append_hexa_code(char ascii_code, char buff[], int index)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;

	buff[index++] = '\\';
	buff[index++] = 'x';

	buff[index++] = map_to[ascii_code / 16];
	buff[index] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - Checks if a character is a digit.
 * @c: The character.
 *
 * Return: 1 if @c is a digit, otherwise 0.
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - Typecasts a num to the given size.
 * @num: The number.
 * @size: The size.
 *
 * Return: Casted @num.
 */
long int convert_size_number(long int num, int size)
{
	if (size == SIZE_LONG)
		return (num);
	else if (size == SIZE_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsignd - Typecasts a num to the specified size.
 * @num: The number.
 * @size: The size.
 *
 * Return: Casted @num.
 */
long int convert_size_unsignd(unsigned long int num, int size)
{
	if (size == SIZE_LONG)
		return (num);
	else if (size == SIZE_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
