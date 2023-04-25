#include "Main.h"

/**
 * printf_char - prints a char.
 * @number: arguments.
 * Return: 1.
 */
int printf_char(va_list number)
{
	char n;

	n = va_arg(number, int);
	_putchar(n);
	return (1);
}
