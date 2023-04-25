#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>

/**
 * struct format - match the conversion specifiers for printf
 * @id: type char pointer of the specifier i.e (l, h) for (d, i, u, o, x, X)
 * @f: type pointer to function for the conversion specifier
 *
 */

typedef struct format
{
	char *ip;
	int (*f)();
} convert_match;

int printf_pointer(va_list nano);
int printf_hex_aux(unsigned long int number);
int printf_HEX_aux(unsigned int number);
int printf_exclusive_string(va_list nano);
int printf_HEX(va_list nano);
int printf_hex(va_list nano);
int printf_oct(va_list nano);
int printf_unsigned(va_list var);
int printf_bin(va_list nano);
int printf_srev(va_list var);
int printf_rot13(va_list var);
int printf_int(va_list var);
int printf_dec(va_list var);
int _strlen(char *n);
int *_strcpy(char *dest, char *src);
int _strlenc(const char *n);
int rev_string(char *n);
int _strlenc(const char *n);
int printf_37(void);
int printf_char(va_list nano);
int printf_string(va_list nano);
int _putchar(char o);
int _printf(const char *format, ...);

#endif
