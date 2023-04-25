#include "Main.h"
/**
 * printf_string - print a string.
 * @number: argumen t.
 * Return: the length of the string.
 */

int printf_string(va_list number)
{
	char *n;
	int v, pin;

	n = va_arg(number, char *);
	if (n == NULL)
	{
		n = "(null)";
		pin = _strlen(n);
		for (v = 0; v < pin; v++)
			_putchar(n[v]);
		return (pin);
	}
	else
	{
		pin= _strlen(n);
		for (v = 0; v < pin; v++)
			_putchar(n[v]);
		return (pin);
	}
}
