#include "main.h"

/**
 * get_flags - Sums up the active flags.
 * @_format: Formatted string.
 * @i: Takes a param.
 * Return: Returns flags.
 */
int get_flags(const char *_format, int *i)
{
	int current_i, j;
	int flags = 0;
	const char FLAGS_CHAR[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARRAY[] = {FUNC_MINUS, FUNC_PLUS, FUNC_ZERO,
					FUNC_HASH, FUNC_SPACE, 0};

	for (current_i = *i + 1; _format[current_i] != '\0'; current_i++)
	{
		for (j = 0; FLAGS_CHAR[j] != '\0'; j++)
			if (_format[current_i] == FLAGS_CHAR[j])
			{
				flags |= FLAGS_ARRAY[j];
				break;
			}

		if (FLAGS_CHAR[j] == 0)
			break;
	}

	*i = current_i - 1;

	return (flags);
}
