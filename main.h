#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* Flags */
#define FUNC_MINUS 1
#define FUNC_PLUS 2
#define FUNC_ZERO 4
#define FUNC_HASH 8
#define FUNC_SPACE 16

/* Sizes */
#define FUNC_LONG 2
#define FUNC_SHORT 1

/**
 * struct fmt - Op.
 *
 * @fmt: The structure format.
 * @fn: the function.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - The struct op.
 *
 * @fmt: The structure format.
 * @fm_t: The function.
 */
typedef struct fmt fmt_t;

int _printf(const char *_format, ...);
int handle_print(const char *fmt, int *index,
va_list list, char buff[], int flags, int width, int precision, int size);

int print_char(va_list types, char buff[],
	int flags, int width, int precision, int size);
int print_string(va_list types, char buff[],
	int flags, int width, int precision, int size);
int print_percent(va_list types, char buff[],
	int flags, int width, int precision, int size);

int print_int(va_list types, char buff[],
	int flags, int width, int precision, int size);
int print_binary(va_list types, char buff[],
	int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buff[],
	int flags, int width, int precision, int size);
int print_octal(va_list types, char buff[],
	int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buff[],
	int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buff[],
	int flags, int width, int precision, int size);

int print_hexa(va_list types, char map_to[],
char buff[], int flags, char flag_ch, int width, int precision, int size);

int print_non_printable(va_list types, char buff[],
	int flags, int width, int precision, int size);

int print_pointer(va_list types, char buff[],
	int flags, int width, int precision, int size);

int get_flags(const char *_format, int *i);
int get_width(const char *_format, int *i, va_list list);
int get_precision(const char *_format, int *i, va_list list);
int get_size(const char *_format, int *i);

int print_reverse(va_list types, char buff[],
	int flags, int width, int precision, int size);


int print_rot13string(va_list types, char buff[],
	int flags, int width, int precision, int size);

int handle_write_char(char c, char buff[],
	int flags, int width, int precision, int size);
int write_number(int is_negative, int index, char buff[],
	int flags, int width, int precision, int size);
int write_num(int index, char buff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int write_pointer(char buff[], int index, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int write_unsignd(int is_negative, int index,
char buff[],
	int flags, int width, int precision, int size);

int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsignd(unsigned long int num, int size);
void print_buffer(char [], int*);

#endif
